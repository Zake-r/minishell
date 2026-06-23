
#include <string.h>
#include <stdio.h>

int count_word(char *s)
{
	int count = 0;
	while (*s)
	{
		while (*s == ' ' && *s != '\0')
			s++;
		if (*s != ' ' && *s != '\0')
			count++;
		while (*s != ' ' && *s != '\0')
			s++;

	}
	return (count);

}

int count_pipe(char *s)
{
	int count = 0;
	while (*s)
	{
		if (*s == '|')
			count++;
		s++;
	}
	return (count);

}

int count_word_to_pipe(char *s)
{
	int count = 0;
	while (*s && *s != '|')
	{
		while (*s == ' ' && *s != '\0' && *s != '|')
			s++;
		if (*s != ' ' && *s != '\0' && *s != '|')
			count++;
		while (*s != ' ' && *s != '\0' && *s != '|')
			s++;
	}
	return (count);
}
int main(void)
{
	char str[] = "some te | xt in here";
	char ***tab;
	char *token = strtok(str, " ");

	tab = malloc(sizeof(char **) * count_pipe(line))
	while (token)
	{
		printf("%s\n",token);
		token = strtok(NULL, " ");
	}
	//printf("%d\n",count_word(str));
	//strtok(str, " ")


}

