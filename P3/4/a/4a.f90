		MODULE constants ! Módulo contendo as constantes
			REAL*8, PARAMETER	::	pi = 3.14159265359d0
			REAL*8	::	delta_tau = 0.01 ! 0.0001
			REAL*8	::	alpha = 0.1
			REAL*8	::	b = 0.05
		END MODULE

		PROGRAM ex4
			USE constants
			REAL*8	::	theta_last
			REAL*8	::	theta
			REAL*8	::	max_tau = 30*2*pi
			REAL*8	::	tau
			REAL*8	::	nu = 0.0
			REAL*8	::	omega
			REAL*8	::	omega_plus
			REAL*8	::	theta_plus ! Definição das variáveis

			INTEGER*8	::	i, n
			n = INT(max_tau/delta_tau) ! Definição do número de iterações baseado do tempo total e em dt

			! método de Verlet
			theta_last = 0.9999*pi
			theta = theta_last
			tau = 0.0
			omega = 0.0
			DO i = 1, n ! Retornando variáveis ao estado inicial
				WRITE(1,*) tau,",", theta ! Salvando dados para posterior análise
				tau = tau + delta_tau
				omega = (theta - theta_last)/delta_tau
				theta_plus = 2*theta - theta_last + (delta_tau**2)*(-b*omega - (1 - alpha*(nu**2)*SIN(nu*tau))*SIN(theta))
				theta_last = theta
				theta = theta_plus
				IF (omega > 0.0 .AND. (theta - theta_last)/delta_tau < 0.0) THEN
				WRITE(4,*)tau,",", theta
				ENDIF
			END DO
			CALL system("python3 graph1.py") ! Plotando e salvando gráfico

			! método de Euler-Cromer
			theta = 0.9999*pi
			tau = 0.0
			omega = 0.0
			DO i = 1, n ! Retornando variáveis ao estado inicial
				WRITE(2,*) tau, ",", theta ! Salvando dados para posterior análise
				tau = tau + delta_tau
				omega_plus = omega - (b*omega + (1d0 - alpha*nu*nu*SIN(nu*tau))*SIN(theta))*delta_tau
				theta = theta + omega*delta_tau
				omega = omega_plus
			END DO
			CALL system("python3 graph2.py") ! Plotando e salvando gráfico

			! método de Euler
			theta = 0.9999*pi
			tau = 0.0
			omega = 0.0
			DO i = 1, n ! Retornando variáveis ao estado inicial
				WRITE(3,*) tau, ",", theta ! Salvando dados para posterior análise
				tau = tau + delta_tau
				theta = theta + omega*delta_tau
				omega = omega - (b*omega + (1d0 - alpha*nu*nu*SIN(nu*tau))*SIN(theta))*delta_tau
			END DO
			CALL system("python3 graph3.py") ! Plotando e salvando gráfico

		END PROGRAM
