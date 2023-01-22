#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
using namespace std;

class components
{
    int x;
    int y;
public:
    friend istream &operator>>(istream &in, components &i)
    {
        in >> i.x >> i.y;
    }
    friend ostream &operator<<(ostream &out, components &i)
    {
        cout << i.x << " " << i.y << endl;
    }

    static components max(vector<components> elements, int low, int high)
    {
        float dist_low = sqrt(pow(elements[low].x, 2) + pow(elements[low].y, 2));
        float dist_high = sqrt(pow(elements[high].x, 2) + pow(elements[high].y, 2));

        if (high - low == 1)
        {
            if (dist_low > dist_high){
                return elements[low];
            }
            else{
                return elements[high];
            }
        };
        components max1 = max(elements, low, (low + high) / 2);
        components max2 = max(elements, (low + high)/2 + 1, high);

        if (sqrt(pow(max1.x, 2) + pow(max1.y, 2)) > sqrt(pow(max2.x, 2) + pow(max2.y, 2))){
            return max1;
        }
        else{
            return max2;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<components> elements;
    components temp, max_dist;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        elements.push_back(temp);
    }
    clock_t low = clock();
    max_dist = max_dist.max(elements, 0, n - 1);
    double f_time = (double)(clock() - low) / CLOCKS_PER_SEC;
    cout << max_dist << endl;
    cout << f_time;
    return 0;
}
