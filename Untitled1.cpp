#include<iostream>
using namespace std;

int countO(int number , int digit){
	if(number == 0) return 0 ;
	int last = number%10 ;
	return (last==digit ? 1: 0) + countO(number/10 , digit) ;
}

int findL(int number){
	int largest = 0 ;
	while(number>0){
		int digit = number % 10 ;
		if( digit > largest) largest = digit ;		
		number/=10;
	}
	return largest ;
}


int main() {
	int number = 1226 ;
	int digit = 2 ;
	int c =countO(number, digit); 
	int L = findL(number) ;
	cout<<L<<endl;
	return 0;
}