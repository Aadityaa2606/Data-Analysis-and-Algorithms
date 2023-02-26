#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <limits.h>
#include <fstream>
using namespace std;

int find_in(vector<vector<int>>& memo, vector<int>& p, int i, int j) {
    if (memo[i][j] > -1) {
        return memo[i][j];
    }
    if (i == j) {
        memo[i][j] = 0;
    } else {
        memo[i][j] = numeric_limits<int>::max();
        for (int k = i; k < j; k++) {
            int q = find_in(memo, p, i, k) + find_in(memo, p, k + 1, j) + p[i] * p[k+1] * p[j+1];
            if (q < memo[i][j]) {
                memo[i][j] = q;
            }
        }
    }
    return memo[i][j];
}

int matrix_chain_order(vector<int> p) {
    int n = p.size() - 1;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return find_in(memo, p, 0, n - 1);
}

// UTILITY FUNCTONS

vector<vector<int>> generateRandomNumbers(const vector<int>& kNumbers) {
    vector<vector<int>> allNumbers;
    random_device device;
    mt19937 generator(device());
    
    for (int n : kNumbers) {
        vector<int> numbers;
        uniform_int_distribution<int> distribution(1, n);

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
        int temp;
        temp = matrix_chain_order(numbers);
        cout<<"Cost for n" << numbers.size() << " = " << temp << endl;
        long double duration=(long double)(clock() - start)/CLOCKS_PER_SEC;
        timeTaken.push_back(duration);
    }
    return timeTaken;
}


int main() {

    // vector<int> val_of_n = {100, 1000, 10000, 50000, 75000, 100000};
    // vector<int> val_of_n = {75000, 100000, 1000000, 1500000, 3000000};
    vector<int> val_of_n = {5,10,15,20,25};
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