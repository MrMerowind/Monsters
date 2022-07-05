#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "resource.h"


sf::RenderWindow window;

using namespace std;

string version = "1.0";

string strTmp;
int odlOdMyszy_x;
int odlOdMyszy_y;
bool petPrzenoszony;

#include "debug.h"
#include "md5.h"
#include "predeclarations.h"
#include "item.h"
#include "inventory.h"
#include "game.h"
#include "pokoje.h"
#include "shop.h"
#include "pet.h"
#include "mysz.h"
#include "przyciski.h"
#include "okno.h"
#include "patcher.h"

int main()
{
    petPrzenoszony = false;
    srand(time(NULL));

    // Updater
    patcher.wyswietl();
    if(patcher.isLogged() == false) return 0;
    // Login

    // Wczytywanie itemow
#include "itemList.h"
    // Kody
#include "kody.h"

    while (okno.otwarte())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                lumber.axeDown(1);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                lumber.axeDown(2);
                // Koniec
            if (event.type == sf::Event::MouseWheelMoved)
            {
                if(shop.isActive())zip.goWheel(event.mouseWheel.delta);
            }

            if (event.type == sf::Event::LostFocus)
                okno.focus(false);

            if (event.type == sf::Event::GainedFocus)
                okno.focus(true);
        }

        okno.wyswietl();
    }


    return 0;
}
