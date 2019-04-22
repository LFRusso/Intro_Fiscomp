      FUNCTION f(x)  RESULT(r)    !DEFINO AQUI A FUNTÇÃO DESEJADA, PARA QUE SEJA MAIS FÁCIL CHAMÁ-LA
         REAL*8   :: x, r
         r = (exp(2*x))*COS(x/4)
      END FUNCTION

      FUNCTION der(x)   RESULT(r)   !DERIVO A FUNÇÃO MANUALMENTE, PARA PODER DETERMINAR O ERRO DA DERIVADA "VERDADEIRA" EM RELAÇÃO À ENCONTRADA COMPUTACIONALMENTE
         REAL*8   :: x, r
         R = -(SIN(x/4) - 8*COS(x/4))*EXP(2*x)/4
      END FUNCTION

      FUNCTION der2(x)  RESULT(r)   !IDEM PARA A SEGUNDA DERIVADA
         REAL*8   ::   x, r
         r = -(16*SIN(X/4) - 63*COS(X/4))*EXP(2*x)/16
      END FUNCTION

      PROGRAM ex1
         IMPLICIT NONE
         REAL*8   :: f, x, der, der2
         REAL*8   :: ff, ft, f3s, f5s, fd
         REAL*8, DIMENSION(14)  :: h
         INTEGER  :: i    !DEFINIÇÃO DAS VARIÁVEIS A SEREM USADAS

         READ(2,*)h   !OS VALORES DE H SERÃO LIDOS DEUM ARQUIVO SEPARADO "fort.2" E ARMAZENADOS EM UM ARRAY

         x = 1    !O VALOR PEDIDO DE X É 1
         DO i = 1, 14
            ff = (f(x+h(i)) - f(x))/h(i) - der(x)   !CALCULO DO ERRO PARA FF
            ft =  (f(x) - f(x-h(i)))/h(i) - der(x)  !CALCULO DE ERRO PARA FT
            f3s = (f(x+h(i)) - f(x-h(i)))/(2*h(i)) - der(x)   !CALCULO DO ERRO PARA F3S
            f5s  =  (-f(x + 2*h(i)) + 8*f(x + h(i)) - 8*f(x - h(i)) + f(x - 2*h(i)))/(12*h(i)) - der(x)   !CALCULO DO ERRO PARA F5S
            fd =  (f(x+h(i)) - 2*f(x) + f(x-h(i)))/(h(i)**2) - der2(x)    !CALCULO DO ERRO PARA FD (SEGUNDA DERIVADA)
            WRITE(1,*)ABS(ff),',', ABS(ft),',', ABS(f3s),',', ABS(f5s),',', ABS(fd)   !ESCREVO OS VALORES OBTIDOS PARA CADA UM COMO TABELA
            !AS VÍRGULAS SÃO PARA FACILITAR A TRANSFORMÇÃO DOS RESULTADOS EM UMA TABELA CSV OU LEITURA POR OUTRO PROGRAMA, AO DEFINI-LA COMO DELIMITADOR
         ENDDO

      END PROGRAM
