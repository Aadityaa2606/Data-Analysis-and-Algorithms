#include <iostream>
using namespace std;

int *max(int *a, int *b, int *c)
{
    if (a[2] >= b[2] && a[2] >= c[2])
        return a;
    else if (b[2] >= a[2] && b[2] >= c[2])
        return b;
    return c;
}

auto max_crossing_sum_subarray(int arr[], int l, int m, int h)
{
    int i, j;
    int *ans = new int[3];
    int left_sum = -100000;
    int sum = 0;

    for (i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = -100000;
    sum = 0;

    for (j = m + 1; j < h; j++)
    {
        sum += arr[j];
        if (sum > right_sum)
            right_sum = sum;
    }

    ans[0], ans[1], ans[2] = i,j,left_sum+right_sum;
    return ans;
}

int* max_sum_subarray(int arr[], int l, int h)
{
    int *ans = new int[3];
    if (l == h){
        ans[0],ans[1],ans[2] = l,h,arr[l];
        return ans;
    }

    int m = (l + h) / 2;

    int* left_max = max_sum_subarray(arr, l, m);
    int* right_max = max_sum_subarray(arr, m + 1, h);
    int* cross_max = max_crossing_sum_subarray(arr, l, m, h);

    return max(left_max, right_max, cross_max);
}

int main()
{
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int* ans = max_sum_subarray(a, 0, 7);
    cout << "Max_sum = " << ans[2] << endl;
    for(int i = ans[0]; i < ans[1]; i++) cout << a[i] << ' '; 
    cout << ans[0];
    return 0;
}