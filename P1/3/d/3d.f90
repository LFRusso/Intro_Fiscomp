		PROGRAM prog
      IMPLICIT NONE
      
	 	INTEGER*8	::	k, i
	 	REAL*8	::	rkiss05
		INTEGER	:: M
		REAL*8, DIMENSION(100)	:: medias
	 	INTEGER*8	::	index
	 	REAL*8		::	xmed
	 	INTEGER, DIMENSION(10**6)	::	votes
	 	REAL*8		:: X = 0
	 	REAL*8		::	sm = 0
	 	REAL*8		::	var = 0

	 	CALL kissinit(42)
	 	OPEN(UNIT=1, FILE="votes.dat", ACTION='READ')
	 	READ(UNIT=1, FMT=*) votes	! leio o arquivo votes.dat
	 	CLOSE(UNIT=1)


	 	DO i = 1, 10**6
		 	xmed = xmed + votes(i)	 		
	 	END DO
	 	xmed = xmed/(10**6)
	 	DO i = 1, 10**6
	 		var = var + (votes(i)-xmed)**2
	 	END DO
	 	var = ((var/(10**6))**0.5)		! calculo a variância do meu conjunto


		DO M = 10, 10**4	! vario M de 10 até 10^4, representando o tamanho do meu subconjunto
			sm = 0
			X = 0		
			DO k = 1, 100	! por 100 vezes, pego uma amostra aleatória e calculo seu desvio padrão não enviesado como descrito no exercício anterior
				xmed = 0				
				DO i = 1, M
					index = int(rkiss05()*10**6)
					xmed = xmed + votes(index)
				ENDDO
				medias(k) = xmed/M
				X = X + medias(k)
			ENDDO
			X = X/100
			
			DO k = 1, 100
				sm = sm + (medias(k)-X)**2	
			END DO
			sm = (sm/99)**0.5	! por fim, para cada subconjunto de tamanho M, tendo pego 100 amostras para cada, terei um desvio padrão enviesado para cada M
			WRITE(1,*) M, ',', sm, ',', var/SQRT(FLOAT(M))	! Salvo os valores do tamanho M, de Sm e de sigma/(M^0.5), sendo sigma a variância de todo conjunto, para posterior análise
		ENDDO
		WRITE(*,*) sm

      END PROGRAM
