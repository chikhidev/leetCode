from typing import List

def create_or_update(nodes, edge):
    if edge[0] not in nodes:
        nodes[edge[0]] = {"name": edge[0], "childs": [], "parents": []}
    if edge[1] not in nodes:
        nodes[edge[1]] = {"name": edge[1], "childs": [], "parents": []}
    if edge[1] not in nodes[edge[0]]["childs"]: nodes[edge[0]]["childs"].append(edge[1])
    if edge[0] not in nodes[edge[1]]["parents"]: nodes[edge[1]]["parents"].append(edge[0])

def fathers_of(nodes, target, route):
    if target in nodes:
        for parent in nodes[target]["parents"]:
            if parent not in route:
                if parent not in route: route.append(parent)
                fathers_of(nodes, parent, route)
    return route

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        nodes = {}
        for edge in edges:
            create_or_update(nodes, edge)

        res = []
        for i in range(n):
            route = []
            fathers_of(nodes, i, route)
            res.append(sorted(route))

        return res
