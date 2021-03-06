/* file "x86_ppro/init.cpp" */

/*
    Copyright (c) 2000 The President and Fellows of Harvard College

    All rights reserved.

    This software is provided under the terms described in
    the "machine/copyright.h" include file.
*/

#include <machine/copyright.h>

#ifdef USE_PRAGMA_INTERFACE
#pragma implementation "x86_ppro/init.h"
#endif

#include <machine/machine.h>
#include <suifvm/suifvm.h>
#include <x86/x86.h>

#include <x86_ppro/contexts.h>
#include <x86_ppro/opcodes.h>
#include <x86_ppro/init.h>

#ifdef USE_DMALLOC
#include <dmalloc.h>
#define new D_NEW
#endif

IdString k_x86_ppro;

Context*
context_creator_x86_ppro()
{
    return new X86PProContext;
}

extern "C" void
init_x86_ppro(SuifEnv *suif_env)
{
    static bool init_done = false;

    if (init_done)
        return;
    init_done = true;

    init_machine(suif_env);
    init_suifvm(suif_env);
    init_x86(suif_env);

    k_x86_ppro = "x86_ppro";

    // initializations for opcode-indexed tables
    init_x86_ppro_opcode_names();
    init_x86_ppro_invert_table();

    the_context_creator_registry[k_x86_ppro] = context_creator_x86_ppro;
}
