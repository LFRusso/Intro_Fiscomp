    FUNCTION f(x, t)    !DEFINO AQUI A FUNTÇÃO DESEJADA, PARA QUE SEJA MAIS FÁCIL CHAMÁ-LA. DESTA VEZ ELA TEM UM PARÂMETRO PARA A TEMPERATURA, POIS ELA TAMBÉM IRÁ VARIAR
      REAL*8  ::  t
      REAL*8  ::  x, f
      f =  TANH(x/t) - x
      RETURN
    END FUNCTION

    FUNCTION fder(x, t)   !DERIVO A FUNÇÃO MATEMÁTICA MANUALMENTE E USO-A COMO OUTRA FUNÇÃO DO CÓDIGO. IDEM PARA A TEMPERATURA
      REAL*8  ::  x, fder
      REAL*8  ::  t
      fder = (1/(COSH(x/t))**(2))*(1/t) - 1
    END FUNCTION

    PROGRAM root
      IMPLICIT NONE
      REAL*8  ::  m, mpp, E, t
      INTEGER*8 ::  i
      REAL*8  ::  f, fder
      LOGICAL ::  continua    !DEFINIÇÃO DAS VARIÁVEIS A SEREM USADAS


      DO i = 1, 1000
        t = (2*i / 1000d0)    !VARIO MINHA TEMPERATURA DE 2/1000 ATÉ 2 (ELA NÂO PODE SER ZERO POIS CAUSARIA UMA INDETERMINAÇÃO NA FUNÇÃO)
        WRITE(*,*)'T= ',t
        E = 10E-8   !DEFINO MEU ERRO 'E' COMO O ERRO DA MÁQUINA POR CONTA DO USO DO TIPO REAL*8
        m = 1
        continua = .TRUE.   !RETORNO A VARIÁVEL LÓGICA QUE DETERMINA A CONTINUAÇÃO DO LOOP À VERDADEIRA
        DO WHILE(continua)
          mpp = m - (f(m, t) / fder(m,t))   !CALCULO mpp (m+1) CONFORME A FÓRMULA
          IF(ABS(m - mpp) < E) THEN   !CASO ATINJA O ERRO DESEJADO, SAIO DO LOOP
            continua = .FALSE.
          END IF
          m = mpp   !DEFINO O "m antigo" COMO O mpp ("m novo" QUE FOI CALCULADO), PARA A PRÓXIMA ITERAÇÃO
        END DO
        WRITE(1,*)m,',', t    !ESCREVO EM UM ARQUIVO O VALOR DE M PARA CADA T UTILIZADO, PARA POSTERIOR ANÁLISE

      END DO

    END PROGRAM
