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
  return chosenItems;
}

std::vector<Item> solveDynamicProgramming(std::vector<Item> items, int knapsackCapacity) { // check
  std::vector<Item> chosenItems;
  std::vector<int> chosenItemsValue = std::vector<int>(knapsackCapacity + 1, 0);
  for (int i = 0; i < items.size(); i++) {
    for (int j = knapsackCapacity; j >= items[i].weight; j--) {
      if (chosenItemsValue[j - items[i].weight] + items[i].value > chosenItemsValue[j]) {
        chosenItemsValue[j] = chosenItemsValue[j - items[i].weight] + items[i].value;
      }
    }
  }
  for (int i = knapsackCapacity; i >= 0; i--) {
    if (chosenItemsValue[i] > 0) {
      for (int j = 0; j < items.size(); j++) {
        if (chosenItemsValue[i] == chosenItemsValue[i - items[j].weight] + items[j].value) {
          chosenItems.push_back(items[j]);
          i -= items[j].weight;
          break;
        }
      }
    }
  }
  return chosenItems;
}
} // namespace AlgorithmicTechniquesComparison