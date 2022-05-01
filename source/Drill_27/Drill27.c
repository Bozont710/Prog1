#include <stdio.h>

void print_out(char p[], int x)
{
    printf("p is %s and x is %d\n", p, x);
}

int main()
{
    printf("Hello World!\n");

    char elso[] = "Hello";
    char masodik[] = "World!";
    printf("%s %s\n", elso, masodik);

    print_out("foo", 7);
    return 0;
}