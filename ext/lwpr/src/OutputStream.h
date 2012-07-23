/*
 * $Id: OutputStream.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_OUTPUT_STREAM_H__
#define LWPR_OUTPUT_STREAM_H__
#include "LWPRType.h"
#include "Object.h"
#include "Buffer.h"
#include <string>

namespace LWPR
{
	static const int OUTPUT_STREAM_DEFAULT_SIZE = 128;

	/**
	 * Ϊ���紫�����
	 */
	class OutputStream : public Object
	{
		OutputStream(const OutputStream& rhs);
		OutputStream& operator=(const OutputStream& rhs);

	public:
		/**
		 * ���캯��
		 */
		OutputStream(int capacity = OUTPUT_STREAM_DEFAULT_SIZE);
		/**
		 * ����дƫ����
		 */
		void Reset();
		/**
		 * дһ��BOOLֵ��Buffer
		 */
		void WriteBOOL(BOOL value);
		/**
		 * дһ��������buffer����ת��Ϊ�����ֽ���
		 */
		void WriteINT8(INT8 value);
		void WriteUINT8(UINT8 value);
		void WriteINT16(INT16 value);
		void WriteUINT16(UINT16 value);
		void WriteINT32(INT32 value);
		void WriteUINT32(UINT32 value);
		void WriteINT64(INT64 value);
		void WriteUINT64(UINT64 value);
		/**
		 * дһ��float�͵ĸ�������buffer
		 */
		void WriteFloat(FP32 value);
		/**
		 * дһ��double�͵ĸ�������buffer
		 */
		void WriteDouble(FP64 value);
		/**
		 * дһ���ַ�����buffer
		 */
		void WriteString(const char* value);
		void WriteString(const std::string& value);
		/**
		 * дһ��buffer��buffer
		 */
		void WriteAny(const char* buf, int size);
		void WriteArray(const void* buf, int size);
		/**
		 * ������ɵ�Buffer
		 */
		Buffer_ptr GetBuffer();

		char *GetStream();
		int GetStreamLength();

	private:
		Buffer_var	m_vBuffer;
		int			m_nOffSet;
	};

	DECLAREVAR(OutputStream);
};

#endif // end of LWPR_OUTPUT_STREAM_H__
