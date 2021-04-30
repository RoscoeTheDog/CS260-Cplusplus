//
// Created by admin on 4/28/2021.
//

#include "ParseTree.hpp"


ParseTree::ParseTree(const std::string &str) {
    xInput << str;

    // This is just a safety net: checks for infix expressions
    for (unsigned i = 0; i < str.length(); ++i) {
        if (str[i] == PARENTH_L ||
            str[i] == PARENTH_R) {
            throw std::invalid_argument("constructor expects post-fix expression");
        }
    }

    if (str != "") {
        exprType = POSTFIX;
        // build a tree passing in the copied string. This way we can preserve the original string in the input buffer.
        parsePostFix(str);
    }
}

bool ParseTree::xIsOperator(char c) {

    if (c == PLUS)
        return true;
    if (c == MINUS)
        return true;
    if (c == MULT)
        return true;
    if (c == DIVIDE)
        return true;
    if (c == EXPO)
        return true;
    if (c == PARENTH_L)
        return true;
    if (c == PARENTH_R)
        return true;

    return false;
}

void ParseTree::parsePostFix(std::string str) {

    if (str == "") {
        throw std::invalid_argument("cannot parse an empty string");
    }

    // "Look at each character in the string in order"
    for (unsigned i = 0; i < str.length(); ++i) {

        // "Skip if space"
        if (str[i] == SPACE)
            continue;

        // "If an operand"
        if (!xIsOperator(str[i])) {
            // "create a new node for the operand"
            Node *N = new Node(str[i]);
            // "push it on the stack"
            xStack.push_back(N);
            continue;
        }

        // "If an operator"
        if (xIsOperator(str[i])) {

            // "create a new node for the operator"
            Node *N = new Node(str[i]);

            // "pop the top of the stack and attach it on the right of the new node"
            if (!xStack.empty()) {
                N->right = xStack.back();
                N->right->head = N; // Link to parent
                xStack.pop_back();
            }

            // "pop the top of the stack and attach it on the left of the new node
            if (!xStack.empty()) {
                N->left = xStack.back();
                N->left->head = N;  // Link to parent
                xStack.pop_back();
            }

            // "push new node and its subtree on the stack"
            xStack.push_back(N);
            continue;
        }

    }

    // "If end of expression"
    // "Pop the top of the stack and save the node as root of the tree"
    xRoot = xStack.back();
    xStack.pop_back();

}

std::string ParseTree::inOrder() {
    // We don't know that a in/out/pre string has been entered prior.
    // Best to destroy and recreate the tree based on the new input.
    xDestroyTree(xRoot);

    // Rebuild tree and output string.
    parseInOrder(xInput.str());

    // xOutput buffer will contain the parsed expression in order.
    return xOutput.str();
}


std::string ParseTree::postOrder(Node * n) {

    // Ensure the stack is empty.
    if (!xStr.empty())
        xStr.clear();

    /*
     *  Recursively go through and add values to the stack from the tree.
     *  Then, pop off the stack to construct the post order.
     *  Finally-- use the xInput str to reconstruct the tree we deleted during traversal.
     */
    if (n) {
        xStr.push_back(n->value);

        if (n->left)
            postOrder(n->left);

        if (n->right)
            postOrder(n->right);

        if (n == n->head->left)
            n->head->left = nullptr;
        if (n == n->head->right)
            n->head->right = nullptr;

        if (n == xRoot){
            xRoot = nullptr;
        }

        delete n;
    }

    xOutput.str("");

    while(!xStr.empty()) {
        xOutput << xStr.back();
        xStr.pop_back();
    }























//
//
//    std::stringstream _s;
//
//    // in case of infix expression, filter parenthesis
//    for (unsigned i = 0; i < xOutput.str().length(); ++i) {
//
//        if (xOutput.str()[i] != PARENTH_L &&
//            xOutput.str()[i] != PARENTH_R) {
//            _s << xOutput.str()[i];
//        }
//    }
//
//    /*
//     *  return the filtered string.
//     *  do not overwrite the member
//     *  if it was initially parsed as inOrder, we should keep it that way
//     */
//    return _s.str();
}

std::string ParseTree::preOrder() {
    return xOutput.str();
}

void ParseTree::parseInOrder(std::string str) {

    // Check invalid args
    if (str == "") {
        throw std::invalid_argument("Cannot parse empty string");
    }
    // If nothing was past to the constructor prior, save the passed in argument
    if (xInput.str() == "")
        xInput << str;

    exprType = INFIX

    // Ensure the output buffer is empty for use.
    xOutput.str("");

    // Iterate through all characters.
    for (unsigned i = 0; i < str.length(); ++i) {

        // if space, continue.
        if (str[i] == SPACE)
            continue;

        // "if operand.. add to output string
        if (!xIsOperator(str[i])) {
            xOutput << str[i];
            continue;
        }

        // "if L paren.."
        if (str[i] == PARENTH_L){
            // "push on the stack"
            xStr.push_back(str[i]);
            continue;
        }

        // "if R paren.."
        if (str[i] == PARENTH_R) {

            // "pop top item (continue until get L paren)"
            while (!xStr.empty()) {

                char xChar = xStr.back(); // Note: back() returns but does not pop!

                // "if L paren, push back on stack, stop popping"
                if (xChar != PARENTH_L) {
                    xOutput << xChar;
                    xStr.pop_back(); // removes the actual item
                    continue;
                }
                else {
                    // else discard and end popping
                    xStr.pop_back();
                    break;
                }
            }
            continue;
        }

        // "if operator..."
        if (xIsOperator(str[i])) {

            while (!xStr.empty()) {

                char xChar = xStr.back(); // Note: back() returns but does not pop!

                // "if L paren, push back on stack, stop popping"
                if (xChar == PARENTH_L) {
                    break;
                }

                // "if not operator with higher precedence, push back on stack,
                //  stop popping"
                if (xOperatorPriority(xChar) < xOperatorPriority(str[i]))
                    break;
                else {
                    xOutput << xChar;
                    xStr.pop_back();
                    continue;
                }

            }
            // "push operator"
            xStr.push_back(str[i]);
        }

    }

    // "At end of expression, pop and add to buffer"
    while (!xStr.empty()) {
        xOutput << xStr.back();
        xStr.pop_back();
    }

    // Invoke parser method to build postfix tree.
    parsePostFix(xOutput.str());

}

ParseTree::~ParseTree() {
    // helper function. recursively destroys nodes.
    xDestroyTree(xRoot);
}

void ParseTree::xDestroyTree(Node *n) {

    // traverse left
    if (n->left)
        return xDestroyTree(n->left);

    // traverse right
    if (n->right)
        return xDestroyTree(n->right);

    // if root set null
    if (n == xRoot)
        xRoot = nullptr;
    else {
        if (n->head->left == n)
            n->head->left = nullptr;
        if (n->head->right == n)
            n->head->right = nullptr;
    }

    // If we are at a leaf, delete it.
    delete n;

    // If root still exists, continue traversing
    if (xRoot)
        return xDestroyTree(xRoot);
    // otherwise, everything is deleted
}