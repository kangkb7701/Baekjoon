#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> dp(1001);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}
	cout << dp[n - 1];

	return 0;
}