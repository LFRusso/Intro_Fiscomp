		MODULE constants ! Módulo contendo as constantes
			REAL*8, PARAMETER	::	pi = 3.14159265359d0
			REAL*8	::	delta_tau = 0.0001 ! 0.0001
			REAL*8	::	alpha = 0.1
			REAL*8	::	b = 0.05
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
			REAL*8	::	theta_zero = 999d0 ! Definição das variáveis

			INTEGER*8	::	i, n, points
			n = INT(max_tau/delta_tau) ! Definição do número de iterações baseado do tempo total e em dt

			points = 100 ! numero de pontos que serão usados, baseado no número de valoes para nu que usarei
			DO j = 1, points
				theta_zero = 999d0
				WRITE(*,*) j*100/points,"%" ! Escrevo quanto % já está concluido, para melhor acompanhamento
				theta_last = 0.9999*pi
				theta = theta_last
				tau = 0.0
				omega = 0.0 ! Retorna variáveis aos estados iniciais
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
				WRITE(1,*) nu,",", theta_zero ! escrevendo resultados para posterior análise
				nu = nu + 20d0/FLOAT(points) ! acresco nu de acordo com o número de pontos
			END DO
			CALL system("python3 graph1.py") ! plota e salva gráfico
		END PROGRAM
