#include<iostream>
using namespace std;

void printChars(char str[]){
	if (str[0] == '\0'){
		return;
	}
	cout<<str[0] << " ";
	printChars(str+1);
}

int main(){
	char comment[100]; 
	cout<<"Enter a comment: ";
	//cin.ignore();
	cin.getline(comment,100);
	cout<<"Ya comment: ";
	printChars(comment);
	cout<<endl;
}