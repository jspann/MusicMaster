//
//  start.h
//  
//
//  Created by James Spann on 3/15/15.
//
//

#ifndef _start_h
#define _start_h

char* tokenStrings[] = {"/","keyword","identity","constant","string literal","(",")","{","}",";",",","=","==","+","++","-","--","*","&&","||","\\n"};

enum tokenType{

	TK_DIV, // / 0
	TK_KEYWORD, // number will be place in array
	TK_IDEN, // function or variable - string will be placed in array
	TK_CONST, // any number
	TK_STRING,//string literal
	TK_LPAREN, // ( 5
	TK_RPAREN, // )
	TK_LBRACKET, // {
	TK_RBRACKET, // }
	TK_SEMICOLON, // ;
	TK_COMMA, // , 10
	TK_ASSIGN, // =
	TK_EQUAL, // ==
	TK_ADD, // +
	TK_INC, // ++
	TK_SUB, // - 15
	TK_DEC, // --
	TK_MULT,
	TK_AND, // &&
	TK_OR, // ||
	TK_NEWL // \n
};

union TokenValue{
   int i;
   //float f;
   //char* str;
   char str[12];
};

typedef struct {
	enum tokenType mytype;
	union TokenValue myvalue;
	/*int (*open)(void *self, char *fspec);
	int (*close)(void *self);
	int (*read)(void *self, void *buff, size_t max_sz, size_t *p_act_sz);
	int (*write)(void *self, void *buff, size_t max_sz, size_t *p_act_sz);*/
	// And data goes here.

} token;

token totalTokens[1000];

void matchTokens(enum tokenType u);
enum tokenType nextToken();
#endif
