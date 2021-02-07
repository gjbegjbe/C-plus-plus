#include<iostream>
using namespace std;

class Operation {
public:
	double NumberA;
	double NumberB;
	virtual double GetResult()=0;
	double getA() {
		return NumberA;
	}
	double getB() {
		return NumberB;
	}
	void setA(int A) {
		NumberA = A;
	}
	void setB(int B) {
		NumberB = B;
	}
};

class OperationAdd :public Operation {
	double GetResult() {
		return NumberA + NumberB;
	}
};

class OperationSub :public Operation {
	double GetResult() {
		return NumberA - NumberB;
	}
};

class OperationMul :public Operation {
	double GetResult() {
		return NumberA * NumberB;
	}
};

class OperationDiv :public Operation {
	double GetResult() {
		return NumberA / NumberB;
	}
};

class OperationFactory {
public:
	static Operation* CreateOperation(char c) {
		switch (c){
		case '+':return new OperationAdd();
		case '-':return new OperationSub();
		case '*':return new OperationMul();
		case '/':return new OperationDiv();
		}
	}
};

int main(){
	double a,b;
	char c;
	cin >> c >> a >> b;
	OperationFactory factory;
	Operation * operation;
	operation = factory.CreateOperation(c);
	operation->setA(a);
	operation->setB(b);
	double answer = operation->GetResult();
	cout << answer << endl;
	system("pause");

}