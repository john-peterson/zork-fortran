// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

// Is global actually in this room?
bool ghere(int obj, int rm) {
// System generated locals
   bool ret_val;

// GHERE, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   switch (obj - star.strbit) {
      case 1:
         goto L1000;
      case 2:
         goto L1000;
      case 3:
         goto L1000;
      case 4:
         goto L1000;
      case 5:
         goto L1000;
      case 6:
         goto L1000;
      case 7:
         goto L1000;
      case 8:
         goto L1000;
      case 9:
         goto L1000;
      case 10:
         goto L1000;
      case 11:
         goto L1000;
      case 12:
         goto L2000;
      case 13:
         goto L3000;
      case 14:
         goto L4000;
      case 15:
         goto L5000;
      case 16:
         goto L5000;
      case 17:
         goto L5000;
      case 18:
         goto L6000;
      case 19:
         goto L7000;
      case 20:
         goto L8000;
      case 21:
         goto L9000;
      case 22:
         goto L9100;
      case 23:
         goto L8000;
      case 24:
         goto L10000;
      case 25:
         goto L11000;
   }
   bug(60, obj);

// 1000--	STARS ARE ALWAYS HERE

L1000:
   return ret_val;

// 2000--	BIRD

L2000:
   ret_val = rm >= Fore1RX && rm < ClearRX || rm == MTreeRX;
   return ret_val;

// 3000--	TREE

L3000:
   ret_val = rm >= Fore1RX && rm < ClearRX && rm != Fore3RX;
   return ret_val;

// 4000--	NORTH WALL

L4000:
   ret_val = rm >= BkVwRX && rm <= BkBoxRX || rm == CPuzzRX;
   return ret_val;

// 5000--	EAST, SOUTH, WEST WALLS

L5000:
   ret_val = rm >= BkVwRX && rm < BkBoxRX || rm == CPuzzRX;
   return ret_val;

// 6000--	GLOBAL WATER

L6000:
   ret_val = (rooms.rflag[rm - 1] & WaterR + FillR) != 0;
   return ret_val;

// 7000--	GLOBAL GUARDIANS

L7000:
   ret_val = rm >= MrCrX && rm <= MrDrX || rm >= MrCerX && rm <= MrDwrX || rm == InMirRX;
   return ret_val;

// 8000--	ROSE/CHANNEL

L8000:
   ret_val = rm >= MrArX && rm <= MrDrX || rm == InMirRX;
   return ret_val;

// 9000--	MIRROR
// 9100		PANEL

L9100:
   if (rm == FDoorRX) {
      return ret_val;
   }
// 						!PANEL AT FDOOR.
L9000:
   ret_val = rm >= MrArX && rm <= MrCrX || rm >= MrAerX && rm <= MrCwrX;
   return ret_val;

// 10000--	MASTER

L10000:
   ret_val = rm == FDoorRX || rm == NCorrRX || rm == ParapRX || rm == CellRX;
   return ret_val;

// 11000--	LADDER

L11000:
   ret_val = rm == CPuzzRX;
   return ret_val;
}

// Is mirror here?
int mrhere(int rm) {
// System generated locals
   int ret_val, i__1;

// MRHERE, PAGE 2

   if (rm < MrAerX || rm > MrDwrX) {
      goto L100;
   }

// RM IS AN E-W ROOM, MIRROR MUST BE N-S (MDIR= 0 OR 180)

   ret_val = 1;
// 						!ASSUME MIRROR 1 HERE.
   if ((rm - MrAerX) % 2 == findex_1.mdir / 180) {
      ret_val = 2;
   }
   return ret_val;

// RM IS NORTH OR SOUTH OF MIRROR.  IF MIRROR IS N-S OR NOT
// WITHIN ONE ROOM OF RM, LOSE.

L100:
   ret_val = 0;
   if ((i__1 = findex_1.mloc - rm, abs(i__1)) != 1 || findex_1.mdir % 180 == 0) {
      return ret_val;
   }

// RM IS WITHIN ONE OF MLOC, AND MDIR IS E-W

   ret_val = 1;
   if (rm < findex_1.mloc && findex_1.mdir < 180 || rm > findex_1.mloc && findex_1.mdir > 180) {
      ret_val = 2;
   }
   return ret_val;
}
