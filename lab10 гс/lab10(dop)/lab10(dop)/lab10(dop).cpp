//#include <iostream>	
//#include <fstream> /
//using namespace std;
//
//int i, c, b = 0; 
//
////функция заполняет массив array значениями от 1 до x и возвращает количество элементов//
//int filling(int x, int max, int* array)
//{
//    //рекурсивная функция, заполняющая массив значениями от 1 до x//
//    if (i <= x) {
//        array[c] = i; 
//        ++i; 
//        c++; //увеличиваем счетчик элементов//
//        filling(x, max, array); //вызов функции для след. элемента//
//    }
//    else {
//        return c; 
//    }
//}
//
//int main()
//{
//    int a;
//    cout << "Enter value: ";
//    cin >> a; 
//
//    int* arr = new int[a]; //выделение памяти под массив arr размером a//
//    ofstream out("file.txt"); 
//
//    int counter = 1; //начальное значение счетчика для функции//
//    int count = filling(a, counter, arr); 
//
//    for (int i = 0; i < count; i++) {
//        cout << arr[i] << endl;
//    }
//
//    for (int i = 0; i <= a; i++) { //запись//
//        out << arr[i] << " ";
//    }
//
//    delete[] arr;
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//const int MAX_COUNTRIES = 4; //кол-во стран//
//
//int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES] = { //матрица смежности//
//    {0, 1, 0, 1},
//    {1, 0, 1, 0},
//    {0, 1, 0, 1},
//    {1, 0, 1, 0}
//};
//
//int groups[MAX_COUNTRIES];
//
////рекурсивная функция//
//void dfs(int node, int group) {
//    groups[node] = group;
//    for (int i = 0; i < MAX_COUNTRIES; ++i) {
//        if (adjacencyMatrix[node][i] == 1 && groups[i] == -1) {
//            dfs(i, 1 - group);
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_CTYPE, "rus");
//
//    for (int i = 0; i < MAX_COUNTRIES; ++i) {     //инициализация массива//
//        groups[i] = -1;
//    }
//
//    for (int i = 0; i < MAX_COUNTRIES; ++i) {     //разделение стран на группы//
//        if (groups[i] == -1) {
//            dfs(i, 0);
//        }
//    }
//
//    cout << "Groups of countries: " << endl;
//    for (int i = 0; i < MAX_COUNTRIES; ++i) {
//        if (groups[i] == 0) {
//            cout << "Country " << i + 1 << ": Group 1" << endl;
//        }
//        else {
//            cout << "Country " << i + 1 << ": Group 2" << endl;
//        }
//    }
//
//    return 0;
//}


#include <iostream> 
using namespace std; 

const int n = 8;
int a[n];

//функция для перестановки элементов массива//
void perestanovka(int k) {
    int i, j, t, p;

    for (i = 0; i < n - k; i++) { //перебор всех возможных перестановок//
        if (k < n - 2)
            perestanovka(k + 1); //рекурсивный вызов функции для след. элемента//
        else {
            for (p = 0; p < n; p++) cout << " " << a[p]; 
            cout << endl;
        }

        t = a[k]; 
        for (j = k + 1; j < n; j++) a[j - 1] = a[j]; //cдвиг элементов массива влево//
        a[j - 1] = t; //перемещаем сохраненный элемент на правый край массива//
    }
}

int main(void)
{
    int i;
    for (i = 0; i < n; i++) a[i] = i + 1;
    perestanovka(0);

    return 0;
}
