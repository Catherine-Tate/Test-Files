
// TCP Client program 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAXLINE 1024 
int main(int argc, char ** argv) 
{ 
    int PORT = atoi(argv[1]);
    int sockfd; 
    char buffer[MAXLINE]; 
    char* message = "Hello Server"; 
    struct sockaddr_in servaddr; 
  
    int n, len; 
    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        printf("socket creation failed"); 
        exit(0); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
  
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  
    if (connect(sockfd, (struct sockaddr*)&servaddr,  
                             sizeof(servaddr)) < 0) { 
        printf("\n Error : Connect Failed \n"); 
    } 
  
    memset(buffer, 0, sizeof(buffer)); 
    strcpy(buffer, "LOGIN Rick\n"); 
    write(sockfd, buffer, sizeof(buffer)); 
    printf("Message from server: "); 
    read(sockfd, buffer, sizeof(buffer)); 
    puts(buffer); 
    
    strcpy(buffer, "BROADCAST 21\nAaaaaaaaaaaaaaaaaagh!\n"); 
    write(sockfd, buffer, strlen(buffer)); 
    printf("Message from server: "); 
    read(sockfd, buffer, sizeof(buffer)); 
    printf("%s", buffer); 
    /*
    strcpy(buffer, "LOGOUT\n"); 
    write(sockfd, buffer, sizeof(buffer)); 
    printf("Message from server: "); 
    read(sockfd, buffer, sizeof(buffer)); 
    puts(buffer); 
    */
    close(sockfd); 
} 

