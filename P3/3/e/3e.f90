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
         REAL*8   :: ltheta, thetapp, aux
         REAL*8   :: periodo = 0.0
          n =  INT( t / dt ) ! Definição das variáveis

         ltheta = theta
         DO i = 1, n
            thetapp = 2*theta - ltheta - (g/l)*SIN(theta)*dt*dt
            wi = wi - (g/l)*SIN(theta)*dt
            E = 0.5*m*l*l*wi*wi + m*g*l*(1 - COS(thetapp))
            WRITE(1,*)dt*i, ',', thetapp, ',', E,',', wi ! Salvando os valores para posterior análise
            periodo = periodo + dt

            ltheta = theta
            theta = thetapp	! Método de Verlet

         END DO
         CALL system("python3 graph.py") ! plota e salva o gráfico
      END PROGRAM
