#ifndef SALARIED_H
#define SALARIED_H
#include "Employee.h"
#include <string>
using namespace std;


class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string &  , const string & , const string & , double =0.0);
    virtual ~SalariedEmployee()=default;

    void setWeeklySalary(double);
    double getWeeklySalary()const;

    //metodo virtual
    virtual double earnings()const override;
    virtual string to_String() const override;
private:
    double weeklySalary;
};

#endif
