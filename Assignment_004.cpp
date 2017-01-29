#include <iostream>
#include <vector>
using namespace std;

struct Cell {
	Cell * next;
	int value;
	Cell(int v) : value(v), next(nullptr) {}
};

class Listo {
	size_t size;
public:
	
	Listo() {
		size = 0;
		top = nullptr;
	}

	~Listo() {
		while (top != nullptr) 
		{
			Cell * toDelete = top;
			top = top->next;
			delete toDelete;
		}
	}
	Cell * top;

	//@brief Add a new value to the end of the linked list
	void Add(int value) {
		Cell * newCell = new Cell(value);
		if (top == nullptr)
		{
			newCell->next = top;
			top = newCell;
		}
		else
		{
			Cell * runner;
			//iterate to the end of the linked list
			for (runner = top; runner->next != nullptr; runner = runner->next) {}
			runner->next = newCell;
		}
		++size;
	}

	int peek(){ return top->value; }
	size_t count() { return size; }
	
	//@brief print the contents of the linked list
	void print() {
		cout << "List contents (" << count() << "): ";
		Cell * runner = top;
		while (runner != nullptr)
		{
			cout << runner->value << " ";
			runner = runner->next;
		}
		cout << endl;
	}

	//@brief Append the contents of one linked list to the end of another
	void append(Listo * other)
	{
		Cell * runner;
		//iterate to the end of the linked list
		for (runner = top; runner->next != nullptr; runner = runner->next) {}		
		
		runner->next = other->top;
		
		while (runner->next != nullptr) 
		{
			runner = runner->next;
			++size;
		}
	}
};

//@brief Take a vector of int and return a linked list
Listo * ConvertToList(const vector<int>& v) {
	Listo * ll = new Listo();

	for (int i : v)
	{
		ll->Add(i);
	}

	return ll;
}

//@brief Calculate the sum of all values in the linked list
int SumList(const Listo& l)
{
	int sum = 0;
	Cell * runner = l.top;
	while (runner != nullptr)
	{
		sum += runner->value;
		runner = runner->next;
	}
	return sum;
}



int main() {
	int temp;
	Listo * l = new Listo();
	cout << "Please enter 10 values that you wish to add to the list"<< endl;
	cout << "================================================================" << endl;
	
	//read in all the values into a vector of ints
	vector<int>v;
	for (int i = 0; i < 2; ++i)
	{
		cout << "(" << i + 1 << "): ";
		cin >> temp;
		v.push_back(temp);
	}

	//covert that vector into a linked list
	l = ConvertToList(v);
	
	//print to verify the contents of the new linked list
	l->print();

	//sum the values of the linked list
	cout << "The sum of all values in the list is: " << SumList(*l) << endl;

	//append a list onto another
	vector<int> v1 = { 1, 4, 6 };
	vector<int> v2 = { 3, 19, 2 };
	Listo * list1 = ConvertToList(v1);
	Listo * list2 = ConvertToList(v2);

	list1->append(list2);
	//print to verify the contents of linked list - 1
	list1->print();

	return 0;
}
