

#include "mymalloc.h"

int main()
{
	char *address1 = (char *)MyMalloc(10 * (sizeof(char)));
	char *address2 = (char *)MyMalloc(500 * (sizeof(char)));
	printf("%p\n", address1);
	printf("%p", address2);

	return 0;
}
