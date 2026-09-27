#include <stdio.h>

#define VALOR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA 4.00


/* Le um valor que obrigatoriamente precisa ser maior que zero */
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


/* Le uma opcao e verifica se esta dentro dos limites informados */
int lerOpcao(char mensagem[], int minimo, int maximo) {
    int opcao;

    do {
        printf("%s", mensagem);
        scanf("%d", &opcao);

        if (opcao < minimo || opcao > maximo) {
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao < minimo || opcao > maximo);

    return opcao;
}


/* A quantidade de tentativas pode ser zero, mas nunca negativa */
int lerTentativas(void) {
    int tentativas;

    do {
        printf("Quantidade de tentativas adicionais: ");
        scanf("%d", &tentativas);

        if (tentativas < 0) {
            printf("A quantidade nao pode ser negativa.\n");
        }

    } while (tentativas < 0);

    return tentativas;
}


/* Define o valor base de acordo com a distancia */
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


/* Retorna o percentual adicional referente ao peso */
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


/* Retorna o percentual da modalidade escolhida */
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


/* Realiza o calculo completo do valor de uma entrega */
float calcularValorEntrega(float distancia,
                           float peso,
                           int modalidade,
                           int protecao,
                           int tentativas) {

    float valorBase;
    float subtotal;
    float adicionalPeso;
    float adicionalModalidade;
    float valorFinal;

    valorBase = calcularValorBase(distancia);

    subtotal = valorBase + (distancia * VALOR_KM);

    adicionalPeso =
        subtotal * calcularPercentualPeso(peso);

    adicionalModalidade =
        subtotal * calcularPercentualModalidade(modalidade);

    valorFinal =
        subtotal + adicionalPeso + adicionalModalidade;

    if (protecao == 1) {
        valorFinal = valorFinal + VALOR_PROTECAO;
    }

    valorFinal =
        valorFinal + (tentativas * VALOR_TENTATIVA);

    return valorFinal;
}


/* Mostra os dados da entrega que acabou de ser calculada */
void mostrarEntrega(float distancia,
                    float peso,
                    int modalidade,
                    int protecao,
                    int tentativas,
                    float valorFinal) {

    printf("\n====================================\n");
    printf("          RESUMO DA ENTREGA\n");
    printf("====================================\n");

    printf("Distancia: %.2f km\n", distancia);
    printf("Peso: %.2f kg\n", peso);

    printf("Modalidade: ");

    switch (modalidade) {

        case 1:
            printf("Economica\n");
            break;

        case 2:
            printf("Expressa\n");
            break;

        case 3:
            printf("Prioritaria\n");
            break;
    }

    if (protecao == 1) {
        printf("Protecao: Sim\n");
    }
    else {
        printf("Protecao: Nao\n");
    }

    printf("Tentativas adicionais: %d\n", tentativas);

    printf("------------------------------------\n");
    printf("Valor da entrega: R$ %.2f\n", valorFinal);
    printf("====================================\n");
}


/* Apresenta os resultados acumulados durante toda a execucao */
void mostrarResumoFinal(int totalEntregas,
                        float valorTotal,
                        int economicas,
                        int expressas,
                        int prioritarias,
                        float maiorValor,
                        float menorValor) {

    float media;

    media = valorTotal / totalEntregas;

    printf("\n====================================\n");
    printf("          RESUMO DA SESSAO\n");
    printf("====================================\n");

    printf("Total de entregas: %d\n", totalEntregas);
    printf("Valor total: R$ %.2f\n", valorTotal);
    printf("Valor medio: R$ %.2f\n", media);

    printf("\nEntregas por modalidade:\n");
    printf("Economicas: %d\n", economicas);
    printf("Expressas: %d\n", expressas);
    printf("Prioritarias: %d\n", prioritarias);

    printf("\nMaior valor: R$ %.2f\n", maiorValor);
    printf("Menor valor: R$ %.2f\n", menorValor);

    printf("====================================\n");
}


int main(void) {

    float distancia;
    float peso;
    float valorFinal;

    float valorTotal = 0.00;
    float maiorValor = 0.00;
    float menorValor = 0.00;

    int modalidade;
    int protecao;
    int tentativas;
    int continuar;

    int totalEntregas = 0;

    int economicas = 0;
    int expressas = 0;
    int prioritarias = 0;


    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n");


    do {

        printf("\n--- NOVA ENTREGA ---\n\n");

        distancia =
            lerValorPositivo("Digite a distancia em km: ");

        peso =
            lerValorPositivo("Digite o peso em kg: ");


        printf("\nEscolha a modalidade:\n");
        printf("1 - Economica\n");
        printf("2 - Expressa\n");
        printf("3 - Prioritaria\n");

        modalidade =
            lerOpcao("Opcao: ", 1, 3);


        printf("\nDeseja adicionar protecao?\n");
        printf("0 - Nao\n");
        printf("1 - Sim\n");

        protecao =
            lerOpcao("Opcao: ", 0, 1);


        printf("\n");

        tentativas = lerTentativas();


        valorFinal = calcularValorEntrega(
            distancia,
            peso,
            modalidade,
            protecao,
            tentativas
        );


        mostrarEntrega(
            distancia,
            peso,
            modalidade,
            protecao,
            tentativas,
            valorFinal
        );


        /* Atualiza os dados da sessao */
        valorTotal = valorTotal + valorFinal;

        totalEntregas++;


        /* Na primeira entrega, ela e ao mesmo tempo maior e menor */
        if (totalEntregas == 1) {
            maiorValor = valorFinal;
            menorValor = valorFinal;
        }
        else {

            if (valorFinal > maiorValor) {
                maiorValor = valorFinal;
            }

            if (valorFinal < menorValor) {
                menorValor = valorFinal;
            }
        }


        /* Conta quantas entregas foram feitas em cada modalidade */
        switch (modalidade) {

            case 1:
                economicas++;
                break;

            case 2:
                expressas++;
                break;

            case 3:
                prioritarias++;
                break;
        }


        printf("\nDeseja registrar outra entrega?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");

        continuar =
            lerOpcao("Opcao: ", 0, 1);


    } while (continuar == 1);


    mostrarResumoFinal(
        totalEntregas,
        valorTotal,
        economicas,
        expressas,
        prioritarias,
        maiorValor,
        menorValor
    );


    printf("\nPrograma encerrado.\n");

    return 0;
}