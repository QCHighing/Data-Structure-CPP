#include <iostream>
#include <time.h>

using namespace std;

// ÕÛ°ë²éÕÒ£¬ÊÊÓÃÓÚÓĞĞòÊı×é
int binarySearch(int* a, const int n, const int x);

// µİ¹éµÄÕÛ°ë²éÕÒ
int binarySearch(int* a, const int left, const int right, const int x);

int main()
{
    int a[10] = { 1,3,5,7,9,10,12,14,16,18 };
    int n = 10, index;

    clock_t start = clock();
    index = binarySearch(a, n, 12);
    clock_t end = clock();
    cout << "ÕÛ°ë²éÕÒ£º " << index << " " << end - start << " ms" << endl;

    start = clock();
    index = binarySearch(a, 0, n - 1, 12);
    end = clock();
    cout << "£¨µİ¹é£©ÕÛ°ë²éÕÒ£º " << index << " " << end - start << " ms" << endl;

    return 0;
}

int binarySearch(int* a, const int n, const int x)
{
    int left{ 0 }, right{ n - 1 };
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (x < a[middle])
            right = middle - 1;
        else if (x > a[middle])
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}


int binarySearch(int* a, const int left, const int right, const int x)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (x < a[mid])
        return binarySearch(a, left, mid - 1, x);
    else if (x > a[mid])
        return binarySearch(a, mid + 1, right, x);
    else
        return mid;
}