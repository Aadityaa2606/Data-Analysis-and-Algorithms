#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<vector<int>> inverts;
    vector<int> inputs, tempVector;
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        inputs.push_back(temp); 
    }

    for(int i = 0; i <n; i++) {
        for(int j = i+1; j < n; j++) {
            if(inputs[i] > inputs[j]){
                tempVector.push_back(i+1);
                tempVector.push_back(j+1);
                inverts.push_back(tempVector);
            }
            tempVector.clear();
        }
    }

    // print out the inverts vector
    cout << "Inverts: " << endl;
    for(int i = 0; i < inverts.size(); i++) {
        for(int j = 0; j < 2; j++) {
            cout << inverts[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


