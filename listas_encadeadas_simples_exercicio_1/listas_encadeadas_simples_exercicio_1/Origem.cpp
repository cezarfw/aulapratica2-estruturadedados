#include<stdio.h>
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void InserirMeio(int num, int posicao);
void InserirFim(int num);
void Listar();

struct ElementoDaLista_Simples
{
	int dado;
	ElementoDaLista_Simples* prox;
} *Head;


int main() {

	int op, num, pos, c;
	while (1) {
		op = menu();
		switch (op)
		{
		case 1:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			InserirInicio(num);
			break;
		case 2:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			InserirFim(num);
			break;
		case 3:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Digite a posicao desejada: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {}
			InserirMeio(num, pos);
			break;
		case 4:

			break;
		case 5:
			Listar();
			break;
		case 6:
			printf("\nFinalizando o programa!\n\n");
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir no inicio da lista encadeada simples\n");
	printf("2.Inserir no fim da lista encadeada simples\n");
	printf("3.Inserir no meio da lista encadeada simples\n");
	printf("4.Remover da lista encadeada simples\n");
	printf("5.Listar a lista encadeada simples\n");
	printf("6.Sair\n");
	printf("\nDigite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}

	system("Cls");
	return op;

}

void InserirInicio(int num) {
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (Head == NULL) {
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}


void Listar() {

	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}

	while (ElementoVarredura != NULL)
	{
		printf("%d ", ElementoVarredura->dado);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");
	system("pause");
}


void InserirFim(int num) {

	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (Head == NULL) {
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
		{
			ElementoVarredura = ElementoVarredura->prox;
		}
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;

	}
}

void InserirMeio(int num, int posicao) {

	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoDaLista_Simples* ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;
	if (posicao == 0) {
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}

}