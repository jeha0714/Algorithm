#include <iostream>
#include <vector>
#include <queue>

int N; // # of meeting

int main(void)
{
	int	s, e;
	std::priority_queue< std::pair<int, int>
						, std::vector< std::pair<int, int> >
						, std::greater< std::pair<int, int> > >	meetingTime;
	int	lastEndTime = 0;
	int	maxMeeting = 0;

/* input data */
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> s >> e;
		meetingTime.push(std::make_pair(e, s));
	}

/* greedy */
	while (!meetingTime.empty())
	{
		s = meetingTime.top().second;
		e = meetingTime.top().first;
		meetingTime.pop();

		if (lastEndTime <= s)
		{
			lastEndTime = e;
			maxMeeting++;
		}
	}

/* print result */
	std::cout << maxMeeting << "\n";

	return (0);
}
