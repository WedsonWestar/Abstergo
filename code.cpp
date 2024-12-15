#include <vector>
#include <iostream>
#include <deque>

int main() {
	int verticies = 0, connections = 0, temporary = 0;
	std::cin >> verticies;
	std::vector<std::vector<int> > graph(verticies, std::vector<int>(0));
	std::vector<int> distances(verticies, -1);
	std::deque<int> queue{};

	for (int i = 0; i < verticies; i++) {
		std::cin >> connections;
		for (int j = 0; j < connections; j++) {
			std::cin >> temporary;
			graph[i].push_back(temporary);
		}
	}

	queue.push_back(0);
	distances[0] = 0;
	while (!queue.empty()) {
		temporary = queue.front();
		queue.pop_front();
		for (int i = 0; i < graph[temporary].size(); i++) {
			if (distances[graph[temporary][i]] == -1) {
				queue.push_back(graph[temporary][i]);
				distances[graph[temporary][i]] = distances[temporary] + 1;
			}
		}
	}

	for (int i = 0; i < verticies; i++) {
		std::cout << distances[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}
