#include<iostream>
#include<string>
using namespace std;

class Jerry{
public:
	void hearMeow() {
		cout << "J: escape" << endl;
	}
	void beChased() {
		cout << "J: run" << endl;
	}
	void beCaught() {
		cout << "J: zhi" << endl;
	}
};


class Owner {
public:
	void hearMeow() {
		cout << "O: What's up?" << endl;
	}
	void seeJHide() {
		cout << "O: you piece of shit." << endl;
	}
	void seeJCaught() {
		cout << "O: well done." << endl;
	}
};


int main() {
	Jerry * jerry=new Jerry;
	Owner * owner=new Owner;

	string action;

	while (getline(cin,action)){
		if (action == "T: meow") {
			jerry->hearMeow();
			owner->hearMeow();
		}
		else if (action == "T: chase") {
			jerry->beChased();
		}
		else if (action == "J: hide") {
			owner->seeJHide();
		}
		else {
			jerry->beCaught();
			owner->seeJCaught();
		}

	}

}