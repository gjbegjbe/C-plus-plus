#include<iostream>
#include<string>

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
		
	}
	return answer;
}



int main() {
	string s;
	
	int max = 0;

	string str = "";

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 'A'&&s[i] < 'Z') {
			str += s[i];
		}
		else {
			int temp = rToInt(str);
			if (temp > max) {
				max = temp;
			}
			str = "";
		}
	}
	int temp = rToInt(str);
	if (temp > max) {
		max = temp;
	}

	cout << max << endl;
	
	
	system("pause");
}