#include <iostream>
#include <locale.h>
using namespace std;
#define MAX 30

/*
Elabore um programa que permita digitar 30 n�meros inteiros.

Garantir que cada n�mero digitado seja maior do que o anterior, mantendo a ordem crescente da digita��o.

Ap�s digitado, cada n�mero dever� ser empilhado em uma estrutura respectiva, de acordo com o fato dele ser par ou �mpar.

Finalizada a digita��o dos 30 n�meros, os valores dever�o ser desempilhados e mostrados na tela, garantindo uma sequ�ncia decrescente.

Obs: Desenvolver essa solu��o implementando as pilhas em forma de lista encadeada e de vetor.
*/

struct Pilha
{
	int qtde;
	int numeros[MAX];
	int par[MAX];
	int impar[MAX];
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int pushPar(Pilha *p, int v)
{
	int podeEmpilharPar = (p->qtde < MAX);
	if (podeEmpilharPar)
	{
		p->par[p->qtde++] = v;
	}
	return podeEmpilharPar;
}

int pushImpar(Pilha *p, int v)
{
	int podeEmpilharImpar = (p->qtde < MAX);
	if (podeEmpilharImpar)
	{
		p->impar[p->qtde++] = v;
	}
	return podeEmpilharImpar;
}

int pop(Pilha *p, int v)
{
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar)
	{
		v = p->numeros[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Pilha *num;
	num = new Pilha;
	num = init();
	int teste = -999999999;
	int resto;

	for(int i = 0; i < 30; i++)
	{
		cout << "Digite o " << i + 1 << "� n�mero de 30 n�meros de forma crescente: " << endl;
		cin >> num->numeros[i];

		if(teste > num->numeros[i])
		{
			do
			{
				cout << "Digite o " << i + 1 << "� novamente de forma crescente: " << endl;
				cin >> num->numeros[i];
			}
			while(teste > num->numeros[i]);
			teste = num->numeros[i];
		}

		else
		{
			teste = num->numeros[i];
		}

		resto = num->numeros[i] % 2;

		if(resto == 0)
		{
			num->par[i] = num->numeros[i];
			pushPar(num, num->par[i]);
		}

		else
		{
			num->impar[i] = num->numeros[i];
			pushImpar(num, num->impar[i]);
		}

		system("cls");
	}

	cout << endl;

	for(int i = 0; i < 30; i++)
	{
		cout << pop(num, num->numeros[i]) << endl;
	}

	return 0;
}
