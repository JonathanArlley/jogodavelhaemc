#include <stdbool.h>
#include <stdio.h>
#include <conio.h>


bool ganhei;
int verific;
char tabuleiro[10] = {'0','1','2','3','4','5','6','7','8','9'} ;
int posicao;
int pontuacao1;
int pontuacao2;
int Empato;
bool ganhar;
int j;
int limparTabuleiro();
int opc;
int n = 1;
int quebra = 1;
int i = 1;
int simbolo1 = 17; // Tabela ASCII
int simbolo2 = 16; // Tabela ASCII

void creditos(){
    printf("Jonathan Arlley \n");


}



//Tabuleiro
void exibirTabuleiro() {

	printf("\xBA----\xBA----\xBA----\xBA\n\xBA  %c \xBA  %c \xBA  %c \xBA\n\xBA",tabuleiro[1],tabuleiro[2],tabuleiro[3]);
	printf("----\xBA----\xBA----\xBA\n\xBA  %c \xBA  %c \xBA  %c \xBA\n\xBA",tabuleiro[4],tabuleiro[5],tabuleiro[6]);
	printf("----\xBA----\xBA----\xBA\n\xBA  %c \xBA  %c \xBA  %c \xBA\n\xBA",tabuleiro[7],tabuleiro[8],tabuleiro[9]);
	printf("----\xBA----\xBA----\xBA\n");



}
//MENU

menu(){



	printf("--------------------------------------------\n");
	printf("-------------{JOGO DA VELHA}-----------------\n");
	printf("---------------------------------------------\n\n");

	printf("1 Jogar contra um amigo (x)\n");
	printf("2 Jogar contra um amigo (O) \n");
	printf("3 Para jogar contra a CPU \n");
	printf("4 Creditos\n");
	printf("5 Ranking\n");
	printf("S Para sair\n");
	printf("Digite a opcao desejada:\n");
	scanf("%i", &opc);


	switch(opc){
	case 1:
		ganhei = false;
		quebra = 1;
		i =1;
		int players(void);
	    players();

		break;
	case 2:
	    ganhei = false;
		quebra = 1;
		i =2;
		int players(void);
	    players();
		break;

    case 3:{
        jogador_computador();
        verificao();
	    computador();

		break;

    }
    case 4:{
        creditos();
        break;

    }

    case 5:{

    rank();
    break;
    }


	case 'S':
		break;
	default:
		printf("Obrigado por jogar!!!");
		break;
	}
	return 0;
}

// Jogar com Players
int players(void) {
	int verificao(int verific);
	int regra();
	int regras2(int stop);
	int posicao;
	int limparTabuleiro();
	int empate();


	while(ganhei != true) {
		exibirTabuleiro();
		printf("Digite um numero correspondente a casa no quadrado:\n");
		printf("PLAYER (%i) :", i);
		scanf("%i",&posicao);
		regras2(posicao);
		verificao(posicao);
		regra();
		empate();

	++i;

 	system("cls");
	// Mini loop dos players
	if(i > 2) {
	   i = 1;
	}
	++n;

    }
	limparTabuleiro();
	menu();


}
//Vericao pra o cara nao substituir as peças  x ou o ;
int verificao(int verific) {
	//player 1
	if((tabuleiro[verific] != 'o') && (i == 1)){
		tabuleiro[verific] = 'x';
	//player 2
	}else if((tabuleiro[verific] != 'x') && (i == 2)){
		tabuleiro[verific] = 'o';
	}


}
//VERIFICA TODAS AS POSIÇOES DO JOGADORES
int regra() {

   if((tabuleiro[1]== 'x' && tabuleiro[2]=='x' && tabuleiro[3] == 'x')||
	  (tabuleiro[4]== 'x' && tabuleiro[5]=='x' && tabuleiro[6] == 'x')||
	  (tabuleiro[7]== 'x' && tabuleiro[8]=='x' && tabuleiro[9] == 'x')||
	  (tabuleiro[1]== 'x' && tabuleiro[5]=='x' && tabuleiro[9] == 'x')||

	  (tabuleiro[3]== 'x' && tabuleiro[5]=='x' && tabuleiro[7] == 'x')||
	  (tabuleiro[2]== 'x' && tabuleiro[5]=='x' && tabuleiro[8] == 'x')||
	  (tabuleiro[1]== 'x' && tabuleiro[4]=='x' && tabuleiro[7] == 'x')||
	  (tabuleiro[3]== 'x' && tabuleiro[6]=='x' && tabuleiro[9] == 'x'))
	{
		++pontuacao1;
		ganhei = true;
	}

   if((tabuleiro[1]== 'o' && tabuleiro[2]=='o' && tabuleiro[3] == 'o')||
	  (tabuleiro[4]== 'o' && tabuleiro[5]=='o' && tabuleiro[6] == 'o')||
	  (tabuleiro[7]== 'o' && tabuleiro[8]=='o' && tabuleiro[9] == 'o')||
	  (tabuleiro[1]== 'o' && tabuleiro[5]=='o' && tabuleiro[9] == 'o')||

	  (tabuleiro[3]== 'o' && tabuleiro[5]=='o' && tabuleiro[7] == 'o')||
	  (tabuleiro[2]== 'o' && tabuleiro[5]=='o' && tabuleiro[8] == 'o')||
	  (tabuleiro[1]== 'o' && tabuleiro[4]=='o' && tabuleiro[7] == 'o')||
	  (tabuleiro[3]== 'o' && tabuleiro[6]=='o' && tabuleiro[9] == 'o'))
	{
		++pontuacao2;
		ganhei = true;
	}


}
// VERIFICA QUANDO DA EMPATE
 int empate() {
	++quebra;
	if(quebra>=10){
		++Empato;
		ganhei = true;
		}
	}

//LIMPAR O TABULEIRO PARA PROXIMA JOGADA


//Ranking
void rank(){
    printf("Player 1 = x \t\t\n");
	printf("Player 2 = O \t\t\n\n");
	printf("(RANK)\t\t\n");
	printf("X PONTOS: %i\t\t\n",pontuacao1);
	printf("O PONTOS: %i\t\t\n",pontuacao2);
	printf("Empate 3 PONTOS: %i \t\t\n",Empato);


}

void computador(char m[3][3]) {

    int Linha, Coluna;

    //Condições nível medio
    if (m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[0][2] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[0][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[0][0] == 'O' && m[2][0] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[0][1] == 'O' && m[2][1] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][2] == 'O' && m[2][2] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[0][0] == 'O' && m[2][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    else if(m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == ' ') {
        Linha = 1;
        Coluna = 2;
    } else if(m[1][0] == 'O' && m[1][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    } else if(m[1][1] == 'O' && m[1][2] == 'O' && m[1][0] == ' ') {
        Linha = 1;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[0][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[1][0] == 'O' && m[2][0] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    } else if(m[1][1] == 'O' && m[2][1] == 'O' && m[0][1] == ' ') {
        Linha = 0;
        Coluna = 1;
    } else if(m[1][2] == 'O' && m[2][2] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[1][1] == 'O' && m[2][2] == 'O' && m[0][0] == ' ') {
        Linha = 0;
        Coluna = 0;
    }

    else if(m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == ' ') {
        Linha = 2;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[2][2] == 'O' && m[2][1] == ' ') {
        Linha = 2;
        Coluna = 1;
    } else if(m[2][1] == 'O' && m[2][2] == 'O' && m[2][0] == ' ') {
        Linha = 2;
        Coluna = 0;
    } else if(m[2][0] == 'O' && m[1][1] == 'O' && m[0][2] == ' ') {
        Linha = 0;
        Coluna = 2;
    } else if(m[2][0] == 'O' && m[0][2] == 'O' && m[1][1] == ' ') {
        Linha = 1;
        Coluna = 1;
    }

    //Condições aleatórias
    else {
        do {
            Linha = rand()%3;
            Coluna = rand()%3;
        } while(m[Linha][Coluna]!=' ');
    }

    m[Linha][Coluna]='O';

}
void jogador_computador(char m[3][3]) {
    int L, C;

    do {
        printf("Digite uma posição válida : ");
        scanf("%d %d", &L, &C);
    } while(L<0 || L>2 || C<0 || C>2 || m[L][C]!=' ');

    m[L][C] ='X';
}


int limparTabuleiro()
{
int tb;
for(tb = 0; tb<=11; tb++) {
		tabuleiro[tb] = ' ' ;

	}
};

//AQUI PARECE A MSG PARA O CARA ESCOLHE O PLAYER CERTO QUE TENTO COLOCAR UM X EM CIMA DA BOLA.
void alerta(){
	int alerta;

    printf("--------------------ATENCAO----------------------\n");
    printf("Ja houve jogada nesta casa! Escolha outra casa.\t\n");
    printf("\tSE VOCE ERROU COM PLAYER 1 APERTE 1\n");
    printf("\tSE VOCE ERROU COM PLAYER 2 APERTE 2\n");
    printf("Digite o numero do player que errou, para voce nao perder a vez!!!\n");
    scanf("%i");



}

// AQUI É ONDE ELE VERIFICA SE O CARA VAI COLOCAR O X NO LUGAR DA BOLA
int regras2(int stop){
	if(tabuleiro[stop] == 'x' || tabuleiro[stop] == 'o')
	{

		void alerta();
		alerta();
}

}
//O START DO CODIGO

int main ()
{

  menu();

}

