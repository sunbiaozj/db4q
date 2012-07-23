/*
 * $Id: RWMutex.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_RWMUTEX_H__
#define LWPR_RWMUTEX_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{

	typedef pthread_rwlock_t PTHREAD_RWLOCK_T;

	class RWMutex
	{
	public:

		/**
		 * ���캯��
		 */
		RWMutex();

		/**
		 * ��������
		 */
		~RWMutex();

		/**
		 * ���� Read Lock
		 */
		void RDLock();

		/**
		 * д�� Write Lock
		 */
		void WRLock();

		/**
		 * �ͷ���
		 */
		void Unlock();

	private:

		PTHREAD_RWLOCK_T m_rwlock;
	};
};

#endif // end of LWPR_RWMUTEX_H__
