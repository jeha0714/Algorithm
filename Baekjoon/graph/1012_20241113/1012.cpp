#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define NONVISIT 0
#define VISIT 1

int	T; // # of test case
std::vector< std::pair<int, int> >	loc;
std::vector< std::vector<int> >		visit;
std::queue< std::pair<int, int> >	queue;

bool	compare(const std::pair<int, int> a, const std::pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	else
		return (a.first < b.first);
}

void	bfs(int x, int y)
{
	// set location to visit
	visit[x][y] = VISIT;

	// add queue to adjacent napa cabbage
	if (std::binary_search(loc.begin(), loc.end(), std::make_pair(x - 1, y)))
		queue.push(std::make_pair(x - 1, y));

	if (std::binary_search(loc.begin(), loc.end(), std::make_pair(x + 1, y)))
		queue.push(std::make_pair(x + 1, y));

	if (std::binary_search(loc.begin(), loc.end(), std::make_pair(x, y - 1)))
		queue.push(std::make_pair(x, y - 1));

	if (std::binary_search(loc.begin(), loc.end(), std::make_pair(x, y + 1)))
		queue.push(std::make_pair(x, y + 1));
}

int main(void)
{
	int	M, N; // field size M * N
	int	K; // # of napa cabbage location
	int	x, y; // x, y location of napa cabbage
	int	nEarthworm = 0;

	std::cin >> T;

	while (T--)
	{
		// input data
		std::cin >> M >> N >> K;
		loc.reserve(K);
		for (int i = 0; i < K; i++)
		{
			std::cin >> y >> x;
			loc.push_back(std::make_pair(x, y));
		}

		// sort loc
		std::sort(loc.begin(), loc.end(), compare);

		// init visit size and set 0(NONVISIT)
		visit.reserve(N);
		for (int i = 0; i < N; i++)
		{
			visit[i].reserve(M);
			for (int j = 0; j < M; j++)
				visit[i][j] = NONVISIT;
		}

		int	n = loc.size();
		for (int i = 0; i < n; i++)
		{
			// insert location to queue if nonVisit
			if (visit[loc[i].first][loc[i].second] == NONVISIT)
				queue.push(std::make_pair(loc[i].first, loc[i].second));
			else
				continue;

			// bfs start
			while (1)
			{
				// break if queue empty
				if (queue.empty())
					break ;

				// get queue front
				x = queue.front().first;
				y = queue.front().second;
				// queue pop
				queue.pop();

				if (visit[x][y] == NONVISIT)
					bfs(x, y);
			}

			nEarthworm++;
		}

		// print result
		std::cout << nEarthworm << "\n";

		// clear info
		loc.clear();
		for (int i = 0; i < N; i++)
			visit[i].clear();
		visit.clear();
		nEarthworm = 0;
	}

	return (0);
}
