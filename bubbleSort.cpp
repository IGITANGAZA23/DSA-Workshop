#include <iostream>
using namespace std; 


int bubbleSort(int Arr[] , int n){
	int count = 0 ;
	bool check = 0;
	for(int i = 0 ; i < n -1 ; i++){
		for(int j= 0 ; j< n-1 ; j++){
			count++ ;
			if(Arr[j]>Arr[j+1]){
				int temp = Arr[j];
				Arr[j] = Arr[j+1] ;
				Arr[j+1] = temp ;
			    check = 1 ;
			}
		}
		cout <<"check: "<< check << endl  ;
	}
	cout <<"count: "<< count <<endl ;
	return 0 ;
}


int main(){
	int Arr[]= {10,20,30,40,50,60} ;
	int n = sizeof(Arr) / sizeof(Arr[0]) ;
	bubbleSort(Arr , n) ;
	for(int i=0 ; i < n ; i++){
		cout<<Arr[i] << " " ;
	}
	return 0 ;
}