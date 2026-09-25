#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void addTime(int h, int m, int s) {
        seconds += s;
        minutes += m + seconds / 60;
        seconds %= 60;

        hours += h + minutes / 60;
        minutes %= 60;

        hours %= 24;
    }

    void showTime() {
        cout << setfill('0')
             << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
};

int main() {
    int hours, minutes, seconds;

    cout << "Enter hour: ";
    cin >> hours;

    cout << "Enter minutes: ";
    cin >> minutes;

    cout << "Enter seconds: ";
    cin >> seconds;

    Time currentTime(hours, minutes, seconds);

    currentTime.addTime(2, 10, 20);

    cout << "Time after 2 hours, 10 minutes and 20 seconds: ";
    currentTime.showTime();

    return 0;
}