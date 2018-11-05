%{
    #include<stdio.h>
    int valid=1;
%}

%token num
%%
S : E '\n'      { printf("Result is  %d\n", $$); }
    ;
E :  E '+' E {$$ = $1 + $3;  }
        |E '-' E {$$ = $1 - $3 ;}
        |T    { $$ =$1 ; }
      ;
T : T '*' T { $$ = $1 * $3;}
  | T '/' T  { $$ = $1 / $3;}
  | F         { $$ = $1;}
  ;
F : num   {$$ = $1;}

%%
int yyerror()
{
    valid=0;
    printf("\nInvalid expression!\n");
    return 0;
}

int main()
{
    printf("\nEnter the expression:\n");
    yyparse();
    printf("\nHey hey hey\n" );
    if(valid)
    {
        printf("\nValid expression!\n");
    }
}
