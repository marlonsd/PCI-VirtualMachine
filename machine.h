/* Trabalho de PC 1
 * Implementação de uma máquina virtual.
 * 
 * Grupo: Guilherme Cousin, Marlon Dias
 * machine.h
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#define SIZE_MEM 256
#define NUMERO_REGISTRADORES 16

struct registro {
	char valor[NUMERO_REGISTRADORES];
}

typedef struct registro registrador;

struct memory {
	char valor[2];
}

typedef struct memory memoria;

void initMem(memoria *op);
void initReg(registrador *op);

int conversao(char *word);
int conversaoHexa(char c);
int execucao(memoria *op);

#endif