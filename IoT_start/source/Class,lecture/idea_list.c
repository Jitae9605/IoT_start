#include <stdio.h>
#include <string.h>

int main1211(void)
{
	// ��������
	/*
	[1]
	����ī ���α׷�

	   �α����� �������� (������ / ȸ�� ���� ���̵� ����) - ȸ�������� ���Ͻø� 3�� �Է����ּ���.
	1. �����ڷ� �α����Ѱ�� = 1 = �ڵ������� ��ȸ/����/���, 2 = ȸ��������ȸ �� ����, 3 = �α׾ƿ�, 4 = ���α׷�����
	2. ȸ������ �α����Ѱ�� = ��Ʈ,�ݳ�(���� ��Ʈ���� ������ ��µǾ���), ȸ��Ż��(��й�ȣ ���Է����� Ȯ��), �α׾ƿ�
	3. 3�� �Է�(ȸ������) = ���̵��Է�(�̹� �����ϴ��� �����Ǵ�), ��й�ȣ�Է�(���ؿ� �´��� �Ǵ�), �ּ� �� �޴�����ȣ�Է�


	[2]
	���� ���α׷�

		�α��� ���� (ȸ������ + ���°���)
		ȸ���� ���¸� ����� �Ա�, ���, ���°� �۱�, ���ڰ��(����, �ܸ�) ���


	[3]
	���θ� ���α׷�(ǰ�� Ưȭ�� �����ҵ�?)

	1.	�α���/ȸ������
	2.	��ǰ������
	3.	��ǰ�� �����ϸ� ȸ���� ���¿��� �� �׾׸�ŭ ���, ��ǰ �������
	4.	��ǰ�� �Ǹŷ��� ���� ��ǰ����� �켱���� ��ȭ
	5.	��ǰ�� ����� 0�̵Ǹ� ���� �Ʒ��� ��ġ(����)
	6.	������ �ܰ��� �����Ϸ��� �ź��� �۴ٸ� �ȳ��ż��� ���
	7.	������ ������������ ������ ��ǰ��� ���� ���� ���� ������ �ܰ��� ���;��Ѵ�.
	8.	�α׾ƿ� �� ���α׷������ư
	9.	�α׾ƿ��ϰ� �ٸ� ���̵�� �α����ص� ������ ȸ���� �����ؼ� �پ�� ����� �����Ǿ���


	[4]
	�������� ���α׷�

	0.	ȸ������/�α���
	1.	�޷��� ���
	2.	������ �Է��ϸ� �޷¿� �ش������� ���
	3.	�ؾ����� ������
	4.	�ؾ����� �߰��ϸ� �ؾ����� ��Ͽ� �ش����� �߰���
	5.	�Ϸ�� ���� ��ȣ�� �Է¹����� �ش������� (�Ϸ�)�� ǥ��
	6.	��¥�� �Է��ϸ� �ش糯¥�� �ִ� ������ �ؾ����� ���(��� �׻����)�� ǥ��


	[5]
	����Ŀ�� �������α׷�

	0.	�α���(1 - ������ = �������� / 2 - ������ = ����Ŀ?����? / 3 - �Ǹ��� = ĳ��?������)

	1.	������
	-	�����ڿ��� �� ������ ���귮�� ����(�Ǹ��ڰ� ������ ������ ������ �����ش� �װ� ����/�ݷ�)
	-	���� ������ ���ݰ� ������ (�����Է»��¿��� ����)�Է�/����Ʈ���(���ͷ� �ڵ����)
	-	������ �� ��Ȳ ����Ʈ ���, �������
	-	������/�Ǹ��ڰ� ��û�� ��ǰ�� �ֹ�(���⿡�� ����)(��ǰ�� ������ ��ϵ��־����)
	-	��ǰ�� ���
	-	Ư�� �������� ������ ���డ��
	-	�� ������ ���귮 ��� �ҷ����� ����

	2.	������
	-	�������� �����ȹ�� ���
	-	������ ���� ������ ������ �Է�
	-	�ҷ�ǰ ���� �Է�
	-	�����ȹ�� ������ ��� (�Ϸ�)ǥ��
	-	�����ڿ��� �ʿ��� ��ǰ �ֹ���û(��Ͽ���)

	3.	�Ǹ���
	-	�Ǹŵ� ���� ����� ������ �Է�
	-	�� �ݾ��� ����� ���⿡ �ݿ�
	-	�ʿ��� ��ǰ, ������ ���� ������ ������ �����ڿ��� ����

	--------------------------------------------------------
	���ӿ��� - ���� �������Լ��� �ʿ�!
	--------------------------------------------------------

	[1] - ( �̴�������Ʈ - 1 )
	�̴ϰ���õ��(�����γ��п� ����?)
	1.	up / down
	-	ȭ�鿡 ������ ���ڸ� ����ϰ� ���� ���� ū��/���� �� �� �Է¹޴´�
	-	(�ɸ��ð� + ���� ����)�� ���߷�, ����, �Ǵܷ� ����up
	-	������� ���̵�up(������ �ڸ���, ��µǴ� ������ �� ����)

	2.	�ϻ�
	-	ȭ�鿡 ������ ��� 
	-	������ �Է��ϸ� �� �ð��� ���� ���߷� ����, ���᰹�������� ���� ���� up
	-	������� ���̵�up(������ �ڸ���, ������ �� ����)

	3.	û�� ��� 
	-	ȭ�鿡 �����ϰ� û�� �÷�, ������ ���
	-	û��� 1(�ø�) 2(����)
	-	���� 4(�ø�) 5(����)
	-	�ð��� Ʋ�� Ƚ���� ���߷�, �Ǵܷ� up

	4. Ʋ���׸�ã��
	-	5*5�� ������ Ư�����ڵ��� 2�� ��� 
	-	���� ������ �迭�� �������� �ϳ��� �ٸ� ������ �ִ�
	-	�� �ٸ� ���� ��ǥ�� �Է��ϸ� ( 11 ~ 55 ) ����. 
	-	�ɸ��ð��� ���᰹���� �����ڰ���, ���߷�, �Ǵܷ� ���� up
	
	n.	(��/���)
	-	���߷�,�����ڰ���,�Ǵܷ�,����
	-	�� ���ӿ����� ������ ���� �ؼ� ������ �ɷ¿� ����� �ο��ϰ� ���
	-	���� ������ �ջ��ؼ� ����� ���
	-	��ŷ �ý��ۿ� �̸� ���

	[2]
	TRPG ��������
	1.	ó�����۽� 25���� ��ǰ�� ������ ��ǰ�� 10�� ì���
	2.	10���� �̺�Ʈ�� �߻�
	3.	�� �̺�Ʈ���� 10���� ��ǰ�� �ϳ��� ����Ѵ�
	4.	������ �̺�Ʈ���� ������ ��ǰ�� ���� ���, ������ �����ϰ� �����ϰ�� �λ�(hp, �����̻�-����/��)ǥ�� �ٸ� ��ǰ�� ���� ���� �ִ�.
	5.	�̺�Ʈ�� ����ǰ� ��ǰ�� ����Ұ��� �����ϴ� �޼��� ����ؼ� ����� ����
	-	ex) ü������ = hpȸ��, �ش� = ����ȸ��, ���� = ���� ��ī���� Ȯ�� �� ���ذ��� ����
	-	������ ��Ʈ������ + ����/�߻����� ��ī������ Ȯ���� ���δ�
	6.	��� �������� �������� ���Ƚ���� �ְ� �̴� ���/����/�̺�Ʈ������ ������� ���ҵǾ� 0�̵Ǹ� �ı�
	7.	��ī�����߿��� �̸� ȸ���Ҽ��ִ°� �ִ�
	-	���尣 = ������ ������/���Ƚ�� ����ȸ�� (���ϼ� ���� - ���� �̲�����)
	-	���ݼ����� = ������ ���Ƚ�� + 1 ~ 3	(����Ȯ���� �����ɸ�)
	-	��ɲ� ���� = ��ǰ�� ����(�ش�,����,����) (���� Ȯ���� �� �̺�Ʈ�� ���� ���� �λ� �� hp����)
	-	���
	8.	��� ��ī���͸� �غ��ϸ� ������ ĳ���� �����¸� ����ϸ鼭 hp�ܷ�, ��ǰ�� �������� ���Ƚ�� �ܷ�, �����̻� ���� � ���� ������ �Űܼ� ����
	9.	���������� ��µǴ� ������ ����
	-	����� ����
	-	�״°� ����������
	-	������ ����	

	[3] 
	�������
	1.	�׳� �θ�����
	2.	��, �ں����� �θ����� �ѹ��� �������� ���ڿ� ���� + (���������� ���� ������ ������ �������� ������ �����̻��� ������ ������ �߰�����)
	3.	�Դٰ� ������ �ִ� �ε���/����/�ǹ��� ���󼭵� �ڻ��� Ư���ǰ� �̿� ���� ������ ���γ��´�.
	4.	��, �ƹ��� �ڻ��� ���Ƶ� ������ �� ���� ����� �����ϰ�
	5.	�ڻ��� �ƹ��� ��� �� ���� ��Ȱ �� �� �ִ�.
	6.	�ڻ��� ������ ������ ����(��Ÿũ����Ʈ �������ð� ����)
	-	�� �������� �������� ���������� �ֽ�(�ѹ��� �������� ���� ������ �ִ� ���� ��ġ�� ��ȭ -30 ~ +30% ����)
	-	�� �ϸ��� ���������� ��Ʈ���� ( - 99 ~ + 300 % )  ( + �� ������ ū ��ŭ Ȯ���� ���Ⲩ�� -�� �� �߳����� ) 
	-	�׳� ���� ������ ��������
	-	���ڵ� �ȳ����� �ƹ��͵� �ȳ������� �����ݾ��� �ڻ����� ���ȵǴ� ����
	7.	�ڻ� ������ ���� ���/����/������ ī���� ȿ���� ����
	-	ex) ��Ʈ���� = �ŷ��� ��ŷ / �Ϸиӽ�ũ�� ����� / �Ѱ� ���µ� ����
	-		�ֽ� = ���÷��̼� / ����� ���� ���尡������ /	ȣ�簡 �ƴ϶� ȭ��
			���� = �ݸ��λ� / ���൵�� / �� 2�� ����� ����
			���� = �����̾�! / ������! / �ζǾ�! / Ⱦ���!
			���
	8.	�������� �������� �ڻ갡ġ�� ���� or �����̻��� �ݾ��� ������ �¸�

		



	*/
}