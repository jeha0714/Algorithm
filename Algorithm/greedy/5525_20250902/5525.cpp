#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int		N, M;
	string	S;
	int		count = 0;
	int		start = -1;
	int		numO;

	// 1. input
	cin >> N >> M >> S;

	// 2. calculate
	for (int i = 0; i < M; i++) {
		if (start == -1) {
			if (S[i] == 'I')
				start = i;

			continue ;
		}
		else if (!((S[i - 1] == 'I' && S[i] == 'O') || (S[i - 1] == 'O' && S[i] == 'I'))) {
			if (S[i] == 'I') { // O가 와야 하는데 I가 온 경우
				numO = (i - start) / 2;
				if (numO - N + 1 > 0)
					count += (numO - N + 1);
			}
			else { // S[i] == 'O' // I가 와야 하는데 O가 온 경우
				numO = (i - start - 1) / 2;
				if (numO - N + 1 > 0)
					count += (numO - N + 1);
			}

			start = -1;
			i--;
		}
		else if (i == M - 1) {
			if (S[i] == 'I') {
				numO = (i - start + 1) / 2;
				if (numO - N + 1 > 0)
					count += (numO - N + 1);
			}
			else {
				numO = (i - start) / 2;
				if (numO - N + 1 > 0)
					count += (numO - N + 1);
			}
		}
	}

	// 3. output
	cout << count;

	return (0);
}
