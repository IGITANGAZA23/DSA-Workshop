#include <iostream>
//#include <ctime>
#include<cmath>
#include<vector>
using namespace std ;
bool isPrime(int n){
	if(n<2) return false ;
	if(n==2) return true ;
	if(n%2==0) return false ;
	int limit = sqrt(n);
	for(int i=3;i<=limit; i+= 2){
		if(n % i == 0) return false;
	}return true ;
}
void prime(int n){
	vector<int> primes;
	int count=0 ;
	int current = 0 ;
	while(count <=n){
		current++ ;
		if(isPrime(current)){
			primes.push_back(current) ;
			count++;
		}
	}
	cout<< "The all primes are: " <<endl;
    for(int i =0 ; i < sizeof(primes)/sizeof(primes[0]) ; i++){
    	cout<< primes[i] << " " << endl ;
	}	
	cout << "The " <<n <<"th primes is " << current <<endl ;
}

int main(){
	int n ;
	cout<<"Input a number : ";
	cin>> n ;
	prime(n);
	return 0 ;
}
