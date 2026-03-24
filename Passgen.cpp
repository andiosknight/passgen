#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
using namespace std;
int ain() {
	setlocale(LC_ALL, "rus");
	mt19937 gen(static_cast<unsigned int>(time(0)));
	int length;
	cout << "Введите длину пароля от 6 до 32 символов: ";
	cin >> length;
	if (length < 6 || length > 32) {
		cout << "Неверные данные" << endl;
		return;
	}
	bool lower, upper, digits, symbols;
	cout << "Использовать строчные? 1 - да, 0 - нет "; cin >> lower;
	cout << "Использовать заглавные? 1 - да, 0 - нет "; cin >> upper;
	cout << "Использовать цифры? 1 - да, 0 - нет "; cin >> digits;
	cout << "Использовать спецсимволы? 1 - да, 0 - нет "; cin >> symbols;
	string chars = "";
	if (lower) chars += "abcdefghijklmnopqrstuvwxyz";
	if (upper) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (digits) chars += "0123456789";
	if (symbols) chars += "!@#$%^&*()-_=+[]{}<>?/";

	if (chars.empty()) {
		cout << "Неверные данные";
		return;
	}
	bool repeat;
	do {
		string password = "";
		uniform_int_distribution<> dist(0, chars.length() - 1);

		for (int i = 0; i < length; i++) {
			password += chars[dist(gen)];
		}
		cout << "Пароль : " << password << endl;
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
		cout << "Сложность: ";
		if (score <= 2) cout << "низкая" << endl;
		else if (score <= 4) cout << "средняя" << endl;
		else cout << "высокая" << endl;
		cout << "Сгенерировать еще? 1 - да, 0 - нет ";
		cin >> repeat;
	} while (repeat);
