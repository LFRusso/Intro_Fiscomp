
      PROGRAM logaritmo
      IMPLICIT NONE
   
      INTEGER*8 n, aux
      REAL*8 fat		! declaração das variáveis

	  DO n = 2,30	! n é o número o qual queremos calcular o fatorial. Ele varia de 2 à 30
	     fat = 1	! variável fat (fatorial) inicia como 1 para cada n
         DO aux = 1,n			
		    fat = fat*FLOAT(aux)	! cálculo do fatorial de n como descrito em (a)
		 END DO
	  WRITE(1,*)'LN(FAT(',n,'))','=', LOG(fat)	! desta vez, escrevo no documento fort.1 uma tabela com cada n e o respectivo valor do logaritmo natural de seu fatorial   
      END DO	  
      
      END PROGRAM
