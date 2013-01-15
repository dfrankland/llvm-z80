//===-- Z80MCTargetDesc.h - Z80 Target Descriptions -------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Z80 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef Z80MCTARGETDESC_H
#define Z80MCTARGETDESC_H

namespace llvm {
  class MCCodeEmitter;
  class MCContext;
  class MCInstrInfo;
  class MCRegisterInfo;
  class MCSubtargetInfo;
  class Target;

  extern Target TheZ80Target;

  MCCodeEmitter *createZ80MCCodeEmitter(const MCInstrInfo &MCII,
    const MCRegisterInfo &MRI, const MCSubtargetInfo &STI, MCContext &Ctx);
} // end namespace llvm

#define GET_REGINFO_ENUM
#include "Z80GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "Z80GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "Z80GenSubtargetInfo.inc"

#endif