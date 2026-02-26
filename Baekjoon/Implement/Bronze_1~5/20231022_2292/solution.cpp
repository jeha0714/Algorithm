#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int	N;
	int	result;
	int	start, end;

	/* Set initial input */
	cin >> N;

	/* Search how many rooms pass by? */
	start = 1;
	end = 1;
	for (int i = 0; ;i++)
	{
		if (start <= N && N <= end)
		{
			result = i + 1;
			break ;
		}
		start += (i * 6);
		end += ((i + 1) * 6);
	}

	/* Print result */
	std::cout << result << "\n";

	return (0);
}
