#include <iostream>
#include <cmath>

#define PIN 4689 // PIN just for test
#define PIN_INPUT_ATTEMPTS 3

#define MAX_NUMBER_OF_GLASSES 700

#define PRICE_CAPPUCCINO 3
#define PRICE_ESPRESSO 2.5
#define PRICE_LATTE 3.5
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

void fillCoffeMachineWithGlasses(int &glassesLeft);
void takeOutProceeds(double &avaliableCash);

void showWrongInputMessage();

double buyCoffee(double cash, double price);
double getCurrentCashBalance(double cash);
double putCashInCoffeeMachine(double cash, double byn);

bool isAccessAllowed();

int main()
{
    int choiceNumber = 0;
    int glasses = 7;
    double cash = 0.0;

    while (true)
    {
        showMainMenu();
        cout << "Please choice number: ";
        cin >> choiceNumber;
        cout << endl;

        switch (choiceNumber)
        {
        case 1:
            cash = getCurrentCashBalance(cash);
            break;
        case 2:
            cash = buyCoffee(cash, PRICE_CAPPUCCINO);
            break;
        case 3:
            cash = buyCoffee(cash, PRICE_ESPRESSO);
            break;
        case 4:
            cash = buyCoffee(cash, PRICE_LATTE);
            break;
        case 5:
            cash = putCashInCoffeeMachine(cash, FIFTY_BELARUS_COPECK);
            break;
        case 6:
            cash = putCashInCoffeeMachine(cash, ONE_BYN);
            break;
        case 7:
            cash = putCashInCoffeeMachine(cash, TWO_BYN);
            break;
        case 8:
            cash = putCashInCoffeeMachine(cash, FIVE_BYN);
            break;
        case 9:
            cash = putCashInCoffeeMachine(cash, TEN_BYN);
            break;
        case 10:
            cash = putCashInCoffeeMachine(cash, TWENTY_BYN);
            break;
        case 11:
            cash = putCashInCoffeeMachine(cash, FIFTY_BYN);
            break;
        case 12:
            cash = putCashInCoffeeMachine(cash, ONE_HUNDRED_BYN);
            break;
        case 13:
            cash = putCashInCoffeeMachine(cash, TWO_HUNDRED_BYN);
            break;
        case 14:
            cash = putCashInCoffeeMachine(cash, FIVE_HUNDRED_BYN);
            break;
        case 15:
            if ( isAccessAllowed() ) {
                cout << "Access allowed." << endl;
                callServiseMenu(glasses, cash);
            } else {
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
         << "2. CAPPUCCINO  " << PRICE_CAPPUCCINO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "3. ESPRESSO    " << PRICE_ESPRESSO << " Byn"
         << "       *" << endl;
    cout << "* "
         << "4. LATTE       " << PRICE_LATTE << " Byn"
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

bool isAccessAllowed()
{
    int pin = 0;

    for (int i = 1; i <= PIN_INPUT_ATTEMPTS; i++) {
        cout << "Please, enter a PIN number:";
        cin >> pin;
        if ( pin == PIN ) {
            return true;
        } else {
            cout << "Wrong PIN number!" << endl;
            cout << "You have " << PIN_INPUT_ATTEMPTS - i << " attempts left." << endl;
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
            fillCoffeMachineWithGlasses(currentGlassesNumber);
            break;
        
        default:
            showWrongInputMessage();
            break;
        }
    }
}

void showServiceMenu()
{
    cout << endl << "Service menu" << endl;
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

void fillCoffeMachineWithGlasses(int &glassesLeft)
{
    glassesLeft = MAX_NUMBER_OF_GLASSES;
    cout << "You successfully filled coffeeBox with glasses." << endl;
}
