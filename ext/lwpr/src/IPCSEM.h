/*
 * $Id: IPCSEM.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_IPCSEM_H__
#define LWPR_IPCSEM_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{
	/**
	 * ���ļ����ᵽ���ź�������Ϊ��д��������
	 * ���������ͣ����������д��
	 */
	class IPCSEM
	{
	public:
		/**
		 * ����һ���ź�������ֵ�ź���
		 * iswrlock��־�Ƿ��Ƕ�д��������Ƕ�д�����������ź�����ֵΪSHRT_MAX
		 * ����ʱ��1��д��ʱ����SHRT_MAX
		 */
		static IPCID_T Create(const IPCKEY_T key,
		                      bool iswrlock = false,
		                      IPC_CREATE_TYPE_E type = LWPR::CREATE_NEW_ONE,
		                      int perm = IPC_DEFAULT_PERM);

		/**
		 * ����IPC Key������Ӧ��IPC ID
		 */
		static IPCID_T GetID(const IPCKEY_T key);

		/**
		 * ����һ���ź�������
		 */
		static void Destroy(const IPCID_T id);

		/**
		 * �����ź���
		 */
		static void Lock(const IPCID_T id, bool blocked = true, bool iswrlock = false);

		/**
		 * �����ź���
		 */
		static void Unlock(const IPCID_T id, bool iswrlock = false);

		/**
		 * �ж��ź����Ƿ��ڼ���״̬
		 */
		static bool IsLocked(const IPCID_T id);
	};

	DEFINE_EXCEPTION(LWPR_IPC_SEM_GET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_RESET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_LOCK_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_UNLOCK_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_CTL_ERR);

	DEFINE_EXCEPTION(LWPR_IPC_SEM_LOCKED_BEFORE);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_NOT_EXIST);
};

#endif // end of LWPR_IPCSEM_H__
