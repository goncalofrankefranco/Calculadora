#include <stdio.h>
#include <string.h>
double x = 0;
char c;
char string[100], check[101], nada[100], linha[256];
int a = 0, b = 0, count, encontrou = 0, countA = 0, i = 0;
FILE *p;

int numeroDeAlgarismos(int a) {
    countA++;
    if (a/10 < 1) {
        return countA;
    } else {
        return numeroDeAlgarismos(a/10);
    }
}

int adicionarItem() {
    p = fopen("estoque.txt", "a");
    printf("\n(Máximo 100 caracteres)\nDigite o nome do item: ");
    scanf("%s[^\n]", string);
    
    printf("\nDigite a quantidade: ");
    scanf("%d", &a);
    getchar();
    printf("\n(Se escreveu uma entrada não numérica, por favor adicionar novamente)");
    
    if (p == NULL || a <= 0) {
        printf("\nHouve um erro ao adicionar o produto.");
    } else {
        fseek(p, 0, SEEK_END);
        fprintf(p, "\n%s\n%d", string, a);
        printf("\nItem adicionado com sucesso!");
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
    p = fopen("estoque.txt", "r+");
    if(p == NULL) {
        printf("\nHouve um erro ao abrir o estoque.");
    } else {
        printf("\nEstoque aberto com sucesso!");
    }
    
    printf("\n(Máximo 100 caracteres)\nDigite o nome do item: ");
    scanf("%s[^\n]", string);
    getchar();

    while (fgets(linha, 112, p) != NULL) {
        if (strstr(linha, string) != NULL) {
            printf("\nO item foi encontrado.");
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("\nO item não foi encontrado.");
    } else {
        printf("\nDigite a quantidade a ser removida: ");
        scanf("%d", &a);
        getchar();
        fscanf(p, "%d", &b);

        if (a > b || a < 0) {
            printf("\nErro. Você não pode remover mais itens do que tem ou remover itens negativos.");
        } else {
            fseek(p, -numeroDeAlgarismos(b), SEEK_CUR);
            fprintf(p, "%d", b - a);
            countA = 0;
            printf("\nVocê removeu %d itens de %s do estoque com sucesso!", b - a, string);
        }
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
    string[0] = '\0';
    if(p == NULL) {
        printf("\nHouve um erro ao ler o estoque. Estoque inexistente.");
    } else {
        if (feof(p) == 0) {
            printf("\n===============================\n   Estoque Atual\n===============================\n");
            while (fscanf(p, "%s[^\n]", string) == 1) {
                printf("Nome: %s\n", string);
                if (fscanf(p, "%s[^\n]", string) == 1) {
                    printf("Quantidade: %s\n\n", string);
                }
            }
        } else {            
            printf("\nO estoque está vazio.");
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
    while (x != 4) {
        printf("\n===============================\n   Controle de Estoque\n===============================\n1. Adicionar Item\n2. Remover Item\n3. Listar Estoque\n4. Sair\n(Se você escolher uma entrada não numérica, escolha uma entrada numérica quando o código se repetir)\nSelecione uma opção: ");
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
