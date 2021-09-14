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
   integer moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct {
   integer mbase, strbit;
} star_;

#define star_1 star_

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
   integer whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls,
      mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw,
      mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

struct {
   integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw,
      openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw,
      clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

/* Table of constant values */

static integer c__672 = 672;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__557 = 557;
static integer c__558 = 558;
static integer c__559 = 559;
static integer c__525 = 525;
static logical c_true = TRUE_;
static integer c__527 = 527;
static integer c__560 = 560;
static integer c__561 = 561;
static integer c__562 = 562;
static integer c__563 = 563;
static integer c__564 = 564;
static integer c__565 = 565;
static logical c_false = FALSE_;
static integer c__566 = 566;
static integer c__2 = 2;
static integer c__580 = 580;

/* TAKE-- BASIC TAKE SEQUENCE */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* TAKE AN OBJECT (FOR VERBS TAKE, PUT, DROP, READ, ETC.) */

logical take_(logical * flg) {
/* System generated locals */
   integer i__1;
   logical ret_val;

/* Local variables */
   static integer x, oa;
#define eqa ((integer *)&advs_1 + 1)
   extern integer rnd_(integer *);
#define eqo ((integer *)&objcts_1 + 1)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
   extern logical qhere_(integer *, integer *), objact_(integer *);
#define objvec ((integer *)&pv_1 + 1)
   extern logical oappli_(integer *, integer *);
#define prpvec ((integer *)&pv_1 + 3)
   extern /* Subroutine */ int rspeak_(integer *);
   extern integer weight_(integer *, integer *, integer *);
   extern /* Subroutine */ int newsta_(integer *, integer *, integer *,
      integer *, integer *), scrupd_(integer *);

/* DECLARATIONS */

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* OBJECTS */

/* FUNCTIONS AND DATA */

/* ADVENTURERS */

/* TAKE, PAGE 2 */

   ret_val = FALSE_;
/* 						!ASSUME LOSES. */
   oa = objcts_1.oactio[prsvec_1.prso - 1];
/* 						!GET OBJECT ACTION. */
   if (prsvec_1.prso <= star_1.strbit) {
      goto L100;
   }
/* 						!STAR? */
   ret_val = objact_(&x);
/* 						!YES, LET IT HANDLE. */
   return ret_val;

 L100:
   x = objcts_1.ocan[prsvec_1.prso - 1];
/* 						!INSIDE? */
   if (prsvec_1.prso != advs_1.avehic[play_1.winner - 1]) {
      goto L400;
   }
/* 						!HIS VEHICLE? */
   rspeak_(&c__672);
/* 						!DUMMY. */
   return ret_val;

 L400:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) != 0) {
      goto L500;
   }
   if (!oappli_(&oa, &c__0)) {
      i__1 = rnd_(&c__5) + 552;
      rspeak_(&i__1);
   }
   return ret_val;

/* OBJECT IS TAKEABLE AND IN POSITION TO BE TAKEN. */

 L500:
   if (x != 0 || qhere_(&prsvec_1.prso, &play_1.here)) {
      goto L600;
   }
   if (objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      rspeak_(&c__557);
   }
/* 						!ALREADY GOT IT? */
   return ret_val;

 L600:
   if (x != 0 && objcts_1.oadv[x - 1] == play_1.winner || weight_(&c__0, &prsvec_1.prso, &play_1.winner) + objcts_1.osize[prsvec_1.prso - 1]
      <= state_1.mxload) {
      goto L700;
   }
   rspeak_(&c__558);
/* 						!TOO MUCH WEIGHT. */
   return ret_val;

 L700:
   ret_val = TRUE_;
/* 						!AT LAST. */
   if (oappli_(&oa, &c__0)) {
      return ret_val;
   }
/* 						!DID IT HANDLE? */
   newsta_(&prsvec_1.prso, &c__0, &c__0, &c__0, &play_1.winner);
/* 						!TAKE OBJECT FOR WINNER. */
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;
   scrupd_(&objcts_1.ofval[prsvec_1.prso - 1]);
/* 						!UPDATE SCORE. */
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
/* 						!CANT BE SCORED AGAIN. */
   if (*flg) {
      rspeak_(&c__559);
   }
/* 						!TELL TAKEN. */
   return ret_val;

} /* take_ */

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa

/* DROP- DROP VERB PROCESSOR */

/* DECLARATIONS */

logical drop_(logical * z__) {
/* System generated locals */
   logical ret_val;

/* Local variables */
   static logical f;
   static integer i__, x;
#define eqa ((integer *)&advs_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define orp ((integer *)&orphs_1)
   extern logical put_(logical *);
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
   extern logical objact_(integer *);
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   extern /* Subroutine */ int rspsub_(integer *, integer *), newsta_(
      integer *, integer *, integer *, integer *, integer *), scrupd_(integer *), rspeak_(integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* ROOMS */

/* GAME STATE */

/* OBJECTS */

/* ADVENTURERS */

/* DROP, PAGE 2 */

/* VERBS */

   ret_val = TRUE_;
/* 						!ASSUME WINS. */
   x = objcts_1.ocan[prsvec_1.prso - 1];
/* 						!GET CONTAINER. */
   if (x == 0) {
      goto L200;
   }
/* 						!IS IT INSIDE? */
   if (objcts_1.oadv[x - 1] != play_1.winner) {
      goto L1000;
   }
/* 						!IS HE CARRYING CON? */
   if ((objcts_1.oflag2[x - 1] & oflags_1.openbt) != 0) {
      goto L300;
   }
   rspsub_(&c__525, &objcts_1.odesc2[x - 1]);
/* 						!CANT REACH. */
   return ret_val;

 L200:
   if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner) {
      goto L1000;
   }
/* 						!IS HE CARRYING OBJ? */
 L300:
   if (advs_1.avehic[play_1.winner - 1] == 0) {
      goto L400;
   }
/* 						!IS HE IN VEHICLE? */
   prsvec_1.prsi = advs_1.avehic[play_1.winner - 1];
/* 						!YES, */
   f = put_(&c_true);
/* 						!DROP INTO VEHICLE. */
   prsvec_1.prsi = 0;
/* 						!DISARM PARSER. */
   return ret_val;
/* 						!DONE. */

 L400:
   newsta_(&prsvec_1.prso, &c__0, &play_1.here, &c__0, &c__0);
/* 						!DROP INTO ROOM. */
   if (play_1.here == rindex_1.mtree) {
      newsta_(&prsvec_1.prso, &c__0, &rindex_1.fore3, &c__0, &c__0);
   }
   scrupd_(&objcts_1.ofval[prsvec_1.prso - 1]);
/* 						!SCORE OBJECT. */
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
/* 						!CANT BE SCORED AGAIN. */
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;

   if (objact_(&x)) {
      return ret_val;
   }
/* 						!DID IT HANDLE? */
   i__ = 0;
/* 						!ASSUME NOTHING TO SAY. */
   if (prsvec_1.prsa == vindex_1.dropw) {
      i__ = 528;
   }
   if (prsvec_1.prsa == vindex_1.throww) {
      i__ = 529;
   }
   if (i__ != 0 && play_1.here == rindex_1.mtree) {
      i__ = 659;
   }
   rspsub_(&i__, &objcts_1.odesc2[prsvec_1.prso - 1]);
   return ret_val;

 L1000:
   rspeak_(&c__527);
/* 						!DONT HAVE IT. */
   return ret_val;

} /* drop_ */

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa

/* PUT- PUT VERB PROCESSOR */

/* DECLARATIONS */

logical put_(logical * flg) {
/* System generated locals */
   logical ret_val;

/* Local variables */
   static integer j, x;
#define eqa ((integer *)&advs_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define orp ((integer *)&orphs_1)
   static integer svi, svo;
#define syn ((integer *)&syntax_1)
   extern logical take_(logical *);
#define pvec ((integer *)&pv_1)
   extern logical qhere_(integer *, integer *);
   extern /* Subroutine */ int rspsb2_(integer *, integer *, integer *);
   extern logical objact_(integer *);
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   extern /* Subroutine */ int rspeak_(integer *);
   extern integer weight_(integer *, integer *, integer *);
   extern /* Subroutine */ int rspsub_(integer *, integer *), scrupd_(
      integer *), newsta_(integer *, integer *, integer *, integer *, integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* MISCELLANEOUS VARIABLES */

/* GAME STATE */

/* OBJECTS */

/* ADVENTURERS */

/* FUNCTIONS AND DATA */

/* VERBS */

/* PUT, PAGE 2 */

   ret_val = FALSE_;
   if (prsvec_1.prso <= star_1.strbit && prsvec_1.prsi <= star_1.strbit) {
      goto L200;
   }
   if (!objact_(&x)) {
      rspeak_(&c__560);
   }
/* 						!STAR */
   ret_val = TRUE_;
   return ret_val;

 L200:
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.openbt) != 0 || (objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.doorbt + oflags_1.contbt) != 0 || (objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.vehbt) != 0) {
      goto L300;
   }
   rspeak_(&c__561);
/* 						!CANT PUT IN THAT. */
   return ret_val;

 L300:
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.openbt) != 0) {
      goto L400;
   }
/* 						!IS IT OPEN? */
   rspeak_(&c__562);
/* 						!NO, JOKE */
   return ret_val;

 L400:
   if (prsvec_1.prso != prsvec_1.prsi) {
      goto L500;
   }
/* 						!INTO ITSELF? */
   rspeak_(&c__563);
/* 						!YES, JOKE. */
   return ret_val;

 L500:
   if (objcts_1.ocan[prsvec_1.prso - 1] != prsvec_1.prsi) {
      goto L600;
   }
/* 						!ALREADY INSIDE. */
   rspsb2_(&c__564, &objcts_1.odesc2[prsvec_1.prso - 1], &objcts_1.odesc2[prsvec_1.prsi - 1]);
   ret_val = TRUE_;
   return ret_val;

 L600:
   if (weight_(&c__0, &prsvec_1.prso, &c__0) + weight_(&c__0, &prsvec_1.prsi, &c__0) + objcts_1.osize[prsvec_1.prso - 1] <= objcts_1.ocapac[prsvec_1.prsi - 1]) {
      goto L700;
   }
   rspeak_(&c__565);
/* 						!THEN CANT DO IT. */
   return ret_val;

/* NOW SEE IF OBJECT (OR ITS CONTAINER) IS IN ROOM */

 L700:
   j = prsvec_1.prso;
/* 						!START SEARCH. */
 L725:
   if (qhere_(&j, &play_1.here)) {
      goto L750;
   }
/* 						!IS IT HERE? */
   j = objcts_1.ocan[j - 1];
   if (j != 0) {
      goto L725;
   }
/* 						!MORE TO DO? */
   goto L800;
/* 						!NO, SCH FAILS. */

 L750:
   svo = prsvec_1.prso;
/* 						!SAVE PARSER. */
   svi = prsvec_1.prsi;
   prsvec_1.prsa = vindex_1.takew;
   prsvec_1.prsi = 0;
   if (!take_(&c_false)) {
      return ret_val;
   }
/* 						!TAKE OBJECT. */
   prsvec_1.prsa = vindex_1.putw;
   prsvec_1.prso = svo;
   prsvec_1.prsi = svi;
   goto L1000;

/* NOW SEE IF OBJECT IS ON PERSON. */

 L800:
   if (objcts_1.ocan[prsvec_1.prso - 1] == 0) {
      goto L1000;
   }
/* 						!INSIDE? */
   if ((objcts_1.oflag2[objcts_1.ocan[prsvec_1.prso - 1] - 1] & oflags_1.openbt) != 0) {
      goto L900;
   }
/* 						!OPEN? */
   rspsub_(&c__566, &objcts_1.odesc2[prsvec_1.prso - 1]);
/* 						!LOSE. */
   return ret_val;

 L900:
   scrupd_(&objcts_1.ofval[prsvec_1.prso - 1]);
/* 						!SCORE OBJECT. */
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;
   newsta_(&prsvec_1.prso, &c__0, &c__0, &c__0, &play_1.winner);
/* 						!TEMPORARILY ON WINNER. */

 L1000:
   if (objact_(&x)) {
      return ret_val;
   }
/* 						!NO, GIVE OBJECT A SHOT. */
   newsta_(&prsvec_1.prso, &c__2, &c__0, &prsvec_1.prsi, &c__0);
/* 						!CONTAINED INSIDE. */
   ret_val = TRUE_;
   return ret_val;

} /* put_ */

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa

/* VALUAC- HANDLES VALUABLES/EVERYTHING */

/* DECLARATIONS */

/* Subroutine */ int valuac_(integer * v) {
/* System generated locals */
   integer i__1;

/* Local variables */
   static logical f;
   static integer i__;
   static logical f1;
#define eqo ((integer *)&objcts_1 + 1)
   extern logical lit_(integer *);
#define orp ((integer *)&orphs_1)
   extern logical put_(logical *);
#define syn ((integer *)&syntax_1)
   extern logical take_(logical *);
#define pvec ((integer *)&pv_1)
   extern logical drop_(logical *), qhere_(integer *, integer *);
   static integer savep, saveh;
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   extern /* Subroutine */ int rspsub_(integer *, integer *), rspeak_(
      integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* OBJECTS */

/* FUNCTIONS AND DATA */

/* VERBS */

/* VALUAC, PAGE 2 */

   f = TRUE_;
/* 						!ASSUME NO ACTIONS. */
   i__ = 579;
/* 						!ASSUME NOT LIT. */
   if (!lit_(&play_1.here)) {
      goto L4000;
   }
/* 						!IF NOT LIT, PUNT. */
   i__ = 677;
/* 						!ASSUME WRONG VERB. */
   savep = prsvec_1.prso;
/* 						!SAVE PRSO. */
   saveh = play_1.here;
/* 						!SAVE HERE. */

/* L100: */
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L1000;
   }
/* 						!TAKE EVERY/VALUA? */
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
/* 						!LOOP THRU OBJECTS. */
      if (!qhere_(&prsvec_1.prso, &play_1.here) || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.actrbt) != 0 || savep == *v && objcts_1.otval[prsvec_1.prso - 1] <= 0) {
         goto L500;
      }
      if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) == 0 && (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.trybt) == 0) {
         goto L500;
      }
      f = FALSE_;
      rspsub_(&c__580, &objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = take_(&c_true);
      if (saveh != play_1.here) {
         return 0;
      }
    L500:
      ;
   }
   goto L3000;

 L1000:
   if (prsvec_1.prsa != vindex_1.dropw) {
      goto L2000;
   }
/* 						!DROP EVERY/VALUA? */
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
      if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner || savep == *v && objcts_1.otval[prsvec_1.prso - 1] <= 0) {
         goto L1500;
      }
      f = FALSE_;
      rspsub_(&c__580, &objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = drop_(&c_true);
      if (saveh != play_1.here) {
         return 0;
      }
    L1500:
      ;
   }
   goto L3000;

 L2000:
   if (prsvec_1.prsa != vindex_1.putw) {
      goto L3000;
   }
/* 						!PUT EVERY/VALUA? */
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
/* 						!LOOP THRU OBJECTS. */
      if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner || prsvec_1.prso == prsvec_1.prsi || savep == *v && objcts_1.otval[prsvec_1.prso - 1] <= 0 || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.visibt) == 0) {
         goto L2500;
      }
      f = FALSE_;
      rspsub_(&c__580, &objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = put_(&c_true);
      if (saveh != play_1.here) {
         return 0;
      }
    L2500:
      ;
   }

 L3000:
   i__ = 581;
   if (savep == *v) {
      i__ = 582;
   }
/* 						!CHOOSE MESSAGE. */
 L4000:
   if (f) {
      rspeak_(&i__);
   }
/* 						!IF NOTHING, REPORT. */
   return 0;
} /* valuac_ */

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo