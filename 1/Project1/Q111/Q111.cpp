#include <iostream>
using namespace std;

int main() {
	char c;
	int x1, y1, x2, y2, x3, y3;
	cin >> c >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3 >> c;

	int d1 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int d2 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
	int d3 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);

	bool isR = false;
	bool isI = false;
		
	double l1 = sqrt(d1);
	double l2 = sqrt(d2);
	double l3 = sqrt(d3);


	if ((l1 + l2 <= l3) || (l1 + l3 <= l2) || (l2 + l3 <= l1) ){
		cout << "NT" << endl;
	}
	else {
		if (d1 == d2 || d1 == d3 || d2 == d3) {
			isI = true;
		}
		if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
			isR = true;
		}

		if (isI && isR) {
			cout << "LRT" << endl;
		}
		else if (!isI && isR) {
			cout << "ORT" << endl;
		}
		else if (isI && !isR) {
			cout << "OIT" << endl;
		}
		else {
			cout << "OT" << endl;
		}
	}
	

	system("pause");


}
