
#include "Move.h"
// Move down
void Down(int a[][4], int &sum)
{

	for (int col = 0; col < 4; col++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 3; i > -1; i--)
		{
			if (a[i][col] != 0)
			{
				tmp1.push_back(a[i][col]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (3 - i < tmp2.size())
						a[i][col] = tmp2[3 - i]; else a[i][col] = 0;
				}
		}

	}
}

// Move Left
void Left(int a[][4], int& sum)
{

	for (int row = 0; row < 4; row++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 0; i < 4; i++)
		{
			if (a[row][i] != 0)
			{
				tmp1.push_back(a[row][i]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (i < tmp2.size())
						a[row][i] = tmp2[i]; else a[row][i] = 0;
				}
		}

	}
}

// Move right

void Right(int a[][4], int &sum)
{

	for (int row = 0; row < 4; row++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 3; i > -1; i--)
		{
			if (a[row][i] != 0)
			{
				tmp1.push_back(a[row][i]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (3 - i < tmp2.size())
						a[row][i] = tmp2[3 - i]; else a[row][i] = 0;
				}
		}
	}
}


// Move up

void Up(int a[][4], int& sum)
{

		for (int col = 0; col < 4; col++)
		{
			vector<int> tmp1;
			vector<int> tmp2;
			for (int i = 0; i < 4; i++)
			{
				if (a[i][col] != 0)
				{
					tmp1.push_back(a[i][col]);
				}
			}

			if (tmp1.size() > 0)
			{
				for (int i = 0; i < tmp1.size() - 1; i++)
				{
					if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
					{
						tmp1[i] *= 2;
						tmp1[i + 1] = 0;
						sum += tmp1[i];
					}
				}

				for (int i = 0; i < tmp1.size(); i++)
				{
					if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
				}


				if (tmp2.size() < 4)
					for (int i = 0; i < 4; i++)
					{
						if (i < tmp2.size())
							a[i][col] = tmp2[i]; else a[i][col] = 0;
					}
			}

		}
}
