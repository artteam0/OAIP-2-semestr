//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main() {
//	ifstream file1("FILE1.txt"); //открываем первый файл для чтения//
//	ofstream file2("FILE2.txt"); //открываем второй файл для записи//
//	char buffer[255];
//
//	if (!file1.is_open()) { //проверка открытия файла//
//		cout << "error of opening first file" << endl;
//		return -1;
//	}
//
//	if (!file2.is_open()) {
//		cout << "error of opening second file" << endl;
//		return -1;
//	}
//
//	while (!file1.eof()) {
//		file1.getline(buffer, 255);
//		if (buffer[0] == 'A') {
//			file2 << buffer << endl;
//		}
//		if (buffer[0] == 'a') {
//			file2 << buffer << endl;
//		}
//	}
//	file1.close();
//	file2.close();
//
//	ifstream file4("FILE2.txt");
//	int countOfWords = 0;
//
//	while (!file4.eof()) {
//		file4.getline(buffer, 255);
//		for (short i = 0; i != strlen(buffer) + 1; i++) {
//			if (buffer[i] == ' ') {
//				countOfWords++;
//			}
//		}
//		countOfWords++;
//	}
//
//	cout << "count of words: " << countOfWords - 1 << endl;
//
//	return 0;
//}
//


#include<iostream>
#include<fstream>
#include<cstring> // Для использования функции strlen
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    ofstream file1_write("FILE1.txt");
    ifstream file1_read("FILE1.txt"); // чтение из файла FILE1.txt 
    char buffer[250], word[250];
    string buf;

    cout << "Введите строку, состоящую из цифр и слов, разделенных пробелами" << endl;
    cin.getline(buffer, 250); // Используем cin для чтения строки
    file1_write << buffer;
    file1_write.close();

    file1_read.getline(buffer, 250);
    file1_read.close();
    int count = 0, g = 0, max_count = 0, word_count = 0, number_word;
    for (int i = 0; i < strlen(buffer); i++) {

        word[g] = buffer[i];
        count++;
        g++;

        if (buffer[i] == ' ') {
            count--; //Убираем из счетчика пробел
            word_count++;
            if (count > max_count) { // Нахождение кол-ва символов длиннейшего слова и его самого
                max_count = count;
                buf = word;
                number_word = word_count;
            }

            count = 0;
            memset(word, 0, sizeof word); // Очищаем массив word
            g = 0; // Сбрасываем индекс для нового слова
        }

    }

    cout << "Кол-во символов в самом длинном слове: " << max_count << endl;
    cout << "Само это слово: " << buf << endl;
    return 0;
}
