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
	memoria ram[SIZE_MEM];
	registrador variavel;
	int i, j, aux, mem;
	char word[4], c;
	
	initMem(&ram);
	initReg(&variavel)
	
	i = 0;
	j = 0;
	
	while((scanf("%c", &c)) == 1){
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
	}
	
	int execucao(*ram);
	
	return 0;
}
