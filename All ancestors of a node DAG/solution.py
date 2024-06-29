def createOrUpdate(nodes, edge):
    found = False
    for node in nodes:
        if node["name"] == edge[0]:
            if not edge[1] in node["childs"]: node["childs"].append(edge[1])
            found = True
    if not found: nodes.append({"name": edge[0], "childs": [edge[1]], "parents": []})

def getNode(nodes, name):
    for node in nodes:
        if node["name"] == name:
            return node
    return None

def fathersOf(nodes, target, route):
    if len(nodes) > 10:
        fathersOf(nodes[:len(nodes)//2], target, route)
        fathersOf(nodes[len(nodes)//2:], target, route)

    node = getNode(nodes, target)
    if node != None:
        for parent in node["parents"]:
            if not parent in route: route.append(parent)
            fathersOf(nodes, parent, route)
        return
    else:
        for node in nodes:
            if target in node["childs"]:
                if not node["name"] in route: route.append(node["name"])
                for parent in node["parents"]:
                    if not parent in route: route.append(parent)
                    fathersOf(nodes, parent, route)
    
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        nodes = []
        res = []
        for edge in edges:
            createOrUpdate(nodes, edge)

        for node in nodes:
            for child in node["childs"]:
                childNode = getNode(nodes, child)
                if childNode != None: childNode["parents"].append(node["name"])

        for i in range(n):
            route = []
            fathersOf(nodes, i, route)
            route.sort()
            res.append(route)

        return res
        