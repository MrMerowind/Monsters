#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

class clInventory
{

private:
    int id[10][10];
    sf::Texture tex_11;
    sf::Texture tex_12;
    sf::Texture tex_13;
    sf::Texture tex_21;
    sf::Texture tex_22;
    sf::Texture tex_23;
    sf::Texture tex_31;
    sf::Texture tex_32;
    sf::Texture tex_33;

    sf::Text texGold;
    sf::Font fNumber;
    int gold;



public:
    clInventory()
    {
        fNumber.loadFromFile("media/fonts/number.ttf");
        texGold.setCharacterSize(20);
        texGold.setFont(fNumber);
        texGold.setColor(sf::Color::Black);
        texGold.setPosition(915,548);
        gold = 0;

        tex_11.loadFromFile("media/graphic/inventory/11.png");
        tex_12.loadFromFile("media/graphic/inventory/12.png");
        tex_13.loadFromFile("media/graphic/inventory/13.png");
        tex_21.loadFromFile("media/graphic/inventory/21.png");
        tex_22.loadFromFile("media/graphic/inventory/22.png");
        tex_23.loadFromFile("media/graphic/inventory/23.png");
        tex_31.loadFromFile("media/graphic/inventory/31.png");
        tex_32.loadFromFile("media/graphic/inventory/32.png");
        tex_33.loadFromFile("media/graphic/inventory/33.png");

        for(int y = 0; y < 8; y++)
        {
            for(int x = 0; x <8; x++)
            {
                id[x][y] = 0;
            }
        }
        for(int y = 8; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                id[x][y] = 4;
            }
        }
        for(int y = 0; y < 10; y++)
        {
            for(int x = 8; x < 10; x++)
            {
                id[x][y] = 4;
            }
        }
    }
    int getGold()
    {
        return gold;
    }
    void save()
    {
        fstream plik;
        string destiny;
            destiny = "media/upload/";
            destiny += login;
            destiny += "_inventory.ini";
        plik.open(destiny.c_str(),ios::out);
        if(plik.good())
        {
            plik<<gold<<" ";
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    plik<<id[x][y]<<" ";
                }
            }
            Debug("[Inventory] Zapisane");
        }
        else
        {
            Debug("[Inventory] Nie mozna zapisac");
        }

        plik.close();
    }
    void load()
    {
        fstream plik;
        string destiny;
            destiny = "media/download/";
            destiny += login;
            destiny += "_inventory.ini";
        plik.open(destiny.c_str(),ios::in);
        if(plik.good())
        {
            plik>>gold;
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    plik>>id[x][y];
                }
            }
            Debug("[Inventory] Wczytane");
        }
        else
        {
            Debug("[Inventory] Stworzone");
        }

        plik.close();
    }
    bool addGold(int value)
    {
        if (gold + value < 0) return false;
        if (gold + value > 999999999) return false;
        gold += value;
        return true;
    }
    bool umiesc(int x , int y, int z)
    {
        if (id[x][y] != 0) return false;
        if (x > 7 || y > 7) return false;
        if(item[z].getInvMiejsce() == 11)
        {
            id[x][y] = z;
            return true;
        }
        if(item[z].getInvMiejsce() == 12)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 13)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0 && id[x][y + 2] == 1)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                id[x][y + 2] = 3;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 21)
        {
            if (id[x][y] == 0 && id[x + 1][y] == 0)
            {
                id[x][y] = z;
                id[x + 1][y] = 1;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 22)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0 && id[x + 1][y] == 0 && id[x + 1][y + 1] == 0)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                id[x + 1][y] = 1;
                id[x + 1][y + 1] = 2;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 23)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0 && id[x][y + 2] == 0 && id[x + 1][y] == 0 && id[x + 1][y + 1] == 0 && id[x + 1][y + 2] == 0)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                id[x][y + 2] = 3;
                id[x + 1][y] = 1;
                id[x + 1][y + 1] = 2;
                id[x + 1][y + 2] = 3;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 31)
        {
            if (id[x][y] == 0 && id[x + 1][y] == 0 && id[x + 2][y] == 0)
            {
                id[x][y] = z;
                id[x + 1][y] = 1;
                id[x + 2][y] = 1;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 32)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0 && id[x + 1][y] == 0 && id[x + 1][y + 1] == 0 && id[x + 2][y] == 0 && id[x + 2][y + 1] == 0)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                id[x + 1][y] = 1;
                id[x + 1][y + 1] = 2;
                id[x + 2][y] = 1;
                id[x + 2][y + 1] = 2;
                return true;
            }
            else return false;
        }
        if(item[z].getInvMiejsce() == 33)
        {
            if (id[x][y] == 0 && id[x][y + 1] == 0 && id[x][y + 1] == 0 && id[x + 1][y] == 0 && id[x + 1][y + 1] == 0 && id[x + 1][y + 2] == 0 && id[x + 2][y] == 0 && id[x + 2][y + 1] == 0 && id[x + 2][y + 2] == 0)
            {
                id[x][y] = z;
                id[x][y + 1] = 2;
                id[x][y + 2] = 3;
                id[x + 1][y] = 1;
                id[x + 1][y + 1] = 2;
                id[x + 1][y + 2] = 3;
                id[x + 2][y] = 1;
                id[x + 2][y + 1] = 2;
                id[x + 2][y + 2] = 3;
                return true;
            }
            else return false;
        }
    }
    void usun(int x, int y)
    {
        if(item[id[x][y]].getInvMiejsce() == 11)
        {
            id[x][y] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 12)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 13)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
            id[x][y + 2] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 21)
        {
            id[x][y] = 0;
            id[x + 1][y] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 22)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
            id[x + 1][y] = 0;
            id[x + 1][y + 1] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 23)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
            id[x][y + 2] = 0;
            id[x + 1][y] = 0;
            id[x + 1][y + 1] = 0;
            id[x + 1][y + 2] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 31)
        {
            id[x][y] = 0;
            id[x + 1][y] = 0;
            id[x + 2][y] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 32)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
            id[x + 1][y] = 0;
            id[x + 1][y + 1] = 0;
            id[x + 2][y] = 0;
            id[x + 2][y + 1] = 0;
        }
        if(item[id[x][y]].getInvMiejsce() == 33)
        {
            id[x][y] = 0;
            id[x][y + 1] = 0;
            id[x][y + 1] = 0;
            id[x + 1][y] = 0;
            id[x + 1][y + 1] = 0;
            id[x + 1][y + 2] = 0;
            id[x + 2][y] = 0;
            id[x + 2][y + 1] = 0;
            id[x + 2][y + 2] = 0;
        }
    }
    int getId(int x, int y)
    {
        return id[x][y];
    }
    void goldWyswietl(int value)
    {
        string tmp = "           ";
        tmp[10] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[9] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[8] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[6] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[5] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[4] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[2] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[1] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;
        tmp[0] = int_to_char(value % 10);
        value -= value % 10;
        value /= 10;

        for(int x = 0; x < 10; x++)
        {
            if (tmp[x] == '0') tmp[x] = ' ';
            if (tmp[x] != ' ') break;
        }

        texGold.setString(tmp);
        window.draw(texGold);
    }
    void wyswietl()
    {
        for(int y = 0; y < 8; y++)
        {
            for(int x = 0; x < 8; x++)
            {
                sf::Sprite sp_bg;

                if(item[id[x][y]].getInvMiejsce() == 11) sp_bg.setTexture(tex_11);
                else if(item[id[x][y]].getInvMiejsce() == 12) sp_bg.setTexture(tex_12);
                else if(item[id[x][y]].getInvMiejsce() == 13) sp_bg.setTexture(tex_13);
                else if(item[id[x][y]].getInvMiejsce() == 21) sp_bg.setTexture(tex_21);
                else if(item[id[x][y]].getInvMiejsce() == 22) sp_bg.setTexture(tex_22);
                else if(item[id[x][y]].getInvMiejsce() == 23) sp_bg.setTexture(tex_23);
                else if(item[id[x][y]].getInvMiejsce() == 31) sp_bg.setTexture(tex_31);
                else if(item[id[x][y]].getInvMiejsce() == 32) sp_bg.setTexture(tex_32);
                else if(item[id[x][y]].getInvMiejsce() == 33) sp_bg.setTexture(tex_33);


                if(id[x][y] >= 100)
                {
                    sp_bg.setPosition(799 + (35 * x),269 + (34 * y));
                    window.draw(sp_bg);
                    item[ id[x][y] ].wyswietlInventory(799 + (35 * x),269 + (34 * y));
                }
            }
        }
        goldWyswietl(gold);

    }


};

clInventory inventory;
#endif // INVENTORY_H_INCLUDED
