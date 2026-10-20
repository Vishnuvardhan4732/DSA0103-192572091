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
