/*
 * $Id: AtomicInteger.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_ATOMIC_INTEGER_H__
#define LWPR_ATOMIC_INTEGER_H__
#include "LWPRType.h"

namespace LWPR
{
	class AtomicIntegerImpl;

	class AtomicInteger
	{
	public:

		/**
		 * ���캯��
		 */
		AtomicInteger(int initialValue = 0);

		/**
		 * ��������
		 */
		~AtomicInteger();

		/**
		 * ��ȡ��ǰֵ
		 */
		int Get() const;

		/**
		 * ����Ϊ����ֵ
		 */
		void Set(int newValue);

		/**
		 * �����ǰֵ == Ԥ��ֵ������ԭ�ӷ�ʽ����ֵ����Ϊ�����ĸ���ֵ
		 * @return ����ɹ����򷵻� true������ False ָʾʵ��ֵ��Ԥ��ֵ�����
		 */
		bool CompareAndSet(int expect, int update);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ��ǰ��ֵ
		 */
		int GetAndIncrement();

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ��ǰ��ֵ
		 */
		int GetAndDecrement();

		/**
		 * ��ԭ�ӷ�ʽ������ֵ�뵱ǰֵ���
		 * @return ��ǰ��ֵ
		 */
		int GetAndAdd(int delta);

		/**
		 * ��ԭ�ӷ�ʽ������ֵ�뵱ǰֵ���
		 * @param delta Ҫ���ϵ�ֵ
		 * @return ���µ�ֵ
		 */
		int AddAndGet(int delta);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ���µ�ֵ
		 */
		int IncrementAndGet();

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ���µ�ֵ
		 */
		int DecrementAndGet();

		/**
		 * i = 2
		 */
		int operator=(int newValue);

		/**
		 * ++i
		 */
		int operator++();

		/**
		 * i++
		 */
		int operator++(int);

		/**
		 * --i
		 */
		int operator--();

		/**
		 * i--
		 */
		int operator--(int);

		/**
		 * ����ת��������
		 */
		operator int () const;

		//////////////////////////////////////////////////////////////////////////

		/**
		 * �����ǰֵ == Ԥ��ֵ������ԭ�ӷ�ʽ����ֵ����Ϊ�����ĸ���ֵ
		 * @return ����ɹ����򷵻� true������ False ָʾʵ��ֵ��Ԥ��ֵ�����
		 */
		static bool CompareAndSet(volatile int *ptr, int expect, int update);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ��ǰ��ֵ
		 */
		static int GetAndIncrement(volatile int *ptr);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ��ǰ��ֵ
		 */
		static int GetAndDecrement(volatile int *ptr);

		/**
		 * ��ԭ�ӷ�ʽ������ֵ�뵱ǰֵ���
		 * @return ��ǰ��ֵ
		 */
		static int GetAndAdd(volatile int *ptr, int delta);

		/**
		 * ��ԭ�ӷ�ʽ������ֵ�뵱ǰֵ���
		 * @param delta Ҫ���ϵ�ֵ
		 * @return ���µ�ֵ
		 */
		static int AddAndGet(volatile int *ptr, int delta);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ���µ�ֵ
		 */
		static int IncrementAndGet(volatile int *ptr);

		/**
		 * ��ԭ�ӷ�ʽ����ǰֵ�� 1
		 * @return ���µ�ֵ
		 */
		static int DecrementAndGet(volatile int *ptr);

	private:
		volatile int m_nValue;
	};
};

#endif // end of LWPR_ATOMIC_INTEGER_H__
