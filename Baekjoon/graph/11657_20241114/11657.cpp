#include <iostream>
#include <vector>
#include <algorithm>

int	N, M; // # of city N, # of bus path M;
std::vector< std::vector<std::pair<int, int> > >	busInfo; // bus path info
std::vector<long long>	minTime; // min time about city 1 to others

/* sort ascending functino */
bool	ascending(const std::pair<int, int> a, const std::pair<int, int> b)
{
	return (a.first < b.first);
}

int main(void)
{
	int	A, B, C; // bus info

	// input data
	std::cin >> N >> M;

	busInfo.reserve(N + 1);
	for (int i = 0; i < M; i++)
	{
		std::cin >> A >> B >> C;
		busInfo[A].push_back(std::make_pair(B, C));
	}

	// sort busInfo
	for (int i = 1; i <= N; i++)
		std::sort(busInfo[i].begin(), busInfo[i].end(), ascending);

	// init minTime
	minTime.reserve(N + 1);
	minTime[1] = 0;
	for (int i = 2; i <= N; i++)
		minTime[i] = INT64_MAX;
	
	// bellman ford algorithm
	for (int i = 1; i < N; i++)
	{
		for (int curr = 1; curr <= N; curr++)
		{
			for (size_t j = 0; j < busInfo[curr].size(); j++)
			{
				int	dest = busInfo[curr][j].first;
				int	time = busInfo[curr][j].second;
				if (minTime[curr] != INT64_MAX && minTime[dest] > minTime[curr] + time)
					minTime[dest] = minTime[curr] + time;
			}
		}
	}

	// find negative cycle
	for (int curr = 1; curr <= N; curr++)
	{
		for (size_t j = 0; j < busInfo[curr].size(); j++)
		{
			int	dest = busInfo[curr][j].first;
			int	time = busInfo[curr][j].second;
			if (minTime[curr] != INT64_MAX && minTime[dest] > minTime[curr] + time)
			{
				std::cout << -1 << "\n";
				return (0);
			}
		}
	}

	// print result
	for (int i = 2; i <= N; i++)
	{
		if (minTime[i] == INT64_MAX)
			std::cout << -1 << "\n";
		else
			std::cout << minTime[i] << "\n";
	}

	return (0);
}
