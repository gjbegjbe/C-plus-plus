#include<iostream>

using namespace std;

int numOut[40000];
int flag1 = 0;

bool sameCheck(int i, int j, int k, int l) {
	for (int m = 0; m < flag1; m = m + 4) {
		if ((i == numOut[m]) && (j == numOut[m + 1]) && (k == numOut[m + 2]) && (l == numOut[m + 3])) {
			return true;
		}

	}
	return false;
}

int main() {
	int num[99999];
	char c;
	int flag = 0;
	int sum;
	cin >> c;
	if (cin.peek() == ']') {
		cin >> c;
		cin >> sum;
		cout << -1 << endl;
	}
	else {
		while (cin.peek() != '\n') {

			cin >> num[flag];
			cin >> c;
			flag++;
		}


		cin >> sum;
		if (flag < 4) {
			cout << -1 << endl;
		}
		else {
			for (int i = 0; i < flag - 1; i++) {
				for (int j = 0; j < flag - 1 - i; j++) {
					if (num[j] > num[j + 1]) {
						int temp = num[j];
						num[j] = num[j + 1];
						num[j + 1] = temp;
					}
				}
			}


			bool no = true;

			for (int i = 0; i < flag - 3; i++) {
				for (int j = i + 1; j < flag - 2; j++) {
					for (int k = j + 1; k < flag - 1; k++) {
						for (int l = k + 1; l < flag; l++) {
							if ((num[i] + num[j] + num[k] + num[l] == sum) && (!sameCheck(num[i], num[j], num[k], num[l]))) {
								numOut[flag1] = num[i];
								flag1++;
								numOut[flag1] = num[j];
								flag1++;
								numOut[flag1] = num[k];
								flag1++;
								numOut[flag1] = num[l];
								flag1++;
								no = false;
							}
						}
					}
				}
			}

			if (no) {
				cout << -1 << endl;
			}
			else {
				for (int i = 0; i < flag1; i = i + 4) {
					cout << '[' << numOut[i] << ',' << ' ' << numOut[i + 1] << ',' << ' ' << numOut[i + 2] << ',' << ' ' << numOut[i + 3] << ']' << endl;
				}
			}
	}
	
			   /*
		bool no = true;
		int flag1 = 0;
		for (int i = 0; i < flag - 4; i++) {
			for (int j = i + 1; j < flag - 3; j++) {
				for (int k = j + 1; k < flag - 2; k++) {
					for (int l = k + 1; l < flag - 1; l++) {
						if (num[i] + num[j] + num[k] + num[l] == sum) {
							num1[flag1][0] = num[i];
							num1[flag1][1] = num[j];
							num1[flag1][2] = num[k];
							num1[flag1][3] = num[l];
							flag1++;

							no = false;
						}
					}
				}
			}
		}
		if (no) {
			cout << -1 << endl;
		}
		else {
			for (int i = 0; i < flag1; i++) {
				if (i != 0) {
					if (!((num1[i][0] == num1[i - 1][0]) && (num1[i][1] == num1[i - 1][1]) && (num1[i][2] == num1[i - 1][2]) && (num1[i][3] == num1[i - 1][3]))) {
						cout << '[' << num1[i][0] << ',' << ' ' << num1[i][1] << ',' << ' ' << num1[i][2] << ',' << ' ' << num1[i][3] << ']' << endl;
					}
				}
				else {
					cout << '[' << num1[i][0] << ',' << ' ' << num1[i][1] << ',' << ' ' << num1[i][2] << ',' << ' ' << num1[i][3] << ']' << endl;
				}
			}
		}*/
	}
	
	
	system("pause");
}