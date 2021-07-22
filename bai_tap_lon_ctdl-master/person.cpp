#include <iostream>
#include <string>
#include "person.h"
#include <iomanip>


using namespace std;

void Person::set()
{
    cout<<"Please type in name: ";
    getline(cin,name);
    cout<<"Please type in phone number: ";
    getline(cin,telephone_number);
}

void Person::get()
{
    cout<<left;
    cout<<"|\t\t"<<setw(30)<<name<<setw(20)<<"|"<<setw(20)<<telephone_number<<endl;
}

string Person::get_name()
{
    return name;
}

string Person::get_phone_number()
{
    return telephone_number;
}

void Person::set(string _name, string _phoneNumber)
{
    name = _name;
    telephone_number = _phoneNumber;
}