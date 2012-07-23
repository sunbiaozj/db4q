/*
 * $Id: CFile.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_CFILE_H__
#define LWPR_CFILE_H__
#include "LWPRType.h"
#include "Exception.h"
#include "Buffer.h"
#include "StringBuffer.h"
#include <cstdio>

namespace LWPR
{
	class CFile
	{
	public:

		/**
		 * ���캯��
		 */
		CFile(const char* fname, const char* mode);

		/**
		 * ��������
		 */
		virtual ~CFile();

		/**
		 * ��ȡ�ļ��Ĵ�С
		 */
		int FSIZE();

		/**
		 * ���ļ�����ȫ�����ص��ڴ�
		 */
		LWPR::Buffer_ptr LoadFileContent();

		/**
		 * д���ݵ��ļ�
		 */
		void FWRITE(const LWPR::Buffer& buf);

		/**
		 * д�ı����ļ�
		 */
		void FWRITE(const LWPR::StringBuffer& strbuf);

	private:
		FILE *m_fp;
	};

	class AutoCloseFile
	{
	public:
		AutoCloseFile(FILE* fp);
		~AutoCloseFile();
	private:
		FILE* m_fp;
	};

#define AUTO_CLOSE_FILE(fp)	LWPR::AutoCloseFile __AutoCloseFile(fp)

	DEFINE_EXCEPTION(FileNotFoundException);
	DEFINE_EXCEPTION(IOException);
};

#endif // end of LWPR_CFILE_H__
