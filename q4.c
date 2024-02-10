#include <stdio.h>
#include <stdlib.h>

// Structure to represent a subset (or disjoint set) for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the root of a given element
int findRoot(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = findRoot(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets
void unionSets(struct Subset subsets[], int x, int y) {
    int xRoot = findRoot(subsets, x);
    int yRoot = findRoot(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank) {
        subsets[xRoot].parent = yRoot;
    } else if (subsets[xRoot].rank > subsets[yRoot].rank) {
        subsets[yRoot].parent = xRoot;
    } else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

// Function to calculate minimum friend connections
int minFriendConnections(int n, int friendships[][2], int numFriendships) {
    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));

    // Initialize subsets
    for (int i = 0; i < n; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Perform union of sets based on friendships
    for (int i = 0; i < numFriendships; ++i) {
        int x = friendships[i][0];
        int y = friendships[i][1];
        unionSets(subsets, x, y);
    }

    int connectedComponents = 0;
    for (int i = 0; i < n; ++i) {
        if (subsets[i].parent == i) {
            connectedComponents++;
        }
    }

    free(subsets);

    // Minimum connections required = connected components - 1
    return (connectedComponents - 1);
}

// Test the function
int main() {
    int n = 7; // Number of users (IDs ranging from 0 to n-1)
    int friendships[][2] = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 6}}; // Sample friendships

    int numFriendships = sizeof(friendships) / sizeof(friendships[0]);

    int minConnections = minFriendConnections(n, friendships, numFriendships);
    printf("Minimum friend connections required: %d\n", minConnections);

    return 0;
}
