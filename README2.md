# Stanford_University_C106B_Programming_Abstractions_2017
Course covers such advanced programming topics as recursion, algorithmic analysis, and data abstraction using the C++ programming language

Completed Assignments (C++):

Recursion Assignment One (Completed Feb/02/2017):
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


Assignment One (Completed Feb/02/2017):
==========================
