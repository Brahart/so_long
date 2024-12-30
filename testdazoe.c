#include "include/so_long.h"

char	*ft_extract_map(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp_buffer;

	line = ft_strdup("");
	buffer = ft_strdup("");
	tmp_buffer = buffer;
	if (fd > 0)
	{
		while (buffer)
		{
			buffer = get_next_line(fd);
			line = ft_strjoin(line, buffer);
			free(buffer);
		}
		return(line);
	}
	ft_error("ERROR\nLecture map has failed");
	return(NULL);
}

int	main(void)
{
	int	fd;
	char	*str;
	fd = open("map/map.ber", O_RDONLY);
	ft_extract_map(fd);
	printf("%s", str);
	return(0);
}