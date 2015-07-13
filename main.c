#include <stdio.h>
#include <stdbool.h>
#include "start.h"

bool getinput;
char *filename;
size_t myarray_size = 1000;
int tokensUsed = 0;
int tokenPointer;
FILE *fp;
char input[20];
char* keywords[] = {"var","pause"};
int lineCount = 1;

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
		printf("Version 1.0 by James Spann\n");
	}

	char ch;
	while (ch != EOF){
		ch = fgetc(fp);

		if (ch == '/'){
			if(expected('*')){
				char z;
				while(1){
					z = fgetc(fp);
					if ((z == '*') && (nextup() == '/')){
						z = fgetc(fp);//one more time to get past the hump
						break;
					}
				}
			}else if(expected('/')){
				char z;
				while(1){
					z = fgetc(fp);
					if (nextup() == '\n'){
						break;
					}
				}
			}else{
				//must be a division symbol
			}
		}else if (ch == '\"'){
			//build string buffer until next " with a nested for loop

			/*char strlit[30];
			strlit[0] = ch;
			int p = 1;
			while(1){

				if (!(nextup() == '\"')){
					char g = fgetc(fp);
					strlit[p] = g;
					p++;
				}else{
					break;
				}
			}*/
			//create string literal token
		}else if (isalpha(ch)){
			char mly[14];
			mly[0] = ch;
			int p = 1;

			while(1){
				if (isalpha(nextup())){
					char g = fgetc(fp);
					mly[p] = g;
					p++;
				}else{
					break;
				}
			}
			
			char tempStrArray[p+1];
			int me;
			for (me = 0; me < p; me++){
				tempStrArray[me] = mly[me];
			}
			tempStrArray[p] = '\0';

			char* tickle = tempStrArray;
			if (iskeyword(tempStrArray) == true){
				int t,z;
				for (t=0; t < (sizeof(keywords) / sizeof(keywords[0])); t++) {
					if (strcmp(tickle,keywords[t]) == 0){
						z=t;
					}
				}

				union TokenValue jk;
				jk.i = z;
				addToken(TK_KEYWORD,jk);
			}else{
				//identifier token
				union TokenValue jk;

				int q;
				for (q = 0; q < p+1; q++){
					jk.str[q] = tempStrArray[q];
				}
				
				addToken(TK_IDEN,jk);
			}
		}else if (isdigit(ch)){
			int c = ch-48;
			int nextly;
			while(1){
				if (isdigit(nextup())){
					nextly = fgetc(fp)-48;

					c = (c*10)+ nextly;
				}else{
					break;
				}
			}
			
			union TokenValue js;
			js.i = c;
			addToken(TK_CONST,js);
		}else if (ch == '\\'){
			//do something for escape sequences
		}else if (ch == '('){
			addblankToken(TK_LPAREN);
		}else if (ch == ')'){
			addblankToken(TK_RPAREN);
		}else if (ch == '{'){
			addblankToken(TK_LBRACKET);
		}else if (ch == '}'){
			addblankToken(TK_RBRACKET);
		}else if (ch == ';'){
			addblankToken(TK_SEMICOLON);
		}else if (ch == ','){
			//create token
		}else if (ch == '='){
			if (nextup() == '='){
				fgetc(fp);//to bounch out the second equal sign
				addblankToken(TK_EQUAL);
			}else{
				addblankToken(TK_ASSIGN);
			}
		}else if (ch == '+'){
			if (nextup() == '+'){
				fgetc(fp);
				addblankToken(TK_INC);
			}else{
				addblankToken(TK_ADD);
			}
		}else if (ch == '-'){
			if (nextup() == '-'){
				fgetc(fp);
				addblankToken(TK_SUB);
			}else{
				addblankToken(TK_DEC);
			}
		}else if (ch == '*'){
			//create * token
			addblankToken(TK_MULT);
		}else if (ch == '&'){
			if (nextup() == '&'){
				//create && token
				addblankToken(TK_AND);
			}else{
				//create & token
				printf("Bitwise operators are currently not supported\n");
			}
		}else if (ch == '|'){
			if (nextup() == '|'){
				//create || token
				addblankToken(TK_OR);
			}else{
				//create | token
				printf("Bitwise operators are currently not supported\n");
			}
		}else if (ch == '\n'){
			lineCount++;
			addblankToken(TK_NEWL);
		}else if(iswhitespace(ch)){
		}else if(ch == -1){
			//do nothing I guess. This is basically EOF
		}else{
			//compileError("Unknown character: \"%c\" on line %i",ch,lineCount);
			printf("Unknown character: \"%c\" on line %i",ch,lineCount);
			exit(0);
		}
	}
}



void parse(){
	
}