#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
int sockfd, n; /* số mô tả socket – socket handle */
int len;
struct sockaddr_in address; /* structure sockaddr_in , chứa các thông tin về socket AF_INET */
int result;
/* Tạo socket cho trình khách. Lưu lại số mô tả socket */
sockfd = socket( AF_INET, SOCK_STREAM, 0 );

/* Đặt tên và gán địa chỉ kết nối cho socket theo giao thức Internet */
address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr( "127.0.1.3" );
address.sin_port = htons(38247);

/* Thực hiện kết nối */
result = connect( sockfd, (struct sockaddr*)&address, sizeof( address ) );
    if ( result == -1 ) {
        perror( "Oops: client1 problem" );
        exit( 1 );
        }
while (1)
{
/* Sau khi socket kết nối, chúng ta có thể đọc ghi dữ liệu của socket tương tự đọc ghi trên file */
char Buff[100];
printf( "Nhap tin nhan: ");
fgets(Buff, sizeof(Buff), stdin); 
write( sockfd, Buff, sizeof(Buff));
char Buff1[100];
n = read ( sockfd, Buff1, sizeof(Buff1));
 if (n > 0) {
    printf( "Tin nhan tu Sever: %s\n", Buff1 );
    }
}
close( sockfd );
}
