      PROGRAM fatorial
      IMPLICIT NONE
   
      INTEGER*8 n, fat, aux	! variáveis ques serão usadas

	  DO n = 1,20	! n irá variar de 1 à 20. Ele será o número o qual queremos o fatorial
	     fat = 1	! fat (fatorial) é o valor do fatorial. Para cada passo de n, ele será iniciado como 1
         DO aux = 1,n	! o aux (auxiliar) será o passo de 1 até n
		    fat = fat*aux	! como aux será igual à a cada passo 1; 2; ...; n, multiplicar fat por ele garente que ele será multiplicado por cada número inteiro de 1 até n
		 END DO
	  WRITE(1,*)n,'! =', fat	! por fim, escrevo num arquivo fort.1 o respetivo n que estou calculando o fatorial e o valor de n!
      END DO	  
      
      END PROGRAM
