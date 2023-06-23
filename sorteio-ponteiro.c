#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroJaExiste(int *numeros, int tamanho, int numero) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (numeros[i] == numero) {
            return 1; // Número já existe
        }
    }
    return 0; // Número não existe
}

void sortearMegaSena(int *numeros) {
    int i, numero;

    // Inicializa a semente randômica usando o tempo atual
    srand(time(NULL));

    // Gera os 6 números aleatórios
    for (i = 0; i < 6; i++) {
        do {
            numero = rand() % 60 + 1; // Gera números entre 1 e 60
        } while (numeroJaExiste(numeros, i, numero)); // Verifica se o número já existe

        numeros[i] = numero; // Adiciona o número ao array
    }
}

int main() {
    int numeros[6];

    sortearMegaSena(numeros);

    // Imprime os números sorteados
    printf("Números sorteados: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}