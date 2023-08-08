#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;

class Stock {
private:
    char name[20];
    float pr;
    int quant;



public:
    void get();
    void show() const;
    int stchk(char nm[30]);
    void withd(int qty);
    void refil(int qty);
     friend void displayStock(const Stock stockItems[], int numProducts);
};

class Dealer {
public:
    static void addNew(Stock stockItems[], int& numProducts);
    static void refill(Stock stockItems[], int numProducts);
    static void remove(Stock stockItems[], int& numProducts);
};

class Customer {
public:
    static void withdraw(Stock stockItems[], int numProducts);
};

class Employee {
public:
    static void refill(Stock stockItems[], int numProducts);
};

const int MAX_PRODUCTS = 100;
Stock stockItems[MAX_PRODUCTS];
int numProducts = 0;

void Stock::withd(int qty) {
    if (quant >= qty) {
        quant -= qty;
        cout << "\n\nStock updated.\n";
        cout << "\n\nTotal price to be paid: " << pr * qty;
        cout << "\n";
    } else {
        cout << "\n\nInsufficient stock";
        cout << "\n";
    }
    getch();
}

void Stock::refil(int qty) {
    quant += qty;
    cout << "\n\nStock updated.";
    cout << "\n";
    getch();
}

int Stock::stchk(char nm[30]) {
    if (strcmp(nm, name) == 0)
        return 0;
    else
        return 1;
}

void Stock::get() {
    cin >> name >> pr >> quant;
}

void Stock::show() const {
    cout << "\n" << name << "\t\t\t" << quant << "\t\t\t" << pr;
}

void Dealer::addNew(Stock stockItems[], int& numProducts) {
    cout << "\nEnter the No. of Products that you wish to add: ";
    int n;
    cin >> n;

    if (n != 0) {
        for (int i = 0; i < n; i++) {
            cout << "\n\nInput the name, price and the quantity of item respectively\n\n";
            stockItems[numProducts].get();
            numProducts++;
            cout << "\n\nItem updated";
            cin.get();
        }
        cout << "\n\nStock Updated!!";
        cin.get();
    } else {
        cin.get();
        cout << "\n\nNo items to be added";
        cout << "\n";
    }
}

void Dealer::refill(Stock stockItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the products name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (stockItems[i].stchk(temp) == 0) {
            stockItems[i].refil(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    cin.get();
    cin.get();
}

void Dealer::remove(Stock stockItems[], int& numProducts) {
    int i = 0;
    char temp[30];
    cout << "\n\t\t\t\tDelete Record";
    cout << "\n\nEnter the name of the product:";
    cin >> temp;

    for (i = 0; i < numProducts; i++) {
        if (stockItems[i].stchk(temp) == 0) {
            stockItems[i].show();
            cout << "\n\n\t\tRecord deleted";
            cout << "\n";
            numProducts--;
            for (int j = i; j < numProducts; j++) {
                stockItems[j] = stockItems[j + 1];
            }
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    getch();
}

void Customer::withdraw(Stock stockItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the product's name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (stockItems[i].stchk(temp) == 0) {
            stockItems[i].withd(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    cin.get();
    getch();
}

void Employee::refill(Stock stockItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the products name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (stockItems[i].stchk(temp) == 0) {
            stockItems[i].refil(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!\n";
    }

    cin.get();
    cin.get();
}

void displayStock(const Stock stockItems[], int numProducts) {
    int i = 1;
    cout << "\n==================================================================";
    cout << "\n\n=================\tTHE STOCK ITEMS ARE\t==================";
    cout << "\n\n==================================================================\n";
    cout << "\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
    cout << "\n\n============================================================\n";

    for (i = 0; i < numProducts; i++) {
        stockItems[i].show();
    }

    if (i == 0) {
        cout << "\n\n\t\t\t!!Empty record room!!";
        getch();
    }
}

int main() {
    int i, j;
    cout << " \t\t\t|============ WELCOME TO STORE MANAGEMENT ============|\n\n\n";
    getch();
mainmenu:
    cout << "\n\t\t\t\t\tSTORE MANAGEMENT SYSTEM\n";
    cout << "\t\t\t=============================================================";
    cout << "\n\n\t\t\t\t\t   1. Dealer Menu\n\t\t\t\t\t   2. Customer Menu\n\t\t\t\t\t   3. Employee Menu";
    cout << "\n\n\t\t\t=============================================================\n";
    cout << "\n\nEnter Your Choice:";
    cin >> j;

    if (j == 1) {
        char pass[10];
        cout << "\n\n\t\t\t\t\tEnter the password letter by letter: ";

        for (int z = 0; z < 6; z++) {
            pass[z] = getch();

            for (i = 1; i <= 1; i++) {
                cout << "*";
            }
        }

        if (strcmp(pass, "dealer") == 0) {
            cout << "\n\n\nCongrats!!Access Granted!!\n\n";
            getch();

        dealermenu:
            cout << "\n\t\t\t===============================================================";
            cout << "\n\n\t\t\t\t\t   DEALER MENU\n\t\t\t\t\t1. Add new product\n\t\t\t\t\t2. Display stock\n\t\t\t\t\t3. Refill\n\t\t\t\t\t4. Remove an item\n\t\t\t\t\t5. Return to main menu\n\t\t\t\t\t6. Exit:";
            cout << "\n\n\n\t\t\t==========================END OF MENU===========================";
            cout << "\n\n Enter your Choice :\t";
            cin >> i;

            if (i == 1) {
                Dealer::addNew(stockItems, numProducts);
                getch();
                goto dealermenu;
            } else if (i == 2) {
                displayStock(stockItems, numProducts);
                getch();
                goto dealermenu;
            } else if (i == 3) {
                Dealer::refill(stockItems, numProducts);
                goto dealermenu;
            } else if (i == 4) {
                Dealer::remove(stockItems, numProducts);
                getch();
                goto dealermenu;
            } else if (i == 5) {
                goto mainmenu;
            } else {
                getch();
                exit(0);
            }
        } else {
            cout << "\n\n\nAuthorised Personnel Only\n\n";
            getch();
            exit(0);
        }
    } else if (j == 2) {
    custmenu:
        cout << "\n\t\t\t=================================================================";
        cout << "\n\n\t\t\t\t\t    CUSTOMER MENU\n\t\t\t\t\t1. Purchase\n\t\t\t\t\t2. Display stock\n\t\t\t\t\t3. Return to main menu\n\t\t\t\t\t4. Exit:";
        cout << "\n\n\n\t\t\t==========================END OF MENU=============================";
        cout << "\n\n Enter your Choice :\t";
        cin >> i;

        if (i == 1) {
            Customer::withdraw(stockItems, numProducts);
            getch();
            goto custmenu;
        } else if (i == 2) {
            displayStock(stockItems, numProducts);
            getch();
            goto custmenu;
        } else if (i == 3) {
            goto mainmenu;
        } else {
            getch();
            exit(0);
        }
    } else if (j == 3) {
        cout << "\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
        char pass[6];

        for (int z = 0; z < 3; z++) {
            pass[z] = getch();

            for (i = 1; i <= 1; i++) {
                cout << "*";
            }
        }

        if (strcmp(pass, "emp") == 0) {
        empmenu:
            cout << "\n\t\t\t=================================================================";
            cout << "\n\n\t\t\t\t\tEMPLOYEE MENU\n\t\t\t\t\t1. Display stock\n\t\t\t\t\t2. Refill\n\t\t\t\t\t3. Return to main menu\n\t\t\t\t\t4. Exit";
            cout << "\n\n\n\t\t\t==========================END OF MENU=============================";
            cout << "\n\n Enter your Choice :\t";
            cin >> i;

            if (i == 1) {
                displayStock(stockItems, numProducts);
                getch();
                goto empmenu;
            } else if (i == 2) {
                Employee::refill(stockItems, numProducts);
                goto empmenu;
            } else if (i == 3) {
                goto mainmenu;
            } else {
                cout << "\n\n\n\t\t\tThank You!!";
                getch();
                exit(0);
            }
        } else {
            cout << "\n\nSorry!! Access Denied..\n\n";
            getch();
            exit(0);
        }
    }

    getch();
}
