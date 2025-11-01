#include <stdio.h>
#include <string.h>
double x = 0, y = 0, a = 0, b = 0;
char c;


int adicao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    getchar();
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    getchar();
    printf("\n(Se escreveu uma entrada não numérica, por favor realizar a conta novamente)");
    printf("\nResultado: %lf + %lf = %lf", a, b, a + b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}

int subtracao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    getchar();
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    getchar();
    printf("\n(Se escreveu uma entrada não numérica, por favor realizar a conta novamente)");
    printf("\nResultado: %lf - %lf = %lf", a, b, a - b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}

int multiplicacao() {
    printf("Digite o primeiro número: ");
    scanf("%lf", &a);
    getchar();
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    getchar();
    printf("\n(Se escreveu uma entrada não numérica, por favor realizar a conta novamente)");
    printf("\nResultado: %lf * %lf = %lf", a, b, a * b);
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}


int divisao() {
    printf("\nDigite o primeiro número: ");
    scanf("%lf", &a);
    getchar();
    printf("\nDigite o segundo número: ");
    scanf("%lf", &b);
    getchar();
    if (b != 0) {
        printf("\n(Se escreveu uma entrada não numérica, por favor realizar a conta novamente)");
        printf("\nResultado: %lf/%lf = %lf", a, b, a/b);
    } else {
        printf("\nVocê não pode dividir por zero.");
    }
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}


int main() {
    while (x != 1 || x != 2 || x != 3 || x != 4 || x != 5) {
        printf("===============================\nCalculadora Simples\n===============================\nSelecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\n(Se você escolher uma entrada não numérica, escolha uma entrada numérica quando o código se repetir)\nOpção: ");
        scanf("%lf", &x);
        getchar();
        if (x == 1) {
            if (adicao()) {
                return 0;
            }
        } else if (x == 2) {     
            if (subtracao()) {
                return 0;
            }          
        } else if (x == 3) {    
            if (multiplicacao()) {
                return 0;
            }      
        } else if (x == 4) {      
            if (divisao()) {
                return 0;
            }        
        } else if (x == 5) {
            printf("\nObrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        } else {
            printf("\nSua opção é inválida.\n Favor prossegir e em seguida escolher outra opção: ");
            scanf("");
            getchar();
        }
    }
    x = 0;
}
 
