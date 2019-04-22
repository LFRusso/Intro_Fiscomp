		PROGRAM domeig
		IMPLICIT NONE

		REAL*8, DIMENSION(:,:), ALLOCATABLE	::	A
		REAL*8, DIMENSION(:), ALLOCATABLE	::	x, xp
		REAL*8										::	rkiss05
		REAL*8										::	lamb, term
		INTEGER*8									:: n, i, j, k, contador = 0
		REAL*8										::	rand
		LOGICAL										::	cont= .True.
	
		!!! DECLARAÇÃO DAS VARIÁVEIS !!!
	
		CALL kissinit(17)
		WRITE(*,*)'DIMENSÃO DA MATRIZ:'
		READ(*,*) n
		ALLOCATE(A(n,n))
		ALLOCATE(x(n))
		ALLOCATE(xp(n))	! Leio a dimensão n da matriz que se deseja calcular o autovalor e aloco a matriz A(n,n), assim como os vetores x(n) e xp(n), que serão usados para multiplicar a matriz

		WRITE(*,*)'ENTRE NUMERO MÁXIMO DE ITERAÇÕES'
		READ(*,*) k		! É digitado o número máximo de loops de múltiplicação que serão realizados antes de finalizar o programa

		WRITE(*,*)'ENTRE COM A MATRIZ'
		DO i = 1, n
			rand  = rkiss05()
			x(i) = rand			! Aproveito o loop de 1 até n, usado para digitar a matriz, para gerar o vetor aleatório x
			READ(*,*) A(i,:)	! Lê a matriz no terminal, linha a linha
		END DO
		WRITE(*,*) 'CALCULANDO'

		DO WHILE(cont)
			contador = contador +1	! O contador será usado para ser comparado com o número máximo de loops, "K", lido anteriormente. Ele será incrementado em 1 a cada loop
			DO i= 1, n
				term = 0.0d0	! 'term' representa cada linha resultante da multiplicação entre A e x, para cada uma das i linhas
				DO j= 1, n
					term = term + x(j)*A(i,j)	! Faço a operação descrita acima
				END DO
				xp(i) = term	! Defino a linha "i" do vetor xp auxiliar como o termo 'term'. Ainda não posso alterar o valor do vetor original x pois ele está sendo usado na múltiplicação, então xp está simplesmente sendo usado para armazenar todos os valoes que serão substituídos de uma vez após o término da operação
				END DO
				x(:) = xp(:)	! Após a multiplicação substituo os valores de x pelos armazenados em xp
			IF (ABS(lamb-MAXVAL(x)).LE.10**(-5) .OR. contador.GE.k) THEN	! Caso a diferença entre a última aproximação do autovalor dominante e a nova seja menor que um valor sigma (no caso sigma = 10**-5) OU caso o número máximo de loops 'k' tenha sido atingido, o programa é interrompido 
				cont = .False.
			END IF

			lamb = MAXVAL(x)	! o autovalor dominante lambda é igual ao maior número do vetor x
			x(:)  = x(:)/lamb	! divido x pelo autovalor para ajustá-lo para o próximo ciclo
			WRITE(1,*)contador,',',lamb	! Salvo em um arquivo para posterior representação gráfica
		END DO

		WRITE(*,*) lamb	! Retorna no terminal o autovalor dominante

		END PROGRAM
