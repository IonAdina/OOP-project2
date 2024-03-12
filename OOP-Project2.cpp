//proiect 2,tema 14
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <iomanip>
#include <algorithm>
#include <cctype>
using namespace std;

//***************************************Class Proces********************************************************
class Proces
{
protected:
    int NrProces;
    string reclamat,reclamant;
public:
    virtual void citire()
    {
        cout<<"dati nr proces(int):";
        cin>>NrProces;
        //cout<<"dati reclamatul(string):";
        //cin>>reclamat;
        //cout<<"dati reclamantul(string):";
        //cin>>reclamant;
    }
    virtual void afisare()
    {
        cout << NrProces << endl  << reclamat << endl << reclamant;
    }
    int get_NrProces()
    {
        return NrProces;
    }
    Proces() //constructor de initializare
    {
        NrProces=0;
        reclamat=' ' ;
        reclamant=' ';
    }
    Proces(int NrProces,string reclamat,string reclamant) //constructor parametrizat
    {
        this->NrProces = NrProces;
        this->reclamat = reclamat;
        this->reclamant = reclamant;
    }
    Proces(const Proces& ob)  //constructor de copiere
    {
        this->NrProces = ob.NrProces;
        this->reclamat = ob.reclamat;
        this->reclamant = ob.reclamant;
    }
    ~Proces() //destructor
    {
        if(NrProces!=0)
            NrProces=0;
        reclamant = ' ';
        reclamat = ' ';
    }
    Proces &operator=(const Proces& ob) //supraincarcarea operatorului de atribuire
    {
        if(this != &ob)
        {
            this->NrProces = ob.NrProces;
            this->reclamat = ob.reclamat;
            this->reclamant = ob.reclamant;
        }
        return *this;
    }
    friend istream &operator>>(istream &, Proces &);
    friend ostream &operator<<(ostream &, Proces &);
    double Calculare_Taxa_Timbru()
    {
        cout<<"Acesta este un proces normal si nu am taxa de timbru";
    }
};

istream &operator>>(istream &in, Proces &p) //supraincarcarea operatorului >>
{
    cout<<"Introdu NrProces:"<<endl;
    cout << "aici: ";
    in >> p.NrProces;
    cout << "reclamat: ";
    in >> p.reclamat;
    cout << "reclamant: ";
    in >> p.reclamant;
    return in;
}
ostream &operator<<(ostream &out,Proces &ob) //supraincarcarea operatorului <<
{
    out<<ob.NrProces<<" "<<ob.reclamant<<" "<<ob.reclamat<<endl;
    return out;
}

//****************************************Class Proces_civil******************************************************

class Proces_civil: public Proces
{
protected:
    double dauneMorale,dauneMateriale;
    int nrMartori;
    bool stadiu;
    static double Procent_Taxa_Timbru;
public:
    friend class Meniu;
    static double getProcent_Taxa_Timbru();
    static void setProcent_Taxa_Timbru(double Taxa_Timbru);
    void citire1()
    {
        Proces :: citire();
        string temp;
        double tempp;
        cout<<"dati nr de dauneMorale(int):";
        cin>>dauneMorale;
        cout<<"dati nr de dauneMateriale(int):";
        cin>>dauneMateriale;
        cout<<"dati nrMartori(int):";
        cin>>nrMartori;
        cout<<"dati stadiu(int/float/double/string):";
        cin>> temp;
        try
        {
            if(typeid(tempp) == typeid(string))
            {
                throw tempp;
            }
            if(tempp>0 )
                stadiu = 1;
            else
                stadiu = 0;
        }
        catch(string tempp)
        {
            cout<<"INVALID!!!";
        }
        if(typeid(temp) == typeid(string))
        {
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            std::istringstream is(temp);
            bool b;
            is >> std::boolalpha >> b;
        }
    }
    double f1 ()        //folosite pentru a apela in main
    {
        return dauneMorale;
    }
    double f2()
    {
        return dauneMateriale;
    }
    void afisare1()
    {
        Proces::afisare();
        cout<<endl;
        cout << dauneMorale<<endl<<dauneMateriale<<endl<<nrMartori<<endl<<stadiu<<endl;
    }
    Proces_civil() //constructor de initializare
    {
        dauneMorale=0;
        dauneMateriale=0;
        nrMartori=0;
        stadiu=0;
    }
    Proces_civil(double dauneMateriale,double dauneMorale, int nrMartori,bool stadiu = false) //constructor parametrizat
    {
        this->dauneMateriale = dauneMateriale;
        this->dauneMorale = dauneMorale;
        this->nrMartori = nrMartori;
        this->stadiu = stadiu;
    }
    Proces_civil(const Proces_civil& ob)  //constructor de copiere
    {
        this->dauneMateriale = ob.dauneMateriale;
        this->dauneMorale = ob.dauneMorale;
        this->nrMartori = ob.nrMartori;
        this->stadiu = ob.stadiu;
    }
    ~Proces_civil() //destructor
    {
        dauneMateriale=0;
        dauneMorale=0;
        nrMartori=0;
        stadiu=0;
    }
    Proces_civil &operator=(const Proces_civil& ob) //supraincarcarea operatorului de atribuire
    {
        if(this != &ob)
        {
            this->dauneMateriale = ob.dauneMateriale;
            this->dauneMorale = ob.dauneMorale;
            this->nrMartori = ob.nrMartori;
            this->stadiu = ob.stadiu;
        }
        return *this;
    }
    friend istream &operator>>(istream &, Proces_civil &);
    friend ostream &operator<<(ostream &, Proces_civil &);

    int getNrMartori() const
    {
        return nrMartori;
    }
    void setNrMartori(int nrMartori)
    {
        Proces_civil::nrMartori=nrMartori;
    }
    bool getStadiu() const
    {
        return stadiu;
    }
    void setStadiu(bool stadiu)
    {
        Proces_civil::stadiu=stadiu;
    }

    void stadiuNrMartori()    //folosita pt modificarea stadiului
    {
        try
        {
            if(nrMartori > 5)
                throw 1;
            else
                throw 0;
        }
        catch(int stadiu)
        {
            cout<<stadiu;
            cout<<endl;
        }
    }
    int get_dauneMorale()
    {
        return dauneMorale;    //geteri pt ca variabilele sunt MEREU private
    }
    int get_dauneMateriale()
    {
        return dauneMateriale;
    }
    int get_NrMartori()
    {
        return nrMartori;
    }
    bool get_stadiu()
    {
        return stadiu;
    }
    double Calculare_Taxa_Timbru()
    {
        double formula;
        //cout<<Procent_Taxa_Timbru<<" "<<dauneMorale<<" "<<dauneMateriale<<" ";
        formula =( Procent_Taxa_Timbru * dauneMorale)+(Procent_Taxa_Timbru * dauneMateriale);
        //cout<<"taxa/e de timbru specifice procesului/lor: "<<formula<<" ";
        cout<<formula<<" ";
        return formula;
    }
};

double Proces_civil::Procent_Taxa_Timbru=0.10;  //procesul prin care am facut variabila statica pt taxa de timbru
double Proces_civil::getProcent_Taxa_Timbru()
{
    return Procent_Taxa_Timbru;
}
void Proces_civil::setProcent_Taxa_Timbru(double Taxa_Timbru)
{
    Procent_Taxa_Timbru=Taxa_Timbru;
}

std::ostream& operator<<(std::ostream&, const Proces_civil& a);
std::istream& operator>>(std::istream&, const Proces_civil& a);

istream &operator>>(istream &in,Proces_civil &p) //supraincarcarea operatorului >>
{
    int temp;
    cout<<"Introdu dauneMorale:"<<endl;
    cout << "aici: ";
    in >> p.dauneMorale;
    cout << "dauneMateriale: ";
    in >> p.dauneMateriale;
    cout << "nrMartori: ";
    in >> p.nrMartori;
    cout << "stadiu:";
    in >> temp;
    p.stadiu = temp;
    return in;
}
ostream &operator<<(ostream &out,Proces_civil &ob) //supraincarcarea operatorului <<
{
    out<<ob.dauneMateriale<<" "<<ob.dauneMorale<<" "<<ob.nrMartori<<ob.stadiu<<endl;
    return out;
}

//****************************************Class Proces_penal******************************************************

class Proces_penal: public Proces
{
protected:
    int dovezi;
    bool stadiu;
public:
    void citire2()
    {
        Proces :: citire();
        string temp;
        double tempp;
        cout<<"dati nr dovezi(int):";
        cin >> dovezi;
        cout<<"dati stadiul(int/float/double/string):";
        cin>> temp;
        try
        {
            if(typeid(tempp) == typeid(string))
            {
                throw tempp;
            }
            if(tempp>0 )
                stadiu = 1;
            else
                stadiu = 0;
        }
        catch(string tempp)
        {
            cout<<"INVALID!!!";
        }
        if(typeid(temp) == typeid(string))
        {
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            std::istringstream is(temp);
            bool b;
            is >> std::boolalpha >> b;
        }
    }
    void afisare2()
    {
        Proces::afisare();
        cout << dovezi<<endl<<stadiu<<endl;
    }
    Proces_penal() //constructor de initializare
    {
        dovezi=0;
        stadiu=0;
    }
    Proces_penal(int dovezi,bool stadiu = false) //constructor parametrizat
    {
        this->dovezi = dovezi;
        this->stadiu = stadiu;
    }
    Proces_penal(const Proces_penal& ob)  //constructor de copiere
    {
        this->dovezi = ob.dovezi;
        this->stadiu = ob.stadiu;
    }
    ~Proces_penal() //destructor
    {
        dovezi=0;
        stadiu=0;
    }
    Proces_penal &operator=(const Proces_penal& ob) //supraincarcarea operatorului de atribuire
    {
        if(this != &ob)
        {
            this->dovezi = ob.dovezi;
            this->stadiu = ob.stadiu;
        }
        return *this;
    }
    friend istream &operator>>(istream &, Proces_penal &);
    friend ostream &operator<<(ostream &, Proces_penal &);

    int getNrDovezi() const
    {
        return dovezi;
    }
    void setNrDovezi(int dovezi)
    {
        Proces_penal::dovezi=dovezi;
    }
    bool getStadiu() const
    {
        return stadiu;
    }
    void setStadiu(bool stadiu)
    {
        Proces_penal::stadiu=stadiu;
    }

    void stadiuNrDovezi()   //folosita pt modificarea stadiului
    {
        try
        {
            if(dovezi > 25)
                throw 1;
            else
                throw 0;
        }
        catch(int stadiu)
        {
            cout<<stadiu;
            cout<<endl;
        }
    }
    int get_dovezi()
    {
        return dovezi;
    }
    int get_stadiu()
    {
        return stadiu;
    }
    double Calculare_Taxa_Timbru()
    {
        cout<<"Acesta este un proces penal si nu am taxa de timbru";
    }
};

istream &operator>>(istream &in, Proces_penal &p) //supraincarcarea operatorului >>
{
    int temp;
    cout<<"Introdu dovezi:"<<endl;
    cout << "aici: ";
    in >> p.dovezi;
    cout << "stadiu:";
    in>> temp;
    p.stadiu = (bool) temp;
    return in;
}
ostream &operator<<(ostream &out,Proces_penal &ob) //supraincarcarea operatorului <<
{
    out<<ob.dovezi<<" "<<ob.stadiu<<endl;
    return out;
}

//************************************Class Meniu************************************************************

class Meniu:public Proces_civil
{
    vector <Proces*>vp;   //vector de procese
    int a[3];
public:
    int operator[](int i)
    {
        return a[i];
    }
    int operator>(int x)
    {
        int y;
        return x > y;
    }
    void adauga_proces(string s)
    {
        if(s=="Civil")                  //upcasting
        {
            vp.push_back(new Proces_civil);
            static_cast<Proces_civil *>(vp.back())->citire1();
        }
        else
        {
            vp.push_back(new Proces_penal);
            static_cast<Proces_penal *>(vp.back())->citire2();
        }
    }
    double proces_taxa_timbru_cea_mai_mare()
    {
        double max_taxa=0.0,dauneMateriale,dauneMorale;
        int maxi=0;
        for(int i=0; i<vp.size(); i++)
            if((dynamic_cast<Proces_civil *>(vp[i])->Calculare_Taxa_Timbru()) > max_taxa)
            {
                maxi=vp[i]->get_NrProces();
                max_taxa=(dynamic_cast<Proces_civil *>(vp[i])->Calculare_Taxa_Timbru());
            }
        cout << endl;
        cout << "Numar Proces: " << maxi << '\n';
        cout << "Taxa cea mai mare este cea specifica procesului " <<maxi<<" si este "<< max_taxa << '\n';
    }

    void afis_meniu()
    {
        cout<<"1.Adauga un nou proces citind de la tastatura tipul procesului si apoi campurile specifice lui\n";
        cout<<"2.Afiseaza procesul care are taxa de timbru cea mai mare.(pt procesele civile)\n";
        cout<<"3.Modifica stadiul unui proces civil.\n";
        cout<<"4.Modifica stadiul unui proces penal.\n";
        cout<<"5.Afiseaza taxa de timbru.(pt procesele civile)\n";
        cout<<"Optiunea aleasa va actiona asupra ultimului proces dat(procesul dat imediat anterior).\n";
        cout<<"De exemplu, daca ultimul proces adaugat este unul penal, nu pot alege optiunea 5,deoarece un proces penal nu are taxa de timbru.";
        cout<<"Daca se vrea o optiune de calculare/modificare, sa fie mereu adaugat inainte un proces (optiunea 1).\n";
        cout<<"Nu pot calcula /modifica ceva,daca inainte am un calcul/modificare.Trebuie clar un proces dat inainte,pe care pot calcula/modifica\n";
        cout<<"Daca se vrea optiunea 2 ,recomand iesirea din program inainte ,apoi adaugarea proceselor civile.";
        cout<<endl;
        int x;
        cout<<"Optiunea?  ";
        cin>>x;
        while (x>=1 && x<=5)
        {
            switch(x)
            {
            case 1:
            {
                string s;
                cout<<"Ce tip de proces doriti sa cititi (Civil sau Penal): ";
                cin>>s;
                adauga_proces(s);
                break;
            }
            case 2:
            {
                proces_taxa_timbru_cea_mai_mare();
                break;
            }
            case 3:
            {
                cout<<"\nStadiul procesului civil modificat este: \n";
                dynamic_cast<Proces_civil *>(vp.back())->stadiuNrMartori();
                break;
            }
            case 4:
            {
                cout<<"\nStadiul procesului penal modificat este: \n";
                dynamic_cast<Proces_penal *>(vp.back())->stadiuNrDovezi();
                break;
            }
            case 5:
            {
                cout<<"Taxa de timbru este: ";
                static_cast<Proces_civil *>(vp.back())->Calculare_Taxa_Timbru();
                break;
            }
            }
            cout<<endl;
            cout<<"1.Adauga un nou proces citind de la tastatura tipul procesului si apoi campurile specifice lui\n";
            cout<<"2.Afiseaza procesul care are taxa de timbru cea mai mare.(pt procesele civile)\n";
            cout<<"3.Modifica stadiul unui proces civil.\n";
            cout<<"4.Modifica stadiul unui proces penal.\n";
            cout<<"5.Afiseaza taxa  de timbru.(pt procesele civile)\n";
            cout<<"Alta optiune?  ";
            cin>>x;
        }

    }
};


int main()
{
    //cateva testari pe care le am facut de a lungul proiectului pentru fiecare functie
    //ca sa verific funtionalitatea

    //Proces_civil p;
    //int nrMartori;
    //p.citire();
    //p.afisare();
    //p.stadiuNrMartori(nrMartori);
    //Proces_penal x;
    //int NrDovezi;
    //x.citire();
    //x.afisare();
    //x.stadiuNrDovezi(NrDovezi);
    //Proces_civil::setProcent(0.25);
    //Proces_civil t;
    //double dauneMorale=0,dauneMateriale=0;
    //t.citire();
    //t.afisare();
    //t.Calculare_Taxa_Timbru(t.f1(),t.f2());
    //Meniu m;
    //string s;
    //cin>>s;
    //m.adauga_proces(s);
    //cin>>s;
    //m.adauga_proces(s);
    //m.proces_taxa_timbru_cea_mai_mare();

    Meniu m;
    m.afis_meniu();
    return 0;
}
