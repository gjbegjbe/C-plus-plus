#include<iostream>
using namespace std;

int main() {
	char c;
	char sodoku[9][9];
	cin >> c >> c >> sodoku[0][0] >> c >> c >> c >> sodoku[0][1] >> c >> c >> c >> sodoku[0][2] >> c >> c >> c >> sodoku[0][3] >> c >> c >> c >>
		sodoku[0][4] >> c >> c >> c >> sodoku[0][5] >> c >> c >> c >> sodoku[0][6] >> c >> c >> c >> sodoku[0][7] >> c >> c >> c >>
		sodoku[0][8] >> c >> c;
	cin >> c >> c >> sodoku[1][0] >> c >> c >> c >> sodoku[1][1] >> c >> c >> c >> sodoku[1][2] >> c >> c >> c >> sodoku[1][3] >> c >> c >> c >>
		sodoku[1][4] >> c >> c >> c >> sodoku[1][5] >> c >> c >> c >> sodoku[1][6] >> c >> c >> c >> sodoku[1][7] >> c >> c >> c >>
		sodoku[1][8] >> c >> c;
	cin >> c >> c >> sodoku[2][0] >> c >> c >> c >> sodoku[2][1] >> c >> c >> c >> sodoku[2][2] >> c >> c >> c >> sodoku[2][3] >> c >> c >> c >>
		sodoku[2][4] >> c >> c >> c >> sodoku[2][5] >> c >> c >> c >> sodoku[2][6] >> c >> c >> c >> sodoku[2][7] >> c >> c >> c >>
		sodoku[2][8] >> c >> c; 
	cin >> c >> c >> sodoku[3][0] >> c >> c >> c >> sodoku[3][1] >> c >> c >> c >> sodoku[3][2] >> c >> c >> c >> sodoku[3][3] >> c >> c >> c >>
		sodoku[3][4] >> c >> c >> c >> sodoku[3][5] >> c >> c >> c >> sodoku[3][6] >> c >> c >> c >> sodoku[3][7] >> c >> c >> c >>
		sodoku[3][8] >> c >> c;
	cin >> c >> c >> sodoku[4][0] >> c >> c >> c >> sodoku[4][1] >> c >> c >> c >> sodoku[4][2] >> c >> c >> c >> sodoku[4][3] >> c >> c >> c >>
		sodoku[4][4] >> c >> c >> c >> sodoku[4][5] >> c >> c >> c >> sodoku[4][6] >> c >> c >> c >> sodoku[4][7] >> c >> c >> c >>
		sodoku[4][8] >> c >> c;
	cin >> c >> c >> sodoku[5][0] >> c >> c >> c >> sodoku[5][1] >> c >> c >> c >> sodoku[5][2] >> c >> c >> c >> sodoku[5][3] >> c >> c >> c >>
		sodoku[5][4] >> c >> c >> c >> sodoku[5][5] >> c >> c >> c >> sodoku[5][6] >> c >> c >> c >> sodoku[5][7] >> c >> c >> c >>
		sodoku[5][8] >> c >> c; 
	cin >> c >> c >> sodoku[6][0] >> c >> c >> c >> sodoku[6][1] >> c >> c >> c >> sodoku[6][2] >> c >> c >> c >> sodoku[6][3] >> c >> c >> c >>
		sodoku[6][4] >> c >> c >> c >> sodoku[6][5] >> c >> c >> c >> sodoku[6][6] >> c >> c >> c >> sodoku[6][7] >> c >> c >> c >>
		sodoku[6][8] >> c >> c;
	cin >> c >> c >> sodoku[7][0] >> c >> c >> c >> sodoku[7][1] >> c >> c >> c >> sodoku[7][2] >> c >> c >> c >> sodoku[7][3] >> c >> c >> c >>
		sodoku[7][4] >> c >> c >> c >> sodoku[7][5] >> c >> c >> c >> sodoku[7][6] >> c >> c >> c >> sodoku[7][7] >> c >> c >> c >>
		sodoku[7][8] >> c >> c;
	cin >> c >> c >> sodoku[8][0] >> c >> c >> c >> sodoku[8][1] >> c >> c >> c >> sodoku[8][2] >> c >> c >> c >> sodoku[8][3] >> c >> c >> c >>
		sodoku[8][4] >> c >> c >> c >> sodoku[8][5] >> c >> c >> c >> sodoku[8][6] >> c >> c >> c >> sodoku[8][7] >> c >> c >> c >>
		sodoku[8][8] >> c >> c;

	bool isS = true;
	int numc[10];
	for (int i = 0; i < 10; i++) {
		numc[i] = 0;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sodoku[i][j] != '.') {
				numc[sodoku[i][j] - '0']++;
			}
		}
		for (int k = 0; k < 10; k++) {
			if (numc[k] > 1) {
				isS = false;
			}
			numc[k] = 0;
		}		
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sodoku[j][i] != '.') {
				numc[sodoku[j][i] - '0']++;
			}
		}
		for (int k = 0; k < 10; k++) {
			if (numc[k] > 1) {
				isS = false;
			}
			numc[k] = 0;
		}
	}
	for (int i = 0; i < 9; i+=3) {
		for (int j = 0; j < 9; j+=3) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (sodoku[i + k][j + l] != '.') {
						numc[sodoku[i + k][j + l] - '0']++;
					}
				}
			}
			for (int p = 0; p < 10; p++) {
				if (numc[p] > 1) {
					isS = false;
				}
				numc[p] = 0;
			}
		}
		
	}
	if (isS) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
	system("pause");
	
}