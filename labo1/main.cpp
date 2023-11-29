#include "iostream"
#include "Carro.cpp"


using namespace std;
void SelectionSort(Carro* arr, int  n);
void bubbleSort(Carro arr[], int n);

int main()
{
    Carro Toyota("Toyota", 2020, 30000);
    Carro Honda("Honda", 2015, 5000);
    Carro Nissan("Nissan", 2023, 20000);
    Carro kia("kia", 2008, 8000);

    Carro arr[4] = {Toyota, Honda, Nissan, kia};

    SelectionSort(arr, 4);
    for(int i = 0; i < 4; i++){
        cout << arr[i].getYear() << endl;
    }
    cout << endl;

    bubbleSort(arr, 4);
    for(int i = 0; i < 4; i++){
        cout << arr[i].getPrice() << endl; 
    }
    

    return 0;

}

void swap(Carro* arr, int i, int min) 
    {
        Carro temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    //SelectionSort implementation
    void SelectionSort(Carro* arr, int  n)
    {
        
        for(int i = 0; i < n-1; i++)
        {
            int min = i;

            for(int j = i+1; j<n; j++)
            {
                if( arr[j].getYear() < arr[min].getYear())
                    min =  j;
            }

            if(min != i)
                swap(arr,i,min);
        }
    } 

void bubbleSort(Carro arr[], int n) {
    // Iterar a través de los elementos del arreglo (n - 1) veces
    for (int i = 0; i < n - 1; i++) {
        // Cada iteración coloca el elemento más grande en su posición final correcta
        for (int j = n - 1; j > i; j--) {
            // Comparar el elemento actual con su elemento adyacente
            if (arr[j].getPrice() > arr[j - 1].getPrice()) {
                // Intercambiar los elementos si están en el orden incorrecto
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}