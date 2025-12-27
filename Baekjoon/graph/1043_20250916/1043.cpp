#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NONVISIT 0
#define VISIT 1
#define NONDIFFUSE 0
#define DIFFUSE 1

int N, M;
int	numTruth;
vector<int>	visits;
vector<vector<int> >	pplToParty;
vector<vector<int> >	partyToPpl;
queue<int>	q;
int	result = 0;

int main(void) {
	int	numPerson;

	// 1. init input
		// N & M
	cin >> N >> M;
		// truth ppl info
	cin >> numTruth;
	for (int i = 0; i < numTruth; i++) {
		cin >> numPerson;
		q.push(numPerson);
	}
		// ppl & party info
	pplToParty.resize(N + 1);
	partyToPpl.resize(M);
	for (int curPartyIndex = 0; curPartyIndex < M; curPartyIndex++) {
		cin >> numPerson;
		partyToPpl.reserve(numPerson);
		for (int j = numPerson; j > 0; j--) {
			cin >> numPerson;
			partyToPpl[curPartyIndex].push_back(numPerson);
			pplToParty[numPerson].push_back(curPartyIndex);
		}
	}

		// etc
	visits.resize(N + 1);
	for (int i = 1; i <= N; i++)
		visits[i] = NONVISIT;

	// 2. find ppl that don't know secret
	while (!q.empty()) {
		numPerson = q.front();
		q.pop();

		if (visits[numPerson] == VISIT)
			continue ;

		visits[numPerson] = VISIT;
		for (int i = 0; i < pplToParty[numPerson].size(); i++) {
			int partyIndex = pplToParty[numPerson][i];
			for (int personIndex = 0; personIndex < partyToPpl[partyIndex].size(); personIndex++) {
				q.push(partyToPpl[partyIndex][personIndex]);
			}
		}
	}

	// 3. calculate result
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < partyToPpl[i].size(); j++) {
			if (visits[partyToPpl[i][j]] == VISIT)
				break ;
			else if (j == partyToPpl[i].size() - 1)
				result++;
		}
	}

	// 4. print result
	cout << result;

	return (0);
}
