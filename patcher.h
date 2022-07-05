#ifndef PATCHER_H_INCLUDED
#define PATCHER_H_INCLUDED

class clForm{

private:
    sf::Sprite sp_bg;
    sf::Texture tex_bg;
    sf::Sprite sp_inactive;
    sf::Texture tex_inactive;
    bool pass;
    int x;
    int y;
    bool active;
    string tekst;

    sf::Text txt;
    sf::Font fnt;

public:
    clForm(bool value1,int px, int py,bool acti)
    {
        x = px;
        y = py;
        fnt.loadFromFile("media/fonts/number.ttf");
        txt.setFont(fnt);
        txt.setColor(sf::Color::White);
        txt.setPosition(x + 5,y + 10);
        txt.setCharacterSize(20);

        tex_bg.loadFromFile("media/graphic/patcher/form.png");
        sp_bg.setTexture(tex_bg);
        tex_inactive.loadFromFile("media/graphic/patcher/inactive.png");
        sp_inactive.setTexture(tex_inactive);
        pass = value1;

        sp_bg.setPosition(x,y);
        sp_inactive.setPosition(x,y);
        active = acti;
    }
    void append(string znak)
    {
        if(tekst.size() >= 20) return;
        tekst.append(znak);
    }
    void pop()
    {
        if(tekst.size() == 0) return;
        tekst.resize(tekst.size() - 1);
    }
    void wyswietl()
    {
        // wymiary 285x43
        window.draw(sp_bg);
        if(active == false) window.draw(sp_inactive);

        string haszLsd;
        haszLsd = tekst;
        if(pass == true)
        {
            for(int x = 0; x < haszLsd.size(); x++)
            {
                haszLsd[x] = '#';
            }
        }

        txt.setString(haszLsd);
        window.draw(txt);
    }
    void setString(string value)
    {
        tekst = value;
    }
    void setActive(bool value)
    {
        active = value;
    }
    bool isActive()
    {
        return active;
    }
    string getText()
    {
        return tekst;
    }
};
clForm fLogin(false,771,103,true);
clForm fHaslo(true,771,186,false);

class clPatcher
{

private:
    sf::Sprite sp_bg;
    sf::Texture tex_bg;
    sf::Sprite sp_main;
    sf::Texture tex_main;
    sf::Texture tex_main_error;
    bool logged;
    bool bMain;

    sf::Sprite sp_bar1;
    sf::Sprite sp_bar2;
    int bar1value;
    int bar2value;
    sf::Texture tex_bar;

public:
    clPatcher()
    {
        barSetPercentage(1,0);
        barSetPercentage(2,0);
        tex_bar.loadFromFile("media/graphic/patcher/bar.png");
        sp_bar1.setTexture(tex_bar);
        sp_bar2.setTexture(tex_bar);
        sp_bar1.setPosition(41,460);
        sp_bar2.setPosition(41,518);

        bMain = false;
        logged = false;
        connected = false;
        tex_bg.loadFromFile("media/graphic/patcher/background.png");
        tex_main.loadFromFile("media/graphic/patcher/connecting.png");
        tex_main_error.loadFromFile("media/graphic/patcher/cant_connect.png");
        sp_bg.setTexture(tex_bg);
        sp_main.setPosition(22,63);
    }
    void barWyswietl()
    {
        sp_bar1.setScale(static_cast<float>(bar1value) / 100.0,1.0);
        sp_bar2.setScale(static_cast<float>(bar2value) / 100.0,1.0);

        window.draw(sp_bar1);
        window.draw(sp_bar2);
    }
    void barSetPercentage(int index, int value)
    {
        if(index == 1)
        {
            if(value < bar1value) return;
            else bar1value = value;
        }
        if(index == 2)
        {
            if(value < bar2value) return;
            else bar2value = value;
        }
    }
    void loguj(string strLogin, string strHaslo)
    {
        if(bar1value != 100 || bar2value != 100) return;

        strHaslo = md5(strHaslo);
        string serwerPath = "User/";
        serwerPath += strLogin;
        serwerPath += "/password.ini";
        sf::Ftp::Response ftpDownload = ftp.download(serwerPath, "media/download/", sf::Ftp::Ascii);
        if(ftpDownload.isOk())
        {
            fstream plik;
            plik.open("media/download/password.ini");
            string strHasloFtp;
            plik>>strHasloFtp;
            plik.close();

            if(strHaslo == strHasloFtp)
            {
                login = fLogin.getText();
                sf::Ftp::Response ftpDownload;
                // Download plikow
                string serwerPath = "User/";
                serwerPath += strLogin;
                serwerPath += "_inventory.ini";
                ftpDownload = ftp.download(serwerPath, "media/download/", sf::Ftp::Binary);
                if(ftpDownload.isOk())
                {
                   inventory.load();
                }
                serwerPath = "User/";
                serwerPath += strLogin;
                serwerPath += "_pokoje.ini";
                ftpDownload = ftp.download(serwerPath, "media/download/", sf::Ftp::Binary);
                if(ftpDownload.isOk())
                {
                   pokoje.load();
                }
                serwerPath = "User/";
                serwerPath += strLogin;
                serwerPath += "_pet.ini";
                ftpDownload = ftp.download(serwerPath, "media/download/", sf::Ftp::Binary);
                if(ftpDownload.isOk())
                {
                   pet.load();
                }
                logged = true;

            }
            else
            {
                fHaslo.setActive(true);
                fHaslo.setString("");
            }
        }
        else
        {
            fLogin.setActive(true);
            fLogin.setString("");
            fHaslo.setString("");
        }
    }
    void wyswietl()
    {
        barSetPercentage(1,20);
        Debug("[Patcher] Start");
        Debug("[Patcher] Laczenie...");
        czasLaczenia = GetTickCount();
        sf::Thread thread(&polacz);
        thread.launch();

        while(logged == false)
        {
            if(window.isOpen() == false)
            {
                return;
            }

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    int i = event.key.code;
                    if(event.key.code == sf::Keyboard::BackSpace)
                        {
                            if(fLogin.isActive()) fLogin.pop();
                            if(fHaslo.isActive()) fHaslo.pop();
                        }
                        else if(event.key.code == sf::Keyboard::Tab)
                        {
                            if(fLogin.isActive())
                            {
                                fLogin.setActive(false);
                                fHaslo.setActive(true);
                            }
                            else if(fHaslo.isActive())
                            {
                                fLogin.setActive(true);
                                fHaslo.setActive(false);
                            }
                        }
                        else if(event.key.code == sf::Keyboard::Return)
                        {
                            if(fLogin.isActive())
                            {
                                fLogin.setActive(false);
                                fHaslo.setActive(true);
                            }
                            else if(fHaslo.isActive())
                            {
                                fLogin.setActive(false);
                                fHaslo.setActive(false);
                                loguj(fLogin.getText(),fHaslo.getText());
                            }
                        }
                        else if(event.key.code == sf::Keyboard::BackSpace)
                        {
                            if(fLogin.isActive()) fLogin.pop();
                            if(fHaslo.isActive()) fHaslo.pop();
                        }
                    else if(i < 26 && i >= 0)
                    {
                        i += 97;
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                        {
                            i -= 32;
                        }
                        if(fLogin.isActive()) fLogin.append(char_to_string(char(i)));
                        if(fHaslo.isActive()) fHaslo.append(char_to_string(char(i)));
                    }
                    else if((i == 26))
                    {
                        i = 48;
                        if(fLogin.isActive()) fLogin.append(char_to_string(char(i)));
                        if(fHaslo.isActive()) fHaslo.append(char_to_string(char(i)));
                    }
                    else if(i < 36 && i >= 0)
                    {
                        i += 22;
                        if(fLogin.isActive()) fLogin.append(char_to_string(char(i)));
                        if(fHaslo.isActive()) fHaslo.append(char_to_string(char(i)));
                    }
                    else if(i < 85 && i >= 75)
                    {
                        i -= 27;
                        if(fLogin.isActive()) fLogin.append(char_to_string(char(i)));
                        if(fHaslo.isActive()) fHaslo.append(char_to_string(char(i)));
                    }
                }

            }
            window.clear(sf::Color::Black);
            window.draw(sp_bg);


            pWyjscie.wyswietl();
            pMinimalizuj.wyswietl();

            if(pWyjscie.wcisniety())
            {
                thread.terminate();
                window.close();
                return;
            }

            if(connected == false)
            {
                if(czasLaczenia + 30000 > GetTickCount())
                {
                    sp_main.setTexture(tex_main);
                }
                else sp_main.setTexture(tex_main_error);
            }
            else
            {
                // UPDATE
                if(bar1value == 80)
                {
                    // Pobieranie archiwum i wypakowywanie
                    if(bar2value == 66)
                    {
                        Debug("[Version] Rozpakowywanie plikow");
                        system("7z x -y MonstersFiles.zip");
                        barSetPercentage(2,100);
                        barSetPercentage(1,100);
                    }
                    if(bar2value == 33)
                    {
                        Debug("[Version] Pobieranie pozostalycz plikow");
                        ftp.download("MonstersFiles.zip", "", sf::Ftp::Binary);
                        barSetPercentage(2,66);
                    }






                }
                if(bar1value == 60)
                {
                    Debug("[Version] Aktualizacja pliku exe");
                    // Aktualizacja exe
                    barSetPercentage(2,33);
                    barSetPercentage(1,80);
                }
                if(bar1value == 40)
                {
                    // Pobieranie pliku z wersja gry
                    ftp.download("version.ini", "media/download/", sf::Ftp::Binary);
                    fstream plik;
                    plik.open("media/download/version.ini");
                    string lastVersion;
                    plik>>lastVersion;
                    plik.close();
                    if(lastVersion == version)
                    {
                        barSetPercentage(1,100);
                        barSetPercentage(2,100);
                        Debug("[Version] To jest aktualna wersja gry");
                    }
                    else
                    {
                        barSetPercentage(1,60);
                        Debug("[Version] Wersja gry jest nieaktualna");
                    }
                }

                barSetPercentage(1,40);
                if(bMain == false)
                {
                    ftp.download("main.png", "media/graphic/patcher/", sf::Ftp::Binary);
                    tex_main.loadFromFile("media/graphic/patcher/main.png");
                    bMain = true;
                }
                sp_main.setTexture(tex_main);
            }
            window.draw(sp_main);
            fLogin.wyswietl();
            fHaslo.wyswietl();

            pZaloguj.wyswietl();
            pReje.wyswietl();

            if(pReje.wcisniety())
            {
                ShellExecute( NULL, "open", "http://www.monsters.aq.pl/rejestracja.php", "", "", SW_SHOWNORMAL );
            }
            if(pZaloguj.wcisniety())
            {
                loguj(fLogin.getText(),fHaslo.getText());
            }
            barWyswietl();
            mysz.wyswietlPatcher();
            window.display();
        }
        Debug("[Patcher] Rozlaczono");
        thread.terminate();
        ftp.disconnect();
    }
    bool isLogged()
    {
        return logged;
    }




};
clPatcher patcher;

#endif // PATCHER_H_INCLUDED
