		MODULE constants ! Módulo contendo as constantes
			REAL*8, PARAMETER	::	pi = 3.14159265359d0
			REAL*8	::	delta_tau = 0.0001
			REAL*8	::	alpha = 0.1
			REAL*8	::	b = 0.0
		END MODULE

		PROGRAM ex4
			USE constants
			REAL*8	::	theta_last
			REAL*8	::	theta
			REAL*8	::	max_tau = 30*2*pi
			REAL*8	::	tau
			REAL*8	::	nu
			REAL*8	::	omega
			REAL*8	::	omega_plus
			REAL*8	::	theta_plus
			REAL*8	::	theta_zero = 999d0
			REAL*8	::	initial_theta ! Definição das variáveis

			INTEGER*8	::	i, n, points
			n = INT(max_tau/delta_tau) ! Definição do número de iterações baseado do tempo total e em dt

			points = 40 ! número de valoes para nu que usarei
			initial_theta = 0.0 ! theta inicial, para ser modificado ao longo do loop
			CALL system("rm nu-theta.csv")

			DO k = 1, 40

				WRITE(*,*) k*100/40,"%" ! Escrevo quanto % já está concluido, para melhor acompanhamento
				CALL system("rm point.csv") ! Apago arquivo antigo, caso exista
				OPEN(10, file = 'point.csv')
				nu = 0.0 ! retorno nu ao valor inicial
				DO j = 1, points
					theta_zero = 999d0
					theta_last = initial_theta
					theta = theta_last
					tau = 0.0
					omega = 0.0 ! retornando variáveis aos estados iniciais
					DO i = 1, n
						tau = tau + delta_tau
						omega = (theta - theta_last)/delta_tau
						theta_plus = 2*theta - theta_last + (delta_tau**2)*(-b*omega - (1 - alpha*(nu**2)*SIN(nu*tau))*SIN(theta))
						theta_last = theta
						theta = theta_plus ! Método de Verlet
						IF (ABS(theta) < theta_zero) THEN ! Determinando o módulo do menor valor de theta
							theta_zero = ABS(theta)
						END IF
					END DO
					WRITE(10,*) nu,",", theta_zero, ",", initial_theta ! escrevendo menor theta encontrado para cada nu, baseado no valor de theta inicial
					nu = nu + 20d0/FLOAT(points) ! acrecento nu de acordo com o número de pontos
				END DO
				CALL system("python3 get_nu.py") ! código de python para encontrar o nu* em cada caso, a partir dos dados

				initial_theta = initial_theta + pi/40.0 ! acrecento um valor desejado ao angulo inicial
			END DO

			CALL system("python3 graph.py") ! plota e salva gráfico
		END PROGRAM
