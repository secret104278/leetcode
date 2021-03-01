from collections import defaultdict


class Graph:
    def __init__(self, vertices) -> None:
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)


class UnionFind:
    def __init__(self, g: Graph) -> None:
        self.g = g

        self.parent = list(range(g.V))
        self.rank = [0] * g.V

    def find(self, p) -> int:
        if self.parent[p] != p:
            # path compression
            self.parent[p] = self.find(self.parent[p])

        return self.parent[p]

    def union(self, p, q) -> int:
        if self.rank[p] > self.rank[q]:
            self.parent[q] = p
        elif self.rank[q] > self.rank[p]:
            self.parent[p] = q
        else:
            self.parent[q] = p
            self.rank[p] += 1

    def is_cyclic(self) -> bool:
        for node in list(range(self.g.V)):
            for neibor in self.g.graph[node]:
                if self.find(node) == self.find(neibor):
                    return True
                else:
                    self.union(node, neibor)

        return False


g = Graph(4)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(3, 2)

u = UnionFind(g)
print(u.is_cyclic())
