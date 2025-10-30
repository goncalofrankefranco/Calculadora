#include <stdio.h>
#include <string.h>
double x = 0, y = 0, a = 0, b = 0;
int d, c; //d de dê me paciência kkkk


int adicao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    printf("\nResultado: %lf + %lf = %lf", a, b, a + b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%d", &c);
    while (c != 's' && c != 'n') {
        if (c == 's')
        {
            return 0;
        } else if (c == 'n') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        } else {
            if (d == 0) {
                d++;
            } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%d", &c);
            }
        }
    }
}

int subtracao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    printf("\nResultado: %lf - %lf = %lf", a, b, a - b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%d", &c);
    while (c != 's' && c != 'n') {
        if (c == 's')
        {
            return 0;
        } else if (c == 'n') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        } else {
            if (d == 0) {
                d++;
            } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%d", &c);
            }
        }
    }
}

int multiplicacao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    printf("\nResultado: %lf * %lf = %lf", a, b, a * b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%d", &c);
    while (c != 's' && c != 'n') {
        if (c == 's')
        {
            return 0;
        } else if (c == 'n') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        } else {
            if (d == 0) {
                d++;
            } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%d", &c);
            }
        }
    }
}

int divisao() {
    printf("\nDigite o primeiro número: ");
    scanf("%lf", &a);
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    while (b == 0) {
        if (b == 0) {
            printf("\nNão é possível dividir por 0. Por favor escolha outro número: ");
            scanf("%lf", &b);
        }
    }
    printf("\nResultado: %lf/%lf = %lf", a, b, a/b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%d", &c);
    while ((c != 's' && c != 'n') && c != '\0') {
        if (c == 's')
        {
            return 0;
        } else if (c == 'n') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        } else {
            if (d == 0) {
                d++;
            } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%d", &c);
            }
        }
    }
}

int main() {
    while (x != 1 || x != 2 || x != 3 || x != 4 || x != 5) {
            printf("===============================\nCalculadora Simples\n===============================\nSelecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção: ");
            scanf("%lf", &x);
            getchar();
            if (x == 1) {
                if (d != 0) {
            d = 0;
        }
                adicao();
            } else if (x == 2) {
                if (d != 0) {
            d = 0;
        }        
                subtracao();
            } else if (x == 3) {
                if (d != 0) {
            d = 0;
        }        
                multiplicacao();
            } else if (x == 4) {
                if (d != 0) {
            d = 0;
        }        
                divisao();
            } else if (x == 5) {
                printf("\nObrigado por usar a calculadora! Até a próxima.\n");
                return 0;
            } else {
                if (d == 0)
        {
            d++;
                } else {
                    printf("\nSua opção é inválida.\n Favor escolher outra opção: ");
                    scanf("%lf", &x);
                }
        }
    } 
}
