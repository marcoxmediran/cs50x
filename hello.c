#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts for user name then prints it
    string name = get_string("Name: ");
    printf("hello, %s\n", name);
}
