#include <stdio.h>

// Função recursiva que resolve o problema da Torre de Hanói
void hanoi(int n, char orig, char dest, char aux) {
    /* caso base: n == 0 - não faz nada */
    if (n > 0) { /* caso geral */
        hanoi(n - 1, orig, aux, dest);
        printf("Mover disco %d de %c para %c\n", n, orig, dest);
        hanoi(n - 1, aux, dest, orig);
    }
}

int main() {
    int num_discos;

    printf("Resolvendo o problema da Torre de Hanói\n");
    printf("Digite o número de discos: ");
    scanf("%d", &num_discos);

    if (num_discos < 1) {
        printf("Número de discos deve ser positivo.\n");
        return 1;
    }

    printf("\nSolução para %d discos:\n", num_discos);
    hanoi(num_discos, 'A', 'C', 'B');  // Move discos de A para C usando B como auxiliar

    // Calcula o número total de movimentos (2^n - 1)
    unsigned long long total_movimentos = (1ULL << num_discos) - 1;
    printf("\nTotal de movimentos: %llu\n", total_movimentos);

    return 0;
}
