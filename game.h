#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class clLumber
{

private:
    bool active;
    bool bStart;
    int axePosition;
    unsigned lastTimeAxe;
    int hearths;
    int points;
    int timer;
    unsigned addLastTime;
    unsigned przesunLastTime;
    //   [Rzad][ID][0 - poz 2 - typ]
    int log[2][10][2];

    sf::Sprite bg;
    sf::Texture bg_lumber_clear;
    sf::Texture bg_lumber_start;
    sf::Texture bg_lumber_lose;
    sf::Sprite axe;
    sf::Texture axe_down;
    sf::Texture axe_up;
    sf::Sprite sp_hearth;
    sf::Texture tex_hrt;

    sf::Text pts;
    sf::Font fnt;

    sf::Sprite sp_log;
    sf::Sprite sp_bomb;

    sf::Texture tex_log;
    sf::Texture tex_bomb;

    sf::Sprite sp_eqoff;
    sf::Texture tex_eqoff;


public:
    clLumber()
    {
        przesunLastTime = GetTickCount();
        addLastTime = GetTickCount();
        timer = 10;
        active = false;
        bStart = false;
        points = 0;
        bg_lumber_clear.loadFromFile("media/graphic/games/lumbermill/background.png");
        bg_lumber_start.loadFromFile("media/graphic/games/lumbermill/start.png");
        bg_lumber_lose.loadFromFile("media/graphic/games/lumbermill/lose.png");
        axe_down.loadFromFile("media/graphic/games/lumbermill/axe_down.png");
        axe_up.loadFromFile("media/graphic/games/lumbermill/axe_up.png");
        tex_hrt.loadFromFile("media/graphic/games/lumbermill/heart.png");
        tex_bomb.loadFromFile("media/graphic/games/lumbermill/bomb.png");
        tex_log.loadFromFile("media/graphic/games/lumbermill/log.png");
        sp_bomb.setTexture(tex_bomb);
        sp_log.setTexture(tex_log);
        sp_hearth.setTexture(tex_hrt);
        bg.setPosition(8,135);

        fnt.loadFromFile("media/fonts/points.ttf");
        pts.setFont(fnt);
        pts.setPosition(13,135);
        pts.setCharacterSize(50);
        pts.setColor(sf::Color::Black);

        for(int x = 0; x < 2; x++)
        {
            for(int y = 0; y < 10; y++)
            {
                for(int z = 0; z < 2; z++)
                {
                    log[x][y][z] == 0;
                }
            }
        }

        tex_eqoff.loadFromFile("media/graphic/window/background_new_eqoff.png");
        sp_eqoff.setTexture(tex_eqoff);

    }
    bool isActive()
    {
        return active;
    }
    void start()
    {
        Debug("[Tartak] Start");
        active = true;
        hearths = 3;
        timer = 10;

        for(int x = 0; x < 2; x++)
        {
            for(int y = 0; y < 10; y++)
            {
                for(int z = 0; z < 2; z++)
                {
                    log[x][y][z] == 0;
                }
            }
        }

        addLastTime = GetTickCount();
        przesunLastTime = GetTickCount();
        lastTimeAxe = GetTickCount();
    }
    void axeDown(int lane)
    {
        Debug("[Tartak] Ciecie");
        if(active == false) return;
        axePosition = lane;
        lastTimeAxe = GetTickCount();
        // 290-330
        for(int y = 0; y < 10; y++)
        {
            if(log[lane - 1][y][0] >= 280 && log[lane - 1][y][0] <= 340)
            {
                if(log[lane - 1][y][1] == 1)
                {
                    points += random(1,points / 50 + 2);
                    Debug("[Tartak] Trafiono w klode");
                    if(ppb(2))
                    {
                        hearths++;
                        Debug("[Tartak] Bonus zycia");
                    }
                }
                if(log[lane - 1][y][1] == 2)
                {
                    hearths--;
                    Debug("[Tartak] Trafiono w bombe");
                    Debug("[Tartak] Utracono zycie");
                }
                log[lane - 1][y][1] = 0;
            }

        }

    }
    void axeUp()
    {
        axePosition = 0;
    }
    void stop()
    {
        Debug("[Tartak] Stop");
        active = false;
        bStart = false;
        points = 0;

        for(int x = 0; x < 2; x++)
        {
            for(int y = 0; y < 10; y++)
            {
                for(int z = 0; z < 2; z++)
                {
                    log[x][y][z] == 0;
                }
            }
        }
    }
    void logDodaj()
    {
        bool brk = false;
        int lane = random(0,2);
        for(int x = 0; x < 10; x++)
        {
            if(log[lane][x][1] == 0)
            {
                log[lane][x][0] = 700;
                if (ppb(90)) log[lane][x][1] = 1;
                else log[lane][x][1] = 2;
                Debug("[Tartak] Spawn");
                brk = true;
                break;
            }
            if (brk) break;
        }
    }
    void logPrzesun()
    {
        for(int x = 0; x < 2; x++)
        {
            for(int y = 0; y < 10; y++)
            {
                log[x][y][0] -=2;
            }
        }
    }
    void logWyswietl()
    {
        for(int x = 0; x < 10; x++)
        {
            if(log[0][x][1] == 1)
            {
                sp_log.setPosition(log[0][x][0],349);
                window.draw(sp_log);
            }
            if(log[0][x][1] == 2)
            {
                sp_bomb.setPosition(log[0][x][0],349);
                window.draw(sp_bomb);
            }
        }

        for(int x = 0; x < 10; x++)
        {
            if(log[1][x][1] == 1)
            {
                sp_log.setPosition(log[1][x][0],430);
                window.draw(sp_log);
            }
            if(log[1][x][1] == 2)
            {
                sp_bomb.setPosition(log[1][x][0],430);
                window.draw(sp_bomb);
            }
        }
    }
    void logUsun()
    {
        for(int x = 0; x < 2; x++)
        {
            for(int y = 0; y < 10; y++)
            {
                if(log[x][y][0] < 231)
                {
                    if(log[x][y][1] == 1)
                    {
                        Debug("[Tartak] Kloda nie zostala trafiona");
                        Debug("[Tartak] Utracono zycie");
                        hearths--;
                    }
                    log[x][y][1] = 0;

                }
            }
        }
    }
    void wyswietl()
    {
        if(bStart == false)
        {
            bg.setTexture(bg_lumber_start);
            window.draw(bg);
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
            {
                addLastTime = GetTickCount();
                przesunLastTime = GetTickCount();
                lastTimeAxe = GetTickCount();
                bStart = true;
            }
        }
        else if(hearths == 0)
        {
            inventory.addGold(points);
            predefinedPetFun += 20;
            hearths = -1;
            Debug("[Tartak] Zdobyto zloto");
        }
        else if(hearths <= -1)
        {
            bg.setTexture(bg_lumber_lose);
            window.draw(bg);
            pts.setString(int_to_string(points));
            pts.setPosition(350,297);
            window.draw(pts);
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
            {
                stop();
                start();
            }
        }
        else
        {
            bg.setTexture(bg_lumber_clear);
            window.draw(bg);
            for(int x = 0; x < hearths; x++)
            {
                sp_hearth.setPosition(720 - (x*55),135);
                window.draw(sp_hearth);
            }

            pts.setString(int_to_string(points));
            pts.setPosition(13,135);
            window.draw(pts);

            // Te przesuwania

            // Szybkosc
            if(points >= 325680) timer = 1;
            else if(points >= 162840) timer = 2;
            else if(points >= 81920) timer = 3;
            else if(points >= 40960) timer = 4;
            else if(points >= 20480) timer = 5;
            else if(points >= 10240) timer = 6;
            else if(points >= 5120) timer = 7;
            else if(points >= 2560) timer = 8;
            else if(points >= 1280) timer = 9;
            else if(points >= 640) timer = 10;
            else if(points >= 320) timer = 11;
            else if(points >= 160) timer = 12;
            else if(points >= 80) timer = 13;
            else if(points >= 40) timer = 14;
            else if(points >= 20) timer = 15;
            else if(points >= 10) timer = 16;
            else if(points >= 0) timer = 17;

            // Renderowanie
            if (addLastTime + timer * 50 < GetTickCount())
            {
                logDodaj();
                addLastTime += timer * 50;
            }
            if (przesunLastTime + timer < GetTickCount())
            {
                logPrzesun();
                przesunLastTime += timer;
            }
            logWyswietl();
            logUsun();



            if(lastTimeAxe + 200 < GetTickCount()) axeUp();

            if(axePosition == 0)
            {
                axe.setTexture(axe_up);
                axe.setPosition(130,300);
                window.draw(axe);
            }
            if(axePosition == 1)
            {
                axe.setTexture(axe_down);
                axe.setPosition(185,305);
                window.draw(axe);
            }
            if(axePosition == 2)
            {
                axe.setTexture(axe_down);
                axe.setPosition(186,381);
                window.draw(axe);
            }
        }
    }
    void render_eq_off()
    {
        window.draw(sp_eqoff);
    }



};

clLumber lumber;

#endif // GAME_H_INCLUDED
