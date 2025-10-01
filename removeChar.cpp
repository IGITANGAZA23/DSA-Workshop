#include <iostream>
#include<cstring>
using namespace std;

void printChars(char str[], char value){
	//int s = strlen(str)- 1;
	if (str[0] == '\0')return;
	if(str[0]!=value) cout<<str[0] + " ";
	printChars(str+1 , value);
	
	/*for(int i =0; i<strlen(str) ; i++){
		if(str[i]!=value){
			cout<<str[i] << " ";
		}else{
			continue;
		}
	}*/
	
}

int main(){
	char a = 'a';
	char comment[100]; 
	cout<<"Enter a comment: ";
	//cin.ignore();
	cin.getline(comment,100);
	cout<<"Ya comment: ";
	printChars(comment, a);
	cout<<endl;
}