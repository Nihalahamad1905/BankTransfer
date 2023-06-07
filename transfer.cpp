#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
	private:
		string accountNumber;
		double balance;
	
	public:
		
	BankAccount(const string& accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance){}
	
	friend void transfer(BankAccount& sender, BankAccount& receiver, double amount);
	
	void DisplayAmount()
	{
		cout<<"\nEnter the Account Number : "<<accountNumber<<endl;
		cout<<"\nEnter the Balance : $"<<balance<<endl;
	}
	
};
void transfer(BankAccount& sender, BankAccount& receiver, double amount)
{
	if(amount>sender.balance)
	{
		cout<<"\nError"<<endl;
	}
	else
	{
		sender.balance-=amount;
		receiver.balance+=amount;
		cout<<"\nTransfer is Done Sucessfully"<<endl;
	}
}

int main()
{
	string accountNumber1,accountNumber2;
	double initialBalance1,initialBalance2;
	
	cout<<"\nEnter the Account Nunmber of Bank 1 :";
	cin>>accountNumber1;
	cout<<"\nEnter the initial Balance of account if Bank 1 :";
	cin>>initialBalance1;
	
	cout<<"\nEnter the Account Nunmber of Bank 2 :";
	cin>>accountNumber2;
	cout<<"\nEnter the initial Balance of account if Bank 2 :";
	cin>>initialBalance2;
	
	BankAccount account1(accountNumber1,initialBalance1);
	BankAccount account2(accountNumber2,initialBalance2);
	
	cout<<"\nInitial Details"<<endl;
	account1.DisplayAmount();
	account2.DisplayAmount();
	
	double transferAmount;
	int ch;
	do{
	
	cout<<"\n1.Trnasfer From Bank 1 to Bank 2 \n2.Tranfer From Bank 2 to Bank 1 \n3.Exit";
	cout<<"Enter your choice - ";
	cin>>ch;
	switch(ch)
	{
	case 1:	
	cout<<"\nTransfering the amount from Bank 1 to Bank 2";
	cout<<"\nEnter the Amount to Transfer :";
	cin>>transferAmount;
	transfer(account1,account2,transferAmount);
	cout<<"\nFinal Details AFter Transfering";
	account1.DisplayAmount();
	account2.DisplayAmount();
	break;
	
	case 2: 
	cout<<"\nTransfering the amount from Bank 2 to Bank 1";
	cout<<"\nEnter the Amount to Transfer :";
	cin>>transferAmount;
	transfer(account2,account1,transferAmount);
	
	cout<<"\nFinal Details AFter Transfering";
	account1.DisplayAmount();
	account2.DisplayAmount();
	break;
	
	case 3: cout<<"THANK YOU"<<endl;
	return 0;
	break;
	
	default : cout<<"Enter Correct Choice"<<endl;
	}
}while(ch!=3);
	return 0;
}
