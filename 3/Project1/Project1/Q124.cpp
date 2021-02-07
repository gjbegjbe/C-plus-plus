#include<iostream>
using namespace std;

int num;
bool allsmall = true;
bool allbig = true;

struct NODE {
	int content;
	NODE *next;
};
NODE *head;

void insert(int n) {
	NODE *pre = head;
	NODE *p = head->next;
	while (p != NULL) {
		pre = p;
		p = p->next;
	}
	NODE *newNode = new NODE();
	newNode->content = n;
	newNode->next = pre->next;
	pre->next = newNode;
}


void printsmall() {
	bool start = true;
	NODE *p = head->next;
	while (p) {

		if (p->content < num) {
			if (!start) {
				cout << "->";
			}
			cout << p->content;
			start = false;
			allbig = false;
		}
		else {
			allsmall = false;
		}
		
		p = p->next;
	}
}

void printbig() {
	bool start = true;
	NODE *p = head->next;
	while (p) {
		if (p->content >= num) {
			if (!start) {
				cout << "->";
			}
			cout << p->content;
			start = false;
		}
		
		p = p->next;
	}
}

int main() {
	head = new NODE();
	head->next = NULL;
	int n;
	while (cin >> n) {
		insert(n);
		if (cin.peek() == '\n') {
			break;
		}
	}
	cin >> num;
	printsmall();
	if (!allsmall) {
		if (!allbig) {
			cout << "->";

		}
		printbig();
	}
	
	cout << endl;
	system("pause");
}