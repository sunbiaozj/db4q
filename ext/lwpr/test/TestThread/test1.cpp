/*
 * $Id: test1.cpp 1 2012-01-17 02:31:57Z  $
 */
/*
 * ����LWPR::Thread���Ƿ������������߳�
 * �߳��Ƿ�����������
 */
#include "Thread.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class ThreadTest : public LWPR::Thread
{
public:
	ThreadTest()
	{
		this->Start();
	}

	~ThreadTest()
	{

	}

	void Run()
	{
		while(true)
		{
			printf("�߳�[%ld] �������С�����\n", GetId());
			Sleep(2.5);
		}
	}

private:
};

/**
 * ������
 */
int main(int argc, char *argv[])
{
	ThreadTest t[100];

	sleep(1000000);
	return 0;
}
