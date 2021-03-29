#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

#define PIN 4689 // PIN just for test
#define MAX_PIN_INPUT_ATTEMPTS 3

#define GLASSES_CAPACITY 700

#define PRICE_CAPPUCCINO 2
#define PRICE_ESPRESSO 2.5
#define PRICE_LATTE 3

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

#define MANAGER_CONTACTS "+375 (29) 197-15-64 "

using namespace std;

int callCashDepositMenu(double &userBalance, double &cashBalance);
int callMainMenu(int &glasses, double &userBalance, double &cashBalance, int &avaliablePinInputAttempts);
int callServiceMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance, int &avaliablePinInputAttempts);

int addSugar();
int adjustPortionSize();
int checkGlasses(int &avaliableGlasses);
int checkAccess(int &avaliablePinInputAttempts);

void clearScreen();
void getMoneyFromUser(double &userBalance, double &cashBalance, double byn);
void giveCoffeeToUser(double &userBalance, double price, int &glasses);
void giveOutProceeds(double &avaliableCash);
void fillCoffeeMachineWithGlasses(int &glassesLeft);

void showCashDepositMenu();
void showMainMenu(double &userBalance, int &glasses);
void showServiceMenu(int &currentGlassesNumber, double &allowedCash);

void showLogo();
void showCoffeeList();
void showServiceInMainMenu();
void showUserBalanceInMainMenu(double &userBalance);

void showCoffeeIsPurchased();
void showDefaultCashDeposit();
void showDefaultGlasses();
void showGlasses(const int &glassesCount);
void showMoneyFromUser(double byn);
void showProceeds(const double &cash);
void showRowStars(int numberOfStars);
void showWrongInputMessage();

bool isMoneyEnough(double &currentBalance, double &itemPrice);

int main()
{
    int glasses = 7,
        avaliablePinInputAttempts = MAX_PIN_INPUT_ATTEMPTS;
    double userBalance = 0.0,
           cashBalance = 0.0;

    callMainMenu(glasses, userBalance, cashBalance, avaliablePinInputAttempts);

    return 0;
}

/******************************************************************************
 * 
 * MAIN MENU FUNCTIONS
 * 
******************************************************************************/

int callMainMenu(int &glasses, double &userBalance, double &cashBalance, int &avaliablePinInputAttempts)
{
    while (true)
    {
        int choiceOption = 0;

        showMainMenu(userBalance, glasses);

        cout << "Please choice option: ";
        cin >> choiceOption;
        cout << endl;

        clearScreen();

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
            switch (checkAccess(avaliablePinInputAttempts))
            {
            case 0:
                cout << "You canceled operation..." << endl;
                break;
            case 1:
                callServiceMenu(glasses, cashBalance, userBalance, avaliablePinInputAttempts);
                break;
            case -1:
                cout << endl;
                cout << "The coffee machine is blocked!" << endl;
                cout << "Reason: too many PIN input attempts." << endl;
                cout << "Please, call our manager to unlock:" << endl;
                cout << MANAGER_CONTACTS << endl;

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

void showMainMenu(double &userBalance, int &glasses)
{
    showLogo();
    cout << "*" << setw(23) << "MAIN MENU" << setw(16) << "*" << endl;
    showRowStars(40);
    cout << "" << setw(25) << "Cash balance: " << userBalance << " BYN" << endl;
    showRowStars(40);
    cout << "" << setw(30) << "Number of glasses: " << setw(1) << glasses << endl;
    showRowStars(40);
    showCoffeeList();
    cout << "*" << setw(24) << "4. Cash deposit" << setw(15) << "*" << endl;
    showRowStars(40);
    cout << "*" << setw(19) << "5. Service" << setw(20) << "*" << endl;
    showRowStars(40);
}

void showLogo()
{
    showRowStars(40);
    showRowStars(40);
    cout << "*" << setw(30) << "LavAzza coffee machine" << setw(9) << "*" << endl;
    showRowStars(40);
    showRowStars(40);
}

void showCoffeeList()
{
    cout << "*" << setw(25) << "Select Coffee" << setw(14) << "*" << endl;
    showRowStars(40);
    cout << "*" << setw(22) << "1. Cappuccino" << setw(5) << PRICE_CAPPUCCINO << setw(12) << "*" << endl;
    cout << "*" << setw(20) << "2. Espresso" << setw(7) << PRICE_ESPRESSO << setw(12) << "*" << endl;
    cout << "*" << setw(17) << "3. Latte" << setw(10) << PRICE_LATTE << setw(12) << "*" << endl;
    showRowStars(40);
}

void showCashDepositMenu()
{
    showRowStars(40);
    cout << "*" << setw(29) << "CASH DEPOSIT (BYN)" << setw(10) << "*" << endl;
    showRowStars(40);
    cout << "*" << setw(10) << "1. " << BYN_BILL_05 << setw(15) << "2. " << setw(3) << BYN_BILL_1 << setw(8) << "*" << endl;
    cout << "*" << setw(10) << "3. " << setw(3) << BYN_BILL_2 << setw(15) << "4. " << setw(3) << BYN_BILL_5 << setw(8) << "*" << endl;
    cout << "*" << setw(10) << "5. " << setw(3) << BYN_BILL_10 << setw(15) << "6. " << setw(3) << BYN_BILL_20 << setw(8) << "*" << endl;
    cout << "*" << setw(10) << "7. " << setw(3) << BYN_BILL_50 << setw(15) << "8. " << BYN_BILL_100 << setw(8) << "*" << endl;
    cout << "*" << setw(10) << "9. " << BYN_BILL_200 << setw(15) << "10. " << BYN_BILL_500 << setw(8) << "*" << endl;
    cout << "*" << setw(22) << " 0. EXIT" << setw(17) << "*" << endl;
    showRowStars(40);
}

void showCoffeeIsPurchased()
{
    showRowStars(40);
    cout << "  " << setw(30) << "Take your coffee, please!" << endl;
    showRowStars(40);
    cout << endl;
    cout << endl;
}

void showDefaultCashDeposit()
{
    showRowStars(40);
    cout << "  " << setw(5) << "Sorry, you don't have enough money!" << endl;
    cout << " " << setw(5) << "You need to put cash in coffee machine" << endl;
    showRowStars(40);
    cout << endl;
    cout << endl;
}

void showDefaultGlasses()
{
    showRowStars(40);
    cout << "  " << setw(10) << "Sorry we don't have glasses! Please," << endl;
    cout << "  " << setw(10) << "call our manager: " << MANAGER_CONTACTS << endl;
    showRowStars(40);
    cout << endl;
    cout << endl;
}

void showMoneyFromUser(double byn)
{
    showRowStars(40);
    cout << " " << setw(30) << "You put in coffee machine " << byn << " BYN" << setw(5) << " " << endl;
    showRowStars(40);
    cout << endl;
    cout << endl;
}

void showRowStars(int numberOfStars)
{
    for (int row = 0; row < numberOfStars; row++)
    {
        cout << "*";
    }
    cout << endl;
}

void showWrongInputMessage()
{
    showRowStars(40);
    cout << " " << setw(32) << "Wrong input! Try again..." << endl;
    showRowStars(40);
    cout << endl;
    cout << endl;
}

int callCashDepositMenu(double &userBalance, double &cashBalance)
{
    while (true)
    {
        int choiceOption = -1;

        showCashDepositMenu();

        cout << endl;
        cout << " " << setw(20) << "Please select how much money do you" << endl;
        cout << " " << setw(10) << "want to put in coffee machine: ";
        cin >> choiceOption;
        cout << endl;

        clearScreen();

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

int callServiceMenu(int &currentGlassesNumber, double &allowedCash, double &usersCurrentBalance, int &avaliablePinInputAttempts)
{
    while (true)
    {
        int choiceOption = -1;
        avaliablePinInputAttempts = MAX_PIN_INPUT_ATTEMPTS;

        showServiceMenu(currentGlassesNumber, allowedCash);

        cout << "Select option or press 0 to exit: ";
        cin >> choiceOption;

        clearScreen();

        switch (choiceOption)
        {
        case 0:
            usersCurrentBalance = 0;
            return 0;
        case 1:
            giveOutProceeds(allowedCash);
            break;
        case 2:
            fillCoffeeMachineWithGlasses(currentGlassesNumber);
            break;

        default:
            showWrongInputMessage();
            break;
        }
    }
}

void showServiceMenu(int &currentGlassesNumber, double &allowedCash)
{
    cout << endl
         << "Service menu" << endl;
    showRowStars(40);
    cout << "Glasses left: " << currentGlassesNumber << endl;
    cout << "Cash balance: " << allowedCash << " BYN" << endl;
    showRowStars(40);
    cout << "1. Issue proceeds" << endl;
    cout << "2. Load the glasses" << endl;
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

void clearScreen()
{
    system("cls");
}

void fillCoffeeMachineWithGlasses(int &glassesLeft)
{
    int newGlasses = 0,
        totalGlasses = glassesLeft,
        leftCapacity = GLASSES_CAPACITY - glassesLeft;


    cout << "How many glasses you want insert? ";
    cin >> newGlasses;

    totalGlasses += newGlasses;

    if (newGlasses <= 0)
    {
        cout << "Are you kidding me?!" << endl;
    }
    else if (totalGlasses > GLASSES_CAPACITY)
    {
        cout << "Too much glasses!";
        if (leftCapacity)
        {
            cout << "Try to insert less. You can only load " << leftCapacity << " glasses." << endl;
        }
        else
        {
            cout << "You can't load any glasses. Container is full.";
        }
    }
    else
    {
        glassesLeft = totalGlasses;
        cout << "You successfully filled coffeeBox with " << newGlasses << " glasses." << endl;
    }
}

int checkAccess(int &avaliablePinInputAttempts)
{
    int userInput = 0;

    while (avaliablePinInputAttempts > 0)
    {
        cout << "Please, enter a PIN number or press 0 to exit:";
        cin >> userInput;

        clearScreen();

        if (userInput == 0)
        {
            return 0;
        }
        else if (userInput == PIN)
        {
            return 1;
        }
        else
        {
            avaliablePinInputAttempts--;
            cout << "Wrong PIN number!" << endl;
        }
    }
    return -1;
}

int checkGlasses(int &avaliableGlasses)
{
    if (avaliableGlasses == 0)
    {
        showDefaultGlasses();
        return 0;
    }
    else
    {
        return avaliableGlasses;
    }
}

bool isMoneyEnough(double &currentBalance, double &itemPrice)
{
    if (currentBalance >= itemPrice)
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
    int choiceOption = 0;

    while (true)
    {
        showRowStars(40);
        cout << "*" << setw(32) << "Would you like to add sugar?" << setw(7) << "*" << endl;
        showRowStars(40);
        cout << "*" << setw(12) << " Yes " << setw(2) << "1" << setw(12) << "No " << setw(2) << "0" << setw(11) << "*" << endl;
        showRowStars(40);
        cout << "Please choice option: ";
        cin >> choiceOption;
        cout << endl;

        clearScreen();

        switch (choiceOption)
        {
        case 0:
            return 0;
        case 1:
            adjustPortionSize();
            return 0;

        default:
            showWrongInputMessage();
            cout << endl;
            break;
        }
    }
}

int adjustPortionSize()
{
    int currentPortionSize = 4;
    int choiceOption = -1;

    while (true)
    {
        showRowStars(40);
        cout << "*" << setw(30) << "Current portion size is " << currentPortionSize << setw(8) << "*" << endl;
        showRowStars(40);
        cout << "*" << setw(10) << "Confirm " << setw(1) << "0" << setw(12)
             << "Increase " << setw(1) << "1" << setw(12)
             << "Decrease " << setw(1) << "2" << setw(2) << "*" << endl;
        showRowStars(40);
        cout << "Please choice option: ";
        cin >> choiceOption;
        cout << endl;

        clearScreen();

        switch (choiceOption)
        {
        case 0:
            return currentPortionSize;
        case 1:
            if (currentPortionSize >= 8)
            {
                showRowStars(40);
                cout << " " << setw(36) << "Sorry, can't increase sugar portion!" << endl;
                cout << "" << setw(25) << "It's maximum" << endl;
                showRowStars(40);
                cout << endl;
                cout << endl;
            }
            else
            {
                currentPortionSize++;
            }
            break;
        case 2:
            if (currentPortionSize <= 0)
            {
                showRowStars(40);
                cout << " " << setw(36) << "Sorry, can't decrease sugar portion!" << endl;
                cout << "" << setw(25) << "It's minimum" << endl;
                showRowStars(40);
                cout << endl;
                cout << endl;
            }
            else
            {
                currentPortionSize--;
            }
            break;
        default:
            showWrongInputMessage();
            cout << endl;
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

            showCoffeeIsPurchased();

            userBalance -= price;
            glasses--;
        }
        else
        {
            showDefaultCashDeposit();
        }
    }
}

void getMoneyFromUser(double &userBalance, double &cashBalance, double byn)
{
    showMoneyFromUser(byn);

    userBalance += byn;
    cashBalance += byn;
}
