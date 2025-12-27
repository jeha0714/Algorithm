#include <iostream>
#include <vector> // vector

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	T, N;
	vector<vector<int> > num_01_fibo(2, vector<int>(2));
	
	/* Set initial input */
	cin >> T;
	num_01_fibo[0][0] = 1;
	num_01_fibo[0][1] = 0;
	num_01_fibo[1][0] = 0;
	num_01_fibo[1][1] = 1;

	/* Find result in each case */
	for (int nth_T = 0; nth_T < T; nth_T++)
	{
		cin >> N;
		if (num_01_fibo.size() - 1 < N)
		{
			for (int i = num_01_fibo.size(); i <= N; i++)
			{
				num_01_fibo.push_back(vector<int>(2, 0));
				num_01_fibo[i][0] = (num_01_fibo[i - 2][0] + num_01_fibo[i - 1][0]);
				num_01_fibo[i][1] = (num_01_fibo[i - 2][1] + num_01_fibo[i - 1][1]);
			}
			cout << num_01_fibo[N][0] << " ";
			cout << num_01_fibo[N][1] << "\n";
		}
		else
		{
			cout << num_01_fibo[N][0] << " ";
			cout << num_01_fibo[N][1] << "\n";
		}
	}

	return (0);
}
