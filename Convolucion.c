// Mariano Ugalde
// 06/01/2023
// Convolucion discreta basica

#include <stdio.h>
#include <string.h>

int main() {

    // Matriz identidad
    int matrizindentidad[3][3] = {
        {1, 2, 1}, 
        {2, 4, 2}, 
        {1, 2, 1}
    };

    // Creando la matriz
    int matriz[3][3];

    // Relleando la matriz
    printf("Ingrese los valores de la matriz\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {

                printf("matriz[%d][%d] = ", i, j);
                scanf("%d", &matriz[i][j]);
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++)
                        printf("%4d", matriz[x][y]);
                    printf("\n");
                }
                printf("\n\n");
        }

    // Creando la matriz extendida
    int matrizextendida[7][7];

    // Inicializando la matriz extendida
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            matrizextendida[i][j] = 0;

    // Ponemos la matriz en la matriz extendida
    for (int i = 2; i < 5; i++)
        for (int j = 2; j < 5; j++)
            matrizextendida[i][j] = matriz[i-2][j-2];
    
    // Imprimimos la matriz extendida
    printf("Matriz extendida\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++)
            printf("%4d ", matrizextendida[i][j]);
        printf("\n");
    }

    // Creando la matriz resultado
    int matrizresultado[5][5];

    // Variable para la suma
    int suma = 0;

    // Convolucion discreta
    // Los dos primeros for son para recorrer la matriz extendida
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            // Los dos siguientes for son para multiplicar la matriz extendida con la matriz identidad
            for(int k = 0; k < 3; k++)
                for(int l = 0; l < 3; l++)
                    // Calculamos la suma de la multiplicacion de la matriz extendida con la matriz identidad
                    suma += matrizextendida[k+i][j+l] * matrizindentidad[k][l];
            // Guardamos el resultado en la matriz resultado
            matrizresultado[i][j] = suma;
            // Reiniciamos la suma
            suma = 0;
        }

    // Imprimimos la matriz resultado
    printf("Matriz resultante\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%4d ", matrizresultado[i][j]);
        printf("\n");
    }
    return 0;
}