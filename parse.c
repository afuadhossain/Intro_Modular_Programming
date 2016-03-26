
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntax.h"
#define BOOLEAN int

//intializing the buffer, pointers to be used by the following functions
char buffer [1000];
char tokenBuffer[32];
char *p;
char *q;

void initBuffer(char *inputLine){
// intializing a buffer where we will store the string passed in the parameter inputLine
	strcpy(buffer,inputLine);
	//have the pointers point at the first position of buffer
	p=&buffer[0];
	q=&buffer[0];
	//take note of initial buffer for the sake of rewinding
}
BOOLEAN hasNextToken(){
//this method determines whether there exists more space in the buffer
	if(*p== '\0'){
		return 0;
	}
	else{
		return 1;
	}
}
char *nextToken(){
//this function removes the first token from the buffer, the removed token is returned
	
	//if buffer is empty, returns NULL	
	if(*p=='\0'){
 		return NULL;
	}
	//q moves across the buffer until it hits a space or null terminator
	while(*q!=' ' && *q!='\0') {
		q++;
	}
	int i=0;
	//we save the trail between p and q into the tokenBuffer, which holds one token
	//moving p forward until it's one space behind q
	while(p<q) {
		tokenBuffer[i] = *p;
		i++;
		p++;
	}
	tokenBuffer[i]='\0';
	//we move p and q to the next token if and only they both land on a space
	if(p!='\0'){
		 p++;
	}
	q=p;
	return tokenBuffer;
}
void myrewind(){
// reinitializes the private buffer with the string originally provided by initBuffer() function call
	p = &buffer[0];
}
