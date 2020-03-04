#include <iostream>

using namespace std;

template<class T>
void BubbleSort(T* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
	int a[10] = { 1,3,5,7,9,0,2,4,6,8 };
	int n = 10;

	BubbleSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
	cout << endl;

	return 0;
}