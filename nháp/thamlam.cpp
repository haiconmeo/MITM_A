#include <stdio.h>
#include <cstdlib>
struct Item {
	
	int weight;
	int value;
	float density;
};

void fractionalKnapsack(Item items[], int n, int W);

int main(void) {
	//variables
	int i, j;
	Item items[50];
	for (int i =0;i<50;i++){
		
		items[i].value= rand()%100;
		items[i].weight=rand()%100;
		items[i].density=0;
		
	}
	
	//list items
	

	//temp item
	Item temp;

	//number of items
	int n = 50;

	//max weight limit of knapsack
	int W = 100;

	//compute desity = (value/weight)
	for(i = 0; i < n; i++) {
		items[i].density = float(items[i].value) / items[i].weight;
	}

	//sort by density in descending order
	for(i = 1; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			if(items[j+1].density > items[j].density) {
				temp = items[j+1];
				items[j+1] = items[j];
				items[j] = temp;
			}
		}
	}

	fractionalKnapsack(items, n, W);

	return 0;
}

void fractionalKnapsack(Item items[], int n, int W) {
	int i, wt;
	float value;

	float totalWeight = 0, totalBenefit = 0;

	for(i = 0; i < n; i++) {
		if(items[i].weight + totalWeight <= W) {

			totalWeight += items[i].weight;
			totalBenefit += items[i].value;

			printf("Selected Item: \tWeight: %d\tValue: %d\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].weight, items[i].value, totalWeight, totalBenefit);

		} else {
			wt = (W - totalWeight);
			value = wt * (float(items[i].value) / items[i].weight);

			totalWeight += wt;
			totalBenefit += value;

			printf("Selected Item: \tWeight: %d\tValue: %f\tTotal Weight: %f\tTotal Benefit: %f\n",  wt, value, totalWeight, totalBenefit);

			break;
		}
	}

	printf("Total Weight: %f\n", totalWeight);
	printf("Total Benefit: %f\n", totalBenefit);
}
