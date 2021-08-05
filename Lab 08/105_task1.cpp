#include <bits/stdc++.h>
using namespace std;
class Account
{
protected:
	string accountNo;
	string accountName;
	float balance;
	void generateAccountNo(int pref, int nextAc)
	{
		accountNo = to_string(pref) + "-" + to_string(nextAc);
	}
	void setter(string ac_name, float b)
	{
		accountName = ac_name;
		balance = b;
	}

public:
	Account(string ac_name = "", float b = 0.0) : accountName(ac_name), balance(b)
	{
	}

	void getter(void)
	{
		cout << "Account number: " << accountNo << endl;
		cout << "Account name: " << accountName << endl;
		cout << "Balance: " << balance << endl;
	}
};

class CurrentAccount : public Account
{
private:
	const int serviceCharge = 100;
	const int accountPrefix = 100;
	static int nextAccount;

public:
	CurrentAccount(string ac_name = "", float b = 0.0) : Account(ac_name, b)
	{
		generateAccountNo(accountPrefix, nextAccount);
		nextAccount++;
	}
	void Description(void)
	{
		cout << "It's a " << accountName << ".It's service charge is " << serviceCharge << endl;
	}
};
// initialising static value
int CurrentAccount ::nextAccount = 0;

class LoanAccount : public Account
{
private:
	float monthlyDeposit;
	float interestRate;
	const int accountPrefix = 900;
	static int nextAccount;

public:
	LoanAccount(string ac_name = "", float b = 0.0, float dep = 0.0, float intRate = 7.0) : Account(ac_name, b), monthlyDeposit(dep), interestRate(intRate / 100)
	{
		generateAccountNo(accountPrefix, nextAccount);
		nextAccount++;
	}
	void setter(string ac_name, float b, float dep, float rate)
	{
		Account::setter(ac_name, b);
		monthlyDeposit = dep;
		interestRate = rate / 100;
	}
	void getter(void)
	{
		Account::getter();
		cout << "Monthly deposit: " << monthlyDeposit << endl;
		cout << "Interest rate: " << interestRate * 100 << "% " << endl;
	}
	void Description(void)
	{
		cout << "It's a " << accountName << ".It's interest rate is " << interestRate * 100 << "%." << endl;
		cout << "You need to deposit a fixed amount of money each month" << endl;
	}
};
int LoanAccount ::nextAccount = 0;
class SavingsAccount : public Account
{
private:
	float monthlyDeposit;
	float interestRate;
	const int accountPrefix = 200;
	static int nextAccount;

public:
	SavingsAccount(string ac_name = "", float b = 0.0, float dep = 0.0, float intRate = 5.0) : Account(ac_name, b), monthlyDeposit(dep), interestRate(intRate / 100)
	{
		generateAccountNo(accountPrefix, nextAccount);
		nextAccount++;
	}
	void setter(string ac_name, float b, float dep, float rate)
	{
		Account::setter(ac_name, b);
		monthlyDeposit = dep;
		interestRate = rate / 100;
	}
	void getter(void)
	{
		Account::getter();
		cout << "Monthly deposit: " << monthlyDeposit << endl;
		cout << "Interest rate: " << interestRate * 100 << "% " << endl;
	}
	void Description(void)
	{
		cout << "It's a " << accountName << ".It's interest rate is " << interestRate * 100 << "%." << endl;
		cout << "You need to deposit a fixed amount of money each month" << endl;
	}
};
// initialising static value
int SavingsAccount::nextAccount = 0;
// child class of Account class

class MonthlyDepositScheme : public Account
{
protected:
	float monthlyDeposit;
	float interestRate;
	float maximumInterest;
	const int accountPrefix = 300;
	static int nextAccount;

public:
	MonthlyDepositScheme(string ac_name, float b, float dep, float intRate, float maxm) : Account(ac_name, b), monthlyDeposit(dep), interestRate(intRate / 100), maximumInterest(maxm / 100)
	{
		generateAccountNo(accountPrefix, nextAccount);
		nextAccount++;
	}
	void setter(string ac_name, float b, float dep, float rate, float interest)
	{
		Account::setter(ac_name, b);
		monthlyDeposit = dep;
		interestRate = rate;
		maximumInterest = interest;
	}
	void getter(void)
	{
		Account::getter();
		cout << "Monthly deposit: " << monthlyDeposit << endl;
		cout << "Interest rate: " << interestRate * 100 << endl;
		cout << "Maximum Interest rate: " << maximumInterest * 100 << "% " << endl;
	}
	void Description(void)
	{
		cout << "It's a " << accountName << "." << endl;
		cout << "It's interest rate is " << interestRate * 100 << "%." << endl;
		cout << "It's maximum interest rate is " << maximumInterest * 100 << "%." << endl;
		cout << "You need to deposit a fixed amount of money each month" << endl;
	}
};
// initialising static value
int MonthlyDepositScheme::nextAccount = 0;

// child class of MonthlyDepositScheme

class TwoYearMDS : public MonthlyDepositScheme
{
public:
	TwoYearMDS(string ac_name = "", float b = 0.0, float dep = 0.0, float intRate = 10.0, float maxm = 15.0) : MonthlyDepositScheme(ac_name, b, dep, intRate, maxm)
	{
	}
};
class FiveYearMDS : public MonthlyDepositScheme
{
public:
	FiveYearMDS(string ac_name = "", float b = 0.0, float dep = 0.0, float intRate = 10.0, float maxm = 15.0) : MonthlyDepositScheme(ac_name, b, dep, intRate, maxm)
	{
	}
};
class InitalDepositMDS : public MonthlyDepositScheme
{
private:
	float initalDepositAmount;

public:
	InitalDepositMDS(string ac_name = "", float b = 0.0, float dep = 0.0, float intRate = 10.0, float maxm = 15.0, float initial = 0.0) : MonthlyDepositScheme(ac_name, b, dep, intRate, maxm), initalDepositAmount(initial)
	{
	}
	void setter(string ac_name, float b, float dep, float rate, float interest)
	{
		MonthlyDepositScheme::setter(ac_name, b, dep, rate, interest);
		initalDepositAmount = b;
	}
	void getter(void)
	{
		MonthlyDepositScheme::getter();
		cout << "Initial Deposit Amount: " << initalDepositAmount << endl;
	}
};

int main(void)
{
	CurrentAccount c1("Current Account", 30000);
	c1.Description();
	c1.getter();
	SavingsAccount s1("Saving Account", 35000, 500, 10);
	s1.Description();
	s1.getter();
	TwoYearMDS T1("Two Year Monthly Deposit Scheme", 50000, 700, 7, 10);
	T1.Description();
	T1.getter();
	FiveYearMDS F1("Five Year Monthly Deposit Scheme", 400000, 5000, 8, 12);
	F1.Description();
	F1.getter();
	InitalDepositMDS I1("Initial Deposit Monthly Deposit Scheme", 1000000, 5000, 10, 15, 10);
	I1.Description();
	I1.getter();
	LoanAccount L1;
	L1.setter("Loan Account", 40000, 1000, 5);
	L1.Description();
	L1.getter();
}
