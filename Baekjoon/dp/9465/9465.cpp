#include <iostream>
#include <vector>

#define MAX2(x, y) (x > y ? x : y)
#define MAX3(x, y, z) (MAX2(MAX2(x, y), z))

#define NVM -1
#define	DIAGONAL 0
#define RIGHT 1
#define DOWN 2
#define UP 3

int	n;
std::vector< std::vector<int> >	sticker;

int	dp(int x, int y, int prev)
{
	/* Handle Out Of Bound */
	if (x < 0 || x >= 2 || y < 0 || y >= n)
		return (0);

	// 1. choose (x, y) + dp(x - 1, y - 1) 
	// 2. no choose (x, y)
	// 		a. dp(x, y - 1)
	// 		b. dp(x - 1, y)
	if (prev == NVM)
	{
		if (x == 0)
			return (MAX3(sticker[x][y] + dp(x + 1, y - 1, DIAGONAL), dp(x + 1, y, NVM), dp(x, y - 1, NVM)));
		else //if (x == 1)
			return (MAX3(sticker[x][y] + dp(x - 1, y - 1, DIAGONAL), dp(x - 1, y, NVM), dp(x, y - 1, NVM)));
	}
	else if (prev == DIAGONAL)
	{
		if (x == 0)
			return (MAX2(sticker[x][y] + dp(x + 1, y - 1, DIAGONAL), dp(x, y - 1, 0)));
		else //if (x == 1)
			return (MAX2(sticker[x][y] + dp(x - 1, y - 1, DIAGONAL), dp(x, y - 1, 0)));
	}
	else if (prev == RIGHT)
	{
		if (x == 0)
			return (MAX2(sticker[x][y] + dp(x + 1, y - 1, 0), dp(x, y - 1, 0)));
		else //if (x == 1)
			return (MAX2(sticker[x][y] + dp(x - 1, y - 1, 0), dp(x, y - 1, 0)));
	}
	else
	{
		if (x == 0)
			return (MAX2(sticker[x][y] + dp(x + 1, y - 1, 0), dp(x, y - 1, 0)));
		else //if (x == 1)
			return (MAX2(sticker[x][y] + dp(x - 1, y - 1, 0), dp(x, y - 1, 0)));
	}
}

int main(void)
{
	int T;
	std::cin >> T;

	while (T--)
	{
	/* input data */
		std::cin >> n;

		sticker.resize(2);
		sticker[0].resize(n);
		sticker[1].resize(n);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				std::cin >> sticker[i][j];
		}

	/* print result */
		std::cout << dp(1, n - 1, NVM) << "\n";

	/* clear data */
		sticker[0].clear();
		sticker[1].clear();
	}

	return (0);
}