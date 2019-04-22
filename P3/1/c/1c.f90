		REAL*8 FUNCTION simp_integrate (list, size, h) ! Método de Simpson para integração numérica
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
			INTEGER	::	time = 100 ! Tempo total máximo (em segundos)
			REAL*8	::	dt = 0.1 ! Intervalo de tempo delta t
			REAL*8	::	total_t ! Tempo total atual
			INTEGER	::	i
			INTEGER 	::	j
			INTEGER	::	n
			REAL*8	::	K ! Valor da energia cinética inicial
			REAL*8	::	Pc = 400.0 ! Potencia do ciclista
			REAL*8	::	simp_integrate ! Função Integral de Simpson
			REAL*8	::	speed ! Velocidade inicial
			REAL*8	::	mass = 70.0 ! Massa
			REAL*8	::	area ! Área da superfície
			REAL*8	::	drag_coef = 1.3 ! Coeficiente de arrasto
			REAL*8, DIMENSION(:), ALLOCATABLE	::	velocities ! Vetor contendo todos os valores para as velocidades em cada instante de tempo
			n = INT(time/dt) ! Calculo do número de iterações baseado no intervalo delta t e no tempo total máximo
			ALLOCATE(velocities(n))

			Area = 5.0 ! Area inicial
			DO j = 1, 3
				total_t = 0.0
				speed = 0.0
				K = 0.0 ! retornando valores aos estados iniciais
				DO i= 1, n
					WRITE(j,*) total_t,",", speed, ",", area ! Savo em 'fort.j' o atual tempo, velocidade e área, para posterior análise
					K = K + dt*(Pc - SQRT(2/(mass**3))*drag_coef*area*(K**(3.0/2.0))) ! Calculo o próximo valor da energia cinética de acordo com a fórmula
					speed = SQRT(2*K/mass) ! Calculo da velocidade atual com base na energia cinética encontrada
					velocities(i) = speed ! Salvo o valor atual da velocidade no array
					total_t = total_t + dt ! Acrescento delta t ao tempo total
				END DO
				WRITE(*,*) "area = ", area, "m**2" ! escrevo no terminal o valor da área atual
				WRITE(*,*)"espaço percorrido:", simp_integrate(velocities, n, dt), "m" ! Calculo espaço percorrido com a integral de Simpson
				area = area + 5.0 ! adiciono 5m^2 à área para a próxima iteração
			END DO
			CALL system("python3 graph.py") ! Ploto e salvo gráfico dos resultados

		END PROGRAM