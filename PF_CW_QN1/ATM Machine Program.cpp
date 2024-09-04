#include<iostream>
#include<cstdlib>
using namespace std;

struct User
{
      User *next;
      string UserName;
      string Password;
      double balance;
      
      
      User()
      {
            UserName="";
            Password="";
            balance=0.0;
            next=NULL;
      }
};



User * users = NULL;

void Welcome();
char MainMenu();
User* Authorization(string, string);
char UserMenu();
void Deposit(User*, double);
void Withdraw(User*, double);
double BalanceInquiry(User*);
void CreateAccount();


int main()  
{
	 User * user;
     Welcome();
	 char ch;
	 
	 do
    {
        ch = MainMenu();
        switch (ch)
        {
	              case 'c' :
	              	    CreateAccount();
	              	    system ("cls");
	              	    break;
	              case 'l':
	              {
	                       string uName;
						   string uPassword;
						   cout<<"Enter Your User Name: ";
						   cin>>uName;
						   
						   cout<<"Enter Your Password: "; 
						   cin>> uPassword;
						   
						   cout << "Trying to login with: " << uName << " / " << uPassword << endl;
						   
						   user = Authorization(uName, uPassword);
						   if(user!=NULL)
						   {
						    char uchoice;
						    do
							{
						    	system("cls");
						    	uchoice = UserMenu();
						    	switch(uchoice)
						    	{
						    		    case 'd':
						    		    {   
						    		    	    double deposit;
						    		    	    cout<<"Enter Deposit Amount:$ ";
						    		    	    cin>>deposit;
						    		    	    Deposit(user,deposit);
						    		    	    break;
						    		    }
						    		    case 'w':
						    		    {	
										        double withdraw;
												WITHDRAW:{cout<<"Enter Withdraw Amount:$ ";
												cin>>withdraw;}	
												if(withdraw>0) 
												{
													Withdraw(user,withdraw);
													system("pause");
												} 
												else
												{
													cout<<"Withdraw Amount Must be Greater than 0"<<endl;
												}  
												break;
									    }
									   	case'r':	
										        cout<<"Your Available Balance is:$ "<<BalanceInquiry(user)<<endl;
										        system("pause");
													
						    	}
						    }while(uchoice!='q');
						  }
						  else
							{
								cout<<"*** LOGIN FAILED! ***"<<endl;
								system("pause");
						    }
						    break;
				  }
	    }
	    system("cls");
    } while (ch != 'q');
}

double BalanceInquiry(User* u)
{
	return u->balance;
}

void Withdraw(User* u, double amount)
{
	if(u!=NULL)
	{
		    if(u->balance>=amount)
		    {
		    	   u->balance-=amount;
		    	   cout<<"You have Successfully Withdrawn Your Amount....!"<<endl;
		    }
		    else
		    {
		    	  cout<<" You have insufficient Balance! Please deposit first."<<endl;
		    }
	}
}					
void Deposit(User* u, double D)
{
	   if(u!=NULL)
	   u->balance += D;
	   else
	   cout<<"For Deposit, You must be Logged In First"<<endl;
}					   
						   	    	     	
char UserMenu()
{
	char choice;
    USERMENU:
    {
        cout << " d-> Deposit Money" << endl;
        cout << " w-> Withdraw Money" << endl;
        cout << " r-> Request Balance" << endl;
        cout << " q-> Logout" << endl;
        cout << endl << " > ";
        cin >> choice;
    }
	if (choice == 'w' || choice == 'r' || choice == 'd' || choice == 'q')
        return choice;
    else
	{
	    cout << endl << "Invalid Input. Please Select a Correct Choice." << endl;
        goto USERMENU;	
	}
}

User* Authorization(string uName, string Pass)
{
	User* temp = users;
	while (temp!=NULL)
	{
		if(temp->UserName == uName && temp->Password == Pass)
		{
			cout << "Access Granted!" << endl;
			system("pause");
            return temp;
		}
        temp=temp->next;
	}
	return NULL;
} 

void CreateAccount() 
{
	User* u =  new User();
	cout <<"Enter Your User Name: ";
	cin>>u->UserName;
	
	cout<<"Enter Your Password: ";
	cin>>u->Password;
	
	
	u->next=users;
	users=u;
	
	cout<<"Account Create: "<< u->UserName << " / " << u->Password << endl;
	
	cout<<"Thank You! Your account has been created!" << endl;
	system("pause");
}   

void Welcome()   
{
	cout<<"Hi welcome to the ATM Machine!"<<endl;	
} 

char MainMenu() 
{ 
    char menu;
    MAINMENU:
    {
    	cout << " l-> Login" << endl;
        cout << " c-> Create New Account" << endl;
        cout << " q-> Quit" << endl;
        cout << endl << " > ";
        cin >> menu;
    }
    
    if(menu== 'l' || menu== 'c' || menu== 'q')
    	return menu;
    else
	{
		cout<<"Please Select the Right Menu Option"<<endl;
		goto MAINMENU;
	}	
}

