#pragma once
//*******************************************************
// Purpose: Class for a emitting an assembly statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 4/11/2015
//
//*******************************************************

#include <string>

#include "cExpr.h"
#include "cStmt.h"
#include "cStmtsList.h"
#include "cParams.h"
#include "cStringLit.h"

class cAsmNode : public cExpr
{
  public:
    cAsmNode(cStringLit *code, cParams *params) : cExpr()
    {
        mOp = code->GetString();
        mCode2 = 0;
        AddChild(params);
        mTwoWord = false;
    }

    cAsmNode(cStringLit *code, int code2, cParams *params) : cExpr()
    {
        mOp = code->GetString();
        mCode2 = code2;
        AddChild(params);
        mTwoWord = true;
    }

    virtual bool IsAsm() { return true; }

    virtual cTypeDecl *GetType()
    {
        fatal_error("Illegal to call GetType on cAsmNode");
        return NULL;
    }

    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    int GetOp2()            { return mCode2; }
    bool UsesTwoArgs()      { return mTwoWord; }
    cParams* GetParams()    { return (cParams*)GetChild(0); }
    string GetOp1String()   { return mOp; }

  protected:
    string mOp;             // the opcode as a string
    int mCode2;             // 2nd opcode for 2 word instructions
    bool mTwoWord;          // true of 2 word instruction
};

