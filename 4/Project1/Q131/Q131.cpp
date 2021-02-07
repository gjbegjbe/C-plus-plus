#include<iostream>
#include<vector>
using namespace std;

class Hero {
public:
	bool magicianStart = false;
	int hp;
	int atk;
	void suffer(int attack) {
		if (!magicianStart) {
			hp -= attack;
		}
		else {
			magicianStart = false;
		}
	}
	bool alive() {
		return hp > 0 ? true : false;
	}
	virtual void Power() = 0;
	virtual void printWin() = 0;
};

class Warrior :public Hero {
public:
	Warrior(int humanPoint = 12, int attack = 2) {
		hp = humanPoint;
		atk = attack;
	}
	void Power() {
		hp++;
	}
	void printWin() {
		cout << "Warrior " << atk << " " << hp;
	}
};

class Magician :public Hero {
public:
	Magician(int humanPoint = 2, int attack = 6) {
		hp = humanPoint;
		atk = attack;
		magicianStart = true;
	}
	void Power() {
		magicianStart = false;
	}
	void printWin() {
		cout << "Magician " << atk << " " << hp;
	}
};

class Leader :public Hero {
public:
	Leader(int humanPoint = 6, int attack = 6) {
		hp = humanPoint;
		atk = attack;
	}
	void Power() {
		atk++;
	}
	void printWin() {
		cout << "Leader " << atk << " " << hp;
	}
};

class Factory {
public:
	static Hero* getHero(int heroType) {
		Hero* result = NULL;
		switch (heroType)
		{
		case 1:
			result = new Warrior();
			break;
		case 2:
			result = new Magician();
			break;
		case 3:
			result = new Leader();
			break;
		default:
			break;
		}
		return result;
	}
};

int main() {
	int heroNumber;
	cin >> heroNumber;

	vector<Hero*> first;
	first.resize(heroNumber);
	vector<Hero*> second;
	second.resize(heroNumber);

	Factory * factory = new Factory();
	int temp = 0;
	for (int i = 0; i < heroNumber; i++) {
		cin >> temp;
		first[i] = factory->getHero(temp);
	}
	for (int i = 0; i < heroNumber; i++) {
		cin >> temp;
		second[i] = factory->getHero(temp);
	}
	int pointer1 = 0;
	int pointer2 = 0;
	while (pointer1 != heroNumber && pointer2 != heroNumber) {
		first[pointer1]->suffer(second[pointer2] -> atk);
		second[pointer2]->suffer(first[pointer1] -> atk);
		if (first[pointer1]->alive()) {
			first[pointer1]->Power();
		}
		else {
			pointer1++;
		}
		if (second[pointer2]->alive()) {
			second[pointer2]->Power();
		}
		else {
			pointer2++;
		}
	}
	if (pointer1 == pointer2) {
		cout << "All Dead";
	}
	else {
		if (pointer1 == heroNumber) {
			for (int i = pointer2; i < heroNumber; i++) {
				second[i]->printWin();
				if (i + 1 != heroNumber) {
					cout << endl;
				}
			}
		}
		if (pointer2 == heroNumber) {
			for (int i = pointer1; i < heroNumber; i++) {
				first[i]->printWin();
				if (i + 1 != heroNumber) {
					cout << endl;
				}
			}
		}
	}
	cout << endl;
	system("pause");
}