#include<stdio.h>
#include<unistd.h>//here for sleep
#include<stdlib.h>
#include<time.h>

const int BAR_LENGTH=50; 
const int MAX_TASKS=5; 
typedef struct progbar
{
   int id;
   int progress;
   int step;
} task;

void printb(task task);   
void printb(task task){
    int bars_to_show=task.progress*BAR_LENGTH/100;
    printf("\nTask %d: [", task.id);
    for (int i = 0; i < BAR_LENGTH; i++)
    {
       if (i<bars_to_show)
       {
        printf("=");
       }else{
        printf(" ");
       }
       
    }    
    printf("] %d%%", task.progress);

}

void clear_scr();
void clear_scr(){
   #ifdef _Win32
   system("cls");
   #else
   system("Clear");
   #endif
}
void main(){
   srand(time(NULL));
   task tasks[MAX_TASKS];

   //initialization.
   for (int i = 0; i < MAX_TASKS; i++)
   {
      tasks[i].id=i+1;
      tasks[i].progress=0;
      tasks[i].step=rand() % 5 + 1;
   }
   int tasks_incomp=1;
   while (tasks_incomp)
   {
      tasks_incomp=0;
      clear_scr();
      for (int i = 0; i < MAX_TASKS; i++)
      {
         tasks[i].progress+=tasks[i].step;
         if (tasks[i].progress>100){
            tasks[i].progress=100;
         }
         else if (tasks[i].progress<100)
         {
            tasks_incomp=1;
         }
         printb(tasks[i]);
         
      }
      
      sleep(1); //sleep for 1 second.
   }
   
   printf("\nAll tasks completed.\n");
}