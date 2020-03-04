#include <iostream>

using namespace std;

int sequentialSearch(int* a, const int n, const int x);

int main()
{
    int a[10] = { 1,3,5,7,9,0,2,4,6,8 };
    int n = 10;

    cout << sequentialSearch(a, n, 6) << endl;

    return 0;
}

int sequentialSearch(int* a, const int n, const int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
            return i;
    }
    return -1;
}