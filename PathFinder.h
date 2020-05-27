#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;


class PathFinder
{
public:
	// Струкрута для возвращения пути
	struct path{
		// Точки начала и конца маршрута
		int A, B;

		// Итоговое время (1000000000), если нет пути
		int time;

		// Вектор для хранения пути
		vector<int> way;

		path(int a, int b) {
			A = a;
			B = b;
			time = -1;
			way.clear();
		}

		// Возвращает ответ на задачу
		int getTime() {
			return time;
		}
	};
	
	PathFinder();
	// Конструктор класса, который принимает название файла, в котором хранятся данные
	PathFinder(string path);

	// Нахождение кратчайшего пути с помощью алгоритма Дейкстры
	path FindPath(int a, int b);

	// Есть ли город с данным номером в сети
	bool exist(int x);
private:
	// Подсчет веса ребра
	double calc(int s, int p, double dist);

	// Подсчет дистанции между городами
	double dist(pair<int, int> a, pair<int, int> b);

	// Хранение координат вершин
	vector<pair<int, int> > city;

	// Список смежности вершин графа
	vector<vector<pair<int, double> > > roads;
};

