#include<unistd.h>

// void ft_putstr(char *str)
// {
// 	int i = 0;
// 	while (str[i] != 0)
// 	{
// 		printf("%d\n", str[i]);
// 		i++;
// 	}
// }

int main(int ac,char **av) // unicode ▶
{
	// ft_putstr(av[1]);

	char	a = -30;
	char	b = -106;
	char	c = -74;

	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);

}