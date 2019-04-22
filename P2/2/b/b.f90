    FUNCTION f(x) RESULT(r)   !DEFINO AQUI A FUNTÇÃO DESEJADA, PARA QUE SEJA MAIS FÁCIL CHAMÁ-LA
	      REAL*8  ::  x, r
      	r = EXP(2*x)*SIN(x)
		END FUNCTION

		PROGRAM integral
      IMPLICIT NONE

      REAL*8  ::  h, x, a, f, b
      INTEGER*8 ::  i, k, aux, N, j, aux2
      REAL*8  ::  Iboole, Itrap, Isim
	    REAL*8	::	S   !DEFINIÇÃO DAS VARÁVEIS QUE SERÃO USADAS
      a = 0d0
		  b = 1d0    !O INTERVALO DE INTEGRAÇÃO É [0,1] (a = 0, b = 1)
      S = (2*EXP(FLOAT(2))*SIN(FLOAT(1)) - EXP(FLOAT(2))*COS(FLOAT(1)) + 1)/5   !S É O VALOR "VERDADEIRO" DA INTEGRAL ENTRE a E b

		  DO j = 1, 13
		    h = 2d0**(-j)    !VARIO MEU h DE 2**-1 À 2**-13, CONFORME PEDIDO
        N = CEILING((b-a)/h)  !N (NÚMERO DE ITERAÇÕES) É DEFINIDO ARREDONDANDO PARA CIMA A DIVISÃO DO TAMANHO DO INTERVALO POR h
        aux2 = 1
      	aux = 0
      	k = 0    !VARIÁVEIS AUXILIARES RETORNAM PARA SEU VALOR INICIAL

        Iboole = 7*f(a) + 7*f(b)    !COMEÇO A INTEGRAL DE BOOLE COMO A SOMA DE SEU PRIMEIRO E ÚLTIMO VALORES MULTIPLICADOS POR 7
			  Isim = f(a) + f(b)   !COMEÇO A INTEGRAL DE SIMPSON COMO A SOMA DE SEU PRIMEIRO E ÚLTIMO VALORS MULTIPLICADOS POR 1
		    Itrap = 0.5*f(a) + 0.5*f(b)   !COMEÇO A INTEGRAL PELO TRAPÉZIO COMO A SOMA DE SEU PRIMEIRO E ÚLTIMO TERMOS DIVIDIDOS POR 2

      	DO i= 1, N-1   !VARIO MEU i DE 1 ATÉ O PENÚLTIMO TERMO, POIS ELE SERÁ USADO COMO MULTIPLICADOR DO h
          Isim = Isim + (2 + 2*aux2)*f(a + i*h)   !SOMO OS TERMOS DA INTEGRAL PELO MÉTODO DE SIMPSON
          aux2 = aux2 + (-1)**(i)   !aux2 VARIA ENTRE 0 E 1, DEFININDO SE O TERMI MULTIPLICADOR É 2 OU 4

				  Itrap = Itrap + f(a+ i*h)   !SOMO OS TERMOS DA INTEGRAL PELO MÉTODO DO TRAPÉZIO

          IF (MOD(i, 2) == 1) THEN
   		       Iboole = Iboole + 32*f(a + i*h)   !SOMO O TERMO MULTIPLICADO POR 32 CASO O ÍNDICE SEJA ÍMPAR
      	  ELSE
     		    Iboole = Iboole + (12 + 2*aux)*f(a + i*h)  !SOMO O TERMO MULTIPLICADO POR 12 ou 14 CASO O ÍNDICE SEJA PAR
      	    aux = aux + (-1)**k    !aux VARIA DE 0 E 1, DEFININDO SE O TERMO MULTIPLICADOR É 12 OU 14 PARA CADA ITERAÇÃO
            k = k + 1
      	  END IF

      	END DO
        Itrap = h*Itrap   !MULTIPLICO TODA A SOMA DA INTEGRAL PELO TRAPÉZIO POR h
        Isim = (h/3)*Isim   !MULTIPLICO TODA A SOMA DA INTEGRAL POR SIMPSON POR h/3
      	Iboole = (2*h/45)*Iboole   !MULTIPLICO TODA A SOMA DA INTEGRAL POR BOOLE POR 2h/45

        WRITE(1,*) h,',', ABS(Itrap - S),',', ABS(Isim - S),',', ABS(Iboole - S)    !ESVREVO O ERRO COMETIDO PARA CADA CASO, PARA CADA h, EM FORMA DE TABELA
      END DO

    END PROGRAM
