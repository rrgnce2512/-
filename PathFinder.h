#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;


class PathFinder
{
public:
	// ��������� ��� ����������� ����
	struct path{
		// ����� ������ � ����� ��������
		int A, B;

		// �������� ����� (1000000000), ���� ��� ����
		int time;

		// ������ ��� �������� ����
		vector<int> way;

		path(int a, int b) {
			A = a;
			B = b;
			time = -1;
			way.clear();
		}

		// ���������� ����� �� ������
		int getTime() {
			return time;
		}
	};
	
	PathFinder();
	// ����������� ������, ������� ��������� �������� �����, � ������� �������� ������
	PathFinder(string path);

	// ���������� ����������� ���� � ������� ��������� ��������
	path FindPath(int a, int b);

	// ���� �� ����� � ������ ������� � ����
	bool exist(int x);
private:
	// ������� ���� �����
	double calc(int s, int p, double dist);

	// ������� ��������� ����� ��������
	double dist(pair<int, int> a, pair<int, int> b);

	// �������� ��������� ������
	vector<pair<int, int> > city;

	// ������ ��������� ������ �����
	vector<vector<pair<int, double> > > roads;
};

