#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* node = find(key, root_);
    if(node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    auto some = Find(key);
    return some != std::nullopt;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    Node* node = find_min(root_);
    if (node != nullptr){
      return node -> value;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    Node* node = find_max(root_);
    if (node != nullptr){
      return node -> value;
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr) {
      node = new Node(key, value);
      return;
    }

    if (key == node->key) {
      node->value = value;
      return;
    }
    if (key < node->key) {
      insert(key, value, node->left);
    } else {
      insert(key, value, node->right);
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node != nullptr){
      if (key > node -> key){
        return remove(key, node -> right);
      }
      if (key < node -> key) {
        return remove(key, node->left);
      }
      if (node -> right == nullptr and node -> left == nullptr){
        delete node;
        node = nullptr;
        return true;
      }
      if (node -> right != nullptr and node -> left == nullptr){
        node = node -> right;
        return true;
      }
      if (node -> right == nullptr and node -> left != nullptr){
        node = node -> left;
        return true;
      }
      node -> key = find_min(node -> right) -> key;
      node -> value = find_min(node -> right) -> value;
      return remove(find_min(node -> right) -> key, node -> right);
      }
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node != nullptr){
      if (key == node -> key){
        return node;
      }
      if (key > node -> key){
        return find(key, node -> right);
      }
      return find(key, node -> left);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node != nullptr){
      Node* kekw = node;
      while (kekw -> left != nullptr){
        kekw = kekw -> left;
      }
      return kekw;
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node != nullptr){
      Node* kekw = node;
      while (kekw -> right != nullptr){
        kekw = kekw -> right;
      }
      return kekw;
    }
    return nullptr;
  }

}  // namespace assignment