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

using namespace std;

class Divider
{
public:
	//                  
	//=================
	// 
	void doubleOreoDiv(int length) {
		cout << setw(length) << setfill(' ') << '\n';
		cout << setw(length) << setfill('=') << '\n';
		cout << setw(length) << setfill(' ') << '\n';
	}

	//                  
	//----------------
	// 
	void singleOreoDiv(int length) {
		cout << setw(length) << setfill(' ') << '\n';
		cout << setw(length) << setfill('-') << '\n';
		cout << setw(length) << setfill(' ') << '\n';
	}

	//                  
	//_________________
	// 
	void contLineOreoDiv(int length) {
		cout << setw(length) << setfill(' ') << '\n';
		cout << setw(length) << setfill('_') << '\n';
		cout << setw(length) << setfill(' ') << '\n';
	}
          
	//=================
	void doubleDiv(int length) {
		cout << setw(length) << setfill('=') << '\n';
	}
      
	//=================
	void singleDiv(int length) {
		cout << setw(length) << setfill('-') << '\n';
	}
         
	//________________
	void contLineDiv(int length) {
		cout << setw(length) << setfill('_') << '\n';
	}
};

