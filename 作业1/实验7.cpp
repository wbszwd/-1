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

// �ȽϺ�������������
bool compareByNum(const Employee& a, const Employee& b) {
	return a.num < b.num;
}

bool compareByName(const Employee& a, const Employee& b) {
	return a.name < b.name;
}

// ���ֲ��Һ���
int binarySearch(const vector<Employee>& employees, const string& key, bool byNum) {
	int low = 0;
	int high = employees.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if ((byNum && employees[mid].num == key) || (!byNum && employees[mid].name == key)) {
			return mid;  // �ҵ��ؼ��֣���������
		}
		else if ((byNum && employees[mid].num < key) || (!byNum && employees[mid].name < key)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;  // û���ҵ��ؼ���
}

// ɾ��ָ��������Ԫ��
void deleteEmployee(vector<Employee>& employees, int index) {
	employees.erase(employees.begin() + index);
}

int main() {
	// ��ʼ��Ա�����ݿ�
	vector<Employee> employeeDatabase = {
		{"2436", "����", "��ʦ", {2050, 2037, 1903, 1270, 3500}},
		{"5201", "�", "������", {2950, 2337, 1903, 1270, 3500}},
		{"1326", "��һ", "����", {3450, 2437, 1903, 1270, 3500}}
		// ���Լ�����Ӹ����Ա����Ϣ
	};

	// ��Ա����Ϣ�����Ž�������
	sort(employeeDatabase.begin(), employeeDatabase.end(), compareByNum);

	int choice;
	string key;

	do {
		cout << "====>1.�����Ų�ѯ\n"
			<< "====>2.��������ѯ\n"
			<< "====>0.�˳�\n"
			<< "��ѡ��1-2��0��: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "������Ҫ��ѯ�Ĺ���: ";
			cin >> key;

			// ���ֲ��ҹؼ���
			int index = binarySearch(employeeDatabase, key, true);

			if (index != -1) {
				// �ҵ��ˣ���ʾԱ����Ϣ
				cout << "�ҵ�Ա����Ϣ��" << endl;
				cout << "����\t����\tְ��\t��λ����\tн������\t��λ����\t�����\t������Ч\n";
				cout << employeeDatabase[index].num << "\t"
					<< employeeDatabase[index].name << "\t"
					<< employeeDatabase[index].title << "\t"
					<< employeeDatabase[index].dSalary[0] << "\t"
					<< employeeDatabase[index].dSalary[1] << "\t"
					<< employeeDatabase[index].dSalary[2] << "\t"
					<< employeeDatabase[index].dSalary[3] << "\t"
					<< employeeDatabase[index].dSalary[4] << endl;

				// ɾ��Ա����Ϣ
				cout << "�Ƿ�ɾ����Ա����Ϣ��(y/n): ";
				char confirm;
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y') {
					deleteEmployee(employeeDatabase, index);
					cout << "Ա����Ϣ��ɾ����\n";
				}
			}
			else {
				cout << "δ�ҵ�����Ҫ���Ա����Ϣ��\n";
			}
			break;
		}
		case 2: {
			cout << "������Ҫ��ѯ������: ";
			cin >> key;

			// ���ֲ��ҹؼ���
			int index = binarySearch(employeeDatabase, key, false);

			if (index != -1) {
				// �ҵ��ˣ���ʾԱ����Ϣ
				cout << "�ҵ�Ա����Ϣ��" << endl;
				cout << "����\t����\tְ��\t��λ����\tн������\t��λ����\t�����\t������Ч\n";
				cout << employeeDatabase[index].num << "\t"
					<< employeeDatabase[index].name << "\t"
					<< employeeDatabase[index].title << "\t"
					<< employeeDatabase[index].dSalary[0] << "\t"
					<< employeeDatabase[index].dSalary[1] << "\t"
					<< employeeDatabase[index].dSalary[2] << "\t"
					<< employeeDatabase[index].dSalary[3] << "\t"
					<< employeeDatabase[index].dSalary[4] << endl;

				// ɾ��Ա����Ϣ
				cout << "�Ƿ�ɾ����Ա����Ϣ��(y/n): ";
				char confirm;
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y') {
					deleteEmployee(employeeDatabase, index);
					cout << "Ա����Ϣ��ɾ����\n";
				}
			}
			else {
				cout << "δ�ҵ�����Ҫ���Ա����Ϣ��\n";
			}
			break;
		}
		case 0:
			cout << "�˳�����\n";
			break;
		default:
			cout << "��Ч��ѡ�����������롣\n";
		}

	} while (choice != 0);

	return 0;
}
