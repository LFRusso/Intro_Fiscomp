---
Title: Projeto 3: Movimento Realístico
Author: Luiz Fernando S. E. Santos
---

# Introdução
No presente projeto, realizamos a simulação de diversos tipos de movimento através de diferentes técnicas computacionais.
Ao passo que a linguagem Fortran 90 foi utilizada nas partes que requerem maior processamento, utilizei uma linguagem de alto nível (Python 3) para a representação gráfica e, algumas vezes, para uma pequena modificação dos resultados obtidos com o programa .f90. Este método especialmente interessante pois, ao passo que o Fortran é conhecido por ser uma linguagem de alta eficiência e é usado para as partes que requerem maior processamento do algoritmo, o Python oferece um modo rápido e dinâmico para a manipulação dos dados gerados, principalmente ao utilizarmos de bibliotecas como o Numpy e o Matplotlib e os dados como estruturas de arrays, tudo isso sem comprometer a eficiência do programa e oferecendo uma automação extra.
Em alguns casos, em que precisei plotar diversos conjuntos de dados juntos (vide exercício 2), optei por utilizar do programa Qtiplot para os gráficos.

# Métodos e Resultados

## 1 - Efeito resistivo do ar em movimento unidimensional

### A.

Considerando $\rho = 0$ e simulando o movimento unidimensional do ciclista, obtém-se o seguinte gráfico:

![velocidade x tempo](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/1/a/velpt.png)

É visível pelo gráfico que não há limite superior para a velocidade nesse caso. Utilizando o méto de Simpson para integração numérica no vetor contendo todas as velocidades e o intervalor dt de tempo, obtemos que a distância percorrida pelo ciclista foi de 11673.14148 m.

### B

Agora, considerando $\rho = 1.3 Kg/m^3$ e $A = 0.3 m^2$, obtemos o segunte gráfico da velocidade contra o tempo:

![velocidade x tempo](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/1/b/velpt.png)

Nesse caso, vemos que há um limite superior para a velocidade, sendo este a velocidade terminal de aproximadamente 12.7049 m/s. Para este caso, a distância percorrida pelo ciclista foi de 992.01137 m.

### C

Reproduzindo a simulação anterior, porém agora variando a área A, obtemos o seguinte resultado para cada valor de área:

![VxT em função da área](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/1/c/vararea.png)

Podemos ver que, quanto menor a área, maior a velocidade terminal do ciclista, o que também implica em um maior espaço percorrido. Podemos ver um exemplo disso quando um ciclista de abaixa na bicicleta, ficando com o tronco paralelo ao quadro da bicicleta e assim reduzindo sua área perpendicular ao vento:

![ciclista de speed; fonte: https://www.cyclingweekly.com/fitness/training/take-strava-kom-142795](https://keyassets.timeincuk.net/inspirewp/live/wp-content/uploads/sites/2/2014/11/increase-average-cycling-speed-1.jpg)


## 2 - Efeito resistivo do ar em movimentos bidimensionais

### A

Utilizando o programa para graficar a trajetória do projétil para cada um dos ângulos $\theta$, e considerando a resistência do ar igual à zero e logo após repetindo para ela sendo $\rho = 1.3 Kg/m^3$, obteve-se:

![trejetória em função de $\theta$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/a/lancamento_obliquo.png)

O que está e acordo com o esperado para este caso.

### B

Considerando $\rho = 1.3 Kg/m^3$ e variando o ângulo $\theta$ inicial do projétil, obteve-se a seguinte relação:

![](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/b/maxtheta.png)

### C

Repetindo os itens anteriores, agora com a resistência do ar variável, obtemos:

![posição do projétil, resistência do ar variável](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/c/lancamento_obliquo_2.png)

Podemos comparar ainda os casos da resistência do ar variável e constante:

![comparaçã $\rho$ fixo e variável](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/c/comparar.png)

É visível que há uma diferença considerável, principalmente sabendo que as distâncias estão em metros.

Agora, encontrando o novo valor para o ângulo que nos fornece o deslocamento máximo em X:

![](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/c/maxtheta.png)

### D

Considerando o $\theta_max$ encontrado anteriormente, variamos a velocidade inivial em $+/- 1%$ e obtemos as distãncias de 6126.2957 m para $V_0 = 373.33 m/s$ e de 6221.5287 m para $V_0 = 380.77 m/s$. Isso é uma diferença da ordem das centenas de metros, o que nos mostra quão difícil é mirar em uma área específica.

### E

Graficando a velocidade em função do tempo para as duas velocidades iniciais anteriores, obtemos o seguinte gráfico:

![velocidade x tempo](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/2/e/VxT.png)


## 3 - Pêndulo simples

### A

Utilizando o método de Euler, obtemos o seguinte gráfico para a variação do ângulo $\theta$ no tempo:

![$\theta$ x T](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/a/thetaxt.png)

Ao passo que a energia em função de tempo é:

![Energia Mecânia x T](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/a/ext.png)

É visível que algo não está certo, e o motivo disso é a não conservação da energia mecânica.

### B

Plotando o ângulo cotra a velocidade angular ($\theta x \omega$), obtemos:

![$\theta x \omega$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/b/thetaxomega.png)

O resultado esperado, ao realizarmos analiticamente a operação, era obter um espaço de fase fechado, levemente losangular, o que não pode ser observado.

### C

Repetimos os últimos ítens agora utilizando o método de Euler-Cromer. Os gráficos obtidos foram:

Utilizando o método de Euler, obtemos o seguinte gráfico para a variação do ângulo $\theta$ no tempo:

![$\theta$ e Energia Mecânica em função de T](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/c/eulercromer.png)

![$\theta x \omega$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/c/thetaxomega.png)

Agora os resultados foram mais próximos do esperado, com a diferença que a energia oscila, porém se conserva no ciclo.

### D

Agora calculo o período com base no tempo necessário para o ângulo retornar ao ao seu valor inicial. O intervalo $\Delta t$ deve ser grandes o bastante para que as oscilações da energia não interfiram significativamente na velocidade ao longo dos ciclos. Isso porque, como a energia mecânica varia no ciclo por conta das iterações, um número maior de iterações implica em mais pontos com a energia mecânica maior ou menor do que deveria. Porém $\Delta t$ também não pode ser grande demais, para que não se perca precisão.

Variando o ângulo inicial e graficando o período em função dele, obtemos:

![período x $\theta_max$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/d/thetaxper.png)

### E

Para o método de Verlet, obtemos os seguintes gráficos:

![$\theta$ e Energia Mecânica em função de T](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/e/verlet.png)

![$\theta x \omega$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/e/thetaxomega.png)

O que é basicamente igual ao obtido pelo método de Euler-Cromer

Quanto ao gráfico do período em função do ângulo inicial:

![período x $\theta_max$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/3/e/thetaxper.png)


## 4 - Estabilização dinâmica

### A

Plotando o gráfico para o método de Euler, Eule-Cromer e Verlet, obtemos:

![Euler](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/a/euler.png)
![Euler-Cromer](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/a/euler_cromer.png)
![Verlet](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/a/verlet.png)

Os resultados para Euler e Verlet foram basicamente os mesmos. Suponho que o motivo disso seja a não necessidade da conservação da energia mecânica no movimento nesse caso.

Agora, utilizando o método de Verlet e pegando seus pontos de máximo local, obtemos:

![Maximos Locais](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/a/extremos.png)

Pegamos então estes pontos e, tirando o logaritmo do eixo de $\theta$, podemos realizer um fitting linear, obtendo a constante de amortecimento como coeficiente ângular:

![linearização](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/a/linearfit.png)

O valor do coef. de amortecimento está de acordo com o esperado para -b/2 (b = 0.05), e mostra que a oscilação é subamortecida.

### B

Variando o valor de $\nu$ de 0 até 20, observamos que existe um valor a partir do qual o valor de $|\theta(\tau)|_{min}$ muda e se estabiliza:

![variação de $\nu$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/b/data.png)

Nesse caso, o valor para o qual isso ocorre é 8.6.

### C

Agora, variando $\theta_0$ e calculando o valor de $\nu*$ para cada valor, obtemos a seguinte relação:

![$\theta_0$ x $\nu*$](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/c/graph.png)

Porém ela não segue a relação $\alpha^2 * \nu*^2 * cos(\theta_0) = 2$. Também não vejo como a relação serviria para valores de $\theta_0$ que resultassem em um cosseno negativo.

### D

Para obter os parâmetros desejados, primeiramente gero a função desejada, utilizando o método de Verlet, para $\nu = 40$. Após isso, utilizo o programa Qtiplot para fittar em minha função apenas a componente lenta, visando reduzir o número de parãmetros e partindo do pressuposto que ela dominará sobre a rápida. Os valores obtidos foram:

![fitting slow](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/d/thetaslow.png)

Utilizando esses parâmetros, realizo agora o fitting da funçã completa:

![fitting slow + fast](https://github.com/LFRusso/IntroFiscomp/blob/master/P3/4/d/thetafast.png)




