#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Employee {
	string num;
	string name;
	string title;
	double dSalary[5];
};

// 比较函数，用于排序
bool compareByNum(const Employee& a, const Employee& b) {
	return a.num < b.num;
}

bool compareByName(const Employee& a, const Employee& b) {
	return a.name < b.name;
}

// 二分查找函数
int binarySearch(const vector<Employee>& employees, const string& key, bool byNum) {
	int low = 0;
	int high = employees.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if ((byNum && employees[mid].num == key) || (!byNum && employees[mid].name == key)) {
			return mid;  // 找到关键字，返回索引
		}
		else if ((byNum && employees[mid].num < key) || (!byNum && employees[mid].name < key)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;  // 没有找到关键字
}

// 删除指定索引的元素
void deleteEmployee(vector<Employee>& employees, int index) {
	employees.erase(employees.begin() + index);
}

int main() {
	// 初始化员工数据库
	vector<Employee> employeeDatabase = {
		{"2436", "张树", "讲师", {2050, 2037, 1903, 1270, 3500}},
		{"5201", "李华", "副教授", {2950, 2337, 1903, 1270, 3500}},
		{"1326", "王一", "教授", {3450, 2437, 1903, 1270, 3500}}
		// 可以继续添加更多的员工信息
	};

	// 对员工信息按工号进行排序
	sort(employeeDatabase.begin(), employeeDatabase.end(), compareByNum);

	int choice;
	string key;

	do {
		cout << "====>1.按工号查询\n"
			<< "====>2.按姓名查询\n"
			<< "====>0.退出\n"
			<< "请选择（1-2或0）: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "请输入要查询的工号: ";
			cin >> key;

			// 二分查找关键字
			int index = binarySearch(employeeDatabase, key, true);

			if (index != -1) {
				// 找到了，显示员工信息
				cout << "找到员工信息：" << endl;
				cout << "工号\t姓名\t职称\t岗位工资\t薪级工资\t岗位津贴\t生活补贴\t奖励绩效\n";
				cout << employeeDatabase[index].num << "\t"
					<< employeeDatabase[index].name << "\t"
					<< employeeDatabase[index].title << "\t"
					<< employeeDatabase[index].dSalary[0] << "\t"
					<< employeeDatabase[index].dSalary[1] << "\t"
					<< employeeDatabase[index].dSalary[2] << "\t"
					<< employeeDatabase[index].dSalary[3] << "\t"
					<< employeeDatabase[index].dSalary[4] << endl;

				// 删除员工信息
				cout << "是否删除该员工信息？(y/n): ";
				char confirm;
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y') {
					deleteEmployee(employeeDatabase, index);
					cout << "员工信息已删除。\n";
				}
			}
			else {
				cout << "未找到符合要求的员工信息！\n";
			}
			break;
		}
		case 2: {
			cout << "请输入要查询的姓名: ";
			cin >> key;

			// 二分查找关键字
			int index = binarySearch(employeeDatabase, key, false);

			if (index != -1) {
				// 找到了，显示员工信息
				cout << "找到员工信息：" << endl;
				cout << "工号\t姓名\t职称\t岗位工资\t薪级工资\t岗位津贴\t生活补贴\t奖励绩效\n";
				cout << employeeDatabase[index].num << "\t"
					<< employeeDatabase[index].name << "\t"
					<< employeeDatabase[index].title << "\t"
					<< employeeDatabase[index].dSalary[0] << "\t"
					<< employeeDatabase[index].dSalary[1] << "\t"
					<< employeeDatabase[index].dSalary[2] << "\t"
					<< employeeDatabase[index].dSalary[3] << "\t"
					<< employeeDatabase[index].dSalary[4] << endl;

				// 删除员工信息
				cout << "是否删除该员工信息？(y/n): ";
				char confirm;
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y') {
					deleteEmployee(employeeDatabase, index);
					cout << "员工信息已删除。\n";
				}
			}
			else {
				cout << "未找到符合要求的员工信息！\n";
			}
			break;
		}
		case 0:
			cout << "退出程序。\n";
			break;
		default:
			cout << "无效的选择，请重新输入。\n";
		}

	} while (choice != 0);

	return 0;
}
