#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, b, m;
	cin >> n >> m >> b;
	vector<vector<int>> g(n, vector<int> (m));
	set<int> h; // ��ϳ���, ������ ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			g[i][j] = x;
			h.insert(x);
		}
	}

	int sec_min = INT_MAX, h_max = 0;
	for (int s = 0; s<=256;s++) { // s�� ����
			int build = 0, destroy = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (g[i][j] > s) destroy += g[i][j] - s;//������ �߶󳻾��� -> �κ��� ����
					else if (g[i][j] < s) {
						build += s - g[i][j]; //������ �� ���� -> �κ����� ������
					}
				}
			}
			// �߶󳽰� + �κ��� �ִ��� >= build (������� ��) �϶��� ����
			if (destroy + b >= build) {
				int sec = destroy*2 + build; // ���� ���� �ð�
				sec_min = min(sec_min, sec);
				//cout << build << " " << destroy<<"\n";
				h_max = sec <= sec_min ? s : h_max; //���籸�� �ð��� �� �������� h�� ���Ű���
			}
	}
	cout << sec_min << " " << h_max;

	return 0;
}