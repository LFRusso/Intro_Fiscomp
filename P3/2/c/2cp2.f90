		MODULE variables
			REAL*8, PARAMETER	::	pi = 3.14159265359d0

			REAL*8	::	m = 42.0	! m	(kg)
			REAL*8	::	A = 0.06984	! A	(m^2) -> a partir do calibre
			REAL*8	::	V_0 = 377.0	! V_0	(m/s) 
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

		REAL*8 FUNCTION rho(altitude)
			USE variables
			REAL*8, INTENT(IN)	::	altitude			
			rho = rho_0*(1 - (beta/temperature)*altitude)**alpha
			RETURN
		END FUNCTION


		REAL*8 FUNCTION Vy (Vxi, Vyi, rho)
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

		REAL*8 FUNCTION Vx (Vxi, Vyi, rho)
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

		REAL*8 FUNCTION distance (theta)
			USE variables
			REAL*8, INTENT(IN)	::	theta
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

				IF (y.LT.0d0) THEN
					distance = x
					RETURN
				ENDIF
			END DO

		END FUNCTION

		PROGRAM ex2
			USE variables

			REAL*8	::	theta	= pi/200.0! theta	(rad)
			INTEGER	::	i
			REAL*8	::	distance

			DO i = 1, 99
				theta = theta + pi/200.0
				WRITE(1,*)theta, ",", distance(theta)
			END DO
			

		END PROGRAM