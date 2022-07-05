#ifndef MYSZ_H_INCLUDED
#define MYSZ_H_INCLUDED

class clMysz
{

private:
    sf::Vector2i pozycjaMyszyWzgledemOkna;
    sf::Texture tex_cursor;
    sf::Texture tex_cursor_move;
    sf::Sprite sp_cursor;
    bool pozaEq;

    int idPrzedmiotu;

    int inventory_last_x;
    int inventory_last_y;

public:
    clMysz()
    {
        idPrzedmiotu = 0;
        pozaEq = false;
        tex_cursor.loadFromFile("media/graphic/window/cursor.png");
        tex_cursor_move.loadFromFile("media/graphic/window/cursor_move.png");
        sp_cursor.setTexture(tex_cursor);
        inventory_last_x = 0;
        inventory_last_y = 0;
        odlOdMyszy_x = 0;
        odlOdMyszy_y = 0;
    }
    void windowMove()
    {
        sp_cursor.setTexture(tex_cursor_move);
    }
    void cursor()
    {
        sp_cursor.setTexture(tex_cursor);
    }
    int x()
    {
        pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition( window );
        return pozycjaMyszyWzgledemOkna.x;
    }
    void ustawOdlOdMyszy(int x, int y)
    {
        odlOdMyszy_x = x;
        odlOdMyszy_y = y;
    }
    int y()
    {
        pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition( window );
        return pozycjaMyszyWzgledemOkna.y;
    }
    bool LPM()
    {
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) return true;
        else return false;
    }
    void wyswietl()
    {
        if(idPrzedmiotu == 5) vulpixMove = true;
        else vulpixMove = false;
        if(lumber.isActive() == false)
        {
        if(x() >= 8 && x() <= 770 && y() >= 134 && y() <= 592) pozaEq = true;
        else pozaEq = false;

        if (pozaEq == false)
        {
            if(idPrzedmiotu == 5) idPrzedmiotu = 0;

            if (idPrzedmiotu == 0 && LPM())
            {
                // Obliczanie pozycji myszy
                if(x() >= 799 && x() <= 1114 && y() >= 269 && y() <= 575)
                {
                    int item_x = (x() - 799) / 35;
                    int item_y = (y() - 269) / 34;

                    if(inventory.getId(item_x,item_y) != 0)
                    {
                        if(inventory.getId(item_x,item_y) == 3) item_y--;
                        if(inventory.getId(item_x,item_y) == 2) item_y--;
                        if(inventory.getId(item_x,item_y) == 1) item_x--;
                        if(inventory.getId(item_x,item_y) == 1) item_x--;
                        idPrzedmiotu = inventory.getId(item_x,item_y);
                        inventory.usun(item_x,item_y);
                        inventory_last_x = item_x;
                        inventory_last_y = item_y;
                        Debug("[Mysz] Podniesiono przedmiot");
                        odlOdMyszy_x = item[idPrzedmiotu].szer() / 2;
                        odlOdMyszy_y = item[idPrzedmiotu].wys() / 2;
                    }

                }
            }
            else if (idPrzedmiotu != 0 && LPM() == false)
            {
                // Obliczanie pozycji myszy
                if(x() >= 799 && x() <= 1114 && y() >= 269 && y() <= 575)
                {
                    int item_x = (x() - 799) / 35;
                    int item_y = (y() - 269) / 34;

                    if(inventory.getId(item_x,item_y) == 0)
                    {
                        if (inventory.umiesc(item_x,item_y,idPrzedmiotu))
                        {
                            idPrzedmiotu = 0;
                            Debug("[Mysz] Upuszczono przedmiot");
                            odlOdMyszy_x = 0;
                            odlOdMyszy_y = 0;
                        }
                    }
                    else
                    {
                        if (inventory.umiesc(inventory_last_x,inventory_last_y,idPrzedmiotu))
                        {
                            idPrzedmiotu = 0;
                            Debug("[Mysz] Przedmiot powrocil na poprzednie miejsce");
                            odlOdMyszy_x = 0;
                            odlOdMyszy_y = 0;
                        }
                        else
                        {
                            Debug("[Mysz] [Error] Poprzednie miejsce jest zajete");
                        }
                    }

                }
                else
                {
                    if (inventory.umiesc(inventory_last_x,inventory_last_y,idPrzedmiotu))
                    {
                        idPrzedmiotu = 0;
                        Debug("[Mysz] Przedmiot powrocil na poprzednie miejsce");
                    }
                    else
                    {
                        Debug("[Mysz] [Error] Poprzednie miejsce jest zajete");
                    }
                }
            }

            if (idPrzedmiotu != 0)
            {
                item[idPrzedmiotu].wyswietlInventory(x(),y());
            }
        } // POZA EQ = TRUE
        else
        {
            if (idPrzedmiotu == 0 && LPM() && shop.isActive() == false) // CHWYTANIE PRZEDMIOTU
            {
                // Chwytanie Vulpixa
                if (x() >= pet.getPozX() && x() <= pet.getPozX() + 171 && y() >= pet.getPozY() && y() <= pet.getPozY() + 119)
                {
                    odlOdMyszy_x = x() - pet.getPozX();
                    odlOdMyszy_y = y() - pet.getPozY();
                    idPrzedmiotu = 5;
                    pet.movementY = 0;
                    pet.kolejka(usun);
                    pet.kolejka(usun);
                    pet.kolejka(usun);
                    pet.kolejka(usun);
                    pet.kolejka(usun);
                    pet.kolejka(wstan);


                    Debug("[Vulpix] Podniesiony");
                }
                else
                {
                    idPrzedmiotu = pokoje.podnies(x(),y());
                    if (idPrzedmiotu != 0) Debug("[Mysz] Podniesiono przedmiot");
                }
            }
            else if (idPrzedmiotu != 0 && LPM() == false && shop.isActive() == false) // UPUSZCZANIE PRZEDMIOTU
            {
                if (idPrzedmiotu == 5)
                {
                    odlOdMyszy_x = 0;
                    odlOdMyszy_y = 0;
                    idPrzedmiotu = 0;
                    Debug("[Vulpix] Opuszczony");
                }
                else
                {
                    if(x() >= pet.getPozX() && x() <= pet.getPozX() + 171 && y() >= pet.getPozY() && y() <= pet.getPozY() + 119 && idPrzedmiotu >= 400 && idPrzedmiotu <= 499)
                    {
                        pet.addFood(item[idPrzedmiotu].getFoodValue());
                        idPrzedmiotu = 0;
                        Debug("[Vulpix] Nakramiony");
                    }
                    else if(pokoje.postaw(x() - odlOdMyszy_x,y() - odlOdMyszy_y,idPrzedmiotu))
                    {
                        idPrzedmiotu = 0;
                    }
                    else
                    {
                        Debug("[Mysz] W pomieszczeniu nie ma miejsca");
                        if (inventory.umiesc(inventory_last_x,inventory_last_y,idPrzedmiotu))
                        {
                            idPrzedmiotu = 0;
                            Debug("[Mysz] Przedmiot powrocil na poprzednie miejsce");
                        }
                        else
                        {

                        }
                    }
                }
            }
            else if (idPrzedmiotu != 0 && LPM() == false && shop.isActive() == true)
            {
                inventory.addGold(item[idPrzedmiotu].getPrice());
                idPrzedmiotu = 0;
                Debug("[Sklep] Sprzedano przedmiot");
            }

            if (idPrzedmiotu != 0) // WYSWIETLANIE PRZEDMIOTU
            {
                if (idPrzedmiotu == 5) pet.setPosition(x() - odlOdMyszy_x, y() - odlOdMyszy_y);

                item[idPrzedmiotu].wyswietlItem(x() - odlOdMyszy_x,y() - odlOdMyszy_y);
            }
        }
        if(idPrzedmiotu == 5) petPrzenoszony = true;
        else petPrzenoszony = false;

    }

        sp_cursor.setPosition(x(),y());
        window.draw(sp_cursor);

    }

    void wyswietlPatcher()
    {
        sp_cursor.setPosition(x(),y());
        window.draw(sp_cursor);

    }

};
clMysz mysz;


#endif // MYSZ_H_INCLUDED
