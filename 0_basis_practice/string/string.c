#include <stdio.h>
int myStrlen(char s[]){
    int len=0;
    int i=0;
    while(s[i]!='\0'){
        len+=1;
        i+=1;
    }
    return len;
}
void reverseString(char s[]){
    int n=myStrlen(s);
    int i;
    char temp;
    for(i=0;i<(n/2);i++){
        temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
}
int countChar(char s[],char key){
    int n=myStrlen(s);
    int i, count=0;
    for(i=0;i<n;i++){
        if(s[i]==key){
            count++;
        }
    }
    return count;
}
int myStrcmp(const char *s, const char *s1){
    int i=0;
    while(s[i]!='\0' && s1[i]!='\0'){
        if(s[i]!=s1[i]){
            return s[i]-s1[i];
        }
        i++;
    }
    return s[i]-s1[i];
}
int isPalindrome(char s[]){
    int i=0;
    int n=myStrlen(s);
    for(i=0;i<(n/2);i++){
        if(s[i]!=s[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(void){
    char s[100];
    char s1[100];
    char key;
    printf("請輸入字串一：");
    scanf("%s",s);
    printf("請輸入字串二：");
    scanf("%s",s1);
    printf("請數入key:");
    scanf(" %c",&key);
    printf("%c出現%d次\n",key,countChar(s,key));  
    printf("字串一與字串二差異為:%d\n",myStrcmp(s,s1));     
    printf("您輸入的單字長度為：%d\n",myStrlen(s));
    if(isPalindrome(s)){
        printf("這是迴文\n");
    }
    else{
        printf("這不是迴文\n");
    }
    reverseString(s);
    printf("倒轉後為：%s\n",s);    
    return 0;
}