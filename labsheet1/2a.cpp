#include <iostream>
using namespace std;
#include <vector>
#include <ctime>

int main() {
    vector<int> nums;
    int ele, n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    cout << "Enter the elements one by one" << endl;
    for(int i=0; i < n; i++) {
        cin >> ele;
        nums.push_back(ele);
    }
    clock_t start = clock();
    for(int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i-1;
        while( j>=0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--; 
        }
        nums[j+1] = key;
    }
    double ftime = (double)(clock() - start)/CLOCKS_PER_SEC;
    cout << "Time taken = " << ftime << endl;
    for(int i=0; i <n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
