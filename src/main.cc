#include "AlgorithmicTechniquesComparison.h"
#include "util/csv.h"

#define outQualityFile "./data/out/quality.csv"
#define outTimeFile "./data/out/time.csv"
#define inInstancesFolder "./data/in/"

int main(int argc, char const *argv[]) {

  int initialNumberOfItems = 10;
  int stepNumberOfItems    = 1;
  int maxNumberOfItems     = 30;

  std::ofstream file_results_quality;
  std::ofstream file_results_time;

  file_results_quality.open(outQualityFile);
  file_results_quality << "numberOfItems,greedy,dynamicProgramming" << std::endl;

  file_results_time.open(outTimeFile);
  file_results_time << "numberOfItems,greedy,dynamicProgramming,exhaustive" << std::endl;

  for (int i = initialNumberOfItems; i < maxNumberOfItems; i += stepNumberOfItems) {

    file_results_time << i << ",";
    file_results_quality << i << ",";
    // LOG
    std::cout << "Generating instance with " << i << " number of elements" << std::endl;
    std::vector<Item> items = AlgorithmicTechniquesComparison::generateRandomItems(i, 100);
    // LOG
    std::cout << "" << std::endl;

    auto start_ch = std::chrono::high_resolution_clock::now();

    auto end_ch    = std::chrono::high_resolution_clock::now();
    auto duration  = std::chrono::duration_cast<std::chrono::milliseconds>(end_ch - start_ch);
    double time_ch = duration.count(); // seconds
    file_results_time << time_ch << ",";
  }
  file_results_time << "\n";
  file_results_time.close();

  return 0;
}
