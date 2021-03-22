#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**Sameh Ahmed**/
int main(int argc, char** argv) 
{
    while(1)
    {
        pid_t pid;
        int readChar; 
        int tracker = 0;
        int z = 0 ;
        int y = 0;
        int argCount = 1 ;
        int x=0;
        bool ampFlag= false;
        char * cPrompt  = (char*)calloc(0, sizeof(char)); 
        char * commandPointer[argCount];
        commandPointer[0] = &cPrompt[0];   

        fprintf(stdout,"Your command> ");

        
        
        
        
        do 
        {
            cPrompt = realloc(cPrompt, tracker*sizeof(char));
            tracker++;
            readChar = getchar();
                if (readChar == '&') 
                 {
                    ampFlag = true;
                    fprintf(stdout,"Parent \n");
                    continue;
                }
            
            cPrompt[tracker-1] = readChar;  
        }
        while (readChar  != '\n');
        
       
        
        
        
        
        
        for (z = 0; z < tracker; z++)
        {
            if ( cPrompt[z] == '\n')
            {
                cPrompt[z] = '\0';
                argCount++;
              
            }

        }
      
        
        
        
       
       for (z = 0; z < tracker-1; z++)
        {
            if (cPrompt[z] == '\0')
            {
                y = &cPrompt[z+1];
                x++;
                commandPointer[x] = y; 
            }
        }
        commandPointer[argCount-1] = NULL;
        
  
        
        
        
        
        pid_t cpid = fork();
        if (cpid < 0){
             fprintf(stderr,"\n");
            
        }
        else if (cpid == 0)
        {
             fprintf(stdout, "CHILD \n ");
             execvp(commandPointer[0],commandPointer);
             
      
        }
        if (pid > 0)
        {
            if (ampFlag == false) 
            {   
                fprintf(stdout, "WAITED \n");
                
                pid = wait(NULL);     
                
            }
            else 
                printf("\n");
    
            
        }
        
    }
    

  
    
}
    