/*
 * $Id: SimpleProcessPool.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_SIMPLE_PROCESS_POOL_H__
#define LWPR_SIMPLE_PROCESS_POOL_H__
#include "LWPRType.h"
#include <list>

namespace LWPR
{
	/**
	 * �򵥽��̳ع��ܣ��ܴ����̶���Ŀ�Ľ��̣���ά�������������н��������˳���������
	 */
	class SimpleProcessPool
	{
	public:
		/**
		 * ���캯��
		 */
		SimpleProcessPool();

		/**
		 * ��������
		 */
		virtual ~SimpleProcessPool();

		/**
		 * ����������������
		 */
		void SetProcessNum(int process_num);

		/**
		 * ��ʼ����
		 */
		void Run(int argc, char** argv);

		/**
		 * �ӽ���ִ����
		 */
		virtual int DoChildWork(int argc, char** argv) = 0;

	private:
		int m_nProcessNum;
		std::list < int > m_ProcessList;
	};
};

#endif // end of LWPR_SIMPLE_PROCESS_POOL_H__
