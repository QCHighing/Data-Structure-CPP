#include <iostream>

using namespace std;

template<class T>
void quickSort(T* a, const int left, const int right)
{
    if (left >= right) return;  // ����������ֻ��һ��Ԫ��ʱ�������ݹ�
    else
    {
        // ѡ����
        if (right - left == 1);
        else
        {   // ��ֵ�������
            int middle = (left + right) / 2;
            if (a[left] > a[middle])
                swap(a[middle], a[left]);
            if (a[middle] > a[right])
                swap(a[middle], a[right]);
            if (a[left] < a[middle])
                swap(a[middle], a[left]);
        }
        int pivot = left;

        // һ�λ���
        int i{ left }, j{ right + 1 };
        while (i < j)
        {
            do i++; while (a[i] < a[pivot]);    // ����ɨ��
            do j--; while (a[j] > a[pivot]);    // ����ɨ��
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[pivot], a[j]);                   // �����Ϊ��ʼ����
        pivot = j;

        // �ݹ�
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