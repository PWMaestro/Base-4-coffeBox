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

int callMainMenu(int &glasses, double &userBalance, double &cashBalance);
int callServiceMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance);
int callCashDepositMenu(double &userBalance, double &cashBalance);

int addSugar();
int adjustPortionSize();
int checkGlasses(int &avaliableGlasses);

void showMainMenu(double &userBalance);
void showServiceMenu();
void showCashDepositMenu();

void giveCoffeeToUser(double &userBalance, double price, int &glasses);
void getMoneyFromUser(double &userBalance, double &cashBalance, double byn);

void showMarkaCoffeeMachineInMainMenu();
void showNamingInMainMenu();
void showUserBalance(double &userBalance);
void showSelectCoffeeInMainMenu();
void showCashDepositInMainMenu();
void showServiceInMainMenu();

void showProceeds(const double &cash);
void giveOutProceeds(double &avaliableCash);
void showGlasses(const int &glassesCount);
void fillCoffeeMachineWithGlasses(int &glassesLeft);

void showWrongInputMessage();

void removeGlass(int &glasses);

bool isMoneyEnough(double &currentBalance, double &itemPrice);
bool isAccessAllowed();

int main()
{
    int glasses = 7;
    double userBalance = 0.0,
           cashBalance = 0.0;

    callMainMenu(glasses, userBalance, cashBalance);

    return 0;
}

int callMainMenu(int &glasses, double &userBalance, double &cashBalance)
{
    while (true)
    {
        int choiceOption = 0;

        showMainMenu(userBalance);
        cout << "Please choice number: ";
        cin >> choiceOption;
        cout << endl;

        switch (choiceOption)
        {
        case 1:
            giveCoffeeToUser(userBalance, PRICE_CAPPUCCINO, glasses);
            break;
        case 2:
            giveCoffeeToUser(userBalance, PRICE_ESPRESSO, glasses);
            break;
        case 3:
            giveCoffeeToUser(userBalance, PRICE_LATTE, glasses);
            break;
        case 4:
            callCashDepositMenu(userBalance, cashBalance);
            break;
        case 5:
            if (isAccessAllowed())
            {
                cout << "Access allowed." << endl;
                callServiceMenu(glasses, cashBalance, userBalance);
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
    showCashDepositInMainMenu();
    showServiceInMainMenu();
    cout << endl;
    cout << endl;
}

void showCashDepositMenu()
{
    cout << "*"
         << "*****************************" << endl;
    cout << "* "
         << "1. " << BYN_BILL_05 << " Byn"
         << "   "
         << "2. " << BYN_BILL_1 << " Byn "
         << "     *" << endl;
    cout << "* "
         << "3. " << BYN_BILL_2 << " Byn    "
         << " "
         << "4. " << BYN_BILL_5 << " Byn "
         << "     *" << endl;
    cout << "* "
         << "5. " << BYN_BILL_10 << " Byn   "
         << " "
         << "6. " << BYN_BILL_20 << " Byn "
         << "    *" << endl;
    cout << "* "
         << "7. " << BYN_BILL_50 << " Byn   "
         << " "
         << "8. " << BYN_BILL_100 << " Byn"
         << "    *" << endl;
    cout << "* "
         << "9. " << BYN_BILL_200 << " Byn  "
         << " "
         << "10. " << BYN_BILL_500 << " Byn "
         << "  *" << endl;
    cout << "* "
         << "        "
         << " 0. EXIT"
         << "           *" << endl;
    cout << "*"
         << "*****************************" << endl;
}

void showUserBalance(double &userBalance)
{
    cout << "   "
         << "Cash balance: " << userBalance << " BYN"
         << "" << endl;
}

void showCashDepositInMainMenu()
{
    cout << "* "
         << "4. Cash deposit"
         << "            *" << endl;
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

void showServiceInMainMenu()
{
    cout << "* "
         << "5. Service"
         << "                 *" << endl;
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
         << "     *" << endl;
    cout << "* "
         << "3. LATTE       " << PRICE_LATTE << " Byn"
         << "     *" << endl;
    cout << "*"
         << "*****************************" << endl;
}

int callCashDepositMenu(double &userBalance, double &cashBalance)
{
    while (true)
    {
        int choiceOption = -1;

        showCashDepositMenu();
        cout << endl;
        cout << "Please select how much money" << endl;
        cout << "you want to put in coffee machine: ";
        cin >> choiceOption;
        cout << endl;

        switch (choiceOption)
        {
        case 0:
            return 0;
        case 1:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_05);
            break;
        case 2:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_1);
            break;
        case 3:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_2);
            break;
        case 4:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_5);
            break;
        case 5:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_10);
            break;
        case 6:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_20);
            break;
        case 7:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_50);
            break;
        case 8:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_100);
            break;
        case 9:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_200);
            break;
        case 10:
            getMoneyFromUser(userBalance, cashBalance, BYN_BILL_500);
            break;
        default:
            showWrongInputMessage();
            break;
        }
    }
}

/******************************************************************************
 * 
 * SERVICE MENU FUNCTIONS
 * 
******************************************************************************/

int callServiceMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance)
{
    while (true)
    {
        int choiceOption = -1;

        showServiceMenu();

        cout << "Select option or press 0 to exit: ";
        cin >> choiceOption;

        switch (choiceOption)
        {
        case 0:
            usersCurrentBalance = 0;
            return 0;
        case 1:
            showProceeds(allowedCash);
            break;
        case 2:
            giveOutProceeds(allowedCash);
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

void showProceeds(const double &cash)
{
    cout << "Avaliable proceeds is " << cash << " BYN." << endl;
}

void showGlasses(const int &glassesCount)
{
    cout << glassesCount << " glasses left." << endl;
}

void giveOutProceeds(double &avaliableCash)
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

void removeGlass(int &glasses)
{
    glasses--;
}

int checkGlasses(int &avaliableGlasses)
{
    if (avaliableGlasses == 0)
    {
        cout << "Sorry we don't have glasses" << endl;
        cout << "Please, call our manager" << endl;

        return 0;
    }
    else
    {
        return avaliableGlasses;
    }
}

bool isMoneyEnough(double &currentBalance, double &itemPrice)
{
    if (currentBalance > itemPrice)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int addSugar()
{
    int sugar = 0;

    cout << "Should I add any sugar?" << endl;

    while (true)
    {
        cout << "Press 1 if yes," << endl;
        cout << "press 0 if no." << endl;
        cin >> sugar;

        switch (sugar)
        {
        case 0:
            cout << "No" << endl;
            return 0;
        case 1:
            cout << "Yes" << endl;
            adjustPortionSize();
            return 0;
        
        default:
            showWrongInputMessage();
            break;
        }
    }
}

int adjustPortionSize()
{
    int currentPortionSize = 4;
    int chosenOption = -1;

    while (true)
    {
        cout << "Current portion size is " << currentPortionSize << "." << endl;
        cout << "Press 0 to decrease" << endl;
        cout << "Press 1 to increase" << endl;
        cout << "Press 2 to confirm" << endl;
        
        cin >> chosenOption;

        switch (chosenOption)
        {
        case 0:
            if (currentPortionSize <= 0)
            {
                cout << "Can't decrease sugar portion!" << endl;
                cout << "You chose zero sugar portion!" << endl;
            }
            else
            {
                currentPortionSize--;
            }
            break;
        case 1:
            if (currentPortionSize >= 8)
            {
                cout << "Can't increase sugar portion!" << endl;
                cout << "You chose maximum sugar portion!" << endl;
            }
            else
            {
                currentPortionSize++;
            }
            break;
        case 2:
            cout << "Adding " << currentPortionSize << " sugar portion..." << endl;
            return currentPortionSize;
            break;
        
        default:
            showWrongInputMessage();
            break;
        }
    }
}

void giveCoffeeToUser(double &userBalance, double price, int &glasses)
{
    if (checkGlasses(glasses))
    {
        if (isMoneyEnough(userBalance, price))
        {
            addSugar();
            removeGlass(glasses);
            cout << "Congratulation!!! You buy coffee" << endl
                 << endl;
            userBalance -= price;
        }
        else
        {
            cout << "Sorry, you don't have enough money" << endl;
            cout << "You need to put cash in coffee" << endl;
            cout << "machine" << endl
                 << endl;
        }
    }
}

void getMoneyFromUser(double &userBalance, double &cashBalance, double byn)
{
    cout << "You put in coffee machine " << endl;
    cout << byn << " BYN" << endl
         << endl;

    userBalance += byn;
    cashBalance += byn;
}
