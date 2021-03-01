from collections import defaultdict


class Graph:
    def __init__(self, vertices) -> None:
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def is_cyclic_util(self, v, visited, rec_stack):
        visited[v] = True
        rec_stack[v] = True

        for neibor in self.graph[v]:
            if not visited[neibor]:
                if self.is_cyclic_util(neibor, visited, rec_stack):
                    return True
            elif rec_stack[neibor]:
                return True

        rec_stack[v] = False
        return False

    def is_cyclic(self):
        visited = [False] * self.V

        # 因為是 graph 所以不能單用 visited 來記錄，如果是 tree 就可以
        rec_stack = [False] * self.V

        for node in range(self.V):
            if not visited[node]:
                if self.is_cyclic_util(node, visited, rec_stack):
                    return True

        return False


g = Graph(4)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(3, 2)
print(g.is_cyclic())