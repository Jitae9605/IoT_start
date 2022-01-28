#include <stdio.h>

// �Լ����� - �����Լ� �ۿ��� �����ϰ� �����ؾ���
// ��ȯ�� �Լ��̸�(�ڷ��� ���ް�)
// ��ȯ�� = �Լ������� �����ϰ� ��ȯ�� ���� ���� (void = ��ȯ ����)
// p��� �̸��� �Լ��� �����ϰ� ����� ������ p�Լ��� ���� ���� �����ϴ� ��

void p(int i); // �Լ����� 1
void fuction_without_return(); // �Լ����� 2 - ��ȯ���� ���� �Լ�
int function_with_return(); // �Լ����� 3 - ��ȯ���� �ִ� �Լ�
void function_without_parameters(); // �Լ����� 4 - �Ķ���Ͱ� ���� �Լ�
void function_with_parameters(int num1, int num2, int num3); // �Լ����� 5 - �Ķ���Ͱ� �ִ� �Լ�
int apple(int total, int eat); // �Լ����� 6 - �Ķ���͵� �ְ� ���ް��� �ִ� �Լ�

// ������Ʈ ��� �Լ�����
void project_p(int num); // 1 - ���� ����ϴ� �Լ�(=)
int add(int num1, int num2); // 2 - ������� �Լ�(+)
int sub(int num1, int num2); // 3 - ������� �Լ�(-)
int mul(int num1, int num2); // 4 - ������� �Լ�(*)
int div(int num1, int num2); // 5 - ��������� �Լ� (/)

int main_function(void)
{
	/* �Ϸ��Ѱ� �ּ�ó���� - �̰� ����� ��
	
	// function
	// ����

	// �Լ��� ����� ����
	int num = 2;
	// printf("num�� %d �Դϴ�.\n", num); // 2
	p(num); // p��� ���ǵ� �Լ��� ȣ���ϰ� �޴� ���� num ���� �Է�

	// 2 + 3 = ?
	num = num + 3; // num += 3;
	// printf("num�� %d �Դϴ�.\n", num); // 5
	p(num);

	// 5 - 1 = ?
	num = num - 1;  // num -= 1;
	// printf("num�� %d �Դϴ�.\n", num); // 4
	p(num);

	// 4 * 3 = ?
	num = num * 3; // num *= 3;
	// print("num�� %d �Դϴ�.\n", num); // 12
	p(num);

	// 12 / 6 = ?
	num = num / 6; // num /= 6;
	// printf("num�� %d �Դϴ�.\n", num); // 2
	p(num);

	printf("----------------------------------\n");


	// �Լ� ����
	// ��ȯ���� ���� �Լ�(void �Լ�) - �Լ� ����/���� 4
	fuction_without_return();


	// ��ȯ���� �ִ� �Լ�(void ����) - �Լ� ����/���� 5
	int ret = function_with_return();
	p(ret);


	// �Ķ����(���ް�)�� ���� �Լ�
	function_without_parameters();


	// �Ķ���Ͱ� �ִ� �Լ�
	function_with_parameters(1, 2, 3);
	function_with_parameters(35, 17, 25);

	// �Ķ���͵� �ް� ��ȯ���� �ִ� �Լ�
	int ret = apple(5, 2); // 5���� ����߿��� 2���� �Ծ����� �ǹ�
	printf("���� ����� ������ %d �Դϴ�.\n", ret);

	// �Ǵ� �̷��Ե� ������
	printf("�� %d �� �߿� %d ���� �Ծ� %d �� ����.\n", 10, 4, apple (10, 4));
	
	�Ϸ��Ѱ� �ּ�ó���� - �̰� ����� �� */

	// ������Ʈ
	// ���� �Լ� �ۼ�

	int num = 2; // �ʱⰪ

	num = add(num, 3); // num = num + 3  = 5
	project_p(num);

	num = sub(num, 1); // num = num - 1  = 4
	p(num);

	num = mul(num, 3); // num = num * 3  = 12
	p(num);

	num = div(num, 6); //num = num / 6   = 2
	p(num);


	return 0;
}

// ���� - �����Լ� �ۿ��� �ռ� �����Ѱ��� �����ؾ���
// �ռ� ������ p��� �Լ��� ���೻��

// �Լ����� 1
void p(int i)
{
	printf("num�� %d �Դϴ�.\n", i);
}


// �Լ����� 2 - ��ȯ���� ���� �Լ�
void fuction_without_return()
{
	printf("��ȯ���� ���� �Լ� �Դϴ�.\n");
}

// �Լ����� 3 - ��ȯ���� �ִ� �Լ�
int function_with_return()
{
	printf("��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return 10;
}

// �Լ����� 4 - �Ķ���Ͱ� ���� �Լ�
void function_without_parameters()
{
	printf("���ް��� ���� �Լ��Դϴ�.\n");
}

// �Լ����� 5 - �Ķ���Ͱ� �ִ� �Լ�
void function_with_parameters(int num1, int num2, int num3)
{
	printf("���ް��� �ִ� �Լ��Դϴ�\n");
	printf("���޹��� ���� %d, %d, %d �Դϴ�.\n\n", num1, num2, num3);
}

// �Լ����� 6 - �Ķ���͵� �ְ� ���ް��� �ִ� �Լ�
int apple(int total, int eat) // ��ü(total)������ �԰�(eat) ���� ����(return) ���
{
	printf("�Ķ���Ϳ� ���ް��� ��� �ִ� �Լ��Դϴ�.\n");
	printf("�� ������ %d ���̰� ���� �� %d ���Դϴ�\n\n", total, eat);
	return total - eat;
}

// ������Ʈ ��� �Լ� ����
void project_p(int num) // 1 - ���
{
	printf("num�� %d �Դϴ�.\n", num);
}

int add(int num1, int num2) // 2 - ����
{
	return num1 + num2;
}

int sub(int num1, int num2) // 3 - ����
{
	return num1 - num2;
}

int mul(int num1, int num2) // 4 - ����
{
	return num1 * num2;
}

int div(int num1, int num2) // 5 - ������
{
	return num1 / num2;
}