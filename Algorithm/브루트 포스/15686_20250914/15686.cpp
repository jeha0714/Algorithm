#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

#define MIN2(x, y) ((x) < (y) ? (x) : (y))
#define INTMAX 2147483647

int 					N, M;
vector<pair<int, int> >	house;
vector<pair<int, int> >	chicken;

int calcDist(const int houseIndex, const int chickenIndex) {
	int	dist = 0;

	dist = abs(house[houseIndex].first - chicken[chickenIndex].first) 
		+ abs(house[houseIndex].second - chicken[chickenIndex].second);

	return (dist);
}

int	calc(const int i) {
	bitset<13>	openChicken(i);
	int			totalDistance = 0;
	int			curDistance;
	int			houseSize = house.size(), chickenSize = chicken.size();
	int			tmp;;

	// 1. find minimum dist each house
	for (int i = 0; i < houseSize; i++) {
		curDistance = INTMAX;
		for (int curChicken = 0; curChicken < chickenSize; curChicken++) {
			if (openChicken[curChicken]) {
				tmp = calcDist(i, curChicken);
				curDistance = MIN2(curDistance, tmp);
			}
		}
		totalDistance += curDistance;
	}

	// 2. return total dist from all house
	return (totalDistance);
}

int	countOne(const int i) {
	bitset<13>	openChicken(i);
	int			count = 0;

	for (int i = 0; i < 13; i++) {
		if (openChicken[i]) count++;
	}

	return (count);
}

int main(void) {
	int	tmp, condition;
	int	result = INTMAX;

	// 1. init input
	cin >> N >> M;
	house.reserve(2 * N);
	chicken.reserve(M);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> tmp;
			if (tmp == 1)
				house.push_back(make_pair(r, c));
			else if (tmp == 2)
				chicken.push_back(make_pair(r, c));
		}
	}

	// 2. find minimum
	condition = pow(2, chicken.size());
	for (int i = 1; i < condition; i++) {
		if (countOne(i) > M)
			continue ;
		tmp = calc(i);
		result = MIN2(result, tmp);
	}

	// 3. print result
	cout << result;

	return (0);
}
