#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
using namespace std;

class Employee
{
public:
    Employee(const string& , const string& , const string &);
    virtual ~Employee()=default;
    
    void setfirstName(const string&);
    string getfirstName()const;

    void setlastName(const string&);
    string getlastName()const;

    void setSocialSecurityNumber(const string&);
    string getSocialSecurityNumber()const;

    // metodos virtualitos lso dos tipos 
    virtual double earnings()const =0;
    virtual string to_String()const;

private:
    string firstName;
    string lastName;
    string SocialSecurityNumber;

};

#endif