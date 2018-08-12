/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"
/******************************************************************
 * Name: Evan Matoske
 * Date: 1/24/2016
 * Dewscription: Using stack to check fo unbalanced Parenstheses.
 ******************************************************************/

/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    assert(s != '\0');
    DynArr *bal;
    bal = newDynArr(10);
    TYPE val;
    char temp = nextChar(s);
    
    do{
        if (temp == '(') {
            val = ')';
                pushDynArr(bal, val);
        }
        
        else if (temp == '{'){
            val = '}';
                pushDynArr(bal, val);
        }
    
        else if (temp == '['){
            val = ']';
                pushDynArr(bal, val);
        }
    
        else if (temp == ')'){
            if (isEmptyDynArr(bal) == 1)
                return 0;
            else if (topDynArr(bal) == ')'){
                popDynArr(bal);
            }
            else return 0;
        }
    
        else if (temp == '}'){
            if (isEmptyDynArr(bal) == 1)
                return 0;
            else if (topDynArr(bal) == '}'){
                popDynArr(bal);
            }
            else return 0;
        }
    
        else if (temp == ']'){
            if (isEmptyDynArr(bal) == 1)
                return 0;
            else if (topDynArr(bal) == ']'){
                popDynArr(bal);
            }
            else return 0;
        }
        
    temp = nextChar(s);
    }while (temp != '\0');
    
    if (isEmptyDynArr(bal) == 1)
        return 1;
    else return 0;
    
}

int main(int argc, char* argv[]){
	
	char* s=argv[10];
	int res;
	s = "{}";
	printf("Assignment 2\n");
    

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

