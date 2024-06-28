def getCities(cities, road: []):
    city0, city1 = None, None
    for city in cities:
        if city["city"] == road[0]: city0 = city
        elif city["city"] == road[1]: city1 = city
    return city0, city1

class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        maxImportance = 0
        cities = []
        for city in range(0, n):
            cities.append(
                {
                    "city": city,
                    "connections": 0,
                }
            )
        for road in roads:
            city0, city1 = getCities(cities, road)
            city0["connections"] += 1
            city1["connections"] += 1
        
        cities.sort(key=lambda x: x["city"], reverse=True)
        cities.sort(key=lambda x: x["connections"])

        for road in roads:
            city0, city1 = getCities(cities, road)
            maxImportance += cities.index(city0) + cities.index(city1) + 2

        return maxImportance


"""
City 2: 7
City 4: 6
City 1: 5
City 5: 4
City 6: 3
City 3: 2
City 0: 1
"""