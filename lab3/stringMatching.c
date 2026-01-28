#include <stdio.h>
#include <string.h>

int string_match(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int i,j;
    int comparisons = 0;

    for(i=0;i<=n-m;i++){
        j=0;
        while(j<m && pattern[j] == text[i+j]){
            comparisons++;
            j++;
        }
        if(j<m) comparisons++;
        if(j==m){
            printf("pattern found at index: %d\n",i);
            printf("total comparisons: %d\n",comparisons);
            return i;
        }
    }
    printf("pattern not found\n");
    printf("total comparisons: %d\n",comparisons);
    return -1;
}

int main(){
    char text[100], pattern[50];
    printf("enter a word: ");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = 0;

    printf("pattern to match: ");
    fgets(pattern,sizeof(pattern),stdin);
    pattern[strcspn(pattern,"\n")] = 0;

    string_match(text,pattern);
    return 0;
}
