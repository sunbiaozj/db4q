/*
 * $Id: ThreadPool.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_THREAD_POOL_H__
#define LWPR_THREAD_POOL_H__
#include "LWPRType.h"
#include "Thread.h"
#include "Resource.h"
#include "Mutex.h"
#include "Synchronized.h"
#include <list>

namespace LWPR
{
	/**
	 * ThreadPoolѡ�����
	 */
	typedef struct thread_pool_option
	{
		int nMinThread;
		int nMaxThread;
		int nMaxIdlThread;

		thread_pool_option();
	} THREAD_POOL_OPTION_T;

	/**
	 * ���������࣬���û��̳�
	 */
	class WorkRequest
	{
	public:
		WorkRequest() {}
		virtual ~WorkRequest() {}
		virtual void DoWork() = 0;
	};

	class ThreadPool : public Resource
	{
		// �����߳�
		class ThreadWorker : public Thread
		{
		public:
			ThreadWorker(ThreadPool& pool);
			~ThreadWorker();
			void Run();
		private:
			ThreadPool& m_ThreadPool;
		};

		// �����߳�
		class ThreadManage : public Thread, public Resource
		{
		public:
			ThreadManage(ThreadPool& pool);
			~ThreadManage();
			void Run();
		private:
			ThreadPool& m_ThreadPool;
		};

		friend class ThreadWorker;
		friend class ThreadManage;

		typedef std::list< WorkRequest* > WorkRequestList;
		typedef std::list< ThreadWorker* > ThreadWorkerList;

	public:
		ThreadPool(THREAD_POOL_OPTION_T& opt);
		virtual ~ThreadPool();

		void AddRequest(WorkRequest* preq);

		void Destroy();

	private:
		inline void ClearDeadThread();

		inline bool IsNeededToCreateThread();

		inline bool IsNeededToDestroyThread();
		
	private:
		THREAD_POOL_OPTION_T	m_Option;			// ѡ�����
		ThreadManage*			m_pThreadManage;	// �����߳�

		Mutex					m_Mutex;			// for m_WorkRequestList
		WorkRequestList			m_WorkRequestList;	// ��������

		ThreadWorkerList		m_ThreadWorkerList;	// �߳�����
		AtomicInteger			m_nIdleThread;		// �����߳�����
		AtomicInteger			m_nTotalThread;		// �����߳�����
	};
};

#endif // end of LWPR_THREAD_POOL_H__
