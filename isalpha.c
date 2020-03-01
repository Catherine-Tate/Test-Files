#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (isalpha(c) == 0)
         printf("%c is not an alphabet.\n", c);
    else
         printf("%c is an alphabet.\n", c);

    return 0;
}
