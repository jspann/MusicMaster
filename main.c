#import <stdio.h>
#include <stdbool.h>

bool getinput;
char *filename;
FILE *fp;
char input[20];

void getterminput();
void lexAnalysis();

int main(int argc, char *argv[]){
	int y;
	getinput = 1;
	
	if (argc == 1){
		getterminput();
	}

	for (y = 1; y<argc; y++) {
		printf("for\n");
		if (argv[y] == NULL){
			//help();
			printf("um. not sure when this happens");
		}else if(strcmp(argv[y],"-u")==0){
			printf("-u     : unbuffered binary stdout and stderr;\n");
		}else if(strcmp(argv[y],"-c")==0){
			filename=argv[y+1];
			y++;
			
			fp = fopen(filename,"r");
			if( fp ) {//Checking if the file exists
				// exists
				/*initlex();
				initParser();
				cgen();
				fclose(fp);
				printf("Finished with success\n");*/
			}else{
				// doesnt exist
				printf("The file doesn't exist. Make sure you have titled it correctly. \n");
				//exit(0);
			}
			
		}else if(strcmp(argv[y],"-?")==0){
			//help();
			printf("helpo");
		}else{
			printf("Invalid command: \"%s\". Please enter -? for available commands.\n",argv[y]);
		}
	}

	//getterminput();
	return 0;
}

void getterminput(){
	while(getinput){
		printf(">");
		scanf("%s",&input);
		lexAnalysis();
	}
}

void lexAnalysis(){
	if (strcmp(input,"exit") == 0){
		getinput = 0;
		
	}else if (strcmp(input,"ver")){
		/* code */
	}
}

void parse(){
	
}