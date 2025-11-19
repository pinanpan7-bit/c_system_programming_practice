#include <stdio.h>
#include <ctype.h>
#include <string.h>
void freq(char s[],char key){
    int count[26]={0};
    int n=strlen(s);
    int i;
    char ch;
    for(i=0;i<n;i++){
        if(s[i]<='Z'&&s[i]>='A'){
            ch=tolower(s[i]);
            count[ch-'a']++;
        }
        else if(s[i]<='z'&&s[i]>='a'){
            count[s[i]-'a']++;
        }
        else{
        }
    }
    printf("%c出現%d次\n",key,count[key-'a']);
}
void Palindrome(char s[]){
    int n=strlen(s);
    int i;
    char *left=s;
    char *right=s+n-1;
    int ack=1;
    while(left<right){
        if(!isalnum(*left)){
            left++;
            continue;
        }
        if(!isalnum(*right)){
            right--;
            continue;
        }
        if(tolower(*right)!=tolower(*left)){
            ack=0;
            break;
        }
        left++;
        right--;
    }
    if(ack==1){
        printf("這是迴文\n");
    }
    else{
        printf("這不是迴文\n");
    }
}

int main(void){
    char s[200];
    char key;
    printf("請輸入一串字串:");
    fgets(s,sizeof(s),stdin);
    s[strcspn(s, "\n")] = '\0';
    printf("要搜尋次數的字母:");
    scanf(" %c",&key);
    key=tolower(key);
    freq(s,key);
    Palindrome(s);
    return 0;
}