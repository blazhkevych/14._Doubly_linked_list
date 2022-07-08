/*
############################################ ЗАДАНИЕ ###########################################
					Добавить в класс "Двусвязный список":
	 Метод поиска заданного элемента по ключу. Ключ
передаётся методу в качестве параметра. Метод
возвращает позицию найденного элемента в случае
успеха или -1 в противном случае.
int Find (char key);
	 Метод замены значения указанного элемента на другое
значение, передаваемое методу в качестве параметра.
void Replace (char value, int position);
	 Метод удаления элементов списка, значение которых
совпадает с заданным ключом.
void DelElementByKey(char key);
	 Перегруженный оператор индексирования.
char& operator[](int position);
	 Метод сортировки элементов списка.
void Sort();
################################################################################################
		СТАТУС : Готово.
################################################################################################
*/

#include <iostream>
#include "List.h"

using namespace std;
int main()
{
	List lst;
	char s[] = "Hello, World !!!";
	cout << s << endl;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
		lst.AddHead(s[i]);
	cout << "\nFirst list\n";
	lst.PrintHead();
	List lst2 = lst;
	cout << "\nSecond list\n";
	lst2.PrintHead();
	List lst3;
	lst3 = lst;
	cout << "\nThird list\n";
	lst3.PrintHead();
	cout << "\nFirst list\n";
	lst.PrintTail();
	lst.Del(2);
	lst.PrintHead();
	lst.Insert('?', 0);
	lst.Insert('?', 4);
	lst.Insert('?', 4);
	lst.PrintHead();
	lst.DelHead();
	lst.PrintHead();
	lst.DelTail();
	lst.PrintHead();

	cout << "#############################################" << endl;
	cout << "Tests" << endl;
	cout << "#############################################" << endl;

	// Метод поиска заданного элемента по ключу. Ключ
	// передаётся методу в качестве параметра. Метод
	// возвращает позицию найденного элемента в случае
	// успеха или - 1 в противном случае.
	List list2;
	char s2[] = "Hello, World !!!";
	//char s2[] = "2013564978";
	cout << s2 << endl;
	int len2 = strlen(s2);
	for (int i = len2 - 1; i >= 0; i--)
		list2.AddHead(s2[i]);
	cout << "\nlist2:\n";
	list2.PrintHead();
	cout << "list2.Find('H');" << endl;
	cout << list2.Find('H') << endl << endl;

	// Метод замены значения указанного элемента на другое
	// значение, передаваемое методу в качестве параметра.
	cout << "list2.Replace('@', 3);" << endl;
	list2.Replace('@', 3);
	cout << "list2:\n";
	list2.PrintHead();
	cout << endl << endl;

	// Метод удаления элементов списка, значение которых
	// совпадает с заданным ключом.
	cout << "list2.DelElementByKey('o');" << endl;
	list2.DelElementByKey('o');
	cout << "list2:\n";
	list2.PrintHead();
	cout << endl << endl;

	// Перегруженный оператор индексирования.
	cout << "const char ch = list2[1];" << endl;
	const char ch = list2[1];
	cout << "list2:\n";
	cout << ch << endl << endl;

	// Метод сортировки элементов списка.
	cout << "list2:\n";
	list2.PrintHead();
	list2.Sort();
	cout << "list2.Sort();" << endl;
	cout << "list2:\n";
	list2.PrintHead();

	return 0;
}