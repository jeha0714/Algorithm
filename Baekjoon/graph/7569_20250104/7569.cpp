#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, H; // width, length, height
vector< vector< vector<int> > >	tomato; // initial tomato info
queue< pair<int, pair<int, int> > > bfsQEven; // bfs queue when even time
queue< pair<int, pair<int, int> > > bfsQOdd; // bfs queue when odd time

// affect adjacent tomato location
int	mH[6] = {0, 0, 0, 0, 1, -1};
int mR[6] = {-1, 0, 1, 0, 0, 0};
int mC[6] = {0, 1, 0, -1, 0, 0};

// total time of ripe tomato
int timeRipe;

int main(void)
{
	int row, col, height;

/* input data */
	cin >> M >> N >> H;

	tomato.resize(H);
	for (int i = 0; i < H; i++)
	{
		tomato[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			tomato[i][j].resize(M);
			for (int k = 0; k < M; k++)
				cin >> tomato[i][j][k];
		}
	}

/* init data */
	// set bfsQ initial value
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 1)
					bfsQEven.push(make_pair(i, make_pair(j, k)));
			}
		}
	}
	// set timeRipe to -1
	timeRipe = -1;

/* do bfs */
	while (!bfsQEven.empty() || !bfsQOdd.empty())
	{
		if (!bfsQEven.empty())
		{
			while (!bfsQEven.empty())
			{
				// pop
				height = bfsQEven.front().first;
				row = bfsQEven.front().second.first;
				col = bfsQEven.front().second.second;
				bfsQEven.pop();

				// add element if condition pass
				for (int i = 0; i < 6; i++)
				{
					if ((0 <= height + mH[i] && height + mH[i] < H)
						&& (0 <= row + mR[i] && row + mR[i] < N)
						&& (0 <= col + mC[i] && col + mC[i] < M)
						&& tomato[height + mH[i]][row + mR[i]][col + mC[i]] == 0)
					{
						tomato[height + mH[i]][row + mR[i]][col + mC[i]] = 1;
						bfsQOdd.push(make_pair(height + mH[i], make_pair(row + mR[i], col + mC[i])));
					}
				}
			}
		}
		else
		{
			while (!bfsQOdd.empty())
			{
				// pop
				height = bfsQOdd.front().first;
				row = bfsQOdd.front().second.first;
				col = bfsQOdd.front().second.second;
				bfsQOdd.pop();

				// add element if condition pass
				for (int i = 0; i < 6; i++)
				{
					if ((0 <= height + mH[i] && height + mH[i] < H)
						&& (0 <= row + mR[i] && row + mR[i] < N)
						&& (0 <= col + mC[i] && col + mC[i] < M)
						&& tomato[height + mH[i]][row + mR[i]][col + mC[i]] == 0)
					{
						tomato[height + mH[i]][row + mR[i]][col + mC[i]] = 1;
						bfsQEven.push(make_pair(height + mH[i], make_pair(row + mR[i], col + mC[i])));
					}
				}
			}
		}
		timeRipe++;
	}

/* print result */
	// print time if all tomato riped
	// print -1 even if one tomato not riped
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					cout << "-1\n";
					return (0);
				}
			}
		}
	}

	cout << timeRipe << "\n";
	return (0);
}
