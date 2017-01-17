#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

// Problem 1---------------------------------------------------------
//this version returns a new string
string CensorString1(string first, string second)
{
	set<char> s;
	for (unsigned i = 0; i < second.length(); ++i)
	{
		s.insert(second[i]);
	}

	string result = "";

	for (unsigned i = 0 ; i < first.length() ; ++i )
	{
		if ( s.find( first[i]) == s.end() )
			result += first[i];
	}

	return result;
}

//this version modifies the original
void CensorString2(string &first, string second)
{
	set<char> s;
	for (unsigned i = 0; i < second.length(); ++i)
	{
		s.insert(second[i]);
	}

	string result = "";
	string::iterator itS;
	itS = first.begin();

	for (unsigned i = 0; i < first.length(); ++i)
	{
		if ( s.find( first[i]) != s.end() )
			first.erase( first.begin() + i );
	}
}


// Problem 2---------------------------------------------------------
typedef struct {
	int min = 100;
	int max = -100;
	double average = 0;
} StatCounter;

StatCounter readFileDataReturnStruct(string filename, StatCounter *s) {
	//create and open file stream object
	ifstream infile(filename);

	string line;
	int counter = 0;
	int total_score = 0;

	while (getline(infile, line))
	{
		int score = stoi(line);
		total_score += score;
		++counter;
		
		if (score < s->min)
			s->min = score;

		if (score > s->max)
			s->max = score;

	}
	s->average = total_score / double(counter);
	infile.close();
	return *s;
}


// Problem 3---------------------------------------------------------
void countLetters(string filename) {

	ifstream infile;
	infile.open(filename);

	if (!infile)
		cerr << "File could not be opened" << endl;

	char ch;
	map <char, int> m;
	while (infile >> ch)
	{
		if ( isalpha(ch) )
		{
			//all data is stored as lower case
			ch = tolower(ch);
			
			if (m.find(ch) == m.end())
			{
				m.insert_or_assign(ch, 1);
			}
			else
				m.at(ch)++;
		}
	}

	vector<char> v = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	for (unsigned i = 0; i < v.size(); ++i)
	{
		if (m.find(v[i]) != m.end())
			cout << v[i] << ": " << m.at(v[i]) << endl;
		else
			cout << v[i] << ": 0" << endl;
	}
	infile.close();
}

int main() {
	
	// Problem 1---------------------------------------------------------
	string result = CensorString1("Stanford", "Sao");
	cout <<  "Problem 1---------------------------------------------------------"<< endl;
	cout << "The starting string is Stanford "<< endl;
	cout << "S, a, o have been removed..." << endl; 
	cout << "Version 1 result: " << result << endl;
	string test2 = "Stanford";
	CensorString2(test2, "Sao");
	cout << "Version 2 result: " << test2 << endl;


	// Problem 2---------------------------------------------------------
	ofstream outfile;
	string fileName = "C:\\Users\\ACER\\Desktop\\fileData.txt";
	outfile.open(fileName);

	//test for success
	if (!outfile)
		cerr << "This file could not be opened" << endl;

	for (int i = 0; i < 100; ++i)
	{
		int temp = 0;
		temp = rand() % 50 + 50;
		outfile << temp << endl;
	}

	outfile.close();
	StatCounter s;
	readFileDataReturnStruct(fileName, &s);
	cout << "\nProblem 2---------------------------------------------------------" << endl;
	cout << "The maximum score is: " << s.max << endl;
	cout << "The minimum score is: " << s.min << endl;
	cout << "The average score is: " << s.average << endl;


	// Problem 3---------------------------------------------------------
	string fileName2 = "C:\\Users\\ACER\\Desktop\\fileData2.txt";
	cout << "\nProblem 3---------------------------------------------------------" << endl;
	countLetters( fileName2 );

	return 0;
}
