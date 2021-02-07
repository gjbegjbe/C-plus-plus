#include<iostream>
using namespace std;


int main() {
	signed long long x, y;
	char c;
	cin >> c >> c >> x >> c >> c >> c >> y;
	if (x > INT_MAX || x < INT_MIN) {
		cout << -1 << endl;
	}
	else if (y > INT_MAX) {
		cout << -1 << endl;
	}
	else {
		long long square;
		square = pow(x, y);
		if (square > INT_MAX || square < INT_MIN) {
			cout << -1 << endl;
		}
		else {
			cout << square << endl;
		}

	}
	system("pause");
}