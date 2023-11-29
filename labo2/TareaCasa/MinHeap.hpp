#include <iostream>

using namespace std;

class MaxHeap
{
private:
    int size = 0;
    int *head = nullptr;

    int left(const int i);   
    int right(const int i);  
    int parent(const int i); 

public:
    
    MaxHeap(int *array, int size);  
    
    MaxHeap();                     
    
    ~MaxHeap();

    
    void swap(int element, int largest);
    void maxHeapify(int i);
    void buildMaxHeap(int *array);
    void heapsort();

    // Priority Queue methods
    int getMinimum();
    int extractMinimum();
    void decreaseKey(int current_key, int new_key);
    void insert(int key);
    void display();



};

int MaxHeap::left(const int i)
{
    return 2 * i + 1;
}

int MaxHeap::right(const int i)
{
    return 2 * i + 2;
}

int MaxHeap::parent(const int i)
{
    return i / 2;
}

MaxHeap::MaxHeap()
{
    this->size = 0;
    this->head = nullptr;
}

MaxHeap::MaxHeap(int *array, int size)
{
    this->size = size;
    this->head = array;
    buildMaxHeap(array);
}

MaxHeap::~MaxHeap()
{
    delete[] head;
}

void MaxHeap::swap(int i, int largest)
{
    int temp = head[i];
    head[i] = head[largest];
    head[largest] = temp;
}

void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && head[l] < head[i])
    {
        smallest = l;
    }
    if (r < size && head[r] < head[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(i, smallest);
        maxHeapify(smallest);
    }
}

void MaxHeap::buildMaxHeap(int *array)
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        maxHeapify(i);
    }
}

void MaxHeap::heapsort()
{
    buildMaxHeap(head);
    for (int i = size - 1; i >= 0; --i)
    {
        swap(0, i);
        --size;
        maxHeapify(0);
    }
}

int MaxHeap::getMinimum()
{
    return head[0];
}

int MaxHeap::extractMinimum()
{
    if (size < 1)
    {
        cerr << "Heap underflow" << endl;
        return -1;
    }
    int min = head[0];
    head[0] = head[size - 1];
    --size;
    maxHeapify(0);
    return min;
}

void MaxHeap::decreaseKey(int current_key, int new_key)
{
    if (new_key > head[current_key])
    {
        cerr << "New key is greater than the current key" << endl;
        return;
    }

    head[current_key] = new_key;
    while (current_key > 0 && head[parent(current_key)] > head[current_key])
    {
        swap(current_key, parent(current_key));
        current_key = parent(current_key);
    }
}

void MaxHeap::insert(int key)
{
    ++size;
    int i = size - 1;
    head[i] = key;
    while (i > 0 && head[parent(i)] > head[i])
    {
        swap(i, parent(i));
        i = parent(i);
    }
}

void MaxHeap::display()
{
    for (int i = 0; i < size; ++i)
    {
        cout << head[i] << " ";
    }
    cout << endl;
}
