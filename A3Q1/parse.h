#define BOOLEAN int
//these are all the functions from parse.c that can be utilzed by other c files
void initBuffer(char *inputLine);
char *nextToken();
BOOLEAN hasNextToken();
void myrewind();
