#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ProductNode {
    int product_id;
    float unit_price;
    struct ProductNode* children[10]; 
};


struct ProductNode* createProductNode(int product_id, float unit_price) {
    struct ProductNode* newNode = (struct ProductNode*)malloc(sizeof(struct ProductNode));
    newNode->product_id = product_id;
    newNode->unit_price = unit_price;

    for (int i = 0; i < 10; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}


float calculateTotalValue(struct ProductNode* node) {
    if (node == NULL) {
        return 0;
    }

    float total_value = node->unit_price;

    for (int i = 0; i < 10 && node->children[i] != NULL; i++) {
        total_value += calculateTotalValue(node->children[i]);
    }

    return total_value;
}


void inOrderTraversal(struct ProductNode* node) {
    if (node != NULL) {
        for (int i = 0; i < 10 && node->children[i] != NULL; i++) {
            inOrderTraversal(node->children[i]);
        }

        printf("Product ID: %d, Unit Price: $%.2f\n", node->product_id, node->unit_price);
    }
}

// Function to search for a specific product in the inventory
bool searchProduct(struct ProductNode* node, int target_id) {
    if (node == NULL) {
        return false;
    }

    if (node->product_id == target_id) {
        return true;
    }

    for (int i = 0; i < 10 && node->children[i] != NULL; i++) {
        if (searchProduct(node->children[i], target_id)) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage:
    struct ProductNode* root = createProductNode(1, 10.0);

    // Add more nodes to the tree
    root->children[0] = createProductNode(2, 15.0);
    root->children[1] = createProductNode(3, 20.0);

    // Variants for product with ID 2
    root->children[0]->children[0] = createProductNode(4, 12.0);
    root->children[0]->children[1] = createProductNode(5, 18.0);

    // Variants for product with ID 3
    root->children[1]->children[0] = createProductNode(6, 22.0);
    root->children[1]->children[1] = createProductNode(7, 25.0);

    // I. Calculate and display the total value of the entire inventory
    float total_value = calculateTotalValue(root);
    printf("Total inventory value: $%.2f\n", total_value);

    // II. In-order traversal to display products in sorted order
    printf("Products in sorted order:\n");
    inOrderTraversal(root);

    // III. Search for a specific product
    int target_id;
    printf("Enter the product ID to search: ");
    scanf("%d", &target_id);

    if (searchProduct(root, target_id)) {
        printf("Product with ID %d is present in the inventory.\n", target_id);
    } else {
        printf("Product with ID %d is absent in the inventory.\n", target_id);
    }

    // Free the allocated memory
    // You may need to implement a function for freeing the tree nodes
    // depending on the actual structure and implementation
    free(root->children[0]);
    free(root->children[1]);
    free(root);

    return 0;
}


