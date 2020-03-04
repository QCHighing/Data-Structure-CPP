#include <iostream>

using namespace std;

template<class T>
void insertSort(T* a, int n)
{
    for (int right = 1; right < n; right++)
    {
        int left = right - 1;
        T temp = a[right];
        while (temp < a[left] and left >= 0)
        {
            a[left + 1] = a[left];
            left--;
        }
        int middle = left + 1;
        a[middle] = temp;
    }
}

int main(int argc, char* argv[])
{
    int a[10] = { 1,3,5,7,9,0,2,4,6,8 };
    int n = 10;

    insertSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;

    return 0;
}

