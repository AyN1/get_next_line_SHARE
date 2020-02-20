#include <fcntl.h>
#include <stdio.h>
#define NBR_EXEC 600

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		i = 0;
	char	*ligne = NULL;
	int		ret = 1;
	int		ret2 = 1;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (argc != 3)
	{
		printf("usage: ./a.out text.txt text2.txt\n");
		return (0);
	}
	while ((ret || ret2) && i < NBR_EXEC)
	{
		if (ret)
		{
			ret = get_next_line(fd, &ligne);
			printf("ret1: [%d] ", ret);
			printf("%s\n", ligne);
			free(ligne);
			ligne = NULL;
		}
		if (ret2)
		{
			ret2 = get_next_line(fd2, &ligne);
			printf("ret2: [%d] ", ret2);
			printf("%s\n", ligne);
			free(ligne);
			ligne = NULL;
		}
		// ++i;
	}
	return (0);
}
