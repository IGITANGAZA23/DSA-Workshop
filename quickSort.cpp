#include<iostream>
using namespace std;
void swap(int arr[] , int i,int j){
	int temp = arr[i] ;
	arr[i] = arr[j] ;
	arr[j] = temp ;
}
int partition(int arr[],int low , int high){
	int pivot = arr[high] ;
	int i = low-1 ;
	for(int j=low ; j<=high-1 ; j++){
		if(arr[j]<pivot){
			i++ ;
			swap(arr,i ,j) ;
		}
	}
	swap(arr ,i+1 , high) ;
	return i+1 ;

}


void quickSort(int arr[] , int low , int high){
	if(low<high){
		int pi = partition(arr , low , high) ;
		quickSort(arr, low, pi-1) ;
		quickSort(arr, pi+1 , high) ;
	}
}

void printArr(int arr[] , int length){
    	for(int i = 0; i< length;i++ ){
		
			cout<<arr[i] << " " ;
	    }
			
}

int main(){
	int arr[] = {3,4,6,1,5,9,8,7,2} ;
	int low = 0 ;
	int length = sizeof(arr)/sizeof(arr[0]) ;
	int high = length -1 ;
	quickSort(arr, low, high) ;
	printArr(arr,length) ;

}