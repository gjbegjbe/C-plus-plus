#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;//读入的含有括号的一串

	string set = "";//表示集合的字符串
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] >= 'a'&&s[i] <= 'z') {
			
			set += s[i];
		}
	}

	char chr = s[s.size() - 1];//寻找的字符

	sort(set.begin(), set.end());//对集合排序

	int length = set.size();

	string* result = new string[pow(2, set.size())];

	for (int j = 0; j < pow(2, set.size()); j++) {
		for (int k = 0; k < set.size(); k++) {
			if (j&(1 << k)) {
				result[j] += set[k];
			}
		}
	}

	string* newResult = new string[pow(2, set.size())];
	int index = 0;

	for (int m = 0; m < pow(2, set.size()); m++) {
		for (int n = 0; n < result[m].size(); n++) {
			if (result[m][n] == chr) {
				newResult[index] = result[m];
				index++;
			}
		}
	}

	string* finResult = new string[pow(2, set.size()-1)];
	for (int i = 0; i < pow(2, set.size() - 1); i++) {
		finResult[i] = newResult[i];
	}

	for (int i = 0; i < pow(2, set.size() - 1); i++) {
		for (int j = 0; j < pow(2, set.size() - 1) -i - 1; j++) {
			
			if (finResult[j] > finResult[j + 1]) {
				string temp = finResult[j];
				finResult[j] = finResult[j + 1];
				finResult[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < pow(2, set.size() - 1); i++) {
		for (int j = 0; j < pow(2, set.size() - 1) - i - 1; j++) {
			if (finResult[j].size() > finResult[j + 1].size()) {
				string temp = finResult[j];
				finResult[j] = finResult[j + 1];
				finResult[j + 1] = temp;
			}
		}
	}



	
	for (int m = 0; m < pow(2, set.size()-1); m++) {
		cout << "{";
		for (int i = 0; i < finResult[m].size(); i++) {
			cout << finResult[m][i];
			if (i != finResult[m].size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		if (m != pow(2, set.size() - 1) - 1) {
			cout << ",";
		}
	}
	cout << endl;

	system("pause");
}
