//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//void add_st();
//void list_of_st();
//void del_st();
//void search_st();
//
//const int MAX_STUD_COUNT = 5;
//const int MAX_LESSONS_COUNT = 5;
//const int MAX_MARKS_COUNT = 5;
//int stud_count = 0;
//
////перечисление для предметов
//enum lessons
//{
//	Algebra = 1, 
//	Chemistry, 
//	Physics, 
//	Russian, 
//	English
//};
//
////структура для хранения данных об ученике
//struct student
//{
//	char fio[50];
//	unsigned studclass : 4;
//	char letter;
//	lessons lesson;
//	int marks[5];
//	double avg;
//};
//
//student stud_list[MAX_STUD_COUNT];
//
//int main()
//{
//	int choice;
//
//	do
//	{
//		cout << "Menu " << endl;
//		cout << "1. Add new student." << endl;
//		cout << "2. Show all students." << endl
//			<< "3. Delete student" << endl
//			<< "4. Searching student." << endl
//			<< "5. Exit" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			add_st();
//			break;
//		case 2:
//			list_of_st();
//			break;
//		case 3:
//			del_st();
//			break;
//		case 4:
//			search_st();
//			break;
//		case 5:
//			cout << "Exit." << endl;
//			break;
//		}
//	} while (choice != 5);
//}
//
////функция для добавления нового ученика
//void add_st()
//{
//	student newStud;
//
//	cout << "Enter full name: ";
//	cin.ignore();
//	gets_s(newStud.fio, 50);
//
//	cout << "Enter grad: ";
//	int cl;
//	cin >> cl;
//	newStud.studclass = static_cast<unsigned>(cl);
//	cin.ignore();
//
//	cout << "Enter letter of grad:";
//	cin >> newStud.letter;
//	cin.ignore();
//
//	int choice;
//	cout << "Enter subject(1 - Algebra, 2 - Chemistry, 3 - Physics, 4 - Russian, 5 - English): ";
//	cin >> choice;
//	switch (choice)
//	{
//	case 1:
//		newStud.lesson = Algebra;
//		break;
//	case 2:
//		newStud.lesson = Chemistry;
//		break;
//	case 3:
//		newStud.lesson = Physics;
//		break;
//	case 4:
//		newStud.lesson = Russian;
//		break;
//	case 5:
//		newStud.lesson = English;
//		break;
//	default:
//		cout << "Error" << endl;
//		return;
//		break;
//	}
//
//	cout << "Enter students rating(max - 5): ";
//	for (int i = 0; i < MAX_MARKS_COUNT; i++)
//	{
//		cin >> newStud.marks[i];
//	}
//
//	int sum = 0;
//
//	for (int i = 0; i < MAX_MARKS_COUNT; i++)
//	{
//		sum += newStud.marks[i];
//	}
//
//	sum = static_cast<double>(sum);
//
//	newStud.avg = sum / static_cast<double>(MAX_MARKS_COUNT);
//
//	stud_list[stud_count] = newStud;
//	stud_count++;
//
//	cout << "Data load success!" << endl << endl;
//}
//
////функция для вывода списка учеников
//void list_of_st()
//{
//	for (int i = 0; i < stud_count; i++)
//	{
//		cout << "Full name: " << stud_list[i].fio << endl;
//
//		cout << "Grad: " << stud_list[i].studclass << stud_list[i].letter << endl;
//
//		cout << "Subject: ";
//		if (stud_list[i].lesson == Algebra)
//		{
//			cout << "Algebra" << endl;
//		}
//		else if (stud_list[i].lesson == Chemistry)
//		{
//			cout << "Chemistry" << endl;
//		}
//		else if (stud_list[i].lesson == Physics)
//		{
//			cout << "Physics" << endl;
//		}
//		else if (stud_list[i].lesson == Russian)
//		{
//			cout << "Russian" << endl;
//		}
//		else if (stud_list[i].lesson == English)
//		{
//			cout << "English" << endl;
//		}
//
//		cout << "Rating: ";
//		for (int k = 0; k < MAX_MARKS_COUNT; k++)
//		{
//			cout << stud_list[i].marks[k] << " ";
//		}
//		cout << endl;
//
//		cout << "Average rating: " << stud_list[i].avg << endl << endl;
//	}
//}
//
////функция для удаления ученика
//void del_st()
//{
//	int choice;
//	cout << "Enter num of student: ";
//	cin >> choice;
//
//	for (int i = choice - 1; i < stud_count - 1; i++)
//	{
//		stud_list[i] = stud_list[i + 1];
//	}
//
//	stud_count--;
//
//	cout << "Data delete success!" << endl << endl;
//}
//
////функция для поиска ученика по ФИО
//void search_st()
//{
//	char buf[50];
//	bool found = false;
//
//	cout << "Enter full name: ";
//	cin.ignore();
//	gets_s(buf, 50);
//
//	for (int i = 0; i < stud_count; i++)
//	{
//		if (strcmp(buf, stud_list[i].fio) == 0)
//		{
//			found = true;
//
//			cout << "Full name: " << stud_list[i].fio << endl;
//
//			cout << "Grad: " << stud_list[i].studclass << stud_list[i].letter << endl;
//
//			cout << "Subject: ";
//			if (stud_list[i].lesson == Algebra)
//			{
//				cout << "Algebra" << endl;
//			}
//			else if (stud_list[i].lesson == Chemistry)
//			{
//				cout << "Биология" << endl;
//			}
//			else if (stud_list[i].lesson == Physics)
//			{
//				cout << "Physics" << endl;
//			}
//			else if (stud_list[i].lesson == Russian)
//			{
//				cout << "Russian" << endl;
//			}
//			else if (stud_list[i].lesson == English)
//			{
//				cout << "English" << endl;
//			}
//
//			cout << "Rating: ";
//			for (int k = 0; k < MAX_MARKS_COUNT; k++)
//			{
//				cout << stud_list[i].marks[k] << " ";
//			}
//			cout << endl;
//
//			cout << "Average rating: " << stud_list[i].avg << endl << endl;
//
//			break;
//		}
//	}
//
//	if (!found)
//	{
//		cout << "Error of finding student." << endl << endl;
//	}
//}


//#include <iostream>
//#include <Windows.h>
//#include <fstream>
//#include <string>
//using namespace std;
//
//// Объявление структуры для хранения данных клиентов
//struct pawnshop
//{
//    union buf
//    {
//        char ch[50];
//        double db;
//        int num;
//    };
//
//    buf fio;    // ФИО
//    buf name;   // Наименование товара
//    buf price;  // Оценочная стоимость товара
//    buf sum;    // Сумма, выданная под залог
//    buf date;   // Дата сдачи
//    buf term;   // Срок хранения
//};
//
//// Константа для максимального количества клиентов
//const int MAX_CLIENTS_COUNT = 5;
//
//// Массив для хранения клиентов
//pawnshop clients_list[MAX_CLIENTS_COUNT];
//
//// Переменная для отслеживания количества клиентов
//int clients_count = 0;
//
//// Прототипы функций
//void add();     // Добавить клиента
//void list();    // Вывести данные клиентов
//void write();   // Записать данные в файл
//void read();    // Прочитать данные из файла
//void search();  // Поиск по ФИО
//
//// Основная функция программы
//int main()
//{
//    // Установка кодировки консоли
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int choice;
//
//    // Главный цикл программы
//    do
//    {
//        // Вывод меню
//        cout << "1 - добавить клиента" << endl
//            << "2 - вывести данные клиентов" << endl
//            << "3 - записать данные в файл" << endl
//            << "4 - прочитать данные из файла" << endl
//            << "5 - поиск по ФИО" << endl
//            << "6 - выход из программы" << endl
//            << "Выберите пункт меню: ";
//
//        // Ввод выбора пользователя
//        cin >> choice;
//
//        // Обработка выбора пользователя
//        switch (choice)
//        {
//        case 1:
//            add();
//            break;
//        case 2:
//            list();
//            break;
//        case 3:
//            write();
//            break;
//        case 4:
//            read();
//            break;
//        case 5:
//            search();
//            break;
//        case 6:
//            cout << "Выход из программы..." << endl;
//            system("pause");
//            break;
//        }
//    }
//} while (choice != 6);
//}
//
//// Функция добавления клиента
//void add()
//{
//    pawnshop newClient;
//
//    // Проверка на максимальное количество клиентов
//    if (clients_count == MAX_CLIENTS_COUNT)
//    {
//        cout << "Вы ввели максимальное кол-во клиентов" << endl;
//        return;
//    }
//
//    // Ввод данных о клиенте
//    cout << "Введите ФИО клиента: ";
//    cin.ignore();
//    gets_s(newClient.fio.ch, 50);
//
//    cout << "Введите наименование товара: ";
//    cin.ignore();
//    gets_s(newClient.name.ch, 50);
//
//    cout << "Введите оценочную стоимость товара в $: ";
//    cin >> newClient.price.db;
//
//    cout << "Введите сумму, выданную под залог в $: ";
//    cin >> newClient.sum.db;
//
//    cout << "Введите дату сдачи в формате ДД.ММ.ГГГГ: ";
//    cin.ignore();
//    gets_s(newClient.date.ch, 50);
//
//    cout << "Введите срок хранения в днях: ";
//    cin >> newClient.term.num;
//
//    // Добавление клиента в массив
//    clients_list[clients_count] = newClient;
//
//    // Увеличение счетчика клиентов
//    clients_count++;
//
//    cout << "Данные успешно записаны!" << endl << endl;
//}
//
//// Функция вывода данных всех клиентов
//void list()
//{
//    for (int i = 0; i < clients_count; i++)
//    {
//        cout << "ФИО: " << clients_list[i].fio.ch << endl;
//        cout << "Наименование товара: " << clients_list[i].name.ch << endl;
//        cout << "Оценочная стоимость товара: " << clients_list[i].price.db << "$" << endl;
//        cout << "Сумма, выданная под залог: " << clients_list[i].sum.db << "$" << endl;
//        cout << "Дата сдачи: " << clients_list[i].date.ch << endl;
//        cout << "Срок хранения: " << clients_list[i].term.num << " дней" << endl << endl;
//    }
//}
//
//// Функция записи данных всех клиентов в файл
//void write()
//{
//    ofstream fin("file.txt");
//
//    // Проверка открытия файла
//    if (!fin.is_open())
//    {
//        cout << "Ошибка открытия файла" << endl << endl;
//        return;
//    }
//
//    // Запись данных в файл
//    for (int i = 0; i < clients_count; i++)
//    {
//        fin << "ФИО: " << clients_list[i].fio.ch << endl;
//        fin << "Наименование товара: " << clients_list[i].name.ch << endl;
//        fin << "Оценочная стоимость товара: " << clients_list[i].price.db << "$" << endl;
//        fin << "Сумма, выданная под залог: " << clients_list[i].sum.db << "$" << endl;
//        fin << "Дата сдачи: " << clients_list[i].date.ch << endl;
//        fin << "Срок хранения: " << clients_list[i].term.num << " дней" << endl << endl;
//    }
//
//    // Закрытие файла
//    fin.close();
//}
//
//// Функция чтения данных из файла и вывода на экран
//void read()
//{
//    ifstream fout("file.txt");
//    string line;
//
//    // Проверка открытия файла
//    if (!fout.is_open())
//    {
//        cout << "Ошибка открытия файла" << endl << endl;
//        return;
//    }
//
//    // Чтение данных из файла и вывод на экран
//    while (getline(fout, line))
//    {
//        cout << line << endl;
//    }
//
//    cout << endl;
//
//    // Закрытие файла
//    fout.close();
//}
//
//// Функция поиска клиента по ФИО
//void search()
//{
//    char buffer[50];
//    bool found = false;
//
//    // Ввод ФИО для поиска
//    cout << "Введите ФИО: ";
//    cin.ignore();
//    gets_s(buffer, 50);
//
//    // Поиск клиента по введенному ФИО
//    for (int i = 0; i < clients_count; i++)
//    {
//        if (strcmp(clients_list[i].fio.ch, buffer) == 0)
//        {
//            found = true;
//            cout << "ФИО: " << clients_list[i].fio.ch << endl;
//            cout << "Наименование товара: " << clients_list[i].name.ch << endl;
//            cout << "Оценочная стоимость товара: " << clients_list[i].price.db << "$" << endl;
//            cout << "Сумма, выданная под залог: " << clients_list[i].sum.db << "$" << endl;
//            cout << "Дата сдачи: " << clients_list[i].date.ch << endl;
//            cout << "Срок хранения: " << clients_list[i].term.num << " дней" << endl << endl;
//        }
//    }
//
//    // Вывод сообщения, если клиент не найден
//    if (!found)
//    {
//        cout << "Клиент с такими ФИО не найден" << endl << endl;
//    }
//}



//#include <iostream> 
//#include <cstdlib> 
//#include <string> 
//using namespace std; 
//enum JoJob 
//{ 
// hammerMan=1,Secretary,Engineer//использвание перечисления 
//}job[100]; 
//struct humanResources 
//{ 
// string initials; 
// string education; 
// string work; 
// string salary; 
// int  year: 12;//Ограничение в 8 байт для года начала работы 
// int stage; 
//}a[100]; 
// 
//int counter = 0; 
// 
//void Enter(int count) 
//{ 
// for (int i = 0; i < count; i++) 
// { 
//  //Последовательный ввод всех данных каждого работника 
//  cout << "Initials:"; 
//  getline(cin, a[i].initials); 
//  getline(cin, a[i].initials); 
//  cout << endl; 
// 
//  cout << "Education:"; 
//  getline(cin, a[i].education); 
//  cout << endl; 
// 
//  cout << "Work:"; 
//  getline(cin, a[i].work); 
//  cout << endl; 
// 
//  cout << "Salary:"; 
//  getline(cin, a[i].salary); 
//  cout << endl; 
//  int year,Job; 
//  cout << "Year:"; 
//  cin >> year;  
//  a[i].year = year; 
//  a[i].stage = 2024 - year; 
// 
//  cout << "Enter job:" << endl << "1.HammerMan" << endl << "2.Secretary" << endl << "3.Engineer"<<endl; 
//  cin >> Job; 
//   job[i]=static_cast<JoJob>(Job); 
// } 
// 
//} 
//void Info(int count) 
//{ 
// 
//  
// for (int i = 0; i < count; i++) 
// { 
//  cout << "Initials:"; 
//  cout <<a[i].initials<< endl; 
// 
//  cout << "Education:"; 
//  cout << a[i].education<<endl; 
// 
//  cout << "Work:"; 
//  cout << a[i].work<<endl; 
// 
//  cout << "Salary:"; 
//  cout <<a[i].salary<< endl; 
// 
//  cout << "Year:"; 
//  cout << a[i].year << endl; 
//  cout << "Work Years:"; 
//  cout << a[i].stage << endl; 
//  cout << "Job:"; 
//  if (job[i] == 1)cout << " Hammerman" << endl; 
//  if (job[i] == 2)cout << " Secretary" << endl; 
//  if (job[i] == 3)cout << " Engineer" << endl; 
// } 
//} 
// 
//void Search(int count) 
//{ 
// cout << endl << "Enter number of work years:"; 
//  int workYears; 
//  cin >> workYears; 
//  for (int i = 0; i < count; i++) 
//  { 
//   if (a[i].stage == workYears) 
//   { 
//    cout << "Initials:"; 
//    cout << a[i].initials << endl; 
// 
//    cout << "Education:"; 
//    cout << a[i].education << endl; 
// 
//    cout << "Work:"; 
//    cout << a[i].work << endl; 
// 
//    cout << "Salary:"; 
//    cout << a[i].salary << endl; 
// 
//    cout << "Year:"; 
//    cout << a[i].year << endl; 
//    cout << "Work Years:"; 
//    cout << a[i].stage << endl; 
//    cout << "Job:"; 
//    if (job[i] == 1)cout << " Hammerman" << endl; 
//    if (job[i] == 2)cout << " Secretary" << endl; 
//    if (job[i] == 3)cout << " Engineer" << endl; 
//   } 
//  } 
// } 
//  
// void Delete(int count) 
// { 
//  int del; 
//    cout << endl << "Worker number:"; 
//    cin >> del; 
//    for (int i = del - 1; i < count - 1; i++) 
//    { 
//     a[i] = a[i + 1]; 
//    } 
//    cout << endl << "Deleted succesfully" << endl; 
//    
// } 
//  void main() 
//  { 
//   int count,choice; 
//   cout << "Number of workers:"; 
//   cin >> count; 
//   Enter(count); 
//   while (true) 
//   { 
//    cout << endl << endl << endl; 
//    cout << "1.Info" << endl << "2.Search" << endl << "3.Delete" << endl; 
//    cin >> choice; 
//    switch (choice) 
//    { 
//    case 1: 
//    { 
//     Info(count); 
//     break; 
//    } 
//    case 2: 
//    { 
//     Search(count); 
//     break; 
//    } 
//    case 3: 
//    { 
//     Delete(count); 
//     count -= 1; 
//    } 
//    } 
//  
//  
//   } 
//  } 
 
 
Кирилл Дмитроченко, [19.03.2024 23:41]
/////////////////////////////////////////////////////////////////////////////////// 
//Вариант 1 
//#include <iostream> 
//#include <cstdlib> 
//#include <string> 
//using namespace std; 
//enum JoJob 
//{ 
// hammerMan=1,Secretary,Engineer//использвание перечисления 
//}job[100]; 
//struct humanResources 
//{ 
// string initials; 
// string education; 
// string work; 
// string salary; 
// int  year: 12;//Ограничение в 8 байт для года начала работы 
// int stage; 
//}a[100]; 
// 
//int counter = 0; 
// 
//void Enter(int count) 
//{ 
// for (int i = 0; i < count; i++) 
// { 
//  cout << endl << endl << "Enter data:" << endl << endl << endl; 
//  Последовательный ввод всех данных каждого работника 
//  cout << "Initials:"; 
//  getline(cin, a[i].initials); 
//  getline(cin, a[i].initials); 
//  cout << endl; 
// 
//  cout << "Education:"; 
//  getline(cin, a[i].education); 
//  cout << endl; 
// 
//  cout << "Work:"; 
//  getline(cin, a[i].work); 
//  cout << endl; 
// 
//  cout << "Salary:"; 
//  getline(cin, a[i].salary); 
//  cout << endl; 
//  int year,Job; 
//  cout << "Year:"; 
//  cin >> year;  
//  a[i].year = year; 
//  a[i].stage = 2024 - year; 
// 
//  cout << "Enter job:" << endl << "1.HammerMan" << endl << "2.Secretary" << endl << "3.Engineer"<<endl; 
//  cin >> Job; 
//   job[i]=static_cast<JoJob>(Job); 
// } 
// 
//} 
//void Info(int count) 
//{ 
// 
//  
// for (int i = 0; i < count; i++) 
// { 
//  cout << endl << "--------------------INFO----------------"<<endl; 
//  cout << "Initials:"; 
//  cout <<a[i].initials<< endl; 
// 
//  cout << "Education:"; 
//  cout << a[i].education<<endl; 
// 
//  cout << "Work:"; 
//  cout << a[i].work<<endl; 
// 
//  cout << "Salary:"; 
//  cout <<a[i].salary<< endl; 
// 
//  cout << "Year:"; 
//  cout << a[i].year << endl; 
//  cout << "Work Years:"; 
//  cout << a[i].stage << endl; 
//  cout << "Job:"; 
//  if (job[i] == 1)cout << " Hammerman" << endl; 
//  if (job[i] == 2)cout << " Secretary" << endl; 
//  if (job[i] == 3)cout << " Engineer" << endl; 
// } 
//} 
// 
//void Search(int count) 
//{ 
// cout << endl << "Enter number of work years:"; 
//  int workYears; 
//  cin >> workYears; 
//  for (int i = 0; i < count; i++) 
//  { 
//   if (a[i].stage == workYears) 
//   { 
//    cout << endl << endl << "------------------------INFO-----------------------" << endl; 
//    cout << "Initials:"; 
//    cout << a[i].initials << endl; 
// 
//    cout << "Education:"; 
//    cout << a[i].education << endl; 
// 
//    cout << "Work:"; 
//    cout << a[i].work << endl; 
// 
//    cout << "Salary:"; 
//    cout << a[i].salary << endl; 
// 
//    cout << "Year:"; 
//    cout << a[i].year << endl; 
//    cout << "Work Years:"; 
//    cout << a[i].stage << endl; 
//    cout << "Job:"; 
//    if (job[i] == 1)cout << " Hammerman" << endl; 
//    if (job[i] == 2)cout << " Secretary" << endl; 
//    if (job[i] == 3)cout << " Engineer" << endl; 
//   } 
//  } 
// } 
//  
// void Delete(int count) 
// { 
//  int del; 
//    cout << endl << "Worker number:"; 
//    cin >> del; 
//    for (int i = del - 1; i < count - 1; i++) 
//    { 
//     a[i] = a[i + 1]; 
//    } 
//    cout << endl << "Deleted succesfully" << endl; 
//    
// } 
//  void main() 
//  { 
//   int count,choice; 
//   cout << "Number of workers:"; 
//   cin >> count; 
//   Enter(count); 
//   while (true) 
//   { 
//    cout << endl << endl << endl; 
//    cout << "1.Info" << endl << "2.Search" << endl << "3.Delete" << endl; 
//    cin >> choice; 
//    switch (choice) 
//    { 
//    case 1: 
//    { 
//     Info(count); 
//     break; 
//    } 
//    case 2: 
//    { 
//     Search(count); 
//     break; 
//    } 
//    case 3: 
//    { 
//     Delete(count); 
//     count -= 1; 
//    } 
//    } 
//  
//  
//   } 
//  } 
// 
// 
// 


#include <iostream> 
#include <cstdlib> 
#include <string> 
using namespace std; 
 
union Exam 
{ 
 char exam[50]; 
}; 
 
struct lector 
{ 
 Exam exam; 
 char initials[50]; 
 char  date[50]; 
 string surname; 
}; 
 
lector
a[1000];
 
 
void Enter(int count) 
{ 
 
 for (int i = 0; i < count; i++) 
 { 
  int j = 0; 
  cout << endl << endl << "Enter data:" << endl << endl << endl; 
  //Последовательный ввод всех данных каждого преподавателя 
  cout << "Initials:"; 
  if (i==0)gets_s(a[i].initials, 50); 
  gets_s(a[i].initials,50); 
 
  cout << "Exam:"; 
  gets_s(a[i].exam.exam, 50); 
  cout << "Date:"; 
  gets_s(a[i].date, 50); 
  while (a[i].initials[j] != ' ') 
     { 
      a[i].surname += a[i].initials[j]; 
      j += 1; 
     } 
 } 
 
} 
void Info(int count) 
{ 
 for (int i = 0; i < count; i++) 
 { 
  cout << "Initials:"<<a[i].initials<<endl; 
  cout << "Exam:"<<a[i].exam.exam<<endl; 
  cout << "Date:"<<a[i].date<<endl; 
 } 
} 
 
void Search(int count) 
{ 
 cout << endl << "Enter Surname:"; 
 string Surname; 
 cin >> Surname; 
 
 for (int i = 0; i < count; i++) 
 { 
  if (a[i].surname ==Surname) 
  { 
   cout << "Initials:" << a[i].initials << endl; 
   cout << "Exam:" << a[i].exam.exam << endl; 
   cout << "Date:" << a[i].date << endl; 
  } 
 } 
} 
 
 void main() 
 { 
  int count,choice; 
  cout << "Number of Exams:"; 
  cin >> count; 
  Enter(count); 
  while (true) 
  { 
   cout << endl << endl << endl; 
   cout << "1.Info" << endl << "2.Search" << endl; 
   cin >> choice; 
   switch (choice) 
   { 
   case 1: 
   { 
    Info(count); 
    break; 
   } 
   case 2: 
   { 
    Search(count); 
   } 
   } 
 
 
  } 
 } 
