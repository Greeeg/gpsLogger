/*===========================================================================
     _____        _____        _____        _____
 ___|    _|__  __|_    |__  __|__   |__  __| __  |__  ______
|    \  /  | ||    \      ||     |     ||  |/ /     ||___   |
|     \/   | ||     \     ||     \     ||     \     ||___   |
|__/\__/|__|_||__|\__\  __||__|\__\  __||__|\__\  __||______|
    |_____|      |_____|      |_____|      |_____|

--[Mark3 Realtime Platform]--------------------------------------------------

Copyright (c) 2012-2015 Funkenstein Software Consulting, all rights reserved.
See license.txt for more information
===========================================================================*/
/*!

    \file   kernelswi.cpp

    \brief  Kernel Software interrupt implementation for ATMega328p

*/

#include "kerneltypes.h"
#include "kernelswi.h"
#include <msp430.h>

//---------------------------------------------------------------------------
void KernelSWI::Config(void)
{
    P2DIR &= ~0x04;
}

//---------------------------------------------------------------------------
void KernelSWI::Start(void)
{        
    P2IE |= 0x04;
}

//---------------------------------------------------------------------------
void KernelSWI::Stop(void)
{
    P2IE &= ~0x04;
}

//---------------------------------------------------------------------------
K_UCHAR KernelSWI::DI()
{
    K_UCHAR ucRet = ((P2IE & 0x04) == 0x04);
    P2IE &= ~0x04;
    return ucRet;
}

//---------------------------------------------------------------------------
void KernelSWI::RI(K_BOOL bEnable_)
{
    if (bEnable_)
    {
        P2IE |= 0x04;
    }
    else
    {
        P2IE &= ~0x04;
    }
}

//---------------------------------------------------------------------------
void KernelSWI::Clear(void)
{
    P2IFG &= ~0x04;
}

//---------------------------------------------------------------------------
void KernelSWI::Trigger(void)
{
    P2IFG |= 0x04;
}
