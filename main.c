#include <stdlib.h>
#include <stdio.h>
#include "syntax.h"
#include "parse.h"

void main(int argc,char *argv[])
{	
	//will throw an error statement if you have entered more than one text file
	if(argc==1){
		printf("You have not entered a txt file, please enter a txt file\n");	
	}
	//will throw an error statement if you have entered no text file
	if(argc>2){
		printf("You have entered more than one txt file, please enter one txt file\n");	
	}
	//intializing a file pointer that will point to the designated file	
	FILE *file_ptr;
	char line[300];
	//opening the designated file
	file_ptr = fopen(argv[1], "rt");
	//making sure file is readable
	if (file_ptr == NULL){
		printf("Oops, something went wrong when opening your file\n");
		return;
	}
	// retrieving a line from the txt file
	int linenumber=1;
	fgets(line,299,file_ptr);
	//checking syntax of line and then retrieving the subsequent lines
	while (!feof(file_ptr)){
		//No spaces, command
		if(strchr(line,' ')==NULL) {
			if (isValidCommand(line)==0){
				printf("ERROR!!! you messed up on line: %d/n%s/n", linenumber, line);
				
			}
		} 
		//Has spaces, expression
		else {
			if (isValidExpression(line)==0){
				printf("ERROR!!! you messed up on line: %d/n%s/n", linenumber, line);
			}
		}
		linenumber++;
		fgets(line, 299, file_ptr);
	}
	fclose(file_ptr);
}

