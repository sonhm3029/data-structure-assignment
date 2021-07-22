#include <iostream>

using namespace std;

class Person{
    string name;
    string telephone_number;

    public:
        //constructor function
        Person(){}
        //destructor function
        ~Person(){}
        // Function to setup personal information
        void set();
        //Funtion to setup personal information (have arguments)
        void set(string _name, string _phoneNumber);
        // Function to get person information
        void get();
        //Function to get person name
        string get_name();
        //Function to get person telephone number
        string get_phone_number();
};