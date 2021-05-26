#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get input from user then print greetings
    string name = get_string("Name: ");
    printf("hello, %s\n", name);
}
