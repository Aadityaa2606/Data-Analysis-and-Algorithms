#include <iostream>
#include <vector>
#include <limits>

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

int matrix_chain_order(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return find_in(memo, p, 0, n - 1);
}

int main() {
    vector<int> p {30, 35, 15, 5, 10, 20, 25};
    int result = matrix_chain_order(p);
    cout << result << endl;
    return 0;
}
