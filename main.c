// ------------------------------------------------------------
//  Trabalho Projetos em Computação I - Máquina Virtual
//	Implementação de uma máquina virtual.
//
// Alunos: Guilherme Cousin, Marlon Dias
// GitHub: https://github.com/marlonsd/PCI-VirtualMachine
// main.c
// ------------------------------------------------------------

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
	
	i = execucao();
	
	printRegistradores();
	
	if (i){
		printf("Execução finalizada com sucesso.\n");
	} else {
		printf("Algum problema foi encontrado na execução.\n");
	}
	
	return 0;
}
