		PROGRAM logaritmo
		IMPLICIT NONE

		INTEGER*8 n, aux
		REAL*8,PARAMETER :: pi = 3.14159265359d0
		REAL*8 fat, S

		DO n = 2,30
	     fat = 1
         DO aux = 1,n			
		    fat = fat*FLOAT(aux)
			END DO
			S = FLOAT(n)*LOG(FLOAT(n)) - FLOAT(n) + 0.5*LOG(2*pi*FLOAT(n))
			WRITE(2,*)n, LOG(fat), S, (LOG(fat)-S)/LOG(fat)
		END DO	  
      
      END PROGRAM