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

void showMainMenu();
void showServiceMenu();
void showGlasses(const int &glassesCount);

int callServiseMenu(int &currentGlassesNumber, double &allowedCash);

void showCheckCashBalanceInMainMenu();
void showDepositMoneyInMainMenu();
void showMaintenanceServiceInMainMenu();
void showMarkaCoffeeMachineInMainMenu();
void showNamingInMainMenu();
void showSelectCoffeeInMainMenu();
void showProseeds(double &cash);

void fillCoffeeMachineWithGlasses(int &glassesLeft);
void takeOutProceeds(double &avaliableCash);

void showWrongInputMessage();

double buyCoffee(double userBalance, double price, int glasses);
double getCurrentCashBalance(double userBalance);
double putCashInCoffeeMachine(double userBalance, double byn);

int removeGlasses(double userBalance, double price, int glasses);

bool isAccessAllowed();

int main()
{
    int choiceNumber = 0;
    int glasses = 7;
    double userBalance = 0.0;

    while (true)
    {
        showMainMenu();
        cout << "Please choice number: ";
        cin >> choiceNumber;
        cout << endl;

        switch (choiceNumber)
        {
        case 1:
            userBalance = getCurrentCashBalance(userBalance);
            break;
        case 2:
            userBalance = buyCoffee(userBalance, PRICE_CAPPUCCINO, glasses);
            glasses = removeGlasses(userBalance, PRICE_CAPPUCCINO, glasses);
            break;
        case 3:
            userBalance = buyCoffee(userBalance, PRICE_ESPRESSO, glasses);
            glasses = removeGlasses(userBalance, PRICE_ESPRESSO, glasses);
            break;
        case 4:
            userBalance = buyCoffee(userBalance, PRICE_LATTE, glasses);
            glasses = removeGlasses(userBalance, PRICE_LATTE, glasses);
            break;
        case 5:
<<<<<<< HEAD
            cash = putCashInCoffeeMachine(cash, BYN_BILL_05);
            break;
        case 6:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_1);
            break;
        case 7:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_2);
            break;
        case 8:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_5);
            break;
        case 9:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_10);
            break;
        case 10:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_20);
            break;
        case 11:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_50);
            break;
        case 12:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_100);
            break;
        case 13:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_200);
            break;
        case 14:
            cash = putCashInCoffeeMachine(cash, BYN_BILL_500);
=======
            userBalance = putCashInCoffeeMachine(userBalance, FIFTY_BELARUS_COPECK);
            break;
        case 6:
            userBalance = putCashInCoffeeMachine(userBalance, ONE_BYN);
            break;
        case 7:
            userBalance = putCashInCoffeeMachine(userBalance, TWO_BYN);
            break;
        case 8:
            userBalance = putCashInCoffeeMachine(userBalance, FIVE_BYN);
            break;
        case 9:
            userBalance = putCashInCoffeeMachine(userBalance, TEN_BYN);
            break;
        case 10:
            userBalance = putCashInCoffeeMachine(userBalance, TWENTY_BYN);
            break;
        case 11:
            userBalance = putCashInCoffeeMachine(userBalance, FIFTY_BYN);
            break;
        case 12:
            userBalance = putCashInCoffeeMachine(userBalance, ONE_HUNDRED_BYN);
            break;
        case 13:
            userBalance = putCashInCoffeeMachine(userBalance, TWO_HUNDRED_BYN);
            break;
        case 14:
            userBalance = putCashInCoffeeMachine(userBalance, FIVE_HUNDRED_BYN);
>>>>>>> d414af00a93fa18c9db644d510a41dfeb035d760
            break;
        case 15:
            if (isAccessAllowed())
            {
                cout << "Access allowed." << endl;
                callServiseMenu(glasses, userBalance);
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
         << "5.  " << BYN_BILL_05 << " Byn"
         << "   "
         << "6. " << BYN_BILL_1 << " Byn "
         << "    *" << endl;
    cout << "* "
         << "7.  " << BYN_BILL_2 << " Byn    "
         << " "
         << "8. " << BYN_BILL_5 << " Byn "
         << "    *" << endl;
    cout << "* "
         << "9.  " << BYN_BILL_10 << " Byn   "
         << " "
         << "10. " << BYN_BILL_20 << " Byn "
         << "  *" << endl;
    cout << "* "
         << "11. " << BYN_BILL_50 << " Byn   "
         << " "
         << "12. " << BYN_BILL_100 << " Byn"
         << "  *" << endl;
    cout << "* "
         << "13. " << BYN_BILL_200 << " Byn  "
         << " "
         << "14. " << BYN_BILL_500 << " Byn "
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
         << "2. CAPPUCCINO  " << PRICE_CAPPUCCINO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "3. ESPRESSO    " << PRICE_ESPRESSO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "4. LATTE       " << PRICE_LATTE << " Byn"
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

double getCurrentCashBalance(double userBalance)
{
    if (userBalance == 0)
    {
        cout << "Please, top up cash balance" << endl;
    }
    cout << "Cash balance: " << userBalance << " BYN" << endl
         << endl;

    return userBalance;
}

double putCashInCoffeeMachine(double userBalance, double byn)
{
    cout << "You put in coffee machine " << endl;
    cout << byn << " BYN" << endl
         << endl;

    return userBalance + byn;
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

void showWrongInputMessage()
{
    cout << "Wrong input! Try again..." << endl;
}

////////////////------------------------////////////////
//////////////// SERVICE MENU FUNCTIONS ////////////////
////////////////------------------------////////////////

int callServiseMenu(int &currentGlassesNumber, double &allowedCash)
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
            return 0;
        case 1:
            showProseeds(allowedCash);
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

void showProseeds(double &cash)
{
    cout << "Avaliable proseeds is " << cash << " BYN." << endl;
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
