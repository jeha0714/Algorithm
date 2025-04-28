#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	int N, d, k, c;
	vector<int>	sushiInfo;
	vector<int>	numSushiEaten;
	int tmp;
	int max = 0;
	int curMax = 0;

	/* init input value */
	cin >> N >> d >> k >> c;
	sushiInfo.resize(N);
	for (int i = 0; i < N; i++)
		cin >> sushiInfo[i];

		// init 0 to numSushiEaten 
	numSushiEaten.resize(d + 1);
	for (int i = 0; i <= d ;i++)
		numSushiEaten[i] = 0;

	/* implemnet */

		// eat sushi at least k-th
	for (int i = 0; i < k; i++)
	{
		if (numSushiEaten[sushiInfo[i]] == 0)	
			curMax++;
		numSushiEaten[sushiInfo[i]]++;
	}
	max = curMax;
	if (max == k)
	{
		if (numSushiEaten[c] == 0)
		{
			cout << k + 1 << "\n";
			return (0);
		}
	}

		// eat sushi until k-th index sushi
	for (int i = k; i < N; i++)
	{
		// rm last ate
		if (numSushiEaten[sushiInfo[i - k]] == 1)
			curMax--;
		numSushiEaten[sushiInfo[i - k]]--;

		// rm coupon
		if (numSushiEaten[c] == 1)
		{
			curMax--;
			numSushiEaten[c]--;
		}

		// eat new sushi
		if (numSushiEaten[sushiInfo[i]] == 0)
			curMax++;
		numSushiEaten[sushiInfo[i]]++;

		// add coupon
		if (numSushiEaten[c] == 0)
		{
			curMax++;
			numSushiEaten[c]++;
		}

		// update max value
		max = max < curMax ? curMax : max;
	}

	// return index 0
		// eat until k-1 index sushi
	for (int i = 0; i < k - 1; i++)
	{
		// rm last ate
		if (numSushiEaten[sushiInfo[N - k + i]] == 1)
			curMax--;
		numSushiEaten[sushiInfo[N - k + i]]--;

		// rm coupon
		if (numSushiEaten[c] == 1)
		{
			curMax--;
			numSushiEaten[c]--;
		}

		// eat new sushi
		if (numSushiEaten[sushiInfo[i]] == 0)
			curMax++;
		numSushiEaten[sushiInfo[i]]++;

		// add coupon
		if (numSushiEaten[c] == 0)
		{
			curMax++;
			numSushiEaten[c]++;
		}

		// update max value
		max = max < curMax ? curMax : max;
	}

	// print output
	std::cout << max << "\n";

	return (0);
}