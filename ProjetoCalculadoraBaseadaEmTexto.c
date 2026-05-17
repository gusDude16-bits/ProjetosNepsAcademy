#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

// Função para o menu:

void limparTela();
int menu();
char continuar();

// Funções para as operações aritméticas: 

void adicao(int a, int b);
void subtracao(int a, int b);
void divisao(int a, int b);
void multiplicacao(int a, int b);
void inserirValores(int *x, int *y);

// Função principal:

int main() {
    setlocale (LC_ALL, "Portuguese_Brazil");
    while(1) {
        int opcao = menu();
        switch (opcao) {
            case 1: {
                int a, b;
                inserirValores(&a, &b);
                adicao(a, b);
                getchar();
                if (continuar() == 'S') {
                    limparTela();
                    break;
                }
                else {
                    printf("Obrigado por usar a calculadora! Até a próxima.\n");
                    opcao = 5;
                    break;
                }
            }
            case 2: {
                int a, b;
                inserirValores(&a, &b);
                subtracao(a, b);
                getchar();
                if (continuar() == 'S') {
                    limparTela();
                    break;
                }
                else {
                    printf("Obrigado por usar a calculadora! Até a próxima.\n");
                    opcao = 5;
                    break;
                }
            }
            case 3: {
                int a, b;
                inserirValores(&a, &b);
                multiplicacao(a, b);
                getchar();
                if (continuar() == 'S') {
                    limparTela();
                    break;
                }
                else {
                    printf("Obrigado por usar a calculadora! Até a próxima.\n");
                    opcao = 5;
                    break;
                }
            }
            case 4: {
                int a, b;
                inserirValores(&a, &b);
                do {
                    if (b == 0)
                        printf("Erro: Divisão por zero não é permitida.\n\n");
                        printf("Insira um valor adequado: ");
                        scanf("%d", &b);
                } while (b == 0);
                divisao(a, b);
                getchar();
                if (continuar() == 'S') {
                    limparTela();
                    break;
                }
                else {
                    printf("Obrigado por usar a calculadora! Até a próxima.\n");
                    opcao = 5;
                    break;
                }
            }
            case 5:
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                break;
        }
        if(opcao==5)
            break;
    }
    return 0;
}

// Ações das funções declaradas em cima:

void limparTela() {
    #ifdef _Win32
        system("cls");
    #else
        system("clear");
    #endif
}

int menu() {
    int opcaoMenu;
    printf("===============================\n   Calculadora Simples\n===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair.\n");
    printf("Opção: ");
    scanf("%d", &opcaoMenu);
    while (opcaoMenu < 0 && opcaoMenu > 5) {
        printf("Opcão inválida! Insira uma opção de 1 a 5.\n");
        scanf("%d", &opcaoMenu);
    }
    return opcaoMenu;
}

char continuar() {
    char opcaoDesejada;
    while (toupper(opcaoDesejada)!='S' && toupper(opcaoDesejada)!='N') {
        printf("Deseja realizar outra operação? (s/n): ");
        scanf("%c", &opcaoDesejada);
        if(toupper(opcaoDesejada)!='S' && toupper(opcaoDesejada)!='N')
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
    }
    return toupper(opcaoDesejada);
}

void inserirValores(int *x, int *y) {
    printf("Digite o primeiro número: ");
    scanf("%d", x);
    printf("Digite o segundo número: ");
    scanf("%d", y);
}

void adicao(int a, int b) {
    printf("\n%d + %d = %d\n\n", a, b, a+b);
}

void subtracao(int a, int b) {
    printf("\n%d - %d = %d\n\n", a, b, a-b);
}

void multiplicacao(int a, int b) {
    printf("\n%d * %d = %d\n\n", a, b, a*b);
}

void divisao(int a, int b) {
    printf("\n%d / %d = %.1lf\n\n", a, b, (double)a/b);
}