#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//Problem Two---------------------------------------------------------
class Rectangle {

private:

	double length;
	double width;

public:

	//Default constructor
	Rectangle() :length(0), width(0) {}
	//Copy constructor
	Rectangle(const Rectangle & other) : length(other.length), width(other.width) {}
	

	//Move constructor
	Rectangle (Rectangle&& other)
	{
	length = move(other.length);
	width = move(other.width);
	}

	//Copy assignment
	Rectangle& operator= (const Rectangle& other)
	{
	if (this != &other)
	{
	this->length = other.length;
	this->width = other.width;
	}
	return *this;
	}
	//Move assignment
	Rectangle& operator= (Rectangle && other)
	{
	if (this != &other)
	{
	this->length = move(other.length);
	this->width = move(other.width);
	}
	return *this;
	}
	
	//Getters
	double getArea() { return length * width; }
	double getPerimeter() { return 2 * length + 2 * width; }
	//Setters
	void setScale(double factor) { length = factor*length; width = factor*width; }

};


//Problem Three---------------------------------------------------------
template <typename Type>
int compFunct(const Type& a, const Type& b)
{
	if (a < b) return -1;
	else if (a > b) return 1;
	else
		return 0;
}


template <typename T>
T FindMax(vector<T> &v, int(*name)(const T& a, const T&b))
{
	T max = v[0];
	for (unsigned i = 0; i < v.size() - 1; ++i)
	{
		if (name(max, v[i + 1]) < 0)
			max = v[i + 1];
	}
	return max;
}

struct Car {
	string name;
	int weight;
	int numAirbags;
	Car(string n, int w, int bags) : name(n), weight(w), numAirbags(bags) {}
};

//overload the ostream operator to print the name of the Car
ostream& operator << (ostream & os, const Car& c)
{
	os << c.name;
	return os;
}

int carCompare(const Car& a, const Car& b)
{
	if (a.numAirbags < b.numAirbags) return -1;
	else if (a.numAirbags > b.numAirbags) return 1;
	else
		return 0;
}


//Problem Four-----------------------------------------------------------
template <typename T>
void Filter(queue<T> & q, bool(*func)(const T & other)) {
	vector<T> container;

	while (!q.empty())
	{
		container.push_back(q.front());
		q.pop();
	}

	for (unsigned i = 0; i < container.size(); ++i)
	{
		if (func(container[i]))
			continue;
		q.push(container[i]);
	}
}

struct recordingT {
	string title;
	string genre;
	int rating;
	recordingT(string t, string g, int r) : title(t), genre(g), rating(r) {}
};

ostream& operator << (ostream& os, recordingT & a) {
	os << a.title;
	return os;
}

bool isBadAnimation(const recordingT & show)
{
	return (show.genre == "animation" && show.rating < 8);
}


//Problem Five-A--------------------------------------------------------
template <typename T>
int compareThese(T& a, T& b) {
	if (a > b) return 1;
	if (a < b) return -1;
	else {
		return 0;
	}
}
template <typename Type>
void RemoveDuplicates(vector<Type> & v, int(*funct)(Type& a, Type& b))
{
	bool uniqueValueFlag = true;
	vector<Type> container;
	
	for ( unsigned i = 0 ; i < v.size() ; ++i )
	{
		uniqueValueFlag = true;
		for (unsigned j = 0; j < container.size(); ++j)
		{
			if (funct( v[i], container[j]) == 0)
			{
				uniqueValueFlag = false;
				break;
			}
		}
		if (uniqueValueFlag) { container.push_back(v[i]); }
	}
	//use simply copy assignment to update the original vector
	v = container;
}

//Problem Five-B----------------------




int main() {

	//Problem Three-----------------------------------------------------------
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(666);
	v.push_back(4);
	//declare a function pointer for integer type
	int(*foo)(const int& a, const int& b);
	//assign function pointer to the templated function
	foo = compFunct<int>;
	cout << FindMax(v, foo) << endl; //should return 666
	vector<Car> v2;
	v2.push_back(Car("Volvo", 1000, 2));
	v2.push_back(Car("Honda", 10000, 4));
	v2.push_back(Car("Mercedes", 1200, 5));
	v2.push_back(Car("Hyundai", 1100, 3));
	//declare a function pointer for Car type
	int(*bar)(const Car& a, const Car& b);
	//assign Car-type function point to the templated function
	bar = carCompare;
	FindMax(v2, bar);
	cout << "The car with the maximum number of airbags is: " << FindMax(v2, bar) << endl;


	//Problem Four-----------------------------------------------------------
	//create pointer to match signature of isBadAnimation function
	bool(*soo)(const recordingT &);
	//assign function pointer to isBadAnimation
	soo = isBadAnimation;
	//declare a new queue of recordingT objects
	queue<recordingT> myList;
	myList.push(recordingT("Alladin", "animation", 9));
	myList.push(recordingT("Hercules", "animation", 8));
	myList.push(recordingT("Lion King", "animation", 10));
	myList.push(recordingT("Lilo And Stitch", "animation", 8));
	myList.push(recordingT("Princess & the Frog", "animation", 2));
	//filter the list to remove all shows with a genre of Animation and a rating less than 8
	Filter(myList, soo);
	//print out the list
	while (!myList.empty())
	{
		cout << myList.front();
		if (myList.size() != 1)
			cout << ", ";
		myList.pop();
	}
	cout << endl;  //"Princess and the Frog" should be removed from the list


//Problem Five-----------------------------------------------------------
	//declare a function pointer
	int(*jar)(int& a, int& b);
	//assign it to the compareThese function
	jar = compareThese;
	//declare and initialize test vector
	vector<int> v5 = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5,5, 6, 6, 7, 7, 8, 8, 8, 9, 9, 9, 10 };
	//print raw vector
	for (int a : v5) { cout << a << " "; } cout << endl;


	RemoveDuplicates(v5, jar);
	
	//print processed vector
	for (int a : v5) { cout << a << " "; } cout << endl;


	return 0;
}
