#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

void virtualViaPointer(const Employee *const); 
void virtualViaReference(const Employee &);    

int main()
{
    cout << fixed << setprecision(2); 

    // create derived-class objects
    SalariedEmployee salariedEmployee{
        "John", "Smith", "111-11-1111", 800};
    CommissionEmployee commissionEmployee{
        "Sue", "Jones", "333-33-3333", 10000, .06};
    BasePlusCommissionEmployee basePlusCommissionEmployee{
        "Bob", "Lewis", "444-44-4444", 5000, .04, 300};

  
    cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
         << salariedEmployee.to_String()
         << "\nearned $" << salariedEmployee.earnings() << "\n\n"
         << commissionEmployee.to_String()
         << "\nearned $" << commissionEmployee.earnings() << "\n\n"
         << basePlusCommissionEmployee.to_String()
         << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    // create and initialize vector of three base-class pointers
    vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
                                 &basePlusCommissionEmployee};

    cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

    for (const Employee *employeePtr : employees)
    {
        virtualViaPointer(employeePtr);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

    for (const Employee *employeePtr : employees)
    {
        virtualViaReference(*employeePtr); // note dereferencing
    }
}

// call Employee virtual functions toString and earnings off a
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee *const baseClassPtr)
{
    cout << baseClassPtr->to_String()
         << "\nganado $" << baseClassPtr->earnings() << "\n\n";
}


void virtualViaReference(const Employee &baseClassRef)
{
    cout << baseClassRef.to_String()
         << "\nganado $" << baseClassRef.earnings() << "\n\n";
}