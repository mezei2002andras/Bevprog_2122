#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugr� �rv�nyes, amely nem tartalmaz semmilyen v�ltoztat�st a main()-ben,
        �s m�r nincs benne kommentezve semmi
    - nem tartalmaz #undefine-t, az "ellenoriz"-en k�v�l nem tartalmaz #define sorokat, �s azt sem szabad megv�ltoztatni
    - warningokat bekapcsolva nincs "no return statement" warning
*/

// Innentol
struct Cucc
{
    string nev;
};

struct Mano
{
    string nev;
    Cucc cucc;
};

void cuccot_cserel(Mano& mano1, Mano& mano2)
{
    Mano temp;
    temp.cucc.nev = mano2.cucc.nev;
    mano2.cucc.nev = mano1.cucc.nev;
    mano1.cucc.nev = temp.cucc.nev;
}

int osszeg(vector<int>& kicsi)
{
    int szum = 0;
    for(int i = 0; i < kicsi.size(); i++)
    {
        szum += kicsi[i];
    }
    return szum;
}

string rejtveny ()
{
    ifstream be("__a.txt");
    string titok;
    if (be.is_open())
    {
        getline(be, titok);
    }
    be.close();
    titok.insert(0, "asd");
    cout << titok << endl;
    return titok;
}
// Idaig

int main()
{
    int pont = 0;
    srand(time(0));

    Cucc motyo;
    Mano mano1;
    motyo.nev = "bot";
    mano1.nev = "Beno";
    mano1.cucc = motyo;

    ellenoriz(mano1.cucc.nev == "bot",pont)

    Mano mano2;
    mano2.nev = "Moha";
    Cucc motyo2;
    motyo2.nev = "kavics";
    mano2.cucc = motyo2;

    cuccot_cserel(mano1, mano2);

    ellenoriz(mano2.cucc.nev == "bot" && mano1.cucc.nev == "kavics",pont)

    cuccot_cserel(mano1, mano2);

    ellenoriz(mano1.cucc.nev == "bot" && mano2.cucc.nev == "kavics",pont)

    vector<int> kicsivektor({1,2,3});
    ellenoriz(osszeg(kicsivektor)==6,pont)

    // ha az elozot j�l csin�ltad meg, akkor ez automatikusan m�g egy pont lesz
    vector<int> v;
    int vegosszeg = rand()%1000+1000;
    int maradek = vegosszeg;
    for (int i=0;i<rand()%5+5;i++) {
        int szam = rand()%100;
        v.push_back(szam);
        maradek-=szam;
    }
    v.push_back(maradek);
    int szamolt_osszeg = osszeg(v);
    ellenoriz(szamolt_osszeg == vegosszeg, pont)

    ofstream ki("__a.txt");
    string titok;
    for (int i=0;i<10;i++) {
        titok+=('a'+rand()%26);
    }
    ki << titok << endl;
    ki.close();
    string megfejtes = rejtveny();
    cout << "titok: " << titok << " megfejtes: " << megfejtes << endl;
    ellenoriz(megfejtes.substr(3,10) == titok,pont);


    cout << endl << pont << "/6 pont";
}
