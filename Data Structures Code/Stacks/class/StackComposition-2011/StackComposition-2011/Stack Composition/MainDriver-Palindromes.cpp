#include <iostream>
#include "StackComposition.h"

using namespace std;

// creates a new string with all blank characters removed
void deblankString(char *s, char *t)
{
    // loop through expression until NULL character is found
    while( *s != '\0')
    {
        // if character is a non-blank, copy to new string
        if (*s != ' ')
            *t++ = *s;
        s++;            // move to next character
    }
    *t = '\0';          // append NULL to new string
}


int main()
{
    // stack holds chars in reverse order
    ComposedStack< char > stack;
    
    int  i = 0;
    char palString[80], deblankedString[80], ch;
    bool isPalindrome = true;    // assume string is a palindrome

    // read in the full-line string
    cin.getline( palString, 80, '\n');

    // remove blanks from string and put result in deblankstring
    deblankString( palString, deblankedString);

    // push the chars of deblanked expression on the stack
    i = 0;
    while( deblankedString[i] != '\0')
    {   
        stack.push( deblankedString[i]);
        i++;
    }

    // now pop stack, comparing characters with original string
    i = 0;
    while( !stack.isStackEmpty())
    {
        stack.pop( ch);    // get next character from  stack
        // if chars don't match, break out of the loop
        if (ch != deblankedString[i])
        {
            isPalindrome = false;   // not a palindrome
            break;
        }
        i++;
    }

    if( isPalindrome)
        cout << '\"' << palString << '\"' 
             << " is a palindrome" << endl;
    else
        cout << '\"' << palString << '\"' 
             << " is not a palindrome" << endl;

	return 0;
}
