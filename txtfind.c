#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30

int get_line(char s[]){
    int num_of_char = 0;
    char c =getchar();

    while(c != '\n' /*&& c != '\r'*/ && num_of_char != LINE){
        strncat(s,&c,1);
        num_of_char++;
        c =getchar();
    }
    return num_of_char;
}

int get_word(char w[]){
    int num_of_char = 0;
    char c =getchar();

    while(c != '\n' && c != '\t' && c != ' ' && c != '\r' && num_of_char != WORD){
        strncat(w,&c,1);
        num_of_char++;
        c =getchar();
    }
    return num_of_char;
}

int substring( char * str1, char * str2){
    char *s;
    s = strstr(str1,str2);
    if (s != NULL)
        return 1;
    else
        return 0;
}

int similar (char *s, char *t, int n){
    int len_s = strlen(s);
    int len_t = strlen(t);
    int miss= 0;
    int i= 0;
    int j= 0;

    int cmp = strcmp(s,t);
    if (!cmp )
    {
        return 1;
    }

    while(i<len_t && j<len_s){
        if(t[i] == s[j]){
            i++;
            j++;
        }
        else {
            i++;
            miss++;
        }
    }
    if(miss <= n && (len_t-len_s) == 1){
        return 1;
    }
    else
        return 0;
}

void print_lines(char * str){
    char c =getchar();

    while(c != EOF){
       char *line = (char*) calloc(LINE,sizeof(char));
       if (line == NULL)
       {
           printf("Error\n");
           return;
       }
        line[0] = c;
        get_line(line);
        if (substring(line, str))
        {
            printf("%s\n",line);
        }
        c =getchar();
        if (line != NULL){
            free(line);
        }
    }
}

void print_similar_words(char * str){
    char c =getchar();
    while (c != EOF)
    {
       char *temp = (char*) calloc(WORD,sizeof(char));
       if (temp == NULL)
       {
            printf("Error\n");
            return;
       }
       temp[0]=c;
       get_word(temp);
       if (similar(str,temp,1)==1)
       {
           printf("%s\n",temp);
       }
       if (temp != NULL){
            free(temp);
        }
       c = getchar();
    }
}

int main(){
    char *option = (char*) calloc(2,sizeof(char));
    char *word = (char*) calloc(WORD,sizeof(char));
    
    if (word == NULL || option == NULL)
    {
        printf("Error");
        return 1;
    }

    get_word(word);
    get_word(option);

    switch (option[0])
    {
        case 'a':
            print_lines(word);
            break;

        case 'b':
            print_similar_words(word);
            break;
    }
    if (word != NULL && option != NULL)
    {
        free(word);
        free(option);
    }

    return 0;
}