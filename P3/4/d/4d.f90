		MODULE constants ! Módulo contendo as constantes
			REAL*8, PARAMETER	::	pi = 3.14159265359d0
			REAL*8	::	delta_tau = 0.01 ! 0.0001
			REAL*8	::	alpha = 0.1
			REAL*8	::	b = 0.05
			REAL*8	::	nu = 40.0
		END MODULE

		PROGRAM ex4
			USE constants
			REAL*8	::	theta_last
			REAL*8	::	theta
			REAL*8	::	max_tau = 30*2*pi
			REAL*8	::	tau
			REAL*8	::	omega
			REAL*8	::	omega_plus
			REAL*8	::	theta_plus
			INTEGER*8	::	i, n ! Definição das variáveis
			n = INT(max_tau/delta_tau) ! Definição do número de iterações baseado do tempo total e em dt

			theta_last = 0.9999*pi
			theta = theta_last
			tau = 0.0
			omega = 0.0 ! Estados iniciais das variáveis
			DO i = 1, n
				WRITE(*,*)i ! Escrevo i atual para melhor acompanhamento do programa
				tau = tau + delta_tau
				omega = (theta - theta_last)/delta_tau
				theta_plus = 2*theta - theta_last + (delta_tau**2)*(-b*omega - (1 - alpha*(nu**2)*SIN(nu*tau))*SIN(theta))
				theta_last = theta
				theta = theta_plus ! Método de Verlet
				WRITE(1,*) tau,",", theta - pi ! salvo resultados para posterior análise
			END DO
		END PROGRAM
