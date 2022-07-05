#ifndef PRZYCISKI_H_INCLUDED
#define PRZYCISKI_H_INCLUDED
class przycisk
{

private:
    sf::Texture tex_v1;
    sf::Texture tex_v2;
    sf::Texture tex_v3;

    sf::Sprite sp_przycisk;
    int pozX;
    int pozY;
    int szer;
    int wys;
    bool preclick;
    bool enabled;

public:
    przycisk(int x, int y,int s,int w, string v1, string v2, string v3)
    {
        tex_v1.loadFromFile(v1);
        tex_v2.loadFromFile(v2);
        tex_v3.loadFromFile(v3);
        sp_przycisk.setTexture(tex_v1);
        preclick = false;
        enabled = false;
        pozX = x;
        pozY = y;
        szer = s;
        wys = w;
    }
    void wyswietl()
    {
        if(mysz.x() >= pozX && mysz.x() <= pozX + szer && mysz.y() >= pozY && mysz.y() <= pozY + wys)
        {
            if(mysz.LPM())
            {
                if (preclick == true)
                {
                    enabled = true;
                    preclick = false;
                    sp_przycisk.setTexture(tex_v3);
                }
            }
            else
            {
                sp_przycisk.setTexture(tex_v2);
                preclick = true;
            }
        }
        else
        {
            sp_przycisk.setTexture(tex_v1);
            preclick = false;
        }
        sp_przycisk.setPosition(pozX,pozY);
        window.draw(sp_przycisk);
    }
    bool wcisniety()
    {
        if (enabled == true)
        {
            enabled = false;
            return true;
        }
        else return false;
    }


};

przycisk pWyjscie(1062,3,30,30,"media/graphic/buttons/exit_v1.png","media/graphic/buttons/exit_v2.png","media/graphic/buttons/exit_v3.png");
przycisk pMinimalizuj(1031,3,30,30,"media/graphic/buttons/minimize_v1.png","media/graphic/buttons/minimize_v2.png","media/graphic/buttons/minimize_v3.png");
przycisk pSalon(55,88,32,32,"media/graphic/buttons/salon_v1.png","media/graphic/buttons/salon_v2.png","media/graphic/buttons/salon_v3.png");
przycisk pSypialnia(55,45,32,32,"media/graphic/buttons/sypialnia_v1.png","media/graphic/buttons/sypialnia_v2.png","media/graphic/buttons/sypialnia_v3.png");
przycisk pKuchnia(101,88,32,32,"media/graphic/buttons/kuchnia_v1.png","media/graphic/buttons/kuchnia_v2.png","media/graphic/buttons/kuchnia_v3.png");
przycisk pLazienka(101,45,32,32,"media/graphic/buttons/lazienka_v1.png","media/graphic/buttons/lazienka_v2.png","media/graphic/buttons/lazienka_v3.png");
przycisk pOgrod(144,81,69,44,"media/graphic/buttons/plot_v1.png","media/graphic/buttons/plot_v2.png","media/graphic/buttons/plot_v3.png");
przycisk pTartak(144,14,82,70,"media/graphic/buttons/tartak_v1.png","media/graphic/buttons/tartak_v2.png","media/graphic/buttons/tartak_v3.png");
przycisk pSklep(295,102,11,23,"media/graphic/buttons/sklep_v1.png","media/graphic/buttons/sklep_v2.png","media/graphic/buttons/sklep_v3.png");
przycisk pSklepPodstawowe(683,140,80,80,"media/graphic/buttons/podstawowe_v1.png","media/graphic/buttons/podstawowe_v2.png","media/graphic/buttons/podstawowe_v3.png");
przycisk pSklepNaSciane(683,230,80,80,"media/graphic/buttons/naSciane_v1.png","media/graphic/buttons/naSciane_v2.png","media/graphic/buttons/naSciane_v3.png");
przycisk pSklepOzdoby(683,320,80,80,"media/graphic/buttons/ozdoby_v1.png","media/graphic/buttons/ozdoby_v2.png","media/graphic/buttons/ozdoby_v3.png");
przycisk pSklepJedzenie(683,410,80,80,"media/graphic/buttons/jedzenie_v1.png","media/graphic/buttons/jedzenie_v2.png","media/graphic/buttons/jedzenie_v3.png");

przycisk pZaloguj(771,250,285,43,"media/graphic/buttons/zaloguj_v1.png","media/graphic/buttons/zaloguj_v2.png","media/graphic/buttons/zaloguj_v3.png");
przycisk pReje(771,300,285,43,"media/graphic/buttons/reje_v1.png","media/graphic/buttons/reje_v2.png","media/graphic/buttons/reje_v3.png");

class pasek
{

private:
    sf::Texture tex_pasek;
    sf::Sprite sp_pasek;
    int pozX;
    int pozY;

public:
    pasek(string v1,int x ,int y)
    {
        pozX = x;
        pozY = y;
        sp_pasek.setPosition(pozX,pozY);
        tex_pasek.loadFromFile(v1);
        sp_pasek.setTexture(tex_pasek);
    }
    void wyswietl(int value)
    {
        sp_pasek.setScale(static_cast<float>(value) / 100,1);
        window.draw(sp_pasek);
    }

};

pasek pasFun("media/graphic/bar/green.png",545,66);
pasek pasFood("media/graphic/bar/green.png",378,33);
pasek pasClean("media/graphic/bar/green.png",545,33);
pasek pasHp("media/graphic/bar/green.png",378,100);
pasek pasEnergy("media/graphic/bar/green.png",378,66);
pasek pasLuck("media/graphic/bar/green.png",545,100);


#endif // PRZYCISKI_H_INCLUDED
