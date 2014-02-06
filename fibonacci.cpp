// From this algorithm, I can see that even to decide to use recursive
// algorithm to solve the problem, there are still very brute force
// recursive and smart recursive idea. This algorithm is the most effici// ent and smart recursive algorithm

// also, this recursive algorithm is exactly simulating an iterative
// approach to solve the same problem. Tellning us that a recursive  
// algorithm is equivalent to a iterative algorithm, and iterative 
// algorithm can also be written as a recursive algorithm. 
#include<iostream>

using namespace std;
double helper(int i, int end, double x, double y) {
    if(i==end) return y;
    else return helper(i, end+1,y,x+y);
}

double fib(int i) {
    //if(i==1 || i==2) return 1;
    return helper(i, 1, 0, 1);
}

int main() {
    for(int i=1;i<10;i++)
//  int i=1477;
        cout<<"fib("<<i<<")= "<<fib(i)<<endl;
    return 0;
}

