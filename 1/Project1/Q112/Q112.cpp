#include<iostream>
using namespace std;

bool is29(int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else if(year % 100 == 0 && year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int year, month, day;
	char c;
	cin >> year >> c >> month >> c >> day;
	int dayOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is29(year)) {
		dayOfMonth[1] = 29;
	}
	if (day > dayOfMonth[month - 1]) {
		cout << -1 << endl;
	}
	else {
		int dayNo = 0;
		for (int i = 0; i < month - 1; i++) {
			dayNo += dayOfMonth[i];
		}
		dayNo += day;
		cout << dayNo << endl;
	}
	system("pause");
}