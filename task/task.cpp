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
		СТАТУС : Не готово.
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

	return 0;
}