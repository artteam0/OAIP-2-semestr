#include"Heap.h"
#include<iostream>
#include<iomanip>

using namespace std;

void AAA::print()
{
	cout << x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*)) // создание кучи
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)  // получение левого элемента
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix) // получение правого элемента
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix) // получение родительского узла
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j) // меняем местами
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix) //восстанавливаем кучу
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}


	void Heap::insert(void* x) // вставляем элемент в кучу
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax() // удаляем максимальное значение из кучи
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}



	void Heap::scan(int i) const//Вывод значений элементов на экран
	{
		int probel = 20;
		cout << '\n';
		if (size == 0)
			cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		cout << '\n';
	}

	void Heap::extractI() // удаление i-го элемента
	{
		int i;
		cout << "Введите i:";
		cin >> i;
		cout << endl;
		if (!isEmpty()) // Проверка, что куча не пуста
		{
			for (int j = i; j < size - 1; j++) // Сдвиг элементов после i на одну позицию влево
			{
				storage[j] = storage[j + 1];
			}
			size--; // Уменьшение размера кучи на 1
			heapify(0); // Восстановление свойств кучи
		}
	}

	void Heap::extractMin() // удаление минимального
	{
		int min = 100, a; // Инициализация переменных min и a
		int** A = (int**)storage; // Приведение указателя storage к типу int**
		void* rc = nullptr; // Инициализация указателя rc

		if (!isEmpty()) // Проверка, что куча не пуста
		{
			for (int i = 0; i < size; i++) // Поиск минимального значения в куче
			{
				if (*A[i] < min) // Если текущий элемент меньше min, обновляем min и запоминаем индекс a
				{
					min = *A[i];
					a = i;
				}
			}
			int i = parent(a); // Вычисление индекса родителя элемента a
			for (int i = a; i < size - 1; i++) // Сдвиг элементов после a на одну позицию влево
			{
				storage[i] = storage[i + 1];
			}
			size--; // Уменьшение размера кучи на 1
			heapify(0); // Восстановление свойств кучи
		}
	}

	void Heap::unionHeap(void* x) // объединение двух куч в одну
	{
		int i;

		for (i = 0; i < size - 1; i++) // Сдвиг элементов кучи на одну позицию влево
		{
			storage[i] = storage[i + 1];
		}
		heapify(0); // Восстановление свойств кучи

		storage[i = ++size - 1] = x; // Добавление нового элемента x в конец кучи
		while (i > 0 && isLess(storage[parent(i)], storage[i])) // Пока не достигнут корень и нарушено свойство кучи, выполняем перестановку элементов
		{
			swap(parent(i), i);
			i = parent(i);
		}
	}

	void printLeftChildrenCount(const heap::Heap& heap, int index)
	{
		// Получаем индекс левого потомка
		int leftChildIndex = h1.left(index);

		// Если левый потомок существует
		if (leftChildIndex != -1)
		{
			// Считаем количество левых потомков текущей вершины
			int leftChildrenCount = 1; // По умолчанию есть левый потомок

			// Рекурсивно вызываем функцию для левого потомка
			printLeftChildrenCount(heap, leftChildIndex);

			// Проверяем наличие дополнительных левых потомков
			int nextLeftChildIndex = heap.left(leftChildIndex);
			while (nextLeftChildIndex != -1)
			{
				leftChildrenCount++; // Увеличиваем счетчик
				// Переходим к следующему левому потомку
				nextLeftChildIndex = heap.left(nextLeftChildIndex);
			}

			// Выводим количество левых потомков текущей вершины
			cout << "Количество левых дочерних вершин для вершины с индексом " << index << ": " << leftChildrenCount << endl;
		}
		else
		{
			// Если левого потомка нет, выводим 0
			cout << "Количество левых дочерних вершин для вершины с индексом " << index << ": " << 0 << endl;
		}
	}


}
