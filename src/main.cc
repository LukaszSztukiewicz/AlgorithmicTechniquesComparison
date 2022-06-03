#include "AlgorithmicTechniquesComparison.h"
#include "util/csv.h"

#define outQualityFile1 "./data/out/quality1.csv"
#define outQualityFile2 "./data/out/quality2.csv"
#define outTimeFile "./data/out/time.csv"
#define inInstancesFolder "./data/in/"

void time_comparison_Greedy_DynamicProgramming_Exhaustive() {
  int initialNumberOfItems = 10;
  int stepNumberOfItems    = 1;
  int maxNumberOfItems     = 30;

  std::ofstream file_results_time;
  file_results_time << "numberOfItems,greedy,dynamicProgramming,exhaustive" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
      AlgorithmicTechniquesComparison::solveExhaustive};

  for (int i = initialNumberOfItems; i < maxNumberOfItems; i += stepNumberOfItems) {
    file_results_time << i << ",";
    int knapsackCapacity = floor(i * 0.6);
    int maxWeight        = floor(i * 0.4);

    // LOG
    std::cout << "Generating instance with " << i << " number of elements" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);

    for (auto solvingFunction : solvingFunctions) {
      auto start = std::chrono::high_resolution_clock::now();

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      auto end     = std::chrono::high_resolution_clock::now();
      auto time_ch = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // milliseconds
      file_results_time << time_ch << ",";
    }
    file_results_time << std::endl;
  }
}

void time_comparison_Greedy_DynamicProgramming() {
  int initialNumberOfItems = 1000;
  int stepNumberOfItems    = 500;
  int maxNumberOfItems     = 10000;

  std::ofstream file_results_time;
  file_results_time << "numberOfItems,greedy,dynamicProgramming" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
  };

  for (int i = initialNumberOfItems; i < maxNumberOfItems; i += stepNumberOfItems) {
    file_results_time << i << ",";
    int knapsackCapacity = floor(i * 0.6);
    int maxWeight        = floor(i * 0.4);

    // LOG
    std::cout << "Generating instance with " << i << " number of elements" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);

    for (auto solvingFunction : solvingFunctions) {
      auto start = std::chrono::high_resolution_clock::now();

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      auto end     = std::chrono::high_resolution_clock::now();
      auto time_ch = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // milliseconds
      file_results_time << time_ch << ",";
    }
    file_results_time << std::endl;
  }
}

void quality_comparison_Greedy_DynamicProgramming() {
  int initialNumberOfItems = 1000;
  int stepNumberOfItems    = 500;
  int maxNumberOfItems     = 10000;

  std::ofstream file_results_time;
  file_results_time << "numberOfItems,greedy,dynamicProgramming" << std::endl;

  // vector of solving functions
  std::vector<std::function<std::vector<Item>(std::vector<Item>, int)>> solvingFunctions = {
      AlgorithmicTechniquesComparison::solveGreedy,
      AlgorithmicTechniquesComparison::solveDynamicProgramming,
  };

  for (int i = initialNumberOfItems; i < maxNumberOfItems; i += stepNumberOfItems) {
    file_results_time << i << ",";
    int knapsackCapacity = floor(i * 0.6);
    int maxWeight        = floor(i * 0.4);

    // LOG
    std::cout << "Generating instance with " << i << " number of elements" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, maxWeight);

    for (auto solvingFunction : solvingFunctions) {
      auto start = std::chrono::high_resolution_clock::now();

      auto solution = solvingFunction(items, knapsackCapacity); // key function

      auto end     = std::chrono::high_resolution_clock::now();
      auto time_ch = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // milliseconds
      file_results_time << time_ch << ",";
    }
    file_results_time << std::endl;
  }
}

int main(int argc, char const *argv[]) {

  time_comparison_Greedy_DynamicProgramming_Exhaustive();
  time_comparison_Greedy_DynamicProgramming();
  quality_comparison_Greedy_DynamicProgramming();

  return 0;
}
