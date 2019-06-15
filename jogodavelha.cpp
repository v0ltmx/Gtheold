#include <stdio.h>
#include <stdlib.h>

void nickname(char nome[50]){
	printf("\t--------Jogo da velha--------\n\n\n\n\n");
}

void tabuleiro(char casas2[3][3]){

	printf("\n\n\n\t\t %c | %c | %c \n",casas2[0][0],casas2[0][1],casas2[0][2]);
  	printf("\t\t-----------\n");
  	printf("\t\t %c | %c | %c \n",casas2[1][0],casas2[1][1],casas2[1][2]);	   	  
 	printf("\t\t-----------\n");
 	printf("\t\t %c | %c | %c \n\n\n\n\n\n",casas2[2][0],casas2[2][1],casas2[2][2]);
}

int main(){
	
	char casas[3][3] = { {'1','2','3'},
		 			     {'4','5','6'},
		 			     {'7','8','9'}};
	
	char nome[50];
	nickname(nome);
	int contador_jogadas,linha,coluna,i,j;
	int vez = 0;
	char resposta;
	
	do{
	   contador_jogadas = 1;
	   		for(i = 0; i<=2; i++){
	   			for(j=0; j<=2; j++){            //ZERANDO O TABULEIRO
	   				casas[i][j] = ' ';
				   }
			   }
		do{
			tabuleiro(casas);
			if(vez%2==0){
				printf("\tJogador X\n");
			}
			else{
				printf("\tJogador O\n");
			}
			printf("\tDigite a linha: ");
			scanf("%d",&linha);
			printf("\tDigite a coluna: ");
			scanf("%d",&coluna);
			
			if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3){//JOGADAS INVÁLIDAS
					 linha = 0 ;	//JOGADA INVÁLIDA
					 coluna = 0;	//JOGADA INVÁLIDA
			}
			else if(casas[linha-1][coluna-1] != ' '){//JOGADAS INVÁLIDAS
				linha = 0;		// SE ELE PREENCHER CASA OCUPADA , INVÁLIDO
				coluna = 0;		// PREENCHENDO CASA OCUPADA, INVÁLIDO
			}
			else{  //JOGADA VÁLIDA                     //LINHA -1 E COLUNA -1, PQ COMEÇAM EM ZERO , CASAS[0][0]
				if(vez%2 == 0){
						 casas[linha-1][coluna-1] = 'X';	
						  }
				else{
	  			  		  casas[linha-1][coluna-1] = 'O';
			}
			vez++;
		 	contador_jogadas++;
			} 
			//CONDIÇÕES DE VITORIA DO JOGADOR X
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){
				contador_jogadas = 11;  // pra encerrar o laço
			}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){
				contador_jogadas = 11;
			}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){
				contador_jogadas = 11;
			}
	
			//CONDIÇÕES DE VITORIA DO JOGADOR O
				if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){
				contador_jogadas = 12;  // pra encerrar o laço
			}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){
				contador_jogadas = 12;
			}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){
				contador_jogadas = 12;
			}
		}while(contador_jogadas <= 9);
		tabuleiro(casas);
			if(contador_jogadas==10){
				printf("\tJogo empatado\n");
			}
			if(contador_jogadas==11){
				printf("\tJogador X venceu!\n");
			}
			if(contador_jogadas==12){
				printf("\tJogador O venceu!\n");
			}
		printf("\tVoce deseja jogar novamente?\n");
		scanf("%s",&resposta);		
	}while(resposta == 's');
	
	system("pause");
	return 0;
}
