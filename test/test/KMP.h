// KMP×Ö·û´®Æ¥ÅäËã·¨
void ComputerPrefix(int *next, char *p, int num)
{
	if (num > 1)
	{
		next[0] = 0;
		next[1] = 0;
	}

	int k =0;
	for (int i = 1; i < num; ++i)
	{
		for (; k != 0 && p[k] != p[i]; k = next[k]);
		if (p[k] == p[i])
		{
			++k;
		}
		next[i+1] = k;
	}
}

int KMPmatch(char *text, int tl, char *sub, int sl, int *next, int s)
{
	int k = 0;
	while (s < tl)
	{
		for (k = next[k]; sub[k] == text[s]; ++k, ++s);
		if (k == 0)
		{
			++s;
		}
		if (k == sl)
		{
			return s - sl;
		}
	}
	return -1;
}

void PrintKMPmatch()
{
	static const int text_len = 1000000;
	static const int sub_len = 10;
	static const int sub_real_len = sub_len + 1;

	int next[sub_real_len];

	char text[text_len];
	char sub[sub_real_len];
	sub[sub_len] = '\0';

	
	int s = -1;
	int key = 0;
	while (true)
	{
		if (s == -1)
		{
			for (int i = 0; i < text_len; ++i)
			{
				text[i] = 'a' + rand()%3;
			}
	
			key = rand()%(text_len - sub_len);
			for (int i = 0; i < sub_len; ++i)
			{
				sub[i] = text[key + i];
			}
			ComputerPrefix(next, sub, sub_len);
			s = 0;
		}

		printf("key = %d\n", key);

		s = KMPmatch(text, text_len, sub, sub_len, next, s);

		printf("KMPmatch: key = %d sub = %s \n", s, sub);

		if (s != - 1)
		{
			printf("text_sub = ");
			for (int i = 0; i < sub_len; ++i)
			{
				printf("%c", text[s+i]);
			}
			printf("\n");

			s += 1;
		}

		system("pause");
	}
}
