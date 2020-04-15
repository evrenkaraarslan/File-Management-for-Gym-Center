#include<iostream>
#include<fstream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;

//To set specific positions on screen
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Class with variables and functions
class fitness
{
	private:
		
		int membernumber;
		char name[50];
		char surname[50];
		float weight;
		float height;
		int age;
	public:
		
		void write();
		void read();
		void displayall();
		void createmember();
		void show_member_info();
		void searchmember(int n);
		void edit();
		void deletee();
		int returnmember(); 
		
};

//Class object

fitness fitt; 

//File object which is compatible with inputs and outputs

fstream fileobject; 

int fitness::returnmember()
        {
            return membernumber;
        }

//Main function
int main()
{
	fitness fitnessobject; 
	int choice;
	while(true)
    {
      	gotoxy(10,2);
      	cout<<"          --------              ";
      	gotoxy(10,4);
      	cout<<"        ------------            ";
      	gotoxy(10,6);
      	cout<<"      ----------------          ";
   	gotoxy(10,8);
	cout<<"         <->     <->            ";
	gotoxy(10,10);
	cout<<"      -----       -----          ";
	gotoxy(10,12);
	cout<<"      WELCOME TO SYSTEM         ";

	gotoxy(80,2);
	cout<<"          --------              ";
	gotoxy(80,4);
	cout<<"        ------------            ";
	gotoxy(80,6);
	cout<<"      ----------------          ";
	gotoxy(80,8);
	cout<<"         <->     <->            ";
	gotoxy(80,10);
	cout<<"      -----       -----         ";
	gotoxy(80,12);
	cout<<"        STAY HEALTHY            ";

        gotoxy(42,2);
        cout<<"|||||||||||||||||||||||||||||||";
        gotoxy(42,3);
        cout<<"|||||Fitness Center System||||| ";
        gotoxy(42,4);
        cout<<"|||||||||||||||||||||||||||||||";
        gotoxy(42,5);
        cout<<"1-Add Member";
        gotoxy(42,7);
        cout<<"2-Show Information of all the members";
        gotoxy(42,9);
        cout<<"3-Update Information of the member";
        gotoxy(42,11);
        cout<<"4-Search member information";
	gotoxy(42,13);
        cout<<"5-Delete the information of member";
        gotoxy(42,15);
        cout<<"6-Exit";
        gotoxy(42,17);
        cout<<"Enter one of the option: ";
        cin>>choice;
	    switch(choice)
	    {
		    case 1:
		   		system("cls");
		    	fitnessobject.write();
		    	break;
			case 2:
				system("cls");
				fitnessobject.displayall();
				break;
			case 3:
				system("cls");
				fitnessobject.edit();
				break;
			case 4:
				system("cls");
				int num;
                                cout << "\n\n\tPlease enter the member number to search: ";
                                cin>>num;
                                fitnessobject.searchmember(num);
                                break;
                        case 5:
            	                system("cls");
            	                fitnessobject.deletee();
            	                break;
			default:
				return 0;
				break;
	    }
	 
}
}

//Create member function
void fitness::createmember()
{   
	gotoxy(40,4);
    cout<<"Enter Member's Number: ";
    cin>>membernumber;
    gotoxy(40,6);
    cout<<"Enter First Name: ";
    cin>>name;
    gotoxy(40,8);
    cout<<"Enter The Surname: ";
    cin>>surname;
    gotoxy(40,10);
    cout<<"Enter The Weight: ";
    cin>>weight;
    gotoxy(40,12);
    cout<<"Enter The Height: ";
    cin>>height;
    gotoxy(40,14);
    cout<<"Enter The Age: ";
    cin>>age;
    gotoxy(40,16);
    cout << "The Account has been created!!";
    gotoxy(40,18);
    cout << "Press enter to go main menu";
    getch();
    system("cls");
}

//Write member function

void fitness::write() 
{
    ofstream evren;
    evren.open("gymmember.dat", ios::out|ios::binary | ios::app);
    fitt.createmember();
    
  //  evren.write((char * ) & fitt, sizeof(fitness));
  
    evren.write(reinterpret_cast<char *>(&fitt), sizeof(fitness));
    evren.close();
    getch();
}

//Display all members function

void fitness::displayall()
{
    system("cls");
    cout <<"\n INFORMATIONS OF ALL MEMBERS \n\n";
    fileobject.open("gymmember.dat", ios:: in |ios::binary);
    while (fileobject.read(reinterpret_cast<char *>(&fitt), sizeof(fitness))) 
    {
        fitt.show_member_info();
        cout << "\n\n||||||||||||||||||||||||||||||||\n";
    }
    fileobject.close();
    cout << "Press enter to go main menu";
    getch();
    system("cls");
}

//Member info function

void fitness::show_member_info() 
{
    cout << "\nThe member number : " << membernumber<<endl;
    cout << "\nThe name of the member : ";
    puts(name);
    cout << "\nThe surname of the member : ";
    puts(surname);
    cout << "\nThe weight of "<<name<<" "<<surname<<" is "<< weight<<endl;
    cout << "\nThe height of "<<name<<" " <<surname<<" is "<< height<<endl;
    cout << "\nThe age of "<<name<<" " <<surname<<" is "<< age<<endl;
}

//Display specific member function

void fitness::searchmember(int n) 
{
	
    int flag = 0;
    fileobject.open("gymmember.dat", ios:: in );
    while (fileobject.read(reinterpret_cast<char *>(&fitt), sizeof(fitness))) 
    {
        if (fitt.returnmember() == n) 
        {
            system("cls");
            fitt.show_member_info();
            flag = 1;
        }
    }
    fileobject.close();
    if (flag == 0)
        cout << "\n\nNo member exists with the number "<<n<<" in the system"<<endl;;
        cout << "Press enter to go main menu";
    getch();
    system("cls");
}

//Edit function

void fitness::edit() 
{
    int no, found = 0;
    system("cls");
    cout << "\n\n\tPlease enter the member number to edit";
    cin >> no;
    fileobject.open("gymmember.dat", ios:: in | ios::out);
    while (fileobject.read(reinterpret_cast<char *>(&fitt), sizeof(fitness)) && found == 0) 
    {
        if (fitt.returnmember() == no) 
        {
            fitt.show_member_info();
            gotoxy(40,16);
            cout << "\nPlease enter the new informations of the member" << endl;
            getch();
            system("cls");
            gotoxy(40,2);
            cout<<"Ready to enter new informations";
            fitt.createmember();
            int a = -1 * sizeof(fitt);
            fileobject.seekp(a, ios::cur);
            fileobject.write(reinterpret_cast<char *>(&fitt), sizeof(fitness));
            cout << "\n\n\t Information Updated";
            found = 1;
        }
    }
    fileobject.close();
    if (found == 0)
        cout << "\n\nNot found!"<<endl;;
    cout << "Press enter to go main menu";
    getch();
    system("cls");
}

//Delete function

void fitness::deletee()
{
    int no;
    system("cls");
    cout << "\n\n\n\tDelete Member";
    cout << "\n\nEnter the member number to delete: ";
    cin >> no;
    fileobject.open("gymmember.dat", ios:: in | ios::out);
    fstream fileobject2;
    fileobject2.open("del.dat", ios::out);
    fileobject.seekg(0, ios::beg);
    while (fileobject.read((char * ) & fitt, sizeof(fitness))) 
    {
        if (fitt.returnmember() != no) 
        {
            fileobject2.write((char * ) & fitt, sizeof(fitness));
        }
    }
    fileobject2.close();
    fileobject.close();
    remove("gymmember.dat");
    rename("del.dat", "gymmember.dat");
    cout << "\n\n\tMember deleted ..";
    getch();
    system("cls");
}
