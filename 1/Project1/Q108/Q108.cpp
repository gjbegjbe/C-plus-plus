#include<iostream>
using namespace std;

bool isPrime(int i) {
	if (i == 1) {
		return false;
	}
	else {
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int x, y;
	char c;
	cin >> c >> x >> y >> c;
	
	int sum = 0;
	for (int i = x; i <= y; i++){
		if (isPrime(i)) {
			sum += i;
		}
	}

	cout << sum << endl;

	system("pause");
}