#include <stdio.h>


// 5. ���ǹ�
// if, if-else, switch-case ���

int main_if(void)
{
	// 1. if���� �⺻ ����

	/*

	// 1) if��

	 if (���Ǻ�)
	 {
	 	�����;
	 }

	// * if �� ���� * 
	int a = 20;
	int b = 0;

	if (a > 10)								// a�� 10���� ũ�� ���ǽ��� ��
	{
		b = a;								// b = a ���Թ� ����
	}

	printf("a : %d, b : %d\n", a, b);		// ������ ����Ǹ� �� ���� ����

	*/

	/*

	// 2) if_else��

	if (���Ǻ�)
	{
		�����1;
	}
	else
	{
		�����2;
	}

	// * if-else�� ���� * 

	int a = 10;

	if (a >= 0)
	{
		a = 1;		// a�� 0���� ũ�ų� ������ a�� 1 ����
	}
	else
	{
		a = -1;		// a �� 0���� �۴ٸ� a�� -1 ����
	}
	printf("a : %d\n", a);

	*/

	/*

	// 3) if_else if��
	// else if�� ��� ��� X

	if (���Ǻ�1)
	{
		�����1;
	}
	else if (���Ǻ�2)
	{
		�����2;
	}
	else
	{
		�����3;
	}

	// * if-else if�� ���� * 

	int a = 0, b = 0;

	if (a > 0)			// a�� 0���� ũ�� b�� 1 ����
	{
		b = 1;
	}
	else if (a == 0)		// a�� 0�̸� b�� 2 ����
	{
		b = 2;
	}
	else					// a�� 0���� ũ���ʰ� 0�� �ƴϸ� b�� 3 ����
	{
		b = 3;
	}

	printf("b : %d\n", b);

	*/


	// 2. if�� ��ø
	// if���� ����ο� �ٽ� if���� ��ġ�� ��

	/*

	if (���Ǻ�1)
	{
		�����1
		if (���Ǻ�2)
		{
			�����2
		}
	}

	// * ��ø if�� ���� * 
	int a = 20, b = 10;

	if (a > 10)				// a�� 10���� ũ��  ������� if�� ����
	{
		if (b >= 0)			// b�� 0�̻��̸� b�� 1�� ����
		{
			b = 1;
		}
		else
		{
			b = -1;			// b�� 0���� ������ b�� -1 ����
		}
	}

	printf("a : %d, b : %d\n", a, b);

		*/
		
	/*

	// 3. switch ~ case ��
	// switch ~ case ���� ������ ���X  
	// �ܼ� �ٸ� ���꿡���� ������� ���� ����� ���
	// break ���ö����� ���Ǹ��� ������ ��� case����κ� ���� ����

	// * switch ~ case �� ���� 1 *
	// �⺻���� switch ~ case �� �� ���

	int rank = 2, m = 0;
	
	switch (rank)		//rank �� Ȯ��
	{
	case 1:
		m = 300;
		break;
	case 2:
		m = 200; 
		break;
	case 3:
		m = 100;
		break;
	default:
		m = 10;
		break;
	}

	printf("m : %d\n", m);

	// * switch ~ case �� ���� 2 *
	// switch ~ case �������� break Ȱ�� �� �ʿ伺

	int rank1 = 2, rank2 = 4, m1 = 0, m2 = 0;

	switch (rank1)					// rank1 �� Ȯ��
	{
	case 1:
		m1 += 100;
	case 2:
		m1 += 100;
	case 3:
		m1 += 100;
		break;
	case 4:
		m1 += 100;
	case 5:
		m1 += 100;
	case 6:
		m1 += 100;
		break;
	}

	switch (rank2)					// rank2 �� Ȯ��
	{
	case 1:
		m2 += 100;
	case 2:
		m2 += 100;
	case 3:
		m2 += 100;
		break;
	case 4:
		m2 += 100;
	case 5:
		m2 += 100;
	case 6:
		m2 += 100;
		break;
	}

	printf("rank1�� ���� : %d\n", m1); // m1 : 200
	printf("rank2�� ���� : %d\n", m2); // m2 : 300

	*/


	return 0;
}