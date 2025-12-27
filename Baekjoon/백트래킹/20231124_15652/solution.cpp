#include <iostream>

using namespace std;

/* Backtracking */
void	print_sequence(int N, int M, int *sequence, int i_sequence)
{
	// Print sequence if sequence set full
	if (i_sequence >= M)
	{
		for (int i = 0; i < M; i++)
			cout << sequence[i] << " ";
		cout << "\n";
		return ;
	}
	// Set sequence
	else
	{
		// Set first index in sequence to 1 ~ N
		if (i_sequence == 0)
		{
			for (int n = 1; n <= N; n++)
			{
				sequence[i_sequence] = n;
				print_sequence(N, M, sequence, i_sequence + 1);
			}
		}
		// Set current index to last number of sequence ~ N
		else
		{
			for (int n = sequence[i_sequence - 1]; n <= N; n++)
			{
				sequence[i_sequence] = n;
				print_sequence(N, M, sequence, i_sequence + 1);
			}
		}
	}
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, M;
	int	*sequence;

	/* Set initial input */
	cin >> N >> M;
	sequence = new int[M]();

	/* Print backtracking! */
	print_sequence(N, M, sequence, 0);

	/* Free memory */
	delete[] sequence;

	return (0);
}