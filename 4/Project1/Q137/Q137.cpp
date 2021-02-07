#include<iostream>
using namespace std;

class myString {
public:
	char head[100] = { '\0' };
	int size;
	myString(char *Head = NULL) {
		size = strlen(Head);
		for (int i = 0; i < size; i++) {
			head[i] = Head[i];
		}
	}

	void reverse() {
		for (int i = 0; i < size/2; i++) {
			char temp = head[i];
			head[i] = head[size - 1 - i];
			head[size - 1 - i] = temp;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << head[i];
		}
		cout << endl;
	}
};

int main() {
	char strchar[100];
	cin.getline(strchar, 100);
	myString * str = new myString(strchar);
	str->reverse();
	str->print();
	system("pause");
}