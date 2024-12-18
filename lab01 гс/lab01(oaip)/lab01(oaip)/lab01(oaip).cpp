////pervoe zadanie osnovnoi variant(5)//
//#include <iostream>
//using namespace std;
//
//int GetRoot1() //функция для вычисления корня первого уравнения//
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
// 
//	//вычисления для метода дихотоми//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((exp(x) - 3 - 1) / x) * ((exp(a) - 3 - 1) / a) <= 0) //подстановка уравнения//
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//int GetRoot2() //функция для вычисления корня второго уравнения//
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
// 
//	//вычисления для метода дихотоми//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if ((0.2 * (x * x)) * (0.2 * (a * a)) <= 0) //подстановка уравнения//
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
////функция указателя//
//void ShowResults(int (*ff)()) 
//{
//	cout << ff() << endl;
//}
//
////использование функции указателя для выбора необходимого уравнения//
//void main()
//{
//	ShowResults(GetRoot2);
//}
//
//
//
////pervoe zadanie perviy dop(8)//
//#include <iostream>
//using namespace std;
//
//int GetRoot1() //функция для вычисления корня первого уравнения//
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//    //вычисления для метода дихотоми//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((x * x * x) + 3 * x - 1) * ((a * a * a) + 3 * a - 1) <= 0) //подстановка уравнения//
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//int GetRoot2() //функция для вычисления корня второго уравнения//
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//    //вычисления для метода дихотоми//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if ((exp(x) - 4) * (exp(a) - 4) <= 0) //подстановка уравнения//
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
////функция указателя//
//void ShowResults(int (*ff)())
//{
//	cout << ff() << endl;
//}
//
////использование функции указателя для выбора необходимого уравнения//
//void main()
//{
//	ShowResults(GetRoot1);
//}



////pervoe zadanie vtoroi dop(9)//
//#include <iostream>
//using namespace std;
//
//int GetRoot1() //функция для вычисления корня первого уравнения//
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((x * x* x) + x - 4) * ((a * a * a) + a - 4) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//int GetRoot2()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if ((1 - (x * x)) * (1 - (a * a)) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//void ShowResults(int (*ff)())
//{
//	cout << ff() << endl;
//}
//
//
//
//void main()
//{
//	ShowResults(GetRoot2);
//}



////pervoe zadanie dop(7)//
//#include <iostream>
//using namespace std;
//
//int GetRoot1()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((x * x * x) + 2 * x - 4) * ((a * a * a) + 2 * a - 4) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//int GetRoot2()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((x * x) - 1) * ((a * a) - 1) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//void ShowResults(int (*ff)())
//{
//	cout << ff() << endl;
//}
//
//
//
//void main()
//{
//	ShowResults(GetRoot2);
//}



////pervoe zadanie tretiy dop(11)//
//#include <iostream>
//using namespace std;
//
//int GetRoot1()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if ((exp(x) + 2 * (x * x) - 3) * (exp(a) + 2 * (a * a) - 3) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//int GetRoot2()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	float a = -100, b = 100, e = 0.0001, x;
//	cout << "Введите a: ";
//	cin >> a;
//	cout << "Введите b: ";
//	cin >> b;
//
//	while ((abs(a - b)) > 2 * e)
//	{
//		x = (a + b) / 2;
//
//		if (((x * x * x) + 3) * ((a * a * a) + 3) <= 0)
//		{
//			b = x;
//		}
//		else a = x;
//	}
//	cout << x;
//	return 0;
//}
//
//
//
//void ShowResults(int (*ff)())
//{
//	cout << ff() << endl;
//}
//
//
//
//void main()
//{
//	ShowResults(GetRoot2);
//}



////vtoroe zadanie osnovnoi variant(5)//
//#include <iostream>
//#include <cstdarg>
//using namespace std;
//
//int kvadr(int count, ...) { //функция для определения количества точных квадратов среди переданных чисел//
//    va_list args; //создание списка аргументов//
//    va_start(args, count); //инициализация va_list, устанавливая начальное положение для доступа к аргументам//
//
//    int squareCount = 0;
//
//    for (int i = 0; i < count; i++) {
//        int num = va_arg(args, int); //получение следующего аргумента из va_list//
//        
//        int sqrtNum = sqrt(num); //проверка, является ли число точным квадратом//
//        if (sqrtNum * sqrtNum == num) {
//            squareCount++;
//        }
//        //конец проверки//
//    }
//
//    va_end(args); //завершение работы со списком аргументов//
//    return squareCount;
//}
//
//int main() {
//    setlocale(LC_CTYPE, "rus");
//
//    cout << "Количество точных квадратов: " << kvadr(11, 5, 9, 18, 81, 25, 66, 32, 4, 16, 69, 132) << endl; //первый вызов функции kvadr//
//    cout << "Количество точных квадратов: " << kvadr(12, 9, 2, 6, 25, 36, 256, 121, 72, 64, 289, 3, 17) << endl; //второй вызов функции kvadr//
//    cout << "Количество точных квадратов: " << kvadr(5, 88, 32, 16, 49, 225) << endl; //третий вызов функции kvadr//
//
//    return 0;
//}
//
//
//
////vtoroe zadanie perviy dop(8)//
//#include <iostream>
//#include <cstdarg>
//using namespace std;
//
////функция для нахождения минимального числа из ряда//
//int mn(int size, ...)
//{
//    va_list args; //создание списка аргументов переменной длинны//
//    va_start(args, size); //инициализация va_list, устанавливая начальное положение для доступа к аргументам//
//
//    int min = va_arg(args, int), buffer; //получение первого аргумента и обозначение предположительного минимума//
//
//    for (int i = 1; i < size; i++)
//    {
//        buffer = va_arg(args, int); //получение следующего аргумента//
//        if (buffer < min)
//        {
//            min = buffer; //если текущий аргумент меньше минимума - минимум обновляется//
//        }
//    }
//
//    va_end(args); //завершение работы со списком аргументов//
//    return min; 
//}
//
//int main()
//{
//    setlocale(LC_CTYPE, "rus"); 
//
//    cout << "Минимальное число из ряда: " << mn(11, 5, -90, 32, 874, 21, 54, 1, -12, 64, 41, 73) << endl; //первый вызов функции mn//
//    cout << "Минимальное число из ряда: " << mn(5, 4, 9, 875, 0, 1) << endl; //второй вызов функции mn//
//    cout << "Минимальное число из ряда: " << mn(7, 84, 23, -11, 63, 8, 52, 1) << endl; //третий вызов функции mn//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void fsum(int n, ...);
//
//void main()
//{
//	setlocale(LC_CTYPE, "Ru");
//	cout << "Сумма  по формуле S = a1 * a2 + a2 * a3 + ..." << endl;
//	fsum(4, 22, 521, 327, 0);
//	fsum(2, 29, 9);
//	fsum(5, 132, 26, 445, 143, 38);
//}
//
//void fsum(int n, ...)
//{
//	int* p = &n;
//	float sum = 0;
//	for (int i = 1; i <= n - 1; i++) {
//		sum += *(p + i) * *(p + i + 1);
//		//sum += *(p + i * sizeof(short)) * *(p + (i + 1) * sizeof(short)); // суммирование всех //параметром посредством перебора с помощью увеличения указателя
//	}
//	cout << "Сумма = " << sum << endl;
//}


#include <iostream>
#include <cstdarg>
using namespace std;

    int fsum(int count, ...) 
    {
    int result = 0;
    va_list args; //создание списка аргументов переменной длинны//
    va_start(args, count); //создание списка аргументов//

    int current = va_arg(args, int); 

    for (int i = 0; i < count - 1; ++i) {

        int next = va_arg(args, int); 

        result += current * next;
        current = next;  
    }

    va_end(args);
    return result;
}

int main() {

    setlocale(LC_CTYPE, "rus");

    int sum1 = fsum(4, 22, 521, 327, 0); //первый вызов функции fsum//
    cout << "Сумма по формуле: " << sum1 << endl;
    int sum2 = fsum(5, 21, 84, 96, 7, 6); //второй вызов функции fsum//
    cout << "Сумма по формуле: " << sum2 << endl;
    int sum3 = fsum(7, 78, 1, 36, 25, 4, 61, 3); //третий вызов функции fsum//
    cout << "Сумма по формуле: " << sum3 << endl;
    return 0;
}






////vtoroe zadanie vtoroi dop(1)//
//#include<iostream>
//#include <cstdarg>
//using namespace std;
//
//void fmin(int count, ...) 
// {
//
//    va_list arg; //создание списка аргументов переменной длинны// 
//    va_start(arg, count); //инициализация va_list, устанавливая начальное положение для доступа к аргументам//
//
//    int min = va_arg(arg, int); //получение первого аргумента и обозначение предположительного минимума//
//
//    for (int i = 1; i < count; i++) {
//        int num = va_arg(arg, int); //получение следующего аргумента//
//
//        if (min > num) {
//            min = num; //если текущий аргумент меньше минимума - минимум обновляется//
//
//        }
//
//    }
//    va_end(arg); //завершение работы со списком аргументов//
//    cout << min << endl;
//}
//
//int main() {
//    setlocale(LC_CTYPE, "rus");
//
//    cout << "Минимальное число из ряда: ";
//    fmin(5, 12, 21, 5, 9, 7); //первый вызов функции minNum//
//    cout << "Минимальное число из ряда: ";
//    fmin(6, 8, 9, 3, 7, 54, 60); //второй вызов функции minNum//
//    cout << "Минимальное число из ряда: ";
//    fmin(6, 8, 0, 12, 54, 1); //третий вызов функции minNum//
//
//}


////vtoroe zadanie tretiy dop(4)//
//#include<iostream>
//#include <cstdarg>
//using namespace std;
//
//void mn(int count, ...)
//{
//
//    va_list arg; //создание списка аргументов переменной длинны//  
//    va_start(arg, count); //инициализация va_list, устанавливая начальное положение для доступа к аргументам//
//
//    int max = va_arg(arg, int); //получение первого аргумента и обозначение предположительного минимума//
//
//    for (int i = 1; i < count; i++) {
//        int num = va_arg(arg, int); //получение следующего аргумента//
//
//        if (max < num) {
//            max = num; //если текущий аргумент больше максимума - минимум обновляется//
//
//        }
//
//    }
//    va_end(arg); //завершение работы со списком аргументов//
//    cout << max << endl;
//}
//
//int main()
//{
//    setlocale(LC_CTYPE, "rus");
//
//    cout << "Максимальное число из ряда: ";
//    mn(5, 12, 13, 5, 9, 7); //первый вызов функции minNum//
//    cout << "Максимальное число из ряда: ";
//    mn(6, 8, 9, 3, 7, 10, 2); //второй вызов функции minNum//
//    cout << "Максимальное число из ряда: ";
//    mn(6, 8, 0, 12, 2, 1, 7); //третий вызов функции minNum//
//
//}




//#include <iostream>
//using namespace std;
//int main()
//{
//	float a = -100, b = 100, e = 0.0001, x;
//	while (abs(a - b) > (2 * e))
//	{
//		x = (a + b) / 2;
//		if ((pow(x, 3) + 2 * x - 1) * (pow(a, 3) + 2 * a - 1) <= 0)
//		{
//			b = x;
//		}
//		else
//			a = x;
//	}
//	cout << "x = " << x << endl;
//	return 0;
//}
//int getRoot1()
//{
//    setlocale(LC_ALL, "rus");
//    double a, b, e, x;
//    cout << "Введите а:";
//    cin >> a;
//    cout << "Введите b:";
//    cin >> b;
//
//    while ((abs(a - b)) > 2 * e)
//    {
//        x = (a + b) / 2;
//
//        if ((pow(x, 3) + x - 4) * (pow(a, 3) + a - 4) <= 0)
//        {
//            b == x;
//        }
//        else a == x;
//    }
//    cout << x;
//}