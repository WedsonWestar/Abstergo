from collections import deque

def main():
    verticies = int(input())
    graph = [[] for _ in range(verticies)]
    distances = [-1] * verticies
    queue = deque()

    for i in range(verticies):
        connections = int(input())
        for j in range(connections):
            temporary = int(input())
            graph[i].append(temporary)

    queue.appendleft(0)
    distances[0] = 0
    while queue:
        temporary = queue.popleft()
        for neighbor in graph[temporary]:
            if distances[neighbor] == -1:
                queue.appendleft(neighbor)
                distances[neighbor] = distances[temporary] + 1

    print(' '.join(map(str, distances)))

if __name__ == "__main__":
    main()
