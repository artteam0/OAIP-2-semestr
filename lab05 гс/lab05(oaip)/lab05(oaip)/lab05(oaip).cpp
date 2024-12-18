//#include <iostream>
//#include <string>
//using namespace std;
//
////объявление функций//
//void personal_library();
//void output();
//void delete_info();
//void searching_for();
//
//int main()
//{
//	int choice;
//
//	do {
//		cout << "Menu  " << endl;
//		cout << "1. Enter information about book." << endl;
//		cout << "2. Information output." << endl;
//		cout << "3. Delete." << endl;
//		cout << "4. Searching for." << endl;
//		cout << "5. Exit." << endl;
//		cin >> choice;
//
//		switch (choice) {
//		case 1: personal_library();
//			break;
//		case 2: output();
//			break;
//		case 3: delete_info();
//			break;
//		case 4: searching_for();
//			break;
//		case 5:
//			cout << "Exit." << endl;
//			break;
//		default:
//			cout << "Error" << endl;
//			break;
//		}
//	} while (choice != 5);
//
//	return 0;
//}
//
////добавление перечисления//
//enum origin
//{
//	purchase = 1,
//	theft,
//	gift
//};
//
////добавление структуры//
//struct INFO
//{
//	string author;
//	string title;
//	string publisher;
//	string year;
//	string library_section;
//	origin origin;
//	string availability;
//};
//
//const int maxLibrary = 100;
//int libraryCount = 1;
//INFO library[maxLibrary];
//
////функция для доавления библиотеки//
//void personal_library()
//{
//
//	for (int i = 0; i < libraryCount; i++) {
//
//		cout << "Enter the author: ";
//		cin >> library[i].author;
//
//		cout << "Enter the title: ";
//		cin >> library[i].title;
//
//		cout << "Enter the publisher: ";
//		cin >> library[i].publisher;
//
//		cout << "Enter the year: ";
//		cin >> library[i].year;
//
//		cout << "Enter the library section (as like special literature, hobbies, home economics, fiction, etc.): " << endl;
//		cin >> library[i].library_section;
//
//		int choice;
//		cout << "Enter origin (1 - purchase; 2 - theft; 3 -  gift;): ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			library[i].origin = purchase;
//			break;
//		case 2:
//			library[i].origin = theft;
//			break;
//		case 3:
//			library[i].origin = gift;
//			break;
//		default:
//			cout << "Error." << endl;
//			break;
//		}
//
//		cout << "Enter availability: ";
//		cin >> library[i].availability;
//
//		cout << "Adding successfully!" << endl;
//	}
//}
//
////функция для вывода данных о библиотеке//
//void output()
//{
//	for (int i = 0; i < libraryCount; i++) {
//
//		cout << "Library " << libraryCount << ": " << endl;
//		cout << "Author: ";
//		cout << library[i].author << endl;
//		cout << "Title: ";
//		cout << library[i].title << endl;
//		cout << "Publisher: ";
//		cout << library[i].publisher << endl;
//		cout << "Year: ";
//		cout << library[i].year << endl;
//		cout << "Library section: ";
//		cout << library[i].library_section << endl;
//
//		cout << "Origin: ";
//		if (library[i].origin == purchase)
//		{
//			cout << "Purchase" << endl;
//		}
//		else if (library[i].origin == theft)
//		{
//			cout << "Theft" << endl;
//		}
//		else if (library[i].origin == gift)
//		{
//			cout << "Gift" << endl;
//		}
//
//		cout << "Availability: ";
//		cout << library[i].availability << endl;
//	}
//}
//
////функция для удаление библиотеки
//void delete_info()
//{
//	int delete_info;
//	cout << endl << "Enter number of client: ";
//	cin >> delete_info;
//
//	for (int i = delete_info - 1; i < libraryCount - 1; i++)
//	{
//		library[i] = library[i + 1];
//	}
//
//	cout << endl << "Delete run success!" << endl;
//	libraryCount -= 1;
//	cout << endl;
//}
//
////функция для поиска библиотеки по году//
//void searching_for()
//{
//	string year;
//	cout << "Enter the year: ";
//	cin >> year;
//
//	bool found = false;
//	cout << "Results of the searching for " << year << ":" << endl;
//
//	for (int i = 0; i < libraryCount; i++) {
//
//		if (library[i].year == year) {
//
//			found = true;
//			cout << "Author: " << library[i].author << endl;
//			cout << "Title: " << library[i].title << endl;
//			cout << "Publisher: " << library[i].publisher << endl;
//			cout << "Library section: " << library[i].library_section << endl;
//
//			cout << "Origin: ";
//			if (library[i].origin == purchase)
//			{
//				cout << "Purchase" << endl;
//			}
//			else if (library[i].origin == theft)
//			{
//				cout << "Theft" << endl;
//			}
//			else if (library[i].origin == gift)
//			{
//				cout << "Gift" << endl;
//			}
//
//			cout << "Availability: " << library[i].availability << endl;
//		}
//	}
//	if (!found) {
//		cout << "Searching for " << year << " failed." << endl;
//	}
//}



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//объявление функций//
void personal_library();
void output();
void delete_info();
void searching_for();
void write_to_file();
void read_from_file();

int main()
{
	int choice;

	do {
		cout << "Menu  " << endl;
		cout << "1. Enter information about book." << endl;
		cout << "2. Information output." << endl;
		cout << "3. Delete." << endl;
		cout << "4. Searching for." << endl;
		cout << "5. Write to file." << endl;
		cout << "6. Read from file." << endl;
		cout << "7. Exit." << endl;
		cin >> choice;

		switch (choice) {
		case 1: personal_library();
			break;
		case 2: output();
			break;
		case 3: delete_info();
			break;
		case 4: searching_for();
			break;
		case 5:
			write_to_file();
			break;
		case 6:
			read_from_file();
			break;
		case 7:
			cout << "Exit" << endl;
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	} while (choice != 7);

	return 0;
}

//добавление перечисления//
union Library 
{
	char author[10];
	char title[7];
	char publisher[15];
	char year[4];
	char library_section[18];
	char origin[100];
	char availability[100];
};

//добавление структуры//
struct INFO
{
	Library author;
	Library title;
	Library publisher;
	Library year;
	Library library_section;
	Library origin;
	Library availability;
};

const int maxLibrary = 100;
int libraryCount = 1;
INFO library[maxLibrary];

//функция для доавления библиотеки//
void personal_library()
{

	for (int i = 0; i < libraryCount; i++) {

		cout << "Enter the author: ";
		cin >> library[i].author.author;

		cout << "Enter the title: ";
		cin >> library[i].title.title;

		cout << "Enter the publisher: ";
		cin >> library[i].publisher.publisher;

		cout << "Enter the year: ";
		cin >> library[i].year.year;

		cout << "Enter the library section (as like special literature, hobbies, home economics, fiction, etc.)" << endl;
		cin >> library[i].library_section.library_section;

		cout << "Enter origin (purchase; theft; gift;): ";
		cin >> library[i].origin.origin;

		cout << "Enter availability: ";
		cin >> library[i].availability.availability;

		cout << "Adding successfully!" << endl;
	}
}

//функция для вывода данных о библиотеке//
void output()
{
	for (int i = 0; i < libraryCount; i++) {

		cout << "Library " << libraryCount << ": " << endl;
		cout << "Author: ";
		cout << library[i].author.author << endl;
		cout << "Title: ";
		cout << library[i].title.title << endl;
		cout << "Publisher: ";
		cout << library[i].publisher.publisher << endl;
		cout << "Year: ";
		cout << library[i].year.year << endl;
		cout << "Library section: ";
		cout << library[i].library_section.library_section << endl;
		cout << "Origin: ";
		cout << library[i].origin.origin << endl;
		cout << "Availability: ";
		cout << library[i].availability.availability << endl;
	}
}

//функция для удаление библиотеки
void delete_info()
{
	int delete_info;
	cout << endl << "Enter number of client: ";
	cin >> delete_info;

	for (int i = delete_info - 1; i < libraryCount - 1; i++)
	{
		library[i] = library[i + 1];
	}

	cout << endl << "Delete run success!" << endl;
	libraryCount -= 1;
	cout << endl;
}

//функция для поиска библиотеки по году//
void searching_for()
{
	string author;
	cout << "Enter thr year: ";
	cin >> author;

	bool found = false;
	cout << "Results of the searching for " << author << ":" << endl;

	for (int i = 0; i < libraryCount; i++) {

		if (library[i].year.year == author) {

			found = true;
			cout << "Author: " << library[i].author.author << endl;
			cout << "Title: " << library[i].title.title << endl;
			cout << "Publisher: " << library[i].publisher.publisher << endl;
			cout << "Library section: " << library[i].library_section.library_section << endl;
			cout << "Origin: " << library[i].origin.origin << endl;
			cout << "Availability: " << library[i].availability.availability << endl;
		}
	}
	if (!found) {
		cout << "Searching for " << author << " failed." << endl;
	}
}

//функция для записи в файл//
void write_to_file()
{
	ofstream write_to_file("file.txt");

	if (!write_to_file.is_open())
	{
		cout << "Error of opening file." << endl;
		return;
	}

	for (int i = 0; i < libraryCount; i++)
	{
		//запись данных в файл//
		write_to_file << "Library " << libraryCount << ": " << endl;
		write_to_file << "Author: " << library[i].author.author << endl;
		write_to_file << "Title: " << library[i].title.title << endl;
		write_to_file << "Publisher: " << library[i].publisher.publisher << endl;
		write_to_file << "Origin: " << library[i].origin.origin << endl;
		write_to_file << "Year: " << library[i].year.year << endl;
		write_to_file << "Library section: " << library[i].library_section.library_section << endl;
		write_to_file << "Availability: " << library[i].availability.availability << endl << endl;
	}

	cout << "Writing run success!" << endl;
	write_to_file.close();

}

//функция для чтения из файла//
void read_from_file()
{
	ifstream read_from_file("file.txt");
	string line;

	while (getline(read_from_file, line))
	{
		//вывод данных из файла//
		cout << line << endl;
	}

	read_from_file.close();
}