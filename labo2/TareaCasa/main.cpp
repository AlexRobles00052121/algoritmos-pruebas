#include <iostream>
#include "MinHeap.hpp"
#include "priorityQueue.hpp"
#include "reader.hpp"

using namespace std;

// Función para inicializar los datos de los clientes
void initializeClientData(Client data[], int rows, int cols)
{
    load_data(data, rows, cols);
}

// Función para crear y llenar el array de ingresos
int *createAndFillIncomesArray(Client data[], int rows)
{
    int *incomes = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        incomes[i] = data[i].income;
    }
    return incomes;
}

// Función para mostrar los resultados
void displayResults(MaxHeap &MaxHeap)
{
    // Mostrar el ingreso mínimo
    cout << "The minimum income is: " << MaxHeap.getMinimum() << endl;

    // Extraer el ingreso mínimo
    cout << "The minimum income extracted is: " << MaxHeap.extractMinimum() << endl;

    // Mostrar el ingreso mínimo
    cout << "The minimum income is: " << MaxHeap.getMinimum() << endl;

    // Reducir la clave del primer elemento
    MaxHeap.decreaseKey(0, 60);

    // Mostrar el ingreso mínimo
    cout << "The minimum income is: " << MaxHeap.getMinimum() << endl;

    // Mostrar el ingreso mínimo
    cout << "The minimum income is: " << MaxHeap.getMinimum() << endl;

    

    // Mostrar el montón (heap)
    MaxHeap.display();

    // Ordenar el array
    MaxHeap.heapsort();

    // Mostrar el array ordenado
    MaxHeap.display();
}

int main()
{
    const int rows = 1000;
    const int cols = 5;
    Client data[rows];

    initializeClientData(data, rows, cols);

    // Crear y llenar el array de ingresos
    int *incomes = createAndFillIncomesArray(data, rows);

    // Crear un objeto maximo
    MaxHeap MaxHeap(incomes, rows);

    // Insertamos la nueva llave
    MaxHeap.insert(40);

    // mostramos los resultados
    displayResults(MaxHeap);


    return 0;
}
