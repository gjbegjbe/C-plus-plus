#include<iostream>
#include<string>
using namespace std;


struct node {
	int val;
	struct node *next;
	struct node *prev;
};

node *head;
node *tail;

void insert(int n) {
	node *newNode = new node();
	newNode->val = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	node *p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	newNode->prev = p;

}

void print() {
	node *p = head->next;
	while (p) {
		cout << p->val;
		if (p->next) {
			cout << ' ';
		}
		p = p->next;
	}
}

void addbegin(int a, int b) {
	node *newNode = new node();
	newNode->val = a;
	newNode->next = NULL;
	newNode->prev = NULL;

	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode;

	print();

}

void addend(int a, int b) {
	insert(a);
	print();
}

void addmid(int a, int pos) {
	node *p = head;
	while (pos > 0) {
		pos--;
		p = p->next;
	}
	node *newNode = new node();
	newNode->val = a;
	newNode->next = NULL;
	newNode->prev = NULL;

	newNode->next = p->next;
	newNode->prev = p;
	p->next->prev = newNode;
	p->next = newNode;

	print();
}

void search(int a, int b) {
	node *p = head->next;

	int pos = 0;

	while (p) {
		if (p->val == a) {
			break;
		}
		p = p->next;
		pos++;
	}
	cout << pos;
}

void deletee(int pos, int b) {
	node *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	print();	
}

void count(int a, int b) {
	node *p = head->next;

	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	cout << count;
}

void reverse(int a, int b) {
	node *temp = NULL;
	node *current = head;
	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	node *p = head;
	while (p->prev != NULL) {
		p = p->prev;
	}
	head->next = p;
	p->prev = head;
	head->prev->next = NULL;
	head->prev = NULL;

	print();
}

typedef void(*func)(int, int);

int main() {
	head = new node();
	head->next = NULL;
	head->prev = NULL;

	int n;
	while (cin >> n) {
		insert(n);
		if (cin.peek() == '\n') {
			break;
		}
	}
	//print();
	int a = 0;
	int b = 0;
	string pstr;
	func p;
	while (cin>>pstr) {
		if (pstr == "addmid") {
			cin >> a >> b;
		}
		else if (pstr == "count" || pstr == "reverse") {
			a = 0;
		}
		else {
			cin >> a;
		}
		if (pstr == "addbegin") {
			p = addbegin;
		}
		else if (pstr == "addend") {
			p = addend;
		}
		else if (pstr == "addmid") {
			p = addmid;
		}
		else if (pstr == "search") {
			p = search;
		}
		else if (pstr == "delete") {
			p = deletee;
		}
		else if (pstr == "count") {
			p = count;
		}
		else {
			p = reverse;
		}

		p(a, b);
		cout << endl;

	}
	
	system("pause");

}