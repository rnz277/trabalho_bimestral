#include <stdio.h>

int main(void) {

    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n");

    printf("\nSistema iniciado.\n");

    return 0;
}
#include <stdio.h>

float lerValorPositivo(char mensagem[]) {
    float valor;

    do {
        printf("%s", mensagem);
        scanf("%f", &valor);

        if (valor <= 0) {
            printf("Valor invalido. Digite um valor maior que zero.\n");
        }

    } while (valor <= 0);

    return valor;
}

int main(void) {

    float distancia;
    float peso;

    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n");

    printf("\n--- Dados da entrega ---\n");

    distancia = lerValorPositivo("Digite a distancia em km: ");
    peso = lerValorPositivo("Digite o peso em kg: ");

    printf("\nDados registrados com sucesso!\n");
    printf("Distancia: %.2f km\n", distancia);
    printf("Peso: %.2f kg\n", peso);

    return 0;
}