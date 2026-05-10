#include <iostream>

using namespace std;

// Struktur dasar node pada Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

// Fungsi untuk mencari nilai minimum
int minValue(Node* root) {
    if (root == nullptr) {
        return -1; 
    }
    
    Node* current = root;
    
    // Terus bergeser ke anak kiri selama anak kiri tersebut ada
    while (current->left != nullptr) {
        current = current->left;
    }
    
    return current->data;
}

int main() {
    // Membangun Tree persis seperti gambar contoh:
    //         5
    //        / \
    //       4   6
    //      /     \
    //     3       7
    //    /
    //   1

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    
    root->left->left = new Node(3);
    root->left->left->left = new Node(1); // Node paling kiri (minimum)
    
    root->right->right = new Node(7);

    // Memanggil fungsi dan mencetak hasilnya
    int min = minValue(root);
    
    cout << "Output: " << min << endl;
    cout << "Explanation: The minimum element in the given BST is " << min << "." << endl;

    return 0;
}