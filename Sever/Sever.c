#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
int server_sockfd, client_sockfd, n, m;
int server_len, client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;

/* Thực hiện khởi tạo socket mới cho trình chủ */
server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );

/* Đặt tên và gán địa chỉ kết nối cho socket theo giao thức Internet */
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = inet_addr( "127.0.1.3" );
server_address.sin_port = htons(38247);

/* Ràng buộc tên với socke t */
bind( server_sockfd, (struct sockaddr *)&server_address, sizeof( server_address ) );

/* Mở hàng đợi nhận kết nối - cho phép đặt hàng vào hàng đợi tối đa 5 kết nối */
listen( server_sockfd, 5 );

/* Lặp vĩnh viễn để chờ và xử lý kết nối của trình khách */

printf( "Dang cho ket noi...\n" );

/* Chờ và chấp nhận kết nối */
client_sockfd = accept( server_sockfd, (struct sockaddr*)&client_address, &client_len );
    if (client_sockfd < 0) 
    { 
        printf("\nLoi ket noi !!! \n"); 
        return -1; 
    }
    else printf("\nDa ket noi !!! \n");
while (1) {
    char Buff[100];
    /* Đọc dữ liệu do trình khách gửi đến */
    n = read ( client_sockfd, Buff, sizeof(Buff));
    if (n > 0) {
    printf( "\nTin nhan tu Client: %s\n", Buff );
    }
    
    char Buff1[100];
    printf( "Nhap tin nhan: ");
    fgets(Buff1, sizeof(Buff1), stdin);; 
    /* Gửi trả dữ liệu về cho trình khách */
    write( client_sockfd, Buff1, sizeof(Buff1));
    }
close( client_sockfd );
/* Đóng kết nối */
}
