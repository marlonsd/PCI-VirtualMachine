/* Trabalho de PC 1
 * Implementação de uma máquina virtual.
 * 
 * Grupo: Guilherme Cousin, Marlon Dias
 * machine.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

void initMem(memoria *op){
	int i;

	i = 0;
	
	while (i < SIZE_MEM){
		op[i]->valor[0] = '\0';
		op[i]->valor[1] = '\0';
		i++;
	}
}

void initReg(registrador *op){
	int i;
	
	i = 0;
	
	while (i < NUMERO_REGISTRADORES){
		op->valor[i] = '\0';
		i++;
	}
}

int conversao(char word){
	int aux;
	
	aux = conversaoHexa(word);
	
	if ((aux <= 0) || (aux >= 13)){
		return 0;
	}

	return aux;
}

int conversaoHexa(char c){
	
	switch(word){
		case '0': return 0;
			break;
		case '1': return 1;
			break;
		case '2': return 2;
			break;
		case '3': return 3;
			break;
		case '4': return 4;
			break;
		case '5': return 5;
			break;
		case '6': return 6;
			break;
		case '7': return 7;
			break;
		case '8': return 8;
			break;
		case '9': return 9;
			break;
		case 'A': return 10;
			break;
		case 'B': return 11;
			break;
		case 'C': return 12;
			break;
		case 'D': return 13;
			break;
		case 'E': return 14;
			break;
		case 'F': return 15;
			break;
		
		default: return 16;
	}
}

int execucao(memoria *op){
	int i, operacao;
	char aux;
	
	i = 0;
	aux = op[i]->valor[0];
	
	while ((i < SIZE_MEM) && (aux != '\0')){
		i++;
		
		operacao = conversaoHexa(aux);
		
		if (!acao(operacao, op[i])){
			printf("Instrução não existe.");
			return 0;
		}
		
		i++;
		aux = op[i]->valor[0];
	}
	
	/*while((scanf("%c", &c)) == 1){
		if (!conversao(c)){
			printf("Instrução não existe.");
			exit(1);
		}
		
		word[i] = c;
		i++; 
		
		scanf("%c", &c);
		
		aux = conversaoHexa(c)
		
		if (aux >= 16) {
			printf("Registrador não existe.");
			exit(1);
		}
		
		word[i] = c;
		i++; 
		
		scanf("%c", &c);
		
		aux = conversaoHexa(c);
		
		if (aux >= 16) {
			printf("Memória não existe.");
			exit(1);
		}
		
		word[i] = c;
		i++; 
		
		mem = aux << 4;
		
		scanf("%c", &c);
		
		aux = conversaoHexa(c);
		
		if (aux >= 16) {
			printf("Memória não existe.");
			exit(1);
		}
		
		word[i] = c;
		i++; 
		
		mem = mem | aux;
	}*/
}

int acao(char opcode, memoria dado){
	
	switch(opcode){
		case 0: return 0;
			break;
		case 1: return 1;
			break;
		case 2: return 2;
			break;
		case 3: return 3;
			break;
		case 4: return 4;
			break;
		case 5: return 5;
			break;
		case 6: return 6;
			break;
		case 7: return 7;
			break;
		case 8: return 8;
			break;
		case 9: return 9;
			break;
		case 10: return 10;
			break;
		case 11: return 11;
			break;
		case 12: return 12;
			break;
		case 13: return 13;
			break;
		case 14: return 14;
			break;
		case 15: return 15;
			break;
		
		default: return 16;
	}
}
