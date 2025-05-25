#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	int n, m, x, y, d =0;
	cin >> n>> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<vector<int>> distance(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a; 
			//������ǥ ���
			if (a == 2) {
				x = i;
				y = j;
			}
			//�׷��� �Է�
			g[i][j] = a;
		}
	}

	//bfs�� Ž��(����: ���ʺ��� �ð����)
	//�ʱⰪ ����
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		// ť �Ǿ� ���� �� ��ǥ���� Ž��
		int X = q.front().first;
		int Y = q.front().second;
		
		q.pop();
		for (int k = 0; k < 4; k++) {
			//�� ��ǥ ����
			int newX = X + dx[k];
			int newY = Y + dy[k];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && g[newX][newY] != 0 && !visited[newX][newY]) {
				//�湮���� �ʰ� ���� �ƴ� ���� ���� �� ��ǥ�� Ž����� -> ť�� push
				q.push({ newX,newY });
				//�湮�ߴ� ǥ��
				visited[newX][newY] = true;
				distance[newX][newY] = distance[X][Y] + 1; //���� ť�� distance���� +1
			}
		}
	}



	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (g[i][j] != 0 && !visited[i][j]) cout << -1 << " ";
			else	cout << distance[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}