#include <iostream>

using namespace std;

template<class T>
void selectSort(T* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        if (min != i)
            swap(a[i], a[min]);
    }
}

int main()
{
	int a[10] = { 1,3,5,7,9,0,2,4,6,8 };
	int n = 10;

	selectSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
	cout << endl;

	return 0;
}

