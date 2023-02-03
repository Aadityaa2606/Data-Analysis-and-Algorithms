#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}

int max_crossing_sum_subarray(int arr[], int l, int m, int h) {
    int left_sum = -100000;
    int sum = 0;

    for(int i=m; i>=l; i--) {
        sum += arr[i];
        if(sum > left_sum) left_sum = sum;
    }

    int right_sum = -100000;
    sum = 0;
    
    for(int i=m+1; i<h; i++) {
        sum += arr[i];
        if(sum > right_sum) right_sum = sum;
    }
    
    return (right_sum + left_sum);
}

int max_sum_subarray(int arr[], int l, int h) {
    if(l == h) return arr[l];

    int m = (l+h)/2;

    int left_max = max_sum_subarray(arr, l , m);
    int right_max = max_sum_subarray(arr, m+1, h);
    int cross_max = max_crossing_sum_subarray(arr, l, m, h);

    return max(left_max, right_max, cross_max);
}

int main() {
    int a[] = {-2, -5, 6 , -2 , -3, 1, 5, -6};

    printf("%d\n", max_sum_subarray(a, 0, 7));
    return 0;
}