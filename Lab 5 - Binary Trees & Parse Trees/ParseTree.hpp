//
// Created by admin on 4/28/2021.
//

#ifndef LAB_5___BINARY_TREES___PARSE_TREES_PARSETREE_HPP
#define LAB_5___BINARY_TREES___PARSE_TREES_PARSETREE_HPP

#include "Node.hpp"
#include "OperatorTypes.hpp"
#include <locale>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class ParseTree {
private:
	typedef enum {
		START = 0,
		PREFIX,
		INFIX,
		POSTFIX,
	} expression_t;

	Node *xRoot = nullptr;
	std::stringstream xInput;
	std::stringstream xOutput;
	std::deque<Node *> xStack;
	std::deque<std::optional<char>> xStr;
	expression_t exprType = START;

	/*
		checks macro to determine type attribute.
		better than using local.h due to limited support of encoded char types
		(I considered both ways).
	*/
	static bool xIsOperator(char c);

	// Helper destructor method.
	// Traverses through nodes and deletes them recursively
	void vDestroyTree(Node *n = nullptr);

	// Helper that builds the tree using whatever is stored in xInput.
	// Useful for reconstructing the tree after it has been parsed into an
	// expression.
	bool vConstructTree();

	// Helper that erases the contents of the output stream.
	// It does NOT clear flags like in the normal STD library.
	void vClearOutStream();

	// Helper that erases the contents of the input stream.
	// It does NOT clear flags like in the normal STD library.
	void vClearInStream();

	// Builds the container stack in prefix notation. It can then be popped and
	// returned by ParseTree::preOrder();
	void vBuildStackPreorder(Node *n = nullptr);

	// Builds the container stack in postOrder notation. It can then be popped and
	// returned by ParseTree::postOrder();
	void vBuildStackPostorder(Node *n = nullptr);

	// Builds the container stack in inOrder notation. This can then be popped and
	// returned by ParseTree::inOrder();
	void vBuildStackInorder(Node *n = nullptr);

	// Returns the input string as as simplified inOrder expression (parenthesis need-only basis)
	void vBuildStackInorderSimple(Node *n = nullptr);

	// Sets xOutput to a postFix expression from a stored xInput infix expression
	void vStrInfixToPostfix(Node *n = nullptr);

public:
	explicit ParseTree(const std::string &str = "");

	~ParseTree();

	// Returns the input expression as preOrder expression.
	std::string preOrder();

	// Returns the input expression as inOrder expression.
	std::string inOrder(bool simplified = false);

	// Returns the input string as a postOrder expression.
	std::string postOrder();

	// Note: 'parser' methods build trees, for this lab in general.
	void parseInOrder(std::string str = "");

	// Note: 'parser' methods build trees, for this lab in general.
	void parsePostFix(std::string str = "");
};

#endif // LAB_5___BINARY_TREES___PARSE_TREES_PARSETREE_HPP
