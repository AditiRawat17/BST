using System;
using System.Collections.Generic;
 
 
public class GFG {
  public static void Main(String[] args) {
    BST tree = new BST();
    tree.insert(30);
    tree.insert(50);
    tree.insert(15);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(60);
    tree.inorder();
  }
}
 
public class Node {
  public Node left;
  public int val;
  public Node right;
 
  public Node(int val) {
    this.val = val;
  }
}
 
public class BST {
  public Node root;
 
  public void insert(int key) {
    Node node = new Node(key);
    if (root == null) {
      root = node;
      return;
    }
    Node prev = null;
    Node temp = root;
    while (temp != null) {
      if (temp.val > key) {
        prev = temp;
        temp = temp.left;
      } else if (temp.val < key) {
        prev = temp;
        temp = temp.right;
      }
    }
    if (prev.val > key)
      prev.left = node;
    else
      prev.right = node;
  }
 
  public void inorder() {
    Node temp = root;
    Stack<Node> stack = new Stack<Node>();
    while (temp != null || stack.Count!=0) {
      if (temp != null) {
        stack.Push(temp);
        temp = temp.left;
      } else {
        temp = stack.Pop();
        Console.Write(temp.val + " ");
        temp = temp.right;
      }
    }
  }
}
