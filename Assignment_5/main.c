#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
        cmd = getchar();
        if(cmd >= 'a' && cmd <= 'z')
            cmd = ('A' + cmd - 'a');
      /* get input command (from the keyboard), validate, and convert to upper
        int badLetter;
        
        do{
        badLetter = 0;
        cmd = getchar();
        if(cmd >= 'a' && cmd <= 'z')
            cmd = ('A' + cmd - 'a');
        
        if ((cmd != 'L')||(cmd !='S')||(cmd != 'A')||(cmd !='G')||(cmd != 'R')||(cmd !='P')||(cmd !='E')){
            printf("Invalid input!");
            cmd = getchar();
            badLetter = 1;
            }
        else badLetter = 0;
        }while (badLetter);
            */
      
        

        /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
        
        /*load file*/
        if (cmd == 'L'){
            char fileName[100];
            printf("Please enter the filename: ");
            scanf("%[^\n]s", fileName);
            while (getchar() != '\n');
            FILE *loadFile = fopen(fileName, "r");
            if (loadFile == NULL)
                fprintf(stderr, "Cannot open %s\n",fileName);
            else{ loadList(mainList, loadFile);
            printf("The list has been loaded from file successfully.");
            fclose(loadFile);
            }
        }
        
        /*save file*/
        else if (cmd == 'S'){
            char fileName[100];
            printf("Please enter the filename: ");
            scanf("%[^\n]s", fileName);
            while (getchar() != '\n');
            FILE *saveFile = fopen(fileName, "w");
            if  (saveFile == NULL)
                fprintf(stderr, "Cannot open %s\n",fileName);
            else { saveList(mainList, saveFile);
            printf("The list has been saved into the file successfully.");
            fclose(saveFile);
            }
        }
        
        /*creat new task*/
        else if (cmd == 'A'){
            int prio;
            char desc[100];
            int outRange = 0;
            
            /*gather users description*/
            printf("Please enter the task description: ");
            scanf("%[^\n]s", desc);
            while (getchar() != '\n');
            do{
                /*gathers users priority inside do/while for data validation*/
                printf("Please enter the task priority (0-999): ");
                scanf("%d", &prio);
                while (getchar() != '\n');
            
                /*Input validation*/
                if ((prio < 0) || (prio > 999)){
                    outRange = 1;
                    printf("Number out of range. Please re-enter.");
                    }
                else outRange = 0;
            
            }while (outRange);
            
            struct Task *newTask = createTask(prio, desc);
            
            addHeap(mainList, newTask, compare);
            printf("The task '%s' has been added to your to-do list \n", desc);
        }
        
        /*get first task*/
        else if (cmd == 'G'){
            if (sizeDynArr(mainList) == 0)
                printf("Your to-do list is empty!\n");
            
            else{
            struct Task *v = getMinHeap(mainList);
            print_type(v);
            }
        }
        
        /*remove first task*/
        else if (cmd == 'R'){
            if (sizeDynArr(mainList) == 0)
               printf("Your to-do list is empty!\n");
            else{
                struct Task *removed = getMinHeap(mainList);
                removeMinHeap(mainList, compare);
                printf("Your first task '%s' has been removed from the list.", removed->description);
            
            }
        }
        
        /*Print list*/
        else if (cmd == 'P'){
            if (sizeDynArr(mainList) == 0)
                printf("Your to-do list is empty!\n");
            else printList(mainList);
        }
        
      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
        printf("\n");
    }while(cmd != 'E');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
