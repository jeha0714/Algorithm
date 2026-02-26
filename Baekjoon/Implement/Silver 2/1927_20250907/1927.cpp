#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int					N, tmp;
	priority_queue<int, vector<int>, greater<int> > pq;

	// 1. init N
	cin >> N;

	// 2. operator
	while (N--) {
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}

	return (0);
}
