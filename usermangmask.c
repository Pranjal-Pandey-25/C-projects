#include<string.h>
#include<stdio.h>
#include<unistd.h>//here for pointing current terminal.
#include<termios.h> 

#define MAX_USER 10
#define CREDENTIAL_LENGTH 30

typedef struct usermang
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
}user;

user users[MAX_USER];
int user_count=0;
void fix_fgets_input(char*);// it will replace \n with \0 in string.
void input_credentials(char* username , char* password);
void register_user();
int login_user(); //returns the user index.

int main(){
    int option;
    int user_index;
    while (1)
    {
    printf("\n\nWelcome to user management.");
    printf("\n1. Register.");
    printf("\n2. Login");
    printf("\n3. Exit");
    printf("\nSelect an option: ");
    scanf("%d", &option);
    getwchar(); //consume  extra enter.----------> point to be noted.
    switch (option)
    {
    case 1:
        register_user();
        break;
    case 2:
       user_index=login_user();
       if (user_index>=0)
       {
       printf("Login succesful, welcome %s",users[user_index].username);
       }else{
        printf("\nLogin failed! incorrect username or password.");
       }
       
        break;
    case 3:
       printf("\nExiting the programe.");
       return 0;
        break;
    
    default:
    printf("\nInvalid input, please try again");
        break;
    }
    }
    
}

void register_user(){
    if (user_count==MAX_USER)
    {
       printf("\nMAX %d user are supported , no more registration is allowed.",MAX_USER);
       return;
    }
    
    int new_index=user_count;
    printf("\nResister a new user.");
    input_credentials(users[new_index].username, users[new_index].password);
    user_count++;
    printf("\n Registration succesfull !");
}

int login_user(){
    char username[CREDENTIAL_LENGTH], password[CREDENTIAL_LENGTH];
    input_credentials(username,password);
    for (int i = 0; i < user_count; i++)
    {
       if (strcmp(username,users[i].username)==0&&strcmp(password,users[i].password)==0)
       {
        return i;
       }  
    }
    return -1;
}

void input_credentials(char* username, char* password){
    printf("\nEnter username : ");
    fgets(username,CREDENTIAL_LENGTH,stdin);
    fix_fgets_input(username);

     printf("\nEnter password (masking enabled) : ");
     fflush(stdout);
    //change terminal properties.
    struct termios old_props , new_props;
    tcgetattr(STDIN_FILENO, &old_props);
    new_props=old_props;
    new_props.c_lflag=~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

    char ch;
    int i=0;
    while ((ch=getchar())!='\n' && ch!=EOF){}
    {
        if (ch=='\b' || ch==127)
        {if (i>0)
        {
             i--;
            printf("\b \b")
        }
        }else{
            password[i]=ch;
            i++;
       printf("*");
        }
    }
    password[i]='\0';
    
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}
void fix_fgets_input(char* string){
    int index = strcspn(string,"\n");
    string[index]='\0';
}