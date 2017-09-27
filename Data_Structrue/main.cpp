#include "link_list_circular_cpp.h"

int main() {
	LinkedList<int> linkedlist;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		Node<int> *node = new Node<int>(i);
		linkedlist.insert(node, i - 1);
	}
	linkedlist.output_josephus(m);
	return 0;
}