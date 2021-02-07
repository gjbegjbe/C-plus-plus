#include<iostream>
using namespace std;

class Car {
public:
	int price;
	int sales_volumn;
	int engine_power;
	int market_size = 0;
	void setMS(int price, int num) {
		market_size += price * num;
	}
	void getMS() {
		cout << market_size << endl;
	}
};

class Chery :public Car {

};

class Benz : public Car {

};

class Tesla :public Car {

};

class Model_car :public  Car {
public:
	void display() {
		cout << "The model car has been displayed." << endl;
	}
};

int main() {
	int cp1, cn1, cp2, cn2, cp3, cn3,
		bp1, bn1, bp2, bn2, bp3, bn3,
		tp1, tn1, tp2, tn2, tp3, tn3,
		mp1, mn1, mp2, mn2, mp3, mn3;
	cin >> cp1 >> cn1 >> cp2 >> cn2 >> cp3 >> cn3;
	cin >> bp1 >> bn1 >> bp2 >> bn2 >> bp3 >> bn3;
	cin >> tp1 >> tn1 >> tp2 >> tn2 >> tp3 >> tn3;
	cin >> mp1 >> mn1 >> mp2 >> mn2 >> mp3 >> mn3;
	Chery * chery = new Chery();
	Benz * benz = new Benz();
	Tesla * tesla = new Tesla();
	Model_car * model_car = new Model_car();
	chery->setMS(cp1, cn1);
	chery->setMS(cp2, cn2);
	chery->setMS(cp3, cn3);
	benz->setMS(bp1, bn1);
	benz->setMS(bp2, bn2);
	benz->setMS(bp3, bn3);
	tesla->setMS(tp1, tn1);
	tesla->setMS(tp2, tn2);
	tesla->setMS(tp3, tn3);
	model_car->setMS(mp1, mn1);
	model_car->setMS(mp2, mn2);
	model_car->setMS(mp3, mn3);
	cout << "chery_market_size is: ";
	chery->getMS();
	cout << "benz_market_size is: ";
	benz->getMS();
	cout << "tesla_market_size is: ";
	tesla->getMS();
	cout << "model_car_market_size is: ";
	model_car->getMS();
	system("pause");
}

