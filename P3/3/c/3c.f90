      PROGRAM pendulo
      IMPLICIT NONE

         REAL*8   :: wi = 0
         REAL*8   :: dt = 0.005d0
         REAL*8, PARAMETER :: pi = 3.1415926535897932d0
         REAl*8   :: theta = pi/2
         REAL*8, PARAMETER   :: t = 40d0
         INTEGER*8   :: i
         INTEGER*8   ::  n
         REAL*8   :: g = 9.8d0, l = 1d0
         REAL*8   :: E
         REAL*8   :: m = 1d0
         ! definição das variáveis

          n =  INT( t / dt )

         DO i = 1, n

            wi = wi - (g/l)*SIN(theta)*dt
            theta = theta + wi*dt
            E = 0.5*m*l*l*wi*wi + m*g*l*(1 - COS(theta)) ! Método de Euler-Cromer

            WRITE(1,*) i*dt,',' , theta, ',', E, ',', wi ! Salvando variáveis para posteior análise
         END DO
         CALL system("python3 graph.py") ! Plota e salva gráfico


      END PROGRAM
