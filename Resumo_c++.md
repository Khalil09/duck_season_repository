# Guia de código C++

### Comandos de compilador:
```sh
g++ <nome_do_programa.cpp> && time ./a.out < in
```
Basicamente esse comando compila e executa o código, com um arquivo de entrada, em uma unica linha, mostrando o tempo ao final.

|Comando           |Função							                                                              |
|------------------|:---------------------------------------------------------------------------------|
|g++               |Executa o compilador de c++			                                                  |
|&& 			         |Executa um commando em seguida do outro                                           |
|time ./a.out < in |Executa o programa compilado com um arquivo entrada "in" e ao final mostra o tempo|

### Forma segura de tratamento para *floats* e *doubles*:

```cpp
scanf("%d.%d", &a, &b);
```
Dessa maneira é possível ler **"a"** como a parte inteira do número e **"b"** como a parte decimal. Assim basta multiplicar o valor de **"a"** pela quantidade de casas decimais que esta tratando e somar com **"b"**.

##### Exemplo:
```cpp
valor = a*100 + b;
```
