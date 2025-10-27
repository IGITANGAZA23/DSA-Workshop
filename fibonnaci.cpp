#include<iostream>
using namespace std ;
// 0,1,1,2,3,5,8,13,21,34

int fib(int n){
	if(n==0)  return 0 ;
	if(n==1) return 1 ;
	return fib(n-1) + fib(n-2) ;
}


void displayfib(int n){
	for(int i=0 ; i<n;i++){
		cout<<fib(i) << " ";
	}
}

int main(){
	int n =10 ;
	displayfib(n) ;
	return 0 ;
}