		REAL*8 FUNCTION simp_integrate (list, size, h) ! Método de Simpson para integração numérica
			IMPLICIT NONE
			REAL*8, INTENT(IN)	::	h
			INTEGER, INTENT(IN)	::	size
			REAL*8,	DIMENSION(size), INTENT(IN)	::	list
			INTEGER	::	i
			INTEGER	::	auxiliar
			auxiliar = 1

			simp_integrate = list(1) + list(size)
			DO i = 2, size-1
				auxiliar = auxiliar - (-1)**i
				simp_integrate = simp_integrate + (4 - auxiliar*2)*list(i)
			END DO
			simp_integrate = (h/3)*simp_integrate

			RETURN
		END FUNCTION


		PROGRAM ex1
			IMPLICIT NONE
			INTEGER	::	time = 300 ! Tempo total máximo (em segundos)
			REAL*8	::	dt = 0.91 ! Intervalo de tempo delta t, pode ser alterado para 0.1
			REAL*8	::	total_t = 0.0 ! Tempo total atual
			INTEGER	::	i
			INTEGER	::	n
			REAL*8	::	Pc = 400.0 ! Potencia do ciclista
			REAL*8	::	K = 0.0 ! Valor da energia cinética inicial
			REAL*8	::	simp_integrate ! Função Integral de Simpson
			REAL*8	::	speed = 0.0 ! Velocidade inicial
			REAL*8	::	mass = 70.0 ! Massa
			REAL*8	::	area = 0.3 ! Área da superfície
			REAL*8	::	drag_coef = 0.0 ! Coeficiente de arrasto
			REAL*8, DIMENSION(:), ALLOCATABLE	::	velocities ! Vetor contendo todos os valores para as velocidades em cada instante de tempo
			n = INT(time/dt) ! Calculo do número de iterações baseado no intervalo delta t e no tempo total máximo
			ALLOCATE(velocities(n))

			DO i= 1, n
				WRITE(1,*) total_t,",", speed ! Savo em 'fort.1' o atual tempo e velocidade, para posterior análise
				WRITE(*,*) speed ! Escrevo no terminal a velocidade atual
				K = K + dt*(Pc - SQRT(2/(mass**3))*drag_coef*area*(K**(3.0/2.0))) ! Calculo o próximo valor da energia cinética de acordo com a fórmula
				speed = SQRT(2*K/mass) ! Calculo da velocidade atual com base na energia cinética encontrada
				velocities(i) = speed ! Salvo o valor atual da velocidade no array
				total_t = total_t + dt ! Acrescento delta t ao tempo total
			END DO
			WRITE(*,*)"espaço percorrido:", simp_integrate(velocities, n, dt), "m"
			CALL system("python3 graph.py") ! Ploto e salvo gráfico dos resultados

		END PROGRAM