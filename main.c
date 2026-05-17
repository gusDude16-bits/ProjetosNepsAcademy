#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

// Função para o menu:

void limparTela();
int menu();
char continuar();

// Funções para as operações aritméticas: 

void adicao(double a, double b);
void subtracao(double a, double b);
void divisao(double a, double b);
void multiplicacao(double a, double b);
void inserirValores(double *x, double *y);

// Função principal:

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    while(1) {
        int opcao = menu();
        
        if (opcao == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }

        double a, b;
        inserirValores(&a, &b);

        switch (opcao) {
            case 1:
                adicao(a, b);
                break;
            case 2:
                subtracao(a, b);
                break;
            case 3:
                multiplicacao(a, b);
                break;
            case 4:
                if (b == 0) {
                    printf("Erro: Divisão por zero não é permitida.\n");
                } else {
                    divisao(a, b);
                }
                break;
        }

        if (continuar() == 'S') {
            limparTela();
        } else {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }
    }
    return 0;
}

// Ações das funções declaradas em cima:

void limparTela() {
    #ifdef _WIN32
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
    printf("5. Sair\n");
    printf("Opção: ");
    scanf("%d", &opcaoMenu);
    while (opcaoMenu < 1 || opcaoMenu > 5) {
        printf("Opção inválida! Insira uma opção de 1 a 5.\n");
        printf("Opção: ");
        scanf("%d", &opcaoMenu);
    }
    return opcaoMenu;
}

char continuar() {
    char opcaoDesejada;
    do {
        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &opcaoDesejada);
        opcaoDesejada = toupper(opcaoDesejada);
        if(opcaoDesejada != 'S' && opcaoDesejada != 'N') {
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
        }
    } while (opcaoDesejada != 'S' && opcaoDesejada != 'N');
    return opcaoDesejada;
}

void inserirValores(double *x, double *y) {
    printf("Digite o primeiro número: ");
    scanf("%lf", x);
    printf("Digite o segundo número: ");
    scanf("%lf", y);
}

void adicao(double a, double b) {
    printf("Resultado: %g + %g = %g\n", a, b, a + b);
}

void subtracao(double a, double b) {
    printf("Resultado: %g - %g = %g\n", a, b, a - b);
}

void multiplicacao(double a, double b) {
    printf("Resultado: %g * %g = %g\n", a, b, a * b);
}

void divisao(double a, double b) {
    printf("Resultado: %g / %g = %g\n", a, b, a / b);
}
