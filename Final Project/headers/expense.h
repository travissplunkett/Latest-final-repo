#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Expense{
    protected:
    float amount;//Amount of expense
    string name;//Name of expense
    public:
    //Default constructor
    Expense();
    //Constructor
    Expense(string _name, float _amount);
    //Returns a string of Expense data
    string toString();
    //Establishes that << returns an ofstream of object data
    friend ofstream &operator<<(ofstream &input, const Expense & e) {
      input << "Name: " << e.name << " Amount: " << e.amount;
      return input;
    }
    float getAmount() const;
};

class College_Expenses : public Expense {
    private:
    float tuition, housing, books;
    public:
    //Default constructor
    College_Expenses();
    //Constructor
    College_Expenses(string _name, float _tuition, float _housing, float _books);
    //Establishes that >> returns a string of College_Expense data
    friend ofstream &operator<<(ofstream &input, const College_Expenses & ce) {
      input << "Tuition: " << ce.tuition << " Housing: " << ce.housing << " Books: " << ce.books << " ";
      return input;
    }
    //Returns a string of Expense data
    string toString();

};

class Recreation_Expense: public Expense{
    public:
    //Default constructor
    Recreation_Expense();
    friend ofstream &operator<<(ofstream &input, const Recreation_Expense & re) {
      input << "Name: " << re.name << " Amount: " << re.amount;
      return input;
    }
};

#endif
