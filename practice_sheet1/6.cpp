#include <iostream>
#include <string>
using namespace std;

int calc_sum(string name) {
    int sum = 0;
    for(int i = 0 ; i<name.size(); i++) sum+=((int)name[i]-96);
    return sum;
} 

void sort_names(string name[], int n) {
    int i, j;
    string key;
    for (i = 1; i < n; i++)
    {
        key = name[i];
        j = i - 1;
        while (j >= 0 && calc_sum(name[j]) < calc_sum(key))
        {
            name[j + 1] = name[j];
            j = j - 1;
        }
        name[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    string names[n];
    for(int i = 0; i < n; i++) cin >> names[i];
    sort_names(names, n);
    for(int i = 0; i < n; i++) cout << names[i] << " ";
    return 0;
}