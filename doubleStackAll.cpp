#include <iostream>
#include <cstdlib>

using namespace std;


/*-- DStack declaration----------------------------------------------------
 
  This header file defines a Stack data type.
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if the specified stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Retrieves the top stack value; leaves stack unchanged
    pop:          Modifies stack by removing the value at the top
    display:      Displays all the stack elements
    full:         Checks if the stack is full.

  Class Invariant:
    1. Stack #0 elements are stored in positions
       0, 1, . . ., myTop0 of myArray.
    2. Stack #1 elements are stored in positions
       STACK_CAPACITY, STACK_CAPACITY-1, ....myTop1, 
--------------------------------------------------------------------------*/

const int STACK_CAPACITY = 6;
typedef int StackElement;

class DStack {
 public:
  DStack();
  /*------------------------------------------------------------------------
    Construct a DStack object.
   -----------------------------------------------------------------------*/

  bool empty(int stackNum) const;
  /*------------------------------------------------------------------------
    Check if stack is empty.
   -----------------------------------------------------------------------*/

  bool full() const;

  void push(int stackNum, const StackElement & value);
  /*------------------------------------------------------------------------
    Add a value to one of the stacks.
    The stackNum parameter specifies 0 or 1 depending on the stack.
   -----------------------------------------------------------------------*/

  StackElement top(int stackNum) const;
  /*------------------------------------------------------------------------
    Retrieve value at top of the stack specified by stackNum.
   -----------------------------------------------------------------------*/

  void pop(int stackNum);
  /*------------------------------------------------------------------------
    Remove value at top of the specified stack.
   -----------------------------------------------------------------------*/ 

 private:
  StackElement myArray[STACK_CAPACITY];
  int myTop0, myTop1;
}; 




DStack::DStack()
{}


bool DStack::empty(int stackNum) const{
}

bool DStack::full() const{
}

void DStack::push(int stackNum, const StackElement & value) {
}


StackElement DStack::top(int stackNum) const {
}

void DStack::pop(int stackNum) {
}



// The main function allows the user to perform the stack operations by using 
// the following format: instruction parameter1 (and parameter2 if necessary)
// The allowed instructions are:
//   - i stackNum element: inserts element in the specified stack
//       for example: i 1 23, inserts 23 in stack #1
//
//   - r stackNum : removes (pops) from the specified stack
//       for example: r 0, removes (pops) from stack #0
//
//   - a stackNum: empties the specified stack while printing its contents
//
//   - t stackNum: displays the top of the specified stack       
//
//   - q: quits
//

int main(int argc, char *argv[]) {

	DStack s;
	char inst; 
	int a, b;

  cout << "$ ";
	while (cin >> inst  and inst != 'q') {
		switch(inst) {
			case 'i': 
				cin >> a >> b;
				if (s.full()) 
					cout << "Can't push " << b << " to stack #" << a << ", it is full!\n"; 
				else  { 
					cout << "Inserting " << b << " to stack #" << a << endl;
					s.push(a, b);
				}
				break;
			case 'r': 
				cin >> a;
				if (s.empty(a)) 
					cout << "Can't pop, stack #" << a << " is empty!\n";
				else { 
					cout << "Poping from stack #" << a << endl;
					s.pop(a);
				}
				break;
			case 't':
				cin >> a;
				cout << "Top of stack #" << a << ": " << s.top(a) << "\n";
				break;
			case 'a':
				cin >> a;
				cout << "Emptying all of stack #" << a << ": ";
				while(!s.empty(a)) {
					cout << s.top(a) << " "; 
					s.pop(a);
				}
				cout << endl;
				break;			
			default:
				cout << "Not a recognized command.\n";			
		}
    cout << "$ ";
	}
  	return 0;
}
