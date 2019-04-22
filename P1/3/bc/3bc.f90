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

	 	!!!DEFINIÇÃO DAS VARIÁVEIS!!!

	 	CALL kissinit(42)
	 	OPEN(UNIT=1, FILE="votes.dat", ACTION='READ')
	 	READ(UNIT=1, FMT=*) votes	!	leio o arquivo 'votes.dat' e armazeno em um array
	 	CLOSE(UNIT=1)

		DO k = 1, 100	! k variando de 1 à 100 (100 amostras diferentes)
			xmed = 0		
			M = int(rkiss05()*10**4)	! M será o tamanho da minha amostra sorteda, portanto ela terá um tamanho >= 10^4
			DO i = 1, M 	! crio uma estrutura de repetição de 1 à M, o que me dará M elementos para a amostra
				index = int(rkiss05()*10**6)	
				xmed = xmed + votes(index)	!	Sorteio também aleatoriamente um indice para votes, o qual o elemento do índice será somado e usado para calcular a média xmed
			ENDDO
			medias(k) = xmed/M 	! adiciono meus valores de xmed à um outro vetor para ser usado posteriormente
			X = X + medias(k)		! X será o valor médio da amostragem, conforme pedido em (c)
		ENDDO
		X = X/100	! X é dividido pelo valor de k (100)

		DO k = 1, 100
			sm = sm + (medias(k)-X)**2	! faço novamente k de 1 à 100, desta vez para calcular o desvio padrão não enviesado Sm
		END DO
		WRITE(*,*)'Xm = ', X
		WRITE(*,*)'sm = ',(sm/99)**0.5	! por fim, escrevo o valor médio encontrado de X e seu respectivo desvio padrão

      END PROGRAM