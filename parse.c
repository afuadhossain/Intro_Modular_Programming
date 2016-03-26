
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntax.h"
#define BOOLEAN int

//intializing the buffer and backup buffer to be used by the following functions
char buffer [1000];
char buffer_backup [1000];

void initBuffer(char *inputLine){
// intializing a buffer where we will store the string passed in the parameter inputLine
	int i;
	for ( i=0; i<=1000; i++){
		buffer[i]=inputLine[i];
		// subsequently storing a backup of that buffer
		buffer_backup[i]=buffer[i];
	}
}
BOOLEAN hasNextToken(){
//this method determines whether there exists more space in the buffer
	if(buffer[0]== '\0'){
		return 0;
	}
	else{
		return 1;
	}
}

char *nextToken(){
//this function removes the first token from the buffer, the removed token is returned
	//tokenizing the input line and saving first token into the variable token
	char *token;
	token=strtok(buffer, " ");
	
	if(token!=NULL){
		int i=0;
		//shifting buffer by the size of token, so it points at the next token
		while(buffer[i]!='\0'){
			buffer[i]=buffer[i+strlen(token)+1];
			i++;
		}
		return token;
	}
	else{
		return NULL;
	}
}
void myrewind(){
// reinitializes the private buffer with the string originally provided by initBuffer() function call
	int i;
	// using the backup we had initially saved, we reintialize the buffer
	for( i-0; i<1000; i++){
		buffer[i]=buffer_backup[i];
	}
}

void main(void){
}	



