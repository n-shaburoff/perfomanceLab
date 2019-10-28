#include "Data.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

double taktsPerSec = CLOCKS_PER_SEC;

const int ITERATIONS = 1000000;
const int BINS = 5;
const int OPERATIONS = 10;

const string sPlus = "+";
const string sMinus = "-";
const string sMultipl = "*";
const string sDivision = "/";

const string intType = "int";
const string floatType = "float";
const string doubleType = "double";
const string longType = "long";
const string charType = "char";

void output(string sign, string type, double tOperation, double fast, bool flag) {
	cout << setw(3) << " " << setw(4) << sign;
	cout << setw(9) << type;
	cout << setw(13) << ITERATIONS * OPERATIONS / (tOperation / taktsPerSec)<<"\t";
	double percent = 100 * fast / tOperation;
	double bins = percent / BINS;
	flag == 1 ? cout << floor(percent) : cout << ceil(percent);
	cout << "%" << '\t';
	int N = 1;
	flag == 1 ? N = floor(bins) : N = ceil(bins);
	for (int i = 0; i < N; i++) cout << "X";
	cout << endl;
}

double IntType::addition() {
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a3 = a2 + a1; a4 = a3 + a2; a5 = a4 + a3; a6 = a5 + a4; a7 = a6 + a5;
		a8 = a7 + a6; a9 = a8 + a7; a10 = a8 + a9; a1 = a10 + a9; a2 = a1 + a10;

	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double IntType::subtraction() {
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a3 = a2 - a1; a4 = a3 - a2; a5 = a4 - a3; a6 = a5 - a4; a7 = a6 - a5;
		a8 = a7 - a6; a9 = a8 - a7; a10 = a8 - a9; a1 = a10 - a9; a2 = a1 - a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double IntType::multiplication() {
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a3 = a2 * a1; a4 = a3 * a2; a5 = a4 * a3; a6 = a5 * a4; a7 = a6 * a5;
		a8 = a7 * a6; a9 = a8 * a7; a10 = a8 * a9; a1 = a10 * a9; a2 = a1 * a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double IntType::division() {
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;

		a4 = a2 / a10; a5 = a3 / a1; a4 = a5 / a1; a3 = a6 / a2; a3 = a8 / a1;
		a1 = a10 / a2; a10 = a9 / a1; a7 = a6 / a1; a8 = a7 / a1; a6 = a8 / a2;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double IntType::empty() {
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

void IntType::print() {
	double tAddition = (addition() - empty()),
		tSubtraction = (subtraction() - empty()),
		tMultiplication = (multiplication() - empty()),
		tDivision = (division() - empty());
	double fast = tAddition;
	if (tSubtraction <= fast) fast = tSubtraction;
	if (tMultiplication <= fast) fast = tMultiplication;
	if (tDivision <= fast) fast = tDivision;

	output(sPlus, intType, tAddition, fast, 1);
	output(sMinus, intType, tSubtraction, fast, 1);
	output(sMultipl, intType, tMultiplication, fast, 1);
	output(sDivision, intType, tDivision, fast, 0);
}

double FloatType::addition() {
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 + a2; a2 = a1 + a3; a3 = a2 + a4; a4 = a3 + a5; a5 = a4 + a6;
		a6 = a5 + a7; a7 = a6 + a8; a8 = a7 + a9; a9 = a8 + a10; a10 = a9 + a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double FloatType::subtraction() {
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 - a2; a2 = a1 - a3; a3 = a2 - a4; a4 = a3 - a5; a5 = a4 - a6;
		a6 = a5 - a7; a7 = a6 - a8; a8 = a7 - a9; a9 = a8 - a10; a10 = a9 - a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double FloatType::multiplication() {
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 * a2; a2 = a1 * a2; a3 = a2 * a3; a4 = a3 * a4; a5 = a4 * a5;
		a6 = a5 * a6; a7 = a6 * a7; a8 = a7 * a8; a9 = a8 * a9; a10 = a9 * a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double FloatType::division() {
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1; a3 = 333 % i + 1; a4 = 4444 % i + 1; a5 = 555 % i + 1;
		a6 = 666 % i + 1; a7 = 77 % i + 1; a8 = 888888 % i + 1; a9 = 9999999 % i + 1; a10 = 101 % i + 1;

		a4 = a2 / a10; a5 = a3 / a1; a4 = a5 / a1; a3 = a6 / a2; a3 = a8 / a1;
		a1 = a10 / a2; a10 = a9 / a1; a7 = a6 / a1; a8 = a7 / a1; a6 = a8 / a2;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double FloatType::empty() {
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

void FloatType::print() {
	double tAddition = (addition() - empty()),
		tSubtraction = (subtraction() - empty()),
		tMultiplication = (multiplication() - empty()),
		tDivision = (division() - empty());
	double fast = tAddition;
	if (tSubtraction <= fast) fast = tSubtraction;
	if (tMultiplication <= fast) fast = tMultiplication;
	if (tDivision <= fast) fast = tDivision;

	output(sPlus, floatType, tAddition, fast, 1);
	output(sMinus, floatType, tSubtraction, fast, 1);
	output(sMultipl, floatType, tMultiplication, fast, 1);
	output(sDivision, floatType, tDivision, fast, 0);
}

double DoubleType::addition() {
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 + a2; a2 = a1 + a3; a3 = a2 + a4; a4 = a3 + a5; a5 = a4 + a6;
		a6 = a5 + a7; a7 = a6 + a8; a8 = a7 + a9; a9 = a8 + a10; a10 = a9 + a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double DoubleType::subtraction() {
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 - a2; a2 = a1 - a3; a3 = a2 - a4; a4 = a3 - a5; a5 = a4 - a6;
		a6 = a5 - a7; a7 = a6 - a8; a8 = a7 - a9; a9 = a8 - a10; a10 = a9 - a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double DoubleType::multiplication() {
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 * a2; a2 = a1 * a2; a3 = a2 * a3; a4 = a3 * a4; a5 = a4 * a5;
		a6 = a5 * a6; a7 = a6 * a7; a8 = a7 * a8; a9 = a8 * a9; a10 = a9 * a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double DoubleType::division() {
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1; a3 = 333 % i + 1; a4 = 4444 % i + 1; a5 = 555 % i + 1;
		a6 = 666 % i + 1; a7 = 77 % i + 1; a8 = 888888 % i + 1; a9 = 9999999 % i + 1; a10 = 101 % i + 1;

		a4 = a2 / a10; a5 = a3 / a1; a4 = a5 / a1; a3 = a6 / a2; a3 = a8 / a1;
		a1 = a10 / a2; a10 = a9 / a1; a7 = a6 / a1; a8 = a7 / a1; a6 = a8 / a2;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double DoubleType::empty() {
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

void DoubleType::print() {
	double tAddition = (addition() - empty()), tSubtraction = (subtraction() - empty()), tMultiplication = (multiplication() - empty()), tDivision = (division() - empty());
	double fast = tAddition;
	if (tSubtraction <= fast) fast = tSubtraction;
	if (tMultiplication <= fast) fast = tMultiplication;
	if (tDivision <= fast) fast = tDivision;

	output(sPlus, doubleType, tAddition, fast, 1);
	output(sMinus, doubleType, tSubtraction, fast, 1);
	output(sMultipl, doubleType, tMultiplication, fast, 1);
	output(sDivision, doubleType, tDivision, fast, 0);
}


double LongType::addition() {
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a1 = a10 + a2; a2 = a1 + a3; a3 = a2 + a4; a4 = a3 + a5; a5 = a4 + a6;
		a6 = a5 + a7; a7 = a6 + a8; a8 = a7 + a9; a9 = a8 + a10; a10 = a9 + a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double LongType::subtraction() {
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a1 = a10 - a2; a2 = a1 - a3; a3 = a2 - a4; a4 = a3 - a5; a5 = a4 - a6;
		a6 = a5 - a7; a7 = a6 - a8; a8 = a7 - a9; a9 = a8 - a10; a10 = a9 - a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double LongType::multiplication() {
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a1 = a10 * a2; a2 = a1 * a2; a3 = a2 * a3; a4 = a3 * a4; a5 = a4 * a5;
		a6 = a5 * a6; a7 = a6 * a7; a8 = a7 * a8; a9 = a8 * a9; a10 = a9 * a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double LongType::division() {
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;

		a4 = a2 / a10; a5 = a3 / a1; a4 = a5 / a1; a3 = a6 / a2; a3 = a8 / a1;
		a1 = a10 / a2; a10 = a9 / a1; a7 = a6 / a1; a8 = a7 / a1; a6 = a8 / a2;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double LongType::empty() {
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

void LongType::print() {
	double tAddition = (addition() - empty()), tSubtraction = (subtraction() - empty()), tMultiplication = (multiplication() - empty()), tDivision = (division() - empty());
	double fast = tAddition;
	if (tSubtraction <= fast) fast = tSubtraction;
	if (tMultiplication <= fast) fast = tMultiplication;
	if (tDivision <= fast) fast = tDivision;

	output(sPlus, longType, tAddition, fast, 1);
	output(sMinus, longType, tSubtraction, fast, 1);
	output(sMultipl, longType, tMultiplication, fast, 1);
	output(sDivision, longType, tDivision, fast, 0);
}

double CharType::addition() {
	auto a1 = static_cast<char>(111); auto a2 = static_cast<char>(22); auto a3 = static_cast<char>(33);
	auto a4 = static_cast<char>(4);   auto a5 = static_cast<char>(55); auto a6 = static_cast<char>(6);
	auto a7 = static_cast<char>(77);  auto a8 = static_cast<char>(88); auto a9 = static_cast<char>(9);
	auto a10 = static_cast<char>(101);
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 11 % i + 1; a2 = 222 % i + 1;

		a1 = a10 + a2; a2 = a1 + a3; a3 = a2 + a4; a4 = a3 + a5; a5 = a4 + a6;
		a6 = a5 + a7; a7 = a6 + a8; a8 = a7 + a9; a9 = a8 + a10; a10 = a9 + a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double CharType::subtraction() {
	auto a1 = static_cast<char>(111); auto a2 = static_cast<char>(22); auto a3 = static_cast<char>(33);
	auto a4 = static_cast<char>(4);   auto a5 = static_cast<char>(55); auto a6 = static_cast<char>(6);
	auto a7 = static_cast<char>(77);  auto a8 = static_cast<char>(88); auto a9 = static_cast<char>(9);
	auto a10 = static_cast<char>(101);
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a1 = a10 - a2; a2 = a1 - a3; a3 = a2 - a4; a4 = a3 - a5; a5 = a4 - a6;
		a6 = a5 - a7; a7 = a6 - a8; a8 = a7 - a9; a9 = a8 - a10; a10 = a9 - a1;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double CharType::multiplication() {
	auto a1 = static_cast<char>(111); auto a2 = static_cast<char>(22); auto a3 = static_cast<char>(33);
	auto a4 = static_cast<char>(4);   auto a5 = static_cast<char>(55); auto a6 = static_cast<char>(6);
	auto a7 = static_cast<char>(77);  auto a8 = static_cast<char>(88); auto a9 = static_cast<char>(9);
	auto a10 = static_cast<char>(101);
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a1 = a10 * a2; a2 = a1 * a2; a3 = a2 * a3; a4 = a3 * a4; a5 = a4 * a5;
		a6 = a5 * a6; a7 = a6 * a7; a8 = a7 * a8; a9 = a8 * a9; a10 = a9 * a10;
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double CharType::division() {
	auto a1 = static_cast<char>(111); auto a2 = static_cast<char>(22); auto a3 = static_cast<char>(33);
	auto a4 = static_cast<char>(4);   auto a5 = static_cast<char>(55); auto a6 = static_cast<char>(6);

	clock_t t1 = clock();
	for (int i = 10; i < 10000000; i++) {
		a1 = i % 11 + 1; a2 = i % 9 + 1;

		a3 = a1 / a2; while (a3 == 0) a3 = rand();
		a4 = a2 / a3; while (a4 == 0) a4 = rand();
		a5 = a3 / a4; while (a5 == 0) a5 = rand();
		a6 = a5 / a4; while (a6 == 0) a6 = rand();

	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

double CharType::empty() {
	auto a1 = static_cast<char>(111); auto a2 = static_cast<char>(22); auto a3 = static_cast<char>(33);
	auto a4 = static_cast<char>(4);   auto a5 = static_cast<char>(55); auto a6 = static_cast<char>(6);
	auto a7 = static_cast<char>(77);  auto a8 = static_cast<char>(88); auto a9 = static_cast<char>(9);
	auto a10 = static_cast<char>(101);
	clock_t t1 = clock();
	for (long i = 10; i < ITERATIONS; i++) {
		a1 = i % 88 + 1; a2 = i % 9 + 1; a3 = static_cast<char>(33); a4 = static_cast<char>(4);
		a5 = static_cast<char>(55); a6 = static_cast<char>(6);  a7 = static_cast<char>(77);
		a8 = static_cast<char>(88); a9 = static_cast<char>(9);  a10 = static_cast<char>(101);
	}
	clock_t t2 = clock();
	double time = t2 - t1;
	return time;
}

void CharType::print() {
	double tAddition = (addition() - empty()),
		tSubtraction = (subtraction() - empty()),
		tMultiplication = (multiplication() - empty()),
		tDivision = (division() - empty());

	double fast = tAddition;

	if (tSubtraction <= fast) fast = tSubtraction;
	if (tMultiplication <= fast) fast = tMultiplication;
	if (tDivision <= fast) fast = tDivision;

	output(sPlus, charType, tAddition, fast, 1);
	output(sMinus, charType, tSubtraction, fast, 1);
	output(sMultipl, charType, tMultiplication, fast, 1);
	output(sDivision, charType, tDivision, fast, 0);
}
