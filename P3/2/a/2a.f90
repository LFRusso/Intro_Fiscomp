		REAL*8 FUNCTION Vy (delta_t, Vxi, Vyi, rho, A, Cd, m, g) ! Função para calcular componente Y da velocidade
			REAL*8, INTENT(IN)	::	Vyi, Vxi, rho, A, Cd, m, delta_t, g
			Vy = Vyi - delta_t*(g + (rho*A*Cd/(2*m))*SQRT(Vxi**2 + Vyi**2)*Vyi)
			RETURN
		END FUNCTION

		REAL*8 FUNCTION Vx (delta_t, Vxi, Vyi, rho, A, Cd, m, g) ! Função para calcular componente X da velocidade
			REAL*8, INTENT(IN)	::	delta_t, Vxi, Vyi, rho, A, Cd, m, g
			Vx = Vxi - delta_t*(rho*A*Cd/(2*m))*SQRT(Vxi*2 + Vyi**2)*Vxi
			RETURN
		END FUNCTION

		PROGRAM ex2
			IMPLICIT NONE
			REAL*8, PARAMETER	::	pi = 3.14159265359d0
			REAL*8	::	Vy, Vx ! Funções

			REAL*8	::	m = 42.0	! m	(kg)
			REAL*8	::	A = 0.06984	! A	(m^2) -> a partir do calibre
			REAL*8	::	V_0 = 377.0	! V_0	(m/s) 
			REAL*8	::	g = 9.8	! g	(m/s^2)
			REAL*8	::	rho_0	= 0.0	! rho_0	(kg/m^3) [0.0;1.3]
			REAL*8	::	Cd	= 0.295	! Cd	(u.A)
			REAL*8	::	delta_t = 0.01	! delta_t	(s); pode ser mudado para 0.001
			REAL*8	::	theta = pi/3.0	! theta	(rad); pode ser mudado para [pi/3;pi/4;pi/6]

			REAL*8	::	Vx_i	! Vx_0	(m/s)
			REAL*8	::	Vx_iplus

			REAL*8	::	Vy_i	! Vy_0	(m/s)
			REAL*8	::	Vy_iplus

			REAL*8	::	x = 0.0	! x_0	(m)
			REAL*8	::	y = 0.0	! y_0	(m)
			REAL*8	::	total_time = 0.0 ! valor do tempo total transcorrido
			INTEGER	::	i

			Vx_i = V_0*COS(theta) ! Valor inicial da componente x de V
			Vy_i = V_0*SIN(theta) ! Valor inicial da componente y de V

			DO
				Vy_iplus = Vy(delta_t, Vx_i, Vy_i, rho_0, A, Cd, m, g) ! Dado os parâmetros, calculo o próximo valor de Vy
				Vx_iplus = Vx(delta_t, Vx_i, Vy_i, rho_0, A, Cd, m, g) ! ! Dado os parâmetros, calculo o próximo valor de Vx

				Vy_i = Vy_iplus
				Vx_i = Vx_iplus
				total_time = total_time + delta_t ! Acrescento dt ao tempo total
				WRITE(*,*) Vx_i, Vy_i ! Escrevo o valor atual das velocidades no terminal

				x = x + Vx_iplus*delta_t ! Obtenho x pela fórmula
				y = y + Vy_iplus*delta_t ! obtenho y pela fórmula
				WRITE(1,*) x, ",", y ! Escrevo em um arquivo 'fort.1' os valroes de x e y para posteior análise

				IF (y.LT.0d0) THEN ! Paro o programa quando y passa de zero (atinge o chão)
					STOP
				ENDIF
			END DO

		END PROGRAM
