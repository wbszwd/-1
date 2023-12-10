#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
// �����ְ��������Ϣ�ṹ��
struct EmployeeSalary {
	string num;
	string name;
	string title;
	int workage;
	double dSalary[5];
}staff[3];

void show1();
void show2();
void search1(string a);
void search2(string b);
void search3(double a, double b);
void BubbleSort(double* arr, int n);

//��ʾ��Ϣ��ѯ
void show1()
{
	cout << "===>1.��ְ�����Ų�ѯ" << endl;
	cout << "===>2.��ְ��������ѯ" << endl;
	cout << "===>3.��������Χ��ѯ" << endl;
	cout << "===>0.�˳���ѯ" << endl;
	cout << "��ѡ��1-3��0����" << endl;
	int choice;
	string a, b;
	double c=0, d=0;
	cin >> choice;
	switch (choice) {
	case 1:
		search1(a); break;
	case 2:
		search2(b); break;
	case 3:
		search3(c,d); break;
	case 0:
		cout << "���˳���" << endl; break;
	}
}
//��Ϣ���
void show2()
{
	cout << "����" << "    ����   " << " ְ��   " << " ��λ����" << " н������" << " ��λ����" << " �����" << " ������Ч" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << staff[i].num << "\t" << staff[i].name << "\t" << staff[i].title << "\t";
		for (int j = 0; j < 5; j++)
		{
			cout << staff[i].dSalary[j] << "      ";
		}
		cout << endl;
	}

}
//�����Ų�ѯ
void search1(string a)
{
	cin >> a;
	int i = 0;
	for (;i < 3; i++)
	{
		if (a == staff[i].num) break;
	}
	cout << "����" << "    ����   " << " ְ��   " << " ��λ����" << " н������" << " ��λ����" << " �����" << " ������Ч" << endl;
	cout << staff[i].num << "\t" << staff[i].name << "\t" << staff[i].title << "\t";
	for (int j = 0; j < 5; j++)
	{
		cout << staff[i].dSalary[j] << "      ";
	}

}
//��������ѯ
void search2(string b)
{
	cin >> b;
	int i = 0;
	for (; i < 3; i++)
	{
		if (b == staff[i].name) break;
	}
	cout << "����" << "    ����   " << " ְ��   " << " ��λ����" << " н������" << " ��λ����" << " �����" << " ������Ч" << endl;
	cout << staff[i].num << "\t" << staff[i].name << "\t" << staff[i].title << "\t";
	for (int j = 0; j < 5; j++)
	{
		cout << staff[i].dSalary[j] << "      ";
	}
}
//�����ʷ�Χ��ѯ
void search3(double a,double b)
{
	cout << "������Ҫ��ѯ�Ĺ��ʷ�Χ����͹��ʺ���߹��ʣ��ÿո��������";
	cin >> a >> b;
	BubbleSort(staff[0].dSalary, 5);
	BubbleSort(staff[1].dSalary, 5);
	BubbleSort(staff[2].dSalary, 5);
	bool found = false;
	for (int i = 0; i < 3; i++) {

		if (staff[i].dSalary[0] >= a && staff[i].dSalary[4] <= b) {
			cout << "���ţ�" << staff[i].title << "��������" << staff[i].name << "�����ʣ�" << staff[i].dSalary << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "δ�ҵ�����Ҫ���Ա����Ϣ��" << endl;
	}
}

//ð������
void BubbleSort(double* arr, int n)
{
	int end = n;
	while (end)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				double tem = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tem;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}

int main()
{
	staff[0].num = "2436";
	staff[0].name = "����";
	staff[0].title = "��ʦ";
	staff[0].dSalary[0] = 2050;
	staff[0].dSalary[1] = 2037;
	staff[1].num = "5201";
	staff[1].name = "�";
	staff[1].title = "������";
	staff[1].dSalary[0] = 2950;
	staff[1].dSalary[1] = 2337;
	staff[2].num = "1326";
	staff[2].name = "��һ";
	staff[2].title = "����";
	staff[2].dSalary[0] = 3450;
	staff[2].dSalary[1] = 2437;
	for (int i = 0; i < 3; i++)
	{
		staff[i].dSalary[2] = 1903;
		staff[i].dSalary[3] = 1270;
		staff[i].dSalary[4] = 3500;
	}
	return 0;
}