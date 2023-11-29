#include <iostream>

class PriorityQueue
{
private:
    int size = 0;
    int *head = nullptr;

    // Funciones de utilidad para calcular los índices de los hijos y el padre.
    int left(const int i);   
    int right(const int i);  
    int parent(const int i); 

public:
    
    PriorityQueue(int *array, int size); 
    PriorityQueue();                     

    
    void swap(int element, int largest);
    void maxHeapify(int i);
    void buildMaxHeap(int *array);
    void heapSort();

    
    int maxHeapMaximum();
    int maxHeapExtractMax();
    void maxHeapIncreaseKey(int current_key, int new_key);
    void maxHeapInsert(int key);
    void display();

    
    ~PriorityQueue();
};

int PriorityQueue::left(const int i)
{
    return 2 * i + 1;
}

int PriorityQueue::right(const int i)
{
    return 2 * i + 2;
}

int PriorityQueue::parent(const int i)
{
    return i / 2;
}

PriorityQueue::PriorityQueue()
{
    this->size = 0;
    this->head = nullptr;
}

// Constructor from an array and its size
PriorityQueue::PriorityQueue(int *array, int size) : size(size), head(array)
{
    buildMaxHeap(array);
}

// Max Heap methods
void PriorityQueue::swap(int i, int largest)
{
    int temp = head[i];
    head[i] = head[largest];
    head[largest] = temp;
}

void PriorityQueue::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && head[l] > head[i])
    {
        largest = l;
    }
    if (r < size && head[r] > head[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(i, largest);
        maxHeapify(largest);
    }
}

void PriorityQueue::buildMaxHeap(int *array)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

void PriorityQueue::heapSort()
{
    buildMaxHeap(head);
    int size = this->size;
    std::cout << size << std::endl;
    for (int i = this->size - 1; i >= 0; i--)
    {
        swap(0, i);
        this->size--;
        maxHeapify(0);
    }
    this->size = size;
}

// Métodos de la Cola de Prioridad
int PriorityQueue::maxHeapMaximum()
{
    // Devolvemos el máximo elemento de la cola de prioridad (raíz del Max Heap).
    return head[0];
}

int PriorityQueue::maxHeapExtractMax()
{
    // Extraemos y devolvemos el máximo elemento de la cola de prioridad

    if (size < 1)
    {
        std::cout << "Heap underflow" << std::endl;
        return -1;
    }
    int max = head[0];
    head[0] = head[size - 1];
    size--;
    maxHeapify(0);
    return max;
}

void PriorityQueue::maxHeapIncreaseKey(int current_key, int new_key)
{
    // Incrementa la llave de un elemento y ajusta la cola de prioridad.

    if (new_key < current_key)
    {
        std::cout << "New key is smaller than current key" << std::endl;
        return;
    }
    head[current_key] = new_key;
    while (current_key > 0 && head[parent(current_key)] < head[current_key])
    {
        swap(current_key, parent(current_key));
        current_key = parent(current_key);
    }
}

void PriorityQueue::maxHeapInsert(int key)
{
    // Insertamos un nuevo elemento en la cola de prioridad y ajusta el Max Heap.
    size++;
    head[size - 1] = -1;
    maxHeapIncreaseKey(size - 1, key);
}

void PriorityQueue::display()
{
    // Imprimimos los elementos de la cola de prioridad.
    for (int i = 0; i < size; i++)
    {
        std::cout << head[i] << " ";
    }
    std::cout << std::endl;
}

// Destructor
PriorityQueue::~PriorityQueue()
{
    // Liberamos la memoria asignada para el arreglo.
    delete[] head;
}