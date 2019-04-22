		MODULE variables ! Módulo contendo as variáveis que serão usadas
			REAL*8, PARAMETER	::	pi = 3.14159265359d0

			REAL*8	::	m = 42.0	! m	(kg)
			REAL*8	::	A = 0.06984	! A	(m^2) -> a partir do calibre
			REAL*8	::	V_0 = 377.0	! V_0	(m/s) 
			REAL*8	::	g = 9.8	! g	(m/s^2)
			REAL*8	::	rho_0	= 1.3	! rho_0	(kg/m^3) [0.0;1.3]
			REAL*8	::	Cd	= 0.295	! Cd	(u.A)
			REAL*8	::	delta_t = 0.01	! delta_t	(s)
			
			REAL*8	::	Vx_i	! Vx_0	(m/s)
			REAL*8	::	Vx_iplus

			REAL*8	::	Vy_i	! Vy_0	(m/s)
			REAL*8	::	Vy_iplus

			REAL*8	::	x	! x_0	(m)
			REAL*8	::	y	! y_0	(m)
		END MODULE

		REAL*8 FUNCTION Vy (delta_t, Vxi, Vyi, rho, A, Cd, m, g) ! Dado os parâmetros, calcula o próximo valor para a componente Y de V
			REAL*8, INTENT(IN)	::	Vyi, Vxi, rho, A, Cd, m, delta_t, g
			Vy = Vyi - delta_t*(g + (rho*A*Cd/(2*m))*SQRT(Vxi**2 + Vyi**2)*Vyi)
			RETURN
		END FUNCTION

		REAL*8 FUNCTION Vx (delta_t, Vxi, Vyi, rho, A, Cd, m, g) ! Dado os parâmetros, calcula o próximo valor para a componente X de V
			REAL*8, INTENT(IN)	::	delta_t, Vxi, Vyi, rho, A, Cd, m, g
			Vx = Vxi - delta_t*(rho*A*Cd/(2*m))*SQRT(Vxi*2 + Vyi**2)*Vxi
			RETURN
		END FUNCTION

		REAL*8 FUNCTION distance (theta) ! Função para calcular distância total em X percorrida dado theta
			USE variables ! Usando as variáveis declaradas no módulo
			REAL*8, INTENT(IN)	::	theta
			REAL*8	::	Vy, Vx ! Funções
			x = 0.0 ! X inicial
			y = 0.0 ! Y inicial


			Vx_i = V_0*COS(theta) ! Componente X da velocidade inicial
			Vy_i = V_0*SIN(theta) ! Componente Y da velocidade inicial

			DO
				Vy_iplus = Vy(delta_t, Vx_i, Vy_i, rho_0, A, Cd, m, g)
				Vx_iplus = Vx(delta_t, Vx_i, Vy_i, rho_0, A, Cd, m, g) ! Cálculo dos próximos valores das componentes das velocidades usando as funções declaradas

				Vy_i = Vy_iplus
				Vx_i = Vx_iplus
				total_time = total_time + delta_t

				x = x + Vx_iplus*delta_t
				y = y + Vy_iplus*delta_t ! Somo a distância diferencial percorrida em dt à Y e X

				IF (y.LT.0d0) THEN ! Condição de parada: atinge o chão
					distance = x ! Distância total percorrida em x
					RETURN
				ENDIF
			END DO

		END FUNCTION

		PROGRAM ex2
			USE variables

			REAL*8	::	theta	= pi/200.0! theta	(rad)
			INTEGER	::	i
			REAL*8	::	distance ! Função

			DO i = 1, 99 ! Vário de theta de pi/200 até pi/2
				theta = theta + pi/200.0
				WRITE(*,*) i ! Escrevo i para acompanhar o processo
				WRITE(1,*) theta,",", distance(theta) ! Escrevo em 'fort.1' o ângulo e a distância em função dele

			END DO
			

		END PROGRAM
