#include<iostream>
using namespace std;

int main() {
	int num[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			num[i][j] = 0;
		}
	}
	int flag = 0;
	while (cin >> num[0][flag]) {
		flag++;
		if (cin.peek() == '\n') {
			break;
		}
	}
	for (int i = 0; i < flag - 1; i++) {
		int j = 0;
		while (cin >> num[i+1][j]) {
			j++;
			if (cin.peek() == '\n') {
				break;
			}
		}
	}

	int route;
	cin >> route;

	route = route % 360;

	switch (route)
	{
	case 0:
		break;
	case 90:
		for (int m = 0; m < flag / 2; m++) {
			for (int n = 0; n < flag; n++) {
				int temp = num[m][n];
				num[m][n] = num[flag - 1 - m][n];
				num[flag - 1 - m][n] = temp;
			}
		}
		for (int m = 0; m < flag; m++) {
			for (int n = m + 1; n < flag; n++) {
				int temp = num[m][n];
				num[m][n] = num[n][m];
				num[n][m] = temp;
			}
		}
		break;
	case 180:
		for (int m = 0; m < flag / 2; m++) {
			for (int n = 0; n < flag; n++) {
				int temp = num[m][n];
				num[m][n] = num[flag - 1 - m][n];
				num[flag - 1 - m][n] = temp;
			}
		}
		for (int m = 0; m < flag / 2; m++) {
			for (int n = 0; n < flag; n++) {
				int temp = num[n][m];
				num[n][m] = num[n][flag - 1 - m];
				num[n][flag - 1 - m] = temp;
			}
		}
		break;
	case 270:
		for (int m = 0; m < flag / 2; m++) {
			for (int n = 0; n < flag; n++) {
				int temp = num[m][n];
				num[m][n] = num[flag - 1 - m][n];
				num[flag - 1 - m][n] = temp;
			}
		}
		for (int m = 0; m < flag; m++) {
			for (int n = 0; n < flag - m - 1; n++) {
				int temp = num[m][n];
				num[m][n] = num[flag - 1 - n][flag - 1 - m];
				num[flag - 1 - n][flag - 1 - m] = temp;
			}
		}
		break;
	default:
		break;
	}


	for (int i = 0; i < flag; i++) {
		for (int j = 0; j < flag; j++) {
			cout << num[i][j];
			if (j != flag - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	system("pause");
}