#include <iostream>
#include "minheap.hpp"
#include "insertNodes.hpp"
// Función principal
int main()
{
    // Crear la cola de prioridad
    SymbolPriorityQueue queue;
    insertData(queue);

    cout << "Size of the queue: " << queue.getSize() << endl;

    // Imprimir el contenido de la cola de prioridad
    while (!queue.isEmpty())
    {
        TreeNode *node = queue.extractMin();
        cout << "Symbol: " << node->symbol << ", Probability: " << node->probability << endl;
        delete node;
    }

    return 0;
}