#include <iostream>
using namespace std ;

int fib(int n){
	//bc
	if(n==0) return 0 ;
	if(n==1) return 1;
	//rc
	return fib(n-1)+fib(n-2);
}

int main(){
	int n = 0 ;
	cout<<"Enter the position of the fibonnaci: "<<endl ;
	cin>> n ;
	cout<<"The "<<n<<"th fibonnaci is: "<<fib(n)<<endl; 
	return 0;
}