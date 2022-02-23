// infix to postfix expression.

# include <stdio.h>
// variables are used in the function.
char opr[25],out[25],ch;
int topopr = -1,topout = -1;

// operation for the operator stack
void pushopr(char ele){
    if (topopr==24)
        printf("\nStack overflow.");
    else{
        topopr++;
        opr[topopr]=ele;
    }
}
char popopr(){
    if (topopr!=-1){
        ch=opr[topopr];
        topopr--;
    }
    return ch;
}
char peepopr(){
    if (topopr!=-1)
        ch = opr[topopr];
    return ch;
}
void displayopr(){
    int i=0;
    printf("\nOperator Stack...");
    for (i = 0; i<=topopr; i++)
        printf("| %c",opr[i]);
}

// operation for the output stack.
void pushout(char ele){
    if (topout==24)
        printf("\nStack overflow.");
    else{
        topout++;
        out[topout]=ele;
    }
}
void displayout(){
    int i=0;
    printf("\nOutput Stack...");
    for (i = 0; i<=topout; i++)
        printf("| %c",out[i]);
}

// checking the priority of the operator.
int priority(char ele){
    switch (ele)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return -1;
}

void main(){
    char infix[25],ele,popele;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    int i=0;
    while (infix[i]!='\0')
    {
        ele = infix[i];
        if (ele=='('){
            pushopr(ele);
        }
        else if (ele==')'){
            // pop element untill ( comes
            while (peepopr()!='(')
            {
                popele = popopr();
                pushout(popele);
            }
            // deleating the left bracket.
            popopr();
        }
        else if (ele=='^'||ele=='+'||ele=='/'||ele=='+'||ele=='-'){
            if (topopr>=0){
                while (priority(peepopr())>=priority(ele) && topopr!=-1)
                {
                    popele = popopr();
                    // popping out the operator with lower priority
                    pushout(popele);
                }
            }
            // push the element in the operator stack which has greater priority.
            pushopr(ele);
        }
        else{
            pushout(ele);
        }
        displayopr();
        displayout();
        i++;
    }
    // if operator stack is not still empty.
    if (topopr!=-1){
        while (topopr!=-1)
        {
            popele = popopr();
            pushout(popele);
        }
    }
    printf("\nPostfix expression = %s",out);
}
