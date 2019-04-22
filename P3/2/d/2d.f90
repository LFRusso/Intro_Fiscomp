		MODULE variables ! Módulo contendo as variáveis que serão usadas
			REAL*8, PARAMETER	::	pi = 3.14159265359d0

			REAL*8	::	m = 42.0	! m	(kg)
			REAL*8	::	A = 0.06984	! A	(m^2) -> a partir do calibre 
			REAL*8	::	g = 9.8	! g	(m/s^2)
			REAL*8	::	rho_0	= 1.3	! rho_0	(kg/m^3) [0.0;1.3]
			REAL*8	::	Cd	! Cd	(u.A)
			REAL*8	::	delta_t = 0.01	! delta_t	(s)
			REAL*8	::	beta = 6.49d-3	!	beta	(K/m)
			REAL*8	::	alpha = 4.256	!	alpha	(u.A)
			REAL*8	::	temperature = 300	!	temperature at sea level	(K)
			

			REAL*8	::	Vx_i	! Vx_0	(m/s)
			REAL*8	::	Vx_iplus

			REAL*8	::	Vy_i	! Vy_0	(m/s)
			REAL*8	::	Vy_iplus

			REAL*8	::	x	! x_0	(m)
			REAL*8	::	y	! y_0	(m)
		END MODULE

		REAL*8 FUNCTION rho(altitude) ! Função para calcular rho de acordo com a altura
			USE variables
			REAL*8, INTENT(IN)	::	altitude			
			rho = rho_0*(1 - (beta/temperature)*altitude)**alpha
			RETURN
		END FUNCTION


		REAL*8 FUNCTION Vy (Vxi, Vyi, rho) ! Dado os parâmetros, calcula o próximo valor para a componente Y de V
			USE variables
			REAL*8, INTENT(IN)	::	Vyi, Vxi, rho


			IF(SQRT(Vxi**2 + Vyi**2) < 343) THEN
				Cd = 0.295
			ELSE 
				Cd = 0.5
			ENDIF

			Vy = Vyi - delta_t*(g + (rho*A*Cd/(2*m))*SQRT(Vxi**2 + Vyi**2)*Vyi)
			RETURN
		END FUNCTION

		REAL*8 FUNCTION Vx (Vxi, Vyi, rho) ! Dado os parâmetros, calcula o próximo valor para a componente X de V
			USE variables
			REAL*8, INTENT(IN)	::	Vyi, Vxi, rho

			IF(SQRT(Vxi**2 + Vyi**2) < 343) THEN
				Cd = 0.295
			ELSE 
				Cd = 0.5
			ENDIF

			Vx = Vxi - delta_t*(rho*A*Cd/(2*m))*SQRT(Vxi*2 + Vyi**2)*Vxi
			RETURN
		END FUNCTION

		REAL*8 FUNCTION distance (theta, V_0) ! Função para calcular distância total em X percorrida dado theta
			USE variables ! Usando as variáveis declaradas no módulo
			USE variables
			REAL*8, INTENT(IN)	::	theta, V_0
			REAL*8	::	Vy, Vx, rho
			x = 0.0
			y = 0.0


			Vx_i = V_0*COS(theta)
			Vy_i = V_0*SIN(theta)

			DO
				Vy_iplus = Vy(Vx_i, Vy_i, rho(y))
				Vx_iplus = Vx(Vx_i, Vy_i, rho(y))

				Vy_i = Vy_iplus
				Vx_i = Vx_iplus
				total_time = total_time + delta_t

				x = x + Vx_iplus*delta_t
				y = y + Vy_iplus*delta_t

				IF (y.LT.0d0) THEN ! Condição de parada: atinge o chão
					distance = x
					RETURN
				ENDIF
			END DO

		END FUNCTION

		PROGRAM ex2
			USE variables

			REAL*8	::	theta	= 0.5654866776	! theta max	(rad)
			REAL*8	::	V_0a = 380.77 ! V0 +1%
			REAL*8	::	V_0b = 373.33 ! V0 -1%
			INTEGER	::	i
			REAL*8	::	distance

			WRITE(*,*) "V0 = ", V_0a,"X = ", distance(theta, V_0a)
			WRITE(*,*) "V0 = ", V_0b,"X = ", distance(theta, V_0b)
			

		END PROGRAM
