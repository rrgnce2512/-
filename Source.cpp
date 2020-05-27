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

	cout << "Данные успешно загружены\n";
	cout << "Для выхода из программы введите 0\n";


	for (;;) {
		cout << "Введите номера вершин, между которыми необходимо найти путь: \n";
		int a, b;
		cin >> a;
		if (a == 0) {
			return 0;
		}
		if (!solution.exist(a)) {
			printf("Вершины с номером %d в городе нет\n", a);
			continue;
		}
		cin >> b;
		if (!solution.exist(b)) {
			printf("Вершины с номером %d в городе нет\n", b);
			continue;
		}
		auto res = solution.FindPath(a, b);
		if (res.time != -1) {
			cout << "Кратчайший путь между вершинами с текущей загруженностью дорог: \n";
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
			cout << "Между выбранными вершинами нет пути.\n";
		}
	}
}