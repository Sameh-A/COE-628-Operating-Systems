/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 *Sameh Ahmed
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



    char **args1;
    char **args2;
    char *firstInput;
    char *secondInput;
    int input1=0;
    int input2=0;
    int stringCount;
 
    
char **argConversion(char *line){
    int y =0;
    char **stringTk=malloc(10*sizeof(char*));
    char *tk1;
    tk1 = strtok(line," ");
    while(tk1!='\0'){
        stringTk[y] =tk1;
        y++;
        tk1 = strtok('\0'," ");
    }
    stringTk[y]='\0';
    return stringTk;
    
}
   
int main(int argc, char** argv) {
    char *cmdString(){ 
    char *stringTracker = malloc(sizeof(char));    
    int x=0;
    while(1){
        stringCount = getchar();
        if(stringCount=='\n'){
        stringTracker[x]=NULL;
        return stringTracker;
        }
        else{
        stringTracker[x]= stringCount;
        }
        x++;
    }
    }
    char *inputString;
    while(1){
    int arry[10];
    printf("enter ls |wc -w to get the file count \n");
    inputString = cmdString() ;
    firstInput = malloc(sizeof(char*));
    secondInput = malloc(sizeof(char*));      
    while(inputString[input1]!='|'){
        firstInput[input1] = inputString[input1];
        input1++;
    }
    firstInput[input1]=(char)NULL;
    input1++;

    while(inputString[input1]!=NULL){
    secondInput[input2]=inputString[input1];
    input1++;
    input2++;
        }
    secondInput[input2]=NULL;
    args1= argConversion(firstInput);
    args2= argConversion(secondInput);
    pipe(arry);
    pid_t cpid = fork();

    
    if (cpid==0){
        dup2(arry[1],STDOUT_FILENO);
        close(arry[0]);
        execvp(args1[0],args1);
    }
    
    else{
        dup2(arry[0],STDIN_FILENO);
        close(arry[1]); 
        execvp(args2[0],args2);
    }
    }
}
