#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	ret;
	char	*buf;
	int fd;

	fd = open("txt/text.txt", O_RDONLY);
	ret = read(fd, buf, 50);
	buf[ret] = '\0';
	printf("ret: %d; result: %s\n", ret, buf);
}