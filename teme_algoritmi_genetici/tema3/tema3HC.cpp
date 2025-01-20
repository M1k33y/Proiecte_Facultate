#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <string>
#include <vector>
#define NO_ITER 2000
#define NO_RUL 20
#define MARJA 0.0001

using namespace std;

double PM = 0.01;
double PC = 0.8;
double POP_SIZE = 200;
double NO_GEN = 2000;
double ELITE_K = 0;

map<string, double> optValues = {
	{"dantzig42.txt", 699},
	{"gr24.txt", 1272},
    {"fri26.txt",937},
    {"gr17.txt",2085},
    {"d198.txt",15780},
    {"att48.txt",10628},
    {"gr96.txt",55209},
    {"pcb442.txt",50778},
    {"pa561.txt",2763},
    {"d657.txt",48912}
};

vector<vector<double>> distances;

vector<unsigned int> decode(vector<unsigned int> );
void readDistances(string );
vector<unsigned int> generateRandom(unsigned int );
vector<vector<unsigned int>> hammingNeigh(vector<unsigned int> target);
double computeDistance(vector<unsigned int> );
double computeStdev(vector<vector<unsigned int>> , unsigned int );
double hillClimbing();
void mutation(vector<vector<unsigned int>> & );
void crossover(vector<vector<unsigned int>> & );
double geneticAlg(double );


int main() {	
	string setName;
	int dec;

	cout << "Set name: "; cin >> setName;
	cout << "Type of algorithm (0/1): "; cin >> dec;
	readDistances(setName);

	double minVal = 0, maxVal = 0, mean = 0, stdev = 0;
	vector<double> results;
	results.reserve(NO_RUL);

	for(int i = 0; i < NO_RUL; i++) {
		//cout << i << ' ';
		double val = dec ? geneticAlg(optValues[setName]) : hillClimbing();
		cout << val << '\n';
		if(!i || minVal > val) minVal = val;
		if(!i || maxVal < val) maxVal = val;
		mean += val;
		results.push_back(val);
	}

	mean /= NO_RUL;

	for(auto el : results) {
		stdev += (el - mean)*(el - mean);
	}

	if(NO_RUL > 1) stdev = sqrt(stdev / (NO_RUL - 1));
	else stdev = 0;

	cout << "Minim: " << minVal;
	cout << "\nMaxim: " << maxVal;
	cout << "\nMedie: " << mean;
	cout << "\nDev std: " << stdev << '\n';
	return 0;
}


//iau indicii de la genereate random si aflu solutia
vector<unsigned int> decode(vector<unsigned int> encoding) 
{
	int n = encoding.size() + 1;

	vector<unsigned int> result;
	result.reserve(n);

	vector<double> values;
	values.reserve(n);

	for(int i = 1; i <= n; i++) values.push_back(i);

	for(auto el : encoding) {
		result.push_back(values[el-1]);
		values.erase(values.begin() + el - 1);
	}

	result.push_back(values[0]);

	return result;
}

void readDistances(string filename) {
	ifstream in(filename);

	int numCities;
	in >> numCities;

	double temp; in >> temp;

	distances.reserve(numCities);

	for(int i = 0; i < numCities; i++) {
		vector<double> tempVec; tempVec.reserve(numCities-1-i);

		double dist;
		for(int j = 0; j < numCities; j++) {
			in >> dist;
			tempVec.push_back(dist);
		}

		distances.push_back(tempVec);
	}

	in.close();

}

//geneerez vector de indici care codifica ordinea eliminarii oraselor
vector<unsigned int> generateRandom(unsigned int size) 
{
	random_device rand_dev;
    mt19937 generator(rand_dev());

    vector<unsigned int> result;
    result.reserve(size-1);

    for(int i = size; i > 1; i--) 
    {
    	uniform_int_distribution<unsigned int> distrPerm(1, i);
    	result.push_back(distrPerm(generator));
    }
    //la fiecare pas aleg un oras pe care il pun in solutia mea

    return result;
}

double computeDistance(vector<unsigned int> perm) {
	double d = 0;

	unsigned int numCities = perm.size();

	for(int i = 1; i < numCities; i++) {
		d += distances[perm[i-1]-1][perm[i]-1];
		//else d += distances[perm[i]-1][perm[i-1]-1];
	}

	d += distances[perm[numCities-1]-1][perm[0]-1];
	//else d += distances[perm[0]-1][perm[numCities-1]-2];

	return d;
}

// hc

vector<vector<unsigned int>> hammingNeigh(vector<unsigned int> target) {
	vector<vector<unsigned int>> neighbours;

	unsigned int tSize = target.size();

	for(int i = 0; i < tSize - 1; i++) {
		for(int j = i+1; j < tSize; j++) {
			auto temp = target[i];
			target[i] = target[j];
			target[j] = temp;

			neighbours.push_back(target);

			temp = target[i];
			target[i] = target[j];
			target[j] = temp;
		}
	}

	return neighbours;
}

double hillClimbing() {

	int numCities = distances.size();

	double min = 0;

	for(int i = 0; i < NO_ITER; i++) {
		auto randomPerm = decode(generateRandom(numCities));
	
		double localMin = computeDistance(randomPerm);

		bool changes = true;


		while(changes) {
			changes = false;
	
			auto neighbours = hammingNeigh(randomPerm);
			for(auto neigh : neighbours) {
				double currVal = computeDistance(neigh);
	
				if(currVal < localMin) {
					localMin = currVal;
					randomPerm = neigh;
					changes = true;
				}
			}
		}

		if(!i || localMin < min) min = localMin;
	}

	return min;
}

// genetic

void mutation(vector<vector<unsigned int>> &generation) {
	random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<double> distr(0, 1);

    unsigned int numCities = generation[0].size() + 1;

    for(int i = 0; i < POP_SIZE; i++) {
    	for(int j = numCities; j > 1; j--) {
    		if(distr(generator) < PM) {
    			generation[i][numCities-j] ++;
    			if(generation[i][numCities-j] > j) generation[i][numCities-j] = 1;
    		}
    	}
    }
}

void crossover(vector<vector<unsigned int>> &generatie) {
    vector<vector<unsigned int>> generatie_noua;
    generatie_noua.reserve(POP_SIZE);

    vector<pair<double, vector<unsigned int>>> probabilities;
    probabilities.reserve(POP_SIZE);

    unsigned int cross_cut;
    unsigned int comp_length = generatie[0].size();

    bool do_break = false;

    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<double> distr(0, 1);
    uniform_int_distribution<unsigned int> distr_lungimi(1, comp_length-1);

    for(auto cromozom : generatie) {
        probabilities.emplace_back(distr(generator), cromozom);
    }

    sort(probabilities.begin(), probabilities.end());

    unsigned int i = 0;

    while(i < POP_SIZE && !do_break) {
        if(probabilities[i].first < PC) {
            if (i+1 < POP_SIZE && (probabilities[i + 1].first < PC || rand_dev() % 2 == 1)) {
                //cout << "\nNa o pereche: ";
                cross_cut = distr_lungimi(generator);
               // cout << cross_cut;

                vector<unsigned int> x1(probabilities[i].second.begin(), probabilities[i].second.begin()+cross_cut);
                x1.reserve(comp_length);
                vector<unsigned int> y1(probabilities[i+1].second.begin(), probabilities[i+1].second.begin()+cross_cut);
                y1.reserve(comp_length);
                vector<unsigned int> x2(probabilities[i].second.begin()+cross_cut, probabilities[i].second.end());
                vector<unsigned int> y2(probabilities[i+1].second.begin()+cross_cut, probabilities[i+1].second.end());

                x1.insert(x1.end(), y2.begin(), y2.end());
                y1.insert(y1.end(), x2.begin(), x2.end());

                generatie_noua.push_back(x1);
                generatie_noua.push_back(y1);
            }
            else do_break = true;
        }
        else do_break = true;

        if(!do_break)
            i += 2;
    }

    while(i < POP_SIZE) { generatie_noua.push_back(probabilities[i].second); i++; }

    generatie = generatie_noua;
}

double eval(vector<unsigned int> route, double minim) {
    double d = computeDistance(route) - minim;
    
    if(d == 0) d += MARJA;

    return 1 / d;
}

double selection(vector<vector<unsigned int>> &generatie, double optVal) {
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<double> distr(0, 1);

    vector<pair<double, unsigned int>> fitness;
    fitness.reserve(POP_SIZE);

    vector<double> proportii;
    proportii.reserve(POP_SIZE+1);

    for(int i = 0; i < POP_SIZE; i++) {
        fitness.emplace_back(eval(decode(generatie[i]), optVal), i);
    }

    double total_fitness = 0;

    for(auto f : fitness)  total_fitness += f.first;
   	sort(fitness.begin(), fitness.end());

    for(int i = 0; i < POP_SIZE; i++) {
        if(!i) proportii.push_back(0);
        else proportii.push_back(fitness[i-1].first / total_fitness + proportii[i-1]);
    }
    proportii.push_back(1);

    vector<vector<unsigned int>> generatie_formata;
    generatie_formata.reserve(POP_SIZE);

    for(int i = 0; i < POP_SIZE; i++) {
    	if(i < ELITE_K) {
    		generatie_formata.push_back(generatie[fitness[POP_SIZE-i-1].second]);
    	} else {
	        double crom_random = distr(generator); // (double) rd() / rd.max();

	        int j = 0;
	        while(j < POP_SIZE) {
	            if(proportii[j] <= crom_random && proportii[j+1] > crom_random) {
	                generatie_formata.push_back(generatie[fitness[j].second]);
	                break;
	            }
	            j++;
        	}
        }
    }
    generatie = generatie_formata;


    return computeStdev(generatie, ELITE_K);
}

double computeStdev(vector<vector<unsigned int>> generation, unsigned int num) {
	vector<double> results;
	results.reserve(num);

	double mean = 0;
	double stad = 0;
	for(int i = 0; i < num; i++) {
		auto d = computeDistance(generation[i]);

		mean += d;

		results.push_back(d);
	}

	mean /= num;

	for(auto el : results) {
		stad += (el - mean) * (el - mean);
	}

	stad = sqrt(stad / (num - 1));

	return stad;
}

double geneticAlg(double optVal) {
	vector<vector<unsigned int>> population;
	population.reserve(POP_SIZE);

	int numCities = distances.size();

	unsigned int bestGen = 0;
	unsigned int currBestGen = 0;

	double bestCurrVal = -1;
	double bestVal = -1;
	double cmpStd = 0;
	double holdPM = PM;

	vector<unsigned int> tour;
	tour.reserve(POP_SIZE);

	for(int i = 0; i < POP_SIZE; i++)
		population.push_back(generateRandom(numCities));


	for(int i = 0; i < NO_GEN; i++) {
		double bestInGen = 0;

		for(int j = 0; j < POP_SIZE; j++) {
			double d = computeDistance(decode(population[j]));

			if(!j || d < bestInGen) bestInGen = d;

			if(bestCurrVal == -1 || d < bestCurrVal) {
				bestCurrVal = d;
				currBestGen = i+1;
			}

			if(bestVal == -1 || d < bestVal) {
				tour = population[j];
				bestVal = d;
				bestGen = i+1;
			}
		}

		if(i+1 - currBestGen > 300) { PM = 0.5; bestCurrVal = -1; } //daca trec 300 de gen fara o sol buna maresc diversitatea
		else if(PM == 0.5) { cout << "Resetam la gen " << i << ' ' << computeStdev(population, POP_SIZE) << ' '  << cmpStd << ' ' << bestVal << '\n'; PM = holdPM; }

		mutation(population);
		crossover(population);
		cmpStd = selection(population, optVal);
	}
	
	cout << "Best of all is " << setprecision(10) << bestVal << " from gen " << bestGen << '\n';

	for(auto i : decode(tour)) cout << i << ' ';
	cout << '\n';

	return bestVal;
}
