#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	m_head = m_tail = nullptr;
	m_count = 0;
}

List::List(const List& L)
{
	m_head = m_tail = nullptr;
	m_count = 0;
	Elem* temp = L.m_head;
	while (temp != nullptr)
	{
		AddTail(temp->m_data);
		temp = temp->m_next;
	}
}

List::~List()
{
	DelAll();
}

void List::AddHead(char data)
{
	Elem* temp = new Elem;
	temp->m_prev = nullptr;
	temp->m_data = data;
	temp->m_next = m_head;
	if (m_head != nullptr)
		m_head->m_prev = temp;
	m_head = temp;
	if (m_tail == nullptr)
		m_tail = temp;
	m_count++;
}

void List::AddTail(char data)
{
	Elem* temp = new Elem;
	temp->m_next = nullptr;
	temp->m_data = data;
	temp->m_prev = m_tail;
	if (m_tail != nullptr)
		m_tail->m_next = temp;
	m_tail = temp;
	if (m_head == nullptr)
		m_head = temp;
	m_count++;
}

void List::DelHead()
{
	if (m_head != nullptr)
	{
		Elem* temp = m_head;
		m_head = m_head->m_next;
		if (m_head != nullptr)
			m_head->m_prev = nullptr;
		else
			m_tail = nullptr;
		delete temp;
		m_count--;
	}
}

void List::DelTail()
{
	if (m_tail != nullptr)
	{
		Elem* temp = m_tail;
		m_tail = m_tail->m_prev;
		if (m_tail != nullptr)
			m_tail->m_next = nullptr;
		else
			m_head = nullptr;
		delete temp;
		m_count--;
	}
}

void List::Insert(char data, int pos)
{
	if (pos < 0 || pos > m_count)
		return;
	if (pos == 0)
	{
		AddHead(data);
		return;
	}
	if (pos == m_count)
	{
		AddTail(data);
		return;
	}
	Elem* current = nullptr;
	if (pos < m_count / 2)
	{
		current = m_head;
		int i = 0;
		while (i < pos)
		{
			current = current->m_next;
			i++;
		}
	}
	else
	{
		current = m_tail;
		int i = m_count - 1;
		while (i > pos)
		{
			current = current->m_prev;
			i--;
		}
	}
	Elem* temp = new Elem;
	temp->m_data = data;
	temp->m_prev = current->m_prev;
	temp->m_next = current;
	current->m_prev->m_next = temp;
	current->m_prev = temp;
	m_count++;
}

void List::Del(int pos)
{
	if (pos < 0 || pos >= m_count)
		return;
	if (pos == 0)
	{
		DelHead();
		return;
	}
	if (pos == m_count - 1)
	{
		DelTail();
		return;
	}
	Elem* delElement = nullptr;
	if (pos < m_count / 2)
	{
		delElement = m_head;
		int i = 0;
		while (i < pos)
		{
			delElement = delElement->m_next;
			i++;
		}
	}
	else
	{
		delElement = m_tail;
		int i = m_count - 1;
		while (i > pos)
		{
			delElement = delElement->m_prev;
			i--;
		}
	}
	delElement->m_prev->m_next = delElement->m_next;
	delElement->m_next->m_prev = delElement->m_prev;
	delete delElement;
	m_count--;
}

void List::PrintHead() const
{
	Elem* current = m_head;
	while (current != nullptr)
	{
		cout << current->m_data;
		current = current->m_next;
	}
	cout << endl;
}

void List::PrintTail() const
{
	Elem* current = m_tail;
	while (current != nullptr)
	{
		cout << current->m_data;
		current = current->m_prev;
	}
	cout << endl;
}

void List::DelAll()
{
	while (m_head != nullptr)
		DelHead();
}

int List::GetCount() const
{
	return m_count;
}

Elem* List::GetElem(int pos) const
{
	Elem* temp = m_head;
	if (pos < 0 || pos >= m_count)
		return nullptr;
	int i = 0;
	while (i < pos)
	{
		temp = temp->m_next;
		i++;
	}
	return temp;
}

List& List::operator = (const List& L)
{
	if (this == &L)
		return *this;
	DelAll();
	Elem* temp = L.m_head;
	while (temp != nullptr)
	{
		AddTail(temp->m_data);
		temp = temp->m_next;
	}
	return *this;
}

// Метод поиска заданного элемента по ключу. Ключ
// передаётся методу в качестве параметра. Метод
// возвращает позицию найденного элемента в случае
// успеха или - 1 в противном случае.
int List::Find(char key) const
{
	int position{ 0 };
	// Запоминаем адрес головного элемента.
	const Elem* temp = m_head;
	// Пока еще есть элементы.
	while (temp != nullptr)
	{
		if (key == temp->m_data)
		{
			return position;
		}
		// Переходим на следующий элемент.
		temp = temp->m_next;
		position++;
	}

	return -1;
}

// Метод замены значения указанного элемента на другое
// значение, передаваемое методу в качестве параметра.
void List::Replace(char value, int position) const 
{
	if (position < 0 || position >= m_count)
		return;
	else
	{
		int i{ 0 };
		// Запоминаем адрес головного элемента.
		Elem* temp = m_head;
		// Пока еще есть элементы.
		while (temp != nullptr)
		{
			if (position == i)
			{
				temp->m_data = value;
				break;
			}
			// Переходим на следующий элемент.
			temp = temp->m_next;
			i++;
		}
	}
}

// Метод удаления элементов списка, значение которых
// совпадает с заданным ключом.
void List::DelElementByKey(char key) 
{
	int i{ 0 };
	// Запоминаем адрес головного элемента.
	Elem* current = m_head;
	// Пока еще есть элементы.
	Elem* afterCurrent{ nullptr };
	while (current != nullptr)
	{
		if (key == current->m_data)
		{
			afterCurrent = current->m_next; // сохраняем адрес следующего за елемента за текущим.
			Del(i);
			current = afterCurrent;
			continue;
		}
		// Переходим на следующий элемент.
		current = current->m_next;
		i++;
	}
}

// Перегруженный оператор индексирования.
char& List::operator[](int position) const
{
	if (position < 0 || position >= m_count)
		return m_head->m_data;

	int i{ 0 };
	// Запоминаем адрес головного элемента.
	Elem* current = m_head;
	// Пока еще есть элементы.
	while (current != nullptr)
	{
		if (position == i)
			return current->m_data;
		// Переходим на следующий элемент.
		current = current->m_next;
		i++;
	}
}

// Метод сортировки элементов списка.
void List::Sort()
{
	// Запоминаем адрес головного элемента.
	List temp = *this;
	for (int i = 0; i < m_count; i++)
	{
		for (int j = m_count - 1; j > i; j--)
		{
			if (temp[j - 1] > temp[j])
			{
				char x = temp[j - 1];
				temp[j - 1] = temp[j];
				temp[j] = x;
			}
		}
	}
	*this = temp;
}