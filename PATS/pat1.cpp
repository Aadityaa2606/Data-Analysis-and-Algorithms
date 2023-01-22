#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class components
{
    float ticket;
    float food;
    float luggage;

public:
    components()
    {
        ticket = 0;
        food = 0;
        luggage = 0;
    }

    components(float ticket, float food, float luggage)
    {
        ticket = ticket;
        food = food;
        luggage = luggage;
    }
    friend istream &operator>>(istream &in, components &i)
    {
        in >> i.ticket >> i.food >> i.luggage;
    }
    friend ostream &operator<<(ostream &out, components &i)
    {
        cout << i.ticket << " " << i.food << " " << i.luggage << endl;
    }

    // write definitions of other member functions and maximum cost by divide and conquer here
    static float find_cost(components x)
    {
        return x.ticket + x.food + x.luggage;
    }

    static components max(vector<components> elements, int start, int end)
    {
        float tot_cost_start = find_cost(elements[start]);
        float tot_cost_end = find_cost(elements[end]);

        if (start == end)
            return elements[start];

        if (end - start == 1)
        {
            if (tot_cost_start > tot_cost_end) 
                return elements[start];
            else 
                return elements[end];
        }

        int mid = (start + end) / 2;
        components left_max = max(elements, start, mid);
        components right_max = max(elements, mid + 1, end);

        if (find_cost(left_max) > find_cost(right_max)) 
            return left_max;
        else 
            return right_max;
    }
};

int main()
{
    int n;
    // cout << "Enter the number of components: ";
    cin >> n;
    vector<components> elements;
    components ele, max_cost;
    for(int i=0; i<n; i++) {
        cin >> ele;
        elements.push_back(ele);
    }
    clock_t start = clock();
    max_cost = max_cost.max(elements, 0, n-1);
    double f_time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout << max_cost << endl; 
    cout << "Time Taken = " << f_time;
    return 0;
}

