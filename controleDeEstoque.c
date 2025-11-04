#include <stdio.h>
#include <string.h>
double x = 0;
char c;
char string[106], check[107], nada[106];
int a = 0, b = 0, count = 0, countA = 0, i = 0;
FILE *p = fopen("estoque.txt", "w");

int numeroDeAlgarismos(int a) {
    countA++;
    if (a/10 > 1) {
        return countA;
        countA = 0;
    } else {
        numeroDeAlgarismos(a/10);
    }
}

int adicionarItem() {
    printf("\n(Máximo 100 caracteres)\nDigite o nome do item: ");
    scanf("%s", string);
    
    printf("\nDigite a quantidade: ");
    scanf("%d", &a);
    getchar();
    printf("\n(Se escreveu uma entrada não numérica, por favor adicionar novamente)");
    
    if(p == NULL || a < 0) {
        printf("\nHouve um erro ao adicionar o produto.");
    } else {
        fprintf(p, "Nome: %s\n Quantidade: %d", string, a);
        printf("\nItem adicionado com sucesso!");
        count++;
    }
    
    printf("\nDeseja realizar outra ação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}

int removerItem() {
    if(p == NULL) {
        printf("\nHouve um erro ao abrir o estoque.");
    } else {
        fprintf(p, "%s\n%d", string, a);
        printf("\nEstoque aberto com sucesso!");
    }
    
    printf("\n(Máximo 100 caracteres)\nDigite o nome do item: ");
    scanf("%s", string);
    
    int count2 = 0;
    for(i = 0; i < count; i++) {
        if (fgets(check, 101, p) != NULL && strcmp(check, string) == 0) {
            printf("\nItem encontrado com sucesso!");
            break;
        } else if (count2 == count) { 
            printf("\nEsse produto não foi registrado.");
            break;
        } else {
            count2++;
        }
    }
    
    printf("\nDigite a quantidade a ser removida: ");
    scanf("%d", &a);
    getchar();
    fscanf(p, "%d", &b);

    if (a > b || a < 0) {
        printf("\nErro. Você não pode remover mais itens do que tem ou remover itens negativos.");
    } else {
        fprintf(p - numeroDeAlgarismos(b), "%d", b - a);
        printf("\nVocê removeu %d itens de %s do estoque com sucesso!", b - a, string);
    }
    
    printf("\nDeseja realizar outra ação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N');
}

int listarEstoque() {
    p = fopen("estoque.txt", "r");
    if(p == NULL) {
        printf("\nHouve um erro ao ler o estoque. Estoque inexistente.");
    } else {
        if (feof(p) != 0) {
            printf("\nEstoque vazio.")
        } else {
            printf("\nEstoque atual:")
            while (feof(p) == 0) {
            fgets(string, 100, p);
            printf("\n%s", string);
            strcpy(string, nada);
            }
        }
    }
    
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf("%c", &c);
    do {
        if (c == 's' || c == 'S') {
            return 0;
        } else if (c == 'n' || c == 'N') {
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 1;
        } else {
                printf("Sua opção é inválida.\nFavor escolher outra opção: ");
                scanf("%c", &c);
                getchar();
            }
        } while (c != 's' && c != 'n' && c != 'S' && c != 'N'); 
}


int main() {
    while (x != 1 || x != 2 || x != 3 || x != 4) {
        printf("\n===============================\n   Controle de Estoque\n===============================\n1. Adicionar Item\n2. Remover Item\n3. Listar Estoque\n4. Sair\n(Se você escolher uma entrada não numérica, escolha uma entrada numérica quando o código se repetir)\nOpção: ");
        scanf("%lf", &x);
        getchar();
        if (x == 1) {
            if (adicionarItem()) {
                return 0;
            }
        } else if (x == 2) {     
            if (removerItem()) {
                return 0;
            }          
        } else if (x == 3) {    
            if (listarEstoque()) {
                return 0;
            }      
        } else if (x == 4) {
            printf("\nObrigado por usar o Controle de Estoques! Até a próxima.\n");
            return 0;
        } else {
            printf("\nSua opção é inválida.\n Favor prossegir dando enter e em seguida escolher outra opção: ");
            scanf("");
            getchar();
        }
    }
    x = 0;
}
