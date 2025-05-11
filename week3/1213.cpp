#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int alphabet[26];

int main() {
    string name;
    cin >> name;

    for (int i = 0; i < name.size(); i++)
        alphabet[name[i] - 'A']++;

    int err = 0;
    int mid_index = -1;

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0) {
            if (alphabet[i] % 2 == 1) {
                mid_index = i;
                alphabet[i]--;
                err++;
            }
        }
    }
    // Ȧ���� ������ ���ĺ��� 2�� �̻��̸� ���� �� ����.
    if (err > 1) cout<<"I'm Sorry Hansoo";
    else {
        string ans = "";
        string temp = "";
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] > 0) {
                for (int j = 0; j < alphabet[i] / 2; j++) {
                    ans += i + 'A';
                }
            }
        }
        temp = ans;
        reverse(temp.begin(), temp.end());
        if (mid_index != -1) {
            ans += mid_index + 'A';
        }
        ans += temp;
        cout << ans << '\n';
    }

	return 0;
}