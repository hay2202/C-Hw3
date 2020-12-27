#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int get_line(char s[]){
    int num_of_char = 0;
    char c ='a';

    while(c != '\n' || num_of_char != LINE){
        scanf("%c",&c);
        strcat(s,&c);
        num_of_char++;
    }
    return num_of_char;
}

int getword(char w[]){
    int num_of_char = 0;
    char c ='a';

    while(c != '\n' || c != '\t' ||c != ' ' || num_of_char != WORD){
        scanf("%c",&c);
        strcat(w,&c);
        num_of_char++;
    }
    return num_of_char;
}

int substring( char * str1, char * str2){
    if(strstr(str1, str2) != NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int similar (char *s, char *t, int n){
    int len_s = strlen(s);
    int len_t = strlen(t);
    int miss, i , j;

    while(i<len_t || j<len_s){
        if(t[i] == s[j]){
            i++;
            j++;
        }
        else {
            j++;
            miss++;
        }
    }
    if(miss == n){
        return 1;
    }
    else 
        return 0;
}

void print_lines(char * str){
    while(!EOF){
        char line[LINE];
        get_line(line);
        if (substring(line, str))
        {
            printf("%s",line);
        }           
    }
}

void print_similar_words(char * str){
    while (!EOF)
    {
       char word[WORD];
       getword(word);
       if (similar(str,word,1)==1 || similar(str,word,0))
       {
           printf("%s",word);
       }
    } 
}

int main(){
    char option[2];
    char word[WORD];

    getword(word);
    getword(option);

    switch (option[0])
    {
        case 'a':
            print_lines(word);
            break;
        
        case 'b':
            print_similar_words(word);
            break;
    }
    return 1;
}