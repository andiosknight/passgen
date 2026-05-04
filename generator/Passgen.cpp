#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>


using namespace std;

int main() {
    mt19937 gen(static_cast<unsigned int>(time(0)));

    int length = 12;
    bool lower = true, upper = true, digits = true, symbols = true;

    string chars = "";
    if (lower) chars += "abcdefghijklmnopqrstuvwxyz";
    if (upper) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (digits) chars += "0123456789";
    if (symbols) chars += "!@#$%^&*()-_=+[]{}<>?/";

    if (chars.empty()) {
        cout << "Error: No characters selected" << endl;
        return 0;
    }

    string password = "";
    uniform_int_distribution<> dist(0, chars.length() - 1);

    for (int i = 0; i < length; i++) {
        password += chars[dist(gen)];
    }

    cout << "Generated Password: " << password << endl;

    int score = 0;
    bool haslow = false, hasup = false, hasdig = false, hassym = false;
    for (char c : password) {
        if (islower(c)) haslow = true;
        else if (isupper(c)) hasup = true;
        else if (isdigit(c)) hasdig = true;
        else hassym = true;
    }

    if (password.length() >= 12) score++;
    if (haslow) score++;
    if (hasup) score++;
    if (hasdig) score++;
    if (hassym) score++;

    cout << "Complexity score: " << score << "/5" << endl;
    while (true) {
        std::this_thread::sleep_for(std::chrono::hours(24));
    }
    return 0;
}
