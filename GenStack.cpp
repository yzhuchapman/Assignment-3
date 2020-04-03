#include "GenStack.h"

//default constructor
template <typename T>
GenStack<T>::GenStack()
{
  myArray = new T[5];
  mSize = 5;
  top = -1;
}

//overloadedconstructor
template <typename T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <typename T>
GenStack<T>::~GenStack()
{
	delete myArray;
  //destructor
}

template <typename T>
void GenStack<T>::push(T data)
{
  if(!this->isFull()){
   myArray[++top] = data;
}
else{
  cout<<"can't push due to a full array."<<endl;
}
}

template <typename T>
T GenStack<T>::pop()
{
  if(this->isEmpty()){
    cout<<"Empty stack, can't pop"<<endl;
    throw 0;
  }else{
  return myArray[top--];
}
}

template <typename T>
T GenStack<T>::peek(){
  return myArray[top];
}

template <typename T>
bool GenStack<T>::isFull()
{
  //returns true if full and false if not full
  return (top>=mSize-1);
}

template <typename T>
bool GenStack<T>::isEmpty()
{
  //returns true if empty and false if not empty
  return (top==-1);
}

template <typename T>
int GenStack<T>::size()
{
  return top+1;
}

template <typename T>
int GenStack<T>::maxSize()
{
  return mSize;
}
