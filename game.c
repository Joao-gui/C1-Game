/**
 * @file game.c
 * @author your name (you@domain.com)
 * @brief Estrutra main do game
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
    Sequencia da estrutra conforme projeto profissional
    - Import das bibliotecas
    - Declaração das Structs (caso precise).
    - Declaração das funções que serão implementadas.
    - Função main
    - Implementação de todas as funções declaradas.
*/

#include <stdio.h>
#include <stdlib.h>

// Criando a estrutura do Calcular
typedef struct{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrar_info(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

// Variável Global
int pontos = 0;

int main(){
    // Deve ser chamado apenas 1 vez, gera a aletoriedade
    srand(time(NULL));
    jogar();    
    return 0;
}

void jogar(){
    Calcular calc;
    int dificuldade;

    printf("Informe o nivel de dificuldade desejada [1, 2, 3 ou 4]:\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    // Gera um valor inteiro randômico entre 0 e 2
    // 0 == Somar, 1 == Diminuir e 2 == Multiplicar
    // rand vem do stdlib.h e quando passa o srand(time(NULL))
    calc.operacao = rand() % 3; 

    if(calc.dificuldade == 1){
        // Fácil
        calc.valor1 = rand() % 11; // Gera valor randomico entre 0 a 10
        calc.valor2 = rand() % 11;
    }
    else if (calc.dificuldade == 2){
        // Média
        calc.valor1 = rand() % 101; // 0 a 100
        calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3){
        // Difícil
        calc.valor1 = rand() % 1001; // 0 a 1000
        calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4){
        // Insano
        calc.valor1 = rand() % 10001; // 0 a 10000
        calc.valor2 = rand() % 10001;
    }
    else{
        // Nível secreto (Ultra)
        calc.valor1 = rand() % 100001; // 0 a 100000
        calc.valor2 = rand() % 100001;
    }
    int resposta;
    printf("Informe o resultado para a seguinte operacao: \n");

    //Somar
    if (calc.operacao == 0){
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(somar(resposta, calc)){
            pontos += 1;
            printf("Voce tem %d ponto(s).\n", pontos);
        }
    }
    // Diminuir
    else if (calc.operacao == 1){
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (diminuir(resposta, calc)){
            pontos += 1;
            printf("Voce tem %d ponto(s).\n", pontos);
        }        
    }
    // Multiplicar
    else if (calc.operacao == 2){
        printf("%d * %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (multiplicar(resposta, calc)){
            pontos += 1;
            printf("Voce tem %d ponto(s).\n", pontos);
        }        
    }
    // Desconhecido
    else{
        printf("A operacao %d nao e reconhecida\n.", calc.operacao);
    }

    // Recomeçar o jogo
    printf("Deseja continuar jogando? [1 - SIm, 0 - Não]\n");
    int continuar;
    scanf("%d", &continuar);

    if (continuar == 1){
        jogar();
    }
    else{
        printf("Voce finalizou com %d ponto(s).\n", pontos);
        exit(0);
    }          
}

void mostrar_info(Calcular calc){
    char op[25];

    // Operação 0 será somar
    if (calc.operacao == 0)
    {
        sprintf(op, "Somar");
    }
    // Operação 1 será diminuir
    else if (calc.operacao == 1)
    {
        sprintf(op, "Diminuir");
    }
    // Operação 2 será multiplicar
    else if (calc.operacao == 2)
    {
        sprintf(op, "Multiplicar");
    }
    else
    {
        sprintf(op, "Operacao desconhecida");
    }
    printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s", calc.valor1, calc.valor2, calc.dificuldade, op);    
}

int somar(int resposta, Calcular calc){
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    // 0 == errou e 1 == acertou
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta Correta. \n");
        certo = 1;
    }
    else
    {
        printf("Resposta Errada.\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int diminuir(int resposta, Calcular calc){
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    // 0 == errou e 1 == acertou
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta Correta. \n");
        certo = 1;
    }
    else
    {
        printf("Resposta Errada.\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, Calcular calc){
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    // 0 == errou e 1 == acertou
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta Correta. \n");
        certo = 1;
    }
    else
    {
        printf("Resposta Errada.\n");
    }
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}