#include <vector>
#include <iostream>
#include <deque>

int main() {
	int verticies = 0, temporary = 0;
	std::cin >> verticies;
	std::vector<std::vector<int> > graph(verticies, std::vector<int>(0));
	std::vector<int> distances(verticies, 1e9);
	std::vector<bool> flag(verticies, false);
	std::deque<int> queue{};

	for (int i = 0; i < verticies; i++) {
		for (int j = 0; j < verticies; j++) {
			std::cin >> temporary;
			graph[i].push_back(temporary);
		}
	}
	//this code is unfinished
	queue.push_front(0);
	distances[0] = 0;
	flag[0] = true;
	while (!queue.empty()) {
		temporary = queue.front();
		queue.pop_front();
		for (int i = 0; i < verticies; i++) {
			if (graph[temporary][i] > 0) {
				queue.push_front(i);
				distances[i] = distances[temporary] + 1;
			}
		}
	}

	for (int i = 0; i < verticies; i++) {
		std::cout << distances[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}
