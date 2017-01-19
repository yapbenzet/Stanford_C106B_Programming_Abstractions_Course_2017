# Stanford_University_C106B_Programming_Abstractions_Course
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
