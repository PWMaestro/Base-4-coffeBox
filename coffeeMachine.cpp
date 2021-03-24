#include <iostream>
#include <cmath>

#define CAPPUCCINO_PRICE 2
#define ESPRESSO_PRICE 3
#define LATTE_PRICE 3.5
#define FIFTY_BELARUS_COPECK 0.5
#define ONE_BYN 1
#define TWO_BYN 2
#define FIVE_BYN 5
#define TEN_BYN 10
#define TWENTY_BYN 20
#define FIFTY_BYN 50
#define ONE_HUNDRED_BYN 100
#define TWO_HUNDRED_BYN 200
#define FIVE_HUNDRED_BYN 500

using namespace std;

void showMainMenu();

void showCheckCashBalanceInMainMenu();
void showDepositMoneyInMainMenu();
void showMaintenanceServiceInMainMenu();
void showMarkaCoffeeMachineInMainMenu();
void showNamingInMainMenu();
void showSelectCoffeeInMainMenu();

double buyCoffee(double cash, double price);
double getCurrentCashBalance(double cash);
double putCashInCoffeeMachine(double cash, double byn);

int main()
{
    int choiceNumber = 0;
    double cash = 0.0;

    while (true)
    {
        showMainMenu();
        cout << "Please choice number: ";
        cin >> choiceNumber;
        cout << endl;

        if (choiceNumber == 1)
        {
            cash = getCurrentCashBalance(cash);
        }
        else if (choiceNumber == 2)
        {
            cash = buyCoffee(cash, CAPPUCCINO_PRICE);
        }
        else if (choiceNumber == 3)
        {
            cash = buyCoffee(cash, ESPRESSO_PRICE);
        }
        else if (choiceNumber == 4)
        {
            cash = buyCoffee(cash, LATTE_PRICE);
        }
        else if (choiceNumber == 5)
        {
            cash = putCashInCoffeeMachine(cash, FIFTY_BELARUS_COPECK);
        }
        else if (choiceNumber == 6)
        {
            cash = putCashInCoffeeMachine(cash, ONE_BYN);
        }
        else if (choiceNumber == 7)
        {
            cash = putCashInCoffeeMachine(cash, TWO_BYN);
        }
        else if (choiceNumber == 8)
        {
            cash = putCashInCoffeeMachine(cash, FIVE_BYN);
        }
        else if (choiceNumber == 9)
        {
            cash = putCashInCoffeeMachine(cash, TEN_BYN);
        }
        else if (choiceNumber == 10)
        {
            cash = putCashInCoffeeMachine(cash, TWENTY_BYN);
        }
        else if (choiceNumber == 11)
        {
            cash = putCashInCoffeeMachine(cash, FIFTY_BYN);
        }
        else if (choiceNumber == 12)
        {
            cash = putCashInCoffeeMachine(cash, ONE_HUNDRED_BYN);
        }
        else if (choiceNumber == 13)
        {
            cash = putCashInCoffeeMachine(cash, TWO_HUNDRED_BYN);
        }
        else if (choiceNumber == 14)
        {
            cash = putCashInCoffeeMachine(cash, FIVE_HUNDRED_BYN);
        }
        else if (choiceNumber == 15)
        {
        }
    }

    return 0;
}

void showMainMenu()
{
    showMarkaCoffeeMachineInMainMenu();
    showNamingInMainMenu();
    showCheckCashBalanceInMainMenu();
    showSelectCoffeeInMainMenu();
    showDepositMoneyInMainMenu();
    showMaintenanceServiceInMainMenu();
    cout << endl;
    cout << endl;
}

void showCheckCashBalanceInMainMenu()
{
    cout << "* "
         << "1. Check cash balance"
         << "      *" << endl;
}

void showDepositMoneyInMainMenu()
{
    cout << "****** "
         << "Deposit money"
         << " *********" << endl;
    cout << "* "
         << "5.  " << FIFTY_BELARUS_COPECK << " Byn"
         << "   "
         << "6. " << ONE_BYN << " Byn "
         << "    *" << endl;
    cout << "* "
         << "7.  " << TWO_BYN << " Byn    "
         << " "
         << "8. " << FIVE_BYN << " Byn "
         << "    *" << endl;
    cout << "* "
         << "9.  " << TEN_BYN << " Byn   "
         << " "
         << "10. " << TWENTY_BYN << " Byn "
         << "  *" << endl;
    cout << "* "
         << "11. " << FIFTY_BYN << " Byn   "
         << " "
         << "12. " << ONE_HUNDRED_BYN << " Byn"
         << "  *" << endl;
    cout << "* "
         << "13. " << TWO_HUNDRED_BYN << " Byn  "
         << " "
         << "14. " << FIVE_HUNDRED_BYN << " Byn "
         << " *" << endl;
}

void showMarkaCoffeeMachineInMainMenu()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "*"
         << "*****************************" << endl;
    cout << "*"
         << "*****************************" << endl;
    cout << "*   "
         << "Italic coffee machine"
         << "    *" << endl;
    cout << "*"
         << "*****************************" << endl;
    cout << "*"
         << "*****************************" << endl;
}

void showMaintenanceServiceInMainMenu()
{
    cout << "****** "
         << "Maintenance service"
         << " ***" << endl;
    cout << "* "
         << "15. Service"
         << "                *" << endl;
    cout << "*"
         << "*****************************" << endl;
}

void showNamingInMainMenu()
{
    cout << "*        "
         << "MAIN MENU"
         << "           *" << endl;
    cout << "*"
         << "*****************************" << endl;
}

void showSelectCoffeeInMainMenu()
{
    cout << "****** "
         << "Select coffee"
         << " *********" << endl;
    cout << "* "
         << "2. CAPPUCCINO  " << CAPPUCCINO_PRICE << " Byn"
         << "       *" << endl;
    cout << "* "
         << "3. ESPRESSO    " << ESPRESSO_PRICE << " Byn"
         << "       *" << endl;
    cout << "* "
         << "4. LATTE       " << LATTE_PRICE << " Byn"
         << "     *" << endl;
}

double buyCoffee(double cash, double price)
{
    if (cash < price)
    {
        cout << "Sorry, you don't have enough money" << endl;
        cout << "You need to put cash in coffee" << endl;
        cout << "machine" << endl
             << endl;
        return cash;
    }
    else
    {
        cout << "Congratulation!!! You buy coffee" << endl
             << endl;
        return cash - price;
    }
}

double getCurrentCashBalance(double cash)
{
    if (cash == 0)
    {
        cout << "Please, top up cash balance" << endl;
    }
    cout << "Cash balance: " << cash << " BYN" << endl
         << endl;

    return cash;
}

double putCashInCoffeeMachine(double cash, double byn)
{
    cout << "You put in coffee machine " << endl;
    cout << byn << " BYN" << endl
         << endl;

    return cash + byn;
}
