#include "GameOfLife.h"

GameOfLife::GameOfLife(RenderWindow* window, unsigned int sirina, unsigned int visina, Color boja_zivih, Color boja_mrtvih, float kvadrat_size)
{
	this->window = window;
	br_stupaca = visina /kvadrat_size;
	br_redaka = sirina / kvadrat_size;
	kapacitet = (br_stupaca * br_redaka);
	this->boja_zivih = boja_zivih;
	this->boja_mrtvih = boja_mrtvih;
	this->kvadrat_size = kvadrat_size;

	prvi_put = true;
	trenutna_generacija.reserve(kapacitet);
	nova_generacija.reserve(kapacitet);
	srand(time(nullptr));
	for (size_t i = 0; i < kapacitet; i++)
	{
		if (slucajna_vrijednost())
		{
			trenutna_generacija.push_back(1);
		}
		else
		{
			trenutna_generacija.push_back(0);
		}
	}
}

void GameOfLife::draw()
{
	if (prvi_put)
	{
		crtaj();
		prvi_put = false;
		sljedeca_generacija();
	}
	else
	{
		trenutna_generacija = nova_generacija;
		crtaj();
		sljedeca_generacija();
	}
}

void GameOfLife::sljedeca_generacija()
{
	nova_generacija.clear();
	for (int i = 0; i < kapacitet; i++)
	{
		if (ziva_celija(i))
		{
			nova_generacija.push_back(1);
		}
		else
		{
			nova_generacija.push_back(0);
		}
	}
}

bool GameOfLife::slucajna_vrijednost()
{
	int rand_value = rand() % 4 + 1;
	if (rand_value != 4)
	{
		return 0;
	}
	return 1;
}

bool GameOfLife::ziva_celija(int i)
{
	if (trenutna_generacija[i] == 1)
	{
		switch (provjera_susjeda(i))
		{
		case 2:
		case 3:
			return 1;
		default:
			return 0;
		}
	}
	switch (provjera_susjeda(i))
	{
	case 3:
		return 1;
	default:
		return 0;
	}
}

int GameOfLife::provjera_susjeda(int i)
{
	int brojac = 0;
	for (int j = (i - 1); j < (i + 2);)
	{
		brojac += provjera_koliko(j);
		j += 2;
	}
	for (int j = (i - 1 - br_stupaca); j < (i + 2 - br_stupaca); j++)
	{
		brojac += provjera_koliko(j);
	}
	for (int j = (i - 1 + br_stupaca); j < (i + 2 + br_stupaca); j++)
	{
		brojac += provjera_koliko(j);
	}
	return brojac;
}

void GameOfLife::crtaj()
{
	set_kvadrat();
	int pozicija = 0;

	for (float i = 0; i < br_redaka * kvadrat_size; i += kvadrat_size)
	{
		for (float j = 0; j < br_stupaca * kvadrat_size; j += kvadrat_size)
		{
			if (trenutna_generacija[pozicija] == 1)
			{
				zivi_kvadrat.setPosition(i, j);
				window->draw(zivi_kvadrat);
			}
			else
			{
				mrtvi_kvadrat.setPosition(i, j);
				window->draw(mrtvi_kvadrat);
			}
			pozicija++;
		}
	}
}


int GameOfLife::provjera_koliko(int j)
{
	if (j < 0 || j >= kapacitet)
	{
		return 0;
	}
	else if (trenutna_generacija[j] == 1)
	{
		return 1;
	}
	return 0;
}

void GameOfLife::set_kvadrat()
{
	zivi_kvadrat.setFillColor(boja_zivih);
	zivi_kvadrat.setSize(Vector2f(kvadrat_size, kvadrat_size));

	mrtvi_kvadrat.setFillColor(boja_mrtvih);
	mrtvi_kvadrat.setSize(Vector2f(kvadrat_size, kvadrat_size));
}
