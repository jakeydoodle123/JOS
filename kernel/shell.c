// shell.c
// dumb shell for JOS
// Author: Jacob Mealey

#include "shell.h"

char *command_buffer = "\0";

void clearBuffer()
{
		command_buffer = command_buffer - stringLength(command_buffer);
}

void shInit()
{
	printf("JOS v0.0.1\n", normal);
}

void prompt()
{
	putchar('>', normal);
}

int commandCheck(char * command)
{
	if(stringCompare(command, "clear")){
		clear_screen(normal);
		return 1;
	}
	if(stringCompare(command, "mkfile")){
		return 1;
	}
	if(stringCompare(command, "list")){
		//listAllFiles(0);
		//listContents(10);
		return 1;
	}
	return 0;
}
void shWrite(char data)
{
	putchar(data, normal);
	if(data == '\n' )
	{
		commandCheck(command_buffer);
		clearBuffer();
		putchar('\n', normal);
		putchar('>', normal);
	}
	else
	{
		if(data == '\b'){
			removeChar(command_buffer, command_buffer);
			return;
		}

		concatChar(command_buffer, data, command_buffer);
	}
}


