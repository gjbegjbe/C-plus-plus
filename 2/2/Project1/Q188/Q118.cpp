#include<iostream>
using namespace std;

int main() {
	int num[100];
	for (int i = 0; i < 100; i++) {
		num[i] = 0;
	}
	int flag = 0;
	int temp;
	while (cin >> temp) {
		num[flag] = temp;
		flag++;
		if (cin.get() == '\n') {
			break;
		}
	}
	int maxsize = 0;
	int minheight = 0;
	for (int i = 0; i < flag; i++) {
		minheight = num[i];
		for (int j = i; j < flag; j++) {
			if (minheight > num[j]) {
				minheight = num[j];
			}
			int tempsize = minheight * (j - i + 1);
			if (tempsize > maxsize) {
				maxsize = tempsize;
			}
		}
	}
	cout << maxsize << endl;
	system("pause");
}