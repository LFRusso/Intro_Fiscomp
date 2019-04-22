      PROGRAM pendulo
         IMPLICIT NONE

         REAL*8   :: wi
         REAL*8   :: dt = 0.005d0
         REAL*8, PARAMETER :: pi = 3.1415926535897932d0
         REAl*8   :: theta = pi/2
         REAL*8, PARAMETER   :: t = 40d0
         INTEGER*8   :: i
         INTEGER*8   ::  n
			INTEGER*8	::	j
         REAL*8   :: g = 9.8d0, l = 1d0
         REAL*8   :: E
         REAL*8   :: m = 1d0
         REAL*8   :: periodo, aux
         REAL*8   :: ltheta
			REAL*8	::	initial_theta = pi/100.0
			REAL*8	::	thetapp
         n =  INT( t / dt )	! Definição das variáveis
			
			DO j = 1, 99 ! loop variando o theta inicial
				aux = 0.0
				wi = 0.0
				periodo = 0.0
				theta = initial_theta
				ltheta = theta ! Retorna as variáveis ao estado inicial
				DO i = 1, n
         	   wi = wi - (g/l)*SIN(theta)*dt	! Método de Euler-Cromer
					thetapp = theta + wi*dt
         	   periodo = periodo + dt
         	   IF (theta > ltheta .AND. theta > thetapp) THEN ! Caso tenha ocorrido uma oscilação, theta é um máximo local, pois ele é igual ao initial_theta
         	      aux = aux + 1d0 ! aux é o auxiliar que indica o número de oscilações
         	   END IF
					ltheta = theta 
					theta = thetapp       	
				END DO
				periodo = periodo/aux ! Defino o período como tempo total dividido pelo número de oscilações
         	WRITE(1,*) initial_theta, ",", periodo ! Escrevo os resultados para posterior análise
				initial_theta = initial_theta + pi/100.0 ! Somo um termo ao theta inicial
			END DO
			CALL system("python3 graph.py")
      END PROGRAM
