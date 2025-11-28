from typing import Dict, List

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:

        graph: Dict[Number, List[Number]] = {}
        result: Number = 1

        for edge in edges:
            for i in range(2):
                oposite = 1 if i == 0 else 0
                if graph.get(edge[i]) is None:
                    graph[edge[i]] = [edge[oposite]]
                else:
                    graph[edge[i]].append(edge[oposite])

        print(graph)

        for edge in edges:
            both_sides: Number = 0
            for i in range(2):
                connections = graph[edge[i]]
                oposite = 1 if i == 0 else 0
                if len(connections) == 1 and connections[0] == edge[oposite]:
                    if values[edge[i]] % k == 0:
                        both_sides += 1
                    continue
                connections_sum = values[edge[i]]
                for connection in connections:
                    if connection != edge[oposite]:
                        connections_sum += values[connection]
                if connections_sum % k == 0:
                    both_sides += 1
            if both_sides == 2:
                result += 1

        return result
       
if __name__ == "__main__":
    s = Solution()

    result = s.maxKDivisibleComponents(7, [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], [3,0,6,1,5,2,1], 3)
    print("res => ", result)


