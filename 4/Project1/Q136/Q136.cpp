#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

class Product{
public:
	double sumnum = 0.0;
		
	void addSum(double price, double count) {
		if (count >= 10) {
			sumnum += price * count*0.88;
		}
		else {
			sumnum += price * count;
		}
	}

	void print() {
		cout.setf(ios::fixed);
		cout << setprecision(2) << sumnum << endl;
	}
};

int main() {
	Product * product = new Product;
	int id;	
	double price;
	double count;
	string line;
	while(getline(cin,line)) {
		if (line.size() == 0) {
			break;
		}
		istringstream record(line);
		record >> id >> price >> count;
		product->addSum(price, count);
	} 
	product->print();

	system("pause");
}