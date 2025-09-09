#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string	s1, s2;
	int		len1, len2;
	vector<vector<int> >	dp;

	// 1. init
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
	dp.resize(len1);
	for (int i1 = 0; i1 < len1; i1++)
		dp[i1].resize(len2);

	
	// 2. calculate max length
	for (int i1 = 0; i1 < len1; i1++) {
		for (int i2 = 0; i2 < len2; i2++) {
			if (s1[i1] == s2[i2]) {
				if (i1 == 0 || i2 == 0)
					dp[i1][i2] = 1;
				else
					dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
			}
			else { // s1[i1] != s2[i2]
				if (i1 == 0) {
					if (i2 == 0)
						dp[i1][i2] = 0;
					else
						dp[i1][i2] = dp[i1][i2 - 1];
				}
				else if (i2 == 0)
					dp[i1][i2] = dp[i1 - 1][i2];
				else
					dp[i1][i2] = dp[i1 - 1][i2] > dp[i1][i2 - 1] ? dp[i1 - 1][i2] : dp[i1][i2 - 1];
			}
			//cout << i1 << " " << i2 << "=" << dp[i1][i2] << "\n";
		}
	}

	// 3. print result
	cout << dp[len1 - 1][len2 - 1];

	return (0);
}
