#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int blue = 0, white = 0;

void cutting(int x, int y, int n, vector<vector<int>>& g) {
    bool cut = false; // �߶���ϴ��� 
    int first_color = g[x][y]; // ù��°ĭ�� ��
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (g[i][j] != first_color) { // �߰��� �ٸ����� ������
                cut = true; // �߶����.
                break;
            }
        }
    }

    if (cut) { // �߶���ϴ� �����̸� 
        cutting(x, y, n / 2, g); // ���ʿ� ���� ��Ʈ
        cutting(x, y + n / 2, n / 2, g); //���ʿ� ������ ��Ʈ
        cutting(x + n / 2, y, n / 2, g); // �Ʒ��ʿ� ���� ��Ʈ
        cutting(x + n / 2, y + n / 2, n / 2, g); // �Ʒ��ʿ� ������ ��Ʈ
    }

    else {
        if (first_color == 1) // �Ķ���
            blue++;
        else // ���
            white++;
    }
}


int  main() {

	int n;
	cin >> n;
	vector<vector<int>> g(n,vector<int> (n));
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			g[i][j] = a;
		}
	}

    cutting(0,0,8,g);
    cout <<white<<"\n" << blue;
	return 0;
}