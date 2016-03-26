#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"


int isValidCommand(char *token){
// A robot command is atomic. It is a single word that directs the robot to do a specific self-contained task. Legal commands are: TAKEASTEP, LEFT, RIGHT, PICKUP, DROP, DETECTMARKER, TURNON, and TURNOFF. These commands are not case sensitive, so Walk, walk, walK, and WALK are all valid
	
	//verifying that commands are valid, else return 0;
	if(strcasecmp(token,"TAKEASTEP")==0 || strcasecmp(token,"LEFT")==0 || strcasecmp	(token,"RIGHT")==0 || strcasecmp(token, "PICKUP")==0 || strcasecmp(token, "DROP")==0 || strcasecmp(token, 		"DETECTMARKER")==0 || strcasecmp(token, "TURNON")==0 ||	strcasecmp(token, "TURNOFF")==0){
		return 1;
	}
	else{
		return 0;
	}	
}
int isValidExpression(char *expression){
/*A robot expression is a statement that composes robot commands into control
structures. Legal expressions are:
• REPEAT n TIMES comma-separated-list-of-commands END
◦ The identifier n is any integer number greater than zero.
◦ The expression “repeat” iterates n times executing the comma-
separated list of commands in the order they are written.
• WHILE NOT c DO comma-separated-list-of-commands END
◦ The identifier c is any legal condition. In this assignment there is only
one condition and it is a robot command: DETECTMARKER. It
returns a true if the robot is standing on a “marker”, otherwise it
returns false.
SAY “message”
◦ The robot speaks the words contained in the string “message”.
*/
	int i;
	for(i=0; i<strlen(expression); i++) {
		if(expression[i]==',') {
			expression[i]=' ';
		}
	}
	initBuffer(expression);
	char *token=nextToken();
	//in the next set of if statements, we are checking to see if the first token is either REPEAT, WHILE, or SAY, else we return 0.

	
	//Checking to see that the expression follows the structure: REPEAT n TIMES comma-separated-list-of-commands END
	
	if (strcasecmp(token, "REPEAT")==0){
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////////////
		if(atoi(token)<=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////////
		if(strcasecmp(token, "TIMES")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 0; ///////////////////////////////////
		while(isValidCommand(token)==1){
			token=nextToken();
			if(token==NULL) return 0;////////////////////////////
		}
		if(strcasecmp(token, "END")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 1;
		
	}
	//Checking to see that the expression follows the structure: WHILE NOT c DO comma-separated list-of-commands END

	if (strcasecmp(token, "WHILE")==0){
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////
		if(strcasecmp(token, "NOT")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////
		if(strcasecmp(token, "DETECTMARKER")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////
		if(strcasecmp(token, "DO")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////
		while(isValidCommand(token)==1){
			token=nextToken();
			if(token==NULL) return 0; //////////////////////////////
		}
		if(strcasecmp(token, "END")!=0){
			return 0;
		}
		token=nextToken();
		if(token==NULL) return 1;
	}
	//Checking to see that the expression follows the structure: SAY "message"
	if (strcasecmp(token, "SAY")==0){
		token=nextToken();
		if(token==NULL) return 0; //////////////////////////////
		if(token!=NULL){
			return 1;	
		}
	}
	return 0;
}
