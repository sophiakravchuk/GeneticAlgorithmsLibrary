#include <iostream>
#include <thread>
#include "genetic.h"

std::vector<int>* Genetic::run(){
    int min_points[1000*n_variables];
    int am_of_gens = 0;
    while (am_of_gens < 1000){
        am_of_gens++;
        next_gen();

        for(int j = 0; j < n_variables; j++) {
            min_points[j] = population[j];
        }
    }

    int* res_a = new int[n_variables];
    std::vector<int>* res = new std::vector<int>();
    for(int j = 0; j < n_variables; j++) {
        res->push_back(population[j]);
        res_a[j] = population[j];
    }
// << " Y = " << (*res)[1]

    std::cout << "Minimum found      X = " << (*res)[0] <<std::endl;
    std::cout << "F(x) = " << f(res_a) << std::endl;
    return res;
}



void Genetic::next_gen(){
    int* results = getResults();

    int* children = new int[pop_size*n_variables];
    int index = findSmallestElement(results, pop_size);

    for (int i = 0; i < n_variables; i++){
        children[i] = population[index*n_variables+i];

    }
    int* scount = new int[am_of_threads];
    int* displs = new int[am_of_threads];
    displs[0] = n_variables;
    int part = pop_size/am_of_threads ;
    for (int i = 0; i < am_of_threads; i++) {
        int end = part * n_variables*(i + 1);
        if (i == (am_of_threads - 1)) {
            end = (pop_size-1)*n_variables;
        }
        scount[i] = end - part*n_variables * i;
        if ( i != am_of_threads-1) {
            displs[i + 1] = displs[i] + scount[i];
        }
    }

    int* children_size = new int[1];
    children_size[0] = n_variables;
    std::vector<std::thread> vector_of_threads2;
    vector_of_threads2.reserve(am_of_threads);
    for (int i = 0; i < am_of_threads; i++) {
        vector_of_threads2.emplace_back(&Genetic::calcGeneration, this, results, scount[i], children, displs[i]);
    }
    for (auto &t: vector_of_threads2) {
        t.join();
    }
    for (int i = 0; i < pop_size*n_variables; i++){
        population[i] = children[i];
    }

    delete[] children;

}

int* Genetic::getResults(){
    int* results = new int[pop_size];
    std::vector<std::thread> vector_of_threads1;
    vector_of_threads1.reserve(am_of_threads);
    int part = pop_size/am_of_threads;
    for (int i = 0; i < am_of_threads; i++) {
        int end = part*(i+1);
        if (i == am_of_threads-1){
            end = pop_size;
        }

        vector_of_threads1.emplace_back(&Genetic::evaluatePopulation, this, population, part*i, end, results);
    }
    for (auto &t: vector_of_threads1) {
        t.join();
    }
    return results;
}


void Genetic::calcGeneration(int* results, int amount, int*  children, int displs){
    int children_index = displs;
    while (amount){

        int* p1 = new int[n_variables];
        int* p2 = new int[n_variables];
        int* pars = new int[2*n_variables];
        int* parents;

        parents = getParent(pars, results, 2);
        el1 = (el1 +1)%100;
        el2 = (el2 +1)%100;

        for (int i = 0; i < n_variables; i++){
            p1[i] = parents[i];
        }
        for (int i = 0; i < n_variables; i++){
            p2[i] = parents[i+n_variables];
        }

        int* signs = get_signs(p1, p2);

        char* binary_p1 = getCipher(p1);
        char* binary_p2 = getCipher(p2);

        int* new_child = getNewChild(binary_p1, binary_p2, signs, 2);
        new_child = mutation(new_child, maxim, minim, 1, 2);

        for (int i = 0; i< n_variables; i++){
            if (new_child[i] > maxim || new_child[i] < minim){
                new_child[i] = getRand(minim, maxim);
            }
        }
        for(int i = 0; i < n_variables; i++){
            children[children_index] = new_child[i];
            children_index++;
        }
        delete binary_p1;
        delete binary_p2;
        delete signs;
        amount--;
    }
}
