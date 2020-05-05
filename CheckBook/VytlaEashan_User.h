// Eashan Vytla
// Grade: 9
// 3/30/2020
// Honors Computer Programming 3
// Project: Checkbook
// File: User.h
// Github: https://github.com/EashanVytla
// The purpose of this program is to that maintains a checkbook register and 
// reports a summary of the current months transactions.


#pragma once

#include <iostream>
#include <iomanip>
#include "VytlaEashan_Divider.h"
#include <string>

using namespace std;

class Transaction
{
public:
    char transactionType;
    float amount;

    Transaction()
    {
        transactionType = ' ';
        amount = 0.0;
    }
};

class User
{
private:
    int numDeposits = 0;
    int numChecks = 0;
    int numTranfers = 0;
    Divider div;
    double startbalance;

public:
    Transaction transaction[100];

    double balance;

    float checks = 0; 
    float deposits = 0; 
    float tranfers = 0;
    int insufficientcount = 0; 

    //Used when the user is done entering everything and just wants to output results
    //based data into array based data so that it is easier to work with
    void outputfeedback(int maxlen) {
        div.doubleOreoDiv(60);
        cout << "Transaction                      Amount          Balance\n";
        addList("Starting Balance", balance, balance);
        startbalance = balance;
        for (int i = 0; i < maxlen; i++) {
            switch (transaction[i].transactionType) {
            case 'C':
            case 'c':
                if(balance >= transaction[i].amount){
                    checks += transaction[i].amount;
                    balance -= checks;
                    addList("Checks", checks, balance);
                    numChecks++;
                }
                else {
                    balance -= 10;
                    insufficientcount++;
                    addList("Insufficient Funds", 10, balance);
                }
                break;
            case 'D': 
            case 'd':
                deposits += transaction[i].amount;
                balance += deposits;
                addList("Deposits", deposits, balance);
                numDeposits++;
                break;
            case 'T':
            case 't':
                tranfers += transaction[i].amount;
                balance -= tranfers;
                addList("Tranfers", tranfers, balance);
                numTranfers++;
                break;
            default:
                cout << "Illegal Transaction Code" << endl;
                break;
            }
        }
        balance -= 5;
        if (balance < 0) {
            cout << "NOTICE: You are not able to pay your service charge of $5.00.\nIf you do not pay this within the next 30 days, your account will be closed.\n\n";
        }
        else {
            addList("Service Charge: ", 5, balance);
        }
    }

    void outputSummary() {
        div.doubleOreoDiv(60);
        cout << "Account Summary\n";
        cout << "                                 Number          Amount\n";
        addListSummary("Beginning Balance", NULL, startbalance);
        addListSummary("Plus Deposits", numDeposits, deposits);
        addListSummary("Less Withdrawals", 1 + numChecks + insufficientcount + numTranfers, tranfers + checks + 5 + (insufficientcount * 10));
        addListSummary("Ending Balance", NULL, balance);
    }

    //Gets the number of digits in a number for formatting
    int getDigits(double val) {
        int count = 0;
        while ((int)val != 0) {
            count++;
            val /= 10;
        }
        return count;
    }

    void addList(string caption, double value, double value2) {
        int valueoffset = 0;
        int value2offset = 0;
        valueoffset = getDigits(value) + 3;
        value2offset = getDigits(value2) + 3;

        int captionoffset = caption.size();
        cout << caption;
        cout << setiosflags(ios::right | ios::fixed | ios::showpoint) << setprecision(2);
        if (value != 0) {
            cout << setw((34 - captionoffset) - (valueoffset - 5)) << setfill(' ') << " ";
        }
        else {
            cout << setw(35 - captionoffset) << setfill(' ') << " ";
        }
        
        cout << value;
        
        if (value2 != 0) {
            cout << setw(12 - (value2offset - 5)) << setfill(' ') << " ";
        }
        else {
            cout << setw(12 + 1) << setfill(' ') << " ";
        }
        
        cout << value2;
        cout << '\n';
    }

    void addListSummary(string caption, int value, double value2) {
        int valueoffset = 0;
        int value2offset = 0;
        valueoffset = getDigits(value) + 3;
        value2offset = getDigits(value2) + 3;

        int captionoffset = caption.size();
        cout << caption;
        cout << setiosflags(ios::right | ios::fixed | ios::showpoint) << setprecision(0);
        if (value != 0) {
            cout << setw((34 - captionoffset) - (valueoffset - 5)) << setfill(' ') << " ";
        }
        else {
            cout << setw(35 - captionoffset) << setfill(' ') << " ";
        }

        cout << setiosflags(ios::right | ios::fixed | ios::showpoint) << setprecision(2);
        cout << value;

        if (value2 != 0) {
            cout << setw(12 - (value2offset - 5)) << setfill(' ') << " ";
        }
        else {
            cout << setw(12 + 1) << setfill(' ') << " ";
        }

        cout << value2;
        cout << '\n';
    }
};

