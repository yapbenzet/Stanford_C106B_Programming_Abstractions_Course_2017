#pragma once

#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
#include <map>
#include <string>
using namespace std;


//Problem ONE------------------------------------------------
struct entryT {
	string firstName;
	string lastName;
	string phoneNo;

	bool operator<(const entryT& other) const {
		if (this->lastName == other.lastName)
			return (this->firstName < other.firstName);
		return this->lastName < other.lastName;
	}
};
//Functor - object that behaves like a function - to be passed into set parameter list
//@brief functor compares all strings in their lowercase forms making the set case-insensitive
struct lex_compare {
	bool operator() (const string & a, const string & b) {
		string first = "";
		string second = "";
		for (unsigned i = 0; i < a.length(); ++i)
			first += tolower(a.at(i));
		for (unsigned i = 0; i < b.length(); ++i)
			second += tolower(b.at(i));
		return (first < second);
	}
};


//Problem TWO------------------------------------------------
struct pointT { int x, y; };
struct cityT {
	string name; pointT coords;
	bool operator() (const cityT& a, const cityT &b) { return a.name < b.name; }
};


//Problem THREE------------------------------------------------
struct pairT {
	string first, second;
};
struct functor {
	bool operator()(const pairT &a, const pairT & b) const
	{
		if (a.first < b.first) return true;
		else if ((a.first == b.first) && (a.second < b.second)) return true;
		else return false;
	}
};
set <pairT, functor> CartesianProduct(set <string> & one, set<string> & two) {
	set<string>::iterator itS;
	set<string>::iterator itS2;
	set<pairT, functor> result;

	for (itS = one.begin(); itS != one.end(); ++itS)
		for (itS2 = two.begin(); itS2 != two.end(); ++itS2)
		{
			pairT temp;
			temp.first = *itS;
			temp.second = *itS2;
			result.insert(temp);
		}
	return result;
}


//Problem FOUR-----------------------------------------------------
int CannonballZ(int h) {
	//base case 
	if (h == 1)
		return h;

	return (h*h) + CannonballZ(h - 1);
}


//Problem FIVE------------------------------------------------
string reverseStringRecursively(string s) {
	string result = "";

	//base case
	if (s.length() == 0)
		return "";

	return  s.at(s.length() - 1) + reverseStringRecursively(s.substr(0, s.length() - 1));
}
string reverseStringNonRecursively(string s) {
	string result = "";
	unsigned count = 1;
	while (count <= s.length())
	{
		result += s.at(s.length() - count);
		count++;
	}
	return result;
}


//Problem SIX------------------------------------------------
int GCD(int x, int y) {
	//Base case
	if (x % y == 0)
	{
		cout << "Gcd is " << y << endl;
		return y;
	}
	return GCD(y, x % y);
}


//Problem EIGHT------------------------------------------------

void ListMemonics(string s) {

	//Initialize the keypad
	map<string, string >  keypad;
	keypad.insert_or_assign("2", "ABC");
	keypad.insert_or_assign("3", "DEF");
	keypad.insert_or_assign("4", "GHI");
	keypad.insert_or_assign("5", "JKL");
	keypad.insert_or_assign("6", "MNO");
	keypad.insert_or_assign("7", "PRS");
	keypad.insert_or_assign("8", "TUV");
	keypad.insert_or_assign("9", "WXY");

	//Create set for combining the key values and producing the result
	set<string> letterCombinationSet;
	vector<string> tempV;

	//Process the input string and add corresponding mapped letter values to the set
	for (unsigned i = 0; i < s.length(); ++i)
	{
		string temp = keypad.at(s.substr(i, 1));
		tempV.push_back(temp);
	}

	int length = s.length();
	int size = 3;

	//Process the set
	vector<string>::iterator itS;
	vector<vector<char>> matrix(length);


	for (int i = 0; i < length; ++i)
		for (int j = 0; j < size; ++j)
			matrix[j].push_back(tempV[i][j]);

	//Print out the characters selected
	for (int j = 0; j < length; ++j) {
		for (int i = 0; i < size; ++i)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	//You want to iterate through all versions of LAST CHARACTER
	int staticable = 0;
	int breakflag = 0;
	int pivot_col = length - 2;
	int pivot_row = 0;

	while (staticable < size)
	{
		//iterate down the rows - repeating the process on each row
		for (int x = 0; x< size; ++x)
		{
			//now just iterate down through the PIVOTS
			for (int i = 0; i < size; ++i)
			{
				//this part prints everything STATIC
				for (int j = 0; j < pivot_col; ++j)
				{
					cout << matrix[staticable][j];
				}
				//now print the PIVOT
				cout << matrix[pivot_row][pivot_col];

				//now print MOVEABLE part
				for (int a = pivot_col + 1; a < length; ++a)
					cout << matrix[i][a];
				cout << endl;
			}
			pivot_row++;
		}

		//reset the pivot row and move left by one unit
		pivot_row = 0;
		pivot_col--;

		if (pivot_col == 0) {
			pivot_col = length - 2;
			staticable++;
			breakflag++;
			if (breakflag == size)
			{
				break;
				break;
			}
		}
	}
}