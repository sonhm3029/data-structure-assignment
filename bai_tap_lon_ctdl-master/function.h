#include <iostream>
#include "phone_directory.cpp"
#include <conio.h>

using namespace std;

char Menu()
{
    char chose;
    cout<<"\n=====        MENU        ====="<<endl;
    cout<<"\n1.      Add new contact";
    cout<<"\n2.      Show directory";
    cout<<"\n3. Sort directory by alphabet";
    cout<<"\n4. Find contact by name or phone number";
    cout<<"\n5.       Delete contact";
    cout<<"\n6.           Exit";
    cout<<"\n===============================";
    cout<<"\nYour Chose:";cin>>chose;
    return chose;
}

void Program(phoneDirectory &directory)
{
    char chose;
    //load available directory
    directory.load_directory();
    do{
        chose = Menu();
        fflush(stdin);
        switch(chose)
        {
            case '1':
                directory.add();
                system("PAUSE");
                cout << "\033[2J\033[1;1H";
            break;
            case '2':
                directory.get();
                system("PAUSE");
                cout << "\033[2J\033[1;1H";
            break;
            case '3':
                directory.timSort_contact_byAlphabet();
                directory.get();
                system("PAUSE");
                cout << "\033[2J\033[1;1H";
            break;
            case '4':
                directory.search_contact();
                system("PAUSE");
                cout << "\033[2J\033[1;1H";
            break;
            case '5':
                directory.delete_contact();
                system("PAUSE");
                cout << "\033[2J\033[1;1H";
            case '6':
                directory.save_new_contact();
            break;
            default:
                directory.save_new_contact();
            break;
        }
    } while(chose !='6');
}