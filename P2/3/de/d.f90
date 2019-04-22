    FUNCTION f(x)   !DEFINO AQUI A FUNTÇÃO DESEJADA, PARA QUE SEJA MAIS FÁCIL CHAMÁ-LA
      REAL*8  ::  t = 0.9   !TEMPERATURA USADA 0.9 PARA O ITEM d
      REAL*8  ::  x, f
      f =  TANH(x/t) - x
      RETURN
    END FUNCTION

    FUNCTION fder(x)    !DERIVO A FUNÇÃO MATEMÁTICA MANUALMENTE E USO-A COMO OUTRA FUNÇÃO DO CÓDIGO
      REAL*8  ::  x, fder
      REAL*8  ::  t = 0.9   !TEMPERATURA USADA 0.9 PARA O ITEM d
      fder = (1/(COSH(x/t))**(2))*(1/t) - 1
    END FUNCTION


    PROGRAM root
      IMPLICIT NONE
      REAL*8  ::  a, b, c, m, mpp, E
      INTEGER*8 ::  n = 0, i
      REAL*8  ::  f, fder
      REAL*8  ::  lc
      LOGICAL ::  continua    !DEFINIÇÃO DAS VARIÁVEIS A SEREM USADAS


      DO i = 0, 14
        E = 10d0**(-i)    !VARIO O ERRO DE 10**-14 ATÉ 1
        n = 0   !O CONTADOR n INICIA COMO 0
        continua = .TRUE.   !RETORNO A VARIÁVEL LÓGICA QUE DETERMINA A CONTINUAÇÃO DO LOOP À VERDADEIRA
        c = 1
        a = 0
        b = 1   !COMEÇO CADA LOOP DO MÉTODO DA BISSEÇÃO NO INTERVALO [0,1]
        DO WHILE(continua)
          lc = c    !DEFINO O VALOR DE "lc" ("last c") COMO O DE c
          c = (a+b)/2    !CALCULO O VALOR DE C COMO A MÉDIA ENTRE a E b
          IF (f(c)*f(b) > 0) THEN   !COMO É PRESSUPOSTO QUE A RAÍZ ESTEJA EM UM INTERVALO EM QUE O PRODUTO DO f DE SEUS EXTREMOS SEJA NEGATIVO...
            b = c
          ELSE
            a = c
          END IF    !...PEGO O OUTRO INTERVALO EM QUE C PASSA A SER SEU NOVO EXTREMO, ASSIM DIVIDINDO O TAMANHO DO INTERVALO PELA METADE
          IF (ABS(c - lc) < E) THEN   !CASO ATINJA O ERRO DESEJADO, SAIO DO LOOP
            continua = .FALSE.
          END IF
          n = n+1   !SOMO 1 AO CONTADOR, PARA PODER VER SEU MÁXIMO ATINGIDO DEPOIS
        END DO
        WRITE(1,*)LOG10(FLOAT(n)),',', LOG10(E)   !ESCREVO EM UM ARQUIVO O LOG DO MAIOR n NECESSÁRIO PARA ATINGIR O ERRO DESEJADO

        m = 1   !CHUTO O VALOR DE m0 COMO 1
        n = 0   !RETORNO O CONTADOR À ZERO
        continua = .TRUE.   !RETORNO A VARIÁVEL LÓGICA QUE DETERMINA A CONTINUAÇÃO DO LOOP À VERDADEIRA
        DO WHILE(continua)
          mpp = m - (f(m) / fder(m))    !CALCULO mpp (m+1) CONFORME A FÓRMULA
          IF(ABS(m - mpp) < E) THEN   !CASO ATINJA O ERRO DESEJADO, SAIO DO LOOP
            continua = .FALSE.
          END IF
          m = mpp   !DEFINO O "m antigo" COMO O mpp ("m novo" QUE FOI CALCULADO), PARA A PRÓXIMA ITERAÇÃO
          n = n + 1   !SOMO 1 AO CONTADOR
        END DO
        WRITE(2,*) LOG10(FLOAT(n)),',', LOG10(E)    !ESCREVO EM OUTRO ARQUIVO O LOG DO MAIOR n NECESSÁRIO PARA ATINGIR O ERRO DESEJADO

      END DO

    END PROGRAM
