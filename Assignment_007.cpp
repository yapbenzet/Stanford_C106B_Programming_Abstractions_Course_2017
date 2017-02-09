#include <iostream>
#include <vector>
using namespace std;

//Problem 1 --------------------------------------------------------
template <typename T>
class Stack {
private:
	vector<T> elems;
public:
	Stack() {}
	~Stack() {}
	void push(T elem) { 
		if (elems.size() == 0)
			elems.push_back(elem);
		else
			elems.insert(elems.begin()+elems.size(), elem); 
	}
	T pop() {
		T temp = elems[elems.size() - 1];
		elems.erase(elems.begin()+ elems.size() - 1);
		return temp;
	}
	size_t size() { return elems.size(); }
	bool isEmpty() { return elems.size() == 0; }
	void reverse() {
		for (unsigned i = 0; i < elems.size() / 2; ++i)
		{
			T temp;
			temp = elems[i];
			elems[i] = elems[elems.size() - 1 - i];
			elems[elems.size() - 1 - i] = temp;
		}
	}

	void print() {
		int i = elems.size() - 1;
		while (i >= 0) {
			cout << elems[i] << " ";
			i--;
		}
		cout << endl;
	}
};

template <typename Type>
void ReverseStack(Stack<Type> & s) {
	Stack<Type> newStack;
	Stack<Type> container;
	vector<Type> ::iterator itV;
	
	while (s.size() != 0)
	{
		Type temp = s.pop();
		container.push(temp);
	}
	s = container;
}

//Linked List 
struct Node
{
	int value;
	Node * next;
};

//Problem 5 --------------------------------------------------------
void Stutter(Node * front) {
	Node * runner = front;
	while (runner != nullptr)
	{
		Node * duplicateNode = new Node();
		duplicateNode->value = runner->value;
		duplicateNode->next = runner->next;
		runner->next = duplicateNode;
		runner = duplicateNode->next;
	}
}


//Problem 6 --------------------------------------------------------
void Unstutter(Node * start) {
	Node * front = start;
	Node * runner = front->next;

	while (true)
	{
		if (front -> value == runner->value)
		{
			if (runner -> next == nullptr)
			{
				front -> next = nullptr;
				break;
			}
			else
			{
				front -> next = runner->next;
				runner = front -> next;
			}
		}

		front = runner;
		
		if (runner -> next == nullptr)
			break;
		else 
			runner = runner->next;
	}
}

void PrintList(Node * start)
{
	Node * runner = start;
	if (runner == nullptr)
		return;
	else
	{
		cout << runner->value << " ";
		PrintList(runner->next);
	}
}


int main() {
	//Problem 1 "Client-side vs. Implementation-side "------------------

	Stack<int> s;
	s.push(1); s.push(2); s.push(3); s.push(4);
	cout << "Original stack contents: ";
	s.print(); //should print 4 3 2 1
	s.reverse();
	cout << "Reversed stack contents: ";
	s.print();  //should print 1 2 3 4
	ReverseStack(s);
	cout << "Reversed-reversed stack contents: ";
	s.print();  //should print 4 3 2 1

	//Problem 5 "Stutter" ------------------
	Node * A = new Node();
	Node * B = new Node();
	Node * C = new Node();
	Node * D = new Node();
	Node * E = new Node();
	A->value = 666;
	B->value = 777;
	C->value = 888;
	D->value = 999;
	E->value = 101010;
	A->next = B;
	B->next = C;
	C->next = D;
	D->next = E;
	E->next = nullptr;

	cout << "Original Linked List: ";
	PrintList(A);
	cout << endl;

	cout << "Stuttered Linked List: ";
	Stutter(A);
	PrintList(A);
	cout << endl;

	//Problem 6 "Remove Duplicates" ------------------
	cout << "UN-Stuttered Linked List: ";
	Unstutter(A);
	PrintList(A);
	cout << endl;
  
	return 0;
}
