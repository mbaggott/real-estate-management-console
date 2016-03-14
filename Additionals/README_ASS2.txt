/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 1 2015 Assignment #2 - "YourSoftware - RMIT" Property System
* Full Name        : Michael Baggott
* Student Number   : 3439668
* Course Code      : CPT 323
* Start up code provided by Robert T.McQuillan
****************************************************************************/

-----------------------------------------------------------------------------
If selected, do you grant permission for your assignment to be released as an
anonymous student sample solution?
-----------------------------------------------------------------------------

Yes

-----------------------------------------------------------------------------




Known bugs:
-----------



Incomplete functionality:
-------------------------



Assumptions:
------------

Features Successfully Implemented (eg All 3 STL Containers,exception handling, function objects 
data validation, pure virtual functions, overloading of << and >> for particular objects)

Assumption: the marker will input only unique employedd ID's. Confiremd bu Robbie on the DB. Unique employee ID is NOT tested for in
the program, and the program will not function properly if duplicate employee id's are used.

All

Class Diagram inlcuded
Command line arguments implemented - arguments must be: commercial.dat residential.dat staff.dat (in correct order)
File input/output
3 STL Containers
Main menu implemented
Makefile included
Memeory leaks checking: No memory leaks found using “valgrind --leak-check=full --show-reachable=yes <command> <arguments>”
Memory abuses: No memory abuses found using “valgrind --track-origins=yes <command><arguments>”
General requirements met
Exception Handling used extensively
Function Object called ComparatorEmpID used in class StaffContainer, function addStaff(), used to sort staff vector - to meet bonus requirement
Class Template for class (function object) ComparatorEmpID - to meet bonus requirement
Function Template in class PropertyContainer for function addStaff() - to meet bonus requirement
Boost Library used extensively to meet bonus requirement. 
     - Classes used: StaffContainer, PropertyContainer
     - Additionally used in utility1.cpp utility1.h utility functions files
Data Validation - including validation of ints, doubles, employee ID and staff ID, for input files, and user input
Pure Virtual Function used in base property and staff classes
Every class has its own interface
Overloading of << and >> for all derived property and staff classes
Overloading of << and >> for file input and output
No C libraries used except one, <cstdlib> for use of EXIT_SUCCESS and EXIT_FAILURE, permission granted on DB by Robbie
No compile erros or warnings
Compile flag (permission granted by Robbie) -std=c++11 required for compilation
Each class is in it's own file
File and class naming conventions adhered to
Variable constants used with sensible variable names
Code is 3-space indented
No lines longer than 80 characters
 


Software used:
---------------
Windows 8.1 64Bit, Codeblocks v13.12 32 Bit, g++ Compiler. Boost header only library. std=c++11 COmpiler Flag. Tested on RMIT linux servers, including Valgrind


Assignment Question to be answered in the README FILE 

Why you think that these particular STL containers were chosen by the software designers?
Multimap: fast for random access with the use of a key. This type of access is required when retrieving properties realted to a specific empployee ID
Set: Able to be sorted, for printing of employee sorted by employee ID. Also unique elements required, which the set allows for.
Vector: Fast addition of property elemenents to the vector at the end is the key here. And efficient access to elements. No positional insertion is required for the program, making the vector a good choice.





Any other notes for the marker:
-------------------------------
