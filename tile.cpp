/*
Suppose we wish to count how many ways there are to tile a 1 * n
rectangle using 1 * 1, 1 * 2, 1 * 3, and 1 * 4 blocks. (The order
of the tiles matters.) For example, there are 29 ways to tile a 1  6
rectangle, as shown in Figure 1.
Figure 1: Tilings of a 1 * 6 rectangle
Let t(n) denote the number of ways to tile a 1 * n rectangle
using blocks of length 1, 2, 3, and 4. For example, t(6) = 29.
(a) Write down a recurrence for t(n).
(b) Find t(100).
*/
#include<iostream>
#include<assert.h>
using namespace std;

int tile(int n) {
	assert(n>=0);
	if(n==0) return 1;
	else {
		int r = tile(n-1);
		if(n>1) r += tile(n-2);
		if(n>2) r += tile(n-3);
		if(n>3) r += tile(n-4);
		return r;
	}

}

int main() {
	int n;
	cout<<"what's n?"<<endl;
	cin>>n;
	while(n != 0) {
		cout<<"the number of ways to cover 1*"<<n<<" tile is "<<tile(n);
		cout<<endl<<"what other n's do you want to check ?"<<endl;
		cin>>n;
	}
	return 0; 	

}

