#include <string.h>

#if 0	// COMPILE ERROR
char	**split(char *str, char ch)
{
    char **array;
    int i;
    int size;
	int j = 0;

    size = strlen(str);
#if 0	// COMPILE ERROR
    array = (char **)malloc(sizeof(char *) * 2);
#endif
    i = 0;
	while (str[i])
	{
        if (str[i] == '=')
            break;
        ++i;
	}
#if 0	// COMPILE ERROR
	array[0] = (char *)malloc(sizeof(char) * i + 1);
#endif
#if 0	// COMPILE ERROR
	array[1] = (char *)malloc(sizeof(char) * (size - i));
#endif
	while (j < i)
	{
		array[0][j] = str[j];
		++j;
	}
#if 0	// COMPILE ERROR
	array[0][i] = NULL;
#endif
#if 0	// COMPILE ERROR
	array[1][size - i - 1] = NULL;
#endif
	j = i + 1;
	while (j < size)
	{
		array[1][j] = str[j];
		++j;
	}
	return (array);
}
#endif
