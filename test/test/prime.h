
// ËØÊıO(n)Ëã·¨

static const int count = 1000;

bool is_prime[count];

void MakePrime()
{
	int prime[count];
	memset(is_prime, true, sizeof(is_prime));
	memset(prime, 0, sizeof(prime));
	
	is_prime[0] = false;
	is_prime[1] = false;

	int lp = 0;
	for (int i = 2; i < count; ++i)
	{
		if (is_prime[i])
		{
			prime[lp++] = i;
		}
		for (int j = 0; j < lp && i*prime[j] < count; ++j)
		{
			is_prime[i*prime[j]] = false;

			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}

void PrintPrime()
{
	for (int i = 0; i < count; ++i)
	{
		if (is_prime[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
