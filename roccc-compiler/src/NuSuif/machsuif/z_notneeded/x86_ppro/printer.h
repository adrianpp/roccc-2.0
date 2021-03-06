/* file "x86_ppro/printer.h" */

/*
    Copyright (c) 2000 The President and Fellows of Harvard College

    All rights reserved.

    This software is provided under the terms described in
    the "machine/copyright.h" include file.
*/

#ifndef X86_PPRO_PRINTER_H
#define X86_PPRO_PRINTER_H

#include <machine/copyright.h>

#ifdef USE_PRAGMA_INTERFACE
#pragma interface "x86_ppro/printer.h"
#endif

#include <machine/machine.h>
#include <x86/x86.h>


class PrinterX86PPro : public PrinterX86 {
  protected:
    virtual void print_instr_alm(Instr*);

  public:
    PrinterX86PPro();
};



#endif /* X86_PPRO_PRINTER_H */
