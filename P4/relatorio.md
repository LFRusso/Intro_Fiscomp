---
title: Projeto 4
author: Luiz Fernando S E Santos
---
# Introdução

## Breve resumo: C++ e orientação a objetos

Os programas principais desse projeto foram feitos na linguagem C++. Assim como o Fortran, o C++ é uma linguagem de baixo nível com alta eficiência, competindo com o Fortran nesse quesito. Algumas vantagens do C++ como linguagem, porém, são:

- **Existência de uma comunidade ativa:** Diferente do Fortran que é extremamente restrito à um nicho específico de usuários, o C++ é há anos uma das linguagem mais usadas em todo o mundo. Isso implica em não apenas ela ser popular em fóruns de dúvidas específicas, mas também em uma abundância de materiais e bibliotecas muito bem otimizadas.
- **Sintaxe:** O C++ apresenta uma sintaxe razoavelmente mais simples que o Fortran. Embora não seja dinâmico como o Python, por exemplo (o que poderia vir com perdas consideráveis de eficiência), pode-se dizer que ele é mais intuitivo e direto na manipulação de variáveis, classes e funções. Isso também torna um código em C++ mais fácil de ser lido por terceiros.
- **Orientação a objetos:** A orientação a objetos pode ser facilmente implementada, o que eu também facilita em diversos casos tanto na escrita quanto leitura do código.

A orientação a objetos foi utilizada nos códigos desse projeto visando criar uma forma mais geral na manipulação dos astros. O armazenamento dos parâmetros de cada astro em uma variável do tipo `planet` definido pelo usuário evita a necessidade do uso de diversas listas, o que poderia se tornar motivo de grande confusão em programas maiores. As funções definidas nas classes (ou `métodos`) também são de grande ajuda principalmente ao calcular diversas vezes as características dos astros.
Quanto à compilar os programas .cpp, basta escrever no terminal:

```g++ programa.cpp -o programa.exe```

Recomendo, porém, utilizar a otimização -O3 ou -O2 do compilador:

```g++ -O3 programa.cpp -o programa.exe```

Neste último caso, talvez o compilador indique um `Warning` após a compilação devido ao uso de uma `string` na função`system()` do programa. O programa, entretanto, será compilado sem nenhum problema.
Esta última função será usada para executar direto os .py, que por sua vez lêem o .dat gerado e plotam os gráficos resultantes.

## O projeto

No presente projeto, foi simulado usando o método de Euler-Cromer e de Runge-Kutta o movimento de corpos celestes. Também foi feita a simulação, usando Runge-Kutta de ordem 4 para a dinâmica de 3 corpos, para difenrentes posições e velocidades iniciais, com o objetivo de ver como os sistemas evoluem.

# Métodos e Resultados

## 1.O problema de dois corpos: orbitas limitadas

### ( a )

Para este exercício simplesmente considero as equações 

$v_{x, i+1} = V_{x, i} - \Delta\tau\rho_{x, i}/{\rho_{i}}^2$
$v_{y, i+1} = V_{y, i} - \Delta\tau\rho_{y, i}/{\rho_{i}}^2$
$\rho_{x,i+1} = \rho_{x, i} + v_{x, i+1}\Delta\tau$
$\rho_{y,i+1} = \rho_{y, i} + v_{y, i+1}\Delta\tau$

Dado os valores iniciais do meu planeta, itero estas equações para um intervalo de tempo determinado. O valor do raio R e da velocidade V do planeta ao longo do tempo para o planeta foram plotados em formato de gráfico, obtendo:

![imagem 1](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/a/grafico.png)

Podemos ver que, como é esperado para o método de Euler-Cromer, a velocidade e o raio variam. Isto vem do fato da energia variar, embora ela se conserve no ciclo.

### ( b )

Primeiramente, para testar se 

$\rho = (a, 0)$
$V = (0, 1/\sqrt{a})$
 
Resulta em uma órbita circular para todos os planetas do sistema solar, testo para cada um. Para isso, defino a classe `planet` e crio todos os planetas, de Mercúrio até Urano, como objetos. Iterando isso obtemos as seguintes órbitas:

![imagem 2](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/b/orbita.png)
(embora a escala do gráfico não colabore, acredite, elas são circulares)

Agora, para ver como o valor de $\delta = \rho_{max}/\rho_{min} - 1$ varia com $d\tau$, ploto o seguinte gráfico para o raio inicial sendo igual ao raio da Terra (1). Assim, obtemos:

![imagem 3](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/b/delta_dt.png)

É visível que resulta em uma reta. Desse gráfico, também tiramos que o valor de $d\tau$ que resulta em $\delta < 10^{-3}$ é $d\tau = 0.0009$. Podemos testar, como mostrado a seguir:

![imagem 4](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/b/excentr.png)

Podemos também variar o módulo do raio e ver como o $d\tau_{max}$, o valor de $d\tau$ que resulta em $\delta < 10^{-3}$ varia com ele. Assim obtemos:

![imagem 5](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/b/a_dt.png)

Vale avisar que a curva em vermelho traçada **não é um fitting** e está lá só para mostrar que os valores variam proporcionalmente à ela.

Essa relação está estreitamente relacionada com a terceira lei de Kepler, que diz que:

$(R_a/R_b)^3 = (T_a/T_b)^2$

Se considerarmos que $d\tau$ deve ser proporcional ao período, ele também deve seguir esta relação de proporcionalidade com o raio.

### ( c )

Agora, implemento o método de Runge-Kutta de ordem 4 ao programa. Isso é feito em dois métodos da classe `planet`: a primeira, dado a velocidade e a posição do planeta calcula $F^{(i)}_j$, $i, j = 1, 2, 3, 4$. Com os valores de $F$, agora iteramos os próximos valores da posição e velocidade do astro.
Usando esse método, podemos ver que a órbita resultante é visualmente muito similar à obtida por Euler-Cromer:

![imagem 6](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/c/trajec.png)

Mas plotando o gráfico da velocidade e do módulo do raio pelo tempo, obtemos:

![imagem 7](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/c/orbita_RK.png)

Embora hajam algumas oscilações, podemos ver pelo eixo **y** que elas são muito pequenas. Isso coincide com o esperado para a conservação da energia para este método.

### ( d )

Num programa igual ao descrito em **c**, agora consideramos $d\tau = d\tau_{max}$ calculamos e salvamos o gráfico de energia mecânica e raio por tempo para o método de Euler-Cromer e Runge-Kutta, obtendo:

![imagem 8](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/d/EM.png)

![imagem 9](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/1/d/Rxt.png)

Como dito antes, a variação da energia mecânica é muito menor do que no caso de Euler-Cromer, e isso reflete na velocidade e no raio.

## 2.Sol, Terra e Júpiter

### ( a )

No caso de três corpos, o Runge-Kutta de ordem 4 continua sendo:

$\rho_{x, i+1} = \rho_{x, i} + \Delta\tau(F_{1, i}^{(1)} + 2F_{1, i}^{(2)} + 2F_{1, i}^{(3)} + F_{1, i}^{(4)})/6$
$\rho_{y, i+1} = \rho_{y, i} + \Delta\tau(F_{2, i}^{(1)} + 2F_{2, i}^{(2)} + 2F_{2, i}^{(3)} + F_{2, i}^{(4)})/6$
$V_{x, i+1} = V_{x, i} + \Delta\tau(F_{3, i}^{(1)} + 2F_{3, i}^{(2)} + 2F_{3, i}^{(3)} + F_{3, i}^{(4)})$
$V_{y, i+1} = V_{y, i} + \Delta\tau(F_{4, i}^{(1)} + 2F_{4, i}^{(2)} + 2F_{4, i}^{(3)} + F_{4, i}^{(4)})$

A unica diferença, agora, é que:

$F_{3, i}^{(j)} = -A_{x, i}^{(j)}$
$F_{4, i}^{(j)} = -A_{y, i}^{(j)}$

Sendo a aceleração $A$ definida pela posição e a massa dos demais planetas. É importante frisar que essa aceleração encontrada para calcular os valores de $F$ depende de $\rho_i$ de cada iteração. Isse quer dizer que precisaremos iterar todos os planetas jutos e encontrar o $rho_i$ de cada um para assim podermos calcular $A_i$ de cada.

### ( b )

Agora, com as equações descritas em **(a)**, fazemos as interações. Como desta vez precisamos definir a aceleração de cada planeta em cada momento, e visto que isso depende da posição dos demais astros, defino o método `Relate()`, que é aplicado em casa astro e recebe os outros dois restantes como parâmetros. Exemplo:

```Terra.Relate(Júpiter, Sol);```

Calcula a aceleração da Terra de acordo com os estados de Júpiter e do Sol. Isso deve ser feito no início de cada iteração, para atualizar as acelerações para as novas posições de casa astro.
Depois disso, precisamos obter os valores de $F$ para **cada um dos astros**. Para fazer isso defino a função `get_F()` que recebe, além do passo temporal $d\tau$ que está sendo usado, todos os astros que estão sendo iterados.
É muito importante que essa parte seja feita para os três ao mesmo tempo, pois o cálculo de $F$ considera valores de R e V de **outros** planetas obtidos exclusivamente para este cálculo. Como a distância entre os astros depende de R de cada um, é importante que esses "novos" valores de R sejam considerados.

O gráfico obtido para as órbitas usando esse programa foi:

![imagem 10](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/2/b/orbita.png)

Quanto ao gráfico do raio R da órbita da Terra ao longo do tempo foi:

![imagem 11](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/2/b/Rxt.png)

Podemos ver que o valor do raio não é muito estável ao longo do tempo. Também podemos reparar, se tomarmos um longo período te tempo, que o Sol está se deslocando, e sabendo que o raio está sendo medido em relação à (0,0), esta movimentação do Sol, que também causa uma movimentação da Terra e de Júpiter, com certeza influencia nesse resultado.
Não pude identificar o motivo para essa movimentação inesperada do Sol

### ( c )

Agora, no mesmo programa que o descrito em **(b)**, multiplico a massa de Júpiter por 100 e o resultado obtido é:

![imagem 12](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/2/c/orbita.png)

![imagem 13](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/2/c/Rxt.png)

Concluímos que provavelmente não seria uma boa ideia aumentar a massa de Júpiter em 100x.

## 3.Coreografias celestes

### ( a )

Para este caso, consideramos as posições e velocidades iniciais dadas e observamos como o sistema evolui em um dado intervalo de tempo. Desta forma, obtemos:

![imagem 14](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/3/a/orbita.png)

É esperado que a distância entre os planetas (de um em relação ao outro) se mantenham constantes ao longo do tempo. Para testar isso, messo cada iteração a distância de um ao outro (de 1 com 2, de 1 com 3 e de 2 com 3). Desta forma, obtemos:

![imagem 15](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/3/a/distancias.png)

Neste gráfico vemos apenas o traçado verde pois foi o último a ser plotado. Isso mostra que as distâncias de um em relação ao outro são sempre iguais no nosso intervalo de tempo.

### ( b )

Usando as condições iniciais dadas para posição e velocidade dos planetas e deixando o sistema evoluir em um dado intervalo de tempo, obtemos:

![imagem 16](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/3/b/orbita.png)

Dando zoom no centro disso:

![imagem 17](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/3/b/centro.png)

### ( c )

Agora, com as novas condições iniciais:

![imagem 18](https://raw.githubusercontent.com/LFRusso/Intro_Fiscomp/master/P4/3/c/orbita.png)
