#include <iostream>
#include <cmath>

using namespace std;

int main() { 
    int k;
    cin >> k;
    int arr[k];
    for(int i=0; i<k; i++) cin >> arr[i];

    int x, sum=0;
    cin >> x;
    
    for(int i=0; i<k/2; i++) {
        sum+=arr[i]*pow(x, i)+arr[k-i-1]*pow(x, k-i-1);
    }
    if(k%2!=0) sum+=arr[k/2]*pow(x, k/2);
    cout << sum;
    return 0;
}