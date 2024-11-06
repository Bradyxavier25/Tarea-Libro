#include <iomanip>
#include <stdexcept>
#include <sstream>
#include<string>
#include "SalariedEmployee.h" 
using namespace std;

// constructor
SalariedEmployee::SalariedEmployee(const string &first,const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn)
{
    setWeeklySalary(salary);
}

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
    if (salary < 0.0)
    {
        throw invalid_argument("Weekly salary must be >= 0.0");
    }

    weeklySalary = salary;
}

// return salary
double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return getWeeklySalary(); }

// return a string representation of SalariedEmployee's information
string SalariedEmployee::to_String() const
{
    ostringstream output;
    output << fixed << setprecision(2);
    output << "salario del empleado: "
           << Employee::to_String() // reuse abstract base-class function
           << "\nsalario semanal: " << getWeeklySalary();
    return output.str();
}