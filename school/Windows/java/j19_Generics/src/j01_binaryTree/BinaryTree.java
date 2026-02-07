package j01_binaryTree;

// Binärbaumklasse
public class BinaryTree<T extends Number & Comparable<T>> {
    private TreeNode<T> root;

    public BinaryTree() {
        root = null;
    }

    // Methode zum Einfügen eines neuen Schlüssels
    public void insert(T key) {
        root = insertRec(root, key);
    }

    // Rekursive Einfügefunktion
    private TreeNode<T> insertRec(TreeNode<T> root, T key) {
        if (root == null) {
            return new TreeNode<>(key);
        }

        int cmp = key.compareTo(root.key);
        if (cmp < 0) {
            root.left = insertRec(root.left, key);
        } else if (cmp > 0) {
            root.right = insertRec(root.right, key);
        }
        // Bei cmp == 0 (Duplikat) keine Aktion
        return root;
    }

    // Methode zur Suche eines Schlüssels
    public boolean search(T key) {
        return searchRec(root, key);
    }

    // Rekursive Suchfunktion
    private boolean searchRec(TreeNode<T> root, T key) {
        if (root == null) return false;
        int cmp = key.compareTo(root.key);
        if (cmp == 0) {
            return true;
        } else if (cmp < 0) {
            return searchRec(root.left, key);
        } else {
            return searchRec(root.right, key);
        }
    }

    // In-Order Traversierung (sortierte Ausgabe)
    public void inorder() {
        inorderRec(root);
        System.out.println();
    }

    private void inorderRec(TreeNode<T> root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }




    // Hauptmethode zum Testen
    public static void main(String[] args) {
        BinaryTree<Double> tree = new BinaryTree<>();

        tree.insert(50.0);
        tree.insert(30.0);
        tree.insert(20.0);
        tree.insert(40.0);
        tree.insert(70.0);
        tree.insert(60.0);
        tree.insert(80.0);

        System.out.println("In-Order Traversierung des Baumes:");
        tree.inorder();

        double keyToFind = 60.0;
        System.out.println("Ist " + keyToFind + " im Baum? " + tree.search(keyToFind));
    }
}

