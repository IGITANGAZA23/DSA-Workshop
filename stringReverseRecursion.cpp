#include <iostream>
#include<cstring>
using namespace std;

void printReverseChars(char str[]){
	//int s = strlen(str)- 1;
	if (str[0] == '\0'){
		return;
	}
	printChars(str+1);
	cout<<str[0] << " ";
	
}

int main(){
	char comment[100]; 
	cout<<"Enter a comment: ";
	//cin.ignore();
	cin.getline(comment,100);
	cout<<"Ya comment: ";
	printReverseChars(comment);
	cout<<endl;
}