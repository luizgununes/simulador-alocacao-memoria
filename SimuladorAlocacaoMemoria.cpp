#include <stdio.h> // Biblioteca para o printf e scanf.
#include <stdlib.h> // Biblioteca para o rand.
#include <locale.h> // Biblioteca para a regionalização.
#include <time.h> // Biblioteca para o srand.
#include <windows.h> // Biblioteca para o SetConsoleTitle.

#define N 50 // Tamanho do Vetor

// Zeros (0) representam posições de memória livres.
// Uns (1) representam posições de memória ocupadas.

int inicializacao(int memoria[N]) {
     int i,n;
     printf("Posição: [0 1 2 3 4 5 6 7 8 9|0 1 2 3 4 5 6 7 8 9|0 1 2 3 4 5 6 7 8 9|0 1 2 3 4 5 6 7 8 9|0 1 2 3 4 5 6 7 8 9|0]");
     printf("\n");
     printf("Memória: [");
     srand(time(NULL)); // Comando que randomiza as vagas do processo.
     for(i=0;i<=N;i++){
          memoria[i]=rand()%2; // Comando que delimita o valor máximo a ser randomizado.
          printf("%d-", memoria[i]);
          }
     printf("]\n");
}

int ff(int memoria[N], int processo) { // FirstFit (Primeira Vaga)
    int j, contador=0, posicao=0;
    for(j=0;j<N;j++){
                     if(memoria[j]==0)
                                      contador++;                                      
                     else contador=0;
                     if (contador==processo ){
                        posicao=(j-processo)+1;
                        return posicao;
                     }      
					 if(j==N-1)
    					return -1;                
    }		      
    }

int wf(int memoria[N], int processo) { // WorstFit (Pior Vaga)    
	int j, contador=0, posicao=0, aux, cont=0;
	for(j=0;j<N;j++){
                     if(memoria[j]==0)
                                      contador++;
                     else contador=0;
                     
                     if (contador>=processo && cont==0){
                        posicao=j-(N-1);          
                        aux=contador;
                        cont=1;
                     }  
                     if(contador>aux){
                        aux=contador;
                        posicao=j-contador+1;
                     } 
                   	 if(ff(memoria, processo)<0)
    					return -1; 		                                   
    }       
	return posicao;   
}

int bf(int memoria[N], int processo) { // BestFit (Melhor Vaga)
    	int j,i=0,contador=0, posicao=0, primeira,aux[N],cont,aux2[N];
    for (j=0;j<N;j++){
                      if(memoria[j]==0)
                                       contador++;
                      else contador=0;
                    
                   	 aux2[j]=contador;
                    
                      if (contador==processo && memoria[j+1]!=0){
                        posicao=(j-contador)+1;         
                        return posicao;
                     }  
                		              	 
                     if(contador>processo && memoria[j+1]!=0 ){
                     	
                     	primeira=contador-processo;
                        aux[j]=primeira;
					 }
					 
					 for(i=0;i<j;i++)
						 if(primeira<aux[i]){
					 		posicao=(j-contador)+1; 
					
					if(j==N-1)
    					if(ff(memoria, processo)<wf(memoria, processo))
    						return ff(memoria, processo);
    						
					 }
					 if(ff(memoria, processo)<0)
    					return -1;                           
    }   
	 return posicao;          
}

int main() {
    int memoria[N],processo=1;
    setlocale(LC_ALL, "Portuguese"); // Comando de regionalização.
    SetConsoleTitle("Simulador de Alocamento de Memoria"); // Comando que dá nome ao programa. 
    
    while(processo!=0){ // Comando para que o código só deixe de ser executado ao inserir zero.
   		inicializacao(memoria);	// Função que inicializa o vetor e o randomiza.
		printf("Informe o tamanho do processo: ");
		scanf("%d", &processo);	
		if(processo!=0)	{
		printf("FirstFit: %d\n",ff(memoria, processo) ); // Chama a função do FirstFit.
		printf("WorstFit: %d\n",wf(memoria, processo) ); // Chama a função do WorstFit.
		printf("BestFit: %d\n",bf(memoria, processo) ); // Chama a função do BestFit.
		printf("\n");
        }
		   }   	
}
