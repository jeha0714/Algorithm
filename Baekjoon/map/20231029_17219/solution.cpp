#include <iostream>
#include <algorithm> // sort
#include <map> // key:value
#include <string> // string

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, M;
	string site, passwd;
	map<string, string> site_with_passwd;
	string	*sites;
	
	/* Set initial input */
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> site >> passwd;
		site_with_passwd.insert(pair<string, string>(site, passwd));
	}

	sites = new string[M]();
	for (int i = 0; i < M; i++)
		cin >> sites[i];

	/* Find passwd of each site */
	for (int i = 0; i < M; i++)
		cout << site_with_passwd.at(sites[i]) << "\n";

	return (0);
}
