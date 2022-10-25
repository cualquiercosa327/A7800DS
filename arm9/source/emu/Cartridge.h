// ----------------------------------------------------------------------------
//   ___  ___  ___  ___       ___  ____  ___  _  _
//  /__/ /__/ /  / /__  /__/ /__    /   /_   / |/ /
// /    / \  /__/ ___/ ___/ ___/   /   /__  /    /  emulator
//
// ----------------------------------------------------------------------------
// Copyright 2005 Greg Stanton
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
// ----------------------------------------------------------------------------
// Cartridge.h
// ----------------------------------------------------------------------------
#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <stdio.h>
#include <string.h>
#include "Equates.h"
#include "Memory.h"
#include "Hash.h"
#include "Pokey.h"

#include "shared.h"

#define MAX_CART_SIZE (1024 * 1024) // 1MB Cart is HUGE!

#define CARTRIDGE_CONTROLLER_NONE        0
#define CARTRIDGE_CONTROLLER_JOYSTICK    1
#define CARTRIDGE_CONTROLLER_LIGHTGUN    2
#define CARTRIDGE_CONTROLLER_PADDLES     3
#define CARTRIDGE_CONTROLLER_TWIN_STICKS 4
#define CARTRIDGE_CONTROLLER_SOTA        5

#define JOY             CARTRIDGE_CONTROLLER_JOYSTICK
#define LGN             CARTRIDGE_CONTROLLER_LIGHTGUN
#define PAD             CARTRIDGE_CONTROLLER_PADDLES
#define TWIN            CARTRIDGE_CONTROLLER_TWIN_STICKS
#define SOTA            CARTRIDGE_CONTROLLER_SOTA

#define CARTRIDGE_CYCLE_STEALING_MASK   0x01
#define CARTRIDGE_WSYNC_MASK            0x02

#define POKEY_NONE      0
#define POKEY_AT_4000   1
#define POKEY_AT_450    2

#define HSC_YES         true
#define HSC_NO          false

#define NTSC            0  
#define PAL             1

#define CARTRIDGE_TYPE_NORMAL           0
#define CARTRIDGE_TYPE_SUPERCART        1
#define CARTRIDGE_TYPE_SUPERCART_LARGE  2
#define CARTRIDGE_TYPE_SUPERCART_RAM    3
#define CARTRIDGE_TYPE_SUPERCART_ROM    4
#define CARTRIDGE_TYPE_ABSOLUTE         5
#define CARTRIDGE_TYPE_ACTIVISION       6
#define CARTRIDGE_TYPE_FRACTALUS        7

#define CT_NORMAL       CARTRIDGE_TYPE_NORMAL
#define CT_SUPCAR       CARTRIDGE_TYPE_SUPERCART
#define CT_SUPLRG       CARTRIDGE_TYPE_SUPERCART_LARGE
#define CT_SUPRAM       CARTRIDGE_TYPE_SUPERCART_RAM
#define CT_SUPROM       CARTRIDGE_TYPE_SUPERCART_ROM
#define CT_ABSOLU       CARTRIDGE_TYPE_ABSOLUTE
#define CT_ACTVIS       CARTRIDGE_TYPE_ACTIVISION
#define CT_FRACTALUS    CARTRIDGE_TYPE_FRACTALUS

#define STEAL_CYCLE     true
#define NO_STEALING     false
#define USES_WSYNC      true
#define SKIP_WSYNC      false


extern bool cartridge_Load(char* filename);
extern void cartridge_Store( );
extern void cartridge_StoreBank(byte bank);
extern void cartridge_Write(word address, byte data);
extern bool cartridge_IsLoaded( );
extern void cartridge_Release( );
extern char cartridge_title[128];
extern char cartridge_description[128];
extern byte cartridge_digest[128];
extern char cartridge_filename[128];

#endif
