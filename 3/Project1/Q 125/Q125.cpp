#include<iostream>
#include<string>
using namespace std;

int add(int x, int y) {
	x = ((x + 52) / 2 + 13) * 3;
	y = (y - 18) * 4 + 12;
	return x + y;
}

int sub(int x, int y) {
	x = ((x + 52) / 2 + 13) * 3;
	y = (y - 18) * 4 + 12;
	return x - y;
}

int mul(int x, int y) {
	x = ((x + 52) / 2 + 13) * 3;
	y = (y - 18) * 4 + 12;
	return x * y;
}

int divv(int x, int y) {
	x = ((x + 52) / 2 + 13) * 3;
	y = (y - 18) * 4 + 12;
	return x / y;
}

typedef int(*func)(int, int);


int main() {
	int time;
	cin >> time;
	int a, b;
	func p;
	string pstr;
	while (time > 0) {
		time--;
		cin >> pstr >> a >> b;
		if (pstr == "add") {
			p = add;
		}
		else if (pstr == "sub") {
			p = sub;
		}
		else if (pstr == "mul") {
			p = mul;
		}
		else {
			p = divv;
		}
		cout << p(a, b) << endl;
	}
	system("pause");

}