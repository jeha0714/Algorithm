#include <iostream>
#include <cmath> // pow

using namespace std;

long long	nth_invite;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long N, r, c;

	/* Set initial input */
	cin >> N >> r >> c;
	N = (long long)pow(2, N);
	r++; c++;

	/* Find n of nth_invite with given location */
	for (; N > 0; N /= 2)
	{
		if (r <= N / 2 && c <= N / 2)
			continue ;
		else if (r <= N / 2 && c > N / 2)
			nth_invite += ((N / 2) * (N / 2));
		else if (r > N / 2 && c <= N / 2)
			nth_invite += ((N / 2) * (N / 2) * 2);
		else if (r > N / 2 && c > N / 2)
			nth_invite += ((N / 2) * (N / 2) * 3);
		if (r > N / 2)
			r -= (N / 2);
		if (c > N / 2)
			c -= (N / 2);
	}

	/* Print result */
	cout << nth_invite << "\n";

	return (0);
}