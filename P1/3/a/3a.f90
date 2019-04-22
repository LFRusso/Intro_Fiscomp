		PROGRAM VMeDP
		IMPLICIT NONE

			INTEGER*8, DIMENSION (10**6) :: votes
			INTEGER*8 :: i
			INTEGER*8 :: aux = 0
			REAL*8 :: result
			
			OPEN(UNIT=1,FILE="votes.dat",ACTION="READ")
			READ(UNIT=1,FMT=*) votes
			CLOSE(UNIT=1)

			DO i = 1, 10**6
				aux = aux + votes(i)
			END DO

			result = FLOAT(aux)/(10**6)
			WRITE(*,*) result

			IF (result.LE.0.5) THEN
				WRITE(*,*) 'O vencedor é 0'
			ELSE
				WRITE(*,*) 'O vencedor é 1'
			ENDIF

		END PROGRAM
