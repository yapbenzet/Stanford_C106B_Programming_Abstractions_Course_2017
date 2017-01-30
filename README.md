# Stanford_University_C106B_Programming_Abstractions_2017
Course covers such advanced programming topics as recursion, algorithmic analysis, and data abstraction using the C++ programming language

Completed Assignments (C++):

Assignment One (Completed Jan/17/2017):
==========================
Problem 1: Removing all occurrences of characters
Write a function CensorString that takes two strings as input and returns
the first string with all of the characters that are present in the second removed.

Problem 2: Files and Structs
When we grade your exams, we’re going to keep track of some statistics like the min,
max and average scores. Define a struct containing these statistics. Then, write a
function that takes a filename, reads the scores from it (one per line where 0 <= score <=
100), and returns the struct you defined. For efficiency’s sake, your function should
make only a single pass over the file

Problem 3: Vectors
Write a function CountLetters that takes a filename and prints the number of times
each letter of the alphabet appears in that file. Because there are 26 numbers to be
printed, CountLetters needs to create a Vector. 


Assignment Two (Completed Jan/19/2017):
==========================
Problem 1: Vectors (AKA C++ ArrayLists…) 
a) How would you declare a Vector that stores eMailMsgs? 
b) Write a function RemoveSpam that takes a vector containing elements of type eMailMsg and removes all elements whose subject begins with the string "SPAM". 
c) How could you modify the to field of the eMailMsg structure so that it can hold the email addresses of an arbitrary number of recipients of an email? With the modification in place, given an eMailMsg email, how would you access the last address listed in the to field?

Problem 2: Queues 
Write a function void ReverseQueue() that reverses the elements in the passed in queue.  

Problem 3: Using the Stack class
Every html tag must be matched by an equivalent closing tag. Mozilla is looking for programmers to help implement this feature in the next version of Firefox and you, armed with your newly acquired knowledge of classes, decide to volunteer for the job. Write the following function: bool IsCorrectlyNested(string htmlStr);

Problem 4: Map Warm-up 
Write a function: char MostFrequentCharacter(ifstream &if, int &numOccurrences); that given an input file stream, returns the character that occurs the most frequently and stores the number of times it occurs in the reference parameter numOccurrences.  To write this function, first start by scanning through the file stream, analyzing each character and storing an updated count in a map.  Then, after you’ve built this table, iterate over it to find the character that occurred the most often. 

Problem 5: Minesweeper
In the game of Minesweeper, a player searches for hidden bombs on a rectangular grid.  The game board is represented by a grid of booleans marking bomb locations. A grid value is true if there is bomb at that location, false otherwise.  Here is an example grid: (0,0) T F F F F T F F F F F T T T F T F T T F F F F F F F T F F F F F F F F F Given such a grid of bomb locations, the function MakeGridOfCounts constructs a new grid of integers storing the count of bombs in each neighborhood.  The neighborhood for a location includes the location itself and its eight adjacent locations.  In the returned grid, each value will be a number from 0 to 9. If passed the boolean grid above, MakeGridOfCounts returns: (0,0) 1 1 0 0 2 2 3 3 2 1 4 3 3 3 2 1 3 2 3 4 3 2 2 1 1 2 1 1 0 0 0 1 1 1 0 0 The function is passed the grid by reference, and returns an int grid created as described. 


Assignment Three (Completed Jan/28/2017):
==========================
Problem 1: Set Callbacks 1. When using a Set to store user-defined types, it is the client's responsibility to write the appropriate comparison callback and pass that function to the Set constructor. The comparison callback also allows the client to customize how entries are compared (and thus control the order they are returned by the iterator) as well as determining which entries will be coalesced as duplicates. 
a) You're building an address book and plan on using a Set to store the entries. Each entry is represented by this structure: struct entryT {  string firstName;  string lastName;  string phoneNumber; }; 
Write a comparison callback that compares entries using last name as the primary key and first name as the secondary key. Show the necessary declaration for creating a Set of entryT using this callback. Given the above setup, what happens if you have two friends with the same first and last name? 
b) You plan on using a Set to store a collection of strings. You wish to treat "Word" and "word" as the same element The default comparison function for Set works on strings, but it compares case-sensitively.  Write a comparison callback that instead compares strings without regard to case and use it to declare a Set of string which operates caseinsensitively. 

Problem 2: Maps You are writing a program to manipulate a geographic map of major world cities. You have a list of city names and their coordinates. When a user clicks on a point, you want to report what city is there. To efficiently support this operation, you plan to use a Map to associate a pointT with the name of the city at that point. However, Maps require that the keys be of string type. Brainstorm a way to resolve this apparent incompatibility and complete the code started below to load the Map with city data.

Problem 3: Cartesian Products The French mathematician Rene Descartes invented the notion of a “Cartesian product” of sets, defined as follows: Let A and B be sets. The Cartesian product of A and B, is the set of all pairs (a, b) where a is a member of set A and b is a member of set B. The pair (a, b) is called an ordered pair, and will be defined in our solution by the following struct: struct pairT {  string first, second; };
Write a function to compute the cartesian product of two sets of strings sets: Set<pairT> CartesianProduct(Set<string> & one, Set<string> & two); For example, the Cartesian Product of {"A", "B", "C"} and {"X", "Y"} is: {("A", "X"), ("A", "Y"), ("B", "X"), ("B", "Y"), ("C", "X"), ("C", "Y")} You will also need to write an appropriate PairCmpFn that compares two pairTs. 

Problem 4: Cannonballs Suppose that you have somehow been transported back to 1777 and the Revolutionary War. You have been assigned a dangerous reconnaissance mission: evaluate the amount of ammunition available to the British for use with their large cannon which has been shelling the Revolutionary forces. Fortunately for you, the British—being neat and orderly—have stacked the cannonballs into a single pyramid-shaped stack with one cannonball at the top, sitting on top of a square composed of four cannonballs, sitting on top of a square composed of nine cannonballs, and so forth. Unfortunately, however, the Redcoats are also vigilant, and you only have time to count the number of layers in the pyramid before you are able to escape back to your own troops. To make matters worse, computers will not be invented for at least 150 years, but you should not let that detail get in your way. Your mission is to write a recursive function Cannonball that takes as its argument the height of the pyramid and returns the number of cannonballs therein. int Cannonball(int height);

Problem 5: ReverseString Given a string, create a function ReverseString that returns the string in reverse order. Consider both recursive and iterative techniques for solving this problem. Which one is easier to come up with? string ReverseString(string str); 

Problem 6: GCD The greatest common divisor (g.c.d.) of two nonnegative integers is the largest integer that divides evenly into both. In the third century B.C., the Greek mathematician Euclid discovered that the greatest common divisor of x and y can always be computed as follows: If x is evenly divisible by y, then y is the greatest common divisor. Otherwise, the greatest common divisor of x and y is always equal to the greatest common divisor of y and the remainder of x divided by y. Use Euclid's insight to write a recursive function int GCD(int x, int y) that computes the greatest common divisor of x and y.

Problem 8: Imagine that you have just been hired by a local telephone company to write a function ListMnemonics that will generate all possible letter combinations that correspond to a given number, represented as a string of digits. For example, if you call ListMnemonics("723") your program should generate the following 27 possible letter combinations that correspond to that prefix: PAD PBD PCD RAD RBD RCD SAD SBD SCD PAE PBE PCE RAE RBE RCE SAE SBE SCE PAF PBF PCF RAF RBF RCF SAF SBF SCF


Assignment Four (Iterative and Recursive versions completed Jan/29/2017):
==========================
Problem 4: Linked List Warmup
Write the following linked list functions. Provide both iterative and a recursive
forumlations. Cell is defined as follows: struct Cell { Cell *next; int value; };
a) Write a function ConvertToList which takes in a Vector of ints and converts it into a
linked list. Assume the Vector has at least one element in it.
b) Write a function which sums the values of a linked list.
int SumList(Cell *list)

Problem 6: Append.  Write a function that given two lists will append the second list onto the first. For example, given the first list (1 4 6) and the second list (3 19 2), the function would destructively modify the first list to contain (1 4 6 3 19 2). It is easiest to write this function recursively. Be sure to handle the case when one or both lists are empty.
