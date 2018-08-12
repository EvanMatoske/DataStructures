/* CS261- Assignment 1 - Q.5*/
/* Name: Evan Matoske
 * Date: 1/15/16
 * Solution description: Answers Q5
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    for (int i = 0; word[i] != '\0'; i++){
        if (i % 2 == 0){
            if (word[i] >= 97 && word[i] <= 122){
                word[i] = toUpperCase(word[i]);
                
            }
        }
        else if (i % 2 != 0){
            if (word[i] >= 65 && word[i] <= 90){
                word[i] = toLowerCase(word[i]);
            }
        }
    }
}

int main(){
    char s[1000];
    /*Read word from the keyboard using scanf*/
    printf("Enter a word : ");
    scanf("%s", s);
    /*Call sticky*/
    sticky(s);
    /*Print the new word*/
    printf("%s \n",s);
    return 0;
}
