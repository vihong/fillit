void		tetri_copy(char** sq, char tetri[4][5], int m, int n)
{
	int i = 0;
	int j = 0;
	int m_max = m + 4;
	int n_max = n + 4;

	for (i = 0; m < m_max && i < 4; m++, i++)
		for (j = 0; n < n_max && j < 5; j++, n++)
		{
			printf("(m: %d, n: %d) with (i: %d, j: %d) \n\n", m, n, i, j);
			if (n == n_max)
			{
				m++;
				n = n - 3;
				i++;
			}
			sq[m][n] = tetri[i][j];
		}

}


void		put_tetri2(char** sq, char tetri[4][5], int pos)
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	int m_start;
	int n_start;
	int m_max = 0;
	int n_max = 0;

	m_start = pos / SQ_SIZE;
	n_start = pos % SQ_SIZE;
	m = 0;
	while (m < SQ_SIZE)
	{
		n = 0;
		while (n < SQ_SIZE)
		{
			if (m == m_start && n == n_start)
			{
				m_max = m + 4;
				while (m < m_max)
				{
					n_max = n + 4;
					j = 0;
					while (n < n_max && j < 5)
					{
						printf("m: %d\n", m);
						printf("n: %d\n", n);
						printf("i: %d\n", i);
						printf("j: %d\n\n", j);

						if (tetri[i][j] != '.')
						{
							sq[m][n] = tetri[i][j];
						}

						n++;
						j++;
					}
					n = n - 4;
					m++;
					i++;
				}
			}
			n++;
		}
		m++;
	}
}


