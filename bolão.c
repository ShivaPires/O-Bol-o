#include <stdio.h>
#include <string.h>
#include <locale.h>

// O Bolão - versão 1.0.0 (beta) - autor: Shiva Pires

typedef struct{
	int mandante;
	int visitante;
}Partida;

typedef struct{
	char nome[20];
	Partida apostas[50];
	int pontuacao[50];
	int pontuacaototal;
}Placar;

void main(){
	int np, j, c, x, y, z, w;
	Partida resultados[50];
	Placar apostas[50];
	printf("Quantos jogos ocorreram nessa rodada:\t", setlocale(LC_ALL,""));
	scanf("%d", &np);
	system("cls");
	printf("Quantas pessoas estão participando do bolão?\t");
	scanf("%d", &j);
	int k = 1;
	int b = 1;
	int i = np;
	while(i>0){
		system("cls");
		printf("Digite o %dº resultado:\t", k);
		scanf("%dx%d", &resultados[k].mandante, &resultados[k].visitante);
		k++;
		i--;
	}
	while(b<=j){
		system("cls");
		printf("Digite o nome do %dº participante:\t", b);
		fflush(stdin);
		gets(apostas[b].nome);
		for(c=1;c<=np;c++){
			system("cls");
			printf("Digite a %dº aposta de %s:\t", c, apostas[b].nome);
			scanf("%dx%d", &apostas[b].apostas[c].mandante, &apostas[b].apostas[c].visitante);
		}
		b++;
	}
	for(x=1;x<=j;x++){
		for(y=1;y<=np;y++){
			if(apostas[x].apostas[y].mandante == resultados[y].mandante && apostas[x].apostas[y].visitante == resultados[y].visitante){
				apostas[x].pontuacao[y] = 25;
			}
			else
				if(apostas[x].apostas[y].mandante == resultados[y].mandante || apostas[x].apostas[y].visitante == resultados[y].visitante){
					if(resultados[y].mandante > resultados[y].visitante && apostas[x].apostas[y].mandante > apostas[x].apostas[y].visitante || resultados[y].mandante < resultados[y].visitante && apostas[x].apostas[y].mandante < apostas[x].apostas[y].visitante){
						if(resultados[y].mandante - resultados[y].visitante == 0 || apostas[x].apostas[y].mandante - apostas[x].apostas[y].visitante == 0) apostas[x].pontuacao[y] = 0;
						else
							if(resultados[y].mandante - resultados[y].visitante > 0 && resultados[y].mandante == apostas[x].apostas[y].mandante || resultados[y].visitante - resultados[y].mandante > 0 && resultados[y].visitante == apostas[x].apostas[y].visitante){
								apostas[x].pontuacao[y] = 18;
							}
							if(resultados[y].mandante - resultados[y].visitante < 0 && resultados[y].mandante == apostas[x].apostas[y].mandante || resultados[y].visitante - resultados[y].mandante < 0 && resultados[y].visitante == apostas[x].apostas[y].visitante){
								apostas[x].pontuacao[y] = 12;
							}
					}
				}
			else
				if(resultados[y].mandante == resultados[y].visitante && apostas[x].apostas[y].mandante-apostas[x].apostas[y].visitante==0){
					apostas[x].pontuacao[y] = 15;
				}
				else
					if(resultados[y].mandante < resultados[y].visitante && apostas[x].apostas[y].mandante < apostas[x].apostas[y].visitante){
						apostas[x].pontuacao[y] = 10;
					}
						else
							if(resultados[y].mandante > resultados[y].visitante && apostas[x].apostas[y].mandante > apostas[x].apostas[y].visitante){
								apostas[x].pontuacao[y] = 10;
							}
		}
	}
	system("cls");
	for(w=1;w<=j;w++){
		printf("%s\n-------------------\n", apostas[w].nome);
		for(z=1;z<=np;z++){
			printf("%d\n", apostas[w].pontuacao[z]);
			apostas[w].pontuacaototal = apostas[w].pontuacaototal + apostas[w].pontuacao[z];
		}
		printf("Total:\t%d\n\n", apostas[w].pontuacaototal);
	}
}
