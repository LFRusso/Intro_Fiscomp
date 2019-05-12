# Introdução

## Breve resumo: C++ e orientação a objetos

Os programas principais desse projeto foram feitos na linguagem C++. Assim como o Fortran, o C++ é uma linguagem de baixo nível com alta eficiência, competindo com o Fortran nesse quesito. Algumas vantagens do C++ como linguagem, porém, são:

- **Existência de uma comunidade ativa:** Diferente do Fortran que é extremamente restrito à um nicho específico de usuários, o C++ é há anos uma das linguagem mais usadas em todo o mundo. Isso implica em não apenas ela ser popular em fóruns de dúvidas específicas, mas também em uma abundância de materiais e bibliotecas muito bem otimizadas.
- **Sintaxe:** O C++ apresenta uma sintaxe razoavelmente mais simples que o Fortran. Embora não seja dinâmico como o Python, por exemplo (o que poderia vir com perdas consideráveis de eficiência), pode-se dizer que ele é mais intuitivo e direto na manipulação de variáveis, classes e funções. Isso também torna um código em C++ mais fácil de ser lido por terceiros.
- **Orientação a objetos:** A orientação a objetos pode ser facilmente implementada, o que eu também facilita em diversos casos tanto na escrita quanto leitura do código.

A orientação a objetos foi utilizada nos códigos desse projeto visando criar uma forma mais geral na manipulação dos astros. O armazenamento dos parâmetros de cada astro em uma variável do tipo `planet` definido pelo usuário evita a necessidade do uso de diversas listas, o que poderia se tornar motivo de grande confusão em programas maiores. As funções definidas nas classes (ou `métodos`) também são de grande ajuda principalmente ao calcular diversas vezes as características dos astros.
Quanto à compilar os programas .cpp, basta escrever no terminal:

g++ programa.cpp -o programa.exe

Recomendo, porém, utilizar a otimização -O3 ou -O2 do compilador:

g++ -O3 programa.cpp -o programa.exe

Neste último caso, talvez o compilador indique um `Warning` após a compilação devido ao uso de uma `string` na função`system()` do programa. O programa, entretanto, será compilado sem nenhum problema.
Esta última função será usada para executar direto os .py, que por sua vez lêem o .dat gerado e plotam os gráficos resultantes.

## O projeto
