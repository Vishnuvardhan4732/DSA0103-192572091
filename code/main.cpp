==============================================================================
                       TASK 1
==============================================================================
#include <iostream>
#include <string>
using namespace std;

enum class Zone { Inner = 1, Middle, Outer };

class FareTable {
public:
    static int baseFarePaise(Zone zone) {
        switch (zone) {
            case Zone::Inner: return 1000;
            case Zone::Middle: return 2000;
            case Zone::Outer: return 3000;
        }
        return -1;
    }
};

class SmartCard {
private:
    long long balancePaise;
public:
    SmartCard(long long balance) : balancePaise(balance) {}
    long long getBalance() const { return balancePaise; }
    bool deductFare(int farePaise) {
        if (farePaise < 0 || balancePaise - farePaise < 5000) return false;
        balancePaise -= farePaise;
        return true;
    }
};

int main() {
    SmartCard card(7000);
    int fare = FareTable::baseFarePaise(Zone::Inner);
    cout << "Base fare: " << fare << " paise\n";
    if (card.deductFare(fare)) cout << "Journey allowed\n";
    else cout << "Journey denied\n";
    cout << "Balance: " << card.getBalance() << " paise\n";
    return 0;
}

==============================================================================
                                   TASK 2
==============================================================================
#include <iostream>
using namespace std;

constexpr int INNER_FARE = 1000;
constexpr int MIDDLE_FARE = 2000;
constexpr int OUTER_FARE = 3000;
constexpr int MIN_BALANCE = 5000;

enum class Zone { Inner = 1, Middle, Outer };

int main() {
    int zone = 2;
    int fare = 0;
    switch (zone) {
        case 1: fare = INNER_FARE; break;
        case 2: fare = MIDDLE_FARE; break;
        case 3: fare = OUTER_FARE; break;
        default: cout << "Invalid zone\n"; return 0;
    }
    cout << "Zone: " << zone << '\n';
    cout << "Fare: " << fare << " paise\n";
    cout << "Minimum balance: " << MIN_BALANCE << " paise\n";
    cout << "Example keyword: int; identifier: fare; operator: =; punctuator: ;\n";
    return 0;
}

==============================================================================
                                TASK 3
==============================================================================
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";

    long long journeys = 3000000LL;
    long long farePaise = 3000LL;
    long long totalPaise = journeys * farePaise;
    double totalRupees = journeys * 30.0;

    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "Total in paise: " << totalPaise << '\n';
    cout << fixed << setprecision(2);
    cout << "Total in rupees: Rs. " << totalRupees << '\n';
    return 0;
}

==============================================================================
                                 TASK 4
==============================================================================
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    double c = a / b;
    double d = static_cast<double>(a) / b;
    cout << c << ' ' << d << '\n';

    char ch = 'A' + 2;
    cout << ch << ' ' << static_cast<int>(ch) + 1 << '\n';

    bool flag = 5;
    cout << flag << ' ';
    cout << boolalpha << flag << '\n';

    unsigned int u = 1;
    int s = -1;
    cout << (s < u ? "s < u" : "s >= u") << '\n';
    return 0;
}

==============================================================================
                              TASK 5
==============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int farePaise = 3000;
    int hour = 9;
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    int totalPaise = farePaise;
    if (peak) totalPaise = totalPaise * 120 / 100;

    cout << "Base fare: Rs. " << farePaise / 100.0 << '\n';
    cout << "Peak hour: " << peak << '\n';
    cout << fixed << setprecision(2);
    cout << "Final fare: Rs. " << totalPaise / 100.0 << '\n';

    int i = 5;
    cout << "Post-increment: " << i++ << '\n';
    cout << "New value: " << i << '\n';
    return 0;
}

==============================================================================
                          TASK 6
==============================================================================
#include <iostream>
using namespace std;

int main() {
    int zone, hour, fare;
    cout << "Enter zone (1-3): ";
    if (!(cin >> zone)) { cout << "Invalid input\n"; return 0; }
    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) { cout << "Invalid input\n"; return 0; }

    switch (zone) {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        default: cout << "Invalid zone\n"; return 0;
    }
    if (hour < 0 || hour > 23) {
        cout << "Invalid hour\n"; return 0;
    }
    if ((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20))
        fare = fare * 120 / 100;

    cout << "Fare: " << fare << " paise\n";
    return 0;
}

==============================================================================
                                TASK 7
==============================================================================
#include <iostream>
using namespace std;

class SmartCard {
private:
    int balancePaise;
public:
    SmartCard(int balance) : balancePaise(balance) {}
    bool canTravel(int farePaise) const {
        return farePaise >= 0 && balancePaise - farePaise >= 5000;
    }
    bool deduct(int farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
    int getBalance() const { return balancePaise; }
};

int main() {
    int balance = 7000, fare = 2000;
    if (balance - fare >= 5000) {
        balance -= fare;
        cout << "Procedural: Journey allowed\n";
    } else cout << "Procedural: Journey denied\n";
    cout << "Procedural balance: " << balance << " paise\n";

    SmartCard card(7000);
    if (card.deduct(2000)) cout << "OOP: Journey allowed\n";
    else cout << "OOP: Journey denied\n";
    cout << "OOP balance: " << card.getBalance() << " paise\n";
    return 0;
}

==============================================================================
                                TASK 8
==============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int zone, hour;
    cout << "Enter zone (1-3): ";
    if (!(cin >> zone)) { cout << "Invalid input\n"; return 0; }

    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) { cout << "Invalid input\n"; return 0; }

    if (zone < 1 || zone > 3) {
        cout << "Value out of range: zone\n"; return 0;
    }
    if (hour < 0 || hour > 23) {
        cout << "Value out of range: hour\n"; return 0;
    }

    cout << setfill('-') << setw(25) << "" << '\n';
    cout << setfill(' ') << left << setw(15) << "Zone" << zone << '\n';
    cout << left << setw(15) << "Hour" << hour << '\n';
    return 0;
}

==============================================================================
                          TASK 9
==============================================================================
#include <iostream>
using namespace std;

int main() {
    int zone, hour;
    long long balancePaise;
    cout << "Enter zone (1-3): ";
    if (!(cin >> zone)) { cout << "Invalid input\n"; return 0; }
    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) { cout << "Invalid input\n"; return 0; }
    cout << "Enter balance in paise: ";
    if (!(cin >> balancePaise) || balancePaise < 0) {
        cout << "Invalid balance\n"; return 0;
    }

    int farePaise;
    switch (zone) {
        case 1: farePaise = 1000; break;
        case 2: farePaise = 2000; break;
        case 3: farePaise = 3000; break;
        default: cout << "Invalid zone\n"; return 0;
    }
    if (hour < 0 || hour > 23) {
        cout << "Invalid hour\n"; return 0;
    }
    if ((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20))
        farePaise = farePaise * 120 / 100;

    cout << "Fare: " << farePaise << " paise\n";
    if (balancePaise - farePaise >= 5000) {
        balancePaise -= farePaise;
        cout << "Journey allowed\n";
        cout << "Remaining balance: " << balancePaise << " paise\n";
    } else {
        cout << "Journey denied\n";
        cout << "Minimum balance of 5000 paise must remain\n";
    }
    return 0;
}

==============================================================================
                          TASK 10
==============================================================================
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    long long journeys[] = {20000LL, 500000LL, 3000000LL};
    long long farePaise = 3000LL;

    cout << "INT_MAX: " << INT_MAX << '\n';
    for (long long count : journeys) {
        long long totalPaise = count * farePaise;
        double totalRupees = count * 30.0;
        cout << "Journeys: " << count << '\n';
        cout << "Integer total: " << totalPaise << " paise\n";
        cout << fixed << setprecision(2);
        cout << "Double total: Rs. " << totalRupees << "\n\n";
    }
    return 0;
}

==============================================================================
                           TASK 11
==============================================================================
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 120;

class SmartCard {
private:
    long long balancePaise;
public:
    SmartCard(long long startingBalance) : balancePaise(startingBalance) {}
    bool recharge(long long amountPaise) {
        if (amountPaise <= 0) return false;
        balancePaise += amountPaise;
        return true;
    }
    bool deductFare(long long farePaise) {
        if (farePaise < 0 || balancePaise - farePaise < MIN_BALANCE_PAISE)
            return false;
        balancePaise -= farePaise;
        return true;
    }
    long long getBalance() const { return balancePaise; }
};

int main() {
    SmartCard card(7000);
    cout << "Starting balance: " << card.getBalance() << " paise\n";
    if (card.recharge(3000)) cout << "Recharge successful\n";
    else cout << "Invalid recharge\n";
    if (card.deductFare(2000)) cout << "Fare deducted\n";
    else cout << "Journey denied\n";
    cout << "Final balance: " << card.getBalance() << " paise\n";
    cout << "Peak fare percentage: " << PEAK_PERCENT << "%\n";
    return 0;
}

==============================================================================
                       TASK 12
==============================================================================
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
