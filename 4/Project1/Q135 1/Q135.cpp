#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include<fstream>

using namespace std;

class Transaction {
public:
	double amount;
	Transaction(double amount) {
		this->amount = amount;
	}
};

class Account {
public:
	int type;
	//double interest;
	vector<Transaction> transactions;

	Account(int type) {
		this->type = type;
	}

	void deposit(double amount) {
		if (amount <= 0) {
			throw"amount must be greater than zero";
		}
		else {
			transactions.push_back(Transaction(amount));
		}
	}

	void withdraw(double amount) {
		if (amount <= 0) {
			throw"amount must be greater than zero";
		}
		else {
			if (sumTransactions() - amount < 0) {
				throw"sumTransactions must be greater than zero";
			}
			transactions.push_back(Transaction(-amount));
		}
	}

	double interestEarned() {
		double total = sumTransactions();
		switch (type) {
		case 0:
			return total * 0.001;
		case 1:
			if (total <= 1000) {
				return total * 0.001;
			}
			else {
				return 1 + (total - 1000)*0.002;
			}
		case 2:
			if (total <= 1000) {
				return total * 0.02;
			}
			else if (total > 1000 && total <= 2000) {
				return 20 + (total - 1000)*0.05;
			}
			else {
				return 70 + (total - 2000)*0.1;
			}
		}
		return 0.0;

	}

	double sumTransactions() {
		double total = 0;
		for (auto p : transactions) {
			total += p.amount;
		}
		return total;

	}
};



class Customer {
public:
	string name;
	vector<Account *> accounts;
	Customer() {};
	Customer(string name) {
		this->name = name;
	}


	int getNumberOfAccounts() {
		return accounts.size();
	}

	double totalInterestEarned() {
		double total = 0.0;
		for (auto p : accounts) {
			total += p->interestEarned();
		}
		return total;
	}
	string getStatement() {
		string statement = "Statement for ";
		
		statement = statement + this->name + string("\n") + string("\n");
		double total_amount_recorder = 0.0;
		for (auto p_account : accounts) {
			string checkingAccountStatement = "";
			string savingsAccountStatement = "";
			string maxSavingsAccountStatement = "";
			int account_type = p_account->type;
			string current_trans = "";
			double current_amount_recorder = 0.0;
			switch (account_type) {
			case 0:
				checkingAccountStatement = "Checking Account\n";
				for (auto trans : p_account->transactions) {
					if (trans.amount > 0) {
						current_trans = current_trans + string(" deposit ") + toDollars(trans.amount) + string("\n");
					}
					else if (trans.amount < 0) {
						current_trans = current_trans + string(" withdrawal ") + toDollars(-trans.amount) + string("\n");
					}
					current_amount_recorder += trans.amount;
				}
				checkingAccountStatement = checkingAccountStatement + current_trans + string("Total ") + toDollars(current_amount_recorder) + string("\n");
				break;
			case 1:
				savingsAccountStatement = "Savings Account\n";
				for (auto trans : p_account->transactions) {
					if (trans.amount > 0) {
						current_trans = current_trans + string(" deposit ") + toDollars(trans.amount) + string("\n");
					}
					else if (trans.amount < 0) {
						current_trans = current_trans + string(" withdrawal ") + toDollars(-trans.amount) + string("\n");
					}
					current_amount_recorder += trans.amount;
				}
				savingsAccountStatement = savingsAccountStatement + current_trans + string("Total ") + toDollars(current_amount_recorder) + string("\n");
				break;
			case 2:
				maxSavingsAccountStatement = "Maxi-Savings Account\n";
				for (auto trans : p_account->transactions) {
					if (trans.amount > 0) {
						current_trans = current_trans + string(" deposit ") + toDollars(trans.amount) + string("\n");
					}
					else if (trans.amount < 0) {
						current_trans = current_trans + string(" withdrawal ") + toDollars(-trans.amount) + string("\n");
					}
					current_amount_recorder += trans.amount;
				}
				maxSavingsAccountStatement = maxSavingsAccountStatement + current_trans + string("Total ") + toDollars(current_amount_recorder) + string("\n");
				break;
			}
			total_amount_recorder += current_amount_recorder;
			statement = statement + checkingAccountStatement + savingsAccountStatement + maxSavingsAccountStatement + string("\n");
		}
		statement += string("Total In All Accounts ") + toDollars(total_amount_recorder) + string("\n");
		return statement;
	}

	string toDollars(double amount) {
		string dollars = "";
		ostringstream out;
		out.precision(2);
		out << std::fixed << amount;
		dollars = "$" + out.str();
		return dollars;
	}

};

class Bank {
public:
	vector<Customer *>customers;
	Bank() {
		
	};

	

	string customerSummary() {
		string summary = "Customer Summary\n";
		for (auto p_customer : customers) {
			summary = summary + string(" - ") + p_customer->name + string(" (");
			int num_accounts = p_customer->getNumberOfAccounts();
			if (num_accounts == 1) {
				summary = summary + to_string(num_accounts) + string(" account)");
			}
			else {
				summary = summary + to_string(num_accounts) + string(" accounts)");
			}
			summary = summary + string("\n");
		}
		return summary;
	}

	double totalInterestPaid() {
		double total = 0;

		for (auto p_customer : customers) {
			total += p_customer->totalInterestEarned();
		}

		return total;

	}
};

int main() {
	vector<Account *> accounts;
	int type=0;
	string name="";
	int index=0;
	double amount=0;

	string command;

	Bank * bank = new Bank();

	//ofstream SaveFile("d:\\1b.txt");




	while (true) {
		cin >> command;
		if (command == "createAccount") {
			cin >> type;
			Account * account = new Account(type);
			accounts.push_back(account);
		}
		else if (command == "createCustomer") {
			cin >> name;
			Customer * customer = new Customer(name);
			bank->customers.push_back(customer);
		}
		else if (command == "addToCustomer") {
			cin >> index >> name;
			Customer * currentCustomer = new Customer();
			for (auto p : bank->customers) {
				if (p->name == name) {
					currentCustomer = p;
					break;
				}
			}
			currentCustomer->accounts.push_back(accounts[index]);
		}
		else if (command == "accountDeposit") {
			cin >> index >> amount;
			Account * currentAccount = accounts[index];
			try {
				currentAccount->deposit(amount);
			}
			catch (const char * msg) {
				cout << msg << endl;
			}
		}
		else if (command == "accountWithdraw") {
			cin >> index >> amount;
			Account * currentAccount = accounts[index];
			try {
				currentAccount->withdraw(amount);
			}
			catch (const char * msg) {
				cout << msg << endl;
			}
		}
		else if (command == "sumTransactions") {
			cin >> index;
			Account * currentAccount = accounts[index];
			cout.setf(ios::fixed);
			cout << setprecision(1) << currentAccount->sumTransactions() << endl;
		}
		else if (command == "numberOfAccount") {
			cin >> name;
			Customer * currentCustomer = new Customer();
			for (auto p : bank->customers) {
				if (p->name == name) {
					currentCustomer = p;
					break;
				}
			}
			cout << currentCustomer->getNumberOfAccounts() << endl;
			//cout << 6 << endl;
		}
		else if (command == "totalInterestEarned") {
			cin >> name;
			Customer * currentCustomer = new Customer();
			for (auto p : bank->customers) {
				if (p->name == name) {
					currentCustomer = p;
					break;
				}
			}
			double totalInterest = 0.0;
			for (auto p : currentCustomer->accounts) {
				totalInterest += p->interestEarned();
			}
			cout.setf(ios::fixed);
			cout << setprecision(1) << totalInterest << endl;
		}
		else if (command == "getStatement") {
			cin >> name;
			Customer * currentCustomer = new Customer();
			for (auto p : bank->customers) {
				if (p->name == name) {
					currentCustomer = p;
					break;
				}
			}
			cout << currentCustomer->getStatement();
		}
		else if (command == "banktotalInserstPaid") {
			cout.setf(ios::fixed);
			cout << setprecision(1) << bank->totalInterestPaid() << endl;
		}
		else if (command == "customsum") {
			cout << bank->customerSummary();
		}
		else {
			break;
		}
		//SaveFile << command << ' ' << time << ' ' << index << ' ' << amount << ' ' << name<<endl;
	}

	//SaveFile.close();

	//_ASSERT(false);

}