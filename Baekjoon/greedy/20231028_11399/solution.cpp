#include <iostream>
#include <algorithm>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int	*P;
	int	min_time;
	
	/* Set initial input */
	cin >> N;
	P = new int[N]();
	for (int i = 0; i < N; i++)
		cin >> P[i];

	/* Sorting ascending */
	sort(P, P + N);

	/* Calculate time */
	min_time = 0;
	for (int i = 0; i < N; i++)
		min_time = min_time + (P[i] * (N - i));
	
	/* Print result */
	cout << min_time << "\n";

	return (0);
}
