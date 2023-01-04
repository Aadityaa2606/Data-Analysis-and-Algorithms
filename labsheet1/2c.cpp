#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <string>

int main() {
    int ele, n;
    cout << "Enter the number of symbols: ";
    cin >> n;
    string seq;
    cout << "Enter the sequence: ";
    cin >> seq;
    clock_t start = clock();
    for(int i = 1; i < n; i++) {
        int key = seq[i];
        int j = i-1;
        while( j>=0 && seq[j] > key){
            seq[j+1] = seq[j];
            j--; 
        }
        seq[j+1] = key;
    }
    double ftime = (double)(clock() - start)/CLOCKS_PER_SEC;
    cout << "Time taken = " << ftime << endl;
    cout << "Sorted seqence = " << seq << endl;
    return 0;
}
 