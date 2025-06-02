/******************************************************************************
# Author:            Ari Pollack and Xavier Braker
# Lab:               Discussion 8
# Date:              June 2, 2025
# Description:       This program gets the user's monthly income and expenses,
                     then calculates how much they're over or under budget.
# Input:             pensionInc (double), socialSecurityInc (double), miscInc
                     (double), groceryExp (double), powerExp (double), miscExp
                     (double)
# Output:            monthlyDiff (double)
# Sources:           Discussion 8 specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Declare core functions, which are defined after main
void Welcome();
void GetInput(string prompt, double& val);
void GetIncome(double& pensionInc, double& socialSecurityInc, double& miscInc, double& monthlyInc);
void GetExpenses(double& groceryExp, double& powerExp, double& miscExp, double& monthlyExp);
void CalcDifference(double monthlyInc, double monthlyExp, double& monthlyDif);
void PrintResults(double& monthlyDiff);
void Goodbye();

int main() {
   // Declare variables for input and output
   double pensionInc = 0.0;
   double socialSecurityInc = 0.0;
   double miscInc = 0.0;
   double groceryExp = 0.0;
   double powerExp = 0.0;
   double miscExp = 0.0;
   double monthlyInc = 0.0;
   double monthlyExp = 0.0;
   double monthlyDiff = 0.0;

   // Set floating point precision to 2 decimals for output
   cout << fixed << setprecision(2);

   // Print a welcome message
   Welcome();
   cout << endl;
   // Get the user's monthly income
   GetIncome(pensionInc, socialSecurityInc, miscInc, monthlyInc);
   cout << endl;
   // Get the user's monthly expenses
   GetExpenses(groceryExp, powerExp, miscExp, monthlyExp);
   cout << endl;
   // Calculate the difference between the user's income and expenses
   CalcDifference(monthlyInc, monthlyExp, monthlyDiff);
   // Print the results
   PrintResults(monthlyDiff);
   cout << endl;
   // Print a goodbye message
   Goodbye();
   cout << endl;

   return 0;
}

// Name:    Welcome()
// Desc:    This function prints a welcome message
// Input:   None
// Output:  Text
// Return:  void
void Welcome() {
   cout << "Welcome to the Monthly Expenses Calculator. For any prompt, enter 0 if not applicable." << endl;
}

// Name:    GetInput()
// Desc:    This function reads a double from the user, representing monthly income or expenses
// Input:   val (double)
// Output:  prompt (string)
// Return:  void
void GetInput(string prompt, double& val) {
   cout << prompt;
   cin >> val;
   while (cin.fail() || val < 0.0){
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid input! Please try again." << endl;
      cout << prompt;
      cin >> val;
   }
}

// Name:    GetIncome()
// Desc:    This function uses GetInput() to read three sources of monthly income from the user
// Input:   pensionInc (double), socialSecurityInc (double), miscInc (double)
// Output:  prompt (string)
// Return:  void
void GetIncome(double& pensionInc, double& socialSecurityInc, double& miscInc, double& monthlyInc) {
   GetInput("Enter monthly pension: $", pensionInc);
   GetInput("Enter monthly social security: $", socialSecurityInc);
   GetInput("Enter additonal monthly income: $", miscInc);
   monthlyInc = pensionInc + socialSecurityInc + miscInc;
   cout << "Your monthly income totals to $" << monthlyInc << endl;
}

// Name:    GetExpenses()
// Desc:    This function uses GetInput() to read three sources of monthly expenses from the user
// Input:   groceryExp (double), powerExp (double), miscExp (double)
// Output:  prompt (string)
// Return:  void
void GetExpenses(double& groceryExp, double& powerExp, double& miscExp, double& monthlyExp) {
   GetInput("Enter monthly grocery expenses: $", groceryExp);
   GetInput("Enter monthly power expenses: $", powerExp);
   GetInput("Enter additonal monthly expenses: $", miscExp);
   monthlyExp = groceryExp + powerExp + miscExp;
   cout << "Your monthly expenses total to $" << monthlyExp << endl;
}

// Name:    CalcDifference()
// Desc:    This function calculates the difference between monthlyIncome and monthlyExpenses
// Input:   None
// Output:  None
// Return:  void
void CalcDifference(double monthlyInc, double monthlyExp, double& monthlyDiff) {
   monthlyDiff = monthlyInc - monthlyExp;
}

// Name:    PrintResults()
// Desc:    This function prints the difference between monthlyIncome and monthlyExpenses
// Input:   None
// Output:  monthlyDiff (double)
// Return:  void
void PrintResults(double& monthlyDiff) {
   if (monthlyDiff < 0.0) {
      cout << "Your expenses are higher than your income! You need $";
   }
   else if (monthlyDiff == 0.0) {
      cout << "Your expenses are equal to your income." << endl;
      return;
   }
   else if (monthlyDiff > 0.0) {
      cout << "Your income is higher than your expenses. You're left with $";
   }
   monthlyDiff = fabs(monthlyDiff);
   cout << monthlyDiff << endl;
}

// Name:    Goodbye()
// Desc:    This function prints a goodbye message
// Input:   None
// Output:  Text
// Return:  void
void Goodbye() {
   cout << "Thanks for using the Monthly Expenses Calculator." << endl;
}