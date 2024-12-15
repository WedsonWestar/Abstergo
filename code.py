from collections import deque
import sys

def main():
    verticies = int(sys.stdin.readline().strip())
    graph = [[] for _ in range(verticies)]
    distances = [int(1e9)] * verticies
    flag = [False] * verticies
    queue = deque()

    for i in range(verticies):
        row = list(map(int, sys.stdin.readline().strip().split()))
        graph[i].extend(row)

    # this code is unfinished
    queue.appendleft(0)
    distances[0] = 0
    flag[0] = True
    while queue:
        temporary = queue.popleft()
        for i in range(verticies):
            if graph[temporary][i] > 0:
                queue.appendleft(i)
                distances[i] = distances[temporary] + 1

    print(' '.join(map(str, distances)))

if __name__ == "__main__":
    main()

