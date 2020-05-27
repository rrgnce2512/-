#include "PathFinder.h"

PathFinder::PathFinder()
{
	city.clear();
	roads.clear();
}

PathFinder::PathFinder(string path)
{
	city.clear();
	roads.clear();

	ifstream in(path);
	if (in.fail()) {
		throw exception("Файл не существует");
	}
	
	int n, m;
	in >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		in >> x >> y;
		city.push_back({x, y});
		roads.push_back(vector<pair<int, double> >(0));
	}
	in >> m;
	for (int i = 0; i < m; i++) {
		int a, b, s, p;
		in >> a >> b >> s >> p;
		a--;
		b--;
		auto distance = calc(s, p, dist(city[a], city[b]));
		if (distance != 1000000000) {
			roads[a].push_back({ b, distance });
			roads[b].push_back({ a, distance });
		}
	}
	in.close();
}

PathFinder::path PathFinder::FindPath(int a, int b)
{
	a--;
	b--;
	const int INF = 1000000000;
	PathFinder::path result(a, b);
	
	set<pair<double, int> > q;
	vector<double> dist(city.size(), INF);
	vector<int> p(city.size());
	dist[a] = 0;
	for (int i = 0; i < dist.size(); i++) {
		q.insert({ dist[i], i });
		p[i] = -1;
	}

	// Поиск пути наименьшего веса
	while (q.size() > 0) {
		auto f = (*q.begin()).second;
		q.erase(*q.begin());
		for (int j = 0; j < roads[f].size(); j++) {
			int c = roads[f][j].first;
			if (dist[c] > dist[f] + roads[f][j].second) {
				q.erase({ dist[c], c });
				dist[c] = dist[f] + roads[f][j].second;
				q.insert({ dist[c], c });
				p[c] = f;
			}
		}
	}

	// Восстановление пути
	if (dist[b] != INF) {
		result.time = -1;
		int t = b;
		while (p[t] != -1) {
			result.way.push_back(t);
			t = p[t];
		}
		result.way.push_back(a);
		result.time = dist[b];

		reverse(result.way.begin(), result.way.end());
	}
	else {
		result.time = dist[b];
	}
	return result;
}

bool PathFinder::exist(int x)
{
	return x <= city.size() && x > 0;
}

double PathFinder::calc(int s, int p, double dist)
{
	if (p == 100) {
		return 1000000000;
	}
	if (p == 0) {
		return dist / s;
	}
	return (dist / s) * (p / 10);
}
// (Расстояние / [пропускная способность]) * ([загруженность] / 10)

double PathFinder::dist(pair<int, int> a, pair<int, int> b)
{
	return sqrt(double((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)));
}
