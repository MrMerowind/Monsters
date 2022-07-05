#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

enum enKomenda
{
    puste,
    siad,
    wstan,
    lezec,
    mrugaj,
    usun,
    idz
};

enum enDir
{
    lewo,
    prawo,
    dol,
    gora

};

enum enStan
{
    siedzi,
    stoi,
    lezy

};

class clPet
{

private:
    enStan stan;
    enKomenda komendy[5];
    enDir kierunek;
    int pozX;
    int pozY;
    unsigned ostatniCzas;

    int fun;
    int food;
    int clean;
    int hp;
    int energy;
    int luck;


    bool bSlp;
    bool akcja;
    unsigned ostatniaAkcja;
    int grafa;

    sf::Sprite sp_pet;
    // Basic
    sf::Texture tex_left_sit;
    sf::Texture tex_left_stand;
    sf::Texture tex_left_lie;

    // Siad
    sf::Texture tex_left_stand_sit_v1;
    sf::Texture tex_left_stand_sit_v2;
    sf::Texture tex_left_stand_sit_v3;

    // Wstan
    sf::Texture tex_left_sit_stand_v1;
    sf::Texture tex_left_sit_stand_v2;
    sf::Texture tex_left_sit_stand_v3;

    // Mrug siedzi
    sf::Texture tex_left_sit_blink_v1;
    sf::Texture tex_left_sit_blink_v2;
    sf::Texture tex_left_sit_blink_v3;
    sf::Texture tex_left_sit_blink_v4;
    sf::Texture tex_left_sit_blink_v5;

    // Mrug stoi
    sf::Texture tex_left_stand_blink_v1;
    sf::Texture tex_left_stand_blink_v2;
    sf::Texture tex_left_stand_blink_v3;
    sf::Texture tex_left_stand_blink_v4;
    sf::Texture tex_left_stand_blink_v5;

    // Kladzie sie
    sf::Texture tex_left_sit_lie_v1;
    sf::Texture tex_left_sit_lie_v2;
    sf::Texture tex_left_sit_lie_v3;
    sf::Texture tex_left_sit_lie_v4;
    sf::Texture tex_left_sit_lie_v5;
    sf::Texture tex_left_sit_lie_v6;

    // Idzie
    sf::Texture tex_left_move_v1;
    sf::Texture tex_left_move_v2;
    sf::Texture tex_left_move_v3;
    sf::Texture tex_left_move_v4;
    sf::Texture tex_left_move_v5;


    // Basic
    sf::Texture tex_right_sit;
    sf::Texture tex_right_stand;
    sf::Texture tex_right_lie;

    // Siad
    sf::Texture tex_right_stand_sit_v1;
    sf::Texture tex_right_stand_sit_v2;
    sf::Texture tex_right_stand_sit_v3;

    // Wstan
    sf::Texture tex_right_sit_stand_v1;
    sf::Texture tex_right_sit_stand_v2;
    sf::Texture tex_right_sit_stand_v3;

    // Mrug siedzi
    sf::Texture tex_right_sit_blink_v1;
    sf::Texture tex_right_sit_blink_v2;
    sf::Texture tex_right_sit_blink_v3;
    sf::Texture tex_right_sit_blink_v4;
    sf::Texture tex_right_sit_blink_v5;

    // Mrug stoi
    sf::Texture tex_right_stand_blink_v1;
    sf::Texture tex_right_stand_blink_v2;
    sf::Texture tex_right_stand_blink_v3;
    sf::Texture tex_right_stand_blink_v4;
    sf::Texture tex_right_stand_blink_v5;

    // Kladzie sie
    sf::Texture tex_right_sit_lie_v1;
    sf::Texture tex_right_sit_lie_v2;
    sf::Texture tex_right_sit_lie_v3;
    sf::Texture tex_right_sit_lie_v4;
    sf::Texture tex_right_sit_lie_v5;
    sf::Texture tex_right_sit_lie_v6;

    // Idzie
    sf::Texture tex_right_move_v1;
    sf::Texture tex_right_move_v2;
    sf::Texture tex_right_move_v3;
    sf::Texture tex_right_move_v4;
    sf::Texture tex_right_move_v5;


public:
    int movementY;
    int movementX;
    clPet()
    {
        stan = stoi;
        kierunek = lewo;
        for(int x = 0; x < 5; x++) komendy[x] = puste;
        akcja = false;
        ostatniaAkcja = GetTickCount();
        grafa = 0;
        movementX = 0;
        movementY = 0;

        fun = 100;
        food = 100;
        clean = 100;
        hp = 100;
        energy = 100;
        luck = 50;
        bSlp = false;

        tex_left_sit.loadFromFile("media/graphic/vulpix/left_sit.png");
        tex_left_stand.loadFromFile("media/graphic/vulpix/left_stand.png");
        tex_left_lie.loadFromFile("media/graphic/vulpix/left_lie_v1.png");

        tex_left_stand_sit_v1.loadFromFile("media/graphic/vulpix/left_stand_sit_v1.png");
        tex_left_stand_sit_v2.loadFromFile("media/graphic/vulpix/left_stand_sit_v2.png");
        tex_left_stand_sit_v3.loadFromFile("media/graphic/vulpix/left_stand_sit_v3.png");

        tex_left_sit_stand_v1.loadFromFile("media/graphic/vulpix/left_sit_stand_v1.png");
        tex_left_sit_stand_v2.loadFromFile("media/graphic/vulpix/left_sit_stand_v2.png");
        tex_left_sit_stand_v3.loadFromFile("media/graphic/vulpix/left_sit_stand_v3.png");

        tex_left_sit_blink_v1.loadFromFile("media/graphic/vulpix/left_sit_blink_v1.png");
        tex_left_sit_blink_v2.loadFromFile("media/graphic/vulpix/left_sit_blink_v2.png");
        tex_left_sit_blink_v3.loadFromFile("media/graphic/vulpix/left_sit_blink_v3.png");
        tex_left_sit_blink_v4.loadFromFile("media/graphic/vulpix/left_sit_blink_v4.png");
        tex_left_sit_blink_v5.loadFromFile("media/graphic/vulpix/left_sit_blink_v5.png");

        tex_left_stand_blink_v1.loadFromFile("media/graphic/vulpix/left_stand_blink_v1.png");
        tex_left_stand_blink_v2.loadFromFile("media/graphic/vulpix/left_stand_blink_v2.png");
        tex_left_stand_blink_v3.loadFromFile("media/graphic/vulpix/left_stand_blink_v3.png");
        tex_left_stand_blink_v4.loadFromFile("media/graphic/vulpix/left_stand_blink_v4.png");
        tex_left_stand_blink_v5.loadFromFile("media/graphic/vulpix/left_stand_blink_v5.png");

        tex_left_sit_lie_v1.loadFromFile("media/graphic/vulpix/left_sit_lie_v1.png");
        tex_left_sit_lie_v2.loadFromFile("media/graphic/vulpix/left_sit_lie_v2.png");
        tex_left_sit_lie_v3.loadFromFile("media/graphic/vulpix/left_sit_lie_v3.png");
        tex_left_sit_lie_v4.loadFromFile("media/graphic/vulpix/left_sit_lie_v4.png");
        tex_left_sit_lie_v5.loadFromFile("media/graphic/vulpix/left_sit_lie_v5.png");
        tex_left_sit_lie_v6.loadFromFile("media/graphic/vulpix/left_sit_lie_v6.png");

        tex_left_move_v1.loadFromFile("media/graphic/vulpix/left_move_v1.png");
        tex_left_move_v2.loadFromFile("media/graphic/vulpix/left_move_v2.png");
        tex_left_move_v3.loadFromFile("media/graphic/vulpix/left_move_v3.png");
        tex_left_move_v4.loadFromFile("media/graphic/vulpix/left_move_v4.png");
        tex_left_move_v5.loadFromFile("media/graphic/vulpix/left_move_v5.png");



        tex_right_sit.loadFromFile("media/graphic/vulpix/right_sit.png");
        tex_right_stand.loadFromFile("media/graphic/vulpix/right_stand.png");
        tex_right_lie.loadFromFile("media/graphic/vulpix/right_lie_v1.png");

        tex_right_stand_sit_v1.loadFromFile("media/graphic/vulpix/right_stand_sit_v1.png");
        tex_right_stand_sit_v2.loadFromFile("media/graphic/vulpix/right_stand_sit_v2.png");
        tex_right_stand_sit_v3.loadFromFile("media/graphic/vulpix/right_stand_sit_v3.png");

        tex_right_sit_stand_v1.loadFromFile("media/graphic/vulpix/right_sit_stand_v1.png");
        tex_right_sit_stand_v2.loadFromFile("media/graphic/vulpix/right_sit_stand_v2.png");
        tex_right_sit_stand_v3.loadFromFile("media/graphic/vulpix/right_sit_stand_v3.png");

        tex_right_sit_blink_v1.loadFromFile("media/graphic/vulpix/right_sit_blink_v1.png");
        tex_right_sit_blink_v2.loadFromFile("media/graphic/vulpix/right_sit_blink_v2.png");
        tex_right_sit_blink_v3.loadFromFile("media/graphic/vulpix/right_sit_blink_v3.png");
        tex_right_sit_blink_v4.loadFromFile("media/graphic/vulpix/right_sit_blink_v4.png");
        tex_right_sit_blink_v5.loadFromFile("media/graphic/vulpix/right_sit_blink_v5.png");

        tex_right_stand_blink_v1.loadFromFile("media/graphic/vulpix/right_stand_blink_v1.png");
        tex_right_stand_blink_v2.loadFromFile("media/graphic/vulpix/right_stand_blink_v2.png");
        tex_right_stand_blink_v3.loadFromFile("media/graphic/vulpix/right_stand_blink_v3.png");
        tex_right_stand_blink_v4.loadFromFile("media/graphic/vulpix/right_stand_blink_v4.png");
        tex_right_stand_blink_v5.loadFromFile("media/graphic/vulpix/right_stand_blink_v5.png");

        tex_right_sit_lie_v1.loadFromFile("media/graphic/vulpix/right_sit_lie_v1.png");
        tex_right_sit_lie_v2.loadFromFile("media/graphic/vulpix/right_sit_lie_v2.png");
        tex_right_sit_lie_v3.loadFromFile("media/graphic/vulpix/right_sit_lie_v3.png");
        tex_right_sit_lie_v4.loadFromFile("media/graphic/vulpix/right_sit_lie_v4.png");
        tex_right_sit_lie_v5.loadFromFile("media/graphic/vulpix/right_sit_lie_v5.png");
        tex_right_sit_lie_v6.loadFromFile("media/graphic/vulpix/right_sit_lie_v6.png");

        tex_right_move_v1.loadFromFile("media/graphic/vulpix/right_move_v1.png");
        tex_right_move_v2.loadFromFile("media/graphic/vulpix/right_move_v2.png");
        tex_right_move_v3.loadFromFile("media/graphic/vulpix/right_move_v3.png");
        tex_right_move_v4.loadFromFile("media/graphic/vulpix/right_move_v4.png");
        tex_right_move_v5.loadFromFile("media/graphic/vulpix/right_move_v5.png");



        pozX = 100;
        pozY = 450;
        ostatniCzas = GetTickCount();

        sp_pet.setScale(171.0 / 475.0, 119.0 / 379.0);

    }
    void save()
    {
        fstream plik;
        string destiny;
        destiny = "media/upload/";
            destiny += login;
            destiny += "_pet.ini";
        plik.open(destiny.c_str(),ios::out);
        if(plik.good())
        {
            plik<<food<<" "<<clean<<" "<<hp<<" "<<energy<<" "<<luck<<" "<<time(NULL);
            Debug("[Vulpix] Zapisane");
        }
        else
        {
            Debug("[Vulpix] Nie mozna zapisac");
        }

        plik.close();
    }
    void load()
    {
        fstream plik;
        string destiny;
            destiny = "media/download/";
            destiny += login;
            destiny += "_pet.ini";
        plik.open(destiny.c_str(),ios::in);
        if(plik.good())
        {
            int tmp;
            plik>>food>>clean>>hp>>energy>>luck>>tmp;
            Debug("[Vulpix] Wczytane");
            tmp = time(NULL) - tmp;
            if(tmp >= 1800) addEnergy(-100);
            while(getFood() > 0 && tmp >= 20)
            {
                addFood(-1);
                tmp -= 20;
            }
            while(getHp() > 0 && tmp >= 1728)
            {
                addHp(-1);
                tmp -= 1728;
            }



        }
        else
        {
            Debug("[Vulpix] Stworzone");
        }

        plik.close();
    }
    int getFun()
    {
        return fun;
    }
    int getPozX()
    {
        return pozX;
    }
    int getPozY()
    {
        return pozY;
    }
    int getHp()
    {
        return hp;
    }
    int getFood()
    {
        return food;
    }
    int getClean()
    {
        return clean;
    }
    int getEnergy()
    {
        return energy;
    }
    int getLuck()
    {
        return luck;
    }
    enStan getState()
    {
        return stan;
    }
    void setState(enStan value)
    {
        stan = value;
    }
    void setKierunek(enDir value)
    {
        kierunek = value;
    }
    void addFun(int value)
    {
        fun += value;
        if (fun < 0)
        {
            fun = 0;
        }
        else if (fun > 100)
        {
            fun = 100;
        }
    }
    void slp(bool value)
    {
        bSlp = value;
    }
    bool isSlp()
    {
        return bSlp;
    }
    void addFood(int value)
    {
        food += value;
        if (food < 0)
        {
            food = 0;
        }
        else if (food > 100)
        {
            addHp((food - 100) / 2);
            food = 100;
        }
    }
    void addHp(int value)
    {
        hp += value;
        if (hp < 0)
        {
            hp = 0;
        }
        else if (hp > 100)
        {
            hp = 100;
        }
    }
    void setPosition(int x , int y)
    {

        //if(x < 8) x = 8;
        if(y < 134) y = 134;

        if(171 + x > 770) x = 770 - 171;
        if(y > 592 - 119) y = 592 - 119;

        pozX = x;
        pozY = y;
    }
    void addClean(int value)
    {
        clean += value;
        if (clean < 0)
        {
            clean = 0;
        }
        else if (clean > 100)
        {
            clean = 100;
        }
    }
    void addEnergy(int value)
    {
        energy += value;
        if (energy < 0)
        {
            energy = 0;
        }
        else if (energy > 100)
        {
            energy = 100;
        }
    }
    void setLuck(int value)
    {
        luck = value;
    }
    void kolejka(enKomenda cmd)
    {
        if(cmd == usun)
        {
            komendy[0] = komendy[1];
            komendy[1] = komendy[2];
            komendy[2] = komendy[3];
            komendy[3] = komendy[4];
            komendy[4] = puste;
            akcja = false;
        }
        else
        {

            for(int x =0; x < 5; x++)
            {
                if (komendy[x] == puste)
                {
                    komendy[x] = cmd;
                    break;
                }
                if(x == 4) Debug("[Wola] [Error] Kolejka pelna");
            }
        }
    }
    void przesun(int x, int y)
    {
        pozX += x;
        pozY += y;

        if(pozX < 8) pozX = 8;
        if(pozY < 134) pozY = 134;

        if(171 + pozX > 770) pozX = 770 - 171;
        if(pozY > 592 - 119) pozY = 592 - 119;
    }
    void wolnaWola()
    {
        addFun(predefinedPetFun);
        predefinedPetFun = 0;

        if(GetTickCount() >= ostatniCzas + 2000)
        {
            if(vulpixMove)
            {
                ostatniCzas += 2000;
                return;
            }
            if (isSlp())
            {
                addEnergy(1);
                if(ppb(50))addHp(1);
            }
            else
            {
                if(ppb(10))
                {
                    addEnergy(-1);
                    Debug("[Vulpix] Energia spada");
                }
                if(ppb(10))
                {
                    if(getFood() == 0)
                    {
                        if(ppb(1))
                        {
                            if(ppb(10))
                            {
                                addHp(-1);
                                Debug("[Vulpix] Zdrowie maleje");
                            }
                        }
                    }
                    else
                    {
                        addFood(-1);
                        Debug("[Vulpix] Glod rosnie");
                    }
                }
                if(ppb(50))addFun(-1);
                {
                    addFun(-1);
                    Debug("[Vulpix] Zabawa maleje");
                }
            }
            ostatniCzas += 2000;
            if(getEnergy() < 20)
            {
                        if(stan == siedzi)
                        {
                            Debug("[Wola] Kladzie sie");
                            kolejka(lezec);
                        }
                        else if(stan == stoi)
                        {
                            Debug("[Wola] Siada");
                            Debug("[Wola] Kladzie sie");
                            kolejka(siad);
                            kolejka(lezec);
                        }
            }



            if (ppb(20) && komendy[0] == puste)
            {
                if(stan == siedzi)
                {
                    Debug("[Wola] Wstaje");
                    kolejka(wstan);
                }
                else if(stan == stoi)
                {
                    if(ppb(50))
                    {
                        Debug("[Wola] Siada");
                        kolejka(siad);
                    }
                    else
                    {
                        Debug("[Wola] Idzie");
                        movementX = random(100,250);
                        if(getPozX() < 370) kierunek = prawo;
                        else kierunek = lewo;
                        kolejka(idz);
                    }
                }
                else if(stan == lezy)
                {

                }
            }
            else if (stan != lezy && komendy[0] == puste)
            {
                Debug("[Wola] Mruga");
                kolejka(mrugaj);
            }
        }
    }
    void spadanie()
    {
        if (pokoje.jestPodpora(pozX + 85,pozY + 119) == false && pozY + 119 < 572)
        {
            przesun(0,1);
        }
    }
    void wyswietl()
    {
        spadanie();

        wolnaWola();
        if (kierunek == lewo)
        {
            if(komendy[0] == puste)
            {
                if(stan == siedzi)
                {
                    sp_pet.setTexture(tex_left_sit);
                }
                if(stan == stoi)
                {
                    sp_pet.setTexture(tex_left_stand);
                }
                if(stan == lezy) sp_pet.setTexture(tex_left_lie);
            }
            else if(komendy[0] == siad)
            {
                if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_left_stand);
                        else if (grafa == 1) sp_pet.setTexture(tex_left_stand_sit_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_left_stand_sit_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_left_stand_sit_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_left_sit);
                        else if (grafa >= 5)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = siedzi;
                        }
                    }
                }
                else if(stan == siedzi)
                {
                    Debug("[Wola] [Error] Juz siedzi");
                    kolejka(usun);
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }

            else if(komendy[0] == wstan)
            {
                if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_left_sit);
                        else if (grafa == 1) sp_pet.setTexture(tex_left_sit_stand_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_left_sit_stand_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_left_sit_stand_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_left_stand);
                        else if (grafa >= 5)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = stoi;
                        }
                    }
                }
                else if(stan == stoi)
                {
                    Debug("[Wola] [Error] Juz stoi");
                    kolejka(usun);
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }

            else if(komendy[0] == mrugaj)
            {
                if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_left_sit);
                        else if (grafa == 1) sp_pet.setTexture(tex_left_sit_blink_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_left_sit_blink_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_left_sit_blink_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_left_sit_blink_v4);
                        else if (grafa == 5) sp_pet.setTexture(tex_left_sit_blink_v5);
                        else if (grafa == 6) sp_pet.setTexture(tex_left_sit);
                        else if (grafa >= 7)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = siedzi;
                        }
                    }
                }
                else if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        ostatniaAkcja +=100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_left_stand);
                    else if (grafa == 1) sp_pet.setTexture(tex_left_stand_blink_v1);
                    else if (grafa == 2) sp_pet.setTexture(tex_left_stand_blink_v2);
                    else if (grafa == 3) sp_pet.setTexture(tex_left_stand_blink_v3);
                    else if (grafa == 4) sp_pet.setTexture(tex_left_stand_blink_v4);
                    else if (grafa == 5) sp_pet.setTexture(tex_left_stand_blink_v5);
                    else if (grafa == 6) sp_pet.setTexture(tex_left_stand);
                    else if (grafa >= 7)
                    {
                        akcja = false;
                        kolejka(usun);
                        stan = stoi;
                    }
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }
            else if(komendy[0] == lezec)
            {
                if(movementY != 0) pozY = movementY - 120;
                movementY = 0;

                if(stan == stoi)
                {
                    Debug("[Wola] [ Error] Kladzie sie stojac");
                    kolejka(usun);
                }
                else if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        ostatniaAkcja +=100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_left_sit);
                    else if (grafa == 1) sp_pet.setTexture(tex_left_sit_lie_v1);
                    else if (grafa == 2) sp_pet.setTexture(tex_left_sit_lie_v2);
                    else if (grafa == 3) sp_pet.setTexture(tex_left_sit_lie_v3);
                    else if (grafa == 4) sp_pet.setTexture(tex_left_sit_lie_v4);
                    else if (grafa == 5) sp_pet.setTexture(tex_left_sit_lie_v5);
                    else if (grafa == 6) sp_pet.setTexture(tex_left_sit_lie_v6);
                    else if (grafa == 7) sp_pet.setTexture(tex_left_lie);
                    else if (grafa >= 7)
                    {
                        akcja = false;
                        stan = lezy;
                    }
                }
                else if(stan == lezy)
                {
                    if(akcja == false && getEnergy() == 100)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else if (akcja == true)
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            slp(false);
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_left_lie);
                        else if (grafa == 1) sp_pet.setTexture(tex_left_sit_lie_v6);
                        else if (grafa == 2) sp_pet.setTexture(tex_left_sit_lie_v5);
                        else if (grafa == 3) sp_pet.setTexture(tex_left_sit_lie_v4);
                        else if (grafa == 4) sp_pet.setTexture(tex_left_sit_lie_v3);
                        else if (grafa == 5) sp_pet.setTexture(tex_left_sit_lie_v2);
                        else if (grafa == 6) sp_pet.setTexture(tex_left_sit_lie_v1);
                        else if (grafa == 7) sp_pet.setTexture(tex_left_sit);
                        else if (grafa >= 7)
                        {
                            akcja = false;
                            stan = siedzi;
                            kolejka(usun);
                        }
                    }
                    else if (getEnergy() < 100)
                    {
                        sp_pet.setTexture(tex_left_lie);
                        slp(true);
                    }
                    else
                    {
                        Debug("[Error] Cos przy lezeniu z komenda lezec");
                    }
                }
            }
            else if(komendy[0] == idz)
            {
                if(stan == siedzi)
                {
                    Debug("[Wola] [Error] Nie moze isc siedzac");
                    kolejka(usun);
                }
                else if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        pozX -= 3;
                        movementX -= 3;
                        ostatniaAkcja += 100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_left_stand);
                    else
                    {
                        if(grafa % 5 == 1) sp_pet.setTexture(tex_left_move_v1);
                        if(grafa % 5 == 2) sp_pet.setTexture(tex_left_move_v2);
                        if(grafa % 5 == 3) sp_pet.setTexture(tex_left_move_v3);
                        if(grafa % 5 == 4) sp_pet.setTexture(tex_left_move_v4);
                        if(grafa % 5 == 0) sp_pet.setTexture(tex_left_move_v5);
                    }

                    if (movementX < 0)
                    {
                        akcja = false;
                        kolejka(usun);
                    }
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }
        }
        else if(kierunek == prawo) // Elo ale dlugie
        {
            if(komendy[0] == puste)
            {
                if(stan == siedzi)
                {
                    sp_pet.setTexture(tex_right_sit);
                }
                if(stan == stoi)
                {
                    sp_pet.setTexture(tex_right_stand);
                }
                if(stan == lezy) sp_pet.setTexture(tex_right_lie);
            }
            else if(komendy[0] == siad)
            {
                if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_right_stand);
                        else if (grafa == 1) sp_pet.setTexture(tex_right_stand_sit_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_right_stand_sit_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_right_stand_sit_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_right_sit);
                        else if (grafa >= 5)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = siedzi;
                        }
                    }
                }
                else if(stan == siedzi)
                {
                    Debug("[Wola] [Error] Juz siedzi");
                    kolejka(usun);
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }

            else if(komendy[0] == wstan)
            {
                if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_right_sit);
                        else if (grafa == 1) sp_pet.setTexture(tex_right_sit_stand_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_right_sit_stand_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_right_sit_stand_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_right_stand);
                        else if (grafa >= 5)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = stoi;
                        }
                    }
                }
                else if(stan == stoi)
                {
                    Debug("[Wola] [Error] Juz stoi");
                    kolejka(usun);
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }

            else if(komendy[0] == mrugaj)
            {
                if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_right_sit);
                        else if (grafa == 1) sp_pet.setTexture(tex_right_sit_blink_v1);
                        else if (grafa == 2) sp_pet.setTexture(tex_right_sit_blink_v2);
                        else if (grafa == 3) sp_pet.setTexture(tex_right_sit_blink_v3);
                        else if (grafa == 4) sp_pet.setTexture(tex_right_sit_blink_v4);
                        else if (grafa == 5) sp_pet.setTexture(tex_right_sit_blink_v5);
                        else if (grafa == 6) sp_pet.setTexture(tex_right_sit);
                        else if (grafa >= 7)
                        {
                            akcja = false;
                            kolejka(usun);
                            stan = siedzi;
                        }
                    }
                }
                else if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        ostatniaAkcja +=100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_right_stand);
                    else if (grafa == 1) sp_pet.setTexture(tex_right_stand_blink_v1);
                    else if (grafa == 2) sp_pet.setTexture(tex_right_stand_blink_v2);
                    else if (grafa == 3) sp_pet.setTexture(tex_right_stand_blink_v3);
                    else if (grafa == 4) sp_pet.setTexture(tex_right_stand_blink_v4);
                    else if (grafa == 5) sp_pet.setTexture(tex_right_stand_blink_v5);
                    else if (grafa == 6) sp_pet.setTexture(tex_right_stand);
                    else if (grafa >= 7)
                    {
                        akcja = false;
                        kolejka(usun);
                        stan = stoi;
                    }
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }
            else if(komendy[0] == lezec)
            {
                if(stan == stoi)
                {
                    Debug("[Wola] [ Error] Kladzie sie stojac");
                    kolejka(usun);
                }
                else if(stan == siedzi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        ostatniaAkcja +=100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_right_sit);
                    else if (grafa == 1) sp_pet.setTexture(tex_right_sit_lie_v1);
                    else if (grafa == 2) sp_pet.setTexture(tex_right_sit_lie_v2);
                    else if (grafa == 3) sp_pet.setTexture(tex_right_sit_lie_v3);
                    else if (grafa == 4) sp_pet.setTexture(tex_right_sit_lie_v4);
                    else if (grafa == 5) sp_pet.setTexture(tex_right_sit_lie_v5);
                    else if (grafa == 6) sp_pet.setTexture(tex_right_sit_lie_v6);
                    else if (grafa == 7) sp_pet.setTexture(tex_right_lie);
                    else if (grafa >= 7)
                    {
                        akcja = false;
                        stan = lezy;
                    }
                }
                else if(stan == lezy)
                {
                    if(akcja == false && getEnergy() == 100)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    else if (akcja == true)
                    {
                        if (GetTickCount() >= ostatniaAkcja + 100)
                        {
                            slp(false);
                            grafa++;
                            ostatniaAkcja +=100;
                        }
                        if (grafa == 0) sp_pet.setTexture(tex_right_lie);
                        else if (grafa == 1) sp_pet.setTexture(tex_right_sit_lie_v6);
                        else if (grafa == 2) sp_pet.setTexture(tex_right_sit_lie_v5);
                        else if (grafa == 3) sp_pet.setTexture(tex_right_sit_lie_v4);
                        else if (grafa == 4) sp_pet.setTexture(tex_right_sit_lie_v3);
                        else if (grafa == 5) sp_pet.setTexture(tex_right_sit_lie_v2);
                        else if (grafa == 6) sp_pet.setTexture(tex_right_sit_lie_v1);
                        else if (grafa == 7) sp_pet.setTexture(tex_right_sit);
                        else if (grafa >= 7)
                        {
                            akcja = false;
                            stan = siedzi;
                            kolejka(usun);
                        }
                    }
                    else if (getEnergy() < 100)
                    {
                        sp_pet.setTexture(tex_right_lie);
                        slp(true);
                    }
                    else
                    {
                        Debug("[Error] Cos przy lezeniu z komenda lezec");
                    }
                }
            }
            else if(komendy[0] == idz)
            {
                if(stan == siedzi)
                {
                    Debug("[Wola] [Error] Nie moze isc siedzac");
                    kolejka(usun);
                }
                else if(stan == stoi)
                {
                    if(akcja == false)
                    {
                        akcja = true;
                        grafa = 0;
                        ostatniaAkcja = GetTickCount();
                    }
                    if (GetTickCount() >= ostatniaAkcja + 100)
                    {
                        grafa++;
                        pozX += 3;
                        movementX -= 3;
                        ostatniaAkcja += 100;
                    }
                    if (grafa == 0) sp_pet.setTexture(tex_right_stand);
                    else
                    {
                        if(grafa % 5 == 1) sp_pet.setTexture(tex_right_move_v1);
                        if(grafa % 5 == 2) sp_pet.setTexture(tex_right_move_v2);
                        if(grafa % 5 == 3) sp_pet.setTexture(tex_right_move_v3);
                        if(grafa % 5 == 4) sp_pet.setTexture(tex_right_move_v4);
                        if(grafa % 5 == 0) sp_pet.setTexture(tex_right_move_v5);
                    }

                    if (movementX < 0)
                    {
                        akcja = false;
                        kolejka(usun);
                    }
                }
                else if(stan == lezy)
                {
                    Debug("[Wola] [Error] Teraz spi");
                    kolejka(usun);
                }
            }
        }
        sp_pet.setPosition(pozX,pozY);
        if(lumber.isActive() == false && shop.isActive() == false)
        window.draw(sp_pet);
    }




};
clPet pet;


#endif // PET_H_INCLUDED
