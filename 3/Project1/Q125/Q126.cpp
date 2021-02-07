#include<iostream>
using namespace std;

struct NODE {
	int content;
	NODE *next;
};
NODE *head;

void insert(int n) {
	NODE *newNode = new NODE();
	newNode->content = n;
	newNode->next = NULL;

	NODE *pre = head;
	NODE *p = head->next;
	if (pre->next == NULL) {
		pre->next = newNode;
		return;
	}
	while ((p->content <= n) && (p->next != NULL)) {
		pre = p;
		p = p->next;
	}
	if (n < p->content) {
		if (p == head->next) {
			head->next = newNode;
			newNode->next = p;
		}
		else {
			pre->next = newNode;
			newNode->next = p;
		}
	}
	else {
		p->next = newNode;
		newNode->next = NULL;
	}
}

void print() {
	NODE *p = head->next;
	while (p) {
		if (p != head->next) {
			cout << ' ';
		}
		cout << p->content;
		p = p->next;
	}
}

int main() {
	head = new NODE();
	head->next = NULL;
	int time;
	cin >> time;
	while (time > 0) {
		int n;
		while (cin >> n) {
			insert(n);
			if (cin.peek() == '\n') {
				break;
			}
		}
		time -= 1;
	}
	
	print();
	cout << endl;
	system("pause");
}