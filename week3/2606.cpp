#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void dfs(const vector<vector<int>>& c, set<int>& s, vector<bool>& visited, int n, int v) { //���̿켱Ž�� Depth-First-Search, ���̿켱: Breadth-first-search
	for (int i = 2; i <= n; i++) {
		if (c[v][i] == 1 && !visited[i]) { //1�̰� �湮���� �ʾҴٸ�,
			s.insert(i);
			visited[i] = true;
			dfs(c, s, visited, n, i);
		}
	}
}

int main() {
	int n, connect; //��ǻ�� ��, ���� ��
	cin >> n>>connect;
	set<int> s;
	vector<vector<int>> c(n+1, vector<int>(n+1,0));
	vector<bool> visited (n+1,false);
	for (int k = 0; k < connect; k++) {
		int a, b;
		cin >> a >> b;
		c[a][b] = 1;
		c[b][a] = 1;
	}
	dfs(c, s, visited ,n, 1);
	cout << s.size();

	return 0;
}
