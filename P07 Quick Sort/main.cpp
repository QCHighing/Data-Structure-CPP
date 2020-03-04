#include <iostream>

using namespace std;

template<class T>
void quickSort(T* a, const int left, const int right)
{
    if (left >= right) return;  // 待排序数列只有一个元素时，结束递归
    else
    {
        // 选枢轴
        if (right - left == 1);
        else
        {   // 中值放在左侧
            int middle = (left + right) / 2;
            if (a[left] > a[middle])
                swap(a[middle], a[left]);
            if (a[middle] > a[right])
                swap(a[middle], a[right]);
            if (a[left] < a[middle])
                swap(a[middle], a[left]);
        }
        int pivot = left;

        // 一次划分
        int i{ left }, j{ right + 1 };
        while (i < j)
        {
            do i++; while (a[i] < a[pivot]);    // 从左扫描
            do j--; while (a[j] > a[pivot]);    // 从右扫描
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[pivot], a[j]);                   // 最左侧为初始枢轴
        pivot = j;

        // 递归
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

int main(int argc, char* argv[])
{
    int a[10] = { 1,3,5,7,9,0,2,4,6,8 };
    int n = 10;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;

    return 0;
}