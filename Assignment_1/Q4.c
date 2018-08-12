/* CS261- Assignment 1 - Q.4*/
/* Name: Evan MAtoke
* Date: 1/15/16
* Solution description: Answers Q4
*/
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (students[i].score > students[j].score){
                struct student a = students[i];
                students[i] = students[j];
                students[j] = a;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n);
    /*Generate random IDs and scores for the n students, using rand().*/
    for (int i = 0; i < n; i++){
        students[i].score = rand() % 100 + 1;
    }
    int IDs[10];
    int ID, j;
    int i = 0;
    while (i < 10){
        ID = rand() % 10 + 1;
        for (j = 0; j < i; j++){
            if(IDs[j] == ID){
                break;
            }
        }
        if (j == i){
            IDs[i++] = ID;
        }
    }
    for (int i = 0; i < 10; i++){
        students[i].id = IDs[i];
    }


    /*Print the contents of the array of n students.*/
    for (int i = 0; i < 10; i++){
        printf("Student %d ID = %d, SCORE %d = %d \n", i + 1,  students[i].id, i + 1 , students[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < 10; i++){
        printf("Student %d ID = %d, SCORE %d = %d \n", i + 1,  students[i].id, i + 1 , students[i].score);
    }
   return 0;
}
