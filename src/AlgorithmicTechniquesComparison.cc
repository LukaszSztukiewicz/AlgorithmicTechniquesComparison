#include "AlgorithmicTechniquesComparison.h"

namespace AlgorithmicTechniquesComparison {

std::vector<Item> generateRandomItems(int numberOfItems, int maxVW) {
  std::vector<Item> items;
  for (int i = 0; i < numberOfItems; i++) {
    Item item;
    item.weight = rand() % maxVW + 1;
    item.value  = rand() % maxVW + 1;
    items.push_back(item);
  }
  return items;
}

bool isValid(int knapsackCapacity, std::vector<Item> chosenItems) {
  int totalWeight = 0;
  for (int i = 0; i < chosenItems.size(); i++) {
    totalWeight += chosenItems[i].weight;
  }
  return totalWeight <= knapsackCapacity;
}

std::vector<Item> solveExhaustive(std::vector<Item> items, int knapsackCapacity) {
  std::vector<Item> bestSolution;
  int bestSolutionValue  = 0;
  std::vector<bool> mask = std::vector<bool>(items.size(), false);
  // for all possible masks
  for (int i = 0; i < (1 << items.size()); i++) { // 2 to the poer of items.size()
    std::vector<Item> chosenItems;
    int chosenItemsValue = 0;
    for (int j = 0; j < items.size(); j++) {
      if (mask[j]) {
        chosenItems.push_back(items[j]);
        chosenItemsValue += items[j].value;
      }
    }
    if (isValid(knapsackCapacity, chosenItems) && chosenItemsValue > bestSolutionValue) {
      bestSolution      = chosenItems;
      bestSolutionValue = chosenItemsValue;
    }
    // increment mask
    int k = 0;
    while (mask[k]) {
      mask[k] = false;
      k++;
    }
    mask[k] = true;
  }
  // LOG
  std::cout << "Exhaustive: " << bestSolutionValue << std::endl;
  // print solution
  for (int i = 0; i < bestSolution.size(); i++) {
    std::cout << bestSolution[i].value << "/" << bestSolution[i].weight << " ";
  }
  printf("\n");
  return bestSolution;
}

std::vector<Item> solveGreedy(std::vector<Item> items, int knapsackCapacity) {
  struct ItemWithScore : public Item {
    double score;
  };
  std::vector<ItemWithScore> itemsWithScore;
  for (int i = 0; i < items.size(); i++) {
    ItemWithScore itemWithScore;
    itemWithScore.weight = items[i].weight;
    itemWithScore.value  = items[i].value;
    itemWithScore.score  = itemWithScore.value / itemWithScore.weight;
    itemsWithScore.push_back(itemWithScore);
  }
  std::sort(itemsWithScore.begin(), itemsWithScore.end(), [](ItemWithScore a, ItemWithScore b) { return a.score > b.score; });
  std::vector<Item> chosenItems;
  int chosenItemsValue = 0;
  for (int i = 0; i < itemsWithScore.size(); i++) {
    if (itemsWithScore[i].weight <= knapsackCapacity) {
      chosenItems.push_back(itemsWithScore[i]);
      chosenItemsValue += itemsWithScore[i].value;
      knapsackCapacity -= itemsWithScore[i].weight;
    }
  }
  // LOG
  printf("Greedy: %d\n", chosenItemsValue);
  // print chosen items
  for (int i = 0; i < chosenItems.size(); i++) {
    std::cout << chosenItems[i].value << "/" << chosenItems[i].weight << " ";
  }
  printf("\n");
  return chosenItems;
}

std::vector<Item> solveDynamicProgramming(std::vector<Item> items, int knapsackCapacity) { // check
  std::vector<Item> chosenItems;
  std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(items.size() + 1, std::vector<int>(knapsackCapacity + 1, 0));
  for (int i = 0; i < items.size(); i++) {
    for (int j = 0; j <= knapsackCapacity; j++) {
      if (j < items[i].weight) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = std::max(dp[i][j], dp[i][j - items[i].weight] + items[i].value);
      }
    }
  }

  int i = items.size();
  int j = knapsackCapacity;
  while (i > 0) {
    if (dp[i][j] != dp[i - 1][j]) {
      chosenItems.push_back(items[i - 1]);
      j -= items[i - 1].weight;
    }
    i--;
  }

  // LOG
  printf("DynamicProgramming: %d\n", dp[items.size()][knapsackCapacity]);
  // print chosen items
  for (int i = 0; i < chosenItems.size(); i++) {
    std::cout << chosenItems[i].value << "/" << chosenItems[i].weight << " ";
  }
  printf("\n");
  return chosenItems;
}
} // namespace AlgorithmicTechniquesComparison