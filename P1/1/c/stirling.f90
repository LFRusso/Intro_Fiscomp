      PROGRAM stirling
      IMPLICIT NONE
      
      REAL*8,PARAMETER :: pi = 3.14159265359d0	! defino o valor parâmetro pi com precisão de 10^-11 
      INTEGER*8 n	! defino a variável n que será usada de contador
      
      DO n = 2,30
         WRITE(1,*)n,':', FLOAT(n)*LOG(FLOAT(n)) - FLOAT(n) + 0.5*LOG(2*pi*FLOAT(n))	! para cada n, calculo a fórmula descrita com seu valor
      END DO
      
      END PROGRAM
