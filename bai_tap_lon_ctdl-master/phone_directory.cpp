#include <iostream>
#include "phone_directory.h"
#include <fstream>

const int RUN = 32;

using namespace std;


void phoneDirectory::add()
{
    cout<<"Please fill in the blank !"<<endl;
    //Create and set up new contact
    Person new_contact;
    new_contact.set();
    list.push_back(new_contact);
}

void phoneDirectory::get()
{
    cout<<"\n|=======================================================================================|";
    cout<<"\n|===============================        PHONE DIRECTORY       ==========================|"<<endl;
    cout<<"|=======================================================================================|";
    cout<<left;
    cout<<"\n|\t\t"<<setw(30)<<"Contact name"<<setw(20)<<"|"<<setw(20)<<"Phone number"<<endl;
    cout<<"|=======================================================================================|"<<endl;
    for(int i = 0; i<list.size(); i++)
    {
        cout<<i + 1<<". ";
        list[i].get();
        cout<<"|=======================================================================================|"<<endl;
    }
}

void phoneDirectory::search_contact()
{
    string name;
    int flag = 0;
    // A little bit UI
    cout<<"\nType in name  or telephone number to search: ";
    getline(cin,name);
    cout<<"\n|=======================================================================================|";
    cout<<"\n|===============================          SEARCH RESULT       ==========================|"<<endl;
    cout<<"|=======================================================================================|";
    cout<<left;
    cout<<"\n|\t\t"<<setw(30)<<"Contact name"<<setw(20)<<"|"<<setw(20)<<"Phone number"<<endl;
    // Binary search
    // int low = 0;
    // int high = list.size()-1;
    for(int i = 0; i<list.size(); i++)
    {
        if(name == list[i].get_name()||name == list[i].get_phone_number())
        {
            list[i].get();
            cout<<"|=======================================================================================|"<<endl;
            flag += 1;
        }
    }

    if(flag == 0)
    {
        cout<<"\n\t\tThere's no result "<<endl;
    }
}

//Insertion sort algorithm
void insertionSort(vector<Person> &list, int left, int right)
{
    for(int i = left; i<=right;i++)
    {
        Person temp = list[i];
        int j = i - 1;
        while(j >= left && list[j].get_name() > temp.get_name())
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }
}

//Merge sort algorithm
void merge(vector<Person> &list,int l,int m, int r)
{
    //Original array is divide into 2 parts
    //left and right array
    int len1 = m - l + 1;  //this is length of left array
    int len2 = r - m; //this is lenght of right array
    vector <Person> left, right;

    for(int i = 0; i < len1; i++)
    {
        Person temp = list[l+i];
        left.push_back(temp);
    }
    for(int i = 0; i<len2; i++)
    {
        Person temp = list[m + 1 +i];
        right.push_back(temp);
    }

    //set index for left,right array and list person
    int i = 0;
    int j = 0;
    int k = l;

    while(i < len1 && j < len2)
    {
        if( left[i].get_name()<=right[j].get_name())
        {
            list[k] = left[i];
            i++;
        }
        else{
            list[k] = right[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements of left, if any
    while(i <len1)
    {
        list[k] = left[i];
        k++;
        i++;
    }
    while(j < len2)
    {
        list[k] = right[j];
        k++;
        j++;
    }
}

void phoneDirectory::timSort_contact_byAlphabet()
{
    //We using tim sort algorithm to sort array
    //This is an algorithm that based on both Insertion sort and Merge sort
    int n = list.size();
    for( int i = 0; i < list.size(); i+= RUN)
    {
        //Sort subarrays of size RUN
        // if size of list < RUN =======> Tim sort = insertion Sort
        insertionSort(list,i,min((i + RUN -1), (n - 1)));
    }

    for(int size = RUN; size < n; size = size *2)
    {
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left <n; left += 2*size)
        {
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid= left+size -1;
            int right = min((left + 2*size -1),(n-1));
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            if( mid <right)
            {
                merge(list,left,mid, right);
            }
        }
    }

}


void phoneDirectory::load_directory()
{
    ifstream loading_directory;
    loading_directory.open("directory.txt");
    while(loading_directory.eof() == false)
    {
        Person new_contact;
        string name;
        string phone_number;
        getline(loading_directory,name,',');
        getline(loading_directory,phone_number);
        new_contact.set(name,phone_number);
        list.push_back(new_contact);
    }
    loading_directory.close();
}

void phoneDirectory::save_new_contact()
{
    ofstream saving_directory;
    saving_directory.open("directory.txt");
    for(int i = 0; i<list.size(); i++)
    {
        if(i == list.size() - 1)
        {
            saving_directory<<list[i].get_name()<<","<<list[i].get_phone_number();
        }
        else{
            saving_directory<<list[i].get_name()<<","<<list[i].get_phone_number()<<endl;
        }
    }
    saving_directory.close();
}


void phoneDirectory::delete_contact()
{
    //Show directory for customer select
    get();
    int chose;
    cout<<"\nChose the contact that you want to delete from directory !";
    cout<<"\nYour chose: ";cin>>chose;
    chose -=1;
    list.erase(list.begin()+ chose);
    cout<<"\nDelete successfully !";
}



