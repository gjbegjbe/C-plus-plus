#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string s;
	int* count=new int[26];
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}
	int time;
	cin >> time;
	
	while (time > -1) {

		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z')) {
				int ascii = (int)s[i];
				int asciiA = (int)'A';
				int asciia = (int)'a';
				if (s[i] >= 'A'&&s[i] <= 'Z') {
					int offset = ascii - asciiA;
					count[offset] += 1;
				}
				else if (s[i] >= 'a'&&s[i] <= 'z') {
					int offset = ascii - asciia;
					count[offset] += 1;
				}
			}
		}
		time -= 1;
	}
	sort(count, count + 26);
	int* fin = new int[26];
	int k = 0;
	for (int j = 0; j < 26; j++) {
		if (count[j] != 0) {
			fin[k] = count[j];
			k++;
		}
	}
	if (k == 0) {
		cout << "[]";
	}
	else {
		for (int m = 0; m < k; m++) {
			if (m == 0) {
				cout << "[";
			}
			cout << fin[m];
			if (m == k - 1) {
				cout << "]";
			}
			else {
				cout << ",";
			}
		}
	}
	
	cout << endl;
	system("pause");
}