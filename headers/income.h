#ifndef INCOME_H
#define INCOME_H
#include <string>
#include <iostream>
#include <vector>
#include "expense.h"

using namespace std;

class Income{
    protected:
    string name;//Name of income
    float amount;//Amount of income
    bool perHour;
    float hourly;
    int hours;
    bool flatPayment;
    float flatAmount;
    public:
    //Default constructor
    Income();
    //Constructor
    Income(string _name, float _amount);
    float getAmount() const;
    string getName() const;
    string toString() const;
};

class Fee : public Income{
    public:
    //Default Constructor
    Fee();
    //Constructor
    Fee(string _name, float _amount);
};

class PV : public Income{
    private:
    vector<Fee *> fees;//Holds misc fees
    vector<Expense *> costs;//Holds misc expenses
    bool isPhoto;//Determines photo or video
    float profit;
    public:
    //Constructor
    PV();
};

class Silverwood : public Income{
    private:
    int weeksPerYear;
    int daysPerWeek;
    float tipAvg;//Average tip revenue per day
    public:
    //Default constructor
    Silverwood();
};

#endif
