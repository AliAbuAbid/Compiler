%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"

typedef enum {false,true} bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;


	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * length;
	}Varaiable;

    typedef struct Function 
	{
        char * name;
		struct Varaiables * arguments;
        char *returnType; 
		int argNum;
		bool findreturn;
    } Function;

		typedef struct SCOPE
	{	
		char *name;
		Varaiable * var;
		int VarCount;
		int Fcount;
		Function ** func;
		struct SCOPE * nextScope;
		struct SCOPE * preScope;
	}SCOPE;
	//part 1
	int yylex();
	int yyerror(char *e);
	
	//part 2
	static int scope=0;
	SCOPE* mkScope(char *);
	SCOPE* finScope(SCOPE * scopes);
	SCOPE* globalScope=NULL;
	void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE*);
	void addVar(Varaiable * arguments,int,int,SCOPE * MYscope);
	void syntaxAnalyzer(node *tree,SCOPE * scope);
	void pushScopes(SCOPE* from,char*);
	char* getExpType(node *,SCOPE*);
	char* findFuncInScopes(node * tree,SCOPE * MYscope);
	char* findVar(node * tree,SCOPE * MYscope);
	node* mkNode(char* token, node *left, node *right);
	Varaiable* mkArguments(node *,int *);
	Varaiable* callFuncArguments(SCOPE *,node *tree,int * count);
	/////////////////////////////
	void printTree(node *tree);
	void printtree(node *tree, int level, int linebreak);
	char* concat(char* s1, char* s2);
	void print_tree (node *tree, int tab);
	void printTabs(int n);
	void printTabsOnce(int n);
	void pausex();
	void unpause();
	void printNewline();
	int streq(char* s1, char* s2);
	int isType(char* t);
	int isOperator(char* t);
	int openParenthesis = 0;
	int pauselevel = 0;
	int hadOperator = 0;
	int currentTab = 0;
	////////////////////
	void generate_three_address_code(node* tree);
	
%}
%union
{
    struct node *node;
    char *string;
}



%token <string> COMMENT WHILE IF ELSE FOR DO VAR ARGS 
%token <string> RETURN
%token <string> BOOL STRING CHARPTR CHAR INT INTPTR PROCEDUR
%token <string> AND ADDRESS EQ ASSINGMENT OR LENGTH GT GTE LTE LT NOTEQ NOT
%token <string> DIVISION PLUS MINUS STAR VARIABLE
%token <string> STR_VAL REAL_VAL CHAR_VAL NULLL
%token <string> MAIN ID SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token <string> DEC_VAL HEX_VAL BTRUE BFALSE  REAL REALPTR FUNCTION COLON  DEREFRENCE  ARG_ARROW
%token <string>	QUOTE DOUBLE_QUOTES BEGIN_COMMENT END_COMMENT VOID

%left NOTEQ LT LTE GTE GT OR AND EQ
%left PLUS MINUS RETURN
%left STAR DIVISION
%left SEMICOLON ASSINGMENT 
%right NOT RBRACE

%nonassoc ID
%nonassoc LPAREN
%nonassoc IF
%nonassoc ELSE 


%type <node> address_expr stmnts stmnt_block derefrence_expr expr_list call_func 
%type <node> expr lhs assmnt_stmnt new_block 
%type <node> stmnt type_pro type_id var_id declear paren_expr
%type <node> pro_body para_list para_pro procedure procedures
%type <node> main program project declares for_declars
%%
 
project: program { syntaxAnalyzer($1,globalScope),generate_three_address_code($1); }; 

program: procedures main{$$=mkNode("CODE",$1,$2);}
;

main: FUNCTION MAIN LPAREN RPAREN COLON VOID LBRACE pro_body RBRACE
{
	$$=mkNode("main",mkNode("\n\t\tARGS None\n\t\tRET VOID\n\t\t",NULL,$8),NULL);
} 

procedures: procedures procedure {$$=mkNode("",$1,$2);}
	| {$$=NULL;};


procedure: FUNCTION ID LPAREN para_pro RPAREN COLON type_pro LBRACE pro_body RBRACE
{ 
		$$=mkNode("FUNC",mkNode($2,mkNode(" ",NULL,NULL),mkNode("\n\t\t(ARGS\n\t\t\t(",$4,mkNode(")\n\t\t(Return",$7,NULL))),mkNode(")",$9,NULL));

}

| PROCEDUR ID LPAREN para_pro RPAREN COLON VOID  LBRACE  pro_body RBRACE
{
	$$=mkNode("FUNC  ",mkNode($2,mkNode("",NULL,NULL),NULL),mkNode("\n\t\t(ARGS\n",$4,$9));
};


para_pro: para_list {$$=$1;}
| {$$=NULL;};



para_list: ARGS ARG_ARROW var_id COLON type_id {$$=mkNode("(",$5,mkNode("",$3,mkNode(")",NULL,NULL)));}
	|  para_list SEMICOLON para_list {$$=mkNode("",$1,mkNode("",$3,NULL));}	;

pro_body:  procedures declares stmnts 
{
	$$=mkNode("\n\t\t(BODY\n\t\t", mkNode(" ",$1,NULL),mkNode(" ",$2,mkNode(" ",$3,mkNode(" ",NULL,NULL))));
};


declares: declares declear  {$$=mkNode("",$1,$2);} | {$$=NULL;}  ;

declear: VAR var_id COLON type_id SEMICOLON 
{
	$$=mkNode("var", $4,$2);
};

var_id: ID COMMA var_id {$$=mkNode($1, mkNode(" ", $3, NULL),NULL);}
	| ID {$$=mkNode($1, NULL, NULL);} ;


type_id: BOOL {$$=mkNode("bool", NULL, NULL);}
	| STRING LBRACKET DEC_VAL RBRACKET {$$=mkNode("string", mkNode("[",mkNode("$3",NULL,NULL),NULL), NULL);}
	| CHAR {$$=mkNode("char", NULL, NULL);}
	| INT {$$=mkNode("int", NULL, NULL);}
	| REAL {$$=mkNode("real", NULL, NULL);}
	| INTPTR {$$=mkNode("int*", NULL, NULL);}
	| CHARPTR {$$=mkNode("char*", NULL, NULL);}
	| STRING {$$=mkNode("string",NULL,NULL);}
	| REALPTR {$$=mkNode("real*", NULL, NULL);};


type_pro: BOOL {$$=mkNode("bool", NULL, NULL);}
 	| STRING {$$=mkNode("string", NULL, NULL);}
	| CHAR {$$=mkNode("char", NULL, NULL);}
	| INT {$$=mkNode("int", NULL, NULL);}
	| REAL {$$=mkNode("real", NULL, NULL);}
	| VOID {$$=mkNode("void", NULL, NULL);}
	| INTPTR {$$=mkNode("int*", NULL, NULL);}
	| CHARPTR {$$=mkNode("char*", NULL, NULL);}
	| REALPTR {$$=mkNode("real*", NULL, NULL);};
	
stmnts: stmnts stmnt {$$=mkNode("",$1,$2);} | {$$=NULL;};

stmnt_block: stmnt {$$=$1;}|declear {$$=$1;}|procedure {$$=$1;} |SEMICOLON  {$$=mkNode("",NULL,NULL);};

new_block: LBRACE procedures declares stmnts RBRACE 
{
	$$=mkNode("{",$2,mkNode("", $4,mkNode("", $4,("}",NULL,NULL))));
};



stmnt: IF LPAREN expr RPAREN  stmnt_block 
{
	$$=mkNode("if",
	mkNode("(", $3, 
	mkNode(")",NULL,NULL)),$5);
}%prec IF
| IF LPAREN expr RPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mkNode("if-else",
	mkNode("", $3, 
	mkNode("",NULL,NULL)),
	mkNode("",$5,
	mkNode("",$7,NULL)));
}
| WHILE LPAREN expr RPAREN  stmnt_block  
{
	$$=mkNode("while",
	mkNode("(", $3, 
	mkNode(")",NULL,NULL)),$5);
}
| FOR LPAREN for_declars SEMICOLON expr SEMICOLON  assmnt_stmnt RPAREN stmnt_block 
{
		$$= mkNode("for",
			mkNode("(",
			mkNode("",$3,$5),
			mkNode("",$7,
			mkNode(")",NULL,NULL))),$9);		
}
| assmnt_stmnt SEMICOLON {$$=mkNode("",$1,NULL);}
| expr SEMICOLON  {$$=$1;}
| RETURN expr SEMICOLON {$$=mkNode("return",$2,NULL);}
| new_block {$$=$1;};

for_declars: VAR var_id COLON type_id{$$=mkNode("var",$4,$2);}
			| lhs ASSINGMENT expr {$$=mkNode("=",$1,$3);}
			| {$$=NULL;}




assmnt_stmnt: lhs ASSINGMENT expr 
{
	$$=mkNode("=",$1,$3);
};

lhs: ID LBRACKET expr RBRACKET 
{
	$$=mkNode($1, mkNode("[",$3,mkNode("]",NULL,NULL)), NULL);
} 
| ID {$$=mkNode($1,NULL,NULL);}
| address_expr {$$=$1;}
| derefrence_expr{$$=$1;} ;

expr:  LPAREN expr RPAREN {$$=mkNode("(",$2,mkNode(")",NULL,NULL));}|
//bool oper
    expr EQ expr {$$=mkNode("==",$1,$3);}
	| expr NOTEQ expr {$$=mkNode("!=",$1,$3);}
	| expr GTE expr {$$=mkNode(">=",$1,$3);}
	| expr GT expr {$$=mkNode(">",$1,$3);}
	| expr LTE expr {$$=mkNode("<=",$1,$3);}
	| expr LT expr {$$=mkNode("<",$1,$3);}
	| expr AND expr {$$=mkNode("&&",$1,$3);}
	| expr OR expr {$$=mkNode("||",$1,$3);}
//aritmetical operator
	| expr PLUS expr {$$=mkNode("+",$1,$3);}
	| expr MINUS expr {$$=mkNode("-",$1,$3);}
	| expr STAR expr {$$=mkNode("*",$1,$3);}
	| expr DIVISION expr {$$=mkNode("/",$1,$3);}
//not operator
	| NOT expr {$$=mkNode("!",$2,NULL);}
	| address_expr {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func {$$=$1;}
	| DEC_VAL {$$=mkNode($1,mkNode("INT",NULL,NULL),NULL);}
	| CHAR_VAL {$$=mkNode($1,mkNode("CHAR", NULL, NULL),NULL);}
	| REAL_VAL {$$=mkNode($1,mkNode("REAL", NULL, NULL),NULL);}
	| STR_VAL {$$=mkNode($1,mkNode("STRING", NULL, NULL),NULL);}
	| BFALSE {$$=mkNode($1,mkNode("BOOL", NULL, NULL),NULL);}
	| BTRUE {$$=mkNode($1,mkNode("BOOL", NULL, NULL),NULL);}
	| LENGTH ID LENGTH 
	{
		$$=mkNode("|",
		mkNode($2,NULL,NULL),
		mkNode("|",NULL,NULL));
	}
	| ID LBRACKET expr RBRACKET 
	{$$=mkNode("var",mkNode($1,mkNode("[",$3,mkNode("]",NULL,NULL)),NULL),NULL);}
	| ID {$$=mkNode(" var",mkNode($1,NULL,NULL),NULL);}
	| NULLL {$$=mkNode("null",NULL,NULL);}

address_expr: ADDRESS ID {$$=mkNode("&",mkNode($2,NULL,NULL),NULL);}
	| ADDRESS LPAREN ID RPAREN {$$=mkNode("&",mkNode("(",mkNode($3,NULL,NULL),NULL),mkNode(")",NULL,NULL));}
	| ADDRESS ID LBRACKET expr RBRACKET 
	{$$=mkNode("&", mkNode($2,mkNode("[",$4,mkNode("]",NULL,NULL)),NULL),NULL);}
	| ADDRESS LPAREN ID LBRACKET expr RBRACKET RPAREN 
	{
		$$=mkNode("&",
		mkNode("(", 
		mkNode($3,mkNode("[",$5,mkNode("]",NULL,NULL)),NULL)
		,mkNode(")",NULL,NULL)),NULL);
	};

	derefrence_expr: DEREFRENCE ID {$$=mkNode("^",mkNode($2,NULL,NULL),NULL);}
	| DEREFRENCE LPAREN expr RPAREN {$$=mkNode("^",mkNode("(",$3,NULL),mkNode(")",NULL,NULL));}
	| DEREFRENCE ID LBRACKET expr RBRACKET 
	{$$=mkNode($1, mkNode($2,mkNode("[",$4,mkNode("]",NULL,NULL)),NULL), NULL);};

expr_list: expr COMMA expr_list {$$=mkNode("",$1,mkNode(",",$3,NULL));} 
	| expr {$$=mkNode("",$1,NULL);}
	| {$$=NULL;};

paren_expr:LPAREN expr_list RPAREN {$$=$2;};
call_func: ID paren_expr {$$=mkNode("Call func",mkNode($1,NULL,NULL),mkNode("ARGS",$2,NULL));} ;
%%



int main()
{
	int res = yyparse();
	if(res==0)
		printf("\nThe Syntax and Semantics Are Valid\n");
		//printtree(tree,0,0); 
	return res;	
}


///////////////////////////////////////////////////////////////////////////


void addVar(Varaiable * arguments,int countvars,int isArg,SCOPE * MYscope){
	if(countvars==0)
	return;
	Varaiable* tmp;
	SCOPE * scopes=MYscope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("There is the same var %s in one declare",arguments[i].name);
		SCOPE * t=scopes->preScope;
		while(t->preScope!=NULL && t->preScope->Fcount==0)
			t=t->preScope;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->Fcount-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(scopes->var==NULL)
	{ 
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		tmp=scopes->var;
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*(scopes->VarCount+countvars));
		for(int i=0;i<scopes->VarCount;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(tmp[i].name,arguments[j].name)==0 )
				{
					printf("There can't be the same var %s in same scope",tmp[i].name);
					SCOPE * t=scopes->preScope;
					while(t->preScope!=NULL && t->preScope->Fcount==0)
						t=t->preScope;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->Fcount-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			scopes->var[i]=tmp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		scopes->var[scopes->VarCount].name=arguments[j].name;
		scopes->var[scopes->VarCount].value=NULL;
		scopes->var[scopes->VarCount].isArg=isArg;
		scopes->var[scopes->VarCount].length=arguments[j].length;
		scopes->var[(scopes->VarCount)++].type=arguments[j].type;
	}

}


char * getExpType(node * tree,SCOPE* MYscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
	
		if(strcmp(tree->left->token,"BOOL")==0)
			msg= "bool";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(getExpType(tree->left,MYscope),"bool")==0)
			msg="bool";
		else{
			printf("ERROR, you can use operator ! only on bool type");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(getExpType(tree->left,MYscope),"string")==0)
		msg="int";
		else{
			printf("ERROR, you can use operator | only on string type in the function %s",globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"string")!=0)
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{

			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"bool")==0)
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
			

		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}

			if(strcmp(getExpType(tree->right,MYscope),"int")==0&&(strcmp(getExpType(tree->left,MYscope),"char*")==0||strcmp(getExpType(tree->right,MYscope),"int*")==0||strcmp(getExpType(tree->right,MYscope),"real*")==0)){
				msg=getExpType(tree->left,MYscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}

		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else{
				msg=getExpType(tree->left,MYscope);
				
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else
				msg=getExpType(tree->left,MYscope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}

		}
		if(strcmp(tree->token,"(")==0)
			msg=getExpType(tree->left,MYscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findFuncInScopes(tree,MYscope);
		
	}
	if(strcmp(msg,"")==0)
		msg=findVar(tree,MYscope);

	
	

	return msg;
}

SCOPE* mkScope(char* name)
{	
	SCOPE *newScope = (SCOPE*)malloc(sizeof(SCOPE));
	newScope->name=name;
	newScope->var=NULL;
	newScope->VarCount=0;
	newScope->func=NULL;
	newScope->Fcount=0;
	newScope->nextScope=NULL;
	newScope->preScope=NULL;
	return newScope;
}


void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE * MYscope){
	Function** tmp;
	SCOPE * scopes = MYscope;
	for(int i=0;i<argNum;i++)
		for(int j=0;j<argNum;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("ERROR, there are identicles arguments %s in func %s\n",arguments[i].name,name);
		exit(1);
	}
	if(scopes->func==NULL)
	{ 
		scopes->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		tmp=scopes->func;
		scopes->func=(Function**) malloc(sizeof(Function*)*(scopes->Fcount+1));
		for(int i=0;i<scopes->Fcount;i++)
		{
				if(strcmp(tmp[i]->name,name)==0 )
				{
					printf("ERROR, there's already function %s in same scope \n",tmp[i]->name);
					exit(1);
				}
				scopes->func[i]=tmp[i];
		}
	}
		scopes->func[scopes->Fcount]=(Function*) malloc(sizeof(Function));
		scopes->func[scopes->Fcount]->name=name;
		scopes->func[scopes->Fcount]->arguments=arguments;
		if(returnType==NULL)
		scopes->func[scopes->Fcount]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type function %s can't be string\n",name);
				exit(1);
			}
		scopes->func[scopes->Fcount]->returnType=returnType->token;
		}
		scopes->func[scopes->Fcount]->argNum=argNum;
		scopes->func[scopes->Fcount]->findreturn=false;
		++(scopes->Fcount); 

}


/* allocation for node*/
node* mkNode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

int yyerror(char *e)
{
	int yydebug=1;
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "Does not accept '%s'\n",yytext);
	
	return 0;
}

SCOPE* finScope(SCOPE * scopes)
{
	SCOPE * MYscope=scopes;
	if(MYscope!=NULL)
	while(MYscope->nextScope!=NULL)
		MYscope=MYscope->nextScope;
	return MYscope;
}


void syntaxAnalyzer(node *tree,SCOPE * MYscope){
	int flagGalit=0;
	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(getExpType(tree->right,MYscope),"NULL")==0&& (strcmp(getExpType(tree->left,MYscope),"real*")==0||strcmp(getExpType(tree->left,MYscope),"int*")==0||strcmp(getExpType(tree->left,MYscope),"char*")==0)))
		if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))!=0 && (strcmp(getExpType(tree->left,MYscope),"int")!=0) && strcmp(getExpType(tree->right,MYscope),"real")!=0 &&(strcmp(getExpType(tree->left,MYscope),"real")!=0) && strcmp(getExpType(tree->right,MYscope),"int")!=0)
		{
			printf("ERORR, you can't do = between %s and %s in scope %s in the function %s\n",getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int VarCount=0;
		Varaiable * var=mkArguments(tree,&VarCount);
		addVar(var,VarCount,0,MYscope);
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in if statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in while statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{

	 if(strcmp(getExpType(tree->left->left->right,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in for statement has to be boolean\n");
			exit(1);
		}

		syntaxAnalyzer(tree->left->left->left,MYscope);

		syntaxAnalyzer(tree->left->right->left,MYscope);

		if(strcmp(tree->right->token,"{")!=0)
		{

			pushScopes(MYscope,tree->token);

			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}

		
		
	}
	else if(strcmp(tree->token, "FUNC") == 0)
	{
        int count=0;
		Varaiable * arg=mkArguments(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));

	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		if(MYscope->func[MYscope->Fcount-1]->findreturn==false)
		{
			//printf("ERORR, there is no Return in func %s\n",tree->left->token); 
			//exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
		
        int count=0;
		Varaiable * arg=mkArguments(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		scope--;	
		return;
    }


	else if(strcmp(tree->token, "Call func") == 0)
	{
		findFuncInScopes(tree,MYscope);
		//printf("(%s \n",tree->token);
		
		
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
		pushScopes(NULL,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,globalScope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,globalScope);
		scope--;
		return;
	}

    else if(strcmp(tree->token, "main") == 0)
	{
		addFunc(tree->token,NULL,NULL,0,MYscope);
		pushScopes(MYscope,tree->token);

	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;
               
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERORR, if condition must be of type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->left,finScope( MYscope->nextScope));
			scope--;
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->right->left,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
	}

	else if(strcmp(tree->token, "return") == 0)
	{
		SCOPE * tmp= MYscope;
		int flag=true;
		while(strcmp(tmp->name,"FUNC")!=0&&strcmp(tmp->name,"PROC")!=0&&strcmp(tmp->name,"CODE")!=0)
		{
			tmp=tmp->preScope;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
			{
			printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			exit(1);
			}
		}
		else
		{
			if (strcmp(tmp->preScope->func[tmp->preScope->Fcount-1]->returnType, "void")==0) 
				flagGalit=1;
			if(tmp->preScope->func[tmp->preScope->Fcount-1]->returnType!=NULL && flagGalit==0)
			{
				if(0==strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
				{
					tmp->preScope->func[tmp->preScope->Fcount-1]->findreturn=true;
				}
				else // Galit's Change
				{
					printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR, there can't be return in function '%s', because it's void type\n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
				exit(1);
			}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    pushScopes(MYscope,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;			
	}
	else if(strcmp(tree->token, " var") == 0 )
	{
		findVar(tree->left,MYscope);
	}
	if (tree->left) 
		syntaxAnalyzer(tree->left,MYscope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,MYscope);
}


void pushScopes(SCOPE* from,char* name)
{
	SCOPE * point;
	if(globalScope==NULL)
		globalScope=mkScope(name);
	else{
	point=globalScope;
	while(point->nextScope!=NULL)
		point=point->nextScope;
	point->nextScope=mkScope(name);
	point->nextScope->preScope=from;
	}
}

char* findFuncInScopes(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp=MYscope;
	Varaiable* arguments;
	bool find = false, flag = true;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->Fcount;i++)
		if(strcmp(tree->left->token,tmp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			arguments=callFuncArguments(MYscope,tree->right->left,&count);
			if(count==tmp->func[i]->argNum)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(arguments[j].type,tmp->func[i]->arguments[t].type)!=0)
						flag=false;
				}
				if(flag==true)
					return tmp->func[i]->returnType;
			}
		}
		tmp=tmp->preScope;
	}
	printf("ERROR,func %s not find call in scope %s in the function %s\n",tree->left->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	if(find==true)
		printf("There is a function with the same name that accepts different arguments\n");
		exit(1);
}

char *findVar(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp = MYscope;
	if(strcmp(tree->token," var")==0)
		tree=tree->left;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->VarCount;i++)
		if(strcmp(tree->token,tmp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(tmp->var[i].type,"string")==0 )
					if(strcmp(getExpType(tree->left->left,MYscope),"int")==0)
					{
							return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in the function %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) or any poiner type in scope %s in the function %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
					exit(1);
				}

			}
			else
			return tmp->var[i].type;

		}
		tmp=tmp->preScope;
	}
	printf("ERORR, var %s wasn't found in scope %s in the function %s\n ",tree->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	exit(1);	
}

Varaiable * mkArguments(node *tree,int *count){
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	if(tree!=NULL)
	{
		node * temp1=tree,*tmp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			tmp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
			{
				type=tmp->left->token;
				if(tmp->left->left!=NULL)
					length=tmp->left->left->left->token;
				node * tmptree;
				tmptree=tmp->right->left;
				do{
				arr2[*count].name=tmptree->token;
				arr2[*count].type=type;
				arr2[*count].length=length;
				(*count)++;
				if(tmptree->left==NULL)
					tmptree=NULL;
				else
					tmptree=tmptree->left->left;
				}while(tmptree!=NULL);
			}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(tmp->token, "var")!=0);
		tmp=temp1;
		if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
		{
			type=tmp->left->token;
			node * tmptree;
			if(strcmp(tmp->token, "var")==0)
			tmptree=tmp->right;
			else
			tmptree=tmp->right->left;
			if(tmp->left->left!=NULL)
			length=tmp->left->left->left->token;
			do{
			arr2[*count].name=tmptree->token;
			arr2[*count].type=type;
			arr2[*count].length=length;
			(*count)++;
			if(tmptree->left==NULL)
				tmptree=NULL;
			else
				tmptree=tmptree->left->left;
			}while(tmptree!=NULL);
		}
		arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=arr2[i].name;
			arr[i].type=arr2[i].type;
		}
	}
	return arr;
}


Varaiable* callFuncArguments(SCOPE * MYscope,node *tree,int * count)
{
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	while(tree!=NULL)
	{
		arr2[(*count)++].type=getExpType(tree->left,MYscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
	for(int i = 0; i<*count; i++)
		arr[i].type=arr2[i].type;
	return arr;
}

void printtree(node* tree, int level, int linebreak) {
	char* t = tree->token;
	char* argss=(char*)malloc(sizeof(tree->left));
	struct node* left = tree->left;
	struct node* right = tree->right;

	char* r;

	char* l;
	
	if (left) {
		l = tree->left->token;
		
	}


	if (right)
	 r = tree->right->token;
	 
	


	int lvl = level;

	int closeParen = 0;

	int newline = 0;

	int tabs = 0;

	int leftBreak = 0;

	int rightBreak = 0;

	int pauseLeft = 0;

	int pauseRight = 0;

	int printTabsLeft = 0;

	int unpaus = 1;



	if (streq(t, "") ||

		streq(t, "\n") ||

		streq(t, " ") ||

		streq(t, "}")) {

		if (streq(t, "\n")) {

			printNewline();

			printTabsOnce(level);

		}

		unpaus = 0;

	} else {

		if (streq(t, ")") && openParenthesis == 0);

		else {

			if (currentTab == 0)

				printTabs(level);

		}

		lvl++;

		if (streq(t, "(")) {

			if (streq(r, ")") && streq(l, "")) {

				printNewline();

				printTabs(level);

				printf("(");

				openParenthesis++;

			}

			pauseLeft = 1;

			pauseRight = 1;

			lvl--;

		} else if (streq(t, ")")) {

			if (openParenthesis > 0) {

				printf("%s", t);

				printNewline();

				newline = 1;

				openParenthesis--;

			}

		} else if (streq(t, "FUNC") || streq(t, "CODE ")) {
            
			printf("(%s", t);

			printNewline();

			closeParen = 1;

			newline = 1;

			leftBreak = 1;

			tabs = 1;

			unpause();

		} else if (streq(t, "Call-func")) {

			if (hadOperator) {

				printNewline();

				printTabsOnce(level);

			}

			printf("(%s", t);

			printNewline();

			closeParen = 1;

			newline = 1;

			leftBreak = 1;

			tabs = 1;

			unpause();

			hadOperator = 1;

		} else if (streq(t, "args")) {

			printf("(ARGS");

			newline = 1;

			closeParen = 1;

			if (left) {

				tabs = 1;

				printNewline();

				pauseRight = 1;

				pauseLeft = 1;

				printTabs(level+1);

			} else {

				printf(" NONE");

			}

		} else if (streq(t, "type ")) {

			printf("(TYPE ");

			closeParen = 1;

			newline = 1;

			pauseLeft = 1;

		} else if (streq(t, "body ")) {

			printf("\n\t\t(BODY");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "return")) {

			printf("\t(RET ");

			closeParen = 1;

			pauseLeft = 1;

			newline = 1;

			if (left && isOperator(l)) tabs = 1;

		} else if (streq(t, "var") || streq(t, "string")) {
            
			printf("(DECLARE ");

			closeParen = 1;

			newline = 1;

			pauseLeft = 1;

			pauseRight = 1;

		} else if (streq(t, "if")){

			printf("(IF ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "if-else")){

			printf("(IF-ELSE ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "while")){
            

			printf("(WHILE ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "do")){

			printf("(DO");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "for")){

			printf("(FOR");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "{")) {

			printf("(BLOCK");

			printNewline();

			closeParen = 1;

			newline = 1;

			tabs = 1;

		} else if (isType(t)) {

			printf("%s", t);

			unpaus = 0;

		} else if (streq(t, "=")) {

			printf("(=");

			pauseLeft = 1;

			pauseRight = 1;

			closeParen = 1;

			newline = 1;

			hadOperator = 0;

		} else if (isOperator(t)) {

			printNewline();

			unpause();

			hadOperator = 1;

			printTabs(level);

			printf("(%s", t);

			if (streq(t, "!")) tabs = 1;

			closeParen = 1;

			pauseLeft = 1;

			newline = 1;

			if (right) {

				if (streq(r, "Call func")) {

					leftBreak = 1;

					printNewline();

					currentTab = 0;

					printTabsLeft = 1;

				} else {

					rightBreak = 1;

				}

				tabs = 1;

			}

			if (left && right) {

				rightBreak = 1;

				newline = 1;

			}

		} else if (streq(t, "]\n")) {

			printf("%s", t);

			printTabsOnce(level);

		} else if (streq(t, "TRUE ") || streq(t, "FALSE ")) {

			printf("%s", t);

			printNewline();

		} else {

			printf(" %s", t);

			unpaus = 0;

			if (linebreak) printNewline();

			--lvl;

		}

	}

	if (left) {

		if (printTabsLeft) { printTabsOnce(lvl); }

		if (pauseLeft) pausex();

		printtree(left, lvl, leftBreak);

	}

	if (right) {

		if (pauseRight) pausex();

		printtree(right, lvl, rightBreak);

	}

	if (currentTab == 0 && (tabs || (hadOperator && streq(t, "=")))) {

		if (streq(t, "args ") && !hadOperator);

		else {

			printTabsOnce(level);

			if (streq(t,"=")) hadOperator = 0;

		}

	}

	if (closeParen) { printf(")"); }

	if (newline) { printNewline(); }

	if (unpaus) { unpause(); }

}


char* concat(char* s1, char* s2) {

	int len1 = strlen(s1);

	int len2 = strlen(s2);

	int len = len1 + len2;

	char* newstr = (char*)malloc(sizeof(char)*len + 1);

	int j = 0;

	for (int i = 0; i < len1; ++i) {

		newstr[j++] = s1[i];

	}

	for (int i = 0; i < len2; ++i) {

		newstr[j++] = s2[i];

	}
	

	newstr[j] = '\0';

	return newstr;

}



void printNewline() {

	printf("\n");

	currentTab = 0;

}



void printTabs(int n)

{

	if (pauselevel)

		return;

	for(int i = 0; i < n; ++i) {

		currentTab++;

		printf("\t");

	}

}



void printTabsOnce(int n) {

	int temp = pauselevel;

	unpause();

	printTabs(n);

	pauselevel = temp;

}



void pausex() {

	pauselevel = 1;

}



void unpause() {

	pauselevel = 0;

}



int streq(char* s1, char* s2) {

	return strcmp(s1, s2) == 0;

}



int isType(char* t) {

	return  streq(t, "BOOL ") ||

			streq(t, "INT ") ||

			streq(t, "CHAR ") ||

			streq(t, "REAL ") ||

			streq(t, "VOID ") ||

			streq(t, "INT* ") ||

			streq(t, "CHAR* ") ||

			streq(t, "REAL* ");

}



int isOperator(char* t) {

	return streq(t, ">") ||

		   streq(t, "<") ||

		   streq(t, ">=") ||

		   streq(t, "<=") ||

		   streq(t, "==") ||

		   streq(t, "!=") ||

		   streq(t, "!") ||

		   streq(t, "||") ||

		   streq(t, "&&") ||

		   streq(t, "*") ||

		   streq(t, "/") ||

		   streq(t, "+") ||

		   streq(t, "-");

}


void printTree(node* tree) {


	printtree(tree,0,0);

}


//////////////////////////////////////////////////////
int l=1,t=0;


char* called;
char* operator;
int x=0;
void generate_three_address_code(node* tree){
	  if (tree == NULL){
	    return;
	  }
 	else if (strcmp(tree->token, "FUNC") == 0 || strcmp(tree->token,"main")==0)
    {	
		if(strcmp(tree->token,"main")==0)
			printf("main:");
        else {
			printf("%s:", tree->left->token);
		}
		printf("\n\tBeginFunc\n");
    }
	else if(strcmp(tree->token,"=")==0){
		if(strcmp(tree->right->token,"Call func")==0){
			if(strcmp(tree->right->right->left->left->token," var")==0){
				printf("\tt%d = %s\n",t,tree->right->right->left->left->left->token);
			}
			else{
	 			printf("\tt%d = %s\n",t,tree->right->right->left->left->token);
			}
			called=tree->left->token;

			printf("\tPushParams t%d\n",t);
			t++;
			
		}
		else{
				if(strcmp(tree->right->token,"+")==0||strcmp(tree->right->token,"-")==0||strcmp(tree->right->token,"*")==0||strcmp(tree->right->token,"/")==0){
					if(strcmp(tree->right->left->token," var")==0 && strcmp(tree->right->right->token," var")==0){

						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->token,tree->right->token,tree->right->right->left->token);
					}
					else if(strcmp(tree->right->left->token," var")==0 && !strcmp(tree->right->right->token," var")==0){
						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->token,tree->right->token,tree->right->right->token);
					}
					else if(!strcmp(tree->right->left->token," var")==0 && strcmp(tree->right->right->token," var")==0){
						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->left->token,tree->right->token,tree->right->right->left->token);
						
					}
					else{
						printf("\tt%d = %s %s %s\n",t,tree->right->left->token,tree->right->token,tree->right->right->token);
						
					}
			}
			else if(strcmp(tree->right->token," var")==0){
				printf("\tt%d = %s\n",t,tree->right->left->token);
			}
	 		else{
				 printf("\tt%d = %s\n",t,tree->right->token);
			}
			printf("\t%s = t%d\n",tree->left->token,t);
			t++;

		}
		
	}
	else if(strcmp(tree->token,"if")==0){
		if(strcmp(tree->left->left->token,"==")==0||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0 ||strcmp(tree->left->left->token,"<")==0){

			if(strcmp(tree->left->left->token,"==")==0 ||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0||strcmp(tree->left->left->token,"<")==0){
				x=l;
				if(strcmp(tree->left->left->right->token," var")==0){
					printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->left->token,l);
				}
				else{
					printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->token,l);
				}
			}
		}
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
	}
	else if(strcmp(tree->token,"else\t")==0){
			printf("\tgoto L%d\n",l+1);
			printf("L%d:   ",l);
			l++;
	}
	else if(strcmp(tree->token,"return")==0){
		if(strcmp(tree->left->token,"+")==0||strcmp(tree->left->token,"-")==0||strcmp(tree->left->token,"*")==0||strcmp(tree->left->token,"/")==0){
			printf("L%d:     t%d = %s %s %s\n",l,t,tree->left->left->left->token,tree->left->token,tree->left->right->left->token);
		}
		printf("\tReturn t%d\n\tEndFunc\n\n\n",t);
		l++;
		t++;
	}

	else if(strcmp(tree->token,"while")==0){
		printf("L%d:    ",l);
		l++;
		if(strcmp(tree->left->left->token,"==")==0 ||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0||strcmp(tree->left->left->token,"<")==0){
			x=l;
			if(strcmp(tree->left->left->right->token," var")==0){
				printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->left->token,l);
			}
			else{ 
				printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->token,l);
			}
		}
		
		
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
		
	}
	else if(strcmp(tree->token,"for")==0){
		printf("L%d:    ",l);
		l++;
			printf("\tif %s < %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->right->token,l);
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
	}
	else if(strcmp(tree->token,"Call func")==0){
		printf("\n\tt%d = LCall %s\n",t,tree->left->token);
		t++;
		printf("\tPopParams %d\n",t+1);
		printf("\t%s = t%d\n",called,t-1);

	}
	


        generate_three_address_code(tree->left);
        generate_three_address_code(tree->right);

}