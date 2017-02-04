#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Warmup Problem: A --------------------------------------
void printInBinary(int num) {
	if (num == 0)
		return;
	printInBinary(num / 2);
	cout << num % 2 << " ";
}


//Warmup Problem: B --------------------------------------
int index = 0;
bool canMakeSum(vector<int> & v, int targetSum)
{
	if ( index == v.size() )
		return false;

	int sum = v[index];

	for (int i = 0; i < v.size(); ++i)
	{
		if (i == index)
			continue;

		if (sum == targetSum)
			return true;

		sum += v[i];
	}
	index++;
	canMakeSum(v, targetSum);	
}

//Problem ONE --------------------------------------
int CountWays(int numStairs) {
	int result = 0;

	if (numStairs == 0)
	{
		return 1;
	}

	if (numStairs <  0)
	{
		return 0;
	}

	result += CountWays(numStairs - 1);
	result += CountWays(numStairs - 2);

	return result;
}


//Problem TWO --------------------------------------
void DrawTick(double x, double y, double w, double h)
{
	cout << h << endl;
}
void DrawRuler(double x, double y, double w, double h) {
	//base case stops the process when it gets too small
	if (h <= 0.2)
		return;
	
	//draw the left tick
	DrawRuler(x, y, (x + (w / 2)), h / 2);

	//take the parameters and draw a central tick
	DrawTick(x + (w / 2), y, x + (w / 2), (h / 2));

	//draw the right tick
	DrawRuler(x + (w / 2), y, w / 2, h / 2);
}


//Problem THREE --------------------------------------
void testString(string n, string params) {
	if (params.empty()) 
	{
		cout << n << endl;
	}	
	for (unsigned i = 0; i < params.length(); ++i)
	{
		testString(n + params[i], params.substr(0, i) + params.substr(i + 1));	
	}
}
	

int main() {
	//Warmup Problem: A --------------------------------------
	int target;
	cout << "Please enter a positive integer value: ";
	cin >> target;
	cout << "The binary version of " << target << " is: "; 
	printInBinary(target);
	cout << endl;

	//Warmup Problem: B --------------------------------------
	int targetInt = 0;
	vector<int> v = { 3 , 7 , 1 , 8 , -3 };
	cout << "Please enter a target number: ";
	cin >> targetInt;
	cout << "For the set: ";
	for (int a : v)
		cout << a << " ";
	cout << endl;
	cout << "The search for " << targetInt << " returned: " << boolalpha << canMakeSum( v , targetInt ) << endl;  


	//Problem ONE --------------------------------------
	cout << "The number of possible combos for 4 is: " << CountWays(4) << endl;
	cout << endl;

	//Problem TWO --------------------------------------
	int x = 0;
	int y = 0;
	int w = 10;
	int h = 6;
	DrawRuler(x, y, w, h);
	cout << endl;

	//Problem THREE --------------------------------------
	string inputStr = "";
	cout << "Please enter a string: ";
	cin >> inputStr;
	cout << "All possible combinations: " << endl;
	testString("", inputStr);
	cout << endl;

	return 0;
}