/*SE TIENE UNA MATRIZ CUADRADA DE TAMAÑO nxn 
Donde n es una potencia de 2. En la matriz se tiene numeros enteros
entre el 1 y el 100, incluyendo ambos extremos. Se le solicita determinar
cual es el numero mas pequeño dentro de la matriz.

-Como tenemos siempre matrices cuadradas, el tamaño mas pequeño que podemos tener es 2x2,
entonces, en ese caso, es necesario convertir todas las matrices entrantes en matrices 2x2,
si tenemos matrices 4x4 en 4 matrices 2x2, si tenemos 8x8, en 4 matrices 4x4 y 
despues 16 matrices 2x2 y asi, y cuando todas sean 1x2, buscar el numero menor en cada ellas y comparar
entonces, si la matriz es 2x2 buscar en la matriz numero mas pequeño, en otro caso, achicar la matriz
*/
#include <stdio.h>
#include <stdlib.h>

int Finalizar(int * matrizMenor, int tamanioOriginal, int numeroMenor){
	int menorReal, menorAux, hola;
	menorReal = matrizMenor[0];
	for(int i = 0; i< (numeroMenor); i++){
		printf("%d ", matrizMenor[i]);
		menorAux = matrizMenor[i];
		if(menorReal < menorAux){
			menorReal = menorReal;
		}
		else{
			menorReal = menorAux;
		}
	}
	printf("el numero menor es %d", menorReal);
	scanf("%d", &hola);
	return 0;
}

int ** ReductorMatriz(int tamanio, int ** matriz, int tamanioOriginal, int cantidad){
	int i,j,tamanioNuevo;
	tamanioNuevo = tamanioOriginal*cantidad;
	int ** matrizNueva = (int**)malloc(sizeof(int*)*(tamanioNuevo));
	for(i = 0; i < (tamanioNuevo); i++){
		matrizNueva[i] = (int*)malloc(sizeof(int)*(tamanio/2)); 
		}
	for(i = 0; i < (tamanioNuevo/2); i++){
		for(j = 0; j < (tamanio/2); j++){
			matrizNueva[i][j] = matriz[i][j];
		}
	}
	for(i = tamanioNuevo/2; i < (tamanioNuevo); i++){
		for(j = tamanio/2; j < (tamanio); j++){
			matrizNueva[i][j-(tamanio/2)] = matriz[i-(tamanioNuevo/2)][j];
		}
	}
	/*for(i= 0; i < tamanioNuevo; i++){
		for(j = 0; j < tamanio/2; j++){
			printf("%d_",matrizNueva[i][j]);
		}
	}*/
	return matrizNueva;
}
int busquedaMenor2x2(int ** matriz, int repeticion, int tamanioOriginal){
	int numero;
	int menor;
	menor = matriz[repeticion][0];
	for(int i = repeticion; i<= (repeticion+1); i++){
		for(int j = 0; j<= 1; j++){
			numero = matriz[i][j];
			if(menor <= numero){
				menor = menor;
			}
			else{
				menor = numero;
			}
		}	
	}
	return menor;
}

int Inicio(int ** matriz, int tamanioMatriz, int * matrizMenor, int repeticionBusqueda, int tamanioOriginal, int cantidad, int numeroMenor){
	if(repeticionBusqueda == (((tamanioOriginal*tamanioOriginal)/2))){
		return Finalizar(matrizMenor, tamanioOriginal, numeroMenor);
	}
	if(tamanioMatriz <= 2){
		matrizMenor[numeroMenor] = busquedaMenor2x2(matriz, repeticionBusqueda, tamanioOriginal);
		return Inicio(matriz, tamanioMatriz, matrizMenor, repeticionBusqueda+2, tamanioOriginal, cantidad, numeroMenor+1);
	}
	else{
		int ** MatrizNueva = ReductorMatriz(tamanioMatriz, matriz, tamanioOriginal, cantidad);
		return Inicio(MatrizNueva, (tamanioMatriz/2), matrizMenor, repeticionBusqueda, tamanioOriginal, cantidad*2, numeroMenor);
	}
}

int main(){
	int n, i, j,nMenor;
	printf("Ingrese tamanio de la matriz (debe ser potencia de 2)");
	scanf("%d", &n);
	nMenor = (n*2);
	if(n == 2){
		nMenor = 1;
	}
	else if(n == 4){
		nMenor == 4;
	}
	int ** matriz = (int**)malloc(sizeof(int*)*(n*n));
	for(i = 0; i< n; i++){
		matriz[i] = (int*)malloc(sizeof(int)*(n*n)); 
	}
	for(i = 0; i< n; i++){
		for(j = 0; j< n; j++){
			matriz[i][j] = rand();
		}
	}
	int * matrizMenor = (int*)malloc(sizeof(int)*(nMenor));
	return Inicio(matriz, n, matrizMenor, 0, n, 2, 0);
}
	