#include <iostream>
#include <vector>

#define NONVISIT 0
#define VISIT 1

std::vector< std::vector<int> >	path; // adjacent node info
std::vector<int>				visit; // visit info
int	nLeaf = 0; // # of leaf node
int	root; // # of root node

void	dfs(int n)
{
	int	nPath = path[n].size();

	visit[n] = VISIT; // set visit

// root dont have parent
// add # of Leaf node value when dont have child
	if ((n == root && nPath == 0) || (n != root && nPath == 1))
	{
		nLeaf++;
		return ;
	}

// dfs for adjacent node
	for (int i = 0; i < nPath; i++)
	{
		if (visit[path[n][i]] == NONVISIT)
			dfs(path[n][i]);
	}

}

int main(void)
{
	int	N; // # of node
	int	n;
	int	delNode; // # of delete node

/* input data */
	std::cin >> N;

	path.reserve(N); // reserve capacity of path vector
	for (int i = 0; i < N; i++)
	{
		std::cin >> n;
		if (n == -1)
		{
			root = i; // init root node
			continue;
		}

		// add path each other
		path[i].push_back(n);
		path[n].push_back(i);
	}

	std::cin >> delNode;

// init visit to NONVISIT
	visit.reserve(N);
	for (int i = 0; i < N; i++)
		visit[i] = NONVISIT;

// handle delete node's path
	for (int i = 0; i < path[delNode].size(); i++)
	{
		n = path[delNode][i]; // n is " delNode's adjacent node "
		for (int j = 0; j < path[n].size(); j++)
		{
			if (path[n][j] == delNode)
			{
				path[n].erase(path[n].begin() + j);
				j--; // decrease j because delete node at upside
			}
		}
	}
	visit[delNode] = VISIT; // set delete node to VISIT

	// dfs start
	if (visit[root] == NONVISIT) // this condition need for when delete node is root
		dfs(root);

	// print # of leaf node
	std::cout << nLeaf << "\n";

	return (0);
}