//
// Created by admin on 5/6/2021.
//

#include "Tree.hpp"


void Tree::insertValue(int value, Node *n) {
//	// if !root, root becomes new node. position becomes this node. return;
//	if (root == nullptr) {
//		// Create a new node, setting it's value to the passed in arg.
//		n = new Node(value);
//		root = n;
//	}
//	if (n == nullptr) {
//		return insertValue(value, root);
//	}
//
//	// if val is < position val && position->left, position = position->left, insertValue(value);  return;
//	if (n->left && value < n->value) {
//		return insertValue(value, n->left);
//	}
//
//	// if val is > position val && position->right, position = position->right, insertValue(value); return;
//	if (n->right && value > n->value) {
//		return insertValue(value, n->right);
//	}
//
//	// if val is < position val insert left, return;
//	if (value < n->value) {
//		Node *_n = new Node(value);
//		_n->head = n;
//		n->left = _n;
//	}
//
//	// if val is > position val insert right, return;
//	if (value > n->value) {
//		Node *_n = new Node(value);
//		_n->head = n;
//		n->right = _n;
//	}
;
}

bool Tree::findValue(int value, Node *n) {

//	if (!root) {
//		throw std::logic_error("Cannot find value. Tree is empty!");
//	}
//	if (n == nullptr) {
//		return findValue(value, root);
//	}
//
//	if (n->value == value) {
//
//		if (removeFound) {
//			n->value = std::nullopt;    // clear value but keep node
//			removeFound = false;        // reset flag
//		}
//
//		return true;
//	}
//
//	// if val < position->val && position->left, position = position->left, findValue(value), break;
//	if (n->left && value < n->value) {
//		return findValue(value, n->left);
//	}
//
//	// if val > position->val && position->right, position = position->right, findValue(value), break;
//	if (n->right && value > n->value) {
//		return findValue(value, n->right);
//	}
//
//	removeFound = false;
//	return false;
//
//
//	// (I'm thinking of using a context switch from deleteValue to signal to findValue whether or not to delete a found value/node.
//	// if val == position->val && private member DELETE = true, mark optional<int>(val) as nullopt && return false
//	// if val == position->val && private member DELETE = false, return true
;
}

bool Tree::deleteValue(int value) {
//	// flag node to be deleted if found. Note: if not found, flag will be reset.
//	removeFound = true;
//	return findValue(value, root);
;
}

std::string Tree::preOrder(Node *n) {

//	// for all these conditions: add a sub-check for 'deleted'
//	// Also assume these are recursive so the start over upon each true statement.
//
//	// start from root
//	if (n == nullptr) {
//		// Reset private string member upon first entry.
//		S = "";
//		return preOrder(root);
//	}
//
//	// if tail > value, go head, return;
//	if (tail && tail->value > n->value) {
//		return preOrder(n->head);
//	}
//
//	// if tail <= value, and right, go right and *continue*. return;
//	if (tail && tail->value <= n->value && n->right) {
//		n = n->right;
//	}
//
//	// if left go left, preOrder(), return;
//	if (n->left) {
//		return preOrder(n->left);
//	}
//
//	// if !left and !right, if head > current, append head, append current, go head. return;
//	if (!n->left && !n->right && n->head->value > n->value) {
//		if (n->head->DELETED) {
//			S.push_back(static_cast<char>('D'));
//		}
//		else {
//			S.push_back(static_cast<char>(*n->head->value));
//		}
//		if (n->DELETED) {
//			S.push_back(static_cast<char>('D'));
//		}
//		else {
//			S.push_back(static_cast<char>(*n->value));
//		}
//		tail = n;
//		return preOrder(n->head);
//	}
//
//	// if !left and !right, if head < current, append current, go head. return;
//	if (!n->left && !n->right && n->head->value < n->value) {
//		if (n->DELETED) {
//			S.push_back(static_cast<char>('D'));
//		}
//		else {
//			S.push_back(static_cast<char>(*n->value));
//		}
//		tail = n;
//		return preOrder(n->head);
//	}
//
//	// if traversing right and no left branches, then make sure we are furthest right in the tree (greatest value).
//	if (n->right) {     // This second 'if right' is neccessary since the first one makes sure left branches of right subtree are not skipped.
//		return preOrder(n->right);
//	}
//
//	// if head null, return string and exit.
//	if (n->head == nullptr) {
//		tail = nullptr;     // clear 'tail' placeholder
//	}
//
//	return S;
;

}

std::string Tree::inOrder(Node *n) {
//	// for all these conditions: add a sub-check for 'deleted'
//	// Also assume these are recursive so the start over upon each true statement.
//
//	if (n == nullptr) {
//		// Reset private string member upon first entry.
//		S = "";
//		return inOrder(root);
//	}
//
//	// bring us to the left most leaf
//	if (!tail && n->left) {
//		return inOrder(n->left);
//	}
//	// once there, push, update tail, and go to head
//	if (!tail && !n->left) {
//		if (removeFound) {
//			n->DELETED = true;
//		}
//		if (n->DELETED) {
//			S.push_back(static_cast<char>('D'));
//		}
//		else {
//			S.push_back(static_cast<char>(*n->value));
//		}
//		tail = n;
//		return inOrder(n->head);
//	}
//		// So long as 'tail' is initialized... this becomes the rest of the algorithm.
//	else {
//		// if left and tail < left, go left
//		if (n->left && tail->value < n->left->value) {
//			return inOrder(n->left);
//		}
//
//		// if tail < current, append current, update tail
//		if (tail->value < n->value) {
//			if (removeFound) {
//				n->DELETED = true;
//			}
//			if (n->DELETED) {
//				S.push_back(static_cast<char>('D'));
//			}
//			else {
//				S.push_back(static_cast<char>(*n->value));
//			}
//			tail = n;
//			// this should be a either left leaf or parent, so we need to check right before first traversing up
//			return inOrder(n);
//		}
//
//		// if right, and tail < right, go right
//		if (n->right && tail->value < n->right->value) {
//			return inOrder(n->right);
//		}
//
//		// if not left and not right, append and go head. update tail
//		if (!n->left && !n->right &&
//		    n->value != tail->value) {
//			if (removeFound) {
//				n->DELETED = true;
//			}
//			if (n->DELETED) {
//				S.push_back(static_cast<char>('D'));
//			}
//			else {
//				S.push_back(static_cast<char>(*n->value));
//			}
//			tail = n;
//			return inOrder(n->head);
//		}
//
//		// if node is greater than tail, and left current and right have been traversed already, then begin climbing up.
//		if (n->value < tail->value) {
//			return inOrder(n->head);
//		}
//
//		tail = nullptr;
//		// Exit if we have hit the highest value node (furthest right).
//		return S;
//	}
;


}

std::string Tree::postOrder(Node *n) {

//	// for all these conditions: add a sub-check for 'deleted'
//	// Also assume these are recursive so the start over upon each true statement.
//
//	if (n == nullptr) {
//		S = "";
//		return postOrder(root);
//	}
//	// bring us to the left most leaf
//	if (!tail && n->left) {
//		return postOrder(n->left);
//	}
//	// once there, push, update tail, and go to head
//	if (!tail && !n->left) {
//
//		if (n->head->DELETED) {
//			S.push_back(static_cast<char>('D'));
//		}
//		else {
//			S.push_back(static_cast<char>(*n->value));
//		}
//		tail = n;
//		return postOrder(n->head);
//	}
//	else {
//
//		if (n->left && n->left->value > tail->value) {
//			return postOrder(n->left);
//		}
//
//		// if current > tail and right exists, go right
//		if (n->value > tail->value && n->right) {
//			return postOrder(n->right);
//		}
//
//		// if not left and not right, append current, update tail, go to head
//		if (!n->left && !n->right) {
//			tail = n;
//			if (n->DELETED) {
//				S.push_back(static_cast<char>('D'));
//			}
//			else {
//				S.push_back(static_cast<char>(*n->value));
//			}
//			return postOrder(n);
//		}
//
//		// if current < tail, append current, update tail, go head
//		if (n->value < tail->value) {
//			tail = n;
//			S.push_back(static_cast<char>(*n->value));
//			return postOrder(n);
//		}
//
//		// if current < tail, append current, update tail, go head
//		if (n->value > tail->value) {
//			tail = n;
//			S.push_back(static_cast<char>(*n->value));
//			return postOrder(n);
//		}
//
//		// if current is tail, go head
//		if (n == tail && n->head) {
//			return postOrder(n->head);
//		}
//
//		// if head nullptr, tail becomes root, return string and exit
//		if (n->head == nullptr) {
//			tail = nullptr;
//
//		}
//
//		return S;
//	}
;

}

std::optional<int> Tree::findLarger(int val, Node *n) {

//	if (n == nullptr) {
//		return findLarger(val, root);
//	}
//
//	// if val < current, and left exists, go left, update tail
//	if ( n->left && val < n->value) {
//		tail = n;
//		return findLarger(val, n->left);
//	}
//
//	// if val > current, and left exists, go right, update tail
//	if (n->left && n->value < val) {
//		tail = n;
//		return findLarger(val, n->right);
//	}
//
//	// if not val >= current, and tail > val, return tail
//	if (!n->value <= val && val > tail->value) {
//
//		if (removeFound) {
//			tail->DELETED = true;
//		}
//
//		return *tail->value;
//	}
//
//	return false;
;
}

std::optional<int> Tree::deleteLarger(int val) {

//	// call findLarger, (node position is saved in member space)
//	this->removeFound = true;
//	return findLarger(val);
;
}

bool Tree::deleteNodeInOrder() {
//	// enable flag when entering inOrder
//	this->removeFound = true;
//	inOrder();
//	// disable flag when exiting inOrder
//	this->removeFound = false;
//
//	return true;
;
}