#include "GenStack.cpp"
#include <fstream>

using namespace std;

//check if it is a pair
bool Pair(char A,char B){
	if(A == '(' && B == ')'){
  return true;
}
	else if(A == '{' && B == '}'){
   return true;
}
	else if(A == '[' && B == ']'){
  return true;
} else{
	return false;
}
}


int main(int argc, char** argv){
  //take command line arg
  ifstream ifs(argv[1]);
  string line;
  int lineCount=0;
  GenStack<char>* S=new GenStack<char>(100);
  //loop through file
  while(getline(ifs, line))
{
  ++lineCount;
  //loop through each characters
  for(int i=0;i<line.size();i++){
  if(line[i]=='(' || line[i]=='{' || line[i]=='[')
  {
    //push opening brackets to the stack
			S->push(line[i]);
}
else if(line[i]==')' || line[i]=='}' || line[i]==']')
		{
			if(S->isEmpty() || !Pair(S->peek(),line[i])){
        //if starts with closing bracket or wrong pair then exit
        cout<<"at line"<<lineCount<<":"<<i<<" wrong brackets or single closing bracket"<<endl;
        return 0;
      }
			else{
        //remove opening brackets from the stack if matched
				S->pop();
      }
		 }
   }
}
if(!S->isEmpty()){
  cout<<"Reached end of file: missing brackets"<<endl;
}else{
cout<<"No errors found"<<endl;
}
return 0;
}
