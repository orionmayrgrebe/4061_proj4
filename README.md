Extends word counting application of 4061_proj2 by using server-client socket programming. While I was unable to get my particular code to work and it will not run properly, it does show my progress in the various files. The master process is the main process of the client program; this process would spawn multiple mapper processers. On the other hand, the reducer process is the main process of the server program. Whenever the client connects to the server via a TCP connection, it will spawn a new reducer thread, making it a multi-threaded server.
