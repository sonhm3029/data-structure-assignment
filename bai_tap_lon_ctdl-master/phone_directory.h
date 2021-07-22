#include <iostream>
#include <vector>
#include "person.cpp"

using namespace std;



class phoneDirectory{
    vector <Person> list;
    public:
        //Function to add new contact to directory
        void add();
        //Function to get the directory
        void get();
        //Function to search contact by name or telephone number
        void search_contact();
        //Function to sort directory by alphabet using Timsort algorithim
        void timSort_contact_byAlphabet();
        //Function to load available directory
        void load_directory();
        //Function to save new contact after adding
        void save_new_contact();
        //Function to delete contact
        void delete_contact();
};