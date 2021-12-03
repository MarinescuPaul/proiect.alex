#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class zboruri{
public:
    char*plecare;
    char*sosire;
    char*data_si_ora_plecare; //format yyyy.mm.dd_hh:mm
    char*data_si_ora_sosire;  //format yyyy.mm.dd_hh:mm
    zboruri(char*p,char*s,char*dp,char*ds){
        this->plecare = new char [strlen(p)+1];
        strcpy(this->plecare,p);
        this->sosire = new char [strlen(s)+1];
        strcpy(this->sosire,s);
        this->data_si_ora_plecare = new char [strlen(dp)+1];
        strcpy(this->data_si_ora_plecare,dp);
        this->data_si_ora_sosire = new char [strlen(ds)+1];
        strcpy(this->data_si_ora_sosire,ds);
    }
    void set_plecare(char*c){
        delete [] this->plecare;
        this->plecare = new char [strlen(c)+1];
        strcpy(this->plecare,c);
    }
    void set_sosire(char*c){
        delete [] this->sosire;
        this->sosire = new char [strlen(c)+1];
        strcpy(this->sosire,c);
    }
    void set_data_si_ora_plecare(char*c){
        delete [] this->data_si_ora_plecare;
        this->data_si_ora_plecare = new char [strlen(c)+1];
        strcpy(this->data_si_ora_plecare,c);
    }
    void set_data_si_ora_sosire(char*c){
        delete [] this->data_si_ora_sosire;
        this->data_si_ora_sosire = new char [strlen(c)+1];
        strcpy(this->data_si_ora_sosire,c);
    }
    string get_sosire(){
        string p = this->plecare;
        return p;
    }
    string get_plecare(){
        string s = this->sosire;
        return s;
    }
    string get_data_si_ora_plecare(){
        string dp = this->data_si_ora_plecare;
        return dp;
    }
    string get_data_si_ora_sosire(){
        string ds = this->data_si_ora_sosire;
        return ds;
    }
    zboruri(){}
    ~zboruri(){
        delete [] this->data_si_ora_plecare;
        delete [] this->data_si_ora_sosire;
        delete [] this->plecare;
        delete [] this->sosire;
    }
    bool operator==(const zboruri&zb){
        if(strcpy(plecare,zb.plecare)==0&&strcpy(sosire,zb.sosire)==0&&strcpy(data_si_ora_plecare,zb.data_si_ora_plecare)==0&&strcpy(data_si_ora_sosire,zb.data_si_ora_sosire)==0)
            return true;
        else
            return false;
    }
};

class Operator{
public:
    char*nume;
    char*user_operator;
    char*parola_operator;
    zboruri*zbor;
    int number_of_zboruri;
    static int number_of_operators;
    Operator(){
        this->number_of_zboruri = 0;
    }
    Operator(char*nu,char*us,char*pass){
        this->nume = new char [strlen(nu)+1];
        strcpy(this->nume,nu);
        this->user_operator = new char [strlen(us)+1];
        strcpy(this->user_operator,us);
        this->parola_operator = new char [strlen(pass)+1];
        strcpy(this->parola_operator,pass);
    }
    ~Operator(){
        delete [] this->nume;
        delete [] this->parola_operator;
        delete [] this->user_operator;
        delete [] this->zbor;
    }
    void set_nume(char*c){
        this->nume = new char [strlen(c)+1];
        strcpy(this->nume,c);
    }
    void set_user_operator(char*c){
        this->user_operator = new char [strlen(c)+1];
        strcpy(this->user_operator,c);
    }
    void set_parola_operator(char*c){
        this->parola_operator = new char [strlen(c)+1];
        strcpy(this->parola_operator,c);
    }
     string get_nume(){
        string s = this->nume;
        return s;
    }
     string get_user_operator(){
        string s = this->user_operator;
        return s;
    }
     string get_parola_operator(){
        string s = this->parola_operator;
        return s;
    }
    bool operator==(const Operator&op){
        return(nume==op.nume&&parola_operator==op.parola_operator&&user_operator==op.user_operator);
    }
    bool verify_user(char*user,char*password){
        if(strcmp(this->user_operator,user)==0&&strcmp(this->parola_operator,password)==0)
            return true;
        else
            return false;
    }
    Operator& operator=(Operator&op){
        delete [] nume;
        nume = new char [strlen(op.nume)+1];
        strcpy(nume,op.nume);
        delete [] user_operator;
        user_operator = new char [strlen(op.user_operator)+1];
        strcpy(user_operator,op.user_operator);
        delete [] parola_operator;
        parola_operator = new char [strlen(op.parola_operator)+1];
        strcpy(parola_operator,op.parola_operator);
    }

};

int Operator::number_of_operators = 3;

class Utilizator{
public:
    char*user_utilizator;
    char*parola_utilizator;
    int number_of_zboruri;
    zboruri*zbor;
    Utilizator(char*uu,char*pu){
        this->number_of_zboruri = 0;
        this->user_utilizator = new char[strlen(uu)+1];
        strcpy(this->user_utilizator,uu);
        this->parola_utilizator = new char[strlen(pu)+1];
        strcpy(this->parola_utilizator,pu);
    }
    ~Utilizator(){
        delete [] this->parola_utilizator;
        delete [] this->user_utilizator;
        delete [] this->zbor;
    }

};

void adaugare_zboruri(char*c_nu){
    char*p;char*s;char*dp;char*ds;
    string sp,ss,sdp,sds;
    cout<<"introduceti detaliile de zbor:"<<endl;
    cout<<"introduceti aeroportul de plecare:"<<endl;
    cin>>sp;
    cout<<"Introduceti aeroportul de venire:"<<endl;
    cin>>ss;
    cout<<"Introduceti datya de plecare:"<<endl;
    cin>>sdp;
    cout<<"Introduceti data de venire:"<<endl;
    cin>>sds;
    p = new char[sp.size()+1];
    s = new char[ss.size()+1];
    dp = new char[sdp.size()+1];
    ds = new char[sds.size()+1];
    strcpy(p,sp.c_str());
    strcpy(s,ss.c_str());
    strcpy(dp,sdp.c_str());
    strcpy(ds,sds.c_str());
    zboruri zb(p,s,dp,ds);
    ofstream izb(c_nu);
    izb<<sp<<endl<<ss<<endl<<sdp<<endl<<sds<<endl;
}

void read_operator_from_file(char*c_nu,Operator*op,int n){
    ifstream izb;
    izb.open(c_nu);
    izb.seekg( n*sizeof(zboruri), ios::cur );
    char*nu;char*us;char*pass;
    string snu,sus,spass;
    if(izb>>snu&&izb>>sus&&izb>>spass){
    nu = new char[snu.size()+1];
    us = new char[sus.size()+1];
    pass = new char[spass.size()+1];
    strcpy(nu,snu.c_str());
    strcpy(us,sus.c_str());
    strcpy(pass,spass.c_str());
    Operator op(nu,us,pass);
    op.set_nume(nu);
    op.set_user_operator(us);
    op.set_parola_operator(pass);
    }
}

int read_zbor_from_file(char*c_nu,zboruri*zb,int n){
    ifstream izb;
    izb.open(c_nu);
    izb.seekg( n*sizeof(zboruri), ios::cur );
    char*p;char*s;char*dp;char*ds;
    string sp,ss,sdp,sds;
    if(izb>>sp&&izb>>ss&&izb>>sdp&&izb>>sds){
    p = new char[sp.size()+1];
    s = new char[ss.size()+1];
    dp = new char[sdp.size()+1];
    ds = new char[sds.size()+1];
    strcpy(p,sp.c_str());
    strcpy(s,ss.c_str());
    strcpy(dp,sdp.c_str());
    strcpy(ds,sds.c_str());
    zboruri zb(p,s,dp,ds);
    zb.set_plecare(p);
    zb.set_sosire(s);
    zb.set_data_si_ora_plecare(dp);
    zb.set_data_si_ora_sosire(ds);
    return 1;
    }
    return 0;
}

void write_zbor_in_file(char*c_nu,zboruri*zb){
    ofstream ozb(c_nu);
    string sp,ss,sdp,sds;
    sp=zb->get_plecare();
    ss=zb->get_sosire();
    sdp=zb->get_data_si_ora_plecare();
    sds=zb->get_data_si_ora_sosire();
    ozb<<sp<<endl<<ss<<endl<<sdp<<endl<<sds<<endl;
}

int stergere_zboruri(char*c_nu,zboruri*zb){
    FILE *newfp = fopen("file.txt", "a");
    zboruri*aux;
    int done = 0;
    int n=0;
    if (newfp != NULL)
    {
        FILE *oldfp = fopen(c_nu, "r");
        if(oldfp != NULL)
        {
            while(read_zbor_from_file(c_nu,aux,n)==1){
                n++;
                if(!(aux==zb)) write_zbor_in_file("file.txt",zb);
            }
            fclose(oldfp);
            done = 1;
        }

        fclose(newfp);
        remove(c_nu);
        rename("file.txt", c_nu);
        return done;
}
}

//ifstream ino("operator.txt");

int main()
{
    char type_of_user;
    Operator oper[10];
    while(true){
        cout<<"if you are an operator press o, if you are a user press u"<<endl;
        cin>>type_of_user;
        switch(type_of_user){
            case 'o':{
                string nu;
                string us;
                string pass;
                char*c_nu;
                char*c_us;
                char*c_pass;
                cout<<"name:"<<endl;
                cin>>nu;
                cout<<"user:"<<endl;
                cin>>us;
                cout<<"password:"<<endl;
                cin>>pass;
                c_nu = new char[nu.size()+1];
                c_us = new char[us.size()+1];
                c_pass = new char[pass.size()+1];
                strcpy(c_nu,nu.c_str());
                strcpy(c_us,us.c_str());
                strcpy(c_pass,pass.c_str());
                for(int i=0;i<3;i++){
                    Operator*op;
                    read_operator_from_file("operator.txt",op,i);
                    oper[i]=op;
                   // cout<<"motan";
                    if(oper[i].verify_user(c_us,c_pass)==false){
                        cout<<"Either the user or the password do not exist. Please try again."<<endl;
                        i--;
                    }

                    else{
                        char sterge_adauga;
pas2:                   cout<<"Pentru a sterge un zbor apasati tasta s, pentru a adauga un zbor apasati tasta a:"<<endl;
                        cin>>sterge_adauga;
                        switch(sterge_adauga){
                            case 's':{
                                char*p;char*s;char*dp;char*ds;
                                string sp,ss,sdp,sds;
                                cout<<"introduceti detaliile zborului pe care doriti sa-l stergeti:"<<endl;
                                cout<<"introduceti aeroportul de plecare:"<<endl;
                                cin>>sp;
                                cout<<"Introduceti aeroportul de venire:"<<endl;
                                cin>>ss;
                                cout<<"Introduceti data de plecare:"<<endl;
                                cin>>sdp;
                                cout<<"Introduceti data de venire:"<<endl;
                                cin>>sds;
                                p = new char[sp.size()+1];
                                s = new char[ss.size()+1];
                                dp = new char[sdp.size()+1];
                                ds = new char[sds.size()+1];
                                strcpy(p,sp.c_str());
                                strcpy(s,ss.c_str());
                                strcpy(dp,sdp.c_str());
                                strcpy(ds,sds.c_str());
                                zboruri*zb;
                                zb->set_plecare(p);
                                zb->set_sosire(s);
                                zb->set_data_si_ora_plecare(dp);
                                zb->set_data_si_ora_sosire(ds);
                                stergere_zboruri(c_nu,zb);
                                break;
                            }
                            case 'a':{
                                adaugare_zboruri(c_nu);
                                break;
                            }
                            default:
                                cout<<"Tasta introdusa gresit. Mai incercati o data.";
                                goto pas2;
                                break;
                        }
                        break;
                    }
                }
                break;
            }
            case 'u':{
                char action;
pas1:           cout<<"if you already have an account press a, else press c"<<endl;
                cin>>action;
                switch(action){
                    case 'a':{
                        break;
                    }
                    case 'c':{
                        break;
                    }
                    default:
                        cout<<"unknown command. please try again"<<endl;
                        goto pas1;
                        break;
                }
                break;
            }
            default:
                cout<<"you typed a wrong character, please try again"<<endl;
        }
    }
    return 0;
}
