#include <iostream>
using namespace std;

int maxsecuence(int* arr, int n){
    int maxi[n+1]; 
    int sum = 0;
    maxi[0] = 0;

    for(int i = 1; i <= n; i++){
        sum = max(sum + arr[i-1], arr[i-1]);
        maxi[i] = max(maxi[i-1], sum);
    }
    return maxi[n];
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int nums[n];

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int res = maxsecuence(nums, n);
        cout << res << endl;
    }
    
    return 0;
}