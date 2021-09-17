#include "F2C.h"
#include "parse.h"

// gamestat.h:

// GAME STATE

extern struct {
   int winner, here;
   Bool telflg;
} play_;
#define play_1 play_

// star.h: (Unlisted)
extern struct {
   int mbase, strbit;
} star_;
#define star_1 star_

// debug.h:

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;
#define debug_1 debug_

// objects.h:

// OBJECTS

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;
#define objcts_1 objcts_
#define eqo ((int *)&objcts_1 + 1)

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;
#define oroom2_1 oroom2_

// oflags.h:

extern struct oflags_1_ {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;
#define oflags_1 oflags_

// advers.h:

// ADVENTURERS

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;
#define advs_1 advs_
#define eqa ((int *)&advs_1 + 1)

extern struct aflags_1_ {
   int astag;
} aflags_;
#define aflags_1 aflags_

extern struct aindex_1_ {
   int player, arobot, amastr;
} aindex_;
#define aindex_1 aindex_

// GETOBJ--	FIND OBJ DESCRIBED BY ADJ, NAME PAIR

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS
static Bool thisit_(int, int, int, int);

// THIS ROUTINE DETAILS ON BIT 3 OF PRSFLG

int getobj_(int oidx, int aidx, int spcobj) {
// System generated locals
   int ret_val, i__1;

// Local variables
   static int i__, av;
   static int obj;
   extern Bool lit_(int);
   static int nobj;
   extern Bool ghere_(int, int);
   static Bool chomp;
   extern int schlst_(int, int, int, int, int, int);

// MISCELLANEOUS VARIABLES

// GETOBJ, PAGE 2

// D	DFLAG=IAND(PRSFLG, 8).NE.0

   chomp = false;
   av = advs_1.avehic[play_1.winner - 1];
   obj = 0;
// 						!ASSUME DARK.
   if (!lit_(play_1.here)) {
      goto L200;
   }
// 						!LIT?

   obj = schlst_(oidx, aidx, play_1.here, 0, 0, spcobj);
// 						!SEARCH ROOM.
// D	IF(DFLAG) PRINT 10,OBJ
// D10	FORMAT(' SCHLST- ROOM SCH ',I6)
   if (obj < 0) {
      goto L1000;
   } else if (obj == 0) {
      goto L200;
   } else {
      goto L100;
   }
// 						!TEST RESULT.
L100:
   if (av == 0 || av == obj || (objcts_1.oflag2[obj - 1] & oflags_1.findbt) != 0) {
      goto L200;
   }
   if (objcts_1.ocan[obj - 1] == av) {
      goto L200;
   }
// 						!TEST IF REACHABLE.
   chomp = true;
// 						!PROBABLY NOT.

L200:
   if (av == 0) {
      goto L400;
   }
// 						!IN VEHICLE?
   nobj = schlst_(oidx, aidx, 0, av, 0, spcobj);
// 						!SEARCH VEHICLE.
// D	IF(DFLAG) PRINT 20,NOBJ
// D20	FORMAT(' SCHLST- VEH SCH  ',I6)
   if (nobj < 0) {
      goto L1100;
   } else if (nobj == 0) {
      goto L400;
   } else {
      goto L300;
   }
// 						!TEST RESULT.
L300:
   chomp = false;
// 						!REACHABLE.
   if (obj == nobj) {
      goto L400;
   }
// 						!SAME AS BEFORE?
   if (obj != 0) {
      nobj = -nobj;
   }
// 						!AMB RESULT?
   obj = nobj;

L400:
   nobj = schlst_(oidx, aidx, 0, 0, play_1.winner, spcobj);
// 						!SEARCH ADVENTURER.
// D	IF(DFLAG) PRINT 30,NOBJ
// D30	FORMAT(' SCHLST- ADV SCH  ',I6)
   if (nobj < 0) {
      goto L1100;
   } else if (nobj == 0) {
      goto L600;
   } else {
      goto L500;
   }
// 						!TEST RESULT
L500:
   if (obj != 0) {
      nobj = -nobj;
   }
// 						!AMB RESULT?
L1100:
   obj = nobj;
// 						!RETURN NEW OBJECT.
L600:
   if (chomp) {
      obj = -10000;
   }
// 						!UNREACHABLE.
L1000:
   ret_val = obj;

   if (ret_val != 0) {
      goto L1500;
   }
// 						!GOT SOMETHING?
   i__1 = objcts_1.olnt;
   for (i__ = star_1.strbit + 1; i__ <= i__1; ++i__) {
// 						!NO, SEARCH GLOBALS.
      if (!thisit_(oidx, aidx, i__, spcobj)) {
         goto L1200;
      }
      if (!ghere_(i__, play_1.here)) {
         goto L1200;
      }
// 						!CAN IT BE HERE?
      if (ret_val != 0) {
         ret_val = -i__;
      }
// 						!AMB MATCH?
      if (ret_val == 0) {
         ret_val = i__;
      }
   L1200:
      ;
   }

L1500:
// 						!END OF SEARCH.
// D	IF(DFLAG) PRINT 40,GETOBJ
// D40	FORMAT(' SCHLST- RESULT   ',I6)
   return ret_val;
}

// SCHLST--	SEARCH FOR OBJECT

// DECLARATIONS
static Bool thisit_(int, int, int, int);

int schlst_(int oidx, int aidx, int rm, int cn, int ad, int spcobj) {
// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   static int i__, j, x;
   extern Bool qhere_(int, int);

// FUNCTIONS AND DATA

   ret_val = 0;
// 						!NO RESULT.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!SEARCH OBJECTS.
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.visibt) == 0 || (rm == 0 || !qhere_(i__, rm)) && (cn == 0 || objcts_1.ocan[i__ - 1] != cn) && (ad == 0 || objcts_1.oadv[i__ - 1] != ad)) {
         goto L1000;
      }
      if (!thisit_(oidx, aidx, i__, spcobj)) {
         goto L200;
      }
      if (ret_val != 0) {
         goto L2000;
      }
// 						!GOT ONE ALREADY?
      ret_val = i__;
// 						!NO.

// IF OPEN OR TRANSPARENT, SEARCH THE OBJECT ITSELF.

   L200:
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0) {
         goto L1000;
      }

// SEARCH IS CONDUCTED IN REVERSE.  ALL OBJECTS ARE CHECKED TO
// SEE IF THEY ARE AT SOME LEVEL OF CONTAINMENT INSIDE OBJECT 'I'.
// IF THEY ARE AT LEVEL 1, OR IF ALL LINKS IN THE CONTAINMENT
// CHAIN ARE OPEN, VISIBLE, AND HAVE SEARCHME SET, THEY CAN QUALIFY
// AS A POTENTIAL MATCH.

      i__2 = objcts_1.olnt;
      for (j = 1; j <= i__2; ++j) {
// 						!SEARCH OBJECTS.
         if ((objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0 || !thisit_(oidx, aidx, j, spcobj)) {
            goto L500;
         }
         x = objcts_1.ocan[j - 1];
// 						!GET CONTAINER.
      L300:
         if (x == i__) {
            goto L400;
         }
// 						!INSIDE TARGET?
         if (x == 0) {
            goto L500;
         }
// 						!INSIDE ANYTHING?
         if ((objcts_1.oflag1[x - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[x - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[x - 1] & oflags_1.openbt) == 0 || (objcts_1.oflag2[x - 1] & oflags_1.schbt) == 0) {
            goto L500;
         }
         x = objcts_1.ocan[x - 1];
// 						!GO ANOTHER LEVEL.
         goto L300;

      L400:
         if (ret_val != 0) {
            goto L2000;
         }
// 						!ALREADY GOT ONE?
         ret_val = j;
// 						!NO.
      L500:
         ;
      }

   L1000:
      ;
   }
   return ret_val;

L2000:
   ret_val = -ret_val;
// 						!AMB RETURN.
   return ret_val;

}

// THISIT--	VALIDATE OBJECT VS DESCRIPTION

// DECLARATIONS

static Bool thisit_(int oidx, int aidx, int obj, int spcobj) {
// Initialized data

   static int r50min = 1600;

// System generated locals
   Bool ret_val;

// Local variables
   static int i__;

// FUNCTIONS AND DATA

//    THE FOLLOWING DATA STATEMENT USED RADIX-50 NOTATION (R50MIN/1RA/)
//       IN RADIX-50 NOTATION, AN "A" IN THE FIRST POSITION IS
//       ENCODED AS 1*40*40 = 1600.

   ret_val = false;
// 						!ASSUME NO MATCH.
   if (spcobj != 0 && obj == spcobj) {
      goto L500;
   }

// CHECK FOR OBJECT NAMES

   i__ = oidx + 1;
L100:
   ++i__;
   if (ovoc[i__ - 1] <= 0 || ovoc[i__ - 1] >= r50min) {
      return ret_val;
   }
// 						!IF DONE, LOSE.
   if (ovoc[i__ - 1] != obj) {
      goto L100;
   }
// 						!IF FAIL, CONT.

   if (aidx == 0) {
      goto L500;
   }
// 						!ANY ADJ?
   i__ = aidx + 1;
L200:
   ++i__;
   if (avoc[i__ - 1] <= 0 || avoc[i__ - 1] >= r50min) {
      return ret_val;
   }
// 						!IF DONE, LOSE.
   if (avoc[i__ - 1] != obj) {
      goto L200;
   }
// 						!IF FAIL, CONT.

L500:
   ret_val = true;
   return ret_val;
}
