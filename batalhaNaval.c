#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define TAM_BARCO 3
#define ICONE_BARCO 3
#define ICONE_AGUA 0
#define ICONE_HABILIDADE 5

//Tamanho do tabuleiro
int tabuleiro[LINHA][COLUNA];

//Habilidades
int cone[5][5]={
                {0,0,5,0,0},
                {0,0,5,0,0},
                {0,5,5,5,0},
                {0,5,5,5,0},
                {5,5,5,5,5}},
    cruz[5][5]={
                {0,0,5,0,0},
                {0,0,5,0,0},
                {5,5,5,5,5},
                {0,0,5,0,0},
                {0,0,5,0,0}},
    octaedro[5][5]={
                    {0,0,5,0,0},
                    {0,5,5,5,0},
                    {5,5,5,5,5},
                    {0,5,5,5,0},
                    {0,0,5,0,0}};

//Verifica se a posição dos barcos sao validas, nao passando do tamanho do tabuleiro ou se sobrepondo sobre outros barcos
void validar(int inicio_vertical, int inicio_horizontal, char *posicao){
    //verifica se os barcos estao dentro do tabuleiro
    if (inicio_horizontal < 0 || inicio_vertical < 0 || (inicio_horizontal + TAM_BARCO) > COLUNA || (inicio_vertical + TAM_BARCO) > LINHA){
        printf("Posição invalida, barco esta fora do tabuleiro");
    }
    else{
        int teste = 0;
        switch (*posicao){
            case 'h': //Posição horizontal
                //Verifica se esta sobrepondo algum barco
                for (int i = 0; i < TAM_BARCO; i++){
                    if(tabuleiro[inicio_vertical][inicio_horizontal + i])
                        teste = 1;
                }
                if (teste)
                {
                    printf("Local invalido, barcos estao se sobrepondo\n");
                }
                else{
                    //Guarda a posição no tabuleiro
                    printf("Local valido\n");
                    for (int i = 0; i < TAM_BARCO; i++){
                        tabuleiro[inicio_vertical][inicio_horizontal + i] = 1;
                    }
                }
                break;
            case 'v': //Posição vertical
                //Verifica se esta sobrepondo algum barco
                for (int i = 0; i < TAM_BARCO; i++){
                    if(tabuleiro[inicio_vertical + i][inicio_horizontal])
                        teste = 1;
                }
                if (teste)
                {
                    printf("Local invalido, barcos estao se sobrepondo\n");
                }
                else{
                    //Guarda a posição no tabuleiro
                    printf("Local valido\n");
                    for (int i = 0; i < TAM_BARCO; i++){
                        tabuleiro[inicio_vertical + i][inicio_horizontal] = 1;
                    }
                }
                break;
            case 'd': //Posição diagonal
                //Verifica se esta sobrepondo algum barco
                for (int i = 0; i < TAM_BARCO; i++){
                    if(tabuleiro[inicio_vertical + i][inicio_horizontal + i])
                        teste = 1;
                }
                if (teste)
                {
                    printf("Local invalido, barcos estao se sobrepondo\n");
                }
                else{
                    //Guarda a posição no tabuleiro
                    printf("Local valido\n");
                    for (int i = 0; i < TAM_BARCO; i++){
                        tabuleiro[inicio_vertical + i][inicio_horizontal + i] = 1;
                    }
                }
                break;
            default:
                printf("Posição escolhida não encontrada");
                break;
        }
    }
}

//Posiciona a habilidade escolhida
void habilidade(int inicio_vertical, int inicio_horizontal, char *habilidade){
    //verifica se a habilidade esta dentro do tabuleiro
    if (inicio_horizontal < 0 || inicio_vertical < 0 ||  inicio_horizontal > 10 || inicio_vertical > 10){
        printf("Posição invalida, habilidade esta fora do tabuleiro");
    }
    else{
        printf("Habilidade valida\n");
        switch (*habilidade){
            case 'A':
                //Cone
                for (int i = -2,j = -2; i < 3 && j < 4; j++)
                {
                    if(j == 3){
                        j = -2;
                        i++;
                    }
                    if (cone[i + 2][j + 2] == ICONE_HABILIDADE)
                        tabuleiro[inicio_vertical + i][inicio_horizontal + j] = ICONE_HABILIDADE;
                }
                break;
            case 'B':
                //Cruz
                for (int i = -2,j = -2; i < 3 && j < 4; j++)
                {
                    if(j == 3){
                        j = -2;
                        i++;
                    }
                    if (cruz[i + 2][j + 2] == ICONE_HABILIDADE)
                        tabuleiro[inicio_vertical + i][inicio_horizontal + j] = ICONE_HABILIDADE;
                }
                break;
            case 'C':
                //Octaedro
                for (int i = -2,j = -2; i < 3; j++)
                {
                    if(j == 3){
                        j = -2;
                        i++;
                    }
                    if (octaedro[i + 2][j + 2] == ICONE_HABILIDADE)
                        tabuleiro[inicio_vertical + i][inicio_horizontal + j] = ICONE_HABILIDADE;
                }
                break;
            default:
                printf("Habilidade escolhida não encontrada");
                break;
        }
    }
}

int main(){
    //Posições dos barcos no tabuleiro
    //  LINHA, COLUNA, POSIÇÃO
    validar(1, 1, "h"); 
    validar(3, 4, "v");
    validar(3, 6, "d");
    validar(6, 2, "d");

    //Posição habilidade
    //  LINHA, COLUNA, HABILIDADE
    habilidade(5, 5, "C");

    //Mostra o tabuleiro no terminal
    for (int i = 0; i < LINHA; i++){
        for (int j = 0; j < COLUNA; j++){
            if (tabuleiro[i][j] == 0){
                printf("%d ", ICONE_AGUA);
            }
            else{
                if (tabuleiro[i][j] == 5)
                {
                    printf("%d ", ICONE_HABILIDADE);
                }
                else{
                    printf("%d ", ICONE_BARCO);
                }
            }
        }
        printf("\n");
    }
}
