// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// Print contents of room
void princr(Bool full, int rm) {
// System generated locals
   int i__1, i__2;

// Local variables
   int i, j, k;

// PRINCR, PAGE 2

   j = 329;
// 						!ASSUME SUPERBRIEF FORMAT.
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP ON OBJECTS
      if (!qhere(i, rm) || (objcts_1.oflag1[i - 1] & VisiO + NDscO) != VisiO || i == advs_1.avehic[play_1.winner - 1]) {
         goto L500;
      }
      if (!(full) && (findex_1.superf || findex_1.brieff && (rooms_1.rflag[play_1.here - 1] & SeenR) != 0)) {
         goto L200;
      }

   // DO LONG DESCRIPTION OF OBJECT.

      k = objcts_1.odesco[i - 1];
// 						!GET UNTOUCHED.
      if (k == 0 || (objcts_1.oflag2[i - 1] & TChO) != 0) {
         k = objcts_1.odesc1[i - 1];
      }
      rspeak(k);
// 						!DESCRIBE.
      goto L500;
// DO SHORT DESCRIPTION OF OBJECT.

   L200:
      rspsub(j, objcts_1.odesc2[i - 1]);
// 						!YOU CAN SEE IT.
      j = 502;

   L500:
      ;
   }

// NOW LOOP TO PRINT CONTENTS OF OBJECTS IN ROOM.

   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP ON OBJECTS.
      if (!qhere(i, rm) || (objcts_1.oflag1[i - 1] & VisiO + NDscO) != VisiO) {
         goto L1000;
      }
      if ((objcts_1.oflag2[i - 1] & ActrO) != 0) {
         i__2 = oactor(i);
         invent(i__2);
      }
      if ((objcts_1.oflag1[i - 1] & TranO) == 0 && (objcts_1.oflag2[i - 1] & OpenO) == 0 || qempty(i)) {
         goto L1000;
      }

   // OBJECT IS NOT EMPTY AND IS OPEN OR TRANSPARENT.

      j = 573;
      if (i != oindex_1.tcase) {
         goto L600;
      }
// 						!TROPHY CASE?
      j = 574;
      if ((findex_1.brieff || findex_1.superf) && !(full)) {
         goto L1000;
      }
   L600:
      princo(i, j);
// 						!PRINT CONTENTS.

   L1000:
      ;
   }
}

// Print contents of adventurer
void invent(int adv) {
// System generated locals
   int i__1;

// Local variables
   int i, j;

// INVENT, PAGE 2

   i = 575;
// 						!FIRST LINE.
   if (adv != aindex_1.player) {
      i = 576;
   }
// 						!IF NOT ME.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP
      if (objcts_1.oadv[j - 1] != adv || (objcts_1.oflag1[j - 1] & VisiO) == 0) {
         goto L10;
      }
      rspsub(i, objcts_1.odesc2[advs_1.aobj[adv - 1] - 1]);
      i = 0;
      rspsub(502, objcts_1.odesc2[j - 1]);
   L10:
      ;
   }

   if (i == 0) {
      goto L25;
   }
// 						!ANY OBJECTS?
   if (adv == aindex_1.player) {
      rspeak(578);
   }
// 						!NO, TELL HIM.
   return;

L25:
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP.
      if (objcts_1.oadv[j - 1] != adv || (objcts_1.oflag1[j - 1] & VisiO) == 0 || (objcts_1.oflag1[j - 1] & TranO) == 0 && (objcts_1.oflag2[j - 1] & OpenO) == 0) {
         goto L100;
      }
      if (!qempty(j)) {
         princo(j, 573);
      }
// 						!IF NOT EMPTY, LIST.
   L100:
      ;
   }
}

// Print contents of object
void princo(int obj, int desc) {
// System generated locals
   int i__1;

// Local variables
   int i;

   rspsub(desc, objcts_1.odesc2[obj - 1]);
// 						!PRINT HEADER.
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP THRU.
      if (objcts_1.ocan[i - 1] == obj) {
         rspsub(502, objcts_1.odesc2[i - 1]);
      }
// L100:
   }
}