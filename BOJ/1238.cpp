#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int vis[1001][1001];
int cost[1001][1001];
vector<int>road[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	while (m--) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		cin >> cost[a][b];
	}

	queue<pair<int, int>>q;
	for (int i = 1; i <= n; i++) {
		q.push({ i,0 });
		while (!q.empty()) {
			int r = q.front().first;
			int t = q.front().second;
			q.pop();
			for (int w : road[r]) {
				if (vis[i][w] != 0 && vis[i][w] <= t + cost[r][w])continue;
				vis[i][w] = t + cost[r][w];
				q.push({ w,t + cost[r][w] });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;
		ans = max(ans, vis[i][x] + vis[x][i]);
	}
	cout << ans;
}