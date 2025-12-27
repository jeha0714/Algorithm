#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int	N, M, W;

std::vector< std::vector<std::pair<int, int> > >	path;
std::vector<int>									dist;

// sort compare to ascending
bool	greater(const std::pair<int, int> a, const std::pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	else
		return (a.first < b.first);
}

std::string	solve()
{
	// init dist to infinite
	dist.reserve(N + 1);
	for (int i = 1; i <= N; i++)
		dist[i] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < path[j].size(); k++)
			{
				int	v = path[j][k].first;
				int	u = path[j][k].second;
				if (dist[v] > dist[j] + u)
					dist[v] = dist[j] + u;
			}
		}
	}

	// find negative cycle
	for (int j = 1; j <= N; j++)
	{
		for (int k = 0; k < path[j].size(); k++)
		{
			int	v = path[j][k].first;
			int	u = path[j][k].second;
			if (dist[v] > dist[j] + u) // negative cycle exist
				return ("YES");
		}
	}

	return ("NO");
}

int main(void)
{
	int	TC; // # of test case
	int	S, E, T;

	// input data
	std::cin >> TC;

	while (TC--)
	{
		// input data
		std::cin >> N >> M >> W;

		// init road
		path.reserve(N + 1);
		for (int i = 0; i < M; i++)
		{
			std::cin >> S >> E >> T;
			if (S == E)
				path[S].push_back(std::make_pair(E, T));
			else
			{
				path[S].push_back(std::make_pair(E, T));
				path[E].push_back(std::make_pair(S, T));
			}
		}

		// init wormhole
		for (int i = 0; i < W; i++)
		{
			std::cin >> S >> E >> T;
			path[S].push_back(std::make_pair(E, -T));
		}

		// sort path
		for (int i = 0; i <= N; i++)
			std::sort(path[i].begin(), path[i].end(), greater);

		// print result
		std::cout << solve() << "\n";

		// clear path 
		for (int i = 0; i <= N; i++)
			path[i].clear();
		path.clear();
	}

	return (0);
}