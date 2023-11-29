#include "labo02.hpp"

using namespace std;

int main(void){

    int n = 1000;
    Client data[n];
    load_data(data);
    heapSort(data, n);
    print(data);
    

    cout << endl;
    return 0;
}
