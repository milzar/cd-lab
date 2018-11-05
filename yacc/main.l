%{
    #include <stdlib.h>
    #include "y.tab.h"
%}

%%

[0-9]+        { yylval = atoi(yytext);return num;}
[*-+]     {return *yytext;}
[\n]      return *yytext;
%%

int yywrap(){
  return 1;
}
