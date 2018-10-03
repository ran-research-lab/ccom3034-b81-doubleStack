#include <iostream>
#include <cstdlib>

using namespace std;




const int STACK_CAPACITY = 6;
typedef int StackElement;

class DStack {
 public:
  DStack();

  bool isEmpty(int stackNum) const;
  bool isFull() const;

  void push(int stackNum, const StackElement & value);
  StackElement top(int stackNum) const;
  void pop(int stackNum);

 private:
  StackElement myArray[STACK_CAPACITY];
  int myTop0, myTop1;
}; 




DStack::DStack()
{}


bool DStack::isEmpty(int stackNum) const{
}

bool DStack::isFull() const{
}

// Given a value and the stack number (0 or 1) pushes the value
// onto the stack (if it is not full)

void DStack::push(int stackNum, const StackElement & value) {
}

// Given the stack number (0 or 1), returns the value of the top element
// in that stack (if that stack is not empty)

StackElement DStack::top(int stackNum) const {
  return(0);
}

// Given the stack number (0 or 1), pops the top element
// from that stack (if that stack is not empty)

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
				if (s.isFull()) 
					cout << "Can't push " << b << " to stack #" << a << ", it is full!\n"; 
				else  { 
					cout << "Inserting " << b << " to stack #" << a << endl;
					s.push(a, b);
				}
				break;
			case 'r': 
				cin >> a;
				if (s.isEmpty(a)) 
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
				while(!s.isEmpty(a)) {
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
