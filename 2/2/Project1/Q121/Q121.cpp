#include<iostream>
using namespace std;

int main() {
	char c[1000];
	int flag = 0;
	/*while (true) {
		cin >> c[flag];
		flag++;
		if (cin.peek() == '\n') {
			break;
		}
	}*/
	cin.get(c, 1000);

	flag = 10;

	int boy = 0;
	int girl = 0;

	for (int i = 0; i < 1000; i++) {
		if (c[i] == 'b' || c[i + 1] == 'o' || c[i + 2] == 'y') {
			boy++;
		}
		if (c[i] == 'g' || c[i + 1] == 'i' || c[i + 2] == 'r' || c[i + 3] == 'l') {
			girl++;
		}
	}

	cout << boy << ' ' << girl << endl;
	system("pause");
}