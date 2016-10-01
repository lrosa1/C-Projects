/*
Laura Rosa
CSC104 Lab 3

In this lab, work with a class that models the billing service
of a cellular phone company. The class will utilize constructors
to initialize data members appropriately. It will use static data members to share
data between class objects.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

class cellphone{
public:
	cellphone();						//Constructor (default)
	cellphone(int);						//Constructor
	cellphone(unsigned int, int);		//Constructor
	void makecall(int);					//Log call information
	void printbill();					//Print Monthly bill
	bool overage();						//Check to see if user has overage
	void printstats();					//Print stats for all users

private:
	int calls[100];						//Call history
	int numcalls;						//Number of calls made
	int allowance;						//"Free" minutes each month
	unsigned int phonenumber;			//Customer's phone number
	static unsigned int nextphone;		//Assigned phone number
	static int totalminutes;			//Combined minutes of all users
	static double totalcharges;			//Combined charges of all users

};
unsigned int cellphone::nextphone = 4015550000;		//Initialize Static Data Member
int cellphone::totalminutes = 0;					//Initialize Static Data Member
double cellphone::totalcharges = 0;					//Initialize Static Data Member


cellphone::cellphone(){								
	numcalls = 0;
	allowance = 500;
	phonenumber = nextphone;
	nextphone++;									//Increments Number for Next User
}
cellphone::cellphone(int allowancemins){
	numcalls = 0;
	allowance = allowancemins;						//Allows for a new allowance other than the default
	phonenumber = nextphone;
	nextphone++;

}
cellphone::cellphone(unsigned int num, int allowancemins){
	numcalls = 0;
	allowance = allowancemins;
	phonenumber = num;								//Phone number set up already (see Ethel)
}

void cellphone::makecall(int callmin){
	calls[numcalls] = callmin;						//Keeps track of number of calls & its the length
	numcalls++;
}

bool cellphone::overage(){
	int sum = 0;
	for (int i = 0; i < numcalls; i++){
		sum = sum + calls[i];
	}

	if (sum > allowance)							
		return true;
	else
		return false;
}

void cellphone::printbill(){
	int minsused=0;
	double sumcharge = 0;
	int sum = 0;
	int avgduration = 0;

	cout << "Phone Number: " << phonenumber << endl;

	for (int i = 0; i < numcalls; i++){
		minsused = minsused + calls[i];
	}

	totalminutes = totalminutes + minsused;
	sum = allowance - minsused;

	cout << "The total number of minutes used is " << minsused << " minutes." << endl;
	cout << "Your monthly allowance is " << allowance << " minutes." << endl;

	if (sum < 0){
		sumcharge = 99.99 + (abs(sum)*1.25);
	}
	else
		sumcharge = 99.99;

	totalcharges = totalcharges + sumcharge;

	cout << "Your total bill is $" << sumcharge << " for the month. " << endl;

	for (int i = 0; i < numcalls; i++){
		if (calls[0] < calls[i]){
			calls[0] = calls[i];
		}
	}

	cout << "The duration of your longest phone call was: " << calls[0] << " minutes." << endl;

	avgduration = minsused / numcalls;
	cout << "The average duration your a phone calls was: " << avgduration << " minutes." << endl;

}
void cellphone::printstats(){
	cout << "The total number of minutes used by all customers are " << totalminutes << " minutes." << endl;
	cout << "The total bill charge of all the customers is $" << totalcharges << endl;
}

int main(){
	
	cellphone lucy;
	cellphone ricky(1000);
	cellphone ethel(4018655555, 2000);

	lucy.makecall(24);							//Length of Lucy's first call is 24 minutes
	lucy.makecall(500);
	lucy.makecall(30);
	if (lucy.overage() == true)
		cout << "Lucy went over her minutes." << endl;
	else
		cout << "Lucy did not go over her minutes." << endl;
	lucy.printbill();
	cout << endl;


	ricky.makecall(60);
	ricky.makecall(1000);
	ricky.makecall(87);
	if (ricky.overage() == true)
		cout << "Ricky went over his minutes." << endl;
	else
		cout << "Ricky did not go over his minutes." << endl;
	ricky.printbill();
	cout << endl;


	ethel.makecall(12);
	ethel.makecall(60);
	ethel.makecall(150);
	if (ethel.overage() == true)
		cout << "Ethel went over her minutes." << endl;
	else
		cout << "Ethel did not go over her minutes." << endl;
	ethel.printbill();
	cout << endl;

	cout << "STATISTICS FOR ALL CUSTOMERS: " << endl;
	ricky.printstats();
	cout << endl;

	return 0;
}