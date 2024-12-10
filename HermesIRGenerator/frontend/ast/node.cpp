#include "node.hpp"

int32_t IntVal::getValue() const { 
    return m_value; 
}

const std::string &StrVal::getValue() const { 
    return m_value; 
}

const std::string &VarVal::getName() const { 
    return m_name; 
}

UnOpKind UnOp::getKind() const { 
    return m_kind; 
}
const InterfaceExpr *UnOp::getExpr() const { 
    return m_expr; 
}

BinOpKind BinOp::getKind() const { 
    return m_kind; 
}
const InterfaceExpr *BinOp::getLeft() const { 
    return m_left; 
}
const InterfaceExpr *BinOp::getRight() const { 
    return m_right; 
}

const std::string &Assign::getDest() const { 
    return m_dest; 
}
const InterfaceExpr *Assign::getExpr() const { 
    return m_expr; 
}

const std::string &Call::getCallee() const { 
    return m_callee; 
}
const CallArg *Call::getArgs() const { 
    return m_args; 
}

const InterfaceExpr *CallArg::getExpr() const { 
    return m_expr; 
}

const InterfaceExpr *ExprStmt::getExpr() const { 
    return m_expr; 
}

ValType VarDef::getType() const { 
    return m_type; 
}
const std::string &VarDef::getName() const { 
    return m_name; 
}
const InterfaceExpr *VarDef::getExpr() const { 
    return m_expr; 
}

const InterfaceNode *If::getExpr() const { 
    return m_expr; 
}
const ChainNode *If::getStatements() const {
    return m_statements;
}

const InterfaceExpr *While::getExpr() const { 
    return m_expr; 
}
const ChainNode *While::getStatements() const {
    return m_statements;
}

const InterfaceExpr *Return::getExpr() const { 
    return m_expr; 
}

ValType FuncArg::getType() const { 
    return m_type; 
}
const std::string &FuncArg::getName() const { 
    return m_name; 
}
const FuncArg *FuncArg::getNext() const {
    return dynamic_cast<const FuncArg *>(ChainNode::getNext());
}

ValType FuncDef::getRetType() const { 
    return m_ret_type; 
}
const std::string &FuncDef::getName() const { 
    return m_name; 
}
const FuncArg *FuncDef::getArgs() const { 
    return m_args; 
}
const ChainNode *FuncDef::getBody() const { 
    return m_body; 
}