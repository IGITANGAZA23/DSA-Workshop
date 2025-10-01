#include<iostream>
using namespace std; 

class Person{
	public:
	string firstname ;
	string lastname ;
	int age ;
	Person(){} ;
	Person(string fname , string lname , int a){
		firstname = fname ;
		lastname = lname ;
		age = a ;
	};
	void printMe(){
		cout<<firstname<<" "<<lastname << " is "<<age<<" years old!"<<endl ;
	}
};


int main(){
	Person person1("ange" , "mugisha", 15);
	Person person2{"peter", "Neza", 18};
	Person person3 = {"mary", "ruza", 20};
	Person* person4 = new Person("patrick", "paul", 12);
	Person person5;
	person5.firstname = "Samuel";
	person5.lastname = "Manuel";
	
	person3.printMe();
}
