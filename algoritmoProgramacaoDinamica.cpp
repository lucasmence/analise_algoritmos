/*ALGORITMO DE PROGRAMACAO DINAMICA

RECURSOS UTILIZADOS PARA O DESENVOLVIMENTO DESTE ALGORITMO QUE PODEM SER ACESSADOS LIVREMENTE

>ALGORITMO BASE DE PROGRAMACAO DINAMICA UTILIZANDO MATRIZES PARA O CASO DA MOCHILA BOOLEANA
LINK: https://gist.github.com/marcoscastro/a39b24bfb512944b19a5

>RECURSO DE CONTAGEM DE MILISEGUINDOS, PARA PODER RETORNAR O TEMPO
LINK: http://professor.ufabc.edu.br/~daniel.martin/ED/tempo.html

*/
#include <iostream>
#include <windows.h>

using namespace std;

int Mochila(int W, int wt[], int b[], int n)
{
	// tabela
	int V[n + 1][W + 1];

	for(int w = 0; w <= W; w++)
		V[0][w] = 0;
	for(int i = 1; i <= n; i++)
		V[i][0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= W; w++)
		{	
			if(wt[i-1] <= w)
			{
				if((b[i-1] + V[i-1][w - wt[i-1]]) > V[i-1][w])
					V[i][w] = b[i-1] + V[i-1][w - wt[i-1]];
				else
					V[i][w] = V[i-1][w];
			}
			else
				V[i][w] = V[i-1][w];
		}
	}

	// retorno final
	return V[n][W];
}

int main()
{
	int inicio, final, contagem = 0;
	inicio = GetTickCount(); 
	int W = 50;
	int n = 3;
	int v[] = {40,56,10};
	int w[] = {10,30,20};
	int maiorValor = Mochila(W, w, v, n);
	final = GetTickCount();
    contagem = final - inicio;
    
	cout << "Valor ideal para a mochila: " << maiorValor << endl;
	cout << "Tempo decorrido: " << contagem  << "ms" << endl;

	return 0;
}
