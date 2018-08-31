#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <Python.h>

int main(int argc, char *argv[]) {

    struct addrinfo hint, *res, p;
    int error;

    if (argc != 2){
        return 1;
    }

    memeset(&hint, 0, sizeof(hint));
    hint.ai_family = AF_UNSPEC;
    hint.ai_socketype = SOCK_STREAM;

    err = getaddrinfo(argv[1], "http", &hint, &res);

    if(err != 0){
      printf("Error caught!");
      return err;
    }

    void *addr;
    struct sockaddr_in *ipv4;
    struct sockaddr_in6  *ipv6;

    for(p = res; p != NULL; p = p -> ai_next){
        if(p->ai_family == AF_INET){
            ipv4(struct sockaddr_in *) p-> ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            ipv6(struct sockaddr_in6 *)p-> ai_addr;
            addr = &(ipv6->sin6_addr);
        }
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s\n", ipstr);
    }
    freeaddrinfo(res);

    return 0
}