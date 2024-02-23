#include <iostream>
using namespace std;
bool authenticateUser(int inputAccountNumber, int inputPin);
void displayMenu();
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);
int main() {
int inputAccountNumber,inputPin;
double balance = 100000.00;
int incorrectPins = 5;
while (incorrectPins > 0) {
cout << "Enter Your Account Number: ";
cin >> inputAccountNumber;
cout << "Enter PIN: ";
cin >> inputPin;
if (authenticateUser(inputAccountNumber, inputPin)) {
displayMenu();
int choice;
do {
cout << "Enter your choice (1-4): ";
cin >> choice;
switch (choice) {
case 1:
checkBalance(balance);
break;
case 2:
balance = deposit(balance);
break;
case 3:
balance = withdraw(balance);
break;
case 4:
cout << "Exiting ATM. Thank you!\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
break;
}
}
while (choice != 4);
break;
}
else
{
incorrectPins--;
if (incorrectPins > 0)
{
cout << "Incorrect account number or PIN. " << incorrectPins <<
" attempts remaining.\n";
}
else
{
cout << "Too many unsuccessful attempts. Your account is locked. Please contact your bank.\n";
}
}
}
return 0;
}
bool authenticateUser(int inputAccountNumber, int inputPin)
{
bool result;
if(inputAccountNumber == 4521 && inputPin == 9001)
{
result=true;
}
else{
result=false;
}
return result;
}
void displayMenu() {
cout <<"*****************************"<<endl;
cout <<"** ATM Menu **"<<endl;
cout <<"*****************************"<<endl;
cout <<"** 1. Check Balance **"<<endl;
cout <<"** 2. Deposit **"<<endl;;
cout <<"** 3. Withdraw **"<<endl;;
cout <<"** 4. Exit **"<<endl;;
cout <<"*****************************"<<endl;
}
void checkBalance(double balance) {
cout << "Current Balance: Rs" << balance << "\n";
}
double deposit(double balance) {
double amount;
cout << "Enter the deposit amount: Rs";
cin >> amount;
if (amount > 0) {
balance = balance+amount;
cout << "Deposit successful. New balance: Rs" << balance << "\n";
}
else
{
cout << "Invalid deposit amount. Please enter a positive value.\n";
}
return balance;
}
double withdraw(double balance) {
double amount;
cout << "Enter the withdrawal amount: Rs";
cin >> amount;
if (amount > 0 && amount <= balance)
{
balance =balance-amount;
cout << "Withdrawal successful. New balance: Rs" << balance << "\n";
}
else if (amount > balance)
{
cout << "Insufficient balance. Withdrawal amount exceeds current balance.\n";
}
else
{
cout << "Invalid withdrawal amount. Please enter a positive value.\n";
}
return balance;
}
