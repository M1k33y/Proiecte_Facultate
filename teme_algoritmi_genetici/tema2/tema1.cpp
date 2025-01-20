#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <random>
#include <cstring>
#include <map>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
#define PRECIZIE 5
#define MAX 30



inline double  deJongFunction(vector<double> p, unsigned int dimensiune)
{
    double val = 0;
    for (unsigned int i = 0; i < dimensiune; i++)
        val += p[i] * p[i];
    return val;
}

inline double  schwefelFunction(vector<double> p, unsigned int dimensiune)
{
    double val = 0;
    for (unsigned int i = 0; i < dimensiune; i++)
        val += -p[i] * sin(sqrt(abs(p[i])));
    return val;
}

inline double  rastriginFunction(vector<double> p, unsigned int dimensiune)
{
    double val = 10 * dimensiune;
    for (unsigned int i = 0; i < dimensiune; i++)
        val += p[i] * p[i] - (10 * cos(2 * M_PI * p[i]));
    return val;
}

inline double  michalewiczFunction(vector<double> p, unsigned int dimensiune)
{
    double val = 0;
    for (unsigned int i = 0; i < dimensiune; i++)
        val += sin(p[i]) * pow((sin(i * p[i] * p[i] / M_PI)), 20);
    val = val * (-1);
    return val;
}

map <string, vector<double>>intervale = {
    {"Rastrigin",{-5.12,5.12}},
    {"DeJong",{-5.12,5.12}},
    {"Schewefel",{-500,500}},
    {"Michalewicz",{0,M_PI}}
};

map <string, double(*)(vector<double>, unsigned int)>functii = {
     {"Rastrigin",&rastriginFunction},
    {"DeJong",&deJongFunction},
    {"Schewefel",&schwefelFunction},
    {"Michalewicz",&michalewiczFunction}
};

inline double decode(vector<bool>v, double a, double b)
{
    double rez = 0;
    unsigned int length = v.size();
    unsigned int p = 1; //putere la 2

    for (int i = length - 1; i >= 0; i--)
    {
        rez += v[i] * p;
        p *= 2;
    }

    rez /= (p - 1);
    rez *= (b - a);
    rez += a;

    return rez;

}

inline vector<bool> randomGeneration(int lungime)
{

    vector<bool> rez;
    random_device bit_random;
    rez.reserve(lungime);
    for (int i = 0; i < lungime; i++)
        rez.push_back(bit_random() % 2);
    return rez;

}


inline unsigned int lengthBitString(double a, double b)
{
    return (unsigned)ceil(log2(b - a) + PRECIZIE * log2(10));
}


inline vector<bool> extract_x(vector<bool>v, int start, int lg)
{
    return vector<bool>(v.begin() + start, v.begin() + start + lg);
}
//extrag un subset din x

inline vector<bool> best_improve(vector<bool>v, string nume, double a, double b, unsigned int dimensiune)
{
    vector<bool>best = v;
    double val_best = 999999999999;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        vector<bool>vecin = v;
        vecin[i] = !v[i];

        vector<double>decoded_nr;
        for (unsigned int j = 0; j < dimensiune; j++)
        {
            vector<bool>sub_nr = extract_x(vecin, j * v.size() / dimensiune, v.size() / dimensiune);
            decoded_nr.push_back(decode(sub_nr, a, b));
        }
        double val_curenta = functii[nume](decoded_nr, dimensiune);

        if (val_curenta < val_best)
        {
            val_best = val_curenta;
            best = vecin;
        }

    }
    return best;
}

inline vector<bool> first_improve(vector<bool>v, string nume, double a, double b, unsigned int dimensiune)
{

    for (unsigned int i = 0; i < v.size(); i++)
    {
        vector<bool>vecin = v;
        vecin[i] = !v[i];

        vector<double>decoded_nr;
        for (unsigned int j = 0; j < dimensiune; j++)
        {
            vector<bool>sub_nr = extract_x(vecin, j * v.size() / dimensiune, v.size() / dimensiune);
            decoded_nr.push_back(decode(sub_nr, a, b));
        }
        double val_curenta = functii[nume](decoded_nr, dimensiune);

        vector<double>decoded_v;
        for (unsigned int j = 0; j < dimensiune; j++)
        {
            vector<bool>sub_v = extract_x(v, j * v.size() / dimensiune, v.size() / dimensiune);
            decoded_v.push_back(decode(sub_v, a, b));
        }
        double val_v = functii[nume](decoded_v, dimensiune);

        if (val_curenta < val_v)
            return vecin;

    }
    return v;
}

inline vector<bool> worst_improve(vector<bool>v, string nume, double a, double b, unsigned int dimensiune)
{
    vector<bool>worst = v;
    double val_worst = -99999999999;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        vector<bool>vecin = v;
        vecin[i] = !v[i];

        vector<double>decoded_nr;
        for (unsigned int j = 0; j < dimensiune; j++)
        {
            vector<bool>sub_nr = extract_x(vecin, j * v.size() / dimensiune, v.size() / dimensiune);
            decoded_nr.push_back(decode(sub_nr, a, b));
        }
        double val_curenta = functii[nume](decoded_nr, dimensiune);

        if (val_curenta > val_worst)
        {
            val_worst = val_curenta;
            worst = vecin;
        }


    }
    return worst;
}

inline double hillClimbing(string nume, unsigned int dimensiune)
{   //initializari din mapari
    double (*functie) (vector<double>, unsigned int) = functii[nume];
    double a = intervale[nume][0], b = intervale[nume][1];



    //implementare hill climbing
    unsigned int t = 0;

    unsigned int lungime = lengthBitString(a, b) * dimensiune;
    vector<bool> best = randomGeneration(lungime);
    vector<double>decoded_best;
    for (int i = 0; i < dimensiune; i++)
    {
        vector<bool> sub_x = extract_x(best, i * lungime / dimensiune, lungime / dimensiune);
        decoded_best.push_back(decode(sub_x, a, b));
    }

    double val_best = functie(decoded_best, dimensiune);
    //am primul (best)

    do
    {
        bool local = false;
        vector<bool>vc = randomGeneration(lungime);
        do
        {
            vector<bool> vn = best_improve(vc, nume, a, b, dimensiune);
            //vector<bool> vn = first_improve(vc, nume, a, b, dimensiune);
            //vector<bool> vn = worst_improve(vc,nume,a,b,dimensiune);
            vector<double>decoded_vc, decoded_vn;

            for (int i = 0; i < dimensiune; i++)
            {
                vector<bool>sub_vc = extract_x(vc, i * lungime / dimensiune, lungime / dimensiune);
                vector<bool>sub_vn = extract_x(vn, i * lungime / dimensiune, lungime / dimensiune);

                decoded_vc.push_back(decode(sub_vc, a, b));
                decoded_vn.push_back(decode(sub_vn, a, b));
            }

            double val_vc = functie(decoded_vc, dimensiune);
            double val_vn = functie(decoded_vn, dimensiune);

            if (val_vn < val_vc)
                vc = vn;
            else
                local = true;

        } while (!local);
        t++;

        vector<double>decoded_vc;
        for (int i = 0; i < dimensiune; i++)
        {
            vector<bool>sub_vc = extract_x(vc, i * lungime / dimensiune, lungime / dimensiune);
            decoded_vc.push_back(decode(sub_vc, a, b));
        }
        double val_vc = functie(decoded_vc, dimensiune);

        if (val_vc < val_best)
        {
            best = vc;
            val_best = val_vc;
        }


    } while (t < MAX);

    //decodez sol finala yay
    vector<double>final_best;
    for (unsigned int i = 0; i < dimensiune; i++)
    {
        vector<bool> sub_final = extract_x(best, i * lungime / dimensiune, lungime / dimensiune);
        final_best.push_back(decode(sub_final, a, b));
    }

    return functie(final_best, dimensiune);


}

inline double simulatedAnnealing(string nume, unsigned int dimensiune)
{
    double (*functie) (vector<double>, unsigned int) = functii[nume];
    double a = intervale[nume][0], b = intervale[nume][1];

    unsigned int t = 0;
    double T = 100.0;
    unsigned int lungime = lengthBitString(a, b) * dimensiune;

    //prima
    vector<bool>vc = randomGeneration(lungime);
    vector<double>decoded_vc;
    for (unsigned int i = 0; i < dimensiune; i++)
    {
        vector<bool>sub_vc = extract_x(vc, i * lungime / dimensiune, lungime / dimensiune);
        decoded_vc.push_back(decode(sub_vc, a, b));
    }
    double val_vc = functie(decoded_vc, dimensiune);
    //gata prima

    vector<bool>best = vc;
    double val_best = val_vc;
    do
    {
        for (unsigned int i = 0; i < dimensiune * 10; i++) //nu stiu cate iteratii trebuie sa aiba din cauza temperaturii
        {
            vector<bool>vn = best_improve(vc, nume, a, b, dimensiune);
            vector<double>decoded_vn;
            for (unsigned int j = 0; j < dimensiune; j++)
            {
                vector<bool>sub_vn = extract_x(vn, j * lungime / dimensiune, lungime / dimensiune);
                decoded_vn.push_back(decode(sub_vn, a, b));
            }
            double val_vn = functie(decoded_vn, dimensiune);

            if (val_vn < val_vc)
            {
                vc = vn;
                val_vc = val_vn;
                if (val_vn < val_best)
                {
                    best = vn;
                    val_best = val_vn;
                }
            }
            else
            {
                if ((double)rand() / RAND_MAX < exp(-(abs(val_vn - val_vc) / T)))
                {
                    vc = vn;
                    val_vc = val_vn;
                }


            }

        }
        T *= 0.9;
        t++;
    } while (t < MAX && T>0.1);

    return val_best;

}
int main()
{
    string nume;
    unsigned int dimensiune;
    unsigned int nrcomanda;
    cout << "Introduceti numele functiei: ";
    cin >> nume;
    if (nume != "Rastrigin" && nume != "DeJong" && nume != "Schewefel" && nume != "Michalewicz")
    {
        cout << "Nume incorect";
        return 0;
    }
    cout << "Introduceti dimensiunea: ";
    cin >> dimensiune;
    cout << "Introduceti 1 pt HillClimbing,2 pt Simulated Annealing: ";
    cin >> nrcomanda;

    auto start = high_resolution_clock::now();

    if (nrcomanda == 1)
        cout << fixed << setprecision(5) << hillClimbing(nume, dimensiune) << endl;
    else
        cout << fixed << setprecision(5) << simulatedAnnealing(nume, dimensiune) << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<seconds>(stop - start);
    cout << duration.count() << " secunde" << endl;
    return 0;


}