#include "income.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
Income::Income(){
    int choice = 0;
    cout << "Name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Paid per hour? yes/no: ";
    cin >> choice;
    if(choice >= 0){
        cout << "Yes chosen. ";
        perHour = true;
        cout << "Wage: ";
        cin.ignore();
        cin >> hourly;
        cout << "Net Hours: ";
        cin.ignore();
        cin >> hours;
    } else {
        cout << "No chosen. " << endl;
        perHour = false;
        hourly = 0;
        hours = 0;
    }
    cout << "Flat payment in addition to wage? yes/no: ";
    cin.ignore();
    cin >> choice;
    if(choice >= 0){
        cout << "Yes chosen. " << endl;
        flatPayment = true;
        cout << "Amount: ";
        cin.ignore();
        cin >> flatAmount;
    } else {
        cout << "No chosen. " << endl;
        flatPayment = false;
        flatAmount = 0;
    }
    amount = (hourly*hours)+(flatAmount);
}
//Constructor
Income::Income(string _name, float _amount){
    name = _name;
    amount = _amount;
    hourly = 0;
    perHour = false;
}
float Income::getAmount() const{
    return amount;
}
string Income::getName() const{
    return name;
}
string Income::toString() const{
    string str;
    str.append("Name: ");
    str += name;
    str += "\n Amount: ";
    str += to_string(amount);
    return str;
}

Fee::Fee(){
    cout << "Enter name: ";
    cin >> name;
    cin.ignore();
    cout << "Enter amount: ";
    cin >> amount;
    perHour = 0;
    hourly = 0;
    hours = 0;
}
Fee::Fee(string _name, float _amount){
    name = _name;
    amount = _amount;
    perHour = 0;
    hourly = 0;
    hours = 0;
}

//Constructor
PV::PV(){
    cout << "Is this photo or video? " << endl;
    cout << "(Enter nonnegative int for photo or negative int for video: ";
    int choice;
    cin.ignore();
    cin >> choice;
    if(choice < 0){
        isPhoto = false;
    }else{
        isPhoto = true;
    }
    cout << "Name of income: ";
    getline(cin,name);
    cin.ignore();
    cout << "Includes an hourly wage? yes/no: ";
    cin.ignore();
    cin >> choice;
    if(choice < 0){
        cout << "No chosen. " << endl;
        perHour = false;
        hourly = 0;
    } else {
        cout << "Enter wage: ";
        cin.ignore();
        cin >> hourly;
        cout << "Enter hours: ";
        cin.ignore();
        cin >> hours;
    }
    cout << "Will you charge any fees? yes/no: ";
    cin.ignore();
    cin >> choice;
    if(choice < 0){
        cout << "No chosen. " << endl;
    } else {
        while (choice >= 0){
            cout << "Yes chosen. Adding fee. " << endl;
            Fee* fptr = new Fee;
            fees.push_back(fptr);
            cout << "Add another fee? yes/no: ";
            cin.ignore();
            cin >> choice;
        }
    }
    cout << "Will this income incur any expenses? yes/no: ";
    cin.ignore();
    cin >> choice;
    while (choice >= 0){
        cout << "Yes chosen. Adding expense. " << endl;
        Expense* eptr = new Expense;
        costs.push_back(eptr);
        cout << "Add another expense? yes/no: ";
        cin.ignore();
        cin >> choice;
    }
    if (choice < 0){
        cout << "No chosen. " << endl;
    }
    float totalFees = 0;
    for(int i=0; i<fees.size(); i++){
        totalFees += fees[i]->getAmount();
    }
    float totalCost = 0;
    for(int i=0; i<fees.size(); i++){
        totalCost += costs[i]->getAmount();
    }
    profit = (perHour*hours)+totalFees-totalCost;
    amount = (perHour*hours)+totalFees;
}

//Constructor
Silverwood::Silverwood(){
    perHour = true;
    cout << "Name of job: ";
    cin >> name;
    cout << "How many weeks per year to work: ";
    cin.ignore();
    cin >> weeksPerYear;
    cout << "How many days per week to work: ";
    cin.ignore();
    cin >> daysPerWeek;
    cout << "How many hours per day to work: ";
    cin.ignore();
    cin >> hours;
    cout << "Wage: ";
    cin.ignore();
    cin >> hourly;
        cout << "Include tips? yes/no: ";
        cin.ignore();
        int choice;
        cin >> choice;
    if(choice >= 0){
        cout << "Yes chosen. " << endl;
        cout << "Enter avg tip amount per day: ";
        cin.ignore();
        cin >> tipAvg;
    }
    amount = (hourly*hours*daysPerWeek*weeksPerYear)+tipAvg;
}

