#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int find_height(Node node) {
  if (node.children.size() == 0) {
    // at leaf node
    return 1;
  }

  int maxHeight = -1;
  for (int i=0; i<node.children.size(); ++i) {
    // for each of the children, call recursive function
    int currHeight = find_height(*(node.children[i]));
    if (currHeight > maxHeight) {
      maxHeight = currHeight;
    }
  }

  return maxHeight + 1;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  Node root;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0) {
      nodes[child_index].setParent(&nodes[parent_index]);
    }
    nodes[child_index].key = child_index;
  }

  for (int i=0; i<nodes.size(); ++i) {
    if (nodes[i].parent == NULL) {
      root = nodes[i];
    }
  }

  int height = find_height(root);
  cout << height << endl;

  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
