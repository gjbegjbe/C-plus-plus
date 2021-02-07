#include<iostream>
using namespace std;


int main() {
	char c[1000];
	for (int i = 0; i < 1000; i++) {
		c[i] = '-';
	}

	int flag = 0;
	cin.get(c, 1000);

	for (int i = 0; i < 1000; i++) {
		if (c[i] != '-') {
			flag++;
		}
	}
	flag -= 1;
	
	

	int count = 1;
	int flag1 = 0;
	char c1[1000];

	for (int i = 0; i < flag; i++) {
		if (i != flag - 1) {
			if (c[i] == c[i + 1]) {
				count++;
			}
			else {
				c1[flag1] = c[i];
				flag1++;
				if (count < 10) {
					c1[flag1] = count + '0';
					flag1++;
				}
				else {
					c1[flag1] = (count / 10) + '0';
					flag1++;
					c1[flag1] = (count % 10) + '0';
					flag1++;
				}
				count = 1;
			}
		}
		else {
			c1[flag1] = c[i];
			flag1++;
			if (count < 10) {
				c1[flag1] = count + '0';
				flag1++;
			}
			else {
				c1[flag1] = (count / 10) + '0';
				flag1++;
				c1[flag1] = (count % 10) + '0';
				flag1++;
			}
		}
	}
	
	if (flag1 > flag) {
		for (int i = 0; i < flag; i++) {
			cout << c[i];
		}
	}
	else {
		for (int i = 0; i < flag1; i++) {
			cout << c1[i];
		}
	}
	
	cout << endl;

	system("pause");
}