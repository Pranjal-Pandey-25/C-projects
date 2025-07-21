#include<stdio.h>
#include<math.h>
void printmenu(){
    printf("\n\n----------------------------------");
    printf("\nWelcometo simple calculator.");
    printf("Choose one of the following operations :\n");
    printf("\n 1. ADD");
    printf("\n 2. SUBTRACT");
    printf("\n 3. MILTIPLY");
    printf("\n 4. DIVIDE");
    printf("\n 5. MODULUS");
    printf("\n 6. POWER");
    printf("\n 7. EXIT");
    printf("\n Now, enter your choice.");
}

double divide(double a,double b);
double divide(double a,double b){
    if (b==0)
    {
        fprintf(stderr,"Invalid argument for division.\n");
        return NAN;
    }
    else{
        return a/b;
    }
}

double modulus(int a, int b);
double modulus(int a, int b){
 if (b==0)
    {
        fprintf(stderr,"Invalid argument for modulus.\n");
        return NAN;
    }
    else{
        return a%b;
    }

}
int main(){
    int choice;
    double first, second, result;

   while(1)
    {
       printmenu();
    scanf("%d", &choice);
    if (choice==7){
        break;
    }
    if (choice<1 || choice>7)
    {
        fprintf(stderr,"Invalid menu choice");
        continue;
    }
    
    
    printf("Please enter first no. : \n");
    scanf("%lf",&first);
    printf("Please enter second no. : \n");
    scanf("%lf",&second);

    switch (choice)
    {
    case 1: //add
       result=first+second;
        break;
    case 2: //subtract
       result=first-second;
        
        break;
    case 3: //multiply
       result=first*second;
        
        break;
    case 4: //divide
       result=divide(first,second);
       
        break;
    case 5: //modulus
       result=modulus(first,second);
        
        break;
     case 6: //power
       result=pow(first,second);
       
        break;
    default:
        break;
    }
    if (!isnan(result))
    {
        printf("Result of operation is %.2f\n", result);
    }
    
   
    } 
    
    
    return 0;
}