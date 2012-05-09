/* Trabalho de PC 1
 * Implementação de uma máquina virtual.
 * 
 * Grupo: Guilherme Cousin, Marlon Dias
 * machine.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

void initMem(){
	int i;

	i = 0;
	
	while (i < SIZE_MEM){
		ram[i].valor[0] = '\0';
		ram[i].valor[1] = '\0';
		i++;
	}
}

void initReg(){
	int i;
	
	i = 0;
	
	while (i < NUMERO_REGISTRADORES){
		variavel.valor[i] = '\0';
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
	
	//printf("conversão: %c\n", c);
	
	switch(c){
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
		case '\0': return 0;
			break;
		default: return 16;
	}
}

int execucao(){
	int i, operacao;
	char aux;
	
	i = 0;
	aux = ram[i].valor[0];
	
	while ((i < SIZE_MEM) && (aux != '\0')){
		i++;
		
		operacao = conversaoHexa(aux);
		printf("-- %d%c%c%c %d\n", operacao, ram[i-1].valor[1], ram[i].valor[0], ram[i].valor[1], i);
		if (!acao(operacao, i)){
			printf("Instrução não existe.");
			return 0;
		}
		
		i++;
		aux = ram[i].valor[0];
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
	printf("\n%d\n", i);
	return 1;
}

int acao(char opcode, int pos){
	int indice, x, y;
	
	switch(opcode){
		case 1: indice = conversaoHexa(ram[pos-1].valor[1]);
			x = leituraMem(ram[pos].valor[0]);
			y = leituraMem(ram[pos].valor[1]);
			printf("Registrador [%d] = %d\n", indice, variavel.valor[indice]);
			printf("Registrador [%d] = %d + %d\n", indice, x, y); //0x%c 0x%c\n", indice, ram[pos].valor[0], ram[pos].valor[1]);
			variavel.valor[indice] = x + y;
			printf("Registrador [%d] = %d\n", indice, variavel.valor[indice]);//variavel.valor[indice]);
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
		default: return 0;
	}
	
	return 1;
}

int leituraMem(char word){
	int i, valor, aux;
	
	i = conversaoHexa(word);

	aux = conversaoHexa(ram[i].valor[0]);
	valor = aux << 4;
	//printf("%c %d -- %d %d\n", ram[i].valor[1], i, aux, valor);
	//printf("\t-- %c -> %d\n", word, aux);
	aux = conversaoHexa(ram[i].valor[1]);
	valor = valor | aux;
	
	return valor;
}
