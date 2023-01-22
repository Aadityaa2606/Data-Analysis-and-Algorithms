#include <iostream>
using namespace std;

void descending_sort(int arr[], int n){
    int i, key, j;
    for(i=1; i<n; i++) {
        key = arr[i];
        j = i - 1;

        while(j>=0 && arr[j]%10 < key%10) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    descending_sort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}