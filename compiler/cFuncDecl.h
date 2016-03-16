#pragma once

#include <string>

#include "cTypeDecl.h"
#include "cStmtsList.h"
#include "cReturnStmt.h"
#include "cIntExpr.h"
#include "cSymbol.h"
#include "cDeclsList.h"
#include "codegen.h"

class cFuncDecl : public cTypeDecl
{
  public:
    cFuncDecl(cTypeDecl *type, cSymbol *name) : cTypeDecl(name, WORD_SIZE)
    {
        // FIX THIS: Semantic checks
        name->SetDecl(this);
        symbolTableRoot->Insert(name);

        AddChild(type);
        AddChild(nullptr); // params
        AddChild(nullptr); // stmts
        mHasStatements  = false;
        mDeclsSize      = 0;
    }

    void AddParams(cAstNode *params)
    {
        SetChild(2, params);
    }

    void AddStatements(cStmtsList *stmts)
    {
        SetChild(3, stmts);
        mHasStatements = true;
    }

    virtual bool IsFunc() { return true; }
    virtual bool IsType() { return false; }

    virtual std::string toString()
    {
        std::string result;
        result = "function: " + GetName()->toString();
        if (GetParams() != NULL)
            result += "( " + GetParams()->toString() + " )";
        else
            result += "( )";

        result += "\n";

        if (mHasStatements)
        {
            if (GetStmts() != NULL)
                result += GetStmts()->toString();
            else
                result += "{}";
        }
        else
        {
            result += ";";
        }

        return result;
    }

    virtual int ComputeOffsets(int base)
    {
        int locals = 0;
        if(GetParams() != NULL)  GetParams()->ComputeOffsets(-STACK_FRAME_SIZE);
        if (GetStmts() != NULL) locals = GetStmts()->ComputeOffsets(locals);
        mDeclsSize = locals;

        return base;
    }

    virtual void GenerateCode()
    {
        if (!mHasStatements) return;

        EmitComment(GetName()->Name() + "\n");
        SetLabelValue(GetName()->Name());
        int adj_size = (mDeclsSize / WORD_SIZE * WORD_SIZE) + WORD_SIZE;
        if (mDeclsSize != 0)
        {
            EmitInt(ADJSP_OP);
            EmitInt(adj_size);
        }

        GetStmts()->GenerateCode();

        // Force return statement
        cReturnStmt *ret = new cReturnStmt(new cIntExpr(0));
        ret->GenerateCode();
    }

    cTypeDecl* ReturnType()     { return (cTypeDecl*)GetChild(1); }
    cDeclsList* GetParams()     { return (cDeclsList*)GetChild(2); }
    cStmtsList* GetStmts()      { return (cStmtsList*)GetChild(3); }
  protected:
    bool mHasStatements;
    int mDeclsSize;
};

