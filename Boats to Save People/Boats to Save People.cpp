#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int numBoats = 0;
        int left = 0;
        int right = people.size() - 1;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            numBoats++;
        }

        return numBoats;
    }
};
