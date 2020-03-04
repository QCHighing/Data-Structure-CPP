#include <iostream>

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main(int argc, char** argv)
{
	int a{ 1 }, b{ 2 };
	swap(a, b);
	printf("a=%d, b=%d", a, b);
	return 0;
}