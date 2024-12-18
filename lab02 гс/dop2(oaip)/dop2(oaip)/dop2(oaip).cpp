#include <stdio.h>
#include <iostream>

int main()
{
    FILE* f, * f2;

    fopen_s(&f, "f.txt", "r"); //открытие первого файла для чтения//

    if (f == NULL) { //проверка открытия файла//
        printf("error of opening first file\n"); 
        return -1;
    }

    fopen_s(&f2, "f2.txt", "w"); //открытие второго файла для записи// 

    if (f2 == NULL) //проверка открытия файла//
    {
        printf("error of opening second file\n"); 
        fclose(f); //закрытие файла//
    }

    int num;

    while (fscanf_s(f, "%d", &num) != EOF) //чтение файла до его конца//
    {
        if (num > 0) { //проверка является ли число положительным//
            fprintf(f2, "%d ", num); //запись во второй файл//
        }
    }

    printf("program run success\n");

    fclose(f); //закрытие файлов//
    fclose(f2); 
}



#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    FILE* f, * g;

    fopen_s(&f, "f.txt", "r"); //открытие первого файла для чтения//

    if (f == NULL) { //проверка открытия файла//
        printf("error of opening first file\n"); 
        return -1;
    }

    fopen_s(&g, "g.txt", "w"); //открытие файла для записи//

    if (g == NULL) {
        printf("error of creating second file\n");
        fclose(f); //закрытие первого файла//
    }

    int inputNum, num;
    cout << "enter num: "; cin >> inputNum;

    while (fscanf_s(f, "%d", &num) != EOF) //чтение файла до его конца//
    {
        if (num > inputNum) { 
            fprintf(g, "%d ", num); //запись во второй файл//
        }
    }

    printf("program run success\n");

    fclose(f); //закрытие файлов//
    fclose(g); 
}



#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
        // Объявляем указатели на файлы и имена файлов
        FILE* fileA, * fileB;
        char filenameA[] = "fileA.txt";
        char filenameB[] = "fileB.txt";

        // Объявляем массив для хранения уникальных чисел и другие переменные
        int uniqueSet[256];
        int size = 0;
        int num;

        // Открываем файл fileA для чтения
        if (fopen_s(&fileA, filenameA, "r") != 0) {
            printf("Ошибка при открытии файла fileA\n");
            return 1;
        }

        // Считываем числа из файла fileA и добавляем уникальные числа в массив
        while (fscanf_s(fileA, "%d", &num) == 1) {
            int found = 0;
            for (int i = 0; i < size; i++) {
                if (uniqueSet[i] == num) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                uniqueSet[size] = num;
                size++;
            }
        }

        fclose(fileA);

        // Открываем файл fileB для записи
        if (fopen_s(&fileB, filenameB, "w") != 0) {
            printf("Ошибка при открытии файла fileB\n");
            return 1;
        }

        // Записываем уникальные числа из массива в файл fileB
        for (int i = 0; i < size; i++) {
            fprintf(fileB, "%d ", uniqueSet[i]);
        }

        printf("Уникальные числа из файла fileA записаны в файл fileB\n");

        fclose(fileB);

        return 0;
    }



#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	FILE* f1, * f2, * f3;

	fopen_s(&f1, "f1.txt", "r");    // проверка на ошибку при открытии файла, fopen_s должно возвращать 0
	if (f1 == NULL) {
		printf("error of opening first file");
		return -1;
	}

	fopen_s(&f2, "f2.txt", "r");
	if (f2 == NULL) {
		printf("error of opening second file");
		return -1;
	}

	double matrix1[100][100];
	double matrix2[100][100];
	double matrix3[100][100];
	double num;
	int numColumns;
	int numLines = 0;

	fscanf_s(f1, "%d", &numColumns);  // считывание первого элемента матрицы

	while (fscanf_s(f1, "%d", &num) != EOF) {   // подсчёт количества строк матрицы в файле
		if (fgetc(f1) == '\n') {
			numLines++;
		}
	}

	for (int i = 0; i < numLines; i++) {       // считывание элементов матрицы и запись в matrix1
		for (int j = 0; j < numColumns; j++) {
			fscanf_s(f1, "%lf", &matrix1[i][j]);
		}
	}

	for (int i = 0; i < numLines; i++) {       // считывание элементов матрицы и запись в matrix2
		for (int j = 0; j < numColumns; j++) {
			fscanf_s(f2, "%lf", &matrix2[i][j]);
		}
	}

	for (int i = 0; i < numLines; i++) {       // нахождение матрицы суммы
		for (int j = 0; j < numColumns; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	fopen_s(&f3, "f3.txt", "w");
	if (f3 == NULL) {
		printf("error of opening second file");
		return -1;
	}
	for (int i = 0; i < numLines; i++) {        // запись в файл матрицы суммы
		for (int j = 0; j < numColumns; j++) {
			fprintf_s(f3, "%.1lf ", matrix3[i][j]);
		}
		fprintf_s(f3, "%c", '\n');
	}



	fclose(f1); //закрытие файлов//
	fclose(f2);
	fclose(f3);  

	printf("program run success\n");

	return 0;
}

#include<stdio.h>
#include<string>	
#include<iostream>
using namespace std;

void main()
{
	int k;
	string gg;

	char row[50];
	FILE* f, * f2;

	fopen_s(&f, "f.txt", "r"); //открытие файла только для чтения//
	cout << "num of srt: ";
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		fgets(row, 50, f); //пропуск строк до нужной//
	}
	fgets(row, 50, f);


	fopen_s(&f2, "f2.txt", "w"); //открытие файла только для записи//
	fprintf(f2, "%s", row);


	fclose(f2);
	fclose(f);

	printf("program run success\n");
}



#include<iostream>
#include<stdio.h>
using namespace std;

void main()
{

#include<stdio.h>
	setlocale(LC_ALL, "rus");
	int A[100], B[100], C[100], i, j, size, count, num, min;
	char row[50];
	FILE* file1, * file2, * file3, * file4;
	//Обьявление входных файлов
	fopen_s(&file1, "NameA.bin", "r");
	fopen_s(&file2, "NameB.bin", "r");
	fopen_s(&file3, "NameC.bin", "r");


	fseek(file1, 0L, SEEK_END);
	size = ftell(file1);
	fseek(file1, 0L, SEEK_SET);


	fgets(row, size, file1);
	count = 0;
	for (i = 0; i < size; i++)
	{
		if (row[i] == ' ') { count += 1; }
	}
	count += 1;
	cout << count << endl;
	fseek(file1, 0L, SEEK_SET);
	for (i = 0; i < count; i++)
	{
		fscanf_s(file1, "%d", &num);
		A[i] = num;
	}

	for (i = 0; i < count; i++)
	{
		fscanf_s(file2, "%d", &num);
		B[i] = num;
	}
	for (i = 0; i < count; i++)
	{
		fscanf_s(file3, "%d", &num);
		C[i] = num;
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);

	fopen_s(&file4, "NameD.bin", "w+");

	for (i = 0; i < count; i++)
	{
		min = A[i];
		if (B[i] < min) min = B[i];
		if (C[i] < min) min = C[i];
		fprintf(file4, "%d ", min);
	}
	fclose(file4);
}



#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    FILE* fileA, * fileB;
    fopen_s(&fileA, "fileA.txt", "r");

    if (fileA == NULL) {
        printf("error of opening first file\n");
        return -1;
    }

    fopen_s(&fileB, "fileB.txt", "w");

    if (fileB == NULL) {
        printf("error of opening second file\n");
        return -1;
    }

    int num, unique_num = 0;
    int unique_numbers[100];
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        int counter = 0;

        for (int i = 0; i < unique_num; i++) {
            if (unique_numbers[i] == num) {
                counter = 1;
                break;
            }
        }

        if (counter == 0) {
            unique_numbers[unique_num] = num;
            unique_num++;
        }
    }

    for (int i = 0; i < unique_num; i++) {
        fprintf_s(fileB, "%d", unique_numbers[i]);
    }

    fclose(fileA);
    fclose(fileB);

    printf("program run success\n");

    return 0;
}


#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    FILE* F1, * F2;

    fopen_s(&F1, "F1.txt", "r");

    if (F1 == NULL) {
        printf("error of opening first file\n");
        return -1;
    }

    fopen_s(&F2, "F2.txt", "w");

    if (F2 == NULL) {
        printf("error of opening second file\n");
    }

    char string[100];
    int number;

    printf("enter num: ");
    scanf_s("%d", &number);

    while (fgets(string, sizeof(string), F1) != NULL) {
        if (strlen(string) > number) {
            fprintf_s(F2, "%s", string);
        }
    }

    fclose(F1);
    fclose(F2);

    printf("program run success\n");

    return 0;
}