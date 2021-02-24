#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
 
int main(void) 
{ 
    int par_to_child[2];           /* pipe from parent to child */ 
    int child_to_par[2];           /* pipe from child to parent */ 
    int child;                     /* child's PID */ 
    char parsend[100]; 
    char parrecv[100]; 
    char childsend[100]; 
    char childrecv[100]; 
 
    /* Setup info texts */ 
    strcpy(parsend,"Parent sent X\n"); 
    strcpy(childsend,"Child sent X\n"); 
    strcpy(parrecv,"Parent received X\n"); 
    strcpy(childrecv,"Child received X\n"); 
 
    /* Create the pipes. */ 
    pipe(par_to_child); 
    pipe(child_to_par); 
 
    /* Create the child process */ 
    child = fork(); 
 
    /* Run the parent's code */ 
    if (child != 0) { 
        /* parent */ 
        int i; 
        char msg, msgin; 
        for(i=0;i<10;i++) { 
            msg = '0' + i; 
            parsend[strlen(parsend)-2] = msg; 
            write(1,parsend,strlen(parsend)); 
            write(par_to_child[1],&msg,1); 
 
            read(child_to_par[0],&msgin,1); 
            parrecv[strlen(parrecv)-2] = msgin; 
            write(1,parrecv,strlen(parrecv)); 
        } 
        exit(0); 
    } else 
 
    /* Run the child's code */ 
    { 
        /* child */ 
        int i; 
        char msgin; 
        for(i=0;i<10;i++) { 
            read(par_to_child[0],&msgin,1); 
            childrecv[strlen(childrecv)-2] = msgin; 
            write(1,childrecv,strlen(childrecv)); 
 
            childsend[strlen(childsend)-2] = msgin; 
            write(1,childsend,strlen(childsend)); 
            write(child_to_par[1],&msgin,1); 
        } 
        exit(0); 
    } 
} 