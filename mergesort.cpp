// In this merge sort, when I tried to merge two sorted subarrays
// into one array, I used recursive merge, which turned out to be 
// even more complicated than a simple loop which takes all kinds
// of situations into careful consideration.
// please refer to the attached mersort.jpg
 
#include<iostream>
#include<vector>
using namespace std;

void push( vector<int>& myArray, int s, int e, vector<int>& auxArray ) {
    for(int i=s;i<=e;i++) {
        auxArray.push_back(myArray[i]);
    }
    return;

}

void merge( vector<int>& myArray, int s, int m, int n, int e, vector<int>& auxArray ) {
    if(s>m) push(myArray,n,e,auxArray);
    else if(n>e) push(myArray,s,m,auxArray);
    else {
        if(myArray[s]<myArray[n] ) {
            auxArray.push_back(myArray[s]);
            s++;
        }
        else {
            auxArray.push_back(myArray[n]);
            n++;
        }
        merge(myArray,s,m,n,e,auxArray);

    }

}

void merge( vector<int>& myArray, int s, int m, int e) {
    vector<int> auxArray;
    merge(myArray,s,m,m+1,e,auxArray);
    for(int i=s;i<=e;i++) {
        myArray[i] = auxArray[i-s];
    }
    return;
}

