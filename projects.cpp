#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;
void addcontact();
bool check_digits(string s);
bool check_numbers(string x);
void searchcontact();
void help();
void self_exist();


string fname,lname,phone_num;

void addcontact(){
    ofstream phone("number.text",ios::app);
 system("cls");
    cout<<"\n\n\tEnter Fisrt Name :";
   cin>>fname;
    cout<<"\n\tEnter Last Name :";
    cin>>lname;
    cout<<"\n\tEnter 10-Digit Phone Number :";
    cin>>phone_num;
    if(check_digits(phone_num)==true){

        if(check_numbers(phone_num)==true){
            if(phone.is_open()){
                phone<<fname<<" "<<lname<<" "<<phone_num<<endl;
                cout<<"\n\tcontact saved successfully";
            }


        }else {
            cout<<"\n \tA phone numbers must contain 10 digits.";
        }
        phone.close();

    }

    else {
        cout<<"\n\tA phone numbers must contain numbers only!";
    }

}



bool check_digits(string s){
    if(s.length()==10)
    return true;
    else return false ;
    

}

bool check_numbers(string x){
    bool check=true;
    for(int i=0;i<x.size();i++){
        if(!(x[i]>=48&&x[i]<=57)){
            check=false;
        }
    }
    if(check==true)return true;
    if(check==false)return false;
}


void searchcontact(){
    bool found=false ;
    ifstream myfile("number.text");
    string keyword;
    cout<<"\n\tEnter Name To Search: ";
    cin>>keyword;
    while(myfile>>fname>>lname>>phone_num){


        if(keyword==fname||keyword==lname){
            system("cls");
            cout<<"\n\n\n\t\tcontact details..";
            cout<<"\n\n\tFirst Name :"<< fname;
            cout<<"\n\tLast Name :"<<lname;
            cout<<"\n\tPhone Number: "<<phone_num;
            found=true;
            break;
        }
    }if(found==false){
        cout<<"\n\tNo such contact found";

    }

   

}
void help(){
   system("cls");
    cout << "\n\n\t\t\t--- Contact Management System Help ---\n\n";
    cout << "1. Add Contact:\n";
    cout << "\tTo add a new contact, choose option 1 from the main menu.\n";
    cout << "\tEnter the first name, last name, and 10-digit phone number when prompted.\n\n";
    
    cout << "2. Search Contact:\n";
    cout << "\tTo search for a contact, choose option 2 from the main menu.\n";
    cout << "\tEnter either the first name or last name of the contact you want to find.\n";
    cout << "\tThe system will display the contact details if found.\n\n";
    
    cout << "3. Help:\n";
    cout << "\tTo display this help message again, choose option 3 from the main menu.\n\n";
    
    cout << "4. Exit:\n";
    cout << "\tTo exit the program, choose option 4 from the main menu.\n";
    cout << "\tThis will close the application.\n\n";
    
    cout << "Note:\n";
    cout << "\t- Phone numbers must contain exactly 10 digits.\n";
    cout << "\t- Only numbers are allowed in the phone number field.\n";
    cout << "\t- The system saves contacts in a file named 'number.txt'.\n\n";
    
    cout << "Press any key to return to the main menu...";
    getch(); 
   
}
void self_exist(){
    system("cls");
    cout<<"\n\n\n\t\tThank you for using !";
    exit(1);

}

int main(){
    short int choice;
     system("cls");
     system("color 0A");
     cout<<" \n\n\n\t\t\tContact Management";
     cout<<"\n\n\t1.Add Contact\n\t2.SearchContact\n\t3.Help\n\t4.Exit\n\t>";
cin>>choice;
switch(choice){
    case 1:
    addcontact();
    break;
    case 2:
    searchcontact();
    break;
    case 3:
    help();
    break;
case 4 :
self_exist();
break;
default:
cout<<"\n\n\tInvalid Input!";
cout<<"\n\tPress any key to continue";
getch();
main();
}
  return 0;  
}



