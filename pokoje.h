#ifndef POKOJE_H_INCLUDED
#define POKOJE_H_INCLUDED

enum enPokoje
{
    salon,
    sypialnia,
    kuchnia,
    lazienka,
    ogrod,
};

class clPokoje
{

private:
    enPokoje typPokoju;
    sf::Texture tex_tlo_salon;
    sf::Texture tex_tlo_sypialnia;
    sf::Texture tex_tlo_kuchnia;
    sf::Texture tex_tlo_lazienka;
    sf::Texture tex_tlo_ogrod;

    sf::Sprite sp_tlo;

    int item_salon[100][3]; // [x][0] - id  [x][1] - x   [x][2] - y
    int item_sypialnia[100][3];
    int item_kuchnia[100][3];
    int item_lazienka[100][3];
    int item_ogrod[100][3];

public:
    clPokoje()
    {
        // Reset
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 100; x++)
            {
                item_salon[x][y] = 0;
                item_sypialnia[x][y] = 0;
                item_kuchnia[x][y] = 0;
                item_lazienka[x][y] = 0;
                item_ogrod[x][y] = 0;
            }
        }

        typPokoju = salon;
        tex_tlo_salon.loadFromFile("media/graphic/room/salon.png");
        tex_tlo_sypialnia.loadFromFile("media/graphic/room/sypialnia.png");
        tex_tlo_kuchnia.loadFromFile("media/graphic/room/kuchnia.png");
        tex_tlo_lazienka.loadFromFile("media/graphic/room/lazienka.png");
        tex_tlo_ogrod.loadFromFile("media/graphic/room/ogrod.png");
    }
    void save()
    {
        fstream plik;
        string destiny;
            destiny = "media/upload/";
            destiny += login;
            destiny += "_pokoje.ini";
        plik.open(destiny.c_str(),ios::out);
        if(plik.good())
        {
            for(int x = 0; x < 100; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    plik<<item_salon[x][y]<<" ";
                    plik<<item_sypialnia[x][y]<<" ";
                    plik<<item_kuchnia[x][y]<<" ";
                    plik<<item_lazienka[x][y]<<" ";
                    plik<<item_ogrod[x][y]<<" ";
                }
            }
            Debug("[Pokoje] Zapisane");
        }
        else
        {
            Debug("[Pokoje] Nie mozna zapisac");
        }

        plik.close();
    }
    void load()
    {
        fstream plik;
        string destiny;
            destiny = "media/download/";
            destiny += login;
            destiny += "_pokoje.ini";
        plik.open(destiny.c_str(),ios::in);
        if(plik.good())
        {
            for(int x = 0; x < 100; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    plik>>item_salon[x][y];
                    plik>>item_sypialnia[x][y];
                    plik>>item_kuchnia[x][y];
                    plik>>item_lazienka[x][y];
                    plik>>item_ogrod[x][y];
                }
            }
            Debug("[Pokoje] Wczytane");
        }
        else
        {
            Debug("[Pokoje] Stworzone");
        }

        plik.close();
    }
    void ustaw(enPokoje typ)
    {
        typPokoju = typ;
    }
    int podnies(int x, int y)
    {
        if(typPokoju == salon)
        {
            for(int a = 99; a >= 0; a--)
            {
                if(x >= item_salon[a][1] && x <= item_salon[a][1] + item[item_salon[a][0]].szer())
                {
                    if(y >= item_salon[a][2] && y <= item_salon[a][2] + item[item_salon[a][0]].wys())
                    {
                        odlOdMyszy_x = x - item_salon[a][1];
                        odlOdMyszy_y = y - item_salon[a][2];

                        int tmp = item_salon[a][0];
                        item_salon[a][0] = 0;
                        return tmp;
                    }
                }
            }
        }

        if(typPokoju == sypialnia)
        {
            for(int a = 99; a >= 0; a--)
            {
                if(x >= item_sypialnia[a][1] && x <= item_sypialnia[a][1] + item[item_sypialnia[a][0]].szer())
                {
                    if(y >= item_sypialnia[a][2] && y <= item_sypialnia[a][2] + item[item_sypialnia[a][0]].wys())
                    {
                        odlOdMyszy_x = x - item_sypialnia[a][1];
                        odlOdMyszy_y = y - item_sypialnia[a][2];

                        int tmp = item_sypialnia[a][0];
                        item_sypialnia[a][0] = 0;
                        return tmp;
                    }
                }
            }
        }

        if(typPokoju == kuchnia)
        {
            for(int a = 99; a >= 0; a--)
            {
                if(x >= item_kuchnia[a][1] && x <= item_kuchnia[a][1] + item[item_kuchnia[a][0]].szer())
                {
                    if(y >= item_kuchnia[a][2] && y <= item_kuchnia[a][2] + item[item_kuchnia[a][0]].wys())
                    {

                        odlOdMyszy_x = x - item_kuchnia[a][1];
                        odlOdMyszy_y = y - item_kuchnia[a][2];

                        int tmp = item_kuchnia[a][0];
                        item_kuchnia[a][0] = 0;
                        return tmp;
                    }
                }
            }
        }

        if(typPokoju == lazienka)
        {
            for(int a = 99; a >= 0; a--)
            {
                if(x >= item_lazienka[a][1] && x <= item_lazienka[a][1] + item[item_lazienka[a][0]].szer())
                {
                    if(y >= item_lazienka[a][2] && y <= item_lazienka[a][2] + item[item_lazienka[a][0]].wys())
                    {

                        odlOdMyszy_x = x - item_lazienka[a][1];
                        odlOdMyszy_y = y - item_lazienka[a][2];

                        int tmp = item_lazienka[a][0];
                        item_lazienka[a][0] = 0;
                        return tmp;
                    }
                }
            }
        }

        if(typPokoju == ogrod)
        {
            for(int a = 99; a >= 0; a--)
            {
                if(x >= item_ogrod[a][1] && x <= item_ogrod[a][1] + item[item_ogrod[a][0]].szer())
                {
                    if(y >= item_ogrod[a][2] && y <= item_ogrod[a][2] + item[item_ogrod[a][0]].wys())
                    {

                        odlOdMyszy_x = x - item_ogrod[a][1];
                        odlOdMyszy_y = y - item_ogrod[a][2];

                        int tmp = item_ogrod[a][0];
                        item_ogrod[a][0] = 0;
                        return tmp;
                    }
                }
            }
        }

        return 0;
    }
    void sortuj()
    {
        for (int x = 0; x < 99; x++)
        {
            if (item_ogrod[x][0] == 0)
            {
                item_ogrod[x][0] = item_ogrod[x + 1][0];
                item_ogrod[x][1] = item_ogrod[x + 1][1];
                item_ogrod[x][2] = item_ogrod[x + 1][2];
                item_ogrod[x + 1][0] = 0;
            }

            if (item_salon[x][0] == 0)
            {
                item_salon[x][0] = item_salon[x + 1][0];
                item_salon[x][1] = item_salon[x + 1][1];
                item_salon[x][2] = item_salon[x + 1][2];
                item_salon[x + 1][0] = 0;
            }

            if (item_sypialnia[x][0] == 0)
            {
                item_sypialnia[x][0] = item_sypialnia[x + 1][0];
                item_sypialnia[x][1] = item_sypialnia[x + 1][1];
                item_sypialnia[x][2] = item_sypialnia[x + 1][2];
                item_sypialnia[x + 1][0] = 0;
            }

            if (item_kuchnia[x][0] == 0)
            {
                item_kuchnia[x][0] = item_kuchnia[x + 1][0];
                item_kuchnia[x][1] = item_kuchnia[x + 1][1];
                item_kuchnia[x][2] = item_kuchnia[x + 1][2];
                item_kuchnia[x + 1][0] = 0;
            }

            if (item_lazienka[x][0] == 0)
            {
                item_lazienka[x][0] = item_lazienka[x + 1][0];
                item_lazienka[x][1] = item_lazienka[x + 1][1];
                item_lazienka[x][2] = item_lazienka[x + 1][2];
                item_lazienka[x + 1][0] = 0;
            }
        }
    }
    bool postaw(int x, int y ,int z)
    {
        // Protekszyn
        if(item[z].szer() + x > 770) x = 770 - item[z].szer();
        if(item[z].wys() + y > 552) y = 552 - item[z].wys();

        if (item[z].getType() == sitable && item[z].wys() + y < 490) y = 490 - item[z].wys();

        if(x < 8) x = 8;
        if(y < 134) y = 134;


        if(typPokoju == salon)
        {
            for(int a = 0; a < 100; a++)
            {
                if(item_salon[a][0] == 0)
                {
                    item_salon[a][0] = z;
                    item_salon[a][1] = x;
                    item_salon[a][2] = y;



                    cout<<"[Debug] [Salon] ID: "<<item_salon[a][0]<<" Poz: "<<item_salon[a][1]<<","<<item_salon[a][2]<<":"<<a<<endl;
                    return true;
                }
            }
        }
        if(typPokoju == sypialnia)
        {
            for(int a = 0; a < 100; a++)
            {
                if(item_sypialnia[a][0] == 0)
                {
                    item_sypialnia[a][0] = z;
                    item_sypialnia[a][1] = x;
                    item_sypialnia[a][2] = y;
                    cout<<"[Debug] [Sypialnia] ID: "<<item_sypialnia[a][0]<<" Poz: "<<item_sypialnia[a][1]<<","<<item_sypialnia[a][2]<<":"<<a<<endl;
                    return true;
                }
            }
        }
        if(typPokoju == kuchnia)
        {
            for(int a = 0; a < 100; a++)
            {
                if(item_kuchnia[a][0] == 0)
                {
                    item_kuchnia[a][0] = z;
                    item_kuchnia[a][1] = x;
                    item_kuchnia[a][2] = y;
                    cout<<"[Debug] [Kuchnia] ID: "<<item_kuchnia[a][0]<<" Poz: "<<item_kuchnia[a][1]<<","<<item_kuchnia[a][2]<<":"<<a<<endl;
                    return true;
                }
            }
        }
        if(typPokoju == lazienka)
        {
            for(int a = 0; a < 100; a++)
            {
                if(item_lazienka[a][0] == 0)
                {
                    item_lazienka[a][0] = z;
                    item_lazienka[a][1] = x;
                    item_lazienka[a][2] = y;
                    cout<<"[Debug] [Lazienka] ID: "<<item_lazienka[a][0]<<" Poz: "<<item_lazienka[a][1]<<","<<item_lazienka[a][2]<<":"<<a<<endl;
                    return true;
                }
            }
        }
        if(typPokoju == ogrod)
        {
            for(int a = 0; a < 100; a++)
            {
                if(item_ogrod[a][0] == 0)
                {
                    item_ogrod[a][0] = z;
                    item_ogrod[a][1] = x;
                    item_ogrod[a][2] = y;
                    cout<<"[Debug] [Ogrod] ID: "<<item_ogrod[a][0]<<" Poz: "<<item_ogrod[a][1]<<","<<item_ogrod[a][2]<<":"<<a<<endl;
                    return true;
                }
            }
        }
        return false;

    }
    void wyswietlItemy()
    {
        if (typPokoju == salon)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_salon[x][0] != 0) item[item_salon[x][0]].wyswietlItem(item_salon[x][1],item_salon[x][2]);
            }
        }
        if (typPokoju == sypialnia)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_sypialnia[x][0] != 0) item[item_sypialnia[x][0]].wyswietlItem(item_sypialnia[x][1],item_sypialnia[x][2]);
            }
        }
        if (typPokoju == kuchnia)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_kuchnia[x][0] != 0) item[item_kuchnia[x][0]].wyswietlItem(item_kuchnia[x][1],item_kuchnia[x][2]);
            }
        }
        if (typPokoju == lazienka)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_lazienka[x][0] != 0) item[item_lazienka[x][0]].wyswietlItem(item_lazienka[x][1],item_lazienka[x][2]);
            }
        }
        if (typPokoju == ogrod)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_ogrod[x][0] != 0) item[item_ogrod[x][0]].wyswietlItem(item_ogrod[x][1],item_ogrod[x][2]);
            }
        }
    }
    void wyswietlTlo()
    {
        if (typPokoju == salon) sp_tlo.setTexture(tex_tlo_salon);
        if (typPokoju == sypialnia) sp_tlo.setTexture(tex_tlo_sypialnia);
        if (typPokoju == kuchnia) sp_tlo.setTexture(tex_tlo_kuchnia);
        if (typPokoju == lazienka) sp_tlo.setTexture(tex_tlo_lazienka);
        if (typPokoju == ogrod) sp_tlo.setTexture(tex_tlo_ogrod);

        sp_tlo.setPosition(8,135);
        window.draw(sp_tlo);
    }
    bool jestPodpora(int srodek, int y)
    {
        if (typPokoju == salon)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_salon[x][2] + item[item_salon[x][0]].getSiadWys() == y)
                {
                    if (item_salon[x][1] + item[item_salon[x][0]].getSiadSzerMin() < srodek && item_salon[x][1] + item[item_salon[x][0]].getSiadSzerMax() > srodek)
                    {
                        return true;
                    }
                }
            }
        }

        if (typPokoju == sypialnia)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_sypialnia[x][2] + item[item_sypialnia[x][0]].getSiadWys() == y)
                {
                    if (item_sypialnia[x][1] + item[item_sypialnia[x][0]].getSiadSzerMin() < srodek && item_sypialnia[x][1] + item[item_sypialnia[x][0]].getSiadSzerMax() > srodek)
                    {
                        return true;
                    }
                }
            }
        }

        if (typPokoju == kuchnia)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_kuchnia[x][2] + item[item_kuchnia[x][0]].getSiadWys() == y)
                {
                    if (item_kuchnia[x][1] + item[item_kuchnia[x][0]].getSiadSzerMin() < srodek && item_kuchnia[x][1] + item[item_kuchnia[x][0]].getSiadSzerMax() > srodek)
                    {
                        return true;
                    }
                }
            }
        }

        if (typPokoju == lazienka)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_lazienka[x][2] + item[item_lazienka[x][0]].getSiadWys() == y)
                {
                    if (item_lazienka[x][1] + item[item_lazienka[x][0]].getSiadSzerMin() < srodek && item_lazienka[x][1] + item[item_lazienka[x][0]].getSiadSzerMax() > srodek)
                    {
                        return true;
                    }
                }
            }
        }

        if (typPokoju == ogrod)
        {
            for (int x = 0; x < 100; x++)
            {
                if (item_ogrod[x][2] + item[item_ogrod[x][0]].getSiadWys() == y)
                {
                    if (item_ogrod[x][1] + item[item_ogrod[x][0]].getSiadSzerMin() < srodek && item_ogrod[x][1] + item[item_ogrod[x][0]].getSiadSzerMax() > srodek)
                    {
                        return true;
                    }
                }
            }
        }



        return false;
    }
    void spadanie()
    {
        if (typPokoju == salon)
        {
            for(int x = 0; x < 100; x++)
            {
                if(item_salon[x][0] >= 300 && item_salon[x][0] < 599)
                {
                    if(jestPodpora(item_salon[x][1] + (item[item_salon[x][0]].szer() / 2),item_salon[x][2] + item[item_salon[x][0]].wys()) == false)
                    {

                        if (item_salon[x][2] + item[item_salon[x][0]].wys() < 552) item_salon[x][2]++;
                    }
                }
            }
        }

        if (typPokoju == sypialnia)
        {
            for(int x = 0; x < 100; x++)
            {
                if(item_sypialnia[x][0] >= 300 && item_sypialnia[x][0] < 599)
                {
                    if(jestPodpora(item_sypialnia[x][1] + (item[item_sypialnia[x][0]].szer() / 2),item_sypialnia[x][2] + item[item_sypialnia[x][0]].wys()) == false)
                    {

                        if (item_sypialnia[x][2] + item[item_sypialnia[x][0]].wys() < 552) item_sypialnia[x][2]++;
                    }
                }
            }
        }

        if (typPokoju == kuchnia)
        {
            for(int x = 0; x < 100; x++)
            {
                if(item_kuchnia[x][0] >= 300 && item_kuchnia[x][0] < 599)
                {
                    if(jestPodpora(item_kuchnia[x][1] + (item[item_kuchnia[x][0]].szer() / 2),item_kuchnia[x][2] + item[item_kuchnia[x][0]].wys()) == false)
                    {

                        if (item_kuchnia[x][2] + item[item_kuchnia[x][0]].wys() < 552) item_kuchnia[x][2]++;
                    }
                }
            }
        }

        if (typPokoju == lazienka)
        {
            for(int x = 0; x < 100; x++)
            {
                if(item_lazienka[x][0] >= 300 && item_lazienka[x][0] < 599)
                {
                    if(jestPodpora(item_lazienka[x][1] + (item[item_lazienka[x][0]].szer() / 2),item_lazienka[x][2] + item[item_lazienka[x][0]].wys()) == false)
                    {

                        if (item_lazienka[x][2] + item[item_lazienka[x][0]].wys() < 552) item_lazienka[x][2]++;
                    }
                }
            }
        }

        if (typPokoju == ogrod)
        {
            for(int x = 0; x < 100; x++)
            {
                if(item_ogrod[x][0] >= 300 && item_ogrod[x][0] < 599)
                {
                    if(jestPodpora(item_ogrod[x][1] + (item[item_ogrod[x][0]].szer() / 2),item_ogrod[x][2] + item[item_ogrod[x][0]].wys()) == false)
                    {

                        if (item_ogrod[x][2] + item[item_ogrod[x][0]].wys() < 552) item_ogrod[x][2]++;
                    }
                }
            }
        }
    }
    void wyswietl()
    {
        sortuj();
        spadanie();
        wyswietlTlo();
        wyswietlItemy();
    }
    enPokoje aktywny()
    {
        return typPokoju;
    }


public:


};
clPokoje pokoje;

#endif // POKOJE_H_INCLUDED
