#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    clock_t t_start = clock();
    for(int j=0; j<n; j++) {
        int min=arr[j];
        int min_idx=j;
        for(int i=j; i<n; i++) {
            // min = min>arr[i] ? arr[i] : min;
            if(min>arr[i]) {
                min_idx=i;
                min=arr[i];
            }
        }
        int temp = arr[j];
        arr[j] = min;
        arr[min_idx] = temp;
    }
    clock_t t_end = clock();
    cout << "Time taken: " << (t_end-t_start)/(double)CLOCKS_PER_SEC << " seconds" << endl;
    for(const int &i : arr) cout << i << ' ';
    return 0;
}