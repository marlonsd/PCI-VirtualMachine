// ------------------------------------------------------------
//  Trabalho Projetos em Computação I - Máquina Virtual
//	Implementação de uma máquina virtual.
//
// Alunos: Guilherme Cousin, Marlon Dias
// GitHub: https://github.com/marlonsd/PCI-VirtualMachine
// machine.c
// ------------------------------------------------------------

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
		printf("-- %X%c%c%c\n", operacao, ram[i-1].valor[1], ram[i].valor[0], ram[i].valor[1]);
		if (!acao(operacao, &i)){
			printf("Instrução não existe.");
			return 0;
		}
		
		i++;
		if (i < SIZE_MEM){
			aux = ram[i].valor[0];
		}
		printf("\n");
	}
	
	return 1;
}

int acao(char opcode, int *position){
	int aux, c, i, indice, x, y, pos;

	pos = *position;
	
	switch(opcode){
		case 1: indice = conversaoHexa(ram[pos-1].valor[1]);
			x = leituraMem(getEndreco(ram[pos].valor[0], ram[pos].valor[1]));
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= 0x[%c%c]\n", indice, ram[pos].valor[0], ram[pos].valor[1]);
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 2: indice = conversaoHexa(ram[pos-1].valor[1]);
			x = getEndreco(ram[pos].valor[0], ram[pos].valor[1]);
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= 0x%c%c\n", indice, ram[pos].valor[0], ram[pos].valor[1]);
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 3: indice = conversaoHexa(ram[pos-1].valor[1]);
			x = variavel.valor[indice];
			indice = getEndreco(ram[pos].valor[0], ram[pos].valor[1]);
			printf("Memória [%X] = 0x%c%c\n", indice, ram[indice].valor[0], ram[indice].valor[1]);
			printf("Memória [%X] <= R[%X]\n", indice, conversaoHexa(ram[pos-1].valor[1]));
			conversaoHToChar(x, indice);
			printf("Memória [%X] = 0x%c%c\n", indice, ram[indice].valor[0], ram[indice].valor[1]);
			break;
			
		case 4: if (!conversaoHexa(ram[pos-1].valor[1])){
				indice = conversaoHexa(ram[pos].valor[0]);
				x = variavel.valor[indice];
				indice = conversaoHexa(ram[pos].valor[1]);
				printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
				printf("Registrador [%X] <= R[%X]\n", indice, conversaoHexa(ram[pos].valor[0]));
				variavel.valor[indice] = x;
				printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			} else {
				printf("Instrução não encontrada.\n\n");
				exit(1);
			}
			break;
			
		case 5: indice = conversaoHexa(ram[pos].valor[0]);
			x = variavel.valor[indice];
			indice = conversaoHexa(ram[pos].valor[1]);
			x = x + variavel.valor[indice];
			indice = conversaoHexa(ram[pos-1].valor[1]);
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= R[%X] + R[%X]\n", indice, conversaoHexa(ram[pos].valor[0]), conversaoHexa(ram[pos].valor[1]));
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 6: printf("Instrução com ponto flutuante. Não abordada.\n");
			break;
			
		case 7: indice = conversaoHexa(ram[pos].valor[0]);
			x = variavel.valor[indice];
			indice = conversaoHexa(ram[pos].valor[1]);
			x = x | variavel.valor[indice];
			indice = conversaoHexa(ram[pos-1].valor[1]);
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= R[%X] v R[%X]\n", indice, conversaoHexa(ram[pos].valor[0]), conversaoHexa(ram[pos].valor[1]));
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 8: indice = conversaoHexa(ram[pos].valor[0]);
			x = variavel.valor[indice];
			indice = conversaoHexa(ram[pos].valor[1]);
			x = x & variavel.valor[indice];
			indice = conversaoHexa(ram[pos-1].valor[1]);
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= R[%X] ^ R[%X]\n", indice, conversaoHexa(ram[pos].valor[0]), conversaoHexa(ram[pos].valor[1]));
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 9: indice = conversaoHexa(ram[pos].valor[0]);
			x = variavel.valor[indice];
			indice = conversaoHexa(ram[pos].valor[1]);
			x = x ^ variavel.valor[indice];
			indice = conversaoHexa(ram[pos-1].valor[1]);
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			printf("Registrador [%X] <= R[%X] xor R[%X]\n", indice, conversaoHexa(ram[pos].valor[0]), conversaoHexa(ram[pos].valor[1]));
			variavel.valor[indice] = x;
			printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			break;
			
		case 10: if (!conversaoHexa(ram[pos].valor[0])){
				y = conversaoHexa(ram[pos].valor[1]);
				i = 0;
				indice = conversaoHexa(ram[pos-1].valor[1]);
				c = variavel.valor[indice];
				
				printf("Registrador [%X] = 0x%X\n", indice, c);
				printf("Registrador [%X] <= R[%X] >> %d\n", indice, indice, conversaoHexa(ram[pos].valor[1]));
				
				while (i < y){
					aux = c & 1; // 1 = 00000001
					c = c >> 1;
					if (aux == 1){
						c = c | 128; // 128 = 10000000
					}
					i++;
				}
				
				variavel.valor[indice] = c;
				printf("Registrador [%X] = 0x%X\n", indice, variavel.valor[indice]);
			} else {
				printf("Instrução não encontrada.\n\n");
				exit(1);
			}
			
			break;
			
		case 11: indice = conversaoHexa(ram[pos-1].valor[1]);
			if (variavel.valor[indice] == variavel.valor[0]){
				printf("Registrador [%d] == Registrador [0], go to 0x%c%c", indice, ram[pos].valor[0], ram[pos].valor[1]);
				x = getEndreco(ram[pos].valor[0], ram[pos].valor[1]);
				*position = x - 1;
			} else {
				printf("Registrador [%d] =/= Registrador [0], go to 0x%X", indice, pos + 1);
			}
			break;
			
		case 12: if (!conversaoHexa(ram[pos-1].valor[1]) && !conversaoHexa(ram[pos].valor[0]) && !conversaoHexa(ram[pos].valor[1])){
				printf("Halt.\n");
				*position = 256;
			} else {
				printf("Instrução não encontrada.\n\n");
				exit(1);
			}
			
			break;
			
		default: return 0;
	}
	
	return 1;
}

int getEndreco(char most, char least){
	int i, aux;
	
	i = conversaoHexa(most);
	aux = conversaoHexa(least);
	
	i = i << 4;
	i = i | aux;
	
	return i;
}

int leituraMem(int endereco){
	int i, valor, aux;

	valor = conversaoHexa(ram[endereco].valor[0]);
	valor = valor << 4;
	
	aux = conversaoHexa(ram[endereco].valor[1]);
	
	valor = valor | aux;
	
	return valor;
}

void conversaoHToChar (int x, int pos){
	int aux;
	char c;
	
	aux = x & 15; // X AND 0F;
	x = x >> 4;
	c = conversaoChar(x);
	
	if (c == '\0'){
		printf("ERRO!\n");
		exit(1);
	}
	
	ram[pos].valor[0] = conversaoChar(x);
	
	c = conversaoChar(aux);
	
	if (c == '\0'){
		printf("ERRO!\n");
		exit(1);
	}
	
	ram[pos].valor[1] = conversaoChar(aux);
}

char conversaoChar(int x){
	char aux;
	
	aux = '\0';
	
	if ((x >= 0) && (x < 10)){
		aux = x + '0';
	} else {
		if ((x >= 10) && (x < 16)){
			aux = x + 'A' - 10;
		}
	}
	
	return aux;
}
