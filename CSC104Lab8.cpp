/*
Laura Rosa
CSC104 Lab 8

In this lab, you will be working with classic recursion problems.
There are three separate classic problems that can be solved using
recursion.

Fibonacci:
Create a program that uses recursive function to calculate the fibonacci sequence

Bowling Pins:
There are 5 rows and a total of 15 pins. Write a recursive function
that takes as input the number of rows (n) and outputs the total number
of pins that would exist in a pyramid with n rows.

Towers of Hanoi:
Write a recursive function that describes instructions for a solution
to this problem. You will output a sequence of instructions that will solve
the problem.

*/
#include <iostream>
#include <iomanip>
using namespace std;

void fibonacci(int n);										//Function Prototype of type void
int bowling(int row);										//Function Prototype of type int
void towers(int count, char src, char dest, char spare);	//Function Prototype of type void

int main(){

	int n = 0;
	int row = 0;
	int count = 0;
	char src = 'A', dest = 'C', spare = 'B';

	cout << "Fibonacci Game: " << endl;
	cout << "How many fibonacci numbers do you want: ";
	cin >> n;
	fibonacci(n);

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Bowling Game:" << endl;
	cout << "How many rows do you want: ";
	cin >> row;
	cout << "The total number of pins is: " << bowling(row) << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	cout << "Enter the number of disks to play. I will give the necessary moves: ";
	cin >> count;
	towers(count, src, dest, spare);
	return 0;
}


void fibonacci(int n){
	int a = 1;
	int b = 2;
	if (n == 0 || n == 1){		//Basecase where first two numbers are 1
		cout << 1 << endl;
		if (n == 0){
			return;
		}
		fibonacci(n - 1);
	}
	else{						//any number after the first 2
		for (int i = 2; i < n; i++){
			int temp = b;		//sets temp = 'b' = 2 (at first)
			b = a + b;			//adds 'b' to the number before it
			a = temp;			//sets 'a' to temp which was what 'b' use to be
		}
		fibonacci(n - 1);	
		cout << b << endl;
	}
}


int bowling(int row)
{
	if (row == 1)
		return 1;		//row 1 only has 1 pin
	else
		return (row + bowling(row - 1)); //adds current row to the row-1 after it. returns number of pins
}


void towers(int count, char src, char dest, char spare)
{
	if (count > 0)
	{
		towers(count - 1, src, spare, dest);	//function goes through this until it reaches 0

		cout << "Move a disk from post " << src << " to post " << dest << endl; //outputs after the function reaches 0

		towers(count - 1, spare, dest, src);
	}
}