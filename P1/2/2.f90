      PROGRAM taylor
      IMPLICIT NONE

      
      REAL*8   :: fat
      INTEGER*8   :: n
      REAL*8   :: T, termo
      REAL*8,PARAMETER  :: pi = 3.14159265359d0
      LOGICAL  :: cont
      INTEGER*8   :: passo
      REAL*8   :: aux      
      INTEGER*8	::	ordem
      
      !DEFINIÇÃO DAS VARIÁVEIS QUE SERÃO USADAS
      
      DO passo = 1,50
         aux = (pi/50)*FLOAT(passo)    !defino 50 pontos igualmente espaçados entre 0 e pi
         ordem = 0
         T= 0     !valor do polinômio de Taylor = 0 cada vez que é feita a aproximação com um novo valor
         n= 0     
         fat= 1.0d0
         cont= .TRUE.      !idem para as demais variáveis que serão incrementadas no próximo loop
         
         DO WHILE (cont)
         
            IF(MOD(n,2).EQ.0) THEN     !como os termos ímpares do polinômio em torno de zero são multiplicados por SIN(0), somo apenas os pares
               termo= (aux**n)/fat     !da fórmula do pol de Taylor
               fat= -fat      !como no caso do cosceno há a variação de soma e subtração do termo, defino o sinal na variável do fatorial que multiplica as demais
               T= T + termo      !soma do termo ao pol em sí
            ENDIF
         	
         	ordem = ordem + 1
            n= n+1      !o próximo loop será para o termo n+1 do polinômio
            fat= fat*FLOAT(n)    !multiplico aqui o antigo fatorial pelo próximo termo, assim obtendo o próximo fatorial
         
            IF (termo.LE.0.000001 .AND. termo.GE.-0.000001) THEN  !caso o último termo gerado do polinômio esteja em [-10^6, 10^6], posso garantir que esta será a precisão do meu polinômio
               cont= .FALSE.     !quebro o loop e começo para o próximo X0
            ENDIF
         
         END DO
         
         WRITE(2,*)aux,',',T     !escrevo os valores de X e T(X) para serem plotados pelo programa 'graphing.py'
         WRITE(1,*) 'COS(X)= ', COS(aux), '// T(X)= ', T, '// ordem= ', ordem    !em outro arquivo coloco os valores originais do COS(X) e o obtido por Taylor
         
      END DO
      END PROGRAM
