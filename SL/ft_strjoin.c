#include "so_long.h"

char	*ft_joint(char *left, char *buf)
{
	char	*ret;
	int		i;
	int		a;


	if(!buf)
		return(NULL);
	a = strlen(left) + strlen(buf);
	ret = malloc(sizeof(char) * (a + 1));
	i = 0;
	a = 0;
	if(left)
	{
		while (left[a])
			ret[i++] = left[a++];
		a = 0;
	}
	while (buf[a])
		ret[i++] = buf[a++];
	ret[i] = '\0';
	//free(left);
	return(ret);
}