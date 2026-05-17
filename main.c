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
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    divisao(a, b);
                }
                break;
        }

        if (continuar() == 'Y') {
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
    
    while (1) {
        printf("Opção: ");
        if (scanf("%d", &opcaoMenu) == 1 && opcaoMenu >= 1 && opcaoMenu <= 5) {
            break; 
        } else {
            while (getchar() != '\n'); 
            printf("Opção inválida! Insira uma opção de 1 a 5.\n");
        }
    }
    return opcaoMenu;
}

char continuar() {
    char opcaoDesejada;
    do {
        printf("Deseja realizar outra operação? (y/n): ");
        scanf(" %c", &opcaoDesejada);
        
        while (getchar() != '\n'); 
        
        opcaoDesejada = toupper(opcaoDesejada);
        
        if(opcaoDesejada != 'Y' && opcaoDesejada != 'N') {
            printf("Resposta inválida. Por favor, digite 'y' para sim ou 'n' para não.\n");
        }
    } while (opcaoDesejada != 'Y' && opcaoDesejada != 'N');
    
    return opcaoDesejada;
}

void inserirValores(double *x, double *y) {
    printf("Enter the first number: ");
    scanf("%lf", x);
    printf("Enter the second number: ");
    scanf("%lf", y);
}

void adicao(double a, double b) {
    printf("Result: %g + %g = %g\n", a, b, a + b);
}

void subtracao(double a, double b) {
    printf("Result: %g - %g = %g\n", a, b, a - b);
}

void multiplicacao(double a, double b) {
    printf("Result: %g * %g = %g\n", a, b, a * b);
}

void divisao(double a, double b) {
    printf("Result: %g / %g = %g\n", a, b, a / b);
}
