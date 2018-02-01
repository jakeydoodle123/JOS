#include "shell.h"
char *command_buffer = "\0";

void sh_init()
{
	clear_screen(0x0F);
	printf("JOS v0.0.1\n", 0x0F);
	putchar('>', 0x0F);
}
void commands_check(char * command)
{
	if(string_compare(command, "clear")){
		clear_screen(0x0F);
	}
}
void sh_write(char data)
{
	putchar(data, 0x0F);
	if(data == '\n')
	{
		printf(command_buffer, 0x0F);
		commands_check(command_buffer);
		command_buffer = command_buffer - string_length(command_buffer);
		putchar('\n', 0x0F);
		putchar('>', 0x0F);
	}
	else
	{
		concatc(command_buffer, data, command_buffer);
	}
}

