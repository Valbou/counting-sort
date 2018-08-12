# include <iostream>

using namespace std;

void afficheTableau(int taille, int tab[])
{
	// AFfiche les elements du tableau separes par des espaces
	for (size_t i = 0; i < taille; ++i)
	{
		cout << tab[i] << " ";
	}
	cout << "\n";
}

int borneMax(int taille, int tab[])
{
	int max = tab[0]; 
	int index = 0;
	for (size_t i = 0; i < taille; ++i)
	{
		if (tab[i] >= max)
		{
			max = tab[i];
		}
	}
	return max;
}

int borneMin(int taille, int tab[])
{
	int min = tab[0]; 
	int index = 0;
	for (size_t i = 0; i < taille; ++i)
	{
		if (tab[i] <= min)
		{
			min = tab[i];
		}
	}
	return min;
}

void countingSort(int taille, int tab[])
{
	// Algorithme de tri du tableau avec la methode Counting Sort
	int min = borneMin(taille, tab);
	int decalage = 0;
	// gestion des nombres negatifs et optimisation du tableau pour les nombre positifs
	if (min < 0)
	{
		decalage = abs(min);
	}
	else
	{
		decalage = -min;
	}
	int const tailleTab2 = borneMax(taille, tab) + decalage + 1;
	int tab2[tailleTab2];

	// Initialisation
	for (size_t i = 0; i < tailleTab2; ++i)
	{
		tab2[i] = 0;
	}

	// Counting
	for (size_t i = 0; i < taille; ++i)
	{
		++tab2[(tab[i]+decalage)];
	}

	// Sort
	size_t index = 0;
	for (size_t i = 0; i < tailleTab2; ++i)
	{
		for(size_t j = 0; j < tab2[i]; ++j)
		{
			tab[index] = i-decalage;
			++index;
		}
	}
}

int main()
{
    int tab[40] = { 9,98,5,6,-3,4,2,1,8,65,12,74,2,21,5,15,-17,18,54,20,100,20,125,134,185,165,14,-8,-23,45,-36,-2,97,63,82,10,-10, -99, 77,-89 }; // Tableau a trier
	int taille = 40;
	int nbInvert = 0; // Nombre d'echanges realises

    cout << "--- Insertion Sort ---" << "\n" << "\n" << "Tableau d'origine " << taille << " :" << "\n";
	afficheTableau(taille, tab);

	countingSort(taille, tab);

	cout << "Tableau trie en " << nbInvert << " inversions :" << "\n";
	afficheTableau(taille, tab);

	// La pause est necessaire pour voir le resultat sous Windows avant la fermeture de la console
	system("pause");
    return 0;
}
