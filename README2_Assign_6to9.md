# Stanford_University_C106B_Programming_Abstractions_2017
Course covers such advanced programming topics as recursion, algorithmic analysis, and data abstraction using the C++ programming language

Completed Assignments (C++):

Recursion Assignment Four (Completed Feb/02/2017):
==========================

Warmup A: Binary is a base-2 number system instead of the decimal (base-10) system we are familiar with. 
Write a recursive function PrintInBinary(int num) that prints the binary representation for a given integer. 
For example, calling PrintInBinary(5) would print 101. Your function may assume the integer parameter is non-negative.

Warmup B: The subset sum problem is an important and classic problem in computer theory. Given a set of integers and a target number, 
your goal is to find a subset of those numbers that sum to that target number. For example, given the numbers {3, 7, 1, 8, -3} 
and the target sum 4, the subset {3, 1} sums to 4. On the other hand, if the target sum were 2, the result is false since there is
no subset that sums to 2. The prototype for this function is bool CanMakeSum(Vector<int> & nums, int targetSum)

Problem 1: The 12-step program to recursive enlightenment You're standing at the base of a staircase and are heading to the top. A small stride will move up one stair, a large stride advances two. You want to count the number of ways to climb the entire staircase based on different combinations of large and small strides. For example, a staircase of three steps can be climbed in three different ways: via three small strides or one small stride followed by one large stride or one large followed by one small. A staircase of four steps can be climbed in five different ways (enumerating them is an exercise left to reader :-).
Write the recursive function int CountWays(int numStairs) that takes a positive numStairs value and returns the number of different ways to climb a staircase of that height taking strides of one or two stairs at a time.
Here's a hint about the recursive structure of the problem: consider the options you have at each stair. You must either take a small stride or a large stride; either will take you closer to the goal and therefore represents a simpler instance of the same problem that can be handled recursively. What is the simplest possible situation and how is it handled?
int CountWays(int numStairs)

Problem 2: Ruler of the world In countries like the United States that still use the traditional English system of measurement, each inch on a ruler is marked off into fractions using tick marks that look like this:
The tallest tick mark falls at the center dividing into halves, two shorter tick marks indicate the quarter divisions, and even shorter ones are used to mark the eighths and sixteenths and so on. Write the recursive function DrawRuler(double x, double y, double w, double h). The function is given the coordinates for a rectangle in which to draw the ruler. The function draws a line along the rectangle's bottom edge and a sequence of vertical tick marks. The middlemost tick mark is centered and is as tall as the rectangle height. Each smaller tick mark is half the height of the next larger one. Once the tick marks become sufficiently small, the recursion terminates.
The recursive insight to this problem is to recognize that the middlemost tick mark subdivides the rectangle into two smaller rectangles, each of which is a smaller ruler of its own.
void DrawRuler(double x, double y, double w, double h)


Assignment Six (Completed Feb/07/2017):
==========================
Problem 2: A simple class
Design an interface for the Rectangle class. We will be keeping track of its size as well
as its location, and should allow the user to find the rectangle’s perimeter and area. You
should also provide a way for the user to scale the rectangle by some amount and
translate it in space

Problem 3: Function Pointers and Templates
a) Write a generic function FindMax that searches a vector to find the largest element and
returns it. The two arguments to the function are the vector and a comparison function.
The comparison function should take two elements and return an integer that is negative
if the first is less than the second, zero if the two are equal, and positive otherwise. The
second parameter should be optional, if not given, the default comparison of built-in
relational operators is used. Your function may assume that the vector has at least one
element. FindMax should be written as a template and must work for vectors of any type.

b) Add the necessary code below to print the name of the safest car from the vector. The
safest car is the one with the most airbags; among cars with the same number of airbags,
the heavier car is safer. You should use the FindMax function from part a.
struct Car { string name; int weight; int numAirbags;};

Problem 4: Templatized Functions
Write a function Filter that removes all elements from a Queue that fits a user-supplied
criteria. The function will take two parameters:
• A Queue, passed by reference, of the elements you want to filter.
• A function pointer to a bool function with one parameter; the type of the
parameter is the same as the one stored in the Queue. The bool function returns
true if the parameter fits a certain criteria. This type of function (one that returns a
boolean) is sometimes called a predicate function.
For example, let's say that I'm cleaning out all of the recording in my DVR. The
information regarding the individual recordings is kept in the following struct:
struct recordingT { string title; string genre; int rating;};
If I want to remove all animated recordings with a rating of less than 8, I would pass a
pointer to the following function:
bool IsBadAnimation(recordingT show) { return (show.genre == "animation" && show.rating < 8); }
If an element contained in the Queue causes the user-supplied function to return true, it
should be removed from the Queue. In addition, function Filter should support Queues
of any type.

Problem 5: More Templatized Functions
a) Write a templatized function RemoveDuplicates that finds all duplicate elements in a
Vector and removes each appearance of the element beyond the first. For example, if it
was passed the Vector [1, 2, 3, 4, 2, 3, 3] it would modify the Vector to be [1, 2, 3, 4]. It
is passed the Vector by reference as well as a comparison function which two elements
and returns an integer that is less than, equal to, or greater than zero depending on
whether the first element is less than, equal to, or greater than the second element,
respectively.

b) Suppose you have a Vector of ints, and you want only one occurrence of a number
with a particular absolute value. That is, you only want one of 2 and -2 to be in the vector


Assignment Seven (Completed Feb/08/2017):
==========================
Problem 1: Client-side vs. Implementation-side Consider a basic Stack class built on top of a Vector: template <typename Type> class Stack { public: Stack(); ~Stack(); void push(Type elem); Type pop(); bool isEmpty(); private: Vector<Type> elems; } 
a) Say we as the implementers want to add a method that will reverse the elements that are currently in the Stack.  How can we do it? 
b) Now write another Reverse function, this time as a client of the stack class

Problem 4: Deques A deque (pronounced “deck”) is a double-ended queue where items can be inserted and removed from both ends of the deque. This structure can be used to simulate both a stack and a queue, and is useful for array operations where we only want to insert at the beginning or end of a list of items.  How would we implement a deque efficiently with linked lists?  Would it be preferable to use a singly-linked or doubly-linked list?  What functions would it need to implement?  How could it be used to simulate a stack or a queue? Note that you should not write any code for this problem. Instead, answer the questions above and sketch out the general form of the implementation, but do not implement it.
The lists in problems 5 and 6 use the structure definition: struct Node { int value; Node* next;
}; These linked list problems will hopefully get you thinking about how to manipulate this data structure; you will need these skills for your current assignment. 

Problem 5: Stutter Write a function Stutter that given a linked list will duplicate every cell in the list. If the incoming list contains the elements (11 5 21 7 7), the function will destructively modify the list to contain (11 11 5 5 21 21 7 7 7 7). 

Problem 6: RemoveDuplicates (a.k.a. Unstutter) Write a function RemoveDuplicates that given a linked list will remove any neighboring duplicates found in the list. If the incoming list is (5 5 22 37 89 89 15 15 22) the function will destructively modify the list to contain (5 22 37 89 15 22). Don't worry about handling duplicate sequences longer than 2 or duplicates that aren't right next to each other in the list.

