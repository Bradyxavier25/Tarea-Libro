#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

Employee::Employee(const string &first , const string &last, const string &ssn)
    :firstName(first),lastName(last) , SocialSecurityNumber(ssn){}

void Employee::setfirstName(const string &first)
{
    firstName = first;
}
string Employee::getfirstName()const
{
    return firstName;
}
void Employee::setlastName(const string &last)
{
    lastName = last;
}
string Employee::getlastName()const
{
    return lastName;
}
void Employee::setSocialSecurityNumber(const string &ssn)
{
    SocialSecurityNumber = ssn;
}
string Employee::getSocialSecurityNumber()const
{
    return SocialSecurityNumber;
}
string Employee::to_String()const
{
    return getfirstName() + " "s + getlastName() + "\nsocial security number: "s + getSocialSecurityNumber();
}




