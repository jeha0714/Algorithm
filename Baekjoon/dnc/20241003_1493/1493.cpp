#include <iostream>
#include <cmath>

int l, w, h;
int cube[20];

void	dnc(int, int, int);
int		findMin(int, int, int);

void	dnc(int cL, int cW, int cH)
{
	// 1. degenerate case
	if (cL <= 0 || cW <= 0 || cH <= 0)
		return ;

	// 2. divide
	int min3 = findMin(cL, cW, cH);
	int t;

	t = log2(min3);
	if (t > 19)
		t = 19;
	for (; t >= 0; t--)	
	{
		if (cube[t] >= 1)
			break ;
	}

	if (t < 0)
	{
		std::cout << -1 << "\n";
		exit (0);
	}

	cube[t] -= 1;
	t = pow(2, t);
	dnc(cL, cW - t, cH);
	dnc(cL- t, t, cH);
	dnc(t, t, cH - t);

	// 3. combine
}

int	findMin(int cL, int cW, int cH)
{
	if (cL <= cW && cL <= cH)
		return (cL);
	else if (cW <= cL && cW <= cH)
		return (cW);
	else if (cH <= cL && cH <= cW)
		return (cH);
}

int main(void)
{
	int nType;
	int size, nCube;
	int total = 0;
	int	remain = 0;

	std::cin >> l >> w >> h;
	for (int i = 0; i < 20; i++)
		cube[i] = 0;

	std::cin >> nType;
	for (int i = 0; i < nType; i++)
	{
		std::cin >> size >> nCube;
		cube[size] = nCube;
		total += nCube;
	}

	dnc(l, w, h);

	for (int i = 0; i < 20; i++)
		remain += cube[i];

	std::cout << total - remain << "\n";

	return (0);
}
