#include <iostream>
#include <string>

using namespace std;

int real(char c) {
	switch (c) {
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	default:return 0;

	}
	return 0;
}

int rToInt(string s) {
	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		int realVal = real(s[i]);
		if (i > 0) {
			int realValPre = real(s[i - 1]);
			if (realVal > realValPre) {
				answer += realVal - 2 * realValPre;
			}
			else {
				answer += realVal;
			}
		}
		else {
			answer += realVal;
		}
		return answer;
	}
}


int main() {
	int array[100];
	string s;
	int max = 0;
	while (cin >> s) {
		int temp = rToInt(s);
		if (temp > max) {
			max = temp;
		}

	}
	cout << max << endl;
}

