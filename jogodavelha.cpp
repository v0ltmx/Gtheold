#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void nickname(char nome[11]){
	system("color 0a");
	printf("\t\t%s\n",nome);
}

void tabuleiro(char t[3][3]){
	printf("\t============================\n");
	printf("\n\n\n\t\t %c | %c | %c \n",t[0][0],t[0][1],t[0][2]);
  	printf("\t\t-----------\n");
  	printf("\t\t %c | %c | %c \n",t[1][0],t[1][1],t[1][2]);	   	  
 	printf("\t\t-----------\n");
 	printf("\t\t %c | %c | %c \n\n\n\n\n\n",t[2][0],t[2][1],t[2][2]);
	printf("\t============================\n\n");
}

int main(){
	
	char tab[3][3];
	char nome[11] = "Velha Game";
	nickname(nome);
	int cont,linha,coluna;
	int jogada = 0;
	char confirmar;
	
	do{
	   cont = 1;
	   		for(int i=0; i<=2; i++){
	   			for(int j=0; j<=2; j++){            //ZERAR O TABULEIRO
	   				tab[i][j] = ' ';
				   }
			   }
		do{
			tabuleiro(tab);
			if(jogada%2==0){
				printf("\tVez do primeiro jogador..\n\n\n");
			}
			else{
				printf("\tVez do segundo jogador..\n\n\n");
			}
			printf("\tInsira a linha e coluna:\n");
			scanf("%d",&linha);
			scanf("%d",&coluna);
			
			if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3){//JOGADAS INVÁLIDAS
					 linha = 0 ;	//JOGADA INVÁLIDA
					 coluna = 0;	//JOGADA INVÁLIDA
			}
			else if(tab[linha-1][coluna-1] != ' '){//JOGADAS INVÁLIDAS
				linha = 0;		// SE ELE PREENCHER CASA OCUPADA , INVÁLIDO
				coluna = 0;		// PREENCHENDO CASA OCUPADA, INVÁLIDO
			}
			else{  //JOGADA VÁLIDA                     //LINHA -1 E COLUNA -1, PQ COMEÇAM EM ZERO , CASAS[0][0]
				if(jogada%2 == 0){
						 tab[linha-1][coluna-1] = 'X';	
						  }
				else{
	  			  		  tab[linha-1][coluna-1] = 'O';
			}
				jogada++;
		 		cont++;
			} 
			//Vitoria do primeiro jogador
			if(tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X'){
				cont = 11;  // pra encerrar o laço
			}
			if(tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X'){
				cont = 11;
			}
			if(tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X'){
				cont = 11;
			}
			if(tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X'){
				cont = 11;
			}
			if(tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X'){
				cont = 11;
			}
			if(tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X'){
				cont = 11;
			}
			if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X'){
				cont = 11;
			}
			if(tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X'){
				cont = 11;
			}
	
			//Vitoria do segundo jogador
				if(tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O'){
					cont = 12;  // pra encerrar o laço
			}
				if(tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O'){
					cont = 12;
			}
				if(tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O'){
					cont = 12;
			}
				if(tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O'){
					cont = 12;
			}
				if(tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O'){
					cont = 12;
			}
				if(tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O'){
					cont = 12;
			}
				if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O'){
					cont = 12;
			}
				if(tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O'){
					cont = 12;
			}
		}while(cont <= 9);
		
				if(cont==10){
					printf("\tO jogo teve um empate!\n");
			}
				if(cont==11){
					printf("\tO primeiro jogador venceu!\n");
			}
				if(cont==12){
					printf("\tO segundo jogador venceu!\n");
			}
		printf("\tVoce quer jogar novamente? Insira 's' para continuar ou qualquer letra pra sair\n");
		scanf("%s",&confirmar);		
	}while(confirmar == 's');
	
	system("pause");
	return 0;
}
