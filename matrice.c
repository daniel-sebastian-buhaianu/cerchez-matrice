#include <iostream>

using namespace std;

#define MIN_N 1
#define MAX_N 100
#define MIN_M 1
#define MAX_M 100

int main()
{
	int n;
	
	cout << "n = "; cin >> n;

	if (n < MIN_N || n > MAX_N)
	{
		cout << "Eroare valoare n\n";
	}

	int m;

	cout << "m = "; cin >> m;

	if (m < MIN_M || m > MAX_M)
	{
		cout << "Eroare valoare m\n";
	}
	
	int i, j, a[n][m];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}

	// Afisez matricea

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}

		cout << "\n";
	}

	cout << "\n";

	// Verificati daca exista o coloana in matrice cu toate elementele nule.
	
	bool exista, ok;

	for (exista = j = 0; j < m && !exista; j++)
	{
		for (ok = 1, i = 0; i < n && ok; i++)
		{
			if (a[i][j])
			{
				ok = 0;
			}
		}

		if (ok)
		{
			exista = 1;
		}
	}

	if (exista)
	{
		cout << "Exista o coloana in matrice cu toate elementele nule.\n";
	}
	else
	{
		cout << "Nu exista o coloana in matrice cu toate elementele nule.\n";
	}

	// Calculati si afisati produsul elementelor nenule de pe fiecare linie a matricei.
	
	int p;
	
	for (i = 0; i < n; i++)
	{
		p = 1;

		for (j = 0; j < m; j++)
		{
			if (a[i][j])
			{
				p *= a[i][j];
			}
		}

		cout << "produsul elementelor nenule de pe linia " << i << " = " << p << "\n";
	}

	// Numarati cate elemente din matrice au ca vecini numai numere pare 
	// (doua elemente sunt numite vecine daca sunt adiacente pe verticala sau orizontala)
	
	int b[n+2][m+2];

	// bordez matricea

	for (j = 0; j < m+2; j++)
	{
		b[0][j] = 0;
		b[m+1][j] = 0;
	}

	for (i = 0; i < n+2; i++)
	{
		b[i][0] = 0;
		b[i][m+1] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			b[i][j] = a[i-1][j-1];
		}
	}

	int nr = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			// verific vecinii

			if (b[i][j-1] % 2 == 0
			    && b[i-1][j] % 2 == 0
			    && b[i][j+1] % 2 == 0
			    && b[i+1][j] % 2 == 0)
			{
				nr++;
			}
		}
	}

	cout << nr << " elemente din matrice au ca vecini numai numere pare\n";
	
	return 0;
}
