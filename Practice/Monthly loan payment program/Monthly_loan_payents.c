/* This program calculates how much the user pays monthly for a loan

You have saved $500 to use as a down payment on a car.
Before beginning your car shopping, you decide to write a program to help you figure out what your monthly payment will be,
given the car’s purchase price, the monthly interest rate, and the time period over which you will pay back the loan.
The formula for calculating your payment is 
payment = (iP)/[1-(1+i)^(-n)]

 where 
P = principal (the amount you borrow) 
i = monthly interest rate ( 1/12 of the annual rate) 
n = total number of payments 
Your program should prompt the user for the purchase price,
the down payment,
the annual interest rate
and the total number of payments (usually 36, 48, or 60).
It should then display the amount borrowed and the monthly payment including a dollar sign and two decimal places

Written by John Akujobi
3rd of October 2022
*/

#include <stdio.h>
#include <math.h>

void printWelcome ();

float getPurchasePrice ();

float getDownPayment ();

float getAnnualInterest ();

float getTotalNumPayments ();

float calcMonthlyInterest(float annualInt);

float calcPrincipal (float purchasePrice, float downPay);

float calcMonthlyPayments (float principal, float monthlyInt, float numPay );

void printResults (float purchasePrice, float downPay, float annualInt, float numPay, float monthlyPay);


int main ()
{
    float purchasePrice, annualInt, downPay, monthlyInt, numPay, monthlyPay, principal;

    printWelcome ();

    purchasePrice = getPurchasePrice ();

    downPay = getDownPayment ();

    annualInt = getAnnualInterest ();

    numPay = getTotalNumPayments ();

    principal = calcPrincipal ( purchasePrice, downPay);
//    printf ("principal of %f", principal);

    monthlyInt = calcMonthlyInterest(annualInt);

    monthlyPay = calcMonthlyPayments ( principal, monthlyInt, numPay);
//    printf ("Monthly pay of %f", monthlyPay);

    printResults (purchasePrice, downPay, annualInt, numPay, monthlyPay);

    return 0;
}

//prints a welcome and purpose statement
void printWelcome ()
{
    printf ("\nHello there! \nThis program calculates the monthly payments for your Car or Loan\n\n");
    return;
}

//gets the Purchase Price
float getPurchasePrice ()
{
    float purchasePrice;
    printf ("What is the total price of the purchase? e.g 700 \n");
    printf ("Type it here --->:");
    scanf ("%f", &purchasePrice);
    printf ("\n");

    return purchasePrice;
}

//gets the Payment paid down by the user
float getDownPayment ()
{
    float downPay;
    printf ("How much was the Down Payment? e.g 150 \n");
    printf ("Type it here --->:");
    scanf ("%f", &downPay);
    printf ("\n");

    return downPay;
}

float getAnnualInterest ()
{
    float annualInt;
    printf ("What is the annual interest? e.g 21.6 \n");
    printf ("Type it here --->:");
    scanf ("%f", &annualInt);
    printf ("\n");

    return annualInt;
}

//receives the total number of 
float getTotalNumPayments ()
{
    float numPay;
    printf ("How many payments will there be? e.g 23 \n");
    printf ("Type it here --->:");
    scanf ("%f", &numPay);
    printf ("\n");

    return numPay;
}

//Calculates the principal of amount borrowed by subtracting the downpayment from the Purchase Price
float calcPrincipal (float purchasePrice, float downPay)
{
    float principal;
    principal = purchasePrice - downPay;

    return principal;
}

//Calculates the Monthly Interest by diving the Annual Interest by 12
float calcMonthlyInterest(float annualInt)
{
    float monthlyInt;
    monthlyInt = (annualInt/12.0);
//  printf ("\n monthlyInt of %f\n", monthlyInt);
    return monthlyInt;
}

//Calculates the monthly pay using the principal, monthly interest and number of payments
float calcMonthlyPayments (float principal, float monthlyInt, float numPay )
{
    float monthlyPay;
    monthlyPay = (  (principal *  monthlyInt) / (1.0 - pow( (1.0 + monthlyInt), (- (numPay)))));

    return monthlyPay;
}

//This prints out the Purchase Price, Down Paynment, Annual Interest, Number of Payments and Monthly Pay calculated
void printResults (float purchasePrice, float downPay, float annualInt, float numPay, float monthlyPay)
{
    printf ("For a:\n");
    printf ("Purchase price of          $%8.2f\n", purchasePrice);
    printf ("Down payment of            $%8.2f \n", downPay);
    printf ("Annual Interest of         %8.2f \% \n", annualInt);
    printf ("Number of payments         %8.2f \n", numPay);
    printf ("\n");
    printf ("Your monthly payment is    $%8.2f \n", monthlyPay);
    printf ("\n");
    
    return;
}
