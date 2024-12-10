#ifndef NODE_HPP_
#define NODE_HPP_

#include <cstdint>
#include <cassert>
#include <iostream>
#include "../common.hpp"

class CallArg;

struct InterfaceNode {
    virtual ~InterfaceNode() = default;
};

struct InterfaceExpr : public InterfaceNode {};

class ChainNode : public InterfaceNode {
    const ChainNode *m_next = nullptr;

  public:
    const auto *getNext() const { return m_next; }

    void append(const ChainNode *next) {
        assert(m_next == nullptr);
        m_next = next;
    }
};


class IntVal final : public InterfaceExpr {
    int32_t m_value = 0;

  public:
    explicit IntVal(int32_t value) : m_value(value) {}

    int32_t getValue() const;
};

class StrVal final : public InterfaceExpr {
    std::string m_value{};

  public:
    explicit StrVal(std::string value) : m_value(value) {}

    const std::string &getValue() const;
};

class VarVal final : public InterfaceExpr {
    std::string m_name{};

  public:
    explicit VarVal(std::string name) : m_name(std::move(name)) {}

    const std::string &getName() const;
};

class UnOp final : public InterfaceExpr {
    UnOpKind m_kind;
    const InterfaceExpr *m_expr = nullptr;

  public:
    explicit UnOp(UnOpKind kind, const InterfaceExpr *expr)
        : m_kind(kind), m_expr(expr) {}

    UnOpKind getKind() const;
    const InterfaceExpr *getExpr() const;
};

class BinOp final : public InterfaceExpr {
    BinOpKind m_kind;
    const InterfaceExpr *m_left = nullptr;
    const InterfaceExpr *m_right = nullptr;

  public:
    BinOp(BinOpKind kind, const InterfaceExpr *left,
             const InterfaceExpr *right)
        : m_kind(kind), m_left(left), m_right(right) {}

    BinOpKind getKind() const;
    const InterfaceExpr *getLeft() const;
    const InterfaceExpr *getRight() const;
};

class Assign final : public InterfaceExpr {
    std::string m_dest{};
    const InterfaceExpr *m_expr = nullptr;

  public:
    Assign(std::string dest, const InterfaceExpr *expr)
        : m_dest(std::move(dest)), m_expr(expr) {}

    const std::string &getDest() const;
    const InterfaceExpr *getExpr() const;
};

class Call final : public InterfaceExpr {
    std::string m_callee{};
    const CallArg *m_args = nullptr;

  public:
    Call(std::string callee, const CallArg *args)
        : m_callee(std::move(callee)), m_args(args) {}

    const std::string &getCallee() const;
    const CallArg *getArgs() const;
};

class CallArg final : public ChainNode {
    const InterfaceExpr *m_expr = nullptr;

  public:
    CallArg(const InterfaceExpr *expr) : m_expr(expr) {}

    const InterfaceExpr *getExpr() const;
};

class ExprStmt final : public ChainNode {
    const InterfaceExpr *m_expr = nullptr;

  public:
    ExprStmt(const InterfaceExpr *expr) : m_expr(expr) {}

    const InterfaceExpr *getExpr() const;
};

class VarDef final : public ChainNode {
    ValType m_type;
    std::string m_name{};
    const InterfaceExpr *m_expr = nullptr;

  public:
    VarDef(ValType type, std::string name, const InterfaceExpr *expr)
        : m_type(type), m_name(std::move(name)), m_expr(expr) {}

    ValType getType() const;
    const std::string &getName() const;
    const InterfaceExpr *getExpr() const;
};

class If final : public ChainNode {
    const InterfaceNode *m_expr = nullptr;
    const ChainNode *m_statements = nullptr;

  public:
    If(const InterfaceNode *expr, const ChainNode *statements)
        : m_expr(expr), m_statements(statements) {}

    const InterfaceNode *getExpr() const;
    const ChainNode *getStatements() const;
};

class While final : public ChainNode {
    const InterfaceExpr *m_expr = nullptr;
    const ChainNode *m_statements = nullptr;

  public:
    While(const InterfaceExpr *expr, const ChainNode *statements)
        : m_expr(expr), m_statements(statements) {}

    const InterfaceExpr *getExpr() const;
    const ChainNode *getStatements() const;
};

class Return final : public ChainNode {
    const InterfaceExpr *m_expr = nullptr;

  public:
    Return(const InterfaceExpr *expr) : m_expr(expr) {}

    const InterfaceExpr *getExpr() const;
};

class FuncArg final : public ChainNode {
    ValType m_type;
    std::string m_name{};

  public:
    FuncArg(ValType type, std::string name)
        : m_type(type), m_name(std::move(name)) {}

    ValType getType() const;
    const std::string &getName() const;

    const FuncArg *getNext() const;
};

class FuncDef final : public ChainNode {
    ValType m_ret_type;
    std::string m_name{};
    const FuncArg *m_args = nullptr;
    const ChainNode *m_body = nullptr;

  public:
    FuncDef(ValType ret_type, std::string name, const FuncArg *args,
            const ChainNode *body)
        : m_ret_type(ret_type), m_name(std::move(name)), m_args(args),
          m_body(body) {}

    ValType getRetType() const;
    const std::string &getName() const;
    const FuncArg *getArgs() const;
    const ChainNode *getBody() const;
};

#endif // NODE_H_