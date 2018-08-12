#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int info;
	node *next;
};

struct list
{
	node *head;
	node *tail;
};

node *GetNode(int x)
{
	node *p;
	p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho.";
		exit(1);
	}
	p->info = x;
	p->next = NULL;
	p->next = 0;
	return p;
}

void InsertHead(list &l, int x)
{
	node *p;
	p = GetNode(x);
	if (p == NULL)
	{
		cout << "Khong tao duoc nut!";
		exit(1);
	}
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		p->next = l.head;
		l.head = p;
	}
}

void Output(list &l)
{
	node *p;
	p = l.head;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}

int Sum(list &l)
{
	int sum = 0;
	node *p;
	p = l.head;
	while (p != NULL)
	{
		sum += p->info;
		p = p->next;
	}
	return sum;
}

int Count(list &l)
{
	int count = 0;
	node *p;
	p = l.head;
	while (p != NULL)
	{
		count += 1;
		p = p->next;
	}
	return count;
}

int Check(list &l, int x)
{
	int count = 0;
	node *p;
	p = l.head;
	while (p != NULL)
	{
		if (x == p->info)
			return 1;
		p = p->next;
	}
	return 0;
}

int Max(list &l)
{
	node *p;
	p = l.head;
	int max = p->info;
	while (p != NULL)
	{
		if (p->info > max)
			max = p->info;
		p = p->next;
	}
	return max;
}

int SNT(int x)
{
	for (int i = 2; i < x; i++)
		if (x%i == 0) return 0;
	return 1;
}

void CountSNT(list &l)
{
	int d = 0;
	node *p;
	p = l.head;
	while (p != NULL)
	{
		if (SNT(p->info))
		{
			cout << p->info << " ";
			d++;
		}
		p = p->next;
	}
	if (d != 0)
		cout << "la " << d << " so nguyen to trong dslk.";
	else
		cout << "Khong co so nguyen to.";
}

void main()
{
	list l;
	l.head = l.tail = NULL;
	int x, y;
	cout << "Nhap noi dung nut, nhap 0 de dung: ";
	cin >> x;
	while (x != 0)
	{
		InsertHead(l, x);
		cout << "Nhap noi dung nut, nhap 0 de dung: ";
		cin >> x;
	}
	Output(l);
	cout << "\nTong phan tu: " << Sum(l);
	cout << "\nDem so nut: " << Count(l);
	cout << "\nNhap so can tim: ";
	cin >> y;
	if (Check(l, y)) cout << "Co " << y << " trong dslk.";
	else cout << "Khong co "<< y << " trong dslk.";
	cout << "\nPhan tu lon nhat: " << Max(l);
	cout << endl;
	CountSNT(l);
	cout << "\n\n";
	system("pause");
}