#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>


int isValidCommand(char *token){
// A robot command is atomic. It is a single word that directs the robot to do a specific self-contained task. Legal commands are: TAKEASTEP, LEFT, RIGHT, PICKUP, DROP, DETECTMARKER, TURNON, and TURNOFF. These commands are not case sensitive, so Walk, walk, walK, and WALK are all valid
	
	//since we don't care for case-sensitivity, we convert everything to upper case for simplicity
	int i=0;
	while(token[i]!='\0'){
		token[i]=toupper(token[i]);
		i++
	}
	//we remove the comma from the end of the token
	if(token(strlen(token)-1) == ","){
		token(strlen(token)-1) == '\0';
	}
	//verifying that commands are valid, else return 0;
	if(token="TAKEASTEP" ||token="LEFT" || token="RIGHT" || token="PICKUP" || token="DROP" || 		token="DETECTMARKER" || token="TURNON" || token="TURNOFF"){
		return 1;
	}
	else{
		return 0;
	}
	
}
int isValidExpression(char *expression){

}
