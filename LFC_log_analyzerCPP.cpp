#include <iostream>
#include "LogTable.h"
#include "Command.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;
	Command * c = new Command("abc", 0);
	LogTable * l = new LogTable();
	return 0;
}
