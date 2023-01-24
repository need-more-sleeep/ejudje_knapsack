#include <iostream>
#include <unordered_set>
#include <vector>

struct precision_item {
	int p_weight = 0;
	int p_cost = 0;
	std::unordered_set<int> numbers;

	precision_item(int p_w, int p_c) :p_weight(p_w), p_cost(p_c) {}
};

class knapsack {
	
	int items_count = 0;
	int max_cost = 0;

	double precision = 0;
	int max_capacity = 0;

	int index_solution = 0;
	std::vector<precision_item> prec_items;
	std::vector<int> orig_costs;

	std::vector<int> costs;
	std::vector<int> weights;
public:
	knapsack(double prec, int max_cap, const std::vector<std::pair<int, int>>& items);
	void solve();
	int get_costs_sum();
	void fill_precision_items();
	friend void print_solution( const knapsack& k);
};


int main() {
	std::ios_base::sync_with_stdio(0);
	double precision;
	int max_weight;
	std::vector <std::pair<int, int>> items;

	std::cin >> precision;
	std::cin >> max_weight;
	int weight, cost;
	while (std::cin >> weight) {
		std::cin >> cost;
		items.emplace_back(std::pair<int, int>(weight, cost));
	}
	knapsack k(precision, max_weight, items);
	k.solve();
	print_solution( k);
}


void print_solution( const knapsack& k) {
	std::cout << k.prec_items[k.index_solution].p_weight << " " << k.prec_items[k.index_solution].p_cost << std::endl;
	for (auto num : k.prec_items[k.index_solution].numbers) {
		std::cout << num + 1 << std::endl;
	}
}

knapsack::knapsack(double prec, int max_cap, const std::vector<std::pair<int, int>>& items) :precision(prec), max_capacity(max_cap) {
	items_count = items.size();
	max_cost = items[0].second;
	for (size_t i = 0; i < items.size(); i++) {
		orig_costs.emplace_back(items[i].second);
		costs.emplace_back(items[i].second);
		weights.emplace_back(items[i].first);
		if (max_cost < items[i].second) {
			max_cost = items[i].second;
		}
	}
}

int knapsack::get_costs_sum() {
	int sum = 0;
	for (size_t i = 0; i < costs.size(); i++) {
		sum += costs[i];
	}
	return sum;
}

void knapsack::fill_precision_items() {
	double coef = 1;
	if (precision != 0) {
		coef = items_count / precision / max_cost;
	}
	if (coef < 1) {
		for (size_t i = 0; i < costs.size(); i++) {
			costs[i] *= coef;
		}

	}
	prec_items.emplace_back(precision_item(0, 0));

	for (size_t i = 0; i < get_costs_sum() + 1; i++)
	{
		prec_items.emplace_back(precision_item(max_capacity + 1, 0));
	}
}


void knapsack::solve() {
	fill_precision_items();
	for (size_t i = 0; i < items_count; i++) {
		int j = get_costs_sum();
		while (j >= costs[i]) {
			int pos = j - costs[i];
			if (prec_items[pos].p_weight + weights[i] < prec_items[j].p_weight) {
				prec_items[j].numbers = prec_items[pos].numbers;
				prec_items[j].numbers.emplace(i);

				prec_items[j].p_weight = prec_items[pos].p_weight + weights[i];
				prec_items[j].p_cost = prec_items[pos].p_cost + orig_costs[i];
			}
			j -= 1;
		}
	}

	for (int i = prec_items.size() - 1; i >= 0; i--) {
		if (prec_items[i].p_weight <= max_capacity) {
			index_solution = i;
			break;
		}
	}
}