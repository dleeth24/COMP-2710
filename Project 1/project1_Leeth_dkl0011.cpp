/* FILE NAME: project1_Leeth_dkl0011.cpp
* AUTHOR: Davis Leeth (dkl0011@auburn.edu)
*
* Complile: g++ project1_Leeth_dkl0011.cpp -o p1.out 	
* Run: ./p1.out 
*
* Comments: Used Dr. Li's hints for help.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
   // VARIABLE INITIALIZATION
   double loanAmount = 0;
   double interestRate = 0;
   double interestRateC = 0;
   double monthlyPayments = 0;
   int currentMonth = 0;
   double interestTotal = 0;
   double principal = 0;
   double interest = 0;
   double finalPayment = 0;

   // CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // USER INPUT
   cout << "\nLoan Amount: ";
   cin >> loanAmount;
   //Checks if the input is valid
   if (loanAmount <= 0 || cin.fail()) {
      cout << "Invalid loan" << endl;
      exit(0);  //Exits the program
   }
   double initialLoan = loanAmount;

   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   //Checks if the input is valid
   if (interestRate < 0 || cin.fail()) {
      cout << "Invalid interest rate" << endl;
      exit(0);   //Exits the program
   }

   interestRate /= 12;
   interestRateC = interestRate / 100;
   double minPayment = loanAmount * interestRateC;
   cout << "Monthly Payments: ";
   cin >> monthlyPayments;
   //Checks if the input is valid
   if (cin.fail() || monthlyPayments <= 0) {
      cout << "Invalid payment" << endl;
      exit(0);    //Exits the program
   }
   //Checks if the input is valid
   if (monthlyPayments <= minPayment) {
      cout << "Insufficient payment" << endl;
      exit(0);   //Exits the program
   }

   cout << endl;

   //Heading of the table
   cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
   //Loop that goes while there is still an amount left to be paid
   while (loanAmount > 0) {
      //Heading of the first month of payment
      if (currentMonth == 0) {
         cout << currentMonth << "\t$" << loanAmount;
         if (loanAmount < 1000) cout << "\t";
            cout << "\t" <<  "N/A\tN/A\tN/A\t\tN/A\n";
      }
      else {
         //CALCULATIONS AND AMORTIZATION TABLE
         interest = interestRateC * loanAmount;
         interestTotal += interest;
         principal = monthlyPayments - interest;
         loanAmount -= principal;
         if (loanAmount < monthlyPayments && loanAmount > 0) {
            finalPayment = loanAmount;
         }
         if (monthlyPayments > loanAmount + interest) {
            principal = loanAmount + interest;
         }
         //If there is only one month of payment needed
         if (monthlyPayments > loanAmount && currentMonth == 1) {
            principal = initialLoan;
            loanAmount = 0;
            if (monthlyPayments >= 1000) {
                  cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments
               << interestRate << "\t$"
               << interest << "\t\t$" << principal << endl;
               }
            else {
            cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
            << "\t" << interestRate << "\t$"
            << interest << "\t\t$" << principal << endl;
            }
            break;
         }
         //This is for the second to last payment when the balance is less than the payment
         if (loanAmount * (1 + interestRateC) < monthlyPayments) {
            if (monthlyPayments >= 1000) {
               if (interestRate == 0) {
                  cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
               << interestRate << "\t$"
               << interest << "\t\t$" << monthlyPayments << endl;
               break;
               }
               
               else {
                  cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
               << "\t" << interestRate << "\t$"
               << interest << "\t\t$" << principal << endl;
               }
            }
            else {
               if (interestRate == 0) {
               cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
            << "\t" << interestRate << "\t$"
            << interest << "\t\t$" << monthlyPayments << endl;
            break;
               }
               else {
            cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
            << "\t" << interestRate << "\t$"
            << interest << "\t\t$" << principal << endl;
            interest = interestRateC * loanAmount;
            monthlyPayments = loanAmount - interest;
            loanAmount = 0;
               }
            }
         }
         //This is the default information that goes into the table for each month
         if (loanAmount * (1 + interestRateC) >= monthlyPayments) {
            if (loanAmount < 1000) {
               if (monthlyPayments >= 1000) {
                  cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
               << interestRate << "\t$"
               << interest << "\t\t$" << principal << endl;
               }
               else {
                  cout << currentMonth << "\t$" << loanAmount << "\t\t$" << monthlyPayments 
                  << "\t" << interestRate << "\t$"
                  << interest << "\t\t$" << principal << endl;
               }
            }
            else {
               cout << currentMonth << "\t$" << loanAmount << "\t$" << monthlyPayments 
               << "\t" << interestRate << "\t$"
               << interest << "\t\t$" << principal << endl;
            }
         }
         //This is for the very last line of the table
         if (loanAmount <= 0 && principal != 0) {
            principal = finalPayment;
            if (monthlyPayments >= 1000) {
                  cout << currentMonth + 1 << "\t$" << loanAmount << "\t\t$" << finalPayment + interest 
               << interestRate << "\t$"
               << interest << "\t\t$" << principal << endl;
               }
            else {
            cout << currentMonth + 1 << "\t$" << loanAmount << "\t\t$" << finalPayment + interest << "\t"
            << interestRate << "\t$" << interest << "\t\t$" << principal << endl;
            interestTotal += interest;
            }
         }
      }
      currentMonth++;
   }
   //For only one month
   if (currentMonth == 1) {
      cout << "****************************************************************\n"; 
      cout << "\nIt takes 1 month to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
      cout << endl << endl;  
   }
   //For multiple months
   else {
      cout << "****************************************************************\n"; 
      cout << "\nIt takes " << currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
      cout << endl << endl;  
   }

   return 0;
   
}