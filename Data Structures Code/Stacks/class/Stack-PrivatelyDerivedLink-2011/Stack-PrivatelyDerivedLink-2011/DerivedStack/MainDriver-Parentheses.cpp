#include <iostream>
#include <string>
#include "PrivatelyDerivedStack.h"

using namespace std;

const char LP = '(';
const char RP = ')';
const int MaxLength = 80;

void printMatchedPairs( string expression)
{
   PrivatelyDerivedStack< int > stack;
   int i, j, length = expression.length();

   for( i = 0 ; i <= length ; i++)
   {
      if( expression[i] == LP)
          stack.push( i);
      else 
		  if( expression[i] == RP)
			  if( !stack.isStackEmpty())
			  {
				  stack.pop( j);
				  cout << j << "  " << i << endl;
			  }
			  else
				  cout << "\nNo match for right parenthesis at index " 
                    << i << endl;
   }

   while( !stack.isStackEmpty())
   {
        stack.pop( j);
		cout << "\nNo match for left parenthesis at index "
                 << j << endl;
   }
 
   return;
}

int main()
{
   string expression;
  
   cout << "Type an expression of length at most " << MaxLength << endl;
   cin >> expression;
   cout << "The pairs of matching parentheses in\n" << endl;
   cout << expression << endl;
   cout << "\nare\n" << endl;
   printMatchedPairs( expression);

   return 0;
}
