%option noyywrap 
%{
#include <stdio.h>
#include "header.h" 
int linenumber;
int IDcount = 0;
symtab * lookup();
symtab * ptr;
void     insertID();
void 	 printSymTab();
void     printIdFrequency();
/* You need to define for all tokens in C--, here are some examples */
#define INT		10
#define FLOAT 		11 
#define OP_ASSIGN 	12 
#define OP_OR 		13 
#define MK_LPAREN 	14 
#define MK_RPAREN 	15 
#define RETURN      16
#define TYPEDEF     17
#define IF          18
#define ELSE        19
#define FOR         20 
#define VOID        21
#define WHILE       22
#define OP_PLUS     23
#define OP_MINUS    24
#define OP_MUL      25
#define OP_DIV      26
#define OP_GT       27 
#define OP_LT       28
#define OP_GEQ      29
#define OP_LEQ      30
#define OP_EQ       31
#define OP_NEQ      32
#define OP_AND      33
#define NOT         34
#define ERROR 		100 

%}

letter   [A-Za-z]
digit    [0-9]
ID	 {letter}({letter}|{digit}|"_")*
WS	 [ \t]+
Int_constant {digit}+

/* You need to define the following RE's */
Float_constant   [0-9]+"."[0-9]+
String_constant  \"(([^\"]|\\\")*[^\\])?\"
comment          "/*"([^*]|\*+[^*/])*\*+"/"

/* Reserved word */
RWInt  "int"
RWFloat "float"
return  "return"
typedef "typedef"
if      "if"
else    "else"
for     "for"
while   "while"
void    "void" 


OP_assign        "="
OP_or   "||"
OP_and  "&&"
OP_not  "!"
OP_plus   "+"
OP_minus  "-"
OP_mul    "*"
OP_div    "/"
OP_gt     ">"
OP_geq    ">="
OP_lt     "<"
OP_leq    "<="
OP_neq    "!="
OP_eq     "=="
 


/* Other operators appear here */ 


newline  "\n"

DL_lparen "("
DL_rparen ")"
DL_lbrace "{"
DL_rbrace "}"
DL_comma  ","
DL_semicol ";"
DL_dot  "."

/* Other separators appear here */

error    .

%%

{comment}       {ECHO; printf("\n");}
{WS}            {}
{RWInt}         {/* return INT; */ }
{RWFloat}       {/* return FLOAT; */}
{return}        {}
{typedef}
{if}
{else}
{for}
{while}
{void}
{Float_constant}  {}
{Int_constant}    {}
{String_constant} {}
{ID}            { 
			ptr = lookup(yytext);
			if (ptr == NULL){
			     insertID(yytext);
                 IDcount ++;
            }	
			else 
			     ptr->counter++;
		}

{OP_assign}     /* return OP_ASSIGN; */ 
{OP_plus}         {}
{OP_minus}        {}
{OP_mul}          {}
{OP_div}          {}
{OP_gt}
{OP_geq}
{OP_lt}
{OP_leq}
{OP_neq}
{OP_eq}
{OP_or}         /* return OP_OR; */
{OP_and}
{OP_not}
{DL_lparen}     /* return MK_LPAREN; */
{DL_rparen}     /* return MK_RPAREN; */
{DL_lbrace}     /* return MK_LBRACE; */
{DL_rbrace}     /* return MK_RBRACE; */
{DL_comma}      {}
{DL_semicol}    {}
{newline}       linenumber += 1;
{error}         printf("ERR: unrecognized token %s\n", yytext); exit(0);/* return ERROR; */

%%

int main(int argc, char **argv)
{
    argc--; ++argv;
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;
    yylex();
    printIdFrequency();
}

