#include<iostream>
using namespace std ;
// 64
int power(int base , int exp){
	if(exp==0) return 1 ;
	if(exp==1) return base ;
	return base*power(base , exp -1) ;
}

int main(){
	int base = 2 ;
	int exp = 6 ;
	int ans = power(base,exp) ;
	cout<<ans<<endl ;
}