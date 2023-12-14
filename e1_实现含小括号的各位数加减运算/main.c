#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        stack->capacity *= 2;
        stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
    }
    stack->array[++stack->top] = value;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top];
}
void deleteStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

typedef struct Context_t
{
    char *str;
    int   pos;
}Ctx;

typedef struct Environment_t
{
    Ctx  ctx;
    int  val;
}Env;

typedef struct Operate_t
{
    Ctx  ctx;
    char op;
}OpEnv;

static Env num(const Ctx ctx)
{
    return (Env){{ctx.str, ctx.pos + 1}, ctx.str[ctx.pos] - '0'};
}

static OpEnv opr(const Ctx ctx)
{
    return (OpEnv){{ctx.str, ctx.pos + 1}, ctx.str[ctx.pos]};
}

static int addSub(int left, int right, char op)
{
    switch(op)
    {
        case '+':
            return (left + right);
        case '-':
            return (left - right);
        default:
            assert(0);
            return 0;
    }
}
// 去括号
void removeBracket (const char *str,char *str2)
{
    int index = 0;
    int index_str2 = 0;
    Stack* st = createStack(20);
    int reverse = 1;
    char* cur = str;
    int sign_pos = -1;
    while(*cur != '\0')
    {
        if(*cur == '(')
        {
            if(sign_pos > -1)
            {
                if(str[sign_pos] == '+')
                {
                    push(st, 1 );
                }
                else if(str[sign_pos] == '-')
                {
                    push(st, -1 );
                    reverse *= -1;
                }
            }
        }
        else if(*cur == ')')
        {
            int last = 1;
            if(!isEmpty(st))
            {
                last = pop(st);
            }
            reverse *= last;
        }
        else if(*cur == '+' )
        {
            if (reverse == -1)
            {
                str2[index_str2++] = '-';
            }
            else
            {
                str2[index_str2++] = '+';
            }
            sign_pos = index;
        }
        else if (*cur == '-')
        {
            if (reverse == -1)
            {
                str2[index_str2++] = '+';
            }
            else
            {
                str2[index_str2++] = '-';
            }
            sign_pos = index;
        }
        else
        {
            str2[index_str2++]=*cur;
        }
        index+=1;
        cur++;
    }
    str2[index_str2++] = '\0';
}
int expr(const char *str)
{
    // 去括号
    char str2[1000];
    removeBracket(str, str2);
    Ctx ctx = {(char *)str2, 0};

    Env env = num(ctx);
    int val = env.val;

    OpEnv opEnv  = opr(env.ctx);

    while (opEnv.op != '\0')
    {
        env   = num(opEnv.ctx);
        val   = addSub(val, env.val, opEnv.op);
        opEnv = opr(env.ctx);
    }

    return val;

}


int main() {
    printf("%d\n", expr("1+2-3")); // 输出0
    printf("%d\n", expr("3-2-1")); // 输出0
    printf("%d\n", expr("(1+2)-3")); // 输出0
    printf("%d\n", expr("3-(2-1)")); // 输出2
    printf("%d\n", expr("3-(2-1)+(2-1)+(4+(3-2))"));
    return 0;
}