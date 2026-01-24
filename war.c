#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cor[20];
    int num_tropas;
} Territorio;

int main() {
    int quantidade;

    printf("Lista de Cadastro de Territorios ");
    scanf("%d", &quantidade);
    getchar(); // Limpa o buffer do Enter

    // Criamos o array com o tamanho que o utilizador escolheu
    Territorio mapa[quantidade]; 

    for(int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("America do Sul: ");
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;

        printf("Azul: ");
        scanf("%s", mapa[i].cor);

        printf("6: ");
        scanf("%d", &mapa[i].num_tropas);
        
        getchar(); // Limpa o buffer para o próximo fgets
    }

    printf("\n--- Lista de todos os %d territórios ---\n", quantidade);
    for(int i = 0; i < quantidade; i++) {
        printf("Território: %s | Exército: %s | Tropas: %d\n", 
               mapa[i].nome, mapa[i].cor, mapa[i].num_tropas);
    }

    return 0;
}