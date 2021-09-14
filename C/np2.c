/*  -- translated by f2c (version 20190311).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
   integer prsa, prsi, prso;
   logical prswon;
   integer prscon;
} prsvec_;

#define prsvec_1 prsvec_

struct {
   integer oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

struct {
   integer lastit;
} last_;

#define last_1 last_

struct {
   integer act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

struct {
   integer vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

struct {
   integer sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

struct {
   integer vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

struct {
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer mbase, strbit;
} star_;

#define star_1 star_

struct {
   integer dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

struct {
   integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   integer visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt,
      schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   integer alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

struct {
   integer astag;
} aflags_;

#define aflags_1 aflags_

struct {
   integer player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

struct {
   integer bvoc[20];
} buzvoc_;

#define buzvoc_1 buzvoc_

struct {
   integer pvoc[45];
} prpvoc_;

#define prpvoc_1 prpvoc_

struct {
   integer dvoc[75];
} dirvoc_;

#define dirvoc_1 dirvoc_

union {
   struct {
      integer avoc1[184], avoc2[114], avoc3[106], avocnd;
   } _1;
   struct {
      doublereal eqv_pad[225];
   } _2;
} adjvoc_;

#define adjvoc_1 (adjvoc_._1)
#define adjvoc_2 (adjvoc_._2)

union {
   struct {
      integer vvoc1[92], vvoc1a[108], vvoc1b[38], vvoc2[104], vvoc3[136], vvoc4[116], vvoc5[134], vvoc6[117], vvoc7[89], vvocnd;
   } _1;
   struct {
      doublereal eqv_pad[475];
   } _2;
} vrbvoc_;

#define vrbvoc_1 (vrbvoc_._1)
#define vrbvoc_2 (vrbvoc_._2)

union {
   struct {
      integer ovoc1[159], ovoc2[144], ovoc3[150], ovoc4[128], ovoc5[111], ovoc6[104], ovoc6a[97], ovoc7[127], ovocnd;
   } _1;
   struct {
      doublereal eqv_pad[525];
   } _2;
} objvoc_;

#define objvoc_1 (objvoc_._1)
#define objvoc_2 (objvoc_._2)

/* Table of constant values */

static integer c__0 = 0;

/* GETOBJ--	FIND OBJ DESCRIBED BY ADJ, NAME PAIR */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* DECLARATIONS */

/* THIS ROUTINE DETAILS ON BIT 3 OF PRSFLG */

integer getobj_(integer * oidx, integer * aidx, integer * spcobj) {
/* System generated locals */
   integer ret_val, i__1;

/* Local variables */
   static integer i__, av;
#define eqa ((integer *)&advs_1 + 1)
   static integer obj;
#define eqo ((integer *)&objcts_1 + 1)
   extern logical lit_(integer *);
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define avoc ((integer *)&adjvoc_1)
   static integer nobj;
#define pvec ((integer *)&pv_1)
#define ovoc ((integer *)&objvoc_1)
#define vvoc ((integer *)&vrbvoc_1)
   extern logical ghere_(integer *, integer *);
   static logical chomp;
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   extern logical thisit_(integer *, integer *, integer *, integer *);
   extern integer schlst_(integer *, integer *, integer *, integer *, integer *, integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* MISCELLANEOUS VARIABLES */

/* GAME STATE */

/* OBJECTS */

/* ADVENTURERS */

/* GETOBJ, PAGE 2 */

/* D	DFLAG=IAND(PRSFLG, 8).NE.0 */

/* VOCABULARIES */

   chomp = FALSE_;
   av = advs_1.avehic[play_1.winner - 1];
   obj = 0;
/* 						!ASSUME DARK. */
   if (!lit_(&play_1.here)) {
      goto L200;
   }
/* 						!LIT? */

   obj = schlst_(oidx, aidx, &play_1.here, &c__0, &c__0, spcobj);
/* 						!SEARCH ROOM. */
/* D	IF(DFLAG) PRINT 10,OBJ */
/* D10	FORMAT(' SCHLST- ROOM SCH ',I6) */
   if (obj < 0) {
      goto L1000;
   } else if (obj == 0) {
      goto L200;
   } else {
      goto L100;
   }
/* 						!TEST RESULT. */
 L100:
   if (av == 0 || av == obj || (objcts_1.oflag2[obj - 1] & oflags_1.findbt)
      != 0) {
      goto L200;
   }
   if (objcts_1.ocan[obj - 1] == av) {
      goto L200;
   }
/* 						!TEST IF REACHABLE. */
   chomp = TRUE_;
/* 						!PROBABLY NOT. */

 L200:
   if (av == 0) {
      goto L400;
   }
/* 						!IN VEHICLE? */
   nobj = schlst_(oidx, aidx, &c__0, &av, &c__0, spcobj);
/* 						!SEARCH VEHICLE. */
/* D	IF(DFLAG) PRINT 20,NOBJ */
/* D20	FORMAT(' SCHLST- VEH SCH  ',I6) */
   if (nobj < 0) {
      goto L1100;
   } else if (nobj == 0) {
      goto L400;
   } else {
      goto L300;
   }
/* 						!TEST RESULT. */
 L300:
   chomp = FALSE_;
/* 						!REACHABLE. */
   if (obj == nobj) {
      goto L400;
   }
/* 						!SAME AS BEFORE? */
   if (obj != 0) {
      nobj = -nobj;
   }
/* 						!AMB RESULT? */
   obj = nobj;

 L400:
   nobj = schlst_(oidx, aidx, &c__0, &c__0, &play_1.winner, spcobj);
/* 						!SEARCH ADVENTURER. */
/* D	IF(DFLAG) PRINT 30,NOBJ */
/* D30	FORMAT(' SCHLST- ADV SCH  ',I6) */
   if (nobj < 0) {
      goto L1100;
   } else if (nobj == 0) {
      goto L600;
   } else {
      goto L500;
   }
/* 						!TEST RESULT */
 L500:
   if (obj != 0) {
      nobj = -nobj;
   }
/* 						!AMB RESULT? */
 L1100:
   obj = nobj;
/* 						!RETURN NEW OBJECT. */
 L600:
   if (chomp) {
      obj = -10000;
   }
/* 						!UNREACHABLE. */
 L1000:
   ret_val = obj;

   if (ret_val != 0) {
      goto L1500;
   }
/* 						!GOT SOMETHING? */
   i__1 = objcts_1.olnt;
   for (i__ = star_1.strbit + 1; i__ <= i__1; ++i__) {
/* 						!NO, SEARCH GLOBALS. */
      if (!thisit_(oidx, aidx, &i__, spcobj)) {
         goto L1200;
      }
      if (!ghere_(&i__, &play_1.here)) {
         goto L1200;
      }
/* 						!CAN IT BE HERE? */
      if (ret_val != 0) {
         ret_val = -i__;
      }
/* 						!AMB MATCH? */
      if (ret_val == 0) {
         ret_val = i__;
      }
    L1200:
      ;
   }

 L1500:
/* 						!END OF SEARCH. */
/* D	IF(DFLAG) PRINT 40,GETOBJ */
/* D40	FORMAT(' SCHLST- RESULT   ',I6) */
   return ret_val;
} /* getobj_ */

#undef prpvec
#undef objvec
#undef vvoc
#undef ovoc
#undef pvec
#undef avoc
#undef syn
#undef orp
#undef eqo
#undef eqa

/* SCHLST--	SEARCH FOR OBJECT */

/* DECLARATIONS */

integer schlst_(integer * oidx, integer * aidx, integer * rm, integer * cn, integer * ad, integer * spcobj) {
/* System generated locals */
   integer ret_val, i__1, i__2;

/* Local variables */
   static integer i__, j, x;
#define eqo ((integer *)&objcts_1 + 1)
   extern logical qhere_(integer *, integer *), thisit_(integer *, integer *, integer *, integer *);

/* OBJECTS */

/* FUNCTIONS AND DATA */

   ret_val = 0;
/* 						!NO RESULT. */
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!SEARCH OBJECTS. */
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.visibt) == 0 || (*rm == 0 || !qhere_(&i__, rm)) && (*cn == 0 || objcts_1.ocan[i__ - 1] != *cn) && (*ad == 0 || objcts_1.oadv[i__ - 1] != *ad)) {
         goto L1000;
      }
      if (!thisit_(oidx, aidx, &i__, spcobj)) {
         goto L200;
      }
      if (ret_val != 0) {
         goto L2000;
      }
/* 						!GOT ONE ALREADY? */
      ret_val = i__;
/* 						!NO. */

/* IF OPEN OR TRANSPARENT, SEARCH THE OBJECT ITSELF. */

    L200:
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0) {
         goto L1000;
      }

/* SEARCH IS CONDUCTED IN REVERSE.  ALL OBJECTS ARE CHECKED TO */
/* SEE IF THEY ARE AT SOME LEVEL OF CONTAINMENT INSIDE OBJECT 'I'. */
/* IF THEY ARE AT LEVEL 1, OR IF ALL LINKS IN THE CONTAINMENT */
/* CHAIN ARE OPEN, VISIBLE, AND HAVE SEARCHME SET, THEY CAN QUALIFY */
/* AS A POTENTIAL MATCH. */

      i__2 = objcts_1.olnt;
      for (j = 1; j <= i__2; ++j) {
/* 						!SEARCH OBJECTS. */
         if ((objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0 || !thisit_(oidx, aidx, &j, spcobj)) {
            goto L500;
         }
         x = objcts_1.ocan[j - 1];
/* 						!GET CONTAINER. */
       L300:
         if (x == i__) {
            goto L400;
         }
/* 						!INSIDE TARGET? */
         if (x == 0) {
            goto L500;
         }
/* 						!INSIDE ANYTHING? */
         if ((objcts_1.oflag1[x - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[x - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[x - 1] & oflags_1.openbt) == 0 || (objcts_1.oflag2[x - 1] & oflags_1.schbt) == 0) {
            goto L500;
         }
         x = objcts_1.ocan[x - 1];
/* 						!GO ANOTHER LEVEL. */
         goto L300;

       L400:
         if (ret_val != 0) {
            goto L2000;
         }
/* 						!ALREADY GOT ONE? */
         ret_val = j;
/* 						!NO. */
       L500:
         ;
      }

    L1000:
      ;
   }
   return ret_val;

 L2000:
   ret_val = -ret_val;
/* 						!AMB RETURN. */
   return ret_val;

} /* schlst_ */

#undef eqo

/* THISIT--	VALIDATE OBJECT VS DESCRIPTION */

/* DECLARATIONS */

logical thisit_(integer * oidx, integer * aidx, integer * obj, integer * spcobj) {
/* Initialized data */

   static integer r50min = 1600;

/* System generated locals */
   logical ret_val;

/* Local variables */
   static integer i__;
#define avoc ((integer *)&adjvoc_1)
#define ovoc ((integer *)&objvoc_1)
#define vvoc ((integer *)&vrbvoc_1)

/* FUNCTIONS AND DATA */

/* VOCABULARIES */

/*    THE FOLLOWING DATA STATEMENT USED RADIX-50 NOTATION (R50MIN/1RA/) */
/*       IN RADIX-50 NOTATION, AN "A" IN THE FIRST POSITION IS */
/*       ENCODED AS 1*40*40 = 1600. */

   ret_val = FALSE_;
/* 						!ASSUME NO MATCH. */
   if (*spcobj != 0 && *obj == *spcobj) {
      goto L500;
   }

/* CHECK FOR OBJECT NAMES */

   i__ = *oidx + 1;
 L100:
   ++i__;
   if (ovoc[i__ - 1] <= 0 || ovoc[i__ - 1] >= r50min) {
      return ret_val;
   }
/* 						!IF DONE, LOSE. */
   if (ovoc[i__ - 1] != *obj) {
      goto L100;
   }
/* 						!IF FAIL, CONT. */

   if (*aidx == 0) {
      goto L500;
   }
/* 						!ANY ADJ? */
   i__ = *aidx + 1;
 L200:
   ++i__;
   if (avoc[i__ - 1] <= 0 || avoc[i__ - 1] >= r50min) {
      return ret_val;
   }
/* 						!IF DONE, LOSE. */
   if (avoc[i__ - 1] != *obj) {
      goto L200;
   }
/* 						!IF FAIL, CONT. */

 L500:
   ret_val = TRUE_;
   return ret_val;
} /* thisit_ */

#undef vvoc
#undef ovoc
#undef avoc