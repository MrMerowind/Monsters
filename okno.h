#ifndef OKNO_H_INCLUDED
#define OKNO_H_INCLUDED

class clOkno
{
private:
    int pozX;
    int pozY;
    sf::Sprite sp_bg;
    sf::Texture tex_bg;
    sf::Sprite sp_dark;
    sf::Texture tex_dark;

    bool bPrzesuwanie;
    bool przedPrzesuwaniem;
    int przesuwanieX;
    int przesuwanieY;

    bool minimized;

    bool bFocus;




public:
    clOkno()
    {

        window.create(sf::VideoMode(1100, 600), "Monsters",sf::Style::None);
        tex_bg.loadFromFile("media/graphic/window/background_new.png");
        sp_bg.setTexture(tex_bg);
        tex_dark.loadFromFile("media/graphic/window/dark.png");
        sp_dark.setTexture(tex_dark);
        Debug("Stworzone okno");
        pozX = window.getPosition().x;
        pozY = window.getPosition().y;
        window.setVerticalSyncEnabled(true);
        window.setMouseCursorVisible(false);
        minimized = false;
        bFocus = true;
        bPrzesuwanie = false;
        przedPrzesuwaniem = false;
    }
    bool otwarte()
    {
        if(window.isOpen()) return true;
        else return false;
    }

    void focus(bool x)
    {
        bFocus = x;
    }
    bool getFocus()
    {
        return bFocus;
    }
    void wyjscie()
    {
        sf::Sprite sp_save;
        sf::Texture tex_save;
        tex_save.loadFromFile("media/graphic/window/background_new_save.png");
        sp_save.setTexture(tex_save);
        window.draw(sp_save);
        window.display();

    Debug("ZAPISYWANIE PROSZE CZEKAC | ZAPISYWANIE PROSZE CZEKAC");
    Debug("ZAPISYWANIE PROSZE CZEKAC | ZAPISYWANIE PROSZE CZEKAC");
    Debug("ZAPISYWANIE PROSZE CZEKAC | ZAPISYWANIE PROSZE CZEKAC");
    Debug("ZAPISYWANIE PROSZE CZEKAC | ZAPISYWANIE PROSZE CZEKAC");
    inventory.save();
    pokoje.save();
    pet.save();

        sf::Ftp::Response response;

        Debug("[Patcher] Laczenie z serwerem...");

        while(response.isOk() == false)
        {
            response = ftp.connect("ftp.monsters.aq.pl");
        }
            Debug("[Patcher] Logowanie");
            ftp.login("monsters.aq.pl", "Monsters!");
            Debug("[Patcher] Wysylanie...");

            string destiny;
            destiny = "media/upload/";
            destiny += login;
            destiny += "_inventory.ini";
            response = ftp.upload(destiny, "User/", sf::Ftp::Binary);
            Debug("[Patcher] 1/3");
            destiny = "media/upload/";
            destiny += login;
            destiny += "_pokoje.ini";
            response = ftp.upload(destiny, "User/", sf::Ftp::Binary);
            Debug("[Patcher] 2/3");
            destiny = "media/upload/";
            destiny += login;
            destiny += "_pet.ini";
            response = ftp.upload(destiny, "User/", sf::Ftp::Binary);
            Debug("[Patcher] 3/3");

        window.close();
        Debug("Okno zamkniete");
    }
    void setPosition(int x, int y)
    {
        pozX = x;
        pozY = y;
    }
    void przesuwanie()
    {
        if (mysz.y() <= 130 && mysz.y() >= 0 && mysz.x() >= 360 && mysz.x() <= 1100)
        {
            if (!mysz.LPM())
                przedPrzesuwaniem = true;
        }
        else przedPrzesuwaniem = false;

        if (mysz.y() <= 130 && mysz.y() >= 0 && mysz.x() >= 0 && mysz.x() <= 1100 && mysz.LPM() && przedPrzesuwaniem)
        {
            if(bPrzesuwanie == false)
            {
                bPrzesuwanie = true;
                przesuwanieX = mysz.x();
                przesuwanieY = mysz.y();
            }
        }
        if (bPrzesuwanie == true)
        {
            pozX += mysz.x() - przesuwanieX;
            pozY += mysz.y() - przesuwanieY;
            mysz.windowMove();
        }
        else mysz.cursor();

        if (!mysz.LPM())
        {
            bPrzesuwanie = false;
        }

    }
    void wyswietl()
    {
        // Czyszczenie
        window.clear();

        if (lumber.isActive())
        {
            lumber.wyswietl();
        }
        else if(shop.isActive())
        {
            shop.wyswietl();
            pSklepPodstawowe.wyswietl();
            pSklepNaSciane.wyswietl();
            pSklepOzdoby.wyswietl();
            pSklepJedzenie.wyswietl();

            if(pSklepPodstawowe.wcisniety())
            {
                shop.przesunNa(100);
                zip.reset();
            }
            if(pSklepNaSciane.wcisniety())
                {
                shop.przesunNa(200);
                zip.reset();
            }
            if(pSklepOzdoby.wcisniety())
            {
                shop.przesunNa(300);
                zip.reset();
            }
            if(pSklepJedzenie.wcisniety())
            {
                shop.przesunNa(400);
                zip.reset();
            }


        }
        else
        {
            pokoje.wyswietl();
        }

        pet.wyswietl();

        // Rysowanie
        window.draw(sp_bg);
        pWyjscie.wyswietl();
        pMinimalizuj.wyswietl();
        pSalon.wyswietl();
        pSypialnia.wyswietl();
        pKuchnia.wyswietl();
        pLazienka.wyswietl();
        pOgrod.wyswietl();
        pTartak.wyswietl();
        pSklep.wyswietl();




        pasFun.wyswietl(pet.getFun());
        pasFood.wyswietl(pet.getFood());
        pasClean.wyswietl(pet.getClean());
        pasHp.wyswietl(pet.getHp());
        pasEnergy.wyswietl(pet.getEnergy());
        pasLuck.wyswietl(pet.getLuck());



        inventory.wyswietl();


        mysz.wyswietl();


        // Opcje
        if (pWyjscie.wcisniety()) wyjscie();
        if (pSypialnia.wcisniety() && pokoje.aktywny() != sypialnia)
        {
            shop.close();
            lumber.stop();
            pokoje.ustaw(sypialnia);
            pet.setPosition(-200,pet.getPozY());
            pet.setKierunek(prawo);
            pet.movementX = 500;
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.setState(stoi);
            pet.kolejka(idz);

        }
        if (pSalon.wcisniety() && pokoje.aktywny() != salon)
        {
            shop.close();
            lumber.stop();
            pokoje.ustaw(salon);
            pet.setPosition(-200,pet.getPozY());
            pet.setKierunek(prawo);
            pet.movementX = 500;
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.setState(stoi);
            pet.kolejka(idz);
        }
        if (pKuchnia.wcisniety() && pokoje.aktywny() != kuchnia)
        {
            shop.close();
            lumber.stop();
            pokoje.ustaw(kuchnia);
            pet.setPosition(-200,pet.getPozY());
            pet.setKierunek(prawo);
            pet.movementX = 500;
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.setState(stoi);
            pet.kolejka(idz);
        }
        if (pLazienka.wcisniety() && pokoje.aktywny() != lazienka)
        {
            shop.close();
            lumber.stop();
            pokoje.ustaw(lazienka);
            pet.setPosition(-200,pet.getPozY());
            pet.setKierunek(prawo);
            pet.movementX = 500;
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.setState(stoi);
            pet.kolejka(idz);
        }
        if (pOgrod.wcisniety() && pokoje.aktywny() != ogrod)
        {
            shop.close();
            lumber.stop();
            pokoje.ustaw(ogrod);
            pet.setPosition(-200,pet.getPozY());
            pet.setKierunek(prawo);
            pet.movementX = 500;
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.kolejka(usun);
            pet.setState(stoi);
            pet.kolejka(idz);
        }
        if (pTartak.wcisniety())
        {
            shop.close();
            lumber.start();
        }
        if (pSklep.wcisniety())
        {
            lumber.stop();
            shop.open();
        }
        if (pMinimalizuj.wcisniety())
        {
            // Nic jeszcze
        }

        przesuwanie();
        sf::Vector2i tmp;
        tmp.x = pozX;
        tmp.y = pozY;
        window.setPosition(tmp);
        //if(mysz.x() <= 0 || mysz.x() >= 1100 || mysz.y() <= 0 || mysz.y() >= 600) window.draw(sp_dark);
        if(lumber.isActive()) lumber.render_eq_off();
        window.display();
    }



};
clOkno okno;

#endif // OKNO_H_INCLUDED
