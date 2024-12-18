#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size, int p)    //Хеш-функция
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}
//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false; // Флаг, указывающий, был ли элемент успешно вставлен
	if (N != size) { // Проверка, что таблица не заполнена
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b; i++) { // Цикл по всем слотам таблицы
			j = (j + 1) % size; // Переходим к следующему слоту (линейный алгоритм)
			if (data[j] == NULL || data[j] == DEL) { // Если слот пуст или удален
				data[j] = d; // Вставляем элемент
				N++; // Увеличиваем количество элементов в таблице
				b = true; // Устанавливаем флаг успешной вставки
			}
		}
	}
	return b; // Возвращаем успешность вставки
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1; // Индекс элемента, если найден, иначе -1
	bool b = false; // Флаг, указывающий, найден ли элемент
	if (N != 0) { // Проверка, что таблица не пуста
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; i++) {
			// Цикл по всем слотам таблицы для поиска элемента
			if (getKey(data[j]) == key) { // Если ключ элемента совпадает с искомым
				t = j; // Сохраняем индекс элемента
				b = true; // Устанавливаем флаг успешного поиска
			}
			j = (j + 1) % size; // Переходим к следующему слоту (линейный алгоритм)
		}
	}
	return t; // Возвращаем индекс найденного элемента или -1
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------

void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент: " << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}