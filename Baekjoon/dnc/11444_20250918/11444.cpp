#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MOD 1000000007

int main(void) {
	long long			n;
	vector<long long>	def{1, 1, 1, 0};
	vector<long long>	tmp1, tmp2;
	vector<long long>	result;

	// 1. init input
	cin >> n;
	if (n == 0) { // 나중에 지워보기
		cout << 1;
		return (0);
	}
	if (n <= 2) {
		cout << 1;
		return (0);
	}
	n -= 2;
	result = def;

	// 2. calculate
	while (n > 0) {
		tmp1 = def;
		tmp2 = def;
		for (unsigned long long i = 1; ; i = i << 1) {
			if (i <= n && n < (i << 1)) {
				tmp2 = result;
				result[0] = ((tmp2[0] * tmp1[0]) % MOD + (tmp2[1] * tmp1[2]) % MOD) % MOD;
				result[1] = ((tmp2[0] * tmp1[1]) % MOD + (tmp2[1] * tmp1[3]) % MOD) % MOD;
				result[2] = ((tmp2[0] * tmp1[2]) % MOD + (tmp2[2] * tmp1[3]) % MOD) % MOD;
				result[3] = ((tmp2[1] * tmp1[2]) % MOD + (tmp2[3] * tmp1[3]) % MOD) % MOD;
				n -= i;
				break ;
			}
			tmp1[0] = ((tmp2[0] * tmp2[0]) % MOD + (tmp2[1] * tmp2[2]) % MOD) % MOD;
			tmp1[1] = ((tmp2[0] * tmp2[1]) % MOD + (tmp2[1] * tmp2[3]) % MOD) % MOD;
			tmp1[2] = ((tmp2[0] * tmp2[2]) % MOD + (tmp2[2] * tmp2[3]) % MOD) % MOD;
			tmp1[3] = ((tmp2[1] * tmp2[2]) % MOD + (tmp2[3] * tmp2[3]) % MOD) % MOD;
			tmp2 = tmp1;
		}
	}

	// 3. print result
	cout << (result[0]) % MOD;

	return (0);
}
