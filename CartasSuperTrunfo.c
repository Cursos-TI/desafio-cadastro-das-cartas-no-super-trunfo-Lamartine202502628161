#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nome[100];
    int populacao;
    float area;
    float pib;
    int pontos;
} Carta;

Carta lerCarta() {
    Carta carta;

    printf("Digite o estado: ");
    scanf("%s", &carta.estado);

    printf("Digite o código da carta: ");
    scanf("%s", carta.codigo);

    printf("Digite o nome da cidade: ");
    scanf("%s", carta.nome);

    printf("Digite a população: ");
    scanf("%d", &carta.populacao);

    printf("Digite a área: ");
    scanf("%f", &carta.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos);

    return carta;
}

void imprimirCarta(Carta carta) {
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %c%s\n", carta.estado, carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos);
}

int totalCartas = 0;
Carta cartasSalvas[1000];
void salvarCarta(Carta carta){
    cartasSalvas[totalCartas++] = carta;
}

void listarCartas(){
    int i;

    if(!totalCartas) {
        printf("Você ainda não cadastrou cartas\n");
        return;
    }

    printf("As cartas cadastradas são:\n");
    for(i=0; i<totalCartas; i++){
        printf("\n");
        imprimirCarta(cartasSalvas[totalCartas - 1 - i]);
    }
    printf("\nFim da lista de cartas cadastradas\n");
}

void cadastrarCarta() {
    Carta carta = lerCarta();
    salvarCarta(carta);
    printf("\nCARTA CADASTRADA COM SUCESSO\n\n");
    imprimirCarta(carta);
}

int mostrarMenu(){
    int opcao;
    int totalItens = 0;

    printf("O que você quer fazer?\n");
    printf("%d - Cadastrar carta;\n", ++totalItens);
    printf("%d - Exibir cartas cadastradas;\n", ++totalItens);
    printf("0 - Sair;\n");
    scanf("%d", &opcao);

    if(opcao < 0 || opcao > totalItens){
        printf("\nOpção invalida\n\n");
        return mostrarMenu();
    }

    return opcao;
}

int main(){
    int opcao;

    printf("Olá\n");
    while(opcao = mostrarMenu()){
        printf("\n");
        if(opcao == 1) cadastrarCarta();
        if(opcao == 2) listarCartas();
        printf("\n");
    }

    return 0;
}
