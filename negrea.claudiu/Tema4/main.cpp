#include <string>
#include <iostream>

//vrem ca obiectele de tip BankAccount sa nu poata fi copiate
// folosesc clasa de baza din Item 6
class Uncopyable{
	protected:
		Uncopyable(){}
		~Uncopyable(){}
	private:
		Uncopyable(const Uncopyable&); // prevenire a copierii
		Uncopyable& operator = (const Uncopyable&);
		};




class BankAccount:private Uncopyable{
	
	public : 
		BankAccount(const std::string& name, const std::string& address,
			   const std::string& iban);
		~BankAccount();
		void showBalance();
		void updateBalance(int amount);
		
			   
	private:
		std::string theName;
		std::string theAddress;
		std::string theIban;
		int balanceAccount;
	};
	
	
	BankAccount::BankAccount(const std::string& name, const std::string& address,
			   const std::string& iban)
	:theName(name),
	 theAddress(address),
	 theIban(iban),
	 balanceAccount(0)
	{
		std::cout << " The account has been created " << "\n";
	}
	
	BankAccount::~BankAccount()
	{
		std::cout << " The account has been deleted " << "\n";
	}
	
	void BankAccount::showBalance(){
		std::cout << " The account balance is: " << balanceAccount << "\n";
		}
	void BankAccount::updateBalance(int amount){
		if(amount > 0){
			balanceAccount += amount;
			std::cout << " Deposit amount is : " << amount << "\n";
			std::cout << " The account balance is: " << balanceAccount << "\n";
		}
	}
	
	int main(){
	
		BankAccount c1("IonPop", "Bucuresti", "RO1234");
		c1.showBalance();
		c1.updateBalance(150);
		return 0;
	}	
