#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Estrutura de um nó na BST
typedef struct No {
	int valor;
	struct No *esq, *dir;
} No;
// Função para criar um novo nó
No* criarNo(int val) {
	No *novoNo = (No*)malloc(sizeof(No));
	novoNo->valor = val;
	novoNo->esq = novoNo->dir = NULL;
	return novoNo;
}
// Função para inserir um valor na BST
No* inserir(No *raiz, int val) {
	if (raiz == NULL) return criarNo(val);
	
	if (val < raiz->valor)
	raiz->esq = inserir(raiz->esq, val);
	else if (val > raiz->valor)
	raiz->dir = inserir(raiz->dir, val);
	
	return raiz;
}
// Função auxiliar para encontrar o menor valor da subárvore direita
No* minimoValor(No *no) {
	No *atual = no;
	while (atual && atual->esq != NULL)
	atual = atual->esq;
	return atual;
}
No* remover(No *raiz, int val) {
 	if (raiz == NULL) return raiz;
 	if (val < raiz->valor)
 	raiz->esq = remover(raiz->esq, val);
 	else if (val > raiz->valor)
 	raiz->dir = remover(raiz->dir, val);
 	else {
 	// Caso 1: Nó é uma folha
 	if (raiz->esq == NULL && raiz->dir == NULL) {
 		free(raiz);
 		return NULL;
 	}
 	// Caso 2: Nó com um filho
 	else if (raiz->esq == NULL) {
 		No *temp = raiz->dir;
 		free(raiz);
 		return temp;
 	}
 	else if (raiz->dir == NULL) {
 		No *temp = raiz->esq;
 		free(raiz);
 		return temp;
 	}
 	// Caso 3: Nó com dois filhos
 	No *temp = minimoValor(raiz->dir);
 	raiz->valor = temp->valor;
 	raiz->dir = remover(raiz->dir, temp->valor);
 	}
 return raiz;
}
void preOrdem(No* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->valor); // Processa o nó atual
		preOrdem(raiz->esq); // Percorre a subárvore esquerda
		preOrdem(raiz->dir); // Percorre a subárvore direita
	}
}
main() {
	setlocale(LC_ALL, "Portuguese");
	No *raiz = NULL;
	int num = 0, sair = 0, close = 0, valor = 0;
	// Inserindo valores

	do{
		printf("---Informe os valores da árvore:---\n");
		scanf("%d",&valor);
		raiz = inserir(raiz, valor);
		
		printf("...Digite 1 para CONTINUAR ou 0 para SAIR: ...");
		scanf("%d",&close);	
	}while(close != 0);
	
	printf("Travessia pre ordem antes da remocão\n");
	preOrdem(raiz);
	printf("\n");
	
	do{
		printf("---Informe um valor a ser removido:---\n");
		scanf("%d",&num);
	
		printf("\n...Removendo o no...\n");
		raiz = remover(raiz, num);
		
		printf("Travessia pre ordem depois da remocao: \n");
		preOrdem(raiz);
		printf("\n");
	
		printf("...Digite 1 para CONTINUAR ou 0 para SAIR: ...");
		scanf("%d",&sair);
	}while(sair != 0);
	
}
