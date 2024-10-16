
#include <iostream> // For input/output stream
#include <stdexcept> // For exception handling: throw/catch errors

using namespace std;

//function prototypes
double addition(double num1, double num2);

double subtraction(double num1, double num2);

double multiplication(double num1, double num2);

double division(double num1, double num2);

//main function
int main(void) {
	
	//preform operations until stop
	bool continueLoop = true;
	while (continueLoop == true) { 
    	//get user input
	    double num1, num2;
	    cout << "Please enter 2 numbers separated by spaces: ";
	    cin >> num1 >> num2;

		//choose operations
		int operation;
		cout << "Operation choices: (1) addition, (2) subtraction, (3) multiplication, (4) division" << endl;
		cout << "Enter operation: ";
		cin >> operation;

		double output; //store each output of each iteration in this var

		//preform operations w/in try-catch
		try { //preform operation
			switch(operation) { //use switch statement
				case 1: //addition
					output = addition(num1, num2);
					cout << num1 << " + " << num2 << " = " << output << endl;
					break;
				case 2: //subtraction
					output = subtraction(num1, num2);
					cout << num1 << " - " << num2 << " = " << output << endl;			
					break;
				case 3: //multiplication
					output = multiplication(num1, num2);
					cout << num1 << " * " << num2 << " = " << output << endl;
					break;
				case 4: //division: watch for div by 0
					output = division(num1, num2);
					cout << num1 << " / " << num2 << " = " << output << endl;			
					break;
				default: //wrong input
					cout << "Failure to choose one of the 4 number operation choices. " << endl;
			} //switch
		} catch (invalid_argument& e) { //invalid argument error
			cout << "Try-catch caught the following error: " << e.what() << endl; //print message
		} //try-catch

		//ask if want to continue, use while loop
		bool continueAsk = true;
		while(continueAsk == true) {
			char response;
			cout << "Would you like to perform another operation (y/n): ";
			cin >> response;
			if (response == 'y') {
				cout << "Starting calculator over again..." << endl;
				continueAsk = false; //stops inner while loop
			} else if (response == 'n') {
				cout << "Exiting calculator..." << endl;
				continueAsk = false; //stops inner while loop
				continueLoop = false; //stops outer while loop
			} else {
				cout << "Incorrect input: Please try again." << endl;
			} //if
		} //while

	} //while
	return 0; //return main on sucess 
} //main

//function implementation
double addition(double num1, double num2) {
	return num1 + num2;
} //addition

double subtraction(double num1, double num2) {
	return num1 - num2;	
} //subtraction

double multiplication(double num1, double num2) {
	return num1 * num2;	
} //multiplication

double division(double num1, double num2) {
	if (num2 != 0) { //check for division by 0
		return num1 / num2;
	} else { //trying to divide by 0, throw exception
		throw invalid_argument("Division by 0 is not allowed.");
	} //if
} //division