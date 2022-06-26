#if 0
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int sock;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0) {

		printf("socket failed\n");

		return 1;
	}

	return 0;
}
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <errno.h>

int main()
{
	int sock;

	sock = socket(3000, 4000, 5000);

	if (sock < 0) {

		perror("socket");
		printf("%d\n", errno);
		return 1;
	}

	return 0;
}

