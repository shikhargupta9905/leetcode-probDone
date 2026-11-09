#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));

        int dayOfYear = day;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        return dayOfYear;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, 
                         std::string arriveBob, std::string leaveBob) {
        int aliceStart = dateToDayOfYear(arriveAlice);
        int aliceEnd = dateToDayOfYear(leaveAlice);
        int bobStart = dateToDayOfYear(arriveBob);
        int bobEnd = dateToDayOfYear(leaveBob);

        int overlapStart = std::max(aliceStart, bobStart);
        int overlapEnd = std::min(aliceEnd, bobEnd);

        if (overlapEnd >= overlapStart) {
            return overlapEnd - overlapStart + 1;
        }
        return 0;
    }
};
