#include <iostream>

int main(void) {
	int N;

	std::cin >> N;

	for (int i = 1; ; i++) {
		if (i % 2 == 1) {
			if (N - i < 0) {
				std::cout << i - N << "\n";
				break ;
			}
			else
				N -= i;
		}
		else {
			if (N - i < 0) {
				std::cout << "0\n";
				break ;
			}
			else
				N -= i;
		}
	}

	return (0);
}
