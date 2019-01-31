/*ALGORITMO DE FORCA BRUTA

RECURSOS UTILIZADOS PARA O DESENVOLVIMENTO DESTE ALGORITMO QUE PODEM SER ACESSADOS LIVREMENTE

>ALGORITMO DE COMBINACAO
LINK: http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

>RECURSO DE CONTAGEM DE MILISEGUINDOS, PARA PODER RETORNAR O TEMPO
LINK: http://professor.ufabc.edu.br/~daniel.martin/ED/tempo.html

*/



#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

// inicializacao das variaveis globais

	int W =  50;
	int tamanhoVetor = 3;
	int v[3] = {40, 56, 10};
	int w[3] = {10, 30, 20}; 
	int maiorValor = 0;
	int vetorIdeal[3] = {0,0,0};
	int tamanhoVetorIdeal = tamanhoVetor;
	/*
	W =  ?;  -> tamanho da mochila, maximo que ela consegue carregar
	
	tamanhoVetor = ?; -> tamanho do vetor, deve ser sempre alterado a partir do momento que o numero de itens no valor for alterado
	
	v[] = {V1, V2... Vn}; -> vetor com os itens ordenados representando o valor que cada item agrega consigo, respectivamente
	
	w[] = {W1, W2... Wn}; -> vetor com os itens ordenados e representando cada tamanho (peso) que ira fazer diferenCa na mochila
	
	maiorValor = ?; -> o maior valor que o sistema conseguiu agregar com uma combinacao sem passar do peso limite
	
	vetorIdeal[] = {I1, I2... In}; -> a combinacao ideal que E salva, nAo passando do limite de peso da mochila (W)
	
	tamanhoVetorIdeal = tamanhoVetor; -> o tamanho que o vetor que carrega a combinacao ideal vai conter, ele inicia com o mesmo
	tamanho do vetor original, pois e o maior numero que ele pode armazenar que e o tamanho original do vetor ideal, porem
	na hora de exibir os RESULTADOS FINAIS e ele quem vai indicar ate que ponto o vetor vai imprimir as combinacoes
	
	*/
	

int BuscaSequencial(int numero){
	for (int i = 0; i < tamanhoVetor; i++){
		if (w[i] == numero){
			return i;
		}
	}
	return -1;	
}

void combinarAte(int vetor[], int combinacao[], int inicio, int fim,
                     int indice, int numero)
{
	
	int valorCombinacaoAtual = 0;
	int pesoCombinacaoAtual = 0;
	

    if (indice == numero)
    {
    	cout << "C: ";
        for (int j = 0; j < numero; j++){
        	valorCombinacaoAtual += v[ BuscaSequencial( combinacao[j] ) ]; 
        	pesoCombinacaoAtual += combinacao[j];
        	
        	cout << combinacao[j];
        	if (j < (numero-1)){
        		cout << ",";	
			}
			else{
				cout << " ";	
			}
        	
		}
        cout << " / W: "<< pesoCombinacaoAtual<<" / V: " << valorCombinacaoAtual << endl;
        if (pesoCombinacaoAtual <= W){
        	if (valorCombinacaoAtual > maiorValor){
        		maiorValor = valorCombinacaoAtual;
        		tamanhoVetorIdeal = numero;
        		for (int j = 0; j < numero; j++){
        			vetorIdeal[j] = combinacao[j];
				}
			}
		}
        return;
    }
 
 	//gravando e gerando a proxima combinacao utilizando a recursivdade
    for (int i=inicio; i<=fim && fim-i+1 >= numero-indice; i++)
    {
        combinacao[indice] = vetor[i];
        combinarAte(vetor, combinacao, i+1, fim, indice+1, numero);
    }
}

void imprimirCombinacao(int vetor[], int n, int numero)
{

    int guardado[numero];
 
    combinarAte(vetor, guardado, 0, n-1, 0, numero);
}
 
int main()
{
    
    int camadas = tamanhoVetor;
    
    int inicio, final, contagem = 0;
	inicio = GetTickCount(); 
    
    for (int i = 1; i <= camadas; i++){
    	imprimirCombinacao(w, tamanhoVetor, i);
	}
	
	
	cout << "RESULTADOS FINAIS " << endl << "======================" 
	<< endl << "VALOR DOS ITENS: " << maiorValor << endl << "ITENS UTILIZADOS : ";
	for (int i = 0; i < tamanhoVetorIdeal; i++){
		
		cout << vetorIdeal[i];
		if (i < (tamanhoVetorIdeal-1)){
        	cout << ",";	
		}
		else{
			cout << " ";	
		}
	}
	final = GetTickCount();
    contagem = final - inicio;
	
	
	cout << endl << "Tempo decorrido: " << contagem  << "ms" << endl;
	
    
}
