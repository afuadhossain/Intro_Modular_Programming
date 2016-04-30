#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	char *BackupTime = getenv("BackupTime");
	char buffertime[6];
	int i = 1;
	//infinite loop
	while(1){
		//declaring the time.h library variables needed to take note of time
		time_t rawtime;
		//this is taking the current time and saving it rawtime
		time(&rawtime);
		//time expressed into local time zone
		struct tm *processedtime=localtime(&rawtime);
		strftime(buffertime, 6, "%H:%M", processedtime);
		printf("Backup to be completed at: %s\n", BackupTime);
		while(strcmp(buffertime, BackupTime)!=0){
			//we sleep for a 1 min, before checking again
			sleep(60);

			//this is taking the current time and saving it rawtime
			time(&rawtime);
			//time expressed into local time zone
			processedtime=localtime(&rawtime);
			strftime(buffertime, 80, "%H:%M", processedtime);
		}
		//backing up from source to destination!
		printf("STARTING BACKUP...\n");
		system("cp -R $BackupSource/*.* $BackupDestination");
		sleep(3);
		printf("BACKUP COMPLETE!\n");
		//sleeps so that we only have one backup within that minute
		sleep(60);
	}
return 0;
}


