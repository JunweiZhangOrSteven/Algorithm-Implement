#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int Ni = 10000;
const int INF = 1 << 30;
struct node {
	int v, d;//v is the point, d is the distance
	node() {};
	node(int a, int b) { v = a; d = b; }
	bool operator < (const node& a)const {
		if (d == a.d)return v < a.v;
		else return d > a.d;
	}
};
vector<node>eg[Ni];
int dis[Ni], n;
int vist[Ni];

void Dijkstra(int s) {
	int i;
	for (int i = 0; i <= n; i++) {
		dis[i] = INF;
	}
	dis[s] = 0;
	priority_queue<node> q;
	q.push(node(s, dis[s]));

	while (!q.empty()) {
		node x = q.top();
		q.pop();
		if (vist[x.v])continue;
		vist[x.v] = 1;
		for (int i = 0; i < eg[x.v].size(); i++) {
			node y = eg[x.v][i];
			if (dis[y.v] > x.d + y.d) {
				dis[y.v] = x.d + y.d;
				q.push(node(y.v, dis[y.v]));
			}
		}
	}


}

int main() {
	int a, b, d, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		eg[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		
			cin >> a >> b >> d;
			eg[a].push_back(node(b, d));
			eg[b].push_back(node(a, d));
	}
	Dijkstra(1);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	return 0;





}