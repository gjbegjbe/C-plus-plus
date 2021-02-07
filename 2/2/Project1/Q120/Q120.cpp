#include<iostream>
using namespace std;

int main() {
	int num[100];
	for (int i = 0; i < 100; i++) {
		num[i] = 0;
	}
	num[0] = 1;
	char ch;
	int temp;
	while (cin.peek()!=']') {
		
		cin >> ch;
		cin >> temp;

		if (temp > 0) {
			num[temp] = 1;
		}
		
	}

	for (int j = 0; j < 100; j++) {
		if (num[j] == 0) {
			cout << j << endl;
			break;
		}
	}
	
	system("pause");
}