#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	switch (n) {
	case 1:
		cout << 1 << endl;
		break;
	case 2:
		cout << 2 << endl;
		break;
	case 3:
		cout << 6 << endl;
		break;
	case 4:
		cout << 7 << endl;
		break;
	default:
		if (n % 4 == 1 || n % 4 == 2) {
			cout << n + 2 << endl;
		}
		else if (n % 4 == 3) {
			cout << n - 1 << endl;
		}
		else {
			cout << n + 1 << endl;
		}

	}
	system("pause");
}