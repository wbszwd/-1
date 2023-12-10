#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
// 定义教职工工资信息结构体
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

//显示信息查询
void show1()
{
	cout << "===>1.按职工工号查询" << endl;
	cout << "===>2.按职工姓名查询" << endl;
	cout << "===>3.按工作范围查询" << endl;
	cout << "===>0.退出查询" << endl;
	cout << "请选择（1-3或0）：" << endl;
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
		cout << "已退出！" << endl; break;
	}
}
//信息输出
void show2()
{
	cout << "工号" << "    姓名   " << " 职称   " << " 岗位工资" << " 薪级工资" << " 岗位津贴" << " 生活补贴" << " 奖励绩效" << endl;
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
//按工号查询
void search1(string a)
{
	cin >> a;
	int i = 0;
	for (;i < 3; i++)
	{
		if (a == staff[i].num) break;
	}
	cout << "工号" << "    姓名   " << " 职称   " << " 岗位工资" << " 薪级工资" << " 岗位津贴" << " 生活补贴" << " 奖励绩效" << endl;
	cout << staff[i].num << "\t" << staff[i].name << "\t" << staff[i].title << "\t";
	for (int j = 0; j < 5; j++)
	{
		cout << staff[i].dSalary[j] << "      ";
	}

}
//按姓名查询
void search2(string b)
{
	cin >> b;
	int i = 0;
	for (; i < 3; i++)
	{
		if (b == staff[i].name) break;
	}
	cout << "工号" << "    姓名   " << " 职称   " << " 岗位工资" << " 薪级工资" << " 岗位津贴" << " 生活补贴" << " 奖励绩效" << endl;
	cout << staff[i].num << "\t" << staff[i].name << "\t" << staff[i].title << "\t";
	for (int j = 0; j < 5; j++)
	{
		cout << staff[i].dSalary[j] << "      ";
	}
}
//按工资范围查询
void search3(double a,double b)
{
	cout << "请输入要查询的工资范围（最低工资和最高工资，用空格隔开）：";
	cin >> a >> b;
	BubbleSort(staff[0].dSalary, 5);
	BubbleSort(staff[1].dSalary, 5);
	BubbleSort(staff[2].dSalary, 5);
	bool found = false;
	for (int i = 0; i < 3; i++) {

		if (staff[i].dSalary[0] >= a && staff[i].dSalary[4] <= b) {
			cout << "工号：" << staff[i].title << "，姓名：" << staff[i].name << "，工资：" << staff[i].dSalary << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "未找到符合要求的员工信息！" << endl;
	}
}

//冒泡排序
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
	staff[0].name = "张树";
	staff[0].title = "讲师";
	staff[0].dSalary[0] = 2050;
	staff[0].dSalary[1] = 2037;
	staff[1].num = "5201";
	staff[1].name = "李华";
	staff[1].title = "副教授";
	staff[1].dSalary[0] = 2950;
	staff[1].dSalary[1] = 2337;
	staff[2].num = "1326";
	staff[2].name = "王一";
	staff[2].title = "教授";
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