#include<iostream>
#include<math.h>
using namespace std;

int main() {
/*����: �Ⱥ������пո񣬶���ֻ���ұ��пո�
x = 3, y = 2*/
	char c;
	int x, y;
	cin >> c >> c >> x >> c >> c >> c >> y;
	if (x > 2147483647 || y > 2147483647 || x < -2147483648 || x < -2147483648) {
		cout << -1;
	}
	else {
		int answer = pow(x, y);
		if (answer > 2147483647 || answer < -2147483648) {
			cout << -1;
		}
		else {
			cout << answer;

		}
	}
	system("pause");
}
