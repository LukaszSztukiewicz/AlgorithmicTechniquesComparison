#include "AlgorithmicTechniquesComparison.h"
#include "util/csv.h"
#include <fstream>

#define outQualityFile "./data/out/quality.csv"
#define outTimeFile1 "./data/out/time1.csv"
#define outTimeFile2 "./data/out/time2.csv"
#define inInstancesFolder "./data/in/"

void time_comparison_Greedy_DynamicProgramming_Exhaustive() {
  int initialNumberOfItems = 10;
  int stepNumberOfItems    = 1;
  int maxNumberOfItems     = 15;

  std::fstream file_results_time;
  file_results_time.open(outTimeFile1, std::fstream::out);
  file_results_time << "numberOfItems,greedy,dynamicProgramming,exhaustive" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
      AlgorithmicTechniquesComparison::solveExhaustive};

  for (int i = initialNumberOfItems; i <= maxNumberOfItems; i += stepNumberOfItems) {
    file_results_time << i << ",";
    int knapsackCapacity = int(i * 0.6);
    int maxWeight        = int(i * 0.4);

    // LOG
    std::cout << "---------Instance N: " << i << " C: " << knapsackCapacity << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);
    // LOG
    // print all items
    for (int i = 0; i < items.size(); i++) {
      std::cout << items[i].value << "/" << items[i].weight << " ";
    }
    printf("\n");

    for (auto solvingFunction : solvingFunctions) {
      auto start = std::chrono::high_resolution_clock::now();

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      auto end     = std::chrono::high_resolution_clock::now();
      auto time_ch = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // time in microseconds
      file_results_time << time_ch << ",";
    }
    file_results_time << std::endl;
  }
}

void time_comparison_Greedy_DynamicProgramming() {
  int initialNumberOfItems = 1000;
  int stepNumberOfItems    = 100;
  int maxNumberOfItems     = 10000;

  std::fstream file_results_time;
  file_results_time.open(outTimeFile2, std::fstream::out);
  file_results_time << "numberOfItems,greedy,dynamicProgramming" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
  };

  for (int i = initialNumberOfItems; i <= maxNumberOfItems; i += stepNumberOfItems) {
    file_results_time << i << ",";
    int knapsackCapacity = int(i * 0.6);
    int maxWeight        = int(i * 0.4);

    // LOG
    std::cout << "Generating instance with " << i << " number of elements GDP" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);

    for (auto solvingFunction : solvingFunctions) {
      auto start = std::chrono::high_resolution_clock::now();

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      auto end     = std::chrono::high_resolution_clock::now();
      auto time_ch = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // microseconds
      file_results_time << time_ch << ",";
    }
    file_results_time << std::endl;
  }
}

void quality_comparison_Greedy_DynamicProgramming() {
  int initialNumberOfItems = 1000;
  int stepNumberOfItems    = 100;
  int maxNumberOfItems     = 10000;

  std::fstream file_results_quality;
  file_results_quality.open(outQualityFile, std::fstream::out);
  file_results_quality << "numberOfItems,greedy,dynamicProgramming" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
  };

  for (int i = initialNumberOfItems; i <= maxNumberOfItems; i += stepNumberOfItems) {
    file_results_quality << i << ",";
    int knapsackCapacity = int(i * 0.6);
    int maxWeight        = int(i * 0.4);

    // LOG
    std::cout << "Generating instance with " << i << " number of elements QGDP" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);

    for (auto solvingFunction : solvingFunctions) {

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      int solutionQuality = 0;
      for (auto item : solution) {
        solutionQuality += item.value;
      }
      file_results_quality << solutionQuality << ",";
    }
    file_results_quality << std::endl;
  }
}

int main(int argc, char const *argv[]) {

  // time_comparison_Greedy_DynamicProgramming_Exhaustive();
  time_comparison_Greedy_DynamicProgramming();
  quality_comparison_Greedy_DynamicProgramming();

  return 0;
}
