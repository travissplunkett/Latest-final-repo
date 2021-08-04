#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "expense.h"

    //Default constructor
    Expense::Expense(){
        cout << "Name of expense: ";
        cin.ignore();
        getline(cin,name);
        cout << "Amount: ";
        cin >> amount;
    }
    //Constructor
    Expense::Expense(string _name, float _amount){
        amount = _amount;
        name = _name; 
    }
    //Returns a string of Expense data
    string Expense::toString(){
        string str;
        str += "Name: ";
        str += name;
        str += "\n";
        str += "Amount: ";
        str += to_string(amount);
        return str;
    }
    float Expense::getAmount() const{
        return amount;
    }
                // //Establishes that << returns an ofstream of object data
                // ofstream Expense::&operator<<(ofstream &input, const Expense & e) {
                //   input << e.toString() << endl;
                //   return input;
                // }
                
    //Default constructor
    College_Expenses::College_Expenses(): Expense(){
        cout << "Name of school: ";
        cin.ignore();
        getline(cin,name);
        cout << "Tuition, yearly, costs: ";
        cin.ignore();
        cin >> tuition;
        cout << "Housing, yearly, costs: ";
        cin.ignore();
        cin >> housing;
        cout << "Books, yearly, cost: ";
        cin.ignore();
        cin >> books;
        amount = tuition + housing + books;
    }
    //Constructor
    College_Expenses::College_Expenses(string _name, float _tuition, float _housing, float _books){
        name = "for college";
        tuition = _tuition;
        housing = _housing;
        books = _books;
        amount = tuition + housing + books;
    }
    //Returns a string of Expense data
    string College_Expenses::toString(){
        string str;
        str += "Name: ";
        str += name;
        str += " | ";
        str += "Tuition: ";
        str += to_string(tuition);
        str += " | ";
        str += "Housing: ";
        str += to_string(housing);
        str += " | ";
        str += "Books: ";
        str += to_string(books);
        str += " | ";
        str += "Total Amount: ";
        str += to_string(amount);
        return str;
    }

    //Default constructor
    Recreation_Expense::Recreation_Expense(){
        cout << "Name of expense: ";
        cin.ignore();
        getline(cin,name);
        cout << "Amount: ";
        cin.ignore();
        cin >> amount;
    }

