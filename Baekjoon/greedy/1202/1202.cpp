#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int	N, K; // # of jewel and bag
std::vector< std::pair<int, int> >	jewel;
std::vector<int>					bag;

bool	compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.first < b.first);
}

int main(void)
{
	int							w, p, k;
	long long					totalPrice = 0; // store total price of jewels
	std::priority_queue<int>	pq; // descending about price of jewels
	int							iCmp = 0; // index to compare jewel

/* input data */
	std::cin >> N >> K;

	// init jewel
	jewel.reserve(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> w >> p;
		jewel.push_back(std::make_pair(w, p));
	}

	// init bag 
	bag.reserve(K);
	for (int i = 0; i < K; i++)
	{
		std::cin >> k;
		bag.push_back(k);
	}

/* sorting */
	// sort jewel to weight ascending
	std::sort(jewel.begin(), jewel.end(), compare);
	// sort bag to weight ascending
	std::sort(bag.begin(), bag.end(), std::less<int>());

/* solve */
	for (int i = 0; i < K; i++)
	{
		for (int j = iCmp; j < N; j++)
		{
			if (jewel[j].first > bag[i])
				break ;
			pq.push(jewel[j].second);
			iCmp++;
		}
		if (!pq.empty())
		{
			totalPrice += pq.top();
			pq.pop();
		}
	}

/* print result */
	std::cout << totalPrice << "\n";

	return (0);
}
