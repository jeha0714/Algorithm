#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define NONVISIT 0
#define VISIT 1

int N, M;
vector< vector< pair<int, int> > >	busInfo;
vector< int >		visit;
vector< long long >	minDist;


void	dijkstra(int s, int e)
{
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >	pq;
	int	u, w;
	int	v, dist;

/* set initial minDist and pq */
	for (size_t i = 0; i < busInfo[s].size(); i++)
	{
		u = busInfo[s][i].first;
		w = busInfo[s][i].second;
		if (minDist[u] > w)
			minDist[u] = w;
		pq.push(make_pair(w, u));
	}

/* find minDist */
	while (!pq.empty())
	{
		u = pq.top().second;
		w = pq.top().first;
		pq.pop();

		if (visit[u] == VISIT)
			continue;
		visit[u] = VISIT;

		for (size_t i = 0; i < busInfo[u].size(); i++)
		{
			v = busInfo[u][i].first;
			dist = busInfo[u][i].second;

			if (minDist[v] > minDist[u] + dist)
			{
				minDist[v] = minDist[u] + dist;
				pq.push(make_pair(minDist[v], v));
			}
		}
	}
}

int main(void)
{
	int	u, v, w;
	int	s, e;

/* input data */
	cin >> N >> M;

	busInfo.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		busInfo[u].push_back(make_pair(v, w));
	}
	cin >> s >> e;

/* init data */
	visit.resize(N + 1);
	minDist.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		visit[i] = NONVISIT;
		minDist[i] = LLONG_MAX;
	}
	visit[s] = VISIT;
	minDist[s] = 0;

/* dijkstra algorithm */
	dijkstra(s, e);

/* print result */
	cout << minDist[e] << "\n";

	return (0);
}
