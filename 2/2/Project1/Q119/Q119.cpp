#include <iostream>
using namespace std;

int main() {
	char name[500][10];
	int time[500];
	int amount[500];
	char city[500][10];
	int nlen[500] = { 0 };
	int clen[500] = { 0 };
	bool invalid[500] = { false };

	char c;
	char c1;

	int flag = 0;
	cin >> c;
	while (true) {
		cin >> c;
		while (cin >> c && c != ',') {
			name[flag][nlen[flag]] = c;
			nlen[flag]++;
		}
		cin >> time[flag] >> c >> amount[flag] >> c;
		while (cin >> c && c != '"') {
			city[flag][clen[flag]] = c;
			clen[flag]++;
		}
		flag++;
		
		if (cin.peek() == ']') {
			break;
		}
		cin >> c;
	}

	for (int i = 0; i < flag; i++) {
		if (amount[i] > 1000) {
			invalid[i] = true;
		}
	}

	for (int i = 0; i < flag - 1; i++) {
		for (int j = i + 1; j < flag; j++) {
			bool nameSame = true;
			if (nlen[i] != nlen[j]) {
				nameSame = false;
			} 
			else{
				for (int k = 0; k < nlen[i]; k++) {
					if (name[i][k] != name[j][k]) {
						nameSame = false;
						break;
					}
				}
			}
			bool citySame = true;
			if (clen[i] != clen[j]) {
				citySame = false;
			}
			else {
				for (int k = 0; k < clen[i]; k++) {
					if (city[i][k] != city[j][k]) {
						citySame = false;
						break;
					}
				}
			}
			int gap = time[i] - time[j];
			if (nameSame && (!citySame) && ((gap >= -60) && (gap <= 60))) {
				invalid[i] = true;
				invalid[j] = true;
			}
		}
	}

	int invalidCount = 0;
	for (int i = 0; i < flag; i++) {
		if (invalid[i]) {
			invalidCount++;
		}
	}
	int temp = 0;
	cout << '[';
	for (int i = 0; i < flag; i++) {
		if (invalid[i]) {
			cout << '"';
			for (int j = 0; j < nlen[i]; j++) {
				cout << name[i][j];
			}
			cout << ',' << time[i] << ',' << amount[i] << ',';
			for (int j = 0; j < clen[i]; j++) {
				cout << city[i][j];
			}
			cout << '"';
			temp++;
			if (temp < invalidCount) {
				cout << ',';
			}
		}
	}
	cout << ']' << endl;
	system("pause");
}