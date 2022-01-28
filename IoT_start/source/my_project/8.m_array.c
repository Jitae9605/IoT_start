#include <stdio.h>

// 陥託据 壕伸

int main_m_array(void)
{
	/* 刃戟廃暗 爽汐坦軒遂 - 戚暗 走酔檎 喫
	
	// 陥託据 壕伸(Multi dimensional Array)
	// 壕伸戚 2託据生稽 糎仙馬澗 依 (植漆, 妊 去引 旭製 - 楳/伸)
	// 切戟莫 壕伸戚硯 [楳][伸]

	// 1. 1託据 壕伸
	int arr[5]; 
	// けけけけけ

	// [0][1][2][3][4]

	printf("----------------------------------\n");

	// 2. 2託据 壕伸
	int arr2[2][5];
	// けけけけけ
	// けけけけけ

	// [0,0][0,1][0,2][0,3][0,4]
	// [1,0][1,1][1,2][1,3][1,4]

	int arr3[4][2];
	// けけ
	// けけ
	// けけ
	// けけ

	// [0,0][0,1]
	// [1,0][1,1]
	// [2,0][2,1]
	// [3,0][3,1]

	printf("----------------------------------\n");

	// 3. 3託据 壕伸
	int arr4[3][3][3];
	// けけけ
	// けけけ
	// けけけ

	// けけけ
	// けけけ
	// けけけ

	// けけけ
	// けけけ
	// けけけ

	// [0,0,0][0,0,1][0,0,2]  --> arr4[0][0][0] ~ arr4[0][0][2]
	// [0,1,0][0,1,1][0,1,2]
	// [0,2,0][0,2,1][0,2,2]

	// [1,0,0][1,0,1][1,0,2]
	// [1,1,0][1,1,1][1,1,2]  --> arr4[1][1][0] ~ arr4[1][1][2]
	// [1,2,0][1,2,1][1,2,2] 

	// [2,0,0][2,0,1][2,0,2]
	// [2,1,0][2,1,1][2,1,2]
	// [2,2,0][2,2,1][2,2,2]  --> arr4[2][2][0] ~ arr4[2][2][2]


	printf("----------------------------------\n");

	// 陥託据 壕伸 識情 貢 舛税
	int arr[5] = { 1, 2, 3, 4, 5 };

	int arr2[2][5] = 
	{
		{1,2,3,4,5}, 
		{1,2,3,4,5} 
	};

	int arr3[4][2] = 
	{ 
		{1,2}, 
		{3,4}, 
		{5,6}, 
		{7,8} 
	};

	// arr3[4][2] 窒径
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("2託据 壕伸 (%d, %d) 税 葵精 : %d\n", i, j, arr3[i][j]);
		}
		printf("\n");
	}

	printf("----------------------------------\n");

	刃戟廃暗 爽汐坦軒遂 - 戚暗 走酔檎 喫 */

	int arr4[3][3][3] = 
	{ 
		{
			{1,2,3}, 
			{4,5,6}, 
			{7,8,9}
		},
		{
			{11,12,13}, 
			{14,15,16}, 
			{17,18,19}
		}, 
		{
			{21,22,23},
			{24,25,26},
			{27,28,29}
		} 
	};

	// arr4[3][3][3] 窒径
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
			printf("3託据 壕伸 (%d, %d, %d) 税 葵精 : %d\n", i, j, k, arr4[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("----------------------------------\n");



	return 0;
}