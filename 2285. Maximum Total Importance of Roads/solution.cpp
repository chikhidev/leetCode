struct _City {
    int city;
    int connections;
    _City(int c) : city(c), connections(0) {}
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cities(n, 0);
        vector<_City> citiesCopy(n, _City(0));
        long roadsSize = roads.size();

        for (int i = 0; i < n; i++) {
            citiesCopy[i].city = i;
        }

        for (int i = 0; i < roadsSize; i++) {;
            citiesCopy[roads[i][0]].connections++;
            citiesCopy[roads[i][1]].connections++;
        }
        std::sort(citiesCopy.begin(), citiesCopy.end(), [](_City &a, _City &b) {
            return a.connections < b.connections;
        });
        for (int i = 0; i < n; i++) {
            cities[citiesCopy[i].city] = i + 1;
        }
        citiesCopy.clear();
        
        long long maximumImportance = 0;
        for (int i = 0; i < roadsSize; i++) {
            maximumImportance += cities[roads[i][0]] + cities[roads[i][1]];
        }

        return maximumImportance;
    }
};