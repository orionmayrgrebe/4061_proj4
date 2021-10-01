#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <zconf.h>
#include <pthread.h>
#include <signal.h>
#include <arpa/inet.h>
#include "../include/protocol.h"

/**
The server program is a multi-threaded server. The server is responsible for
listening and building connections from clients. The server waits for
connections on the specified port. When it receives a connection, it
should spawn a new thread to handle that connection. A thread is responsible
for handling requests from a client by reading client’s messages from a socket
set up between them, doing necessary computation (refer to section 4.
Communication Protocol) and sending responses to the client back through the
socket. The thread should exit after it close the client connection.

Server maintains two important lists - azList and updateStatus. azList is a
1-D integer list and updateStatus is a 2-D integer list, as shown in Figure 4.
The server saves the sum of all the word count results from mapper clients in
the azList. updateStatus table has 3 essential attributes - MapperID, Number
of updates, check in/out flag. A new entry of the updateStatus table is created
when the server receives a CHECKIN request from a new mapper client (refer to
the details of request commands in section 4.1 Request). You can feel free to
add more columns to the table if needed.

**/

int azList[26];
// 2-D integer list. MapperID, number of updates, check in/out flag

//Incremented by 1 when receiving an UPDATE_AZLIST request from a mapper client.
//The value should be the same with the number of files the mapper client processes.
int updateStatus[32][3];

int main(int argc, char *argv[]) {
    int server_port;

    if (argc == 2) { // 1 arguments
        server_port = atoi(argv[1]);
    } else {
        printf("Invalid or less number of arguments provided\n");
        printf("./server <server Port>\n");
        exit(0);
    }
    //int sockfd = socket(domain, type, protocol)
    /**
    sockfd: socket descriptor, an integer (like a file-handle)
    domain: integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
    type: communication type
    SOCK_STREAM: TCP(reliable, connection oriented)
    SOCK_DGRAM: UDP(unreliable, connectionless)
    protocol: Protocol value for Internet Protocol(IP), which is 0. This is the
    same number which appears on protocol field in the IP header of a packet.
    **/
    /**
    * int bind(int sockfd, const struct sockaddr *addr,
                          socklen_t addrlen);
      After creation of the socket, bind function binds the socket to the
      address and port number specified in addr(custom data structure).
      In the example code, we bind the server to the localhost, hence we
      use INADDR_ANY to specify the IP address.
      address.sin_addr.s_addr = INADDR_ANY;
    */
    //server listens for a connection on specified port
    //int listen(int sockfd, int backlog);
    /**
    It puts the server socket in a passive mode, where it waits for the client
    to approach the server to make a connection. The backlog, defines the maximum
    length to which the queue of pending connections for sockfd may grow. If a
    connection request arrives when the queue is full, the client may receive
    an error with an indication of ECONNREFUSED.
    **/
    //when it receives a connection, spawns a new thread to handle that connection
    /**
    int new_socket= accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    It extracts the first connection request on the queue of pending connections
    for the listening socket, sockfd, creates a new connected socket, and returns
    a new file descriptor referring to that socket. At this point, connection is
    established between client and server, and they are ready to transfer data.
    */
    //the thread is responsible for handling requests from a client
    //reads the messages the client sends through the socket set up between them
    //does necessary computation
    //sends responses to client through socket

    // Server receives a CHECKIN request from new mapper client (4.1) and
    // creates a new entry in updateStatus
    // Server (Reducer) code
    //pthread_create() for 0->mapper num
    /** Servers should handle various error cases such as:
    - When receiving a request with unknown request code
    - When mapper ID is not greater than zero
    - When there is no corresponding entry in the updateSatus table
    - When a mapper client sends CHECKIN request, if it is already checked-in.
    - When a mapper client sends CHECKOUT request, if it is not checked-in.
    - Handling request permission etc. */
    return 0;
}
