/*
 * $Id: test2.cpp 1 2012-01-17 02:31:57Z  $
 */
/*
 * ����LWPR::EventNetDispatch���Ƿ�����������
 * �䵱Client
 */
#include "Socket.h"
#include "SimpleProcessPool.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class Test2 : public LWPR::SimpleProcessPool
{
public:
	Test2()
	{
	}

	~Test2()
	{
	}

	int DoChildWork(int argc, char** argv)
	{
		for(int i = 0; i < 10000; i++)
		{

			LWPR::SOCKET_FD_T nConnFd = LWPR::Socket::ConnectRemoteHost("192.168.187.128", 39000);
			if(nConnFd > 0)
			{
				cout << "ConnectRemoteHost OK " << nConnFd << endl;

				LWPR::SOCKET_RET_TYPE_E nRet = LWPR::Socket::WriteSocket(nConnFd, argv[2], 5);
				printf("first nRet = %d\n", nRet);

				//sleep(3);

				nRet = LWPR::Socket::WriteSocket(nConnFd, "SECOND", 5);
				printf("second nRet = %d\n", nRet);

				//sleep(3);

				LWPR::Socket::CloseSocket(nConnFd);
			}
			else
			{
				cout << "ConnectRemoteHost Failed " << nConnFd << endl;
			}
		}

		return 0;
	}
};


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Useage: %s ������ ��������\n", argv[0]);
		exit(-1);
	}

	Test2 test2;
	test2.SetProcessNum(atoi(argv[1]));
	test2.Run(argc, argv);

	return 0;
}
