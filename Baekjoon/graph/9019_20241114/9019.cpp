#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define NONVISIT 0
#define VISIT 1

int							A, B; // initial number A, final number B
std::vector<std::string>	result(10000);
std::vector<int>			visit(10000);
std::queue<int>				queue;

void	bfs(int n)
{
	int	D, S, L, R; // calculate

	D = 2 * n > 9999 ? 2 * n % 10000 : 2 * n;
	S = n == 0 ? 9999 : n - 1;
	L = n % 1000 * 10 + n / 1000;
	R = n / 10 + n % 10 * 1000;

	// D
	if (visit[D] == NONVISIT)
	{
		queue.push(D);
		visit[D] = visit[n] + 1;
		result[D] = result[n] + "D";
	}

	// S
	if (visit[S] == NONVISIT)
	{
		queue.push(S);
		visit[S] = visit[n] + 1;
		result[S] = result[n] + "S";
	}

	// L
	if (visit[L] == NONVISIT)
	{
		queue.push(L);
		visit[L] = visit[n] + 1;
		result[L] = result[n] + "L";
	}

	// R
	if (visit[R] == NONVISIT)
	{
		queue.push(R);
		visit[R] = visit[n] + 1;
		result[R] = result[n] + "R";
	}
}

int main(void)
{
	int	T; // # of test case	
	int	nPop;

	std::cin >> T;
	while (T--)
	{
		// input data
		std::cin >> A >> B;

		// init visit to NONVISIT
		for (int i = 0; i < 10000; i++)
			visit[i] = NONVISIT;
		
		// push initial number in queue
		queue.push(A);
		visit[A] = VISIT;
		result[A] = "";

		// bfs start
		while (!queue.empty())
		{
			nPop = queue.front(); // get queue front
			queue.pop(); // queue pop

			if (nPop != B)
				bfs(nPop);
			else // print result
				std::cout << result[nPop] << "\n";
		}

	}

	return (0);
}