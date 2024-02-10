#include <stdio.h>
#include <stdlib.h>

// Node structure for the multiway tree
struct Node {
    int key;
    struct Node** children;
};

// Function to create a new node with given key
struct Node* createNode(int key, int numChildren) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->children = (struct Node**)malloc(numChildren * sizeof(struct Node*));
    for (int i = 0; i < numChildren; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a key into the multiway tree
void insertKey(struct Node* root, int key, int numChildren) {
    // Update the key of the root node if it's the first insertion
    if (root->key == 0) {
        root->key = key;
        return;
    }

    // Insert at the first available child
    for (int i = 0; i < numChildren; ++i) {
        if (root->children[i] == NULL) {
            root->children[i] = createNode(key, numChildren);
            break;
        }
    }
}

// Function to calculate and display the sum of all keys in the tree
int calculateSum(struct Node* root) {
    if (root == NULL) return 0;

    int sum = root->key;
    for (int i = 0; root->children[i] != NULL; ++i) {
        sum += calculateSum(root->children[i]);
    }

    return sum;
}

// Function to perform in-order traversal and display keys in sorted order
void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    for (int i = 0; root->children[i] != NULL; ++i) {
        inOrderTraversal(root->children[i]);
    }

    printf("%d ", root->key);
}

// Function to find and display the maximum key in the tree
int findMaxKey(struct Node* root) {
    if (root == NULL) return -1; // Assuming keys are non-negative
    
    int maxKey = root->key;
    for (int i = 0; root->children[i] != NULL; ++i) {
        int childMax = findMaxKey(root->children[i]);
        if (childMax > maxKey) {
            maxKey = childMax;
        }
    }

    return maxKey;
}

// Function to find and display the minimum key in the tree
int findMinKey(struct Node* root) {
    if (root == NULL) return -1; // Assuming keys are non-negative
    
    int minKey = root->key;
    for (int i = 0; root->children[i] != NULL; ++i) {
        int childMin = findMinKey(root->children[i]);
        if (childMin < minKey) {
            minKey = childMin;
        }
    }

    return minKey;
}

int main() {
    // Get user inputs for the insertion process
    int numChildren;
    printf("Enter the number of children each node can have: ");
    scanf("%d", &numChildren);

    int numInsertions;
    printf("Enter the number of insertions: ");
    scanf("%d", &numInsertions);

    struct Node* root = createNode(0, numChildren); // Assuming the root has a key of 0

    // Insert keys and calculate sum after each insertion
    for (int i = 0; i < numInsertions; ++i) {
        int key;
        printf("Enter key for insertion %d: ", i + 1);
        scanf("%d", &key);

        insertKey(root, key, numChildren);
        int sum = calculateSum(root);
        printf("Sum after insertion %d: %d\n", i + 1, sum);
    }

    // Calculate and display average key value
    int sum = calculateSum(root);
    float average = (float)sum / numInsertions;
    printf("Average key value: %.2f\n", average);

    // Display keys in sorted order using in-order traversal
    printf("Keys in sorted order: ");
    inOrderTraversal(root);
    printf("\n");

    // Display maximum and minimum keys
    printf("Maximum key: %d\n", findMaxKey(root));
    printf("Minimum key: %d\n", findMinKey(root));

    // Free allocated memory
    free(root->children);
    free(root);

    return 0;
}

