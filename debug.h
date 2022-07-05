#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

void Debug(string text)
{
    cout<<"[Debug] "<<text<<endl;
}

bool ppb(int x)
{
    int los = rand() % 100;
    if (los < x) return true;
    else return false;
}

string int_to_string(int value)
{
    stringstream ss;
    ss<<value;
    string wynik;
    ss>>wynik;
    return wynik;
}

char int_to_char(int value)
{
    stringstream ss;
    ss<<value;
    char wynik;
    ss>>wynik;
    return wynik;
}

string char_to_string(char value)
{
    stringstream ss;
    ss<<value;
    string wynik;
    ss>>wynik;
    return wynik;
}

int random(int nMin, int nMax)
{
    int tmp;
    tmp = (rand() % (nMax - nMin)) + nMin;
    return tmp;
}

int predefinedPetFun = 0;
bool vulpixMove = false;
sf::Ftp ftp;
bool connected;
int czasLaczenia;
string login;

void polacz()
{
        sf::Ftp::Response response = ftp.connect("ftp.monsters.aq.pl");
        if (response.isOk())
        {
            Debug("[Patcher] Polaczono");
            ftp.login("monsters.aq.pl", "Monsters!");
            Debug("[Patcher] Zalogowano");
            connected = true;
            while(true)
            {
                Sleep(10000);
                ftp.keepAlive();
            }
        }
        else
        {
            Debug("[Patcher] Nie mozna polaczyc");
            czasLaczenia -= 60000;
        }
}
sf::Thread thread(&polacz);

#endif // DEBUG_H_INCLUDED
