// SP_LABA3.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
using namespace std;

struct Elem
{
	string data;
	Elem* next, * prev;
};

class List
{
	Elem* Head, * Tail;
	int Count;

public:

	List();
	List(const List&);
	~List();

	int GetCount();
	// �������� ������� ������
	Elem* GetElem(int);

	// ������� ���� ������
	void DelAll();
	// �������� �������� �� �������
	void Del(int pos = 0);
	// ������� �������� �� �������
	void Insert(string n, int pos = 0);
	// ���������� � ����� ������
	void AddTail(string n);
	// ���������� � ������ ������
	void AddHead(string n);
	// ������ ������
	void Print();
	// ������ ������������� ��������
	void Print(int pos);
};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::List(const List& L)
{
	Head = Tail = NULL;
	Count = 0;
	Elem* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DelAll();
}

void List::AddHead(string n)
{
	Elem* temp = new Elem;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

void List::AddTail(string n)
{
	Elem* temp = new Elem;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}

void List::Insert(string data, int pos)
{
	if (pos < 1 || pos > Count + 1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	if (pos == Count + 1)
	{
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		AddHead(data);
		return;
	}

	int i = 1;
	string new_data = data;
	// ����������� �� ������ n - 1 ��
	Elem* Ins = Head;
	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}

	Elem* PrevIns = Ins->prev;

	Elem* temp = new Elem;
	temp->data = data;
	// ��������� ������
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}

void List::Del(int pos)
{
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}

	int i = 1;
	Elem* Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	// ���� ������� �� ������
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	// ���� ������� �� �����
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	// ��������� �������?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	delete Del;
	Count--;
}

void List::Print(int pos)
{
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	Elem* temp;
	// ���������� � ����� ������� 
	// ������� ���������
	if (pos <= Count / 2)
	{
		// ������ � ������
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// ������ � ������
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			temp = temp->prev;
			i++;
		}
	}
	cout << pos << " element: ";
	cout << temp->data << endl;
}

void List::Print()
{
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

void List::DelAll()
{
	while (Count != 0)
		Del(1);
}

int List::GetCount()
{
	return Count;
}

Elem* List::GetElem(int pos)
{
	Elem* temp = Head;
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}

void main()
{
	List L;
	L.AddHead("One");
	L.AddHead("Two");
	L.AddHead("Four");
	L.AddHead("Five");
	L.AddHead("Six");	
	cout << "List L:\n";
	L.Print();
	cout << endl;

	L.AddTail("Tail");
	cout << "List L after AddTail: \n";
	L.Print();
	cout << endl;

	L.Insert("Three", 4);
	cout << "List L after Insert:\n";
	L.Print();
	cout << endl;

	
	L.Del(3);
	cout << "List L after Del:\n";
	L.Print();
}
