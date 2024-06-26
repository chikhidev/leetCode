int secondHigher(vector<int> &arr, int pos, int n) {
    if (pos >= n - 1) return -1;
    int maxElement = *std::max_element(arr.begin() + pos + 1, arr.end());
    for (int i = pos + 1; i < n; i++) {
        if (arr[i] == maxElement && arr[i] <= arr[pos]) {
            return i;
        }
    }
    return -1;
}

int spaceIn(vector<int> &arr, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += arr[i];
    }
    return sum;
}

bool allSameLevel(vector<int> &arr, int n) {
    if (n > 2) {
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                return false;
            }
        }
    }
    return true;
}

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int water = 0;
        int i = 0;


        if (allSameLevel(arr, n)) {
            return 0;
        }
        while (i < n) {
            std::cout << "i -> " << i << std::endl;

            int space_between = 0;
            int start = arr[i];
            if (start == 0) {
                i++;
                continue;
            }

            int j = i + 1;
            int SH = secondHigher(arr, i, n);

            if (SH != -1) {
                std::cout << "SH -> " << SH << std::endl;
                j = SH;
                space_between = j - i - 1;
            } else {
                while (j < n && arr[j] < start) {
                    space_between++;
                    j++;
                }
            }
            if (j >= n) {
                i++;
                continue;
            }
            int end = arr[j];
            std::cout << "j -> " << j << std::endl;
            int space = spaceIn(arr, i + 1, j);
            if (start < end) {
                water += (start * space_between) - space;
            } else {
                water += (end * space_between) - space;
            }
            i = j;
        }
        return water;
    }
};