#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <limits.h>
#include <fstream>
using namespace std;


struct details
{
    int low;
    int high;
    int sum;
};
details find_max_crossing_subarray(vector<int> a, int low, int mid, int high)
{
    int left_sum, right_sum, sum, i, max_left, max_right;
    details d;
    sum = 0;
    left_sum = INT_MIN;
    for(i=mid;i>=low;i--)
    {
        sum += a[i];
        if (sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    right_sum = INT_MIN;
    sum=0;
    for(i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if (sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = left_sum + right_sum;
    return d;
}
details find_maximum_subarray(vector<int> a,int low,int high)
{
    details left_details,right_details,cross_details,d;
    int mid;
    if(low==high)
    {
        d.low = low;
        d.high = high;
        d.sum = a[low];
        return d;
    }
    mid = (low+high)/2;
    left_details = find_maximum_subarray(a,low,mid);
    right_details = find_maximum_subarray(a,mid+1,high);
    cross_details = find_max_crossing_subarray(a,low,mid,high);
    if((left_details.sum>=right_details.sum)&&(left_details.sum>=cross_details.sum))
        return left_details;
    else if((right_details.sum>=left_details.sum)&&(right_details.sum>=cross_details.sum))
        return right_details;
    else
        return cross_details;
}

// UTILITY FUNCTONS

vector<vector<int>> generateRandomNumbers(const vector<int>& kNumbers) {
    vector<vector<int>> allNumbers;
    random_device device;
    mt19937 generator(device());
    
    for (int n : kNumbers) {
        vector<int> numbers;
        uniform_int_distribution<int> distribution(0, n);

        for (int i = 0; i < n; i++) {
            numbers.push_back(distribution(generator));
        }

        allNumbers.push_back(numbers);
    }

    return allNumbers;
}

vector<long double> timeTaken(const vector<vector<int>>& allNumbers) {
    vector<long double> timeTaken;
    for (const auto& numbers : allNumbers) {
        clock_t start = clock();
        details temp;
        temp = find_maximum_subarray(numbers,0,numbers.size()-1);
        long double duration=(long double)(clock() - start)/CLOCKS_PER_SEC;
        timeTaken.push_back(duration);
    }
    return timeTaken;
}


int main() {

    vector<int> val_of_n = {100, 1000, 10000, 50000, 75000, 100000};
    // vector<int> val_of_n = {75000, 100000, 1000000, 1500000, 3000000};

    int k = val_of_n.size();
    vector<vector<int>> allNumbers = generateRandomNumbers(val_of_n);
    vector<long double> times = timeTaken(allNumbers);
    for (int i = 0; i < k; i++) {
        cout << "Time taken for n = " << allNumbers[i].size() << ": " << times[i] << " microseconds" << endl;
    }

    string s = "output_DCC.txt";
    ofstream myfile;
    myfile.open(s);
    for(int i=0; i<k; i++) {
        myfile << val_of_n[i] << endl;
    }
    myfile << endl << endl; 
    for(int i=0; i<k; i++) {
        myfile << times[i] << endl;
    }
    myfile.close();
    return 0;

}