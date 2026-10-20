#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    long long balanceRupees;
    int zone, hour, day, pass1, pass2;

    cout << "Enter balance in rupees: ";
    if (!(cin >> balanceRupees)) { cout << "Invalid input\n"; return 0; }
    cout << "Select zone (1=Zone1, 2=Zone2, 3=Zone3, 4=Airport): ";
    if (!(cin >> zone)) { cout << "Invalid input\n"; return 0; }
    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) { cout << "Invalid input\n"; return 0; }
    cout << "Enter day (0=Weekday, 1=Weekend): ";
    if (!(cin >> day)) { cout << "Invalid input\n"; return 0; }
    cout << "Select first pass zone (1-4): ";
    if (!(cin >> pass1)) { cout << "Invalid input\n"; return 0; }
    cout << "Select second pass zone (1-4): ";
    if (!(cin >> pass2)) { cout << "Invalid input\n"; return 0; }

    if (balanceRupees < 0 || balanceRupees > numeric_limits<long long>::max() / 100 ||
        zone < 1 || zone > 4 ||
        hour < 0 || hour > 23 || day < 0 || day > 1 ||
        pass1 < 1 || pass1 > 4 || pass2 < 1 || pass2 > 4 ||
        pass1 == pass2) {
        cout << "Invalid input\n";
        return 0;
    }

    const int faresPaise[] = {0, 1000, 2000, 3000, 6000};
    long long farePaise = faresPaise[zone];

    if (zone == pass1 || zone == pass2) {
        farePaise = 0;
    } else if (day == 1) {
        farePaise = farePaise * 90 / 100;
    } else if ((hour >= 8 && hour < 10) ||
               (hour >= 17 && hour < 20)) {
        farePaise = farePaise * 120 / 100;
    }

    long long balancePaise = balanceRupees * 100;
    cout << fixed << setprecision(2);
    cout << "Fare: Rs. " << farePaise / 100.0 << '\n';

    if (balancePaise - farePaise >= 5000) {
        balancePaise -= farePaise;
        cout << "Journey allowed\n";
        cout << "Remaining balance: Rs. " << balancePaise / 100.0 << '\n';
    } else {
        cout << "Journey denied: Minimum Rs. 50 must remain\n";
    }
    return 0;
}
