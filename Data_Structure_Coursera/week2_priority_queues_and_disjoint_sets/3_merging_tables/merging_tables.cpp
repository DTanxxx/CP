#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		// find parent and compress path
		if (sets[table].parent != table) {
			sets[table].parent = getParent(sets[table].parent);
		}
		return sets[table].parent;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			DisjointSetsElement destinationTable = sets[realDestination];
			DisjointSetsElement sourceTable = sets[realSource];
			if (destinationTable.rank < sourceTable.rank) {
				// merge destination into source, and change the table number
				sourceTable.parent = destinationTable.parent;
				sourceTable.size += destinationTable.size;
				sets[realDestination] = sourceTable;
				sets[realSource] = destinationTable;
				
				if (sourceTable.size > max_table_size) {
					max_table_size = sourceTable.size;
				}
			}
			else {
				// merge source into destination
				sourceTable.parent = destinationTable.parent;
				if (sourceTable.rank == destinationTable.rank) {
					// update destinationTable's rank;
					destinationTable.rank++;
				}
				destinationTable.size += sourceTable.size;
				if (destinationTable.size > max_table_size) {
					max_table_size = destinationTable.size;
				}
				sets[realDestination] = destinationTable;
				sets[realSource] = sourceTable;
			}
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
                --destination;
                --source;
		
		tables.merge(destination, source);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
