#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    vector<int> nums;
    int n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n-2; j++) {
            if(nums[i] > nums[i+1]) {
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }
    }


    for(int i=0; i<n; i++) cout << nums[i] << " ";
    return 0;
}