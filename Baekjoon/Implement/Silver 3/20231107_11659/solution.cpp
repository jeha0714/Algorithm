#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, M;
	int	*sequence_N;
	int	start, end;
	int	*sequence_sum; // array of Prefix Sum

	/* Set initial input */
	cin >> N >> M;
	sequence_N = new int[N + 1]();
	for (int i = 1; i <= N; i++)
		cin >> sequence_N[i];
	sequence_sum = new int[N + 1]();
	for (int i = 1; i <= N; i++)
		sequence_sum[i] = sequence_N[i] + sequence_sum[i - 1];

	/* Find reuslt in each case */
	for (int nth_test = 1; nth_test <= M; nth_test++)
	{
		cin >> start >> end;
		cout << sequence_sum[end] - sequence_sum[start - 1] << "\n";
	}

	/* Free memory */
	delete[] sequence_N;
	delete[] sequence_sum;

	return (0);
}
