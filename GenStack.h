#include<iostream>
#include <stdlib.h>  
using namespace std;

template <typename T>
class GenStack
{
public:
  GenStack(); //default constructor
  GenStack (int maxSize); //overloadedconstructor
  ~GenStack(); //destructor
  void push(T data); //insert
  T pop(); //remove

  //helper functions
  bool isFull();
  bool isEmpty();
  T peek();
  int size();
  int maxSize();
  int mSize; // max size of myStack
  int top; // variable to keep track of indices representing the top of our myStack
  T *myArray;
};
