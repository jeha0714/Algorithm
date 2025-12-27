#include <iostream>
#include <vector>

#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define UNDEFINE -1

using namespace std;

int n;
vector< vector<int> >	sticker;
vector< vector<int> >	maxDp;

int dp(int r, int c)
{
	int	max;

/* degenerate case */
	if (c == n - 1)
		return (sticker[r][c]);
	else if (maxDp[r][c] != UNDEFINE)
		return (maxDp[r][c]);

/* select case 	*/
	// if r == 0
		// 1. sticker[0][c] + dp(1, c + 1)
		// 2. dp(0, c + 1)
	// if r == 1
		// 1. sticker[1][c] + dp(0, c + 1)
		// 2. dp(1, c + 1)
	if (r == 0)
		maxDp[r][c] = MAX2(maxDp[r][c], MAX2(sticker[0][c] + dp(1, c + 1), dp(0, c + 1)));
	else
		maxDp[r][c] = MAX2(maxDp[r][c], MAX2(sticker[1][c] + dp(0, c + 1), dp(1, c + 1)));

	return (maxDp[r][c]);
}

int main(void)
{
	int	T;
	int score;

/* init data */
	cin >> T;
	sticker.resize(2);
	maxDp.resize(2);

/* test case */
	for (int t = 0; t < T; t++)
	{
	/* clear data */
		sticker[0].clear();
		sticker[1].clear();
		maxDp[0].clear();
		maxDp[1].clear();

	/* input data */
		cin >> n;

		sticker[0].resize(n);
		sticker[1].resize(n);
		for (int r = 0; r < 2; r++)
		{
			for (int c = 0; c < n; c++)
				cin >> sticker[r][c];
		}

	/* init data */
		maxDp[0].resize(n);
		maxDp[1].resize(n);
		for (int r = 0; r < 2; r++)
		{
			for (int c = 0; c < n; c++)
				maxDp[r][c] = UNDEFINE;
		}

	/* do dp */
		maxDp[0][0] = dp(0, 0);
		maxDp[1][0] = dp(1, 0);

	/* print result */
		if (maxDp[0][0] > maxDp[1][0])
			cout << maxDp[0][0] << "\n";
		else
			cout << maxDp[1][0] << "\n";
	}

	return (0);
}
