/* CS261- Assignment 1 - Q.2*/
/* Name: Evan Matoske	
 * Date: 1/15/16
 * Solution description: Answers to Q2
 * */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
   
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("%d, %d, %d \n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("%d \n", z);
    /*Print the values of x, y and z again*/
    printf("%d, %d, %d \n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
/*The value of z did not get changed because it was passed by value, that is
 * just a copy of the number was passed into the function so it could not be 
 * manipulated in anyway. The other number were passed by reference or address.
 * Those numbers can be manipulated by the function.*/     
    
