cmake_minimum_required(VERSION 4.2)
project(estudos)

set(CMAKE_CXX_STANDARD 14)

add_executable(estudos
        fscanf-exercicios/ex1.c
        fscanf-exercicios/ex2.c
        fscanf-exercicios/ex3.c
        fscanf-exercicios/ex4.c
        fscanf-exercicios/ex5.c
        fscanf-exercicios/ex6.c
        fscanf-exercicios/ex7.c
        fscanf-exercicios/exercicios.txt
        fscanf-exercicios/pessoa.txt
        prog2/pilhas/labirinto.c
        testes/adivinhacaofor.c
        testes/adivinhacaowhile.c
        testes/imprimirfor.c
        testes/simp2.c
        testes/tabuada.c
        testes/varrerarray.c
        testes/voidparameters.c
        cadastro.c
        prog2.c
        prog2/pilhas/push.c)
