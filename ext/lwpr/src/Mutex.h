/*
 * $Id: Mutex.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_MUTEX_H__
#define LWPR_MUTEX_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{

	typedef pthread_mutex_t  PTHREAD_MUTEX_T;

	class Mutex
	{
	public:

		/**
		 * ���캯��
		 */
		Mutex();

		/**
		 * ��������
		 */
		~Mutex();

		/**
		 * ����
		 */
		void Lock();

		/**
		 * ����������
		 * ��������ɹ�����true�����򷵻�false
		 */
		bool TryLock();

		/**
		 * �ͷ���
		 */
		void Unlock();

		/**
		 * ��ȡ����Ϊ��������׼��
		 */
		PTHREAD_MUTEX_T* GetMutexRef();

	private:

		PTHREAD_MUTEX_T m_mutex;
	};
};

#endif // end of LWPR_MUTEX_H__
