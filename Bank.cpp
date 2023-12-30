#include<bits/stdc++.h>
using namespace std;
class BankAccount{
private:
    int accountNumber;
    string accountHolder;
    double balance;
public:
    BankAccount(int accNumber, const string& accHolder) : accountNumber(accNumber), accountHolder(accHolder), balance(0.0){}
    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } 
        else{
            cout << "Invalid amount for deposit." << endl;
        }
    }
    void withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } 
        else{
            cout << "Invalid amount for withdrawal or insufficient funds." << endl;
        }
    }
    void displayBalance() const{
        cout << "Account Number: " << accountNumber << "\tAccount Holder: " << accountHolder << "\tBalance: $" << balance << endl;
    }
};
class Bank{
private:
    vector<BankAccount> accounts;
    int nextAccountNumber;
public:
    Bank() : nextAccountNumber(1001){}
    void createAccount(const string& accHolder){
        BankAccount newAccount(nextAccountNumber++, accHolder);
        accounts.push_back(newAccount);
        cout << "Account created successfully. Account Number: " << newAccountNumber << endl;
    }
    BankAccount* findAccount(int accNumber){
        for(auto& account : accounts){
            if(account.getAccountNumber() == accNumber){
                return &account;
            }
        }
        return nullptr;
    }
};
int main(){
    Bank bank;

    bank.createAccount("Shwetank");
    bank.createAccount("Shubham");
    BankAccount* ShwetankAccount = bank.findAccount(1001);
    if(ShwetankAccount){
        ShwetankAccount->deposit(500.0);
        ShwetankAccount->withdraw(200.0);
    }
    BankAccount* ShubhamAccount = bank.findAccount(1002);
    if(ShubhamAccount){
        ShubhamAccount->deposit(1000.0);
        ShubhamAccount->withdraw(300.0);
    }
    cout << "\nAccount Details:\n";
    if(ShwetankAccount){
        ShwetankAccount->displayBalance();
    }
    if(ShubhamAccount){
        ShubhamAccount->displayBalance();
    }
    return 0;
}
