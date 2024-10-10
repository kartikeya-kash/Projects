#include <iostream>
#include <string>
using namespace std;

string email;
string pass;


bool nuser(){
    string confirmpass;
    cout<<"enter mail id and password "<<endl;
    cin>>email;
    cin>>pass;
    cout<<"confirm password please "<<endl;
    cin>>confirmpass;
    if(confirmpass == pass){
        cout<<"registered successfully !!!"<<endl<<endl<<endl<<endl;
        return true;
    }
    else{
        cout<<"wrong password entered !";
        exit(0);
    }
}

bool loginuser(){
    string te;
    string tp;
    char ch='y';
    do{
        cout<<"\tWELCOME\t"<<endl;
        cout<<"enter 1 to Login"<<endl;
        cout<<"enter 2 for new user "<<endl;
        cout<<"enter n to exit the application!"<<endl;
        cin>>ch;
        cout<<endl<<endl;
        
        switch(ch){
            case '1':
                cout<<"enter email ID = ";
                cin>>te;
                cout<<"enter password = ";
                cin>>tp;
                if(te == email && tp == pass){
                    cout<<"login sucess , welcome "<<endl; 
                    return true;
                }
                else{
                    cout<<"mail or pass is wrong! or user not found please register"<<endl;
                    exit(0);
                }
                
                
            break;
            case '2':
                nuser();
            break;
            case 'n':
            exit (0);
        }
        
        
    }while(ch=='y');
} 

struct booking {
    string name;
    long phone;
    string email;
    string password;
    string boarding;
    string getof;
    int date;
    int month;
    string food;
    string coach;
    booking *next;
    booking *prev;
};

void book(booking *&first) {
    booking *newp = new booking();
    newp->prev = NULL;
    newp->next = NULL;

    if (first == NULL) {
        first = newp;

        cout << "Enter name = ";
        cin.ignore();  
        getline(cin, newp->name);  

        cout << "Enter phone number = ";
        cin >> newp->phone;
        cin.ignore();  

        cout << "Enter email address = ";
        getline(cin, newp->email);

        cout << "Enter password = ";
        getline(cin, newp->password);

        cout << "Enter boarding location = ";
        getline(cin, newp->boarding);
        
        cout << "Enter place to get off = ";
        getline(cin, newp->getof);

        cout << "Enter date for booking (day) = ";
        cin >> newp->date;
        cin.ignore();  
        
        cout << "Enter month for booking = ";
        cin >> newp->month;
        cin.ignore();  

        cout << "Enter food choice (yes/no) = ";
        getline(cin, newp->food);

        cout << "Enter coach ('3AC , 2AC , 1AC , sleeper , urgent ') = ";
        getline(cin, newp->coach);
        cout<<endl<<endl<<endl;
    }
    else{
        booking * temp = first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        newp->prev = temp;
        temp->next = newp;
        
        cout << "Enter name = ";
        cin.ignore();  
        getline(cin, newp->name);  

        cout << "Enter phone number = ";
        cin >> newp->phone;
        cin.ignore();  

        cout << "Enter email address = ";
        getline(cin, newp->email);

        cout << "Enter password = ";
        getline(cin, newp->password);

        cout << "Enter boarding location = ";
        getline(cin, newp->boarding);
        
        cout << "Enter place to get off = ";
        getline(cin, newp->getof);

        cout << "Enter date for booking (day) = ";
        cin >> newp->date;
        cin.ignore();  
        
        cout << "Enter month for booking = ";
        cin >> newp->month;
        cin.ignore();  

        cout << "Enter food choice (yes/no) = ";
        getline(cin, newp->food);

        cout << "Enter coach ('3AC , 2AC , 1AC , sleeper , urgent ') = ";
        getline(cin, newp->coach);
        cout<<endl<<endl<<endl;
    }
}

void cancel(booking *&first){
    string e,p;
    int seat=1;
    booking * temp = first;

    if(first == NULL){
        cout<<"no seat reserved, can't cancel."<<endl;
        return;
    }

    cout<<"Enter email ID and password!"<<endl;
    cin>>e;
    cin>>p;

    while(temp != NULL && (temp->email != e || temp->password != p)) {
        temp = temp->next;
        seat++;
    }

    if(temp == NULL){
        cout<<"No reservation found!"<<endl<<endl<<endl;
        return;
    }

    cout<<"Seat number "<<seat<<" is canceled successfully."<<endl;

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        first = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;  
}

void info(booking *&first){
    if(first == NULL)
    {
        cout<<"no booking yet, all seats empty!"<<endl<<endl<<endl;
    }
    else{
        int bookingNumber=1;
        booking * temp = first ;
        while (temp != NULL)
        {
            cout<<"booking number = "<<bookingNumber<<" Name = "<<temp->name<<" Email id = "<<temp->email<<endl;
            bookingNumber++;
            temp = temp->next;
        }
    }
}

int main() {
    booking *first = NULL;
    
    loginuser();
   if(nuser){
                char choice = 'c';
                do {
                    cout << "\tWelcome to railway reservation!!" << endl;
                    cout << "Enter 1 to book ticket" << endl;
                    cout << "Enter 2 to cancel ticket" << endl;
                    cout << "Enter 3 to display info of all passanger " << endl;
                    cout << "Enter 'c' to continue or 's' to stop! " << endl;
                    cin >> choice;
                    cout<<endl<<endl<<endl;
            
                    if (choice == '1') {
                        book(first);
                    }
                    else if(choice =='2'){
                        cancel(first);
                    }
                    else if(choice == '3'){
                        info(first);
                    }
                } while (choice != 's');
            }
    return 0;
}