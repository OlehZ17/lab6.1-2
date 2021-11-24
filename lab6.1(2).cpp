#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Calc(int* a, const int size, int& s, int& k, int i);

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 22;
	int a[n];

	int Low = -10;
	int High = 35;
	int s = 0;
	int k = 0;

	Create(a, n, Low, High, 0);
	cout << "a: "; Print(a, n, 0);

	Calc(a, n, s, k, 0);
	cout << "a: "; Print(a, n, 0);

	cout << "s:" << setw(4) << s << endl
		<< "k:" << setw(2) << k << endl;

}
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Calc(int* a, const int size, int& s, int& k, int i)
{
	if (a[i] > 0 || !(a[i] % 3 == 0)) {
		s += a[i];
		a[i] = 0;
		k++;
	}
	if (i < size - 1) {
		Calc(a, size, s, k, i + 1);
	}
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
