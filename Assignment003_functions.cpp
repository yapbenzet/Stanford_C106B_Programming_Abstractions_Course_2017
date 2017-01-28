#include "Assignment03_functions.hpp"

int main() {
	//Problem ONE------------------------------------------------
	set<entryT> s;

	entryT a;
	a.firstName = "ZZZlvin";
	a.lastName = "hobbes";
	a.phoneNo = "";

	entryT b;
	b.firstName = "AAAark";
	b.lastName = "hobbes";
	b.phoneNo = "";

	entryT c;
	c.firstName = "AAAark";
	c.lastName = "hobbes";
	c.phoneNo = "";

	entryT d;
	d.firstName = "RRRRAAAark";
	d.lastName = "hobbes";
	d.phoneNo = "";

	s.insert(b);
	s.insert(a);
	s.insert(c);
	s.insert(d);

	set<entryT>::iterator itS;
	for (itS = s.begin(); itS != s.end(); ++itS)
		//comparison is handled internally by the struct/class by overloading Less-Than operator <
		cout << (*itS).firstName << endl;
	
	set<string, lex_compare> s2;  // functor as Comparator
	//if set evaluation is now case-insensitive (default is case-sensitive) 
	//Therefore all three entries should be considered duplicates and condensed to the first entry
	s2.insert("word");
	s2.insert("WORD");
	s2.insert("WoRd");

	set<string>::iterator itS2;
	for (itS2 = s2.begin(); itS2 != s2.end(); ++itS2)
		//comparison is handled by the functor parameter
		cout << (*itS2) << endl;


	//Problem TWO------------------------------------------------
	map< string, cityT > cityMap;
	map< string, cityT > ::iterator itM;

	int xvalue, yvalue;
	vector<cityT> v;
	
	cityT city1;
	city1.name = "Toronto"; 
	city1.coords.x = 5;
	city1.coords.y = 5;

	cityT city2;
	city2.name = "Vancouver";
	city2.coords.x = 9995;
	city2.coords.y = 9995;

	cityT city3;
	city3.name = "Montreal";
	city3.coords.x = 15;
	city3.coords.y = 15;

	v.push_back(city1);
	v.push_back(city2);
	v.push_back(city3); 

	for (unsigned i = 0; i < v.size(); ++i)
	{
		//concatenate the x and y value to make a unique key to index the cityMap
		string temp = v[i].coords.x + "and" + v[i].coords.y;
		cityMap.insert_or_assign(temp, v[i]);
	}
	
	cout << "Please enter an x value: ";
	cin >> xvalue;
	cout << "Please enter an y value: ";
	cin >> yvalue;

	//when searching for user entered data, create search key using the entered values to match the cityMap keys
	string targetString = xvalue + "and" + yvalue;

	itM  = cityMap.find(targetString);

	if (itM == cityMap.end())
		cout << "Search not found" << endl;
	else
		cout << "Your selected city is " << itM->second.name<< endl;
	

	//Problem THREE------------------------------------------------
	set<string> one;
	one.insert("A");
	one.insert("B");
	one.insert("C");
	set<string> two;
	two.insert("X");
	two.insert("Y");
	set<pairT,functor> sPair = CartesianProduct(one, two);
	set<pairT, functor> ::iterator itSp;
	cout << "The Cartesian product of {X, Y} and {A,B,C} is: " << endl;
	for (itSp = sPair.begin(); itSp != sPair.end(); ++itSp)
	{
		cout << " (" << (*itSp).first << ", "<< (*itSp).second << ") "<< endl;
	}


	//Problem FOUR------------------------------------------------
	int height = 0;
	cout << "Please enter the height of the pyramid: ";
	cin >> height;
	cout << "The number of cannonballs is: " << CannonballZ(height)<< endl;
	

	//Problem FIVE------------------------------------------------
	string inputStr = "hello";
	cout << reverseStringRecursively(inputStr) << endl;
	cout << reverseStringNonRecursively(inputStr) << endl;


	//Problem SIX--------------------------------------------------
	int xvalue1, yvalue1;
	cout << "Please enter two numbers: ";
	cin >> xvalue1;
	cin >> yvalue1;
	GCD(xvalue1, yvalue1);

	
	//Problem EIGHT--------------------------------------------------
	string inputStr;
	cout << "Please input the desired 3 digit code: ";
	cin >> inputStr;
	ListMemonics(inputStr);

	return 0;
}