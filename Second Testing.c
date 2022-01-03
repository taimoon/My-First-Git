#include"Polish_Notation.h"
#include<string.h>

int main(){
    char infix[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    char postfix[strlen(infix)*2];
    char prefix[strlen(infix)*2];
    postfixConverter(&infix[0], &postfix[0], strlen(infix));
    printf("%s\n", postfix);
    prefixConverter(&infix[0], &prefix[0], strlen(infix));
    printf("%s", prefix);
    return 0;
}
