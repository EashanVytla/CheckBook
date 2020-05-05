// Eashan Vytla
// Grade: 9
// 3/30/2020
// Honors Computer Programming 3
// Project: Checkbook
// File: User.h
// Github: https://github.com/EashanVytla
// The purpose of this program is to that maintains a checkbook register and 
// reports a summary of the current months transactions.

#include <iostream>
#include <iomanip>
#include "VytlaEashan_User.h"
#include <string>

using namespace std;

void showKey();
int getCounts(double val);

int main()
{
    char replay = false;
    do {
        replay = false;
        User myuser;
        bool quit = false;
        int i = 0;
        string bankname;
        string accountname;
        bool skip = false;

        cout << "Welcome to Loot Bank\n";
        cout << setfill('-') << setw(20) << " \n";

        showKey();

        cout << setfill('-') << setw(20) << " \n";
        cout << "Please enter this month's transaction: \n";
        cout << "Balance: ";
        cin >> myuser.balance;

        char transTemp;

        do {
            cout << "Transaction: ";
            cin >> transTemp;

            if (transTemp == 'E' || transTemp == 'e') {
                quit = true;
                break;
            }

            if (transTemp == 'T' || transTemp == 't') {
                cout << "Amount for transfer(Available - " << myuser.balance << "): ";
                cin >> myuser.transaction[i].amount;
                if (myuser.transaction[i].amount < myuser.balance) {
                    cout << "Name of other bank: ";
                    cin >> bankname;
                    cout << "Name of your account: ";
                    cin >> accountname;
                    cout << "Request Sent :)" << endl;
                    cout << " " << endl;
                }
                else {
                    cout << "You don't have enough money to make this transfer!" << endl;
                    skip = true;
                }
            }
            else { 
                cout << "Amount: ";
                cin >> myuser.transaction[i].amount;
            }

            if (!skip) {
                myuser.transaction[i].transactionType = transTemp;
                i++;
                skip = false;
            }
        } while (!quit);


        myuser.outputfeedback(i);
        myuser.outputSummary();

        cout << "Run again?[Y/n]";
        cin >> replay;
        system("CLS");
    } while (replay == 'y' || replay == 'Y');
}

void showKey() {
    //Command Key 
    cout << "Transaction Key: " << endl;
    cout << "C - Check" << endl;
    cout << "D - Deposit" << endl;
    cout << "T - Transfer Accounts (Extra-Credit)" << endl;
    cout << "E - Exit loop" << endl;
}
