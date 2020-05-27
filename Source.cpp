#include <iostream>

#include "PathFinder.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	PathFinder solution;
	try {
		solution = PathFinder("data.txt");
	}
	catch (exception e){
		cout << e.what();
	}

	cout << "������ ������� ���������\n";
	cout << "��� ������ �� ��������� ������� 0\n";


	for (;;) {
		cout << "������� ������ ������, ����� �������� ���������� ����� ����: \n";
		int a, b;
		cin >> a;
		if (a == 0) {
			return 0;
		}
		if (!solution.exist(a)) {
			printf("������� � ������� %d � ������ ���\n", a);
			continue;
		}
		cin >> b;
		if (!solution.exist(b)) {
			printf("������� � ������� %d � ������ ���\n", b);
			continue;
		}
		auto res = solution.FindPath(a, b);
		if (res.time != -1) {
			cout << "���������� ���� ����� ��������� � ������� �������������� �����: \n";
			for (int i = 0; i < res.way.size(); i++) {
				cout << res.way[i] + 1;
				if (i != res.way.size() - 1) {
					cout << " -> ";
				}
				else {
					cout << "\n";
				}
			}
		}
		else {
			cout << "����� ���������� ��������� ��� ����.\n";
		}
	}
}