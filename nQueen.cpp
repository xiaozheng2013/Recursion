//From this code, you can see what does recursive BACKTRACING means,
//and also the technique to simplify task is also impressive :)
// this code would solve the n-Queen problem, 
// the code would record the number of solutions to 
// the size-n problem, and print out the board. 

// Note: this is only one board, this is the advantage 
// of recursive BACKTRACING. 
#include<iostream>
#include<vector>

using namespace std;

static int N;
static bool board[20][20];
static bool col[20];
static bool updiag[39]; //they have the same sum
						//whose range is [0..2n-2]
static bool dndiag[39];//they have the same difference 
						//whose range is [1-n..n-1]
				// but (n-1) + row - col in [0, 2n-2]

void display( bool board[20][20], int n ) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(board[i][j]) cout<<"Y ";
			else cout<<"N ";
		}
		cout<<endl;
	}

}

bool qualify(int n, int i, int j) {
	if(col[j] || updiag[i+j] || dndiag[n-1 + i - j] )
		return false;
	else return true;

}

void onBoard(int n, int i, int j) {
	board[i][j] = true;
	col[j] = true;
	updiag[i + j] = true;
	dndiag[n - 1 + i - j] = true;
}

void offBoard(int n, int i, int j) {
	board[i][j] = false; 
	col[j] = false;
	updiag[i + j] = false; 
	dndiag[n - 1 + i - j] = false;
}

void placeChess(int i, int n) {
	if(i == n) {
		display(board,n);
		cout<<endl;
		N++;
		return;
	}
		
	for(int j=0;j<n;j++) {
		if( qualify(n,i,j) ) {
			onBoard(n,i,j);	
			placeChess(i+1, n);
			offBoard(n,i,j);
		}
	}

}

void nQueen(int n) {
	placeChess(0,n);	
	return;
}

int main() {
	cout<<"what's the size ?"<<endl;
	int n;
	cin>>n;
	while(n>0) {
		nQueen(n);
		cout<<"there are "<<N<<" many solutions."<<endl;
		cout<<"what's the size ?"<<endl;
		cin>>n;
		N=0;
	}
	return 0;

}

