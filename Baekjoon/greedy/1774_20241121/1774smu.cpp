#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/* 자료구조 */
int n, m, o; /* n: vertex의 수, m: edge의 수, o: mcst의 수 */
vector <pair<int, int> > vertices; /* (x, y) --> v */
vector <pair<int, pair<int, int> > > edges; /* weight, v1, v2 */
vector <pair<int, int> > mcst; /* v1, v2 */

/* union-find */
class UnionFind
{
	vector<int> parent, rank;

public:
	UnionFind(int n)
	{
		parent.resize(n + 1);
		rank.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return (parent[x]);
	}

	bool unite(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		if (rootX == rootY)
			return (false);

		if (rank[rootX] < rank[rootY])
			parent[rootX] = rootY;
		else if (rank[rootX] > rank[rootY])
			parent[rootY] = rootX;
		else
		{
			parent[rootY] = rootX;
			rank[rootX]++;
		}
		
		return (true);
	}
};

void	kruskal()
{
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<> >	pq;
	UnionFind uf(n);

	/* edge를 pq에 저장 */
	for (int i = 0; i < m; i++)
	{
		/* 이미 mcst에 포함된 edge는 pq에 저장하지 않음 */
		for (int j = 0; j < o; j++)
		{
			/* edge(u, v) = mcst(u, v) or edge(u, v) = mcst(v, u) --> 통과 */
			if ((edges[i].second.first == mcst[j].first && edges[i].second.second == mcst[j].second)
				|| (edges[i].second.first == mcst[j].second && edges[i].second.second == mcst[j].first))
				continue ;
		}
		pq.push(edges[i]);
	}

	int u, v, w;
	int dist = 0;
	while (!pq.empty() && mcst.size() < n - 1)
	{
		w = pq.top().first;
		u = pq.top().second.first;
		v = pq.top().second.second;
		pq.pop();

		/* cycle이 발생하지 않으면 */
		if (uf.find(u) != uf.find(v))
		{
			mcst.push_back(make_pair(u, v));
			dist += w;
			uf.unite(u, v);
		}
	}

	if (mcst.size() < n - 1)
	{
		printf("No mcst\n");
		return ;
	}

	for (int i = 0; i< mcst.size(); i++)
		printf("<%d %d>\n", mcst[i].first, mcst[i].second);
	printf("%d\n", dist);
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int tc;
	int x, y, w;

	fscanf(fp, "%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		fscanf(fp, "%d %d", &n ,&o);
		/* vertex 읽기 */
		for (int i = 0; i < n; i++)
		{
			fscanf(fp, "%d %d", &x, &y);
			vertices.push_back(make_pair(x, y)); /* v[i] <- (x, y) */
		}
		/* edge 구축: complete graph */
		m = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue ;

				/* vertex distance: Manhattan distance: |x2 - x1| + |y2 - y1| */
				w = abs(vertices[i].first - vertices[j].first) + abs(vertices[i].second - vertices[j].second);
				edges.push_back(make_pair(w, make_pair(i, j)));
				m++;
			}
		}

		/* 초기 mcst 생성 */
		for (int i = 0; i < o; i++)
		{
			fscanf(fp, "%d %d", &x, &y);
			mcst.push_back(make_pair(x, y));
		}

		kruskal();
	}

	fclose(fp);
	return (0);
}