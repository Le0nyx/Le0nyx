package j01_binaryTree;

// Knotenklasse für den Binärbaum
class TreeNode<T> {
    T key;
    TreeNode<T> left, right;

    public TreeNode(T item) {
        key = item;
        left = right = null;
    }
}

