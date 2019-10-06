# numerical-calculus
Repositório criado para praticar os métodos utilizados na máteria MAT174 - Cálculo Numérico, ministrada por Rafaela Souza Alcântara 

## Organização
Esse repositório está organizado de acordo os tipos de métodos:  
- [Métodos iterativos para equações não lineares](iterative-methods-for-non-linear-equations):  
    - **Método da Bisseção**:  
    Regido pelo Teorema do Valor Intermediário, o Método da Bisseção consiste em uma busca binária dentro de um intervalo [a,b] dado até que se satisfaça o critério de parada onde |a-b| < epsilon.  

    > Teorema do Valor Intermediário: se f(a)f(b) < 0, então existe raiz de f(x) nesse intervalo [a, b]. 
    
    Então, pegamos x sendo a metade do intervalo [a, b] e considerando momentaneamente o intervalo sendo [a, x] verificamos se x satisfaz o Teorema: se sim, assumimos, de fato, o intervalo [a, x] para a próxima iteração, pois a raiz estará nesse intervalo; caso contrário, a raiz estará no intervalo [x, b].
    
    - **Método do Ponto Fixo ou Método da Iteração Linear**:  
    O método consiste em separar uma função f(x) em duas: uma g(x), função linear, e h(x), uma curva de forma que g(x) + h(x) = f(x). Dado essa curva, um raiz inicial k válido é aquele em que aplicando k na derivada da curva tenhamos um número, em valores absolutos, menor ou igual a 1:  

    > Proposição I: |h'(k)| <= 1  
    
    Uma vez encontrado essa g(x) que satisfaça a Proposição I, o método projeta pontos de g(x) nessa h(x) até que a diferença, em termos absolutos, entre dois resultados dessas projeções.    
- [Métodos iterativos para equações algébricas](iterative-methods-for-algebric-equations):  

    > Proposição II: f(x)f''(x) > 0  
    
    - **Método de Newton**:  
    Dado um ponto A da função f(x) que respeite a Proposição II, o método consiste em projetar uma reta tangente a f(x), passando por A, até um ponto B que intercepta o eixo das abscissas. As iterações param quando a diferença entre A e B, em valores absolutos, for menor que epsilon.
    
    - **Método das Cordas ou Método da Secante**:  
    Semelhantemente ao Método de Newton, o método das cordas, usando a mesma Proposição II, consiste em projetar uma reta secante passando por dois pontos A e B pertecentes à função, até um ponto C no eixo das abscissas. As iterações param quando a diferença enre B e C, em termos absolutos, for menor que epsilon. 
- [Resolução de sistemas lineares](linear-system-resolution):  
    - **Eliminação de Gauss**:  
    Dado um sistema linear, transforma-o em um sistema triangular superior, onde todas as posições abaixo da diagonal principal são nulas
    
    - **Jordan**:  
    Dado um sistema linear, transforma-o em um sistema diagonal, onde todas as posições, exceto a diagonal principal, são nulas.
    
    - **Jacobi**:  
    
    - **Gauss-Seidel**:  
