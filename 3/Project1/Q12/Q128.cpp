#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

double matrix1_num[50][50];
double matrix2_num[50][50];
string matrix1_char[50][50];
string matrix2_char[50][50];

string row[50];

double add(double a, double b) {
	return a + b;
}

string add_c(string a, string b) {
	string res = "";
	string start = a + b;
	for (int i = 0; i < start.length(); i++) {
		bool has = false;
		for (int j = 0; j < i; j++) {
			if (start[j] == start[i]) {
				has = true;
				break;
			}
		}
		if (!has) {
			res += start[i];
		}
	}
	return res;
}

double mul(double a, double b) {
	return a * b;
}

string mul_c(string a, string b) {
	return a + b;
}

void print(double res[][50],int na,int mb) {
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < mb; j++) {
			if (res[i][j] - (int)res[i][j] <= 0.00000001) {
				cout << res[i][j];
			}
			else {
				cout.setf(ios::fixed);
				cout << setprecision(4) << res[i][j];
				cout.unsetf(ios::fixed);
			}
			if (j == mb - 1) {
				cout << endl;
			}
			else {
				cout << ' ';
			}
		}
	}
}

void print_c(string res[][50], int na, int mb) {
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < mb; j++) {
			cout << res[i][j];
			if (j == mb - 1) {
				cout << endl;
			}
			else {
				cout << ' ';
			}
		}
	}
}

template<class T>
void m_mul(T a[][50], T b[][50], int na, int m, int mb) {
	T res[50][50] = { 0 };
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < mb; j++) {
			for (int k = 0; k < m; k++) {
				res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	print(res, na, mb);
}

template<>
void m_mul<string>(string a[][50], string b[][50], int na, int m, int mb) {
	string res[50][50] = { "" };
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < mb; j++) {
			for (int k = 0; k < m; k++) {
				res[i][j] = add_c(res[i][j], mul_c(a[i][k], b[k][j]));
			}
		}
	}
	print_c(res, na, mb);
	
}


int main() {
	int t1, n1, m1, t2, n2, m2, fint;
	fint = -1;
	cin >> t1 >> n1 >> m1;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			cin >> matrix1_char[i][j];
		}
	}
	cin >> t2 >> n2 >> m2;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			cin >> matrix2_char[i][j];
		}
	}
	if (t1 == 1 && t2 == 1) {
		fint = 1;
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m1; j++) {
				matrix1_num[i][j] = stod(matrix1_char[i][j]);
			}
		}
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				matrix2_num[i][j] = stod(matrix2_char[i][j]);
			}
		}
	}
	cout << fint << endl;
	if (fint == 1) {
		m_mul(matrix1_num, matrix2_num, n1, m1, m2);
	}
	else {
		m_mul(matrix1_char, matrix2_char, n1, m1, m2);
	}
	system("pause");
}