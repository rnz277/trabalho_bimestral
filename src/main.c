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
int lerOpcao(int minimo, int maximo) {
    int opcao;

    do {
        scanf("%d", &opcao);

        if (opcao < minimo || opcao > maximo) {
            printf("Opcao invalida. Digite novamente: ");
        }

    } while (opcao < minimo || opcao > maximo);

    return opcao;


    int modalidade;
    int protecao;
    int tentativas;
    float distancia;
    float peso;

    printf("\nEscolha a modalidade:\n");
        printf("1 - Economica\n");
        printf("2 - Expressa\n");
        printf("3 - Prioritaria\n");
        printf("Opcao: ");
        modalidade = lerOpcao(1, 3);

        printf("\nDeseja adicionar protecao?\n");
        printf("0 - Nao\n");
        printf("1 - Sim\n");
        printf("Opcao: ");
        protecao = lerOpcao(0, 1);

        do {
            printf("\nQuantidade de tentativas adicionais: ");
            scanf("%d", &tentativas);

            if (tentativas < 0) {
                printf("A quantidade nao pode ser negativa.\n");
            }

        } while (tentativas < 0);

        printf("\n----- DADOS DA ENTREGA -----\n");
        printf("Distancia: %.2f km\n", distancia);
        printf("Peso: %.2f kg\n", peso);
        printf("Modalidade: %d\n", modalidade);
        printf("Protecao: %d\n", protecao);
        printf("Tentativas adicionais: %d\n", tentativas);
    
        #define VALOR_KM 1.20
        #define VALOR_PROTECAO 7.50
        #define VALOR_TENTATIVA 4.00

        float calcularValorBase(float distancia) {

        if (distancia <= 5) {
            return 8.00;
        } 
        else if (distancia <= 15) {
            return 12.00;
        } 
        else if (distancia <= 30) {
            return 18.00;
        } 
        else {
            return 25.00;
        }
        }

        float calcularPercentualPeso(float peso) {

        if (peso <= 2) {
            return 0.00;
        } 
        else if (peso <= 5) {
            return 0.05;
        } 
        else if (peso <= 10) {
            return 0.10;
        } 
        else {
            return 0.20;
            }
    }
    float calcularPercentualModalidade(int modalidade) {

    switch (modalidade) {

        case 1:
            return 0.00;

        case 2:
            return 0.15;

        case 3:
            return 0.30;

        default:
            return 0.00;
        }
    }
    float calcularValorEntrega(float distancia, float peso, int modalidade,
                           int protecao, int tentativas) {
                            
                           };

        float valorBase;
        float subtotal;
        float adicionalPeso;
        float adicionalModalidade;
        float valorFinal;

        valorBase = calcularValorBase(distancia);

        subtotal = valorBase + (distancia * VALOR_KM);

        adicionalPeso = subtotal * calcularPercentualPeso(peso);

        adicionalModalidade =
            subtotal * calcularPercentualModalidade(modalidade);

        valorFinal = subtotal + adicionalPeso + adicionalModalidade;

        if (protecao == 1) {
            valorFinal = valorFinal + VALOR_PROTECAO;
        }

        valorFinal = valorFinal + (tentativas * VALOR_TENTATIVA);

            return valorFinal;

    float valorFinal;

        valorFinal = calcularValorEntrega(
        distancia,
        peso,
        modalidade,
        protecao,
        tentativas
    );

    printf("\n------------------------------\n");
    printf("Valor da entrega: R$ %.2f\n", valorFinal);
    printf("------------------------------\n");
        }   
