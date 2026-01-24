#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
    char cor[20];
    int num_tropas;
    int ativo; // 0 para vazio, 1 para ocupado
} Territorio;

int main() {
    Territorio mapa[MAX];
    int opcao, i, id;

    // Inicializa todos como vazios
    for(i = 0; i < MAX; i++) mapa[i].ativo = 0;

    do {
        printf("\n--- MENU WAR ---\n");
        printf("1. Cadastrar Territorio\n");
        printf("2. Excluir Territorio\n");
        printf("3. Listar Territorios\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer

        switch(opcao) {
            case 1:
                // Procura primeira vaga livre
                id = -1;
                for(i = 0; i < MAX; i++) {
                    if(mapa[i].ativo == 0) {
                        id = i;
                        break;
                    }
                }

                if(id != -1) {
                    printf("Nome: ");
                    fgets(mapa[id].nome, 50, stdin);
                    mapa[id].nome[strcspn(mapa[id].nome, "\n")] = 0;
                    printf("Cor: ");
                    scanf("%s", mapa[id].cor);
                    printf("Tropas: ");
                    scanf("%d", &mapa[id].num_tropas);
                    mapa[id].ativo = 1;
                    printf("Cadastrado com sucesso!\n");
                } else {
                    printf("Erro: Limite de 5 territorios atingido!\n");
                }
                break;

            case 2:
                printf("Informe o numero do territorio (1 a 5) para excluir: ");
                scanf("%d", &id);
                if(id >= 1 && id <= 3) {
                    mapa[id-1].ativo = 0; // "Apaga" o registro
                    printf("Territorio excluido!\n");
                } else {
                    printf("ID invalido.\n");
                }
                break;

            case 3:
                printf("\n--- Territorios Cadastrados Ativos ---\n");
                for(i = 0; i < MAX; i++) {
                    if(mapa[i].ativo == 1) {
                        printf("[%d] %s | Cor: %s | Tropas: %d\n", i+1, mapa[i].nome, mapa[i].cor, mapa[i].num_tropas);
                    }
                }
                break;
        }
    } while(opcao != 0);

    return 0;
}