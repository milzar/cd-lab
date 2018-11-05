#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isKeyword(char *str){
          const char keywords[][30] = {
          "if",
          "else",
          "int",
          "float",
          "char",
          "double",
          "return",
          "break",
          "continue",
          "for",
          "while",
          "do",
          "const",
          "include"
        };

        for(int i=0;i<14;i++){
              if(strstr(str,keywords[i]))
                  return true;
        }
        return false;
}

bool isOperator(char *str){
    const char operators[][2] = {
                                "+",
                                "*",
                                "/",
                                "-",
                                "="
                              };
    for(int i=0;i<5;i++){
          if(strcmp( str,operators[i] ) ==0 )
              return true;
    }
    return false;
}

bool isDelimiter(char *str){
      const char delimiters[][2] = {
              ";",
              "{",
              "}"
      };
      for(int i=0;i<3;i++){
          if(strcmp(str,delimiters[i]) ==0)
              return true;
      }
      return false;
}
bool isIdentifier(char *str){
    if( isdigit(str[0])  )
        return false;
    else
        return true;

}
void identifyString(char *str){
      if(isKeyword(str)){
            printf("Keyword: \t %s\n",str );
      }
      else if(  isOperator(str) ){

            printf("Operator: \t %s\n",str );
      }
      else if(isDelimiter(str)){
              printf("Delimiter: \t%s\n",str );
      }
      else if( isIdentifier(str)  ){
            printf("Identifier: \t%s \n",str );
      }

}

void readWords(FILE *fptr, char *c){
        fptr = fopen("input.txt", "r");
        FILE *outptr;
        outptr = fopen("output.txt","w");
        if(!c){
            printf("Error Allocating memory\n" );
            return;
        }
        if(!fptr){
            printf("Error opening file\n" );
            return;
        }

          while( fscanf(fptr,"%s", c) == 1 ){
              // printf("%s \n", c );
              identifyString(c);
              fprintf(outptr,"%s",c);
          }


        fclose(fptr);
}

int main(){
  char *c = (char*)  malloc(100000);

  FILE *fptr;
  readWords(fptr,c);


  return 0;
}
