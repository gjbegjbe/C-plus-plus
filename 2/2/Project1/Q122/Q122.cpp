#include<iostream>
using namespace std;

int main() {
	long long num[1000];
	long long temp;
	int flag = 0;
	while (cin >> temp) {
		bool isIn = false;
		for (int m = 0; m < flag; m++) {
			if (temp == num[m]) {
				isIn = true;
			}
		}
		if (!isIn) {
			num[flag] = temp;
			flag++;
		}
		
		if (cin.get() == '\n') {
			break;
		}
	}
	for (int i = 0; i < flag - 1; i++) {
		for (int j = 0; j < flag - 1 - i; j++) {
			if (num[j] > num[j + 1]) {
				long long t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}
	int count = 1;
	int max = 1;
	bool inCount = false;
	for (int k = 0; k < flag - 1; k++) {
		if (num[k] == num[k + 1] - 1) {
			count += 1;
		}
		else {
			if (count > max) {
				max = count;
			}
			count = 1;
		}
		if (k == flag - 2) {
			if (count > max) {
				max = count;
			}
		}
	}
	cout << max << endl;
	system("pause");
}