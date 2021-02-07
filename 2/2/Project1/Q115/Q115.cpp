#include<iostream>
using namespace std;

int main() {
	int num[1000];
	for (int i = 0; i < 1000; i++) {
		num[i] = 0;
	}
	int temp;
	int flag = 0;
	while (cin >> temp) {
		
		bool isIn = false;
		for (int i = 0; i < 1000; i++) {
			if (num[i] == temp) {
				isIn = true;
				break;
			}
		}
		if (!isIn) {
			//cout << temp;
			num[flag] = temp;
			flag++;
		}
		if (cin.get() == '\n') { break; }
	}
	for (int j = 0; j < flag; j++) {
		cout << num[j];
		if (j != flag - 1) {
			cout << ' ';
		}
		else {
			cout << endl;
		}
	}
	
	
	system("pause");
}