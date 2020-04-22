#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

class GameOfLife
{
public:
	GameOfLife(RenderWindow* window, unsigned int sirina, unsigned int visina, Color boja_zivih, Color boja_mrtvih, float kvadrat_size);
	void draw();
private:
	RenderWindow* window;
	unsigned int br_stupaca;
	unsigned int br_redaka;
	unsigned int kapacitet;
	bool prvi_put;
	RectangleShape zivi_kvadrat;
	RectangleShape mrtvi_kvadrat;
	Color boja_zivih;
	Color boja_mrtvih;
	float kvadrat_size;
	vector<int> trenutna_generacija;
	vector<int> nova_generacija;
	bool slucajna_vrijednost();
	void sljedeca_generacija();
	bool ziva_celija(int i);
	int provjera_susjeda(int i);
	void crtaj();
	int provjera_koliko(int j);
	void set_kvadrat();
};