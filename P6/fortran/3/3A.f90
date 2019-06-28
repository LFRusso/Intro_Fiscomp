	! For one dimension

	PROGRAM random_walk
	IMPLICIT NONE

	INTEGER*8			:: t,k 
	REAL*8                  :: x,dx,xm,xm2,error1,error2
	REAL*8, DIMENSION(200)  :: r1,r2,r3
		

	OPEN(UNIT = 10,  FILE = "randomwalk1d_xm.txt" )
	OPEN(UNIT = 20,  FILE = "randomwalk1d_xm2.txt")
	OPEN(UNIT = 30,  FILE = "randomwalk1d_x.txt")
	OPEN(UNIT = 50,  FILE = "randomwalk1d_50.txt" )
	OPEN(UNIT = 100, FILE = "randomwalk1d_100.txt")
	OPEN(UNIT = 200, FILE = "randomwalk1d_200.txt")

	! erro = dp/sqrt(N)

	DO WHILE ( ( error1 .GT. (0.1d0)) .OR. (error2 .GT. (xm2/10.d0)) .OR. (k .LT. 5) )
		
		k   = k + 1		
		x   = 0.d0

		DO t = 1,200				! Step number 
			
			CALL RANDOM_NUMBER(dx)
			
			x = x + dx*2.d0 - 1.d0
					
			IF ( (t .EQ. 50) .OR. (t .EQ. 100) .OR. (t .EQ. 200) ) THEN
				
				WRITE(t,*)t,x
			
			END IF
			
			WRITE(30,*)t,x 
	
			r1(t) = r1(t) + x
			r2(t) = r2(t) + x**2.d0
			r3(t) = r3(t) + x**4.d0
			 
		END DO

			xm  	  = r1(200)/k
			error1  = DSQRT(r2(200)/k - xm**2.d0)/DSQRT(REAL(k,8) )
			xm2 	  = r2(200)/k
			error2  = DSQRT(r3(200)/k - xm2**2.d0)/DSQRT(REAL(k,8))
		
			
	END DO
		
	DO t = 1,200

		xm 	  = r1(t)/k		
		error1  = DSQRT(r2(t)/k - xm**2.d0)/DSQRT(REAL(k,8))
		WRITE(10,*)t,xm,error1
		
		xm2	  = r2(t)/k
		error2  = DSQRT(r3(t)/k - xm2**2.d0)/DSQRT(REAL(k,8))
		WRITE(20,*)t,xm2,error2

	END DO

	WRITE(*,*)" k to 10% error ", k

	CLOSE(10)
	CLOSE(20)
	CLOSE(30)
	CLOSE(50)
	CLOSE(100)
	CLOSE(200)

	CALL system("python3 plotsA.py")	
	
	
	END PROGRAM random_walk

	
