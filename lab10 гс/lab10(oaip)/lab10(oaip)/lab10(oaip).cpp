#include <iostream>
using namespace std;

//рекурсивная функция для вычисления биномиального коэффициента//
long long binom(int n, int m) {

    if (m == 0 || m == n) { //базовые случаи//
        return 1; 
    }
    else {
        return binom(n - 1, m - 1) + binom(n - 1, m); //формула бинома ньютона для коэфф.//
    }
}

int main() {
    int n, m;
    cout << "Enter n and m (0 <= m <= n): ";
    cin >> n >> m;

    if (n < 0 || m < 0 || m > n) {
        cout << "Error." << endl;
        return 1;
    }

    long long result = binom(n, m); //вычисление и вывод//
    cout << "binom coef C = " << result << endl;

    return 0;
}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
////рукурсивная функция дл вычисления суммы синусов//
//double sin(int n, double x)
//{
//	if (n == 1) //базовый случай//
//	{
//		return sin(x);
//	}
//	else {
//		return sin(n * x) + sin(n - 1, x); //сумма синусов//
//	}
//}
//
//int main()
//{
//	int n;
//	double x;
//
//	cout << "Enter n: ";
//	cin >> n;
//	cout << "Enter x (rad): ";
//	cin >> x;
//
//	if (n <= 0)
//	{
//		cout << "Error." << endl;
//		return 1;
//	}
//
//	double result = sin(n, x); //вычисление и вывод//
//	cout << "Res: " << result << endl;
//
//	return 0;
//}