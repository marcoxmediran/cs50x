#include <stdio.h>
#include <cs50.h>

int main(void)
{
	// Get name from user then print greetings
	string name = get_string("Name: ");
	prinft("hello, %s\n", name);
}
