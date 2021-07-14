#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
private:
    int account_no;
    string account_holder_name;
    string account_type;
    double current_balance;
    double minimum_balance;

public:
    BankAccount()
    {

    }
    BankAccount(int no, string name, string type, double balance, double min_balance) : account_no(no), account_holder_name(name), account_type(type), current_balance(balance), minimum_balance(min_balance)
    {
    }
    void setInfo(void)
    {
        cout << "Account No: ";
        cin >> account_no;
        cout << "Acount Holder Name: ";
        cin >> account_holder_name;
        cout << "Account Type: ";
        cin >> account_type;
        cout << "Current Balance: ";
        cin >> current_balance;
        cout << "Minimum Balance: ";
        cin >> minimum_balance;
    }
    void showInfo(void)
    {
        cout << "Account No: " << account_no << endl;
        cout << "Acount Holder Name: " << account_holder_name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Current Balance: " << current_balance << endl;
        cout << "Minimum Balance: " << minimum_balance << endl;
    }
    void showBalance(void)
    {
        cout << "Current Balance: " << current_balance << endl;
    }
    void deposit(double val)
    {
        current_balance += val;
    }
    void withdrawal(double val)
    {
        if (current_balance - val >= minimum_balance)
            current_balance -= val;
        else
            cout << "Cannot Withdraw" << endl;
    }
    void giveInterest(double val = 2.5)
    {
        double interest = (current_balance * (val / 100));
        deposit(interest * 0.9);
    }
    ~BankAccount()
    {
        cout << "Account of Mr. " << account_holder_name << " with account no " << account_no << " is destroyed with a balance BDT " << current_balance << endl;
    }
};
int main(void)
{
    BankAccount acc1,acc2(65142,"Zaarin","Current",50000.00,1000);
    acc2.giveInterest(5.7);
    acc2.showInfo();
    acc1.setInfo();
    acc1.deposit(5000.00);
    acc1.showBalance();
    acc1.withdrawal(450.00);
    acc1.showInfo();
}