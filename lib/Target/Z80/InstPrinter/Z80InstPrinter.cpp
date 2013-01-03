//===-- Z80InstPrinter.cpp - Convert Z80 MCInst to assembly syntax --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints an Z80 MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "Z80InstPrinter.h"
#include "Z80.h"
#include "llvm/MC/MCInst.h"
#include "llvm/Support/FormattedStream.h"
using namespace llvm;

// Include the auto-generated portion of the assembler writer
#include "Z80GenAsmWriter.inc"

void Z80InstPrinter::printInst(const MCInst *MI, raw_ostream &O,
  StringRef Annot)
{
  printInstruction(MI, O);
  printAnnotation(O, Annot);
}

void Z80InstPrinter::printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O)
{
  const MCOperand &Op = MI->getOperand(OpNo);

  if (Op.isReg())
  {
    O << getRegisterName(Op.getReg());
  }
  else if (Op.isImm())
  {
    O << Op.getImm();
  }
  else
  {
    assert(0 && "unknown operand kind in printOperand");
  }
}
