#include <stdio.h>
#include<time.h>
void fill_time(char*);


int main(){
    char time[50];  //string
    fill_time(time);
    printf("Current time : %s", time);
    return 0;
}
void fill_time(char* buffer){
    time_t raw_time;
    struct tm *current_time;
    time(&raw_time);
    current_time=localtime(&raw_time);
    strftime(buffer, sizeof(buffer),"%I:%M:%S %p", current_time);
   
}

//I am getting error in this , lets us do this after some projects .