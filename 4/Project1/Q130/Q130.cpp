#include<iostream>
using namespace std;

class Hamburger {
public:
	int price;
	Hamburger() {
		price = 0;
	}
	virtual int totalCost()=0;
	
};

class MeatDecorator :public Hamburger {
public:
	MeatDecorator() {};
	int totalCost() {
		return price;
	}
};

class Beef :public MeatDecorator {
private:
	int num = 0;
	int price = 10;
	Hamburger * hamburger = NULL;
public:
	Beef(Hamburger* ham, int num) {
		this->num = num;
		this->hamburger = ham;
	}
	int totalCost() {
		return this->num*this->price + hamburger->price;
	}
};

class Pork :public MeatDecorator {
private:
	int num = 0;
	int price = 8;
	Hamburger * hamburger = NULL;
public:
	Pork(Hamburger* ham, int num) {
		this->num = num;
		this->hamburger = ham;
	}
	int totalCost() {
		return this->num*this->price + hamburger->price;
	}
};

class Chicken :public MeatDecorator {
private:
	int num = 0;
	int price = 7;
	Hamburger * hamburger = NULL;
public:
	Chicken(Hamburger* ham, int num) {
		this->num = num;
		this->hamburger = ham;
	}
	int totalCost() {
		return this->num*this->price + hamburger->price;
	}
};

class VegetableDecorator :public Hamburger {
public:
	VegetableDecorator() {};
	int totalCost() {
		return price;
	}
};

class Lettuce :public VegetableDecorator {
private:
	int num = 0;
	int price = 4;
	Hamburger * hamburger = NULL;
public:
	Lettuce(Hamburger* ham, int num) {
		this->num = num;
		this->hamburger = ham;
	}
	int totalCost() {
		return this->num*this->price + hamburger->price;
	}
};

class Tomato :public VegetableDecorator {
private:
	int num = 0;
	int price = 3;
	Hamburger * hamburger = NULL;
public:
	Tomato(Hamburger* ham, int num) {
		this->num = num;
		this->hamburger = ham;
	}
	int totalCost() {
		return this->num*this->price + hamburger->price;
	}
};

class MeatFactory {
public:
	static MeatDecorator* get(int id,int num,Hamburger* meatHam) {
		MeatDecorator* meat = NULL;
		switch (id)
		{case 1:
			meat = new Beef(meatHam,num);
			break;
		case 2:
			meat = new Pork(meatHam, num);
			break;
		case 3:
			meat = new Chicken(meatHam, num);
			break;
		default:
			break;
		}
		return meat;
	}
};

class VegetableFactory {
public:
	static VegetableDecorator* get(int id, int num, Hamburger* vegetableHam) {
		VegetableDecorator* vegetable = NULL;
		switch (id)
		{
		case 1:
			vegetable = new Lettuce(vegetableHam, num);
			break;
		case 2:
			vegetable = new Tomato(vegetableHam, num);
			break;
		default:
			break;
		}
		return vegetable;
	}
};

int main() {
	Hamburger * meatHam = new MeatDecorator();
	Hamburger * vegetableHam = new VegetableDecorator();
	MeatFactory  meatFactory;
	VegetableFactory vegetableFactory;
	int meatType, meatNum, vegetableType, vegetableNum;
	cin >> meatType >> meatNum;
	MeatDecorator * meat = meatFactory.get(meatType, meatNum, meatHam);
	cin >> vegetableType >> vegetableNum;
	VegetableDecorator * vegetable = vegetableFactory.get(vegetableType, vegetableNum, vegetableHam);
	int price = meat->totalCost() + vegetable->totalCost();
	cout << price << endl;
	system("pause");
}