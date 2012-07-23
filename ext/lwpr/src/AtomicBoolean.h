/*
 * $Id: AtomicBoolean.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_ATOMIC_BOOLEAN_H__
#define LWPR_ATOMIC_BOOLEAN_H__
#include "LWPRType.h"

namespace LWPR
{
	class AtomicBoolean
	{
	public:
		/**
		 * ���캯��
		 */
		AtomicBoolean(bool initialValue = false);

		/**
		 * �����ǰֵ == Ԥ��ֵ������ԭ�ӷ�ʽ����ֵ����Ϊ�����ĸ���ֵ
		 * @return ����ɹ����򷵻� true������ False ָʾʵ��ֵ��Ԥ��ֵ�����
		 */
		bool CompareAndSet(bool expect, bool update);

		/**
		 * ���ص�ǰֵ
		 */
		bool Get() const;

		/**
		 * ����Ϊ����ֵ����������ǰ��ֵ
		 * @return ��ǰ��ֵ
		 */
		bool GetAndSet(bool newValue);

		/**
		 * ������������Ϊ����ֵ��
		 */
		void Set(bool newValue);

		/**
		 * ����ת��������
		 */
		operator bool () const;

	private:
		volatile int m_nValue;
	};
};

#endif // end of LWPR_ATOMIC_BOOLEAN_H__
