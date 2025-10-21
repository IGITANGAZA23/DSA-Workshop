#include<iostream>
using namespace std;


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key in its correct position
        arr[j + 1] = key;
    }
}


int main(){
	int arr[] = {20,10,30,50,40} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	cout<<"Unsorted array: " <<endl ;
	for(int i =0  ; i< n ; i++){
		cout<< arr[i] << " ";
	}
	cout<<endl ;
	insertionSort(arr,n) ;
	
	
	cout<<"Sorted array: " <<endl ;
	for(int i =0  ; i< n ; i++){
		cout<< arr[i] << " ";
	}
	
}