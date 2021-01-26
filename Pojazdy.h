#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string_view>
using namespace std;

class Pojazd
{
public:
    virtual void print() = 0;
    virtual string get_rej() = 0;
    virtual string get_typ() = 0;
    virtual string get_marka() = 0;
    virtual string get_model() = 0;
    virtual double get_poj() = 0;
    Pojazd() : rejestracja{ "Wrak" } {}
    Pojazd(string r):rejestracja{r}{}
    virtual ~Pojazd() = default;
    string rejestracja;

};

class Osobowy : public Pojazd
{
public:
    void print() override
    {
        cout << "Samochod osobowy " << marka << " " << model << " o numerze rejestracyjnym " << this->rejestracja <<
            " posiada silnik o pojemosci " << poj << '\n';    }
    string get_rej() override { return this->rejestracja; }
    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    double get_poj() override { return poj; }
    Osobowy(string rej_, string marka_, string model_, double poj_) : Pojazd{ rej_ }, marka{ marka_ },
        model{ model_ }, poj{poj_}{}

private:
    string typ = "Osobowy";
    string  marka,model;
    double poj;
};
class Motocykl : public Pojazd
{
public:
    void print() override
    {
        cout << "Motocykl " << marka << " " << model << " o numerze rejestracyjnym " << this->rejestracja <<
            " posiada silnik o pojemosci " << poj<<'\n';
    }
    string get_rej() override { return this->rejestracja; }
    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    double get_poj() override { return poj; }
    Motocykl(string rej_, string marka_, string model_, double poj_) : Pojazd{ rej_ }, marka{ marka_ },
        model{ model_ }, poj{ poj_ }{}

private:
    string typ = "Motocykl";
    string  marka, model;
    double poj;
};
class Ciezarowka : public Pojazd
{
public:
    void print() override
    {
        cout << "Samochod ciezarowy " << marka << " " << model << " o numerze rejestracyjnym " << this->rejestracja <<
            " posiada silnik o pojemosci " << poj << '\n';
    }
    string get_rej() override { return this->rejestracja; }
    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    double get_poj() override { return poj; }
    Ciezarowka(string rej_, string marka_, string model_, double poj_) : Pojazd{ rej_ }, marka{ marka_ },
        model{ model_ }, poj{ poj_ }{}

private:
    string typ = "Ciezarowka";
    string  marka, model;
    double poj;
};