#include<iostream>
#include<vector>
using namespace std;



class Chess {
public:
	char type;
	Chess(char type) {
		this->type = type;
	}
};

class Board {
public:
	int size;
	int length;
	int space;
	vector<vector<Chess*> > board;


	Board(int size, int length) {
		this->size = size;
		this->length = length;
		this->space = size * size;
		board.resize(size, vector<Chess*>(size));
	}



	char now = 'O';
	const int a[8][2] = { {0,1},{1,0},{1,1}, {1,-1},{0,-1},{-1,0},{-1,-1},{-1,1} };
	bool place(int x, int y) {

		board[x][y] = new Chess(now);
		space--;
		int d[4] = { -1,-1,-1,-1 };

		for (int i = 0; i < 8; i++) {
			int j = x;
			int k = y;
			while (j >= 0 && k >= 0 && j < size&&k < size&& board[j][k] && board[j][k]->type == now) {
				j += a[i][0];
				k += a[i][1];
				d[i % 4]++;
			}
		}

		if (d[0] >= length || d[1] >= length || d[2] >= length || d[3] >= length) {
			cout << now << " Success"<<endl;
			return false;
		}

		if (!space) {
			cout << "Dogfall"<<endl;
			return false;
		}

		now = now == 'O' ? 'X' : 'O';

		return true;
	}
};

int main() {
	int size, length;
	cin >> size >> length;
	Board * board = new Board(size,length);

	bool game = true;
	int x, y;
	while (game) {
		cin >> x >> y;
		game = board->place(x, y);
		
	}
	system("pause");
}