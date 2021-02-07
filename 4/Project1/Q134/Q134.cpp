#include<iostream>
#include<string>
#include<vector>


using namespace std;



class Car {
public:
	string id;
	char type;
	double size;
	int remainTime;
	int waitTime;
	double fee;

	double startplace;//起始位置
	double endplace;//结束位置

	Car(char type, string id) {
		this->type = type;
		this->id = id;
		switch (type) {
		case'S':
			this->size = 1;
			this->fee = 1.5;
			this->remainTime = 3;
			this->waitTime = 1;
			break;
		case'M':
			this->size = 1.5;
			this->fee = 3;
			this->remainTime = 2;
			this->waitTime = 2;
			break;
		case'L':
			this->size = 2;
			this->fee = 4.5;
			this->remainTime = 1;
			this->waitTime = 3;
			break;
		}
	}

};

bool par(string weather, double parkLength,double parkCurrentLength, Car * car, vector<Car*> &park) {

	if (weather == "sunny") {
		if (parkCurrentLength - car->size < 0) {
			return false;
		}
		else {
			park.push_back(car);
			return true;
		}
	}
	else {
		double start = 0;
		int place = 0;
		for (int i = 0; i < park.size(); i++) {
			double end = park[i]->startplace;
			if (end - start >= car->size) {
				car->startplace = start;
				park.insert(park.begin() + i,car);
				return true;
			}
			start = end + park[i]->size;
		}
		if (parkLength - start < car->size) {
			return false;
		}
		car->startplace = start;
		park.push_back(car);
		return true;
	}
	return false;
}

int main() {
	double parkLength;
	string weather;
	cin >> parkLength >> weather;
	vector<Car*> park;
	vector<Car*> wait;
	vector<Car*> list;

	string command;
	char type;
	string id;
	double feeSum = 0;


	while (true) {
		cin >> command;
		if (command == "in") {
			cin >> type >> id;
			Car * car = new Car(type, id);
			list.push_back(car);
		}
		else {
			break;
		}
	}

	if (list.size() == 0) {
		cout << "null" << endl;
		return 0;
	}
	else {
		while (list.size() != 0 || wait.size() != 0 || park.size() != 0) {

			double parkCurrentLength = parkLength;//空余的长度

			int pointer = 0;
			while (pointer<park.size()) {
				park[pointer]->remainTime--;
				if (park[pointer]->remainTime <= 0) {
					feeSum += park[pointer]->fee;
					park.erase(park.begin()+pointer);
					pointer--;
				}
				pointer++;
			}

			for (int i = 0; i < park.size(); i++) {
				parkCurrentLength -= park[i]->size;
			}

			pointer = 0;
			while (pointer<wait.size()) {
				wait[pointer]->waitTime--;
				if (wait[pointer]->waitTime <= 0) {
					wait.erase(wait.begin()+pointer);
					pointer--;
				}
				pointer++;
			}

			if (list.size() > 0) {
				wait.push_back(list[0]);
				list.erase(list.begin());
			}

			while (wait.size() > 0) {
				bool canPut;
				Car * car = wait[0];
				canPut = par(weather, parkLength,parkCurrentLength, car, park);
				if (!canPut) {
					break;
				}
				parkCurrentLength -= wait[0]->size;
				wait.erase(wait.begin());
			}

			//打印每一步的状态
			if (!park.empty()) {
				for (int i = 0; i < park.size() - 1; i++) {
					cout << park[i]->id << ' ';
				}
				cout << park[park.size() - 1]->id << endl;
			}
			if (park.empty()) {
				cout << "null" << endl;
			}

		}

		
	}

	cout << feeSum<<endl;
	system("pause");


}