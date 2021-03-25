#include <iostream>
#include <cmath>

#define PIN 4689 // PIN just for test
#define MAX_PIN_INPUT_ATTEMPTS 3

#define MAX_NUMBER_OF_GLASSES 700

#define PRICE_CAPPUCCINO 3
#define PRICE_ESPRESSO 2.5
#define PRICE_LATTE 3.5

#define BYN_BILL_05 0.5
#define BYN_BILL_1 1
#define BYN_BILL_2 2
#define BYN_BILL_5 5
#define BYN_BILL_10 10
#define BYN_BILL_20 20
#define BYN_BILL_50 50
#define BYN_BILL_100 100
#define BYN_BILL_200 200
#define BYN_BILL_500 500

using namespace std;

void showMainMenu(double &userBalance);
void showServiceMenu();
void showGlasses(const int &glassesCount);

int callServiseMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance);

void showUserBalance(double &userBalance);
void showDepositMoneyInMainMenu();
void showMaintenanceServiceInMainMenu();
void showMarkaCoffeeMachineInMainMenu();
void showNamingInMainMenu();
void showSelectCoffeeInMainMenu();
void showProceeds(double &cash);

void fillCoffeeMachineWithGlasses(int &glassesLeft);
void takeOutProceeds(double &avaliableCash);

void showWrongInputMessage();

double buyCoffee(double userBalance, double price, int glasses);
double putMoneyInCoffeeMachine(double balance, double byn);

int removeGlasses(double userBalance, double price, int glasses);

bool isAccessAllowed();

int main()
{
    int choiceNumber = 0;
    int glasses = 7;
    double userBalance = 0.0, cashBalance = 0.0;

    while (true)
    {
        showMainMenu(userBalance);
        cout << "Please choice number: ";
        cin >> choiceNumber;
        cout << endl;

        switch (choiceNumber)
        {
        case 1:
            userBalance = buyCoffee(userBalance, PRICE_CAPPUCCINO, glasses);
            glasses = removeGlasses(userBalance, PRICE_CAPPUCCINO, glasses);
            break;
        case 2:
            userBalance = buyCoffee(userBalance, PRICE_ESPRESSO, glasses);
            glasses = removeGlasses(userBalance, PRICE_ESPRESSO, glasses);
            break;
        case 3:
            userBalance = buyCoffee(userBalance, PRICE_LATTE, glasses);
            glasses = removeGlasses(userBalance, PRICE_LATTE, glasses);
            break;
        case 4:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_05);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_05);
            break;
        case 5:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_1);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_1);
            break;
        case 6:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_2);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_2);
            break;
        case 7:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_5);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_5);
            break;
        case 8:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_10);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_10);
            break;
        case 9:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_20);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_20);
            break;
        case 10:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_50);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_50);
            break;
        case 11:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_100);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_100);
            break;
        case 12:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_200);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_200);
            break;
        case 13:
            userBalance = putMoneyInCoffeeMachine(userBalance, BYN_BILL_500);
            cashBalance = putMoneyInCoffeeMachine(cashBalance, BYN_BILL_500);
            break;
        case 14:
            if (isAccessAllowed())
            {
                cout << "Access allowed." << endl;
                callServiseMenu(glasses, cashBalance, userBalance);
            }
            else
            {
                cout << "The coffeeBox is shutting down currently..." << endl;
                return 1;
            }
            break;

        default:
            showWrongInputMessage();
            break;
        }
    }

    return 0;
}

/******************************************************************************
 * 
 * MAIN MENU FUNCTIONS
 * 
******************************************************************************/

void showMainMenu(double &userBalance)
{
    showMarkaCoffeeMachineInMainMenu();
    showNamingInMainMenu();
    showUserBalance(userBalance);
    showSelectCoffeeInMainMenu();
    showDepositMoneyInMainMenu();
    showMaintenanceServiceInMainMenu();
    cout << endl;
    cout << endl;
}

void showUserBalance(double &userBalance)
{
    cout << "*    "
         << "Cash balance: " << userBalance << " BYN"
         << "     *" << endl;
}

void showDepositMoneyInMainMenu()
{
    cout << "****** "
         << "Deposit money"
         << " *********" << endl;
    cout << "* "
         << "4.  " << BYN_BILL_05 << " Byn"
         << "   "
         << "5. " << BYN_BILL_1 << " Byn "
         << "    *" << endl;
    cout << "* "
         << "6.  " << BYN_BILL_2 << " Byn    "
         << " "
         << "7. " << BYN_BILL_5 << " Byn "
         << "    *" << endl;
    cout << "* "
         << "8.  " << BYN_BILL_10 << " Byn   "
         << " "
         << "9. " << BYN_BILL_20 << " Byn "
         << "  *" << endl;
    cout << "* "
         << "10. " << BYN_BILL_50 << " Byn   "
         << " "
         << "11. " << BYN_BILL_100 << " Byn"
         << "  *" << endl;
    cout << "* "
         << "12. " << BYN_BILL_200 << " Byn  "
         << " "
         << "13. " << BYN_BILL_500 << " Byn "
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
         << "14. Service"
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
         << "1. CAPPUCCINO  " << PRICE_CAPPUCCINO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "2. ESPRESSO    " << PRICE_ESPRESSO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "3. LATTE       " << PRICE_LATTE << " Byn"
         << "     *" << endl;
}

double buyCoffee(double userBalance, double price, int glasses)
{
    if (glasses != 0)
    {
        if (userBalance < price)
        {
            cout << "Sorry, you don't have enough money" << endl;
            cout << "You need to put cash in coffee" << endl;
            cout << "machine" << endl
                 << endl;
            return userBalance;
        }
        else
        {
            cout << "Congratulation!!! You buy coffee" << endl
                 << endl;
            return userBalance - price;
        }
    }
    else
    {
        return userBalance;
    }
}

double putMoneyInCoffeeMachine(double balance, double byn)
{
    cout << "You put in coffee machine " << endl;
    cout << byn << " BYN" << endl
         << endl;

    return balance + byn;
}

/******************************************************************************
 * 
 * SERVICE MENU FUNCTIONS
 * 
******************************************************************************/

int callServiseMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance)
{
    while (true)
    {
        int choiceNumber = -1;

        showServiceMenu();

        cout << "Select option or press 0 to exit: ";
        cin >> choiceNumber;

        switch (choiceNumber)
        {
        case 0:
            usersCurrentBalance = 0;
            return 0;
        case 1:
            showProceeds(allowedCash);
            break;
        case 2:
            takeOutProceeds(allowedCash);
            break;
        case 3:
            showGlasses(currentGlassesNumber);
            break;
        case 4:
            fillCoffeeMachineWithGlasses(currentGlassesNumber);
            break;

        default:
            showWrongInputMessage();
            break;
        }
    }
}

void showServiceMenu()
{
    cout << endl
         << "Service menu" << endl;
    cout << "--------------------" << endl;
    cout << "1. Show avaliable revenue" << endl;
    cout << "2. To issue proceeds" << endl;
    cout << "3. Show remaining glasses" << endl;
    cout << "4. Take glasses" << endl;
    cout << "0. Exit" << endl;
}

void showProceeds(double &cash)
{
    cout << "Avaliable proceeds is " << cash << " BYN." << endl;
}

void showGlasses(const int &glassesCount)
{
    cout << glassesCount << " glasses left." << endl;
}

void takeOutProceeds(double &avaliableCash)
{
    cout << "Opening the lock..." << endl;
    cout << "Opened." << endl;

    avaliableCash = 0;

    cout << "You successfully take out all proseeds." << endl;
}

/******************************************************************************
 * 
 * GENERAL FUNCTIONS
 * 
******************************************************************************/

void fillCoffeeMachineWithGlasses(int &glassesLeft)
{
    int newGlasses = 0,
        totalGlasses = glassesLeft;

    cout << "How many glasses you want insert? ";
    cin >> newGlasses;

    totalGlasses += newGlasses;

    if (totalGlasses > MAX_NUMBER_OF_GLASSES)
    {
        cout << "Too much glasses! Try to insert less." << endl;
    }
    else
    {
        glassesLeft = totalGlasses;
        cout << "You successfully filled coffeeBox with " << newGlasses << " glasses." << endl;
    }
}

void showWrongInputMessage()
{
    cout << "Wrong input! Try again..." << endl;
}

bool isAccessAllowed()
{
    int pin = 0;

    for (int i = 1; i <= MAX_PIN_INPUT_ATTEMPTS; i++)
    {
        cout << "Please, enter a PIN number:";
        cin >> pin;
        if (pin == PIN)
        {
            return true;
        }
        else
        {
            cout << "Wrong PIN number!" << endl;
            cout << "You have " << MAX_PIN_INPUT_ATTEMPTS - i << " attempts left." << endl;
        }
    }

    return false;
}

int removeGlasses(double userBalance, double price, int glasses)
{
    if (glasses == 0)
    {
        cout << "Sorry we don't have glasses" << endl;
        cout << "Please, call our manager" << endl;
        glasses = 0;
        return glasses;
    }
    else
    {
        if (userBalance < price)
        {
            return glasses;
        }

        return glasses - 1;
    }
}
