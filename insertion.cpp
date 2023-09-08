#include <iostream>

using namespace std;

//Algoritmo de Ordenamiento por Inserción

int main(){

    //arreglo de números
    int numeros[] = {4, 3, 8, 2, 1};
    // interador, almacenar posición y cambio de numeros
    int i, pos, aux;

    //Bucle que recorre todos los numeros por posición
    for(i=0;i<5;i++){
        // guardamos la posición
        pos = i;
        // el número que esta dentro de esa posición
        aux = numeros[i];

        //Hacemos comparaciones si la posición es mayor a cero, número a la izquierda es mayor a número actual entramos al WHILE
        while((pos >0) && (numeros[pos-1] > aux)){
            //Aqui hacemos el cambio de posición
            numeros[pos] = numeros[pos -1];
            pos--;
        }
        //Para refrescar cada vez que haga la iteración  
        numeros[pos] =  aux;
    }

    cout << "Orden ascendente: ";
    for(i=0;i<5;i++){
        cout << numeros[i] <<" - ";
    }


    cout << "\nOrden descendente: ";
    for(i=4; i>=0; i--){
        cout << numeros[i] << " - ";
    }


    return 0;
}

