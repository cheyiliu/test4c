#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/un.h>
#include <stddef.h>

// from http://www.gnu.org/software/libc/manual/html_mono/libc.html#Sending-Data
// 由socket_client.c 修改而来

#define PORT            5555
#define MESSAGE         "Yow!!! Are we having fun yet?!?"
//#define SERVERHOST      "www.gnu.org"
#define SERVERHOST      "192.168.6.72"

void write_to_server(int filedes) {
	int nbytes;

	nbytes = write(filedes, MESSAGE, strlen(MESSAGE) + 1);
	if (nbytes < 0) {
		perror("write");
		exit(EXIT_FAILURE);
	}
}

void init_sockaddr(struct sockaddr_in *name, const char *hostname,
		uint16_t port) {
	struct hostent *hostinfo;

	name->sin_family = AF_INET;
	name->sin_port = htons(port);
	/*
	 hostinfo = gethostbyname (hostname);
	 if (hostinfo == NULL)
	 {
	 fprintf (stderr, "Unknown host %s.\n", hostname);
	 exit (EXIT_FAILURE);
	 }
	 name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
	 */

	if (inet_pton(AF_INET, hostname, &name->sin_addr) <= 0) {
		printf("inet_pton error \n");
		exit(EXIT_FAILURE);
	}
}

int main(void) {
	//int sock;
	//struct sockaddr_in servername;

	/* Create the socket. */
	//sock = socket(PF_INET, SOCK_STREAM, 0);
	//if (sock < 0) {
	//	perror("socket (client)");
	//	exit(EXIT_FAILURE);
	//}

	/* Connect to the server. */
	//init_sockaddr(&servername, SERVERHOST, PORT);
struct sockaddr_un name;
  int sock;
  size_t size;

  /* Create the socket. */
  sock = socket (PF_LOCAL, SOCK_STREAM, 0);
  if (sock < 0)
    {
      perror ("socket");
      exit (EXIT_FAILURE);
    }

  /* Bind a name to the socket. */
  name.sun_family = AF_LOCAL;
  strncpy (name.sun_path, "test.pc.local.socket1", sizeof (name.sun_path));
  name.sun_path[sizeof (name.sun_path) - 1] = '\0';


	if (0 > connect(sock, (struct sockaddr *) &name, sizeof(name))) {
		perror("connect (client)");
		exit(EXIT_FAILURE);
	}

	/* Send data to the server. */
	write_to_server(sock);
	close(sock);
	exit(EXIT_SUCCESS);
}

