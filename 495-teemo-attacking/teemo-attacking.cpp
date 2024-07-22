#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = 0;

        // Iterate through each attack time except the last one
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            int timeDiff = timeSeries[i + 1] - timeSeries[i]; // Calculate the time difference to the next attack

            // Add the minimum of the time difference and the poison duration to the total time
            time += (timeDiff < duration) ? timeDiff : duration;
        }

        // Add the duration for the last attack
        if (!timeSeries.empty()) {
            time += duration;
        }

        return time;
    }
};
