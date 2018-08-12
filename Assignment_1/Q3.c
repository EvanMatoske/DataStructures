/* CS261- Assignment 1 - Q.3*/
/* Name: Evan Matoske	
 * Date:1/15/16
 * Solution description: Answers Q3
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (number[i] > number[j]){
                int a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}


int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int* array;
    array = malloc(sizeof(int)*n);
    /*Fill this array with random numbers, using rand().*/
    for (int i =0; i < n; i++)
        array[i] = rand() % 100;
    /*Print the contents of the array.*/
    for (int i =0; i < n; i++)
        printf("%d \n", array[i]);
    printf("\n");
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/  
    for (int i =0; i < n; i++)
        printf("%d \n", array[i]);
    return 0;
}
