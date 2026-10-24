#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
private:
    short unsigned int dateMonthToDays(int date, int month) {
        const size_t monthIndex = month - 1;

        unsigned int days = 0;

        for (size_t i = 0; i < monthIndex; i++) {
            days += monthDays[i];
        }

        return days + date;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const int aliceArrDate = stoi(arriveAlice.substr(3));
        const int aliceDepDate = stoi(leaveAlice.substr(3));
        const int aliceArrMonth = stoi(arriveAlice.substr(0,2));
        const int aliceDepMonth = stoi(leaveAlice.substr(0,2));

        const int aliceArrDay = dateMonthToDays(aliceArrDate, aliceArrMonth);
        const int aliceDepDay = dateMonthToDays(aliceDepDate, aliceDepMonth);

        const int bobArrDate = stoi(arriveBob.substr(3));
        const int bobDepDate = stoi(leaveBob.substr(3));
        const int bobArrMonth = stoi(arriveBob.substr(0,2));
        const int bobDepMonth = stoi(leaveBob.substr(0,2));

        const int bobArrDay = dateMonthToDays(bobArrDate, bobArrMonth);
        const int bobDepDay = dateMonthToDays(bobDepDate, bobDepMonth);

        // The later start date
        const int start = max(aliceArrDay, bobArrDay);
        // The earlier end date
        const int end = min(aliceDepDay, bobDepDay);

        // +1 to cover the inclusiveness nature i.e. arrival and departure dates are inclusive.
        return max(0, end - start + 1);
    }
};
