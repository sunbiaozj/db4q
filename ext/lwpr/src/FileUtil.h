/*
 * $Id: FileUtil.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_FILE_UTIL_H__
#define LWPR_FILE_UTIL_H__
#include <vector>
#include <string>

namespace LWPR
{
	class FileUtil
	{
	public:
		static bool IsFileExist(const char* fileName);

		/**
		 * �ݹ齨��Ŀ¼
		 * file ��� ��ȫ·�����ļ���
		 *      ��:  /post_app/hd_app/center2/file/20071229/11/rptd/100711030306220071229.rpt
		 *
		 * ����file
		 */
		static char *BuildFile(const char *file);

		/*
		 * �ݹ齨��Ŀ¼
		 * path ��� ��ȫ·��
		 *      ��:  /post_app/hd_app/center2/file/20071229/11/rptd
		 *           /post_app/hd_app/center2/file/20071229/11/rptd/
		 *
		 * ����@path
		 */
		static char *BuildPath(const char *path);

		/**
		 * ȥ���ļ�·���������ļ���
		 */
		static std::string GetBaseName(const char* file);

		/**
		 * �����ļ���չ��
		 */
		static std::string ChangeFileExtName(const char* file, const char* ext);

		/**
		 * �����ļ��������ɿ�����궨��
		 */
		static std::string GenHeaderDef(const char* file);
	};
};

#endif // end of LWPR_FILE_UTIL_H__
