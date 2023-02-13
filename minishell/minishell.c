#include "minishell.h"

/*202212222111 во время обработки нескольких строк одной коммандой,
будет необхадимо вернутся к функции init ---- main_control*/

int init(char **envp)
{
	char *line;
	while(1)
	{
		line = readline("root# ");
		//rl_replace_line("", 0);Hoso 20221224
		if(line && *line)
		{
			main_control(envp,line);
			free(line);
		}
	}
	
}

int main  (int argc, char **argv ,char **envp)
{
	// struct termios t;
	// tcgetattr(STDIN_FILENO, &t);
	// t.c_lflag &= ~ECHO;
	// tcsetattr(STDIN_FILENO, TCSANOW, &t);
	// signal(SIGQUIT, SIG_IGN);
	if (argc == 1)
		init(envp);
	return(0);
}
