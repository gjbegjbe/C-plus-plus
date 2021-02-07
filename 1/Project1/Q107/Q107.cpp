#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	string news = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a'&&s[i] <= 'z') {
			news += (char)toupper(s[i]);
		}
		else if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= '0'&&s[i] <= '9')) {
			news += s[i];
		}
	}
	int length = news.size();
	string ans = "";
	int index = length - k;
	while (index > 0) {
		string temp = news.substr(index, k);
		ans = "-" + temp + ans;
		index -= k;
	}
	string fir = news.substr(0, index + k);
	ans = fir + ans;

	cout << ans << endl;
	system("pause");

}