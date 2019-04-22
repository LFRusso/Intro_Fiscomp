      FUNCTION f(x) RESULT(r)   !DEFINO AQUI A FUNTÇÃO DESEJADA, PARA QUE SEJA MAIS FÁCIL CHAMÁ-LA
        REAL*8  ::  T = 0.5   !TEMPERATURA T USADA 0.5, CONFORME O PEDIDO NO EXERCÍCIO
        REAL*8  ::  x, r
        r = TANH(x/T) - x
      END FUNCTION

      FUNCTION fder(x) RESULT(r)    !DERIVO A FUNÇÃO MATEMÁTICA MANUALMENTE E USO-A COMO OUTRA FUNÇÃO DO CÓDIGO
        REAL*8  ::  x, r
        REAL*8  ::  T = 0.5
        r = (1/(COSH(x/t))**(2))*(1/t) - 1
      END FUNCTION


      PROGRAM root
      IMPLICIT NONE
        REAL*8  ::  a, b, c, m, mpp
        INTEGER*8 ::  n = 0
        REAL*8  ::  f, fder
        REAL*8  ::  lc    !DEFINIÇÃO DAS VARIÁVEIS A SEREM USADAS

        c = 1
        a = 0
        b = 1
        m = 1   !INICIO COM O INTERVALO [a,b] COM a = 0, b = 1, c = 1 E DEFINO m0 = 1, COMO MOSTRADO NA PRIMEIRA LINHA DA TABELA-MODELO

        DO    !DENTRO DO MESMO LOOP, FAREI O MÉTODO DA BISSEÇÃO E DE NEWTON-RAPHSON, O CRITÉRIO PARA PARAR O LOOP SENDO O ERRO DA BISSEÇÃO, UMA VEZ QUE É ESPERADO QUE ELA DEMORA MAIS PARA CHEGAR LÁ
          mpp = m - (f(m) / fder(m))    !mpp É O PRÓXIMO VALOR PARA m, CALCULADO A PARTIR DA FÓRMULA
          WRITE(1,*) n,',', a,',', b,',', ABS(a - b),',', m,',', ABS(mpp - m)   !ESCREVO A TABELA COMO PEDIDO
          m = mpp   !DEFINO O VALOR DE "m antigo" COMO O DO "novo m", PREPARANDO PARA A PRÓXIMA ITERAÇÃO

          lc = c    !DEFINO O VALOR DE "lc" ("last c") COMO O DE c
          c = (a+b)/2   !CALCULO O VALOR DE C COMO A MÉDIA ENTRE a E b

          IF (f(c)*f(b) > 0) THEN   !COMO É PRESSUPOSTO QUE A RAÍZ ESTEJA EM UM INTERVALO EM QUE O PRODUTO DO f DE SEUS EXTREMOS SEJA NEGATIVO...
            b = c
          ELSE
            a = c
          END IF    !...PEGO O OUTRO INTERVALO EM QUE C PASSA A SER SEU NOVO EXTREMO, ASSIM DIVIDINDO O TAMANHO DO INTERVALO PELA METADE

          IF (ABS(c - lc) < 1d-6) THEN  !CASO ATINJA O ERRO DESEJADO, SAIO DO LOOP
            STOP
          END IF
          n = n+1   !SOMO 1 AO CONTADOR, PARA PODER VER SEU MÁXIMO ATINGIDO DEPOIS


        END DO

      END PROGRAM
