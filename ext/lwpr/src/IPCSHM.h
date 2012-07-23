/*
 * $Id: IPCSHM.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_IPCSHM_H__
#define LWPR_IPCSHM_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{
	class IPCSHM
	{
	public:
		/**
		 * ����һ�������ڴ����
		 */
		static IPCID_T Create(const IPCKEY_T key,
		                      int size,
		                      IPC_CREATE_TYPE_E type = LWPR::CREATE_NEW_ONE,
		                      int perm = IPC_DEFAULT_PERM);

		/**
		 * ����IPC Key������Ӧ��IPC ID
		 */
		static IPCID_T GetID(const IPCKEY_T key);

		/**
		 * ����һ�������ڴ����
		 */
		static void Destroy(const IPCID_T id);

		/**
		 * ���ں˽������ڴ��ַ�������������
		 */
		static void* Mount(const IPCID_T id, PERMISSION_E prms = LWPR::RW);

		/**
		 * ж�ر����̹��صĽ��̵�ַ
		 */
		static void Unmount(void *addr);

		/**
		 * ����MagicCode��ȡϵͳ�пɷ��ʵĹ����ڴ�ID
		 */
		static int FetchSHMID(IPCIDList& ids, LWPR::UINT32 magic_code);

	private:
	};

	DEFINE_EXCEPTION(LWPR_IPC_SHM_GET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SIZE_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SHMAT_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SHMDT_ERR);

	DEFINE_EXCEPTION(LWPR_IPC_SHM_NOT_EXIST);
};

#endif // end of LWPR_IPCSHM_H__
