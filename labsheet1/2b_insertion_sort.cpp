#include <iostream>
using namespace std;
#include <vector>
#include <ctime>

int main()
{
    vector<int> nums;
    int ele, n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    cout << "Enter the elements one by one" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    int k;
    cout << "Enter the k value : ";
    cin >> k;
    int k_pos = -1;
    clock_t tstart = clock();
    for (int i = 1; i < n; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            if (nums[j] == k)
                k_pos++;
            j--;
        }
        nums[j + 1] = key;
        if (key == k)
            k_pos = j + 1;
    }
    double ftime = (double)(clock() - tstart) / CLOCKS_PER_SEC;
    cout << "Time taken = " << ftime << endl;
    cout << "Elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\nPosition of K = " << k_pos + 1 << endl;
    return 0;
}