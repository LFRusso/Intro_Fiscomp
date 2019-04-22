		PROGRAM list
		IMPLICIT NONE

		LOGICAL		:: troca = .True.
		INTEGER	:: i, n, m
		REAL*8	:: aux
		REAL, DIMENSION(10**4)	:: lista	! a variável lista representa todo o arquivo dos Rnumbers
		REAL, DIMENSION(:), ALLOCATABLE	:: vetor	
		
		OPEN(UNIT=2,FILE="Rnumbers.dat",ACTION="READ")
		READ(UNIT = 2, FMT = *) lista
		CLOSE(UNIT = 2)	
		WRITE(*,*) 'DIGITE O VALOR DE N: '
		READ(*,*) n
		ALLOCATE(vetor(n))	! armazeno até o termo n da lista dentro do meu vetor, tendo sido n entrado no terminal anteriormente
		vetor(:) = lista(:n)
		
!=======================BUBBLE=SORT=============================
		DO WHILE(troca)
			troca = .False.
			DO i = 1, n -1 
				IF(vetor(i).GT.vetor(i+1)) THEN
					aux = vetor(i)
					vetor(i) = vetor(i+1)
					vetor(i+1) = aux
					troca = .True.
				ENDIF
			ENDDO
		ENDDO
!======FONTE = https://pt.wikipedia.org/wiki/Bubble_sort ======-

		WRITE(*,*)'DIGITE M: '
		READ(*,*) m 	! leio o valor de m desejado

		OPEN(UNIT=1,FILE="menores.dat",ACTION="WRITE")	! crio o arquivo em que vou salvar os resultados
		DO i =1,m
			WRITE(UNIT=1,FMT = *) vetor(i)	! percorro os m primeiros termos do vetor já ordenado de ordem crescente e os salvo no arquivo
		ENDDO
		CLOSE(UNIT=1)

		END PROGRAM
