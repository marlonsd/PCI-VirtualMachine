/* Trabalho de PC 1
 * Implementação de uma máquina virtual.
 * 
 * Grupo: Guilherme Cousin, Marlon Dias
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

int main(){
	int i, j, aux, mem;
	char word[4], c;
	
	initMem();
	initReg();
	
	i = 0;
	j = 0;
	
	scanf("%c", &c);
	while(c != '@'){
		if (c != '\n'){
			ram[j].valor[i] = c;
			i++;
			if (i == 2){
				j++;
				i = 0;
			}
		} else {
			i = 0;
		}
		scanf("%c", &c);
	}
	
	//printf("-- %c%c%c%c\n", ram[0].valor[0], ram[0].valor[1], ram[1].valor[0], ram[1].valor[1]);
	//printf("-- %c%c%c%c\n\n", ram[2].valor[0], ram[2].valor[1], ram[3].valor[0], ram[3].valor[1]);
	
	i = execucao();
	
	if (i){
		printf("Execução finalizada com sucesso.\n");
	} else {
		printf("Algum problema foi encontrado na execução.\n");
	}
	
	return 0;
}
