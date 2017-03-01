/*
Proj 1 - Avaliador de Expressoes Matematicas
Utilizando Fila/Pilha
mudar a expressao de infixa para pos-fixa
-receber a string
-quebrar e inserir na pilha/fila
		Pilha: FiLo
		Fila: FiFo
-regra geral: se for numero vai para a fila, se for operando vai para a pilha.
		usar tabela para ver se necessario remover.
-um caso excessao
		parentese, ao transformar em pos-fixa os parenteses somem.
-fila no final vai estar em forma pos-fixa e pilha deve estar vazia.
		se a expressao for invalida a pilha vai continuar com elemento(s) dentro dela.
Resolucao:
-remover elementos da fila ate encontrar um OP.	
-inserir o primeiro numero da pilha em N2 e o seguinte em N1.
-empilhar o resultado da operaçao.	
-voltar ao primeiro passo.
Etapas:
1- Implementar Pilha e Fila (02/Mar)
2- Implementar Conversao de Infixa para Pos-Fixa (Polonesa Reversa) (09/Mar)
3- Impletamentar Calculo do Valor (16/Mar)
Entrega dia 23/Mar
N1: Double
N2: Double
OP: Char

typedef Struct pilha Pilha{char S;
			Pilha *prox;
			};
typedef Struct fila Fila{char S;
			Fila *prox;
			};
			
while (novo->prox != NULL); <- verificar a pilha, se estiver vazia ja analizou a expressao inteira.

ie:
input:3+2*7-4 (string) <- quebrar string, quebrador tem que pegar todas as partes
output:13

ie2:

(infixa) 1+2*3^2/3-4*(2-1)+9
(pos-fixa)1232^*3/+421-*-9+

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *prox;
		   }Node;

Node *aloca();
void inicia(Node **Pilha);	
void empilha(Node **Pilha);
void desempilha(Node **Pilha);
void queue(Node **Fila);
void unqueue(Node **Fila);

int main()
{
    Node *Fila = (Node*) malloc (sizeof(Node));
      if(!Fila)
	{
	  printf("Sem Memoria Disponivel");
	}
	else
	  {
	    inicia(&Fila);
	  }
	  
    Node *Pilha = (Node*) malloc (sizeof(Node));
    
      if(!Pilha)
	{
	  printf("Sem Memoria Disponivel");
	}
	else
	  {
	    inicia(&Pilha);
	  }
	  
    //double resultado;
    int op=0;
    
    do{
	printf("1-push\n");
	printf("2-pop\n");
	printf("3-queue\n");
	printf("4-unqueue\n");
	  scanf("%i", &op);
	
	switch(op)
	{
	  case 1:
	    empilha(&Pilha);
	    break;
	  case 2:
	    desempilha(&Pilha);
	    break;
	  case 3:
	    queue(&Fila);
	    break;
	  case 4:
	    unqueue(&Fila);
	    break;
	  default:
	    printf("Comando invalido\n\n");
	}

      }while(op!=0);
    return 0;
}

Node *aloca()
{
    Node *novo = (Node*) malloc(sizeof(Node));
      if(!novo)
	{
	  printf("vazia");
	}
	else
	  {
	    printf("digite o numero:");
	    scanf("%d", &novo->num);
	  }
    return novo;
}

void inicia(Node **Pilha)
{
    (*Pilha)->prox = NULL;
}

void empilha(Node **Pilha)
{
    Node *novo = aloca();
    novo->prox = NULL;
    if(!*Pilha)
      {
	(*Pilha)->prox = novo;
      }
      else
	{
	  Node *aux = (*Pilha)->prox;
	  while(aux->prox != NULL)
	    {
	     aux = aux->prox;
	    }
	  aux->prox = novo;
	}
}

void desempilha(Node **Pilha)
{
    if(!*Pilha)
      {
	printf("Vazia");
      }
      else
	{
	  Node *ultimo;
	  ultimo = (*Pilha)->prox;
	  Node *penultimo;
	  penultimo = *Pilha;
	  
	  while(ultimo->prox != NULL)
	    {
	      printf("\n \n %d \n \n",ultimo->num);
	      penultimo = ultimo;
	      ultimo = ultimo->prox;
	      printf("\n \n %d \n \n",ultimo->num);
	    }
	    
	  //printf("\n \n %d \n \n",ultimo->num);
	  //penultimo->prox =NULL;
	  //free(ultimo);
	}
}

void queue(Node **Fila)
{
    Node *novo = aloca();
    novo->prox = NULL;
    if(!*Fila)
      {
	(*Fila)->prox = novo;
      }
      else
	{
	  Node *aux = (*Fila)->prox;
	  while(aux->prox != NULL)
	    {
	      aux = aux->prox;
	    }
	  aux->prox = novo;
	}
}

void unqueue(Node **Fila)
{
    if(!*Fila)
    {
      printf("vazia");
    }
    else
      {
	Node *aux = (*Fila)->prox;
	(*Fila)->prox = aux->prox;
	free(aux);
      }
}