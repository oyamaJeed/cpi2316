/*** TCP/IP client program ***/
/* Usage: ./k05c */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define	PORT	50001
#define BLEN	64

int main(int argc, char *argv[])
{

	int SessionID;
	struct hostent *HostInfo;
	struct sockaddr_in ServerAddr;
	char buf[BLEN];
  
	if(argc!=2){
		fprintf(stderr,"Usage: ./k05c HostName!\n");	//　エラー処理
		exit(1);
	}
  
	if((SessionID=socket(AF_INET,SOCK_STREAM,0))==-1){	//ソケット生成とエラー処理
		fprintf(stderr, "Failed to make a socket!\n");
		exit(1);
	}
  
	if((HostInfo=gethostbyname(argv[1]))==NULL){		//　NULLの場合エラー
		fprintf(stderr,"Failed to find host.\n");
		exit(1);
	}
  
	ServerAddr.sin_family=AF_INET;
	ServerAddr.sin_port=htons(PORT);	//　ネットワークバイト順に変換してsin_familyに代入
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memcpy((char *)&ServerAddr.sin_addr,(char *)HostInfo->h_addr_list[0],HostInfo->h_length);

//--------------------------------------------

/*	if((SessionID = connect(SessionID,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr)))==-1){
		fprintf(stderr,"Failed to connect.\n");
		exit(1);
	}*/

	connect(SessionID,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));

	if(recv(SessionID,buf,sizeof(buf),0)==-1){		//　返事の返し方
		fprintf(stderr,"Failed to recv a message.\n");
		exit(1);
	}

	printf("%s\n",buf);

	if (shutdown(SessionID,2)==-1){	//　シャットダウン処理
		fprintf(stderr,"Failed to shutdown.\n");
		exit(1);
	}
	close(SessionID);

}

