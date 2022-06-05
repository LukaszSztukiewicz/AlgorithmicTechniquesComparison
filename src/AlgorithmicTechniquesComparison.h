#ifndef ALGORITHMICTECHNIQUESCOMPARISON_H
#define ALGORITHMICTECHNIQUESCOMPARISON_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct Item {
  int weight;
  int value;
};

namespace AlgorithmicTechniquesComparison {

std::vector<Item> generateRandomItems(int numberOfItems, int maxWeight);
bool isValid(int knapsackCapacity, std::vector<Item> chosenItems);

std::vector<Item> solveGreedy(std::vector<Item> items, int knapsackCapacity);
std::vector<Item> solveExhaustive(std::vector<Item> items, int knapsackCapacity);
std::vector<Item> solveDynamicProgramming(std::vector<Item> items, int knapsackCapacity);

} // namespace AlgorithmicTechniquesComparison

#endif // ALGORITHMICTECHNIQUESCOMPARISON_H
