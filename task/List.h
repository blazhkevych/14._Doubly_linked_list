#pragma once;

struct Elem
{
	char m_data; // Данные
	Elem* m_next, * m_prev;
};

class List
{
	// Голова, хвост
	Elem* m_head, * m_tail;
	// Количество элементов
	int m_count;

public:

	// Конструктор
	List();

	// Конструктор копирования
	List(const List&);

	// Деструктор
	~List();

	// Получить количество элементов
	int GetCount() const;

	// Получить элемент списка
	Elem* GetElem(int) const;

	// Удалить весь список
	void DelAll();

	// Удаление элемента по индексу
	void Del(int pos);

	// Вставка элемента в заданную позицию
	void Insert(char data, int pos);

	// Добавление в конец списка
	void AddTail(char data);

	// Добавление в начало списка
	void AddHead(char data);

	//Удаление головного элемента
	void DelHead();

	//Удаление хвостового элемента
	void DelTail();

	// Печать списка, начиная с головы
	void PrintHead() const;

	//Печать списка, начиная с хвоста
	void PrintTail() const;

	// Перегрузка оператора =
	List& operator = (const List&);

	// Метод поиска заданного элемента по ключу. Ключ
	// передаётся методу в качестве параметра. Метод
	// возвращает позицию найденного элемента в случае
	// успеха или - 1 в противном случае.
	int Find(char key) const;

	// Метод замены значения указанного элемента на другое
	// значение, передаваемое методу в качестве параметра.
	void Replace(char value, int position) const;

	// Метод удаления элементов списка, значение которых
	// совпадает с заданным ключом.
	void DelElementByKey(char key);

	// Перегруженный оператор индексирования.
	char& operator[](int position) const;

	// Метод сортировки элементов списка.
	void Sort();
};