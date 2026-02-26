#include <iostream>
#include <vector> // vector
#include <string> // string
#include <algorithm> // stable_sort

using namespace std;

/* Function Compare sort*/
static int	compare(pair<int, string> a, pair<int, string> b)
{
	return (a.first < b.first);
}

/* Main */
int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int	N;
	int	age;
	string name;
	vector <pair<int, string> > info;

	/* Set initial input */
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		info.push_back(pair<int, string>(age, name));
	}

	/* Sorting */
	stable_sort(info.begin(), info.end(), compare);

	/* Print result */
	for (int i = 0; i < N; i++)
		cout << info[i].first << " " << info[i].second << "\n";

	return (0);
}
