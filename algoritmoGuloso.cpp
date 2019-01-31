/*ALGORITMO GULOSO

RECURSOS UTILIZADOS PARA O DESENVOLVIMENTO DESTE ALGORITMO QUE PODEM SER ACESSADOS LIVREMENTE

>RECURSO DE CONTAGEM DE MILISEGUINDOS, PARA PODER RETORNAR O TEMPO
LINK: http://professor.ufabc.edu.br/~daniel.martin/ED/tempo.html

*/


#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;


/*

ler os dados armazenando de forma sequencial

implementa uma algoritmo de ordenacao

na hora de comparar os objetos utilize a razao Vi/Wi

utilize um vetor de forma decrescente e ordenara os objetos por importancia

a parte de selecionar e so voce comecar no primeiro elemento e colocar no seu conjunto solucao
e ver se o conjunto continua factivel (se atinge o limite do peso total W)

se o peso do conjunto for igual ao peso inserido, o algoritmo pode ser encerrado

o peso pode ficar ate menor do que o maximo


nem sempre vai gerar uma solucao otima mas vai ser a solucao aproximada


*/

int VerificaSeEstaOrdenado(float AVetor[]){
	int estaOrdenado = 1; /*1 - sim | 0 - nao*/
	for (int i = 0; i < 8; i++){
		for (int j = i+1; j < 8; j++){
			if (AVetor[i] > AVetor[j]){
				estaOrdenado = 0;
				return estaOrdenado;
			}
		}
	}
	return estaOrdenado;
}

void InverteOrdenacao(float *vetor, int tamanho){
	int vetorAuxiliar[tamanho];
	for (int i = 0; i < tamanho; i++){
		vetorAuxiliar[i] = vetor[tamanho-1-i];
	}
	for (int i = 0; i < tamanho; i++){
		vetor[i] = vetorAuxiliar[i];
	}
}


void OrdenacaoPorSelecao(float *vetor, int tamanho){

	
	for (int i = 0; i < (tamanho-1); i++){
		int eleito = vetor[i];
		int menor = vetor[i];
		int posicao = i;
		
		for (int j = i+1; j < tamanho; j++){
			if (vetor[j] < menor)
			{
				menor = vetor[j];
				posicao = j;
			}
					
		}
		if (menor < vetor[i]){
			vetor[i] = menor;
			vetor[posicao] = eleito;
		}
		
		if (VerificaSeEstaOrdenado(vetor) == 1){ 
			break;
		}
	}
	
	InverteOrdenacao(vetor,tamanho);
}

int BuscaSequencial(float *vetor, int tamanho, int numero){
	for (int i = 0; i < tamanho; i++){
		if (vetor[i] == numero){
			return i;
		}
	}
	return -1;
}


int main(){ 

	int inicio, final, contagem = 0;
	inicio = GetTickCount(); 
	  
	int n = 3;
	int W = 50;
	int v[n] = {40,56,10};
	float valor[n];
	float valorMapeado[n];
	int w[n] = {10,30,20};
	int conjunto[n];
	int vetorIdeal[n];
	int tamanhoVetorIdeal = 0;
	
	for (int i = 0; i < n; i++){
		valor[i] = v[i]/w[i];
		valorMapeado[i] = valor[i];
	}
	
	OrdenacaoPorSelecao(valor,n); 
	
	
	int somaDePesoAtual = 0;
	int valorMochila = 0;
	
	
	for (int i = 0; i < n; i++){
		int pesoVetor = w[BuscaSequencial(valorMapeado,n,valor[i])];
		if ((pesoVetor+somaDePesoAtual) <= W ){
			somaDePesoAtual += pesoVetor;
			valorMochila +=  v[BuscaSequencial(valorMapeado,n,valor[i])];
			vetorIdeal[tamanhoVetorIdeal] = w[BuscaSequencial(valorMapeado,n,valor[i])];
			tamanhoVetorIdeal++;	
		}
		
	}	
	final = GetTickCount();
    contagem = final - inicio;
	
	cout << "Peso total da melhor combinacao realizada: " << somaDePesoAtual << endl;
	cout << "Valor total da melhor combinacao realizada: " << valorMochila << endl;
	cout << "Combinacao Realizada: ";
	for (int i = 0; i < tamanhoVetorIdeal; i++){
		cout << vetorIdeal[i] << " ";
	}
	cout << endl;
	
	cout  << "Tempo decorrido: " << contagem  << "ms" << endl;
	
}







