#include <stdio.h>
int mainPrintfScanf(void)
{
	/* �Ϸ��Ѱ� �ּ�ó���� - �̰� ����� ��
	 
	//������ ���� ����
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);
	printf("----------------------------------\n");

	// �Ǽ��� ���� ����
	float f = 46.5f; //float�� ���� ���� �ǵڿ��� �׻�"f"�� ���� ��
	printf("%.2f\n", f); //%f ��� %.2f �� �� ������ ����� �Ҽ� 2°�ڸ����� ����϶�� ǥ�� ������ ��� ��µȴ� ex) 46.500000
	double d = 4.428; 
	printf("%.2lf\n", d); // float�� %f double�� %lf �̴�
	const int YEAR = 2000; //const = ����� ���� = �� ���� ���ķ� ���� �ٲ��� ���� (�� �� ����)
	printf("�¾ �⵵ : %d\n", YEAR);
	printf("----------------------------------\n");

	// printf
	//����
	int add = 3 + 7; // 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d + %d = %d\n", 30, 79, 30 + 79);
	printf("%d * %d = %d\n", 30, 79, 30 * 79);
	printf("----------------------------------\n");

	//scanf
	//Ű���� �Է��� �޾Ƽ� ����
	int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &input); // "�޴� ������"(%d = �������� �ްڴ�), &input(= ���� ���� input�̶�� ������ �Է�)
	printf("�Է°� : %d\n", input);
	printf("\n");

	// ������ �޾Ƽ� ������ ���� �����ϴ� ��
	int one, two, three;
	printf("3���� ������ �Է��ϼ���. : ");
	scanf_s("%d %d %d", &one, &two, &three); // �Է��Ҷ� �� ���� ���⸦ ���� ����
	printf("ù ��° ��: %d\n", one);
	printf("�� ��° ��: %d\n", two);
	printf("�� ��° ��: %d\n", three);

	// ����(�� ����), ���ڿ�(���� ����)
	char c = 'A'; // ���� = char
	printf("%c\n", c); // ���� = %c
	
	char str[256]; // ���ڿ� = char str[�� ����]
	scanf_s("%s", str, sizeof(str)); //���ڿ� = %s, ���ڿ��� ������ '&'�� ���� ��� ũ�⸦ ����ؾ���(sizeof(���ڿ� �̸�))
	printf("%s\n", str);
	// �ǹ� : sizeof(s
	tr)�� ũ�Ⱑ 4���ε� ������� ���?
	printf("----------------------------------\n");

	�Ϸ��Ѱ� �ּ�ó���� - �̰� ����� �� */ 
	
	//������Ʈ
	// �������� �������� ������ �Լ�(���� �ۼ�)
	// �̸�? ����? ������? Ű? ���˸�?
	char name[256];
	printf("�̸��� ������? ");
	scanf_s("%s", name, sizeof(name));
	
	int age = 0;
	printf("����̿���? ");
	scanf_s("%d", &age);

	float weight = 0;
	printf("�����Դ� �� kg�̿���? ");
	scanf_s("%f", &weight);

	double height = 0;
	printf("Ű�� �� cm ����? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("���� ���˸� ���������? ");
	scanf_s("%s", what, sizeof(what));

	// �����������
	printf("\n\n--- ���������� ---\n\n");
	printf("�̸�    : %s\n", name);
	printf("����    : %d\n", age);
	printf("������  : %.2f\n", weight);
	printf("Ű      : %.2lf\n", height);
	printf("����    : %s\n", what);





	return 0;
}