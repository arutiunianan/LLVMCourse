#ifndef AST_HPP_
#define AST_HPP_

#include <memory>
#include <vector>

#include "node.hpp"

using INode     = InterfaceNode;
using INodeUPtr = std::unique_ptr<INode>;

struct AST {
    std::vector<INodeUPtr> m_ast_nodes{};

    const INode *m_ast_root;
};

#endif // AST_HPP_
