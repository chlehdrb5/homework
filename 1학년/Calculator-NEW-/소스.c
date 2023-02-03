#include <stdio.h>

struct BigNum

{

	int i_digit[100];
	int d_digit[100];
	int i_total_digit;
	int d_total_digit;
	int i_digit_add[100];
	int d_digit_add[100];
	int sign;
};

int enter_number(char *input, struct BigNum *object);
int compare_number(struct BigNum *object, struct BigNum *object2);
int plus(struct BigNum *object, struct BigNum *object2, struct BigNum *object3);
int minus(struct BigNum *object, struct BigNum *object2, struct BigNum *object3);
int multiple(struct BigNum *object, struct BigNum *object2, struct BigNum *object3);
int divide(struct BigNum *object, struct BigNum *object2, struct BigNum *object3, struct BigNum *object4, struct BigNum *object5, struct BigNum *object6, int *d_total);

int main()

{
	char input[201], input2[201], operation;
	int i, j, k;
	struct BigNum object[6];
	j = 0;
	printf("큰 수 계산기입니다. 정수 100자리, 소수 100자리 까지 입력 가능합니다. \n연산은 사칙연산만 가능합니다. 결과값이 정수, 소수 100자리를 넘어가면 표기는 되나 연산이 제대로 되지 않습니다.\n");
	printf("수를 입력해 주십시오. \n");
	scanf("%s", input);
	enter_number(input, &object[0]);

	for (;;)
	{
		printf("수행하려는 연산을 입력해 주십시오. 이전 연산을 취소하려면 '!'를, 종료하려면 x 를 입력하십시오. +.-.*./:");
		scanf(" %c", &operation);
		if (operation == 'x')
		{
			printf("계산기를 종료합니다. \n");
			break;
		}

		if (operation == '+')

		{
			printf("두 번째 수를 입력해 주십시오. \n");
			scanf("%s", &input2);
			enter_number(input2, &object[1]);
			if (object[0].sign>0 && object[1].sign>0)
			{
				plus(&object[0], &object[1], &object[2]);
			}

			else if (object[0].sign <0 && object[1].sign<0)
			{
				plus(&object[0], &object[1], &object[2]);
			}
			else if (object[0].sign>0 && object[1].sign<0)
			{
				minus(&object[0], &object[1], &object[2]);
			}

			else

			{

				minus(&object[1], &object[0], &object[2]);

			}

			printf("결과를 출력합니다. \n");

			if (object[2].sign < 0)

			{

				printf("-");

			}

			for (i = 0; i<object[2].i_total_digit; i++)

			{

				printf("%d", object[2].i_digit[object[2].i_total_digit - i - 1]);

			}

			if (object[2].d_total_digit>0)

			{

				printf(".");

			}

			for (i = 0; i<object[2].d_total_digit; i++)

			{

				printf("%d", object[2].d_digit[object[2].d_total_digit - i - 1]);

			}

			printf("\n");

			object[3] = object[0];

			object[0] = object[2];

		}

		else if (operation == '-')

		{

			printf("두 번째 수를 입력해 주십시오. \n");

			scanf("%s", &input2);

			enter_number(input2, &object[1]);

			if (object[0].sign > 0 && object[1].sign > 0)

			{

				minus(&object[0], &object[1], &object[2]);

			}

			else if (object[0].sign > 0 && object[1].sign < 0)

			{

				plus(&object[0], &object[1], &object[2]);

			}

			else if (object[0].sign < 0 && object[1].sign > 0)

			{

				plus(&object[0], &object[1], &object[2]);

			}

			else

			{

				minus(&object[0], &object[1], &object[2]);

			}

			printf("결과를 출력합니다. \n");

			if (object[2].sign < 0)

			{

				printf("-");

			}

			for (i = 0; i<object[2].i_total_digit; i++)

			{

				printf("%d", object[2].i_digit[object[2].i_total_digit - i - 1]);

			}

			if (object[2].d_total_digit>0)

			{

				printf(".");

			}

			for (i = 0; i<object[2].d_total_digit; i++)

			{

				printf("%d", object[2].d_digit[object[2].d_total_digit - i - 1]);

			}

			printf("\n");

			object[3] = object[0];

			object[0] = object[2];

		}

		else if (operation == '*')

		{

			printf("두 번째 수를 입력해 주십시오. \n");

			scanf("%s", &input2);

			enter_number(input2, &object[1]);

			multiple(&object[0], &object[1], &object[2]);

			printf("결과를 출력합니다. \n");

			if (object[2].sign < 0)

			{

				printf("-");

			}

			if (object[2].i_total_digit>100)

			{

				for (i = 0; i<object[2].i_total_digit - 100; i++)

				{

					printf("%d", object[2].i_digit_add[object[2].i_total_digit - 100 - 1 - i]);

				}

				for (i = 0; i<100; i++)

				{

					printf("%d", object[2].i_digit[99 - i]);

				}

			}

			else

			{

				for (i = 0; i<object[2].i_total_digit; i++)

				{

					printf("%d", object[2].i_digit[object[2].i_total_digit - i - 1]);

				}

			}

			if (object[2].d_total_digit>0)

			{

				printf(".");

			}

			if (object[2].d_total_digit>100)

			{

				for (i = 0; i<100; i++)

				{

					printf("%d", object[2].d_digit[99 - i]);

				}

				for (i = 0; i<object[2].d_total_digit - 100; i++)

				{

					printf("%d", object[2].d_digit_add[object[2].d_total_digit - 100 - 1 - i]);

				}

			}

			else

			{

				for (i = 0; i<object[2].d_total_digit; i++)

				{

					printf("%d", object[2].d_digit[object[2].d_total_digit - i - 1]);

				}

			}

			printf("\n");

			object[3] = object[0];

			object[0] = object[2];

		}

		else if (operation == '/')

		{

			printf("두 번째 수를 입력해 주십시오. \n");

			scanf("%s", &input2);

			enter_number(input2, &object[1]);

			printf("소수점 몇번째까지 계산하겠습니까? 최대 100까지 입력 가능합니다 : ");

			scanf("%d", &k);

			if (k <= 100)

			{

				divide(&object[0], &object[1], &object[2], &object[3], &object[4], &object[5], &k);

			}

			else

			{

				printf("연산 가능한 범위를 벗어납니다. \n");

				continue;

			}

			printf("결과를 출력합니다. \n");

			if (object[2].sign < 0)

			{

				printf("-");

			}

			if (object[2].i_total_digit>100)

			{

				for (i = 0; i<object[2].i_total_digit - 100; i++)

				{

					printf("%d", object[2].i_digit_add[object[2].i_total_digit - 100 - 1 - i]);

				}

				for (i = 0; i<100; i++)

				{

					printf("%d", object[2].i_digit[99 - i]);

				}

			}

			else

			{

				for (i = 0; i<object[2].i_total_digit; i++)

				{

					printf("%d", object[2].i_digit[object[2].i_total_digit - i - 1]);

				}

			}

			if (object[2].d_total_digit>0)

			{

				printf(".");

			}

			if (object[2].d_total_digit>100)

			{

				for (i = 0; i<100; i++)

				{

					printf("%d", object[2].d_digit[99 - i]);

				}

				for (i = 0; i<object[2].d_total_digit - 100; i++)

				{

					printf("%d", object[2].d_digit_add[object[2].d_total_digit - 100 - 1 - i]);

				}

			}

			else

			{

				for (i = 0; i<object[2].d_total_digit; i++)

				{

					printf("%d", object[2].d_digit[object[2].d_total_digit - i - 1]);

				}

			}

			printf("\n");

			object[3] = object[0];

			object[0] = object[2];

		}

		else if (operation == '!')

		{

			printf("연산을 되돌립니다. \n");

			object[0] = object[3];

			printf("현재 입력되어 있는 수는 ");

			if (object[0].sign < 0)

			{

				printf("-");

			}

			for (i = 0; i<object[0].i_total_digit; i++)

			{

				printf("%d", object[0].i_digit[object[0].i_total_digit - i - 1]);

			}

			if (object[0].d_total_digit>0)

			{

				printf(".");

			}

			for (i = 0; i<object[0].d_total_digit; i++)

			{

				printf("%d", object[0].d_digit[object[0].d_total_digit - i - 1]);

			}

			printf(" 입니다. \n");

		}

		else if (operation == 'x')

		{

			printf("계산기를 종료합니다. \n");

			break;

		}

		else

		{

			printf("잘못된 연산입니다.\n");

		}

	}

	return 0;

}

int enter_number(char *input, struct BigNum *object)

{

	int i, j, l;

	i = j = l = 0;

	object->i_total_digit = 0;

	object->d_total_digit = 0;

	if (*input == '-')

	{

		input++;

		while (*input != '.'&&*input != '\0')

		{

			i++;

			input++;

		}

		j = i;

		input = input - i;

		i = 0;

		for (i = 0; i<j; i++)

		{

			object->i_digit[j - i - 1] = (int)*input - 48;

			object->i_total_digit++;

			input++;

		}

		if (*input != '\0')

		{

			input++;

		}

		while (*input)

		{

			object->d_total_digit++;

			l++;

			input++;

		}

		input = input - l;

		for (i = 0; i<l; i++)

		{

			object->d_digit[l - i - 1] = (int)*input - 48;

			input++;

		}

		input = input - object->i_total_digit - object->d_total_digit - 2;

		l = 0;

		object->sign = -1;

	}

	else

	{

		while (*input != '.' && *input != '\0')

		{

			i++;

			input++;

		}

		j = i;

		input = input - i;

		i = 0;

		for (i = 0; i<j; i++)

		{

			object->i_digit[j - i - 1] = (int)*input - 48;

			object->i_total_digit++;

			input++;

		}

		if (*input == '.')

		{

			input++;

		}

		while (*input)

		{

			object->d_total_digit++;

			l++;

			input++;

		}

		input = input - l;

		for (i = 0; i<l; i++)

		{

			object->d_digit[l - i - 1] = (int)*input - 48;

			input++;

		}

		input = input - object->i_total_digit - object->d_total_digit - 1;

		l = 0;

		object->sign = 1;

	}

	return 0;

}

int compare_number(struct BigNum *object, struct BigNum *object2)

{

	int i, j, k;

	j = 0; k = 0;

	for (i = 0; i<400; i++)

	{

		if (object->i_total_digit > object2->i_total_digit)

		{

			j = 1;

			k = 1;

			break;

		}

		else if (object2->i_total_digit > object->i_total_digit)

		{

			j = 1;

			k = 2;

			break;

		}

		else if (object2->i_total_digit == object->i_total_digit)

		{

			if (object->i_digit[object->i_total_digit - i - 1] > object2->i_digit[object2->i_total_digit - i - 1])

			{

				j = 1;

				k = 1;

				break;

			}

			else if (object2->i_digit[object2->i_total_digit - i - 1] > object->i_digit[object->i_total_digit - i - 1])

			{

				j = 1;

				k = 2;

				break;

			}

			else if (object2->i_digit[object2->i_total_digit - i - 1] == object->i_digit[object->i_total_digit - i - 1])

			{

				if (i>object->i_total_digit || i>object2->i_total_digit)

				{

					i = 0;

					break;

				}

				else if (object->i_digit[0] == 0 && object->i_total_digit == 1)

				{

					i = 0;

					break;

				}

			}

		}

	}

	if (j == 0)

	{

		for (;;)

		{

			if (object->d_digit[object->d_total_digit - 1 - i] > object2->d_digit[object2->d_total_digit - 1 - i])

			{

				j = 1;

				k = 1;

				break;

			}

			else if (object2->d_digit[object2->d_total_digit - 1 - i] > object->d_digit[object->d_total_digit - 1 - i])

			{

				j = 1;

				k = 2;

				break;

			}

			else

			{

				if (i<object->d_total_digit && i<object2->d_total_digit)

				{

					i++;

				}

				else

				{

					if (object->d_total_digit == object2->d_total_digit)

					{

						j = 1;

						k = 0;

						break;

					}

					else if (object->d_total_digit > object2->d_total_digit)

					{

						j = 1;

						k = 1;

						break;

					}

					else

					{

						j = 1;

						k = 2;

						break;

					}

				}

			}

		}

	}

	return k;

}

int plus(struct BigNum *object, struct BigNum *object2, struct BigNum *object3)

{

	int i, j, k, m;

	m = 0;

	if (object->d_total_digit > object2->d_total_digit)

	{

		for (j = 0; j<object2->d_total_digit; j++)

		{

			object3->d_digit[j + object2->d_total_digit] = object2->d_digit[j] + object->d_digit[j + object2->d_total_digit];

		}

		object3->d_total_digit = object->d_total_digit;

	}

	else if (object->d_total_digit == object2->d_total_digit)

	{

		for (i = 0; i<object2->d_total_digit; i++)

		{

			object3->d_digit[i] = object->d_digit[i] + object2->d_digit[i];

		}

		object3->d_total_digit = object2->d_total_digit;

	}

	else

	{

		k = object2->d_total_digit - object->d_total_digit;

		for (j = 0; j<object->d_total_digit; j++)

		{

			object3->d_digit[j + k] = object->d_digit[j] + object2->d_digit[j + k];

		}

		for (j = 0; j<object2->d_total_digit; j++)

		{

			object3->d_digit[j] = object2->d_digit[j];

		}

		object3->d_total_digit = object2->d_total_digit;

	}



	if (object->i_total_digit>object2->i_total_digit)

	{

		for (j = 0; j<object2->i_total_digit; j++)

		{

			object3->i_digit[j] = object->i_digit[j] + object2->i_digit[j];

		}

		for (j = object2->i_total_digit; j<object->i_total_digit; j++)

		{

			object3->i_digit[j] = object->i_digit[j];

		}

		object3->i_total_digit = object->i_total_digit;

	}

	else if (object->i_total_digit == object2->i_total_digit)

	{

		for (j = 0; j<object->i_total_digit; j++)

		{

			object3->i_digit[j] = object->i_digit[j] + object2->i_digit[j];

		}

		object3->i_total_digit = object2->i_total_digit;

	}

	else

	{

		for (j = 0; j<object->i_total_digit; j++)

		{

			object3->i_digit[j] = object->i_digit[j] + object2->i_digit[j];

		}

		for (j = object->i_total_digit; j<object2->i_total_digit; j++)

		{

			object3->i_digit[j] = object2->i_digit[j];

		}

		object3->i_total_digit = object2->i_total_digit;

	}

	for (j = 0; j<object3->d_total_digit; j++)

	{

		if (object3->d_digit[j]>9)

		{

			object3->d_digit[j] = object3->d_digit[j] - 10;

			if (j == object3->d_total_digit - 1)

			{

				if (object3->i_digit[0] >= 0 && object3->i_digit[0] < 20)

				{

					object3->i_digit[0] = object3->i_digit[0] + 1;

				}

				else

				{

					object3->i_digit[0] = 1;

				}

			}

			else

			{

				object3->d_digit[j + 1] = object3->d_digit[j + 1] + 1;

			}

		}

	}

	for (j = 0; j<object3->i_total_digit; j++)

	{

		if (object3->i_digit[j]>9)

		{

			object3->i_digit[j] = object3->i_digit[j] - 10;

			if (j == 99)

			{

				object3->i_digit_add[0] = 1;

				object3->i_total_digit++;

			}

			else

			{

				if (object3->i_digit[j + 1]<20 && object3->i_digit[j + 1] >= 0)

				{

					object3->i_digit[j + 1]++;

				}

				else

				{

					object3->i_digit[j + 1] = 1;

					object3->i_total_digit++;

				}



			}

		}

	}

	if (object3->d_digit[0] == 0)

	{

		object3->d_total_digit--;

		for (j = 1; j<object3->d_total_digit; j++)

		{

			if (object3->d_digit[j] == 0)

			{

				object3->d_total_digit--;

			}

			else

			{

				break;

			}

		}

	}

	object3->sign = object->sign;

	return 0;

}

int minus(struct BigNum *object, struct BigNum *object2, struct BigNum *object3)

{

	int i, j, k;

	k = compare_number(object, object2);

	if (object->i_total_digit>object2->i_total_digit)

	{

		if (object->d_total_digit>object2->d_total_digit)

		{

			object3->i_total_digit = object2->i_total_digit;

			object3->d_total_digit = object->d_total_digit;

		}

		else

		{

			object3->i_total_digit = object2->i_total_digit;

			object3->d_total_digit = object2->d_total_digit;

		}

	}

	else if (object->i_total_digit == object2->i_total_digit)

	{

		if (object->d_total_digit>object2->d_total_digit)

		{

			object3->i_total_digit = object->i_total_digit;

			object3->d_total_digit = object->d_total_digit;

		}

		else

		{

			object3->i_total_digit = object->i_total_digit;

			object3->d_total_digit = object2->d_total_digit;

		}

	}

	else

	{

		if (object->d_total_digit>object2->d_total_digit)

		{

			object3->i_total_digit = object->i_total_digit;

			object3->d_total_digit = object->d_total_digit;

		}

		else

		{

			object3->i_total_digit = object->i_total_digit;

			object3->d_total_digit = object2->d_total_digit;

		}

	}

	for (i = 0; i<object3->i_total_digit; i++)

	{

		object3->i_digit[i] = object->i_digit[i] - object2->i_digit[i];

	}

	if (object->i_total_digit>object2->i_total_digit)

	{

		for (i = object3->i_total_digit; i<object->i_total_digit; i++)

		{

			object3->i_digit[i] = object->i_digit[i];

		}

		object3->i_total_digit = object->i_total_digit;

	}

	else

	{

		for (i = object3->i_total_digit; i<object2->i_total_digit; i++)

		{

			object3->i_digit[i] = 0 - object2->i_digit[i];

			j++;

		}

		object3->i_total_digit = object2->i_total_digit;

	}

	if (object->d_total_digit>object2->d_total_digit)

	{

		j = object->d_total_digit - object2->d_total_digit;

	}

	else

	{

		j = object2->d_total_digit - object->d_total_digit;

	}

	if (object->d_total_digit>object2->d_total_digit)

	{

		for (i = 0; i<j; i++)

		{

			object3->d_digit[i] = object->d_digit[i];

		}

		for (i = j; i<object3->d_total_digit; i++)

		{

			object3->d_digit[i] = object->d_digit[i] - object2->d_digit[i - j];

		}

	}

	else if (object->d_total_digit == object2->d_total_digit)

	{

		for (i = 0; i<object->d_total_digit; i++)

		{

			object3->d_digit[i] = object->d_digit[i] - object2->d_digit[i];

		}

	}

	else

	{

		for (i = 0; i<j; i++)

		{

			object3->d_digit[i] = 0 - object2->d_digit[i];

		}

		for (i = j; i<object3->d_total_digit; i++)

		{

			object3->d_digit[i] = object->d_digit[i - j] - object2->d_digit[i];

		}

	}

	if (k == 1)

	{

		for (i = 0; i<object3->d_total_digit; i++)

		{

			if (object3->d_digit[i]<0)

			{

				object3->d_digit[i] = object3->d_digit[i] + 10;

				if (i == 99 || i == object3->d_total_digit - 1)

				{

					object3->i_digit[0]--;

				}

				else

				{

					object3->d_digit[i + 1]--;

				}

			}

		}

		for (i = 0; i<object3->i_total_digit; i++)

		{

			if (object3->i_digit[i]<0)

			{

				object3->i_digit[i] = object3->i_digit[i] + 10;

				object3->i_digit[i + 1]--;

			}

		}

		object3->sign = object->sign;

	}

	else if (k == 2)

	{

		for (i = 0; i<object3->d_total_digit; i++)

		{

			object3->d_digit[i] = 0 - object3->d_digit[i];

			if (object3->d_digit[i]<0)

			{

				if (i == 99)

				{

					object3->i_digit[0]--;

				}

				else if (i == object3->d_total_digit - 1)

				{

					object3->d_digit[i] = object3->d_digit[i] + 10;

					object3->i_digit[0]++;

				}

				else

				{

					object3->d_digit[i] = object3->d_digit[i] + 10;

					object3->d_digit[i + 1]++;

				}

			}

		}

		for (i = 0; i<object3->i_total_digit; i++)

		{

			object3->i_digit[i] = 0 - object3->i_digit[i];

			if (object3->i_digit[i]<0)

			{

				object3->i_digit[i] = object3->i_digit[i] + 10;

				object3->i_digit[i + 1]++;

			}

		}

		object3->sign = 0 - object->sign;

	}

	for (i = 0; i<object3->d_total_digit; i++)

	{

		if (object3->d_digit[i] == 0)

		{

			object3->d_total_digit--;

		}

		else

		{

			break;

		}

	}

	j = 0;

	for (i = 0; i<object3->i_total_digit; i++)

	{



		if (object3->i_digit[object3->i_total_digit - 1 - i] == 0)

		{

			j++;

		}

		else

		{

			object3->i_total_digit = object3->i_total_digit - j;

			j = 0;

			break;

		}

	}

	return 0;

}

int multiple(struct BigNum *object, struct BigNum *object2, struct BigNum *object3)

{

	int i, j, k, l, m, n, o;

	int obj_num[200], obj2_num[200], obj3_num[400];

	for (i = 0; i<object->d_total_digit; i++)

	{

		obj_num[i] = object->d_digit[i];

	}

	for (i = 0; i<object->i_total_digit; i++)

	{

		obj_num[i + object->d_total_digit] = object->i_digit[i];

	}

	for (i = 0; i<object2->d_total_digit; i++)

	{

		obj2_num[i] = object2->d_digit[i];

	}

	for (i = 0; i<object2->i_total_digit; i++)

	{

		obj2_num[i + object2->d_total_digit] = object2->i_digit[i];

	}

	object3->d_total_digit = object->d_total_digit + object2->d_total_digit;

	object3->i_total_digit = object->i_total_digit + object2->i_total_digit;

	if (object->i_digit[object->i_total_digit - 1] * object2->i_digit[object2->i_total_digit - 1])

	{

		object3->i_total_digit++;

	}

	for (i = 0; i<object3->i_total_digit + object3->d_total_digit; i++)

	{

		obj3_num[i] = 0;

	}

	for (i = 0; i<object2->d_total_digit + object2->i_total_digit; i++)

	{

		for (j = 0; j<object->d_total_digit + object->i_total_digit; j++)

		{

			k = obj_num[j] * obj2_num[i];

			l = k / 10;

			n = k % 10;

			obj3_num[i + j] = obj3_num[i + j] + n;

			obj3_num[i + j + 1] = obj3_num[i + j + 1] + l;

			if (obj3_num[i + j]>9)

			{

				obj3_num[i + j] = obj3_num[i + j] - 10;

				obj3_num[i + j + 1]++;

			}

			if (obj3_num[i + j + 1]>9)

			{

				obj3_num[i + j + 1] = obj3_num[i + j + 1] - 10;

				obj3_num[i + j + 2]++;

			}

		}

	}

	if (object3->d_total_digit>100 && object3->i_total_digit>100)

	{

		for (i = 0; i<object3->d_total_digit - 100; i++)

		{

			object3->d_digit_add[i] = obj3_num[i];

		}

		for (i = 0; i<100; i++)

		{

			object3->d_digit[i] = obj3_num[i + object3->d_total_digit - 100];

			object3->i_digit[i] = obj3_num[i + object3->d_total_digit];

		}

		for (i = 0; i<object3->i_total_digit - 100; i++)

		{

			object3->i_digit_add[i] = obj3_num[i + object3->d_total_digit + object3->i_total_digit - 100];

		}

	}

	else if (object3->d_total_digit>100 && object3->i_total_digit <= 100)

	{

		for (i = 0; i<object3->d_total_digit - 100; i++)

		{

			object3->d_digit_add[i] = obj3_num[i];

		}

		for (i = 0; i<100; i++)

		{

			object3->d_digit[i] = obj3_num[i + object3->d_total_digit - 100];

		}

		for (i = 0; i<object3->i_total_digit; i++)

		{

			object3->i_digit[i] = obj3_num[i + object3->d_total_digit];

		}

	}

	else if (object3->d_total_digit <= 100 && object3->i_total_digit>100)

	{

		for (i = 0; i<object3->d_total_digit; i++)

		{

			object3->d_digit[i] = obj3_num[i];

		}

		for (i = 0; i<100; i++)

		{

			object3->i_digit[i] = obj3_num[i + object3->d_total_digit];

		}

		for (i = 0; i<object3->i_total_digit - 100; i++)

		{

			object3->i_digit_add[i] = obj3_num[i + object3->d_total_digit + object3->i_total_digit - 100];

		}

	}

	else

	{

		for (i = 0; i<object3->d_total_digit; i++)

		{

			object3->d_digit[i] = obj3_num[i];

		}

		for (i = 0; i<object3->i_total_digit; i++)

		{

			object3->i_digit[i] = obj3_num[i + object3->d_total_digit];

		}

	}

	if (object3->d_total_digit>100)

	{

		for (i = 0; i<object3->d_total_digit - 100; i++)

		{

			if (object3->d_digit_add[i] == 0)

			{

				for (j = 0; j<object3->d_total_digit - 100; j++)

				{

					object3->d_digit_add[j] = object3->d_digit_add[j + 1];

				}

				object3->d_total_digit--;

			}

			else

			{

				m = 0;

				break;

			}

		}

		if (m != 0)

		{

			for (i = 0; i<100; i++)

			{

				if (object3->d_digit[i] == 0)

				{

					for (j = 0; j<object3->d_total_digit; j++)

					{

						object3->d_digit[j] = object3->d_digit[j + 1];

					}

					object3->d_total_digit--;

				}

				else

				{

					m = 1;

					break;

				}

			}

		}

	}

	else

	{

		for (i = 0; i<object3->d_total_digit; i++)

		{

			if (object3->d_digit[i] == 0)

			{

				for (j = 0; j<object3->d_total_digit; j++)

				{

					object3->d_digit[j] = object3->d_digit[j + 1];

				}

				object3->d_total_digit--;

			}

			else

			{

				break;

			}

		}

	}

	if (object3->i_total_digit>100)

	{

		for (i = 0; i<object3->i_total_digit - 100; i++)

		{

			if (object3->i_digit_add[i] == 0)

			{

				object3->i_total_digit--;

			}

			else

			{

				m = 0;

				break;

			}

		}

		if (m != 0)

		{

			for (i = 0; i<100; i++)

			{

				if (object3->i_digit[99 - i] == 0)

				{

					object3->i_total_digit--;

				}

				else

				{

					m = 1;

					break;

				}

			}

		}

	}

	else

	{

		o = object3->i_total_digit;

		for (i = 0; i<object3->i_total_digit; i++)

		{

			if (object3->i_digit[o - 1 - i] == 0)

			{

				object3->i_total_digit--;

			}

			else

			{

				break;

			}

		}

	}

	object3->sign = object->sign * object2->sign;

	return 0;

}

int divide(struct BigNum *object, struct BigNum *object2, struct BigNum *object3, struct BigNum *object4, struct BigNum *object5, struct BigNum *object6, int *d_total)

{

	int i, j, k, l;

	int a, b, c, d, e;

	a = object->sign;

	b = object2->sign;

	c = d = 0; e = 0;

	j = k = l = 0;

	object->sign = 1; object2->sign = 1;

	object3->i_total_digit = object3->d_total_digit = 0;

	*object6 = *object;

	*object4 = *object2;

	if (object->i_total_digit == 1 && object->i_digit[0] == 0)

	{

		d++;

		object->i_digit[0] = object->d_digit[object->d_total_digit - 1];

		for (i = 0; i<object->d_total_digit; i++)

		{

			object->d_digit[object->d_total_digit - 1 - i] = object->d_digit[object->d_total_digit - 1 - i];

		}

		object->d_digit[0] = 0;

	}

	if (object2->i_total_digit == 1 && object2->i_digit[0] == 0)

	{

		for (i = 0; i<100; i++)

		{

			if (object4->d_digit[object->d_total_digit - 1 - i] == 0)

			{

				e++;

			}

			else

			{

				break;

			}

		}

		object4->i_digit[0] = object4->d_digit[object4->d_total_digit - 1 - e];

		for (i = 0; i<object4->d_total_digit; i++)

		{

			object4->d_digit[object4->d_total_digit - 1 - i] = object4->d_digit[object4->d_total_digit - 1 - i - e];

		}

		for (i = 0; i<e; i++)

		{

			object4->d_digit[i] = 0;

		}

		if (e == 0)

		{

			object4->d_digit[0] = 0;

			d--;

		}

		d = d - e;

	}

	for (i = 0; i<object4->i_total_digit; i++)

	{

		object4->i_digit[object->i_total_digit - 1 - i] = object4->i_digit[object4->i_total_digit - 1 - i];

	}

	for (i = 0; i<object->i_total_digit - object4->i_total_digit; i++)

	{

		if (object4->d_digit[object4->d_total_digit - 1 - i] >= 0 && object4->d_digit[object4->d_total_digit - 1 - i]<10)

		{

			object4->i_digit[object->i_total_digit - object4->i_total_digit - 1 - i] = object4->d_digit[object4->d_total_digit - 1 - i];

		}

		else

		{

			object4->i_digit[object->i_total_digit - object4->i_total_digit - 1 - i] = 0;

		}

	}

	for (i = 0; i<object->i_total_digit - object4->i_total_digit; i++)

	{

		object4->d_digit[object4->d_total_digit - 1 - i] = 0;

	}

	object4->d_total_digit = object2->d_total_digit - object->i_total_digit + object2->i_total_digit;

	object4->i_total_digit = object->i_total_digit;

	for (;;)

	{

		*object5 = *object;

		if (object->d_total_digit>object4->d_total_digit)

		{

			for (i = object->d_total_digit - object4->d_total_digit; i<object->d_total_digit; i++)

			{

				object->d_digit[i] = object->d_digit[i] - object4->d_digit[i - object->d_total_digit + object4->d_total_digit];

			}

		}

		else

		{



			for (i = 0; i<object4->d_total_digit - object->d_total_digit; i++)

			{

				object->d_digit[i] = 0 - object4->d_digit[i];

			}

			for (i = object4->d_total_digit - object->d_total_digit; i<object4->d_total_digit; i++)

			{

				object->d_digit[i] = object->d_digit[i] - object4->d_digit[i - object4->d_total_digit + object->d_total_digit];

			}

			object->d_total_digit = object4->d_total_digit;

		}

		for (i = 0; i<object->d_total_digit; i++)

		{

			if (object->d_digit[i]<0 && i != object->d_total_digit - 1)

			{

				object->d_digit[i] = object->d_digit[i] + 10;

				object->d_digit[i + 1]--;

			}

			else if (object->d_digit[i]<0 && i == object->d_total_digit - 1)

			{

				object->d_digit[i] = object->d_digit[i] + 10;

				object->i_digit[0]--;

			}

		}

		for (i = 0; i<object->i_total_digit; i++)

		{

			object->i_digit[i] = object->i_digit[i] - object4->i_digit[i];

		}

		for (i = 0; i<object->i_total_digit; i++)

		{

			if (object->i_digit[i]<0 && i != object->i_total_digit - 1)

			{

				object->i_digit[i] = object->i_digit[i] + 10;

				object->i_digit[i + 1]--;

			}

			else if (object->i_digit[i]<0 && i == object->i_total_digit - 1)

			{

				if (object->i_digit[i + 1]>0 && object->i_digit[i + 1]<10)

				{

					object->i_digit[i] = object->i_digit[i] + 10;

					object->i_digit[i + 1]--;

				}

			}

		}

		c++;

		if (object->i_digit[object->i_total_digit - 1]<0)

		{

			*object = *object5;

			if (d <= object->i_total_digit - object2->i_total_digit)

			{

				object3->i_digit[object->i_total_digit - object2->i_total_digit - d] = c - 1;

				object3->i_total_digit++;

			}

			else

			{

				object3->d_digit[*d_total - d + object->i_total_digit - object2->i_total_digit] = c - 1;

				object3->d_total_digit++;

			}

			for (i = 0; i<object->i_total_digit; i++)

			{

				object->i_digit[object->i_total_digit - i] = object->i_digit[object->i_total_digit - 1 - i];

			}

			if (object->d_digit[object->d_total_digit - 1] >= 0 && object->d_digit[object->d_total_digit - 1]<10)

			{

				object->i_digit[0] = object->d_digit[object->d_total_digit - 1];

			}

			else

			{

				object->i_digit[0] = 0;

			}

			for (i = 0; i<object->d_total_digit - 1; i++)

			{

				object->d_digit[object->d_total_digit - 1 - i] = object->d_digit[object->d_total_digit - 2 - i];

			}

			object->d_digit[0] = 0;

			d++;

			c = 0;

		}

		if (d - object->i_total_digit + object2->i_total_digit>*d_total)

		{

			break;

		}

	}

	for (i = 0; i<object3->d_total_digit; i++)

	{

		if (object3->d_digit[i] == 0)

		{

			l++;

		}

		else

		{

			break;

		}

	}

	for (i = 0; i<object3->d_total_digit; i++)

	{

		object3->d_digit[i] = object3->d_digit[i + l];

	}

	object3->d_total_digit = object3->d_total_digit - l;

	l = 0;

	for (i = 0; i<object3->i_total_digit; i++)

	{

		if (object3->i_digit[object3->i_total_digit - 1 - i] == 0)

		{

			l++;

		}

		else

		{

			break;

		}

	}

	object3->i_total_digit = object3->i_total_digit - l;

	l = 0;

	object3->sign = a * b;

	*object = *object6;

	return 0;

}

