#include <SFML/Graphics.hpp>
#include "GameOfLife.h"

void set_velicina_ekrana(unsigned int &sirina, unsigned int &visina)
{
	int odabir;
	bool ponovo;

	cout << "Ponudjene rezolucije: " << endl
		<< "1) 800 x 600" << endl
		<< "2) 800 x 720" << endl
		<< "3) 1024 x 600" << endl
		<< "4) 1024 x 720" << endl << endl;

	do
	{
		ponovo = false;

		cout << "Unesite broj ispred zeljene rezolucije: ";
		cin >> odabir;

		switch (odabir)
		{
		case 1:
			sirina = 800;
			visina = 600;
			break;
		case 2:
			sirina = 800;
			visina = 720;
			break;
		case 3:
			sirina = 1024;
			visina = 600;
			break;
		case 4:
			sirina = 1024;
			visina = 720;
			break;
		default:
			ponovo = true;
			cout << endl << "Unesite broj od 1 do 4!" << endl << endl;
			break;
		}
	} while (ponovo);
}

void ponuda()
{
	cout << "1) Crna" << endl
		<< "2) Bijela" << endl
		<< "3) Zuta" << endl
		<< "4) Crvena" << endl
		<< "5) Plava" << endl
		<< "6) Purpurnocrvena" << endl
		<< "7) Svijetloplava" << endl
		<< "8) Zelena" << endl;
}

Color boja(int broj)
{
	switch (broj)
	{
	case 1:
		return Color::Black;
	case 2:
		return Color::White;
	case 3:
		return Color::Yellow;
	case 4:
		return Color::Red;
	case 5:
		return Color::Blue;
	case 6:
		return Color::Magenta;
	case 7:
		return Color::Cyan;
	case 8:
		return Color::Green;
	}
}

void set_boja_celija(Color& boja_zivih, Color& boja_mrtvih)
{
	system("CLS");

	int odabir_zive, odabir_mrtve;
	bool ponovo;
	bool povratak;
	
	do
	{
		povratak = false;
		ponovo = false;

		cout << endl << "Ponudjene boje zivih celija: " << endl;
		ponuda();
		cout << "Unesite broj: ";
		cin >> odabir_zive;
		
		if (odabir_zive < 1 || odabir_zive > 8)
		{
			povratak = true;
			cout << "Morate unijeti broj od 1 do 8!" << endl << endl;
		}
		else
		{
			do
			{
				ponovo = false;

				cout << endl << "Ponudjene boje mrtvih celija: " << endl;
				ponuda();
				cout << "Unesite broj: ";
				cin >> odabir_mrtve;

				if (odabir_mrtve == odabir_zive)
				{
					int zelja;
					cout << "Ne mozete odabrati istu boju za mrtve i zive celije! " << endl
						<< "Ukoliko zelite promijeniti boju zivih celija, pritisnite 1 " << endl
						<< "Ukoliko zelite odabrati boju mrtvih celija, pritisnite 2 " << endl;
					cin >> zelja;
					if (zelja == 1)
					{
						povratak = true;
					}
					else
					{
						ponovo = true;
					}
					cout << endl;
				}
				else
				{
					if (odabir_mrtve < 1 || odabir_mrtve > 8)
					{
						ponovo = true;
						cout << "Morate unijeti broj od 1 do 8! " << endl;
					}
					else
					{
						boja_mrtvih = boja(odabir_mrtve);
					}
				}
			} while (ponovo);
			boja_zivih = boja(odabir_zive);
		}
	} while (povratak);
}

void set_velicina_celije(float& kvadrat_size)
{
	system("CLS");

	int velicina;
	bool ponovo;

	cout << "Ponudjene velicine celija: " << endl
		<< "1) 6 x 6" << endl
		<< "2) 8 x 8" << endl
		<< "3) 10 x 10" << endl
		<< "4) 12 x 12" << endl << endl;

	do
	{
		ponovo = false;

		cout << "Unesite zeljeni broj: ";
		cin >> velicina;
		
		switch (velicina)
		{
		case 1:
			kvadrat_size = 6;
			break;
		case 2:
			kvadrat_size = 8;
			break;
		case 3:
			kvadrat_size = 10;
			break;
		case 4:
			kvadrat_size = 12;
			break;
		default:
			cout << endl << "Morate unijeti broj od 1 do 4!" << endl << endl;
			ponovo = true;
			break;
		}
	} while (ponovo);
}

void set_vrijeme_osvjezavanja(float& vrijeme)
{
	system("CLS");

	int odabir;
	bool ponovo;

	cout << "Ponudjena vremena osvjezavanja (u sekundama): " << endl
		<< "1) 2,00 s" << endl
		<< "2) 1,50 s" << endl
		<< "3) 1,00 s" << endl
		<< "4) 0,50 s" << endl
		<< "5) 0,10 s" << endl << endl;

	do
	{
		ponovo = false;

		cout << "Unesite zeljeni broj: ";
		cin >> odabir;

		switch (odabir)
		{
		case 1:
			vrijeme = 2;
			break;
		case 2:
			vrijeme = 1.5;
			break;
		case 3:
			vrijeme = 1;
			break;
		case 4:
			vrijeme = 0.5;
			break;
		case 5:
			vrijeme = 0.1;
			break;
		default:
			cout << endl << "Morate unijeti broj od 1 do 5!" << endl << endl;
			ponovo = true;
			break;
		}
	} while (ponovo);
}

int main()
{
	Clock sat;
	unsigned int sirina;
	unsigned int visina;
	Color boja_zivih;
	Color boja_mrtvih;
	float kvadrat_size;
	float vrijeme;

	set_velicina_ekrana(sirina, visina);
	set_boja_celija(boja_zivih, boja_mrtvih);
	set_velicina_celije(kvadrat_size);
	set_vrijeme_osvjezavanja(vrijeme);

	RenderWindow window(VideoMode(sirina, visina), "Conway's Game of Life");
	window.setFramerateLimit(60);
	GameOfLife gof(&window, sirina, visina, boja_zivih, boja_mrtvih, kvadrat_size);

	gof.draw();
	window.display();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (sat.getElapsedTime() >= seconds(vrijeme))
		{
			window.clear();
			gof.draw();
			window.display();
			sat.restart();
		}
	}

	return 0;
}