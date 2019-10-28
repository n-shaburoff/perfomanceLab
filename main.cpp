#include "Data.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Info() {
	cout << "Write the type of the variable you want to check, you can also check all types" << endl;
	cout << "\"i\" for int" << endl;
	cout << "\"d\" for double" << endl;
	cout << "\"f\" for float" << endl;
	cout << "\"l\" for long" << endl;
	cout << "\"c\" for char" << endl;
	cout << "\"a\" for all" << endl;
	cout << "Press 1 to exit" << endl;
}

int main() {
	IntType Int; DoubleType Double; LongType Long; FloatType Float; CharType Char;
	cout << setiosflags(ios::left);
	char dataType = 'q';
	Info();
	do {
		cin >> dataType;
		switch (dataType) {
		case 'i': Int.print(); break;
		case 'd': Double.print(); break;
		case 'f': Float.print(); break;
		case 'l': Long.print(); break;
		case 'c': Char.print(); break;
		case 'a':  Int.print(); cout << endl;
			Double.print(); cout << endl;
			Float.print(); cout << endl;
			Long.print(); cout << endl;
			Char.print(); cout << endl; break;
		case '1': break;
		}
	} while (dataType != '1');
	return 0;
}