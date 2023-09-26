#include <iostream>

using namespace std;
#include "reader.hpp"

//Función Minheapify: Ajusta un subárbol con raíz en el índice 'i' para cumplir la propiedad de Min Heap.

void Minheapify(Client *data, int n, int i) {
    int shorter = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //Vemos si el hijo izquierdo es menor que el padre
    if(l < n && data[l].income < data[shorter].income){
        shorter = l;
    }else{
        shorter = i;
    }
        
    //Vemos si el hijo derecho es menor que el padre
    if(r < n && data[r].income < data[shorter].income){
        shorter = r;
    }  
    
    if (shorter != i) {
        swap(data[i], data[shorter]); // Intercambia el nodo actual con el nodo más pequeño.
        Minheapify(data, n, shorter); // Llama recursivamente para ajustar el subárbol.
    }
}   

// Función buildMinHeap: Convierte el arreglo en un Min Heap.
void buildMinHeap(Client *data, int n){
    for (int i = (n / 2) - 1; i >= 0; i--){
        Minheapify(data, n, i); // Llama a Minheapify para cada nodo que no sea una hoja.
    }
}

// Función extractMinHeap: Extrae los elementos del Min Heap uno por uno para ordenarlos.
void extractMinHeap(Client *data, int n){

    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]); // Extrae el elemento mínimo (en la raíz) y lo coloca en la posición correcta.
        Minheapify(data, i, 0); // Llama a Minheapify para ajustar el subárbol restante.
    }
}

// Función heapSort: Ordena el arreglo de Clientes utilizando el algoritmo Heapsort.
void heapSort(Client *data, int n){
    buildMinHeap(data, n); // Convierte el arreglo en un Min Heap.
    extractMinHeap(data, n); // Extrae los elementos uno por uno para ordenarlos.
}

// Función print: Imprime los objetos Client en el arreglo.
void print(Client *data) {

    for(int i = 0; i < 1000; ++i){
        cout << i << " "<< data[i].name << " "<< 
        data[i].address << " "<< data[i].job << " " 
        << data[i].income << "\n";
    }


    cout << endl << endl << endl;

}
