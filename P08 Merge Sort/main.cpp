#include <iostream>

using namespace std;

template <class T>
void printArray(const T* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// 一次归并排序, 输入为已排序数组
template <class T>
void merge( T* a,  T*b, T* result, int m, int n)
{
    // 遍历等长元素
    int i = 0, j = 0, k = 0;
    while (i < m and j < n)
    {
        if (a[i] <= b[j])
        {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = b[j++];
        }
    }
    // 复制其余元素
    copy(a + i, a + m, result + k);
    copy(b + j, b + n, result + k);
}

// 一次归并排序, 输入为已排序数组 a[l,...,m]  a[m+1,...,n]
template <class T>
void merge(T* a, T* result, const int l, const int m, const int n)
{
    // 遍历等长元素
    int i = l, j = m + 1, k = l;
    while (i <= m and j <= n)
    {
        if (a[i] <= a[j])
        {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = a[j++];
        }
    }
    // 复制其余元素
    copy(a + i, a + m + 1, result + k);
    copy(a + j, a + n + 1, result + k);
}

// 一趟归并排序
template <class T>
void mergePass(T* a, T* result,  int n,  int h)
{
    int i = 1;   // [0,1,2,3, 4,5,6]  h=3, l=i, m=3=l+h-1, n=l+2*h-1, i=1/7/13...
    while (i + 2 * h - 1 <= n)
    {
        merge(a, result, i, i + h - 1, i + 2 * h - 1);
        i += 2 * h;
    }
    if (n > i + h - 1)
        merge(a, result, i, i + h - 1, n);
    else
        copy(a + i, a + n + 1, result + i);
}

// 归并排序（迭代式）
template <class T>
void mergeSort(T* a,  int n)
{
    if (a == nullptr or n <= 0) return;
    T* temp = new T[n + 1];
    int h = 1;  // 最初归并长度为1
    while (h < n)
    {
        mergePass(a, temp, n, h);
        h *= 2;
        mergePass(temp, a, n, h);
        h *= 2;
    }
    delete[] temp;
}

// 归并排序（递归式）
template <class T>
void mergeSort(T* a, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, a, left, mid, right);
}

int main(int argc, char** argv)
{
    // 测试一次归并排序
    //int a[] = { 1,3,5,7,9 };
    //int b[] = { 0,4,6,8,8,14,15 };
    //int ret[12] = { 0 };
    //merge(a, b, ret, 5, 7);
    //printArray(ret, 12);

    // 测试一次归并排序
    //int a[] = { 0,1,3,5,7,9,0,4,6,8,8,14,15 };
    //int ret[13] = { 0 };
    //merge(a, ret, 1, 5, 12);
    //printArray(a, 13);
    //printArray(ret, 13);

    // 归并排序
    int a[] = { 0,2,5,8,4,1,3,7,6 };   // a[0]不用
    mergeSort(a, 8);
    printArray(a, 9);
    mergeSort(a, 1, 8);
    printArray(a, 9);

    return 0;
}