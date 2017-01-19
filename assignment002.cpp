#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct eMailMsg{
    vector<string> to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};


void RemoveSpam (vector<eMailMsg> &v)
{
    vector<eMailMsg> ::iterator itV;
    for( itV = v.begin(); itV != v.end();++itV)
    {
        string checkString = (*itV).message;
        if (checkString.substr(0,4) == "SPAM")
         v.erase(itV);
    }
}

string printLastAddress ( eMailMsg &e)
{
    string temp = ""+(e.to)[(e.to).size() - 1];
    return temp;
}

void ReverseQueue(queue<int> &q)
{
    vector<int> v;
    while (q.size() != 0)
    {
        v.push_back(q.front());
        q.pop();
    }
  sort(v.begin(), v.end());
  for(unsigned i =0; i < v.size(); ++i)
  {
      q.push(v[i]);
  }
}

bool IsCorrectlyNested(string htmlStr){
	char ch;
	string token ="";
	bool tokenFlag = false;
	bool endFlag = false;
	stack<string> frontstack;
	stack<string> endstack;
	stringstream ss;
	ss.str(htmlStr);

	while (ss >> ch)
	{
		if (ch == '<')
		{
			tokenFlag = true;
		}

		if (ch == '>')
		{
			if (endFlag) {
				endstack.push(token);
			}
			else {
				frontstack.push(token);
			}

			token = "";
			tokenFlag = false;
			endFlag = false;
		}

		if (tokenFlag)
		{
			if (ch == '/') { endFlag = true; }
			if (isalpha(ch))
				token += ch;
		}
	}

		if (frontstack.size() != endstack.size())
			return false;

		while (frontstack.size() > 0)
		{
			string frontcheck = frontstack.top();
			string endcheck = endstack.top();

			if (frontcheck != endcheck)
				return false;

			frontstack.pop();
			endstack.pop();
		}
		return true;
}


char MostFrequentCharacter(ifstream &infile, int &maxsize) {
	map<char, int> m;
	char ch;
	char maxchar;

	//initialize maxsize to zero
	maxsize = 0;

	while (infile >> ch)
	{
		if (m.find(ch) != m.end())
		{
			++m.at(ch);
			//check for a new maximum
			if (m.at(ch) > maxsize)
			{
				maxsize = m.at(ch);
				maxchar = ch;
			}
		}
		else
		{
			m.insert_or_assign(ch, 1);
		}
	}
	return maxchar;
}



int main(){

//Problem 1: "Vectors"--------------------------------------------------
vector<eMailMsg> v;
eMailMsg e;
(e.to).push_back("Sylvia Branch");
(e.to).push_back("Tiana Branch");
(e.to).push_back("Carlton Branch");
(e.to).push_back("Alan Branch");
//print last address in TO field
//should print 'Alan Branch'
cout << printLastAddress(e)<< endl;
    

//Problem 2: "Queues" --------------------------------------------------
queue<int> q;
q.push(55);
q.push(32);
q.push(21);
q.push(666);
q.push(77);
q.push(34);
q.push(86);
 ReverseQueue(q);
//front should be 21
cout << q.front() << endl;
//size should be 7
cout << q.size() << endl;


//Problem 3: "Using the Stack Class" --------------------------------------------------
string goodinput = "<html><head><title></title></head><body><h1></h1><p></p><p><b>This is a well-formed html page</b></p></body></html>";
string badinput = "<html><head><title></title></head><body><h1></h1><p><p><b>This is a well-formed html page</b></p></body></html>";
//Test the algorithm 
cout <<"Test of well-formed input: "<< boolalpha <<  IsCorrectlyNested(goodinput) << endl;
cout << "Test of incorrectly-formed input: " << boolalpha << IsCorrectlyNested(badinput) << endl;


//Problem 4: "Map Warmup" --------------------------------------------------
string filename = "C:\\Users\\ACER\\Desktop\\inputData.txt";
ifstream infile(filename);
if (!infile) cerr << "File could not be opened" << endl;
int numOccur = 0;
char result = MostFrequentCharacter(infile, numOccur);
cout << "The character that occurred the most in the provided file is: " << result << endl;
cout << "It occurs " << numOccur << " times."<< endl;

return 0;
}