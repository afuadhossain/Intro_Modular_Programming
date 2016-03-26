#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"


int isValidCommand(char *token){
// A robot command is atomic. It is a single word that directs the robot to do a specific self-contained task. Legal commands are: TAKEASTEP, LEFT, RIGHT, PICKUP, DROP, DETECTMARKER, TURNON, and TURNOFF. These commands are not case sensitive, so Walk, walk, walK, and WALK are all valid
	
	//we remove the comma from the end of the token
	if(token[strlen(token)-1] == ','){
		token[strlen(token)-1] == '\0';
	}
	//verifying that commands are valid, else return 0;
	if(strcasecmp(token,"TAKEASTEP")==0 || strcasecmp(token,"LEFT")==0 || strcasecmp(token, 	"RIGHT")==0 || strcasecmp(token, "PICKUP")==0 || strcasecmp(token, "DROP")==0 || 		strcasecmp(token, "DETECTMARKER")==0 || strcasecmp(token, "TURNON")==0 || 
	strcasecmp(token, "TURNOFF")==0){
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
	
	








}
void main(void){
}
