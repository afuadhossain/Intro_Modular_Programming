#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>


int isValidCommand(char *token){
// A robot command is atomic. It is a single word that directs the robot to do a specific self-contained task. Legal commands are: TAKEASTEP, LEFT, RIGHT, PICKUP, DROP, DETECTMARKER, TURNON, and TURNOFF. These commands are not case sensitive, so Walk, walk, walK, and WALK are all valid
	
	//we remove the comma from the end of the token
	if(token(strlen(token)-1) == ","){
		token(strlen(token)-1) == '\0';
	}
	//verifying that commands are valid, else return 0;
	if(strcasecmp(token,"TAKEASTEP")==0 || strcasecmp(token,"LEFT")==0 || strcasecmp(token, 	"RIGHT")==0 || strcasecmp(token, "PICKUP")==0 || strcasecmp(token, "DROP")==0 || 		strcasecmp(token, "DETECTMARKER")==0 || strcasecmp(token, "TURNON")==0 || 
	strcasecmp(token="TURNOFF")==0){
		return 1;
	}
	else{
		return 0;
	}	
}
int isValidExpression(char *expression){












}
