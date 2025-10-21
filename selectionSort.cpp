#include<iostream>
using namespace std; 


int selectionSort(int arr[], int n){
	for(int  i =0 ; i <n-1 ; i++){
		int target =  i ;
		for(int j = i+1 ; j < n ; j++){
			if(arr[j] < arr[target]){
				target =  j ;
			}
		}
		if(target != i){
			int temp = arr[i] ;
			arr[i] = arr[target] ;
			arr[target] = temp ;
		}
	}
	return 0 ;
}

int main(){
	int arr[] = {20,10,30,50,40} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	cout<<"Unsorted array: " <<endl ;
	for(int i =0  ; i< n ; i++){
		cout<< arr[i] << " ";
	}
	cout<<endl ;
	selectionSort(arr,n) ;
	
	
	cout<<"Sorted array: " <<endl ;
	for(int i =0  ; i< n ; i++){
		cout<< arr[i] << " ";
	}
	
}