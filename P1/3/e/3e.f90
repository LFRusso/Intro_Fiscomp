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
		LOGICAL		:: cont = .TRUE.
	 	REAL*8		::	var = 0, erro

	 	CALL kissinit(42)
	 	OPEN(UNIT=1, FILE="votes.dat", ACTION='READ')
	 	READ(UNIT=1, FMT=*) votes
	 	CLOSE(UNIT=1)
	 	
	 	DO i = 1, 10**6
		 	xmed = xmed + votes(i)	 		
	 	END DO
	 	xmed = xmed/(10**6)
	 	DO i = 1, 10**6
	 		var = var + (votes(i)-xmed)**2
	 	END DO
	 	var = (var/(10**6))**0.5

		DO M = 10, 10**4	
			erro = var/SQRT(FLOAT(M))
			IF (erro .LE. 0.1) THEN
				WRITE(*,*) M
				EXIT
			ENDIF
		ENDDO
		
      END PROGRAM
