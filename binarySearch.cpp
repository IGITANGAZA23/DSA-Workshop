#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
	
	void printArr(int arr[] , int length){
    	for(int i = 0; i< length;i++ ){
		
			cout<<arr[i] << " " ;
	    }		
    }
	
	
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9} ;
	int key = 1 ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	int found = binarySearch(arr , n , key) ;
	
    if(found != -1){
    	cout<<"Element "<<key<<" Found at index " <<found<<endl ;
	}else{
		cout<<"Element "<<key<<" not found"<<endl ;
	}
	printArr(arr,n) ;
}