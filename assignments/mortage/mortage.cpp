/**************
 * Program: assignment1.cpp or mortage.cpp
 * Author: Riley Rice
 * Date: 4/04/2022
 * Description: This is a mortage calculator which will calculate your mortage payments per month and overall money spent and interest paid over
 * the lifetime of the loan.
 * Input: The inputs include the overallprice of the house (dollars), the downpayment on the loan (dollars), the length of time before the loan is paid off (years), and then
 * the annual interest rate(percent).
 * Output: The output of the program is the estimated monthly payment on the mortage loan (dollars), the total amount of money paid over the loan (dollars), the principal
 * paid (dollars), and the interest paid over the lifetime of the loan (dollars).
 **************/

#include <iostream>
#include <math.h>
#include <iomanip>

//used standard namespace for all functions since there aren't a lot of functions being used in this function and there is a lot of prompts and outputs.
using namespace std;

/***************
 * Function: month_mortage()
 * Description: It takes in the price of a house, your downpayment on a house, the length of the loan, and the interest rate
 * and then returns your expected monthly mortage price.
 * Parameters: overallprice of the house as a double, the downpayment your expecting to pay as a double, the length of your loan
 * as a double, and your annual interest rate as a double.
 * Pre-conditions: It needs the overallprice, downpayment, and length as valid doubles. It also needs the annualinterestrate to be converted
 * from percentage to decimal (this is done by diving the percentage by 100 beforehand.
 * Post-conditions: It then returns the final monthly mortage price as a double. 
 ***************/
double month_mortage(double overallprice, double downpayment, double length, double annualinterestrate) {
	//get the princpal for calculation
	double principal = overallprice - downpayment;

	// Divide the annual interest rate by 12 to get the monthly rate.
	double interest = annualinterestrate / 12.0;
	
	//get the length in months for the formula
	double month_length = length * 12.0;

	//used this so it would look cleaner in the formula when using the pow() function
	double base = interest + 1.0;

	/* For this calculation I used the formula for monthly interest rate which is the
	*  (principal loan amount * (the monthly interest rate * (monthly interest rate)
	*  to the power of the (amount of months) all divided by the interest + 1 to the power 
	*  of the month length - 1. */
	double final_mortage = (principal * interest * pow(base, month_length)) / (pow(base, month_length) - 1.0);

	return final_mortage;
}

int main() {

	// prompt the users so they know what program their using and what it is.
	cout << endl;
	cout << "Hello, and welcome to the mortage calculator!" << endl << endl;
	
	//initialize variables
	bool outputs = true;
	double overallprice, downpayment, length, annualinterestrate;

	while (outputs) {
		//get the overall price of the house
		cout << "Enter the home price, in dollars: ";
		cin >> overallprice;
		cout << endl;

		/* get the other inputs of the program such as the down payment, length of loan,
		*  and interest rate */
		cout << "Enter the down payment, in dollars: ";
		cin >> downpayment;

		if (overallprice < downpayment) {
			cout << endl << "The down payment shouldn't be larger than the overall price, try again." << endl << endl;
			continue;
		}

		cout << "Enter the length of loan, in years: ";
		cin >> length;

		/* for the interest rate it is given in percentages and we have to convert it to decimal
		*  so after recieving the interest rate from the user in percentage I then divide it by 100 to
		*  turn it into decimal so that it can be used in the calculation of the month_mortage() function. */
		cout << "Enter the annual interest rate, in percentage: ";
		cin >> annualinterestrate;
		cout << endl;
		annualinterestrate /= 100.0;

		/* Call the monthly mortage function with the variables given earlier on and store it in a variable called
		*  mortage so that I can output the monthly amount and then use that amount to calculate the other variables
		*  such as the total money paid and the principal and interest paid. I calculated the total paid by mutliplying
		*  the length in years by 12 to get the amount of months for the loan and then multiply that by the monthly mortage
		*  cost to get the total amount paid over the loan. Then you can use that to find the total principal and interest paid.*/
		double mortage = month_mortage(overallprice, downpayment, length, annualinterestrate);
		double totalpaid = mortage * (12.0 * length);
		double principal = overallprice - downpayment;
		double interestpaid = totalpaid - principal;

		/* Here I output all the calculations for the user in a structured manner so they know which peice of
		*  information is being displayed. */
		cout << "Your estimated monthly payment is: $" << fixed << setprecision(2) << mortage << endl;
		cout << "Total Paid: $" << fixed << setprecision(2) << totalpaid << endl;
		cout << "Principal Paid: $" << fixed << setprecision(2) << principal << endl;
		cout << "Interest Paid: $" << fixed << setprecision(2) << interestpaid << endl;

		//I finish it off with thanking them for using the program and also letting them know that the program is over and was succesful.
		cout << endl << endl;
		cout << "Thanks for using the mortage calculator!";
		cout << endl << endl;
		break;
	}
	return 0;
}
