#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED

int podglad = 0;

class clZip
{

private:
    sf::Texture tex_bg;
    sf::Sprite sp_bg;
    sf::Texture tex_zip;
    sf::Sprite sp_zip;
    int value;
    bool preclick;
    bool active;
    int przesuwanie;

public:
    clZip()
    {
        tex_bg.loadFromFile("media/graphic/shop/zip.png");
        tex_zip.loadFromFile("media/graphic/shop/zipper.png");
        sp_bg.setTexture(tex_bg);
        sp_zip.setTexture(tex_zip);
        sp_bg.setPosition(658,140);
        value = 3;

        preclick = false;
        active = false;
        przesuwanie = 0;
    }
    int getMove()
    {
        int tmp = value * 17 / 309;
        return tmp;
    }
    void reset()
    {
        value = 3;
    }
    void goWheel(int value2)
    {
        value -= value2 * 309/17;
        if(value < 3) value = 3;
        if(value > 309) value = 309;
    }
    void wyswietl()
    {
        myszka = sf::Mouse::getPosition( window );

        if(myszka.x >= 660 && myszka.x <= 680 && myszka.y >= 160 + value && myszka.y <= 260 + value)
        {
            if(sf::Mouse::isButtonPressed( sf::Mouse::Left ))
            {
                if(preclick == true && active == false)
                {
                    preclick = false;
                    active = true;
                    przesuwanie = myszka.y - 160 - value;
                }
            }
            else
            {
                preclick = true;
                active = false;
            }
        }
        else
        {
            if(!sf::Mouse::isButtonPressed( sf::Mouse::Left )) active = false;
            preclick = false;
        }

        if(active)
        {
            value = myszka.y - 160 - przesuwanie;
            if(value < 3) value = 3;
            if(value > 309) value = 309;
        }


        window.draw(sp_bg);
        sp_zip.setPosition(660,160 + value);
        window.draw(sp_zip);
    }


};
clZip zip;

class clShelf
{

private:
    sf::Texture tex_bg;
    sf::Sprite sp_bg;
    sf::Texture tex_lock;
    sf::Sprite sp_lock;
    int x;
    int y;
    int id;
    bool preclick;
    bool active;


    sf::Text tex_price;
    sf::Font fnt;

    sf::Sprite sp_buy;
    sf::Texture tex_buy;



public:
    clShelf()
    {
        preclick = false;
        active = false;
        fnt.loadFromFile("media/fonts/number.ttf");
        tex_price.setCharacterSize(20);
        tex_price.setColor(sf::Color::White);
        tex_price.setFont(fnt);

        tex_bg.loadFromFile("media/graphic/shop/shelf.png");
        sp_bg.setTexture(tex_bg);
        tex_lock.loadFromFile("media/graphic/shop/shelf_lock.png");
        sp_lock.setTexture(tex_lock);
        tex_buy.loadFromFile("media/graphic/shop/shelf_buy.png");
        sp_buy.setTexture(tex_buy);
        id = 0;
    }
    void wyswietl()
    {
        sp_bg.setPosition(x,y);
        sp_lock.setPosition(x,y);
        sp_buy.setPosition(x,y);
        window.draw(sp_bg);
        if(item[id].isCreated())
        {
            item[id].wyswietlInventory(x + 11,y + 8);
            string tmp = int_to_string(item[id].getPrice());
            while(tmp.size() <= 6)
            {
                tmp.insert(0," ");
            }
            tex_price.setString(tmp);
            tex_price.setPosition(x + 10,y + 110);
            window.draw(tex_price);

            // Kupowanie
            myszka = sf::Mouse::getPosition( window );

        if(myszka.x >= x && myszka.x <= x + 120 && myszka.y >= y && myszka.y <= y + 143)
        {
            if(sf::Mouse::isButtonPressed( sf::Mouse::Left ))
            {
                if(preclick == true && active == false)
                {
                        active = true;
                        preclick = false;
                }
            }
            else
            {
                preclick = true;
                active = false;
            }
        }
        else
        {
            if(!sf::Mouse::isButtonPressed( sf::Mouse::Left )) active = false;
            preclick = false;
        }

        if(preclick)
        {
            window.draw(sp_buy);
            podglad = id;
        }
        if(active)
        {
            if(inventory.getGold() >= item[id].getPrice())
            {
            bool brk = false;
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    if(inventory.umiesc(x,y,id))
                    {
                        inventory.addGold(0 - item[id].getPrice());
                        active = false;
                        brk = true;
                        Debug("[Sklep] Kupiono przedmiot");
                    }
                    if(brk) break;
                }
                if(brk) break;
            }
            }
        }

        }
        else window.draw(sp_lock);

    }
    void setPos(int posx,int posy)
    {
        x = posx;
        y = posy;
    }
    void setID(int value)
    {
        id = value;
    }

};

class clShop
{

private:
    sf::Sprite sp_bg;
    sf::Texture tex_bg;
    bool active;
    clShelf shelf[5][3];
    int przesuwanie;


public:
    clShop()
    {
        tex_bg.loadFromFile("media/graphic/shop/background.png");
        sp_bg.setTexture(tex_bg);
        sp_bg.setPosition(8,135);
        active = false;
        przesuwanie = 100;
        for(int y = 0; y < 3; y++)
        {
            for(int x = 0; x < 5; x++)
            {
                shelf[x][y].setPos(13 + x * 130, 140 + y * 153);
            }
        }
    }
    bool isActive()
    {
        return active;
    }
    void przesunNa(int value)
    {
        przesuwanie = value;
    }
    void wyswietl()
    {
        podglad = 0;
        window.draw(sp_bg);

        for(int y = 0; y < 3; y++)
        {
            for(int x = 0; x < 5; x++)
            {
                shelf[x][y].setID(5*y + x + przesuwanie + zip.getMove() * 5);
                shelf[x][y].wyswietl();
            }
        }
        zip.wyswietl();
    }
    void open()
    {
        active = true;
    }
    void close()
    {
        active = false;
    }




};
clShop shop;

#endif // SHOP_H_INCLUDED
