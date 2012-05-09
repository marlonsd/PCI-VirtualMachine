// ------------------------------------------------------------
//  Trabalho Projetos em Computação I - Máquina Virtual
//	Implementação de uma máquina virtual.
//
// Alunos: Guilherme Cousin, Marlon Dias
// GitHub: https://github.com/marlonsd/PCI-VirtualMachine
// machine.h
// ------------------------------------------------------------

#ifndef MACHINE_H_
#define MACHINE_H_

#define SIZE_MEM 256
#define NUMERO_REGISTRADORES 16

struct registro {
	int valor[NUMERO_REGISTRADORES];
};

typedef struct registro registrador;

struct memory {
	char valor[2];
};

typedef struct memory memoria;

void initMem();
void initReg();

int conversao(char word);
int conversaoHexa(char c);
int execucao();
int acao(char opcode, int *pos);
char leituraMem(int endereco);
char getEndreco(char most, char least);
void conversaoHToChar (int x, int pos);
char conversaoChar(int x);
void printRegistradores();

memoria ram[SIZE_MEM];
registrador variavel;

#endif
