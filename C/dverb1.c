#include "F2C.h"
#include "parse.h"

// gamestat.h:

// GAME STATE

extern struct {
   int winner, here;
   Bool telflg;
} play_;
#define play_1 play_

// state.h:
extern struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;
#define state_1 state_

// star.h: (Unlisted)
extern struct {
   int mbase, strbit;
} star_;
#define star_1 star_

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

// rindex.h:

extern struct rindex_1_ {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// verbs.h:

// VERBS

extern struct vindex_1_ {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;
#define vindex_1 vindex_

// TAKE-- BASIC TAKE SEQUENCE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// TAKE AN OBJECT (FOR VERBS TAKE, PUT, DROP, READ, ETC.)

Bool take_(Bool flg) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int x, oa;
   extern int rnd_(int);
   extern Bool qhere_(int, int);
   extern Bool objact_(/*int*/);
   extern Bool oappli_(int, int);
   extern void rspeak_(int);
   extern int weight_(int, int, int);
   extern void newsta_(int, int, int, int, int);
   extern void scrupd_(int);

// DECLARATIONS

// FUNCTIONS AND DATA

// TAKE, PAGE 2

   ret_val = false;
// 						!ASSUME LOSES.
   oa = objcts_1.oactio[prsvec_1.prso - 1];
// 						!GET OBJECT ACTION.
   if (prsvec_1.prso <= star_1.strbit) {
      goto L100;
   }
// 						!STAR?
   ret_val = objact_(/*x*/);
// 						!YES, LET IT HANDLE.
   return ret_val;

L100:
   x = objcts_1.ocan[prsvec_1.prso - 1];
// 						!INSIDE?
   if (prsvec_1.prso != advs_1.avehic[play_1.winner - 1]) {
      goto L400;
   }
// 						!HIS VEHICLE?
   rspeak_(672);
// 						!DUMMY.
   return ret_val;

L400:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) != 0) {
      goto L500;
   }
   if (!oappli_(oa, 0)) {
      i__1 = rnd_(5) + 552;
      rspeak_(i__1);
   }
   return ret_val;

// OBJECT IS TAKEABLE AND IN POSITION TO BE TAKEN.

L500:
   if (x != 0 || qhere_(prsvec_1.prso, play_1.here)) {
      goto L600;
   }
   if (objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      rspeak_(557);
   }
// 						!ALREADY GOT IT?
   return ret_val;

L600:
   if (x != 0 && objcts_1.oadv[x - 1] == play_1.winner || weight_(0, prsvec_1.prso, play_1.winner) + objcts_1.osize[prsvec_1.prso - 1] <= state_1.mxload) {
      goto L700;
   }
   rspeak_(558);
// 						!TOO MUCH WEIGHT.
   return ret_val;

L700:
   ret_val = true;
// 						!AT LAST.
   if (oappli_(oa, 0)) {
      return ret_val;
   }
// 						!DID IT HANDLE?
   newsta_(prsvec_1.prso, 0, 0, 0, play_1.winner);
// 						!TAKE OBJECT FOR WINNER.
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;
   scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
// 						!UPDATE SCORE.
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
// 						!CANT BE SCORED AGAIN.
   if (flg) {
      rspeak_(559);
   }
// 						!TELL TAKEN.
   return ret_val;

}

// DROP- DROP VERB PROCESSOR

// DECLARATIONS

Bool drop_(/*Bool z__*/) {
// System generated locals
   Bool ret_val;

// Local variables
   static Bool f;
   static int i__, x;
   extern Bool put_(/*Bool*/);
   extern Bool objact_(/*int*/);
   extern void rspsub_(int, int);
   extern void newsta_(int, int, int, int, int);
   extern void scrupd_(int);
   extern void rspeak_(int);

// ROOMS

// DROP, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   x = objcts_1.ocan[prsvec_1.prso - 1];
// 						!GET CONTAINER.
   if (x == 0) {
      goto L200;
   }
// 						!IS IT INSIDE?
   if (objcts_1.oadv[x - 1] != play_1.winner) {
      goto L1000;
   }
// 						!IS HE CARRYING CON?
   if ((objcts_1.oflag2[x - 1] & oflags_1.openbt) != 0) {
      goto L300;
   }
   rspsub_(525, objcts_1.odesc2[x - 1]);
// 						!CANT REACH.
   return ret_val;

L200:
   if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner) {
      goto L1000;
   }
// 						!IS HE CARRYING OBJ?
L300:
   if (advs_1.avehic[play_1.winner - 1] == 0) {
      goto L400;
   }
// 						!IS HE IN VEHICLE?
   prsvec_1.prsi = advs_1.avehic[play_1.winner - 1];
// 						!YES,
   f = put_(/*true*/);
// 						!DROP INTO VEHICLE.
   prsvec_1.prsi = 0;
// 						!DISARM PARSER.
   return ret_val;
// 						!DONE.

L400:
   newsta_(prsvec_1.prso, 0, play_1.here, 0, 0);
// 						!DROP INTO ROOM.
   if (play_1.here == rindex_1.mtree) {
      newsta_(prsvec_1.prso, 0, rindex_1.fore3, 0, 0);
   }
   scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
// 						!SCORE OBJECT.
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
// 						!CANT BE SCORED AGAIN.
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;

   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!DID IT HANDLE?
   i__ = 0;
// 						!ASSUME NOTHING TO SAY.
   if (prsvec_1.prsa == vindex_1.dropw) {
      i__ = 528;
   }
   if (prsvec_1.prsa == vindex_1.throww) {
      i__ = 529;
   }
   if (i__ != 0 && play_1.here == rindex_1.mtree) {
      i__ = 659;
   }
   rspsub_(i__, objcts_1.odesc2[prsvec_1.prso - 1]);
   return ret_val;

L1000:
   rspeak_(527);
// 						!DONT HAVE IT.
   return ret_val;

}

// PUT- PUT VERB PROCESSOR

// DECLARATIONS

Bool put_(/*Bool flg*/) {
// System generated locals
   Bool ret_val;

// Local variables
   static int j, x;
   static int svi, svo;
   extern Bool take_(Bool);
   extern Bool qhere_(int, int);
   extern void rspsb2_(int, int, int);
   extern Bool objact_(/*int*/);
   extern void rspeak_(int);
   extern int weight_(int, int, int);
   extern void rspsub_(int, int);
   extern void scrupd_(int);
   extern void newsta_(int, int, int, int, int);

// MISCELLANEOUS VARIABLES

// FUNCTIONS AND DATA

// PUT, PAGE 2

   ret_val = false;
   if (prsvec_1.prso <= star_1.strbit && prsvec_1.prsi <= star_1.strbit) {
      goto L200;
   }
   if (!objact_(/*x*/)) {
      rspeak_(560);
   }
// 						!STAR
   ret_val = true;
   return ret_val;

L200:
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.openbt) != 0 || (objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.doorbt + oflags_1.contbt) != 0 || (objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.vehbt) != 0) {
      goto L300;
   }
   rspeak_(561);
// 						!CANT PUT IN THAT.
   return ret_val;

L300:
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.openbt) != 0) {
      goto L400;
   }
// 						!IS IT OPEN?
   rspeak_(562);
// 						!NO, JOKE
   return ret_val;

L400:
   if (prsvec_1.prso != prsvec_1.prsi) {
      goto L500;
   }
// 						!INTO ITSELF?
   rspeak_(563);
// 						!YES, JOKE.
   return ret_val;

L500:
   if (objcts_1.ocan[prsvec_1.prso - 1] != prsvec_1.prsi) {
      goto L600;
   }
// 						!ALREADY INSIDE.
   rspsb2_(564, objcts_1.odesc2[prsvec_1.prso - 1], objcts_1.odesc2[prsvec_1.prsi - 1]);
   ret_val = true;
   return ret_val;

L600:
   if (weight_(0, prsvec_1.prso, 0) + weight_(0, prsvec_1.prsi, 0) + objcts_1.osize[prsvec_1.prso - 1] <= objcts_1.ocapac[prsvec_1.prsi - 1]) {
      goto L700;
   }
   rspeak_(565);
// 						!THEN CANT DO IT.
   return ret_val;

// NOW SEE IF OBJECT (OR ITS CONTAINER) IS IN ROOM

L700:
   j = prsvec_1.prso;
// 						!START SEARCH.
L725:
   if (qhere_(j, play_1.here)) {
      goto L750;
   }
// 						!IS IT HERE?
   j = objcts_1.ocan[j - 1];
   if (j != 0) {
      goto L725;
   }
// 						!MORE TO DO?
   goto L800;
// 						!NO, SCH FAILS.

L750:
   svo = prsvec_1.prso;
// 						!SAVE PARSER.
   svi = prsvec_1.prsi;
   prsvec_1.prsa = vindex_1.takew;
   prsvec_1.prsi = 0;
   if (!take_(false)) {
      return ret_val;
   }
// 						!TAKE OBJECT.
   prsvec_1.prsa = vindex_1.putw;
   prsvec_1.prso = svo;
   prsvec_1.prsi = svi;
   goto L1000;

// NOW SEE IF OBJECT IS ON PERSON.

L800:
   if (objcts_1.ocan[prsvec_1.prso - 1] == 0) {
      goto L1000;
   }
// 						!INSIDE?
   if ((objcts_1.oflag2[objcts_1.ocan[prsvec_1.prso - 1] - 1] & oflags_1.openbt) != 0) {
      goto L900;
   }
// 						!OPEN?
   rspsub_(566, objcts_1.odesc2[prsvec_1.prso - 1]);
// 						!LOSE.
   return ret_val;

L900:
   scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
// 						!SCORE OBJECT.
   objcts_1.ofval[prsvec_1.prso - 1] = 0;
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.tchbt;
   newsta_(prsvec_1.prso, 0, 0, 0, play_1.winner);
// 						!TEMPORARILY ON WINNER.

L1000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!NO, GIVE OBJECT A SHOT.
   newsta_(prsvec_1.prso, 2, 0, prsvec_1.prsi, 0);
// 						!CONTAINED INSIDE.
   ret_val = true;
   return ret_val;

}

// VALUAC- HANDLES VALUABLES/EVERYTHING

// DECLARATIONS

void valuac_(int v) {
// System generated locals
   int i__1;

// Local variables
   static Bool f;
   static int i__;
   static Bool f1;
   extern Bool lit_(int);
   extern Bool put_(/*Bool*/);
   extern Bool take_(Bool);
   extern Bool drop_(/*Bool*/);
   extern Bool qhere_(int, int);
   static int savep, saveh;
   extern void rspsub_(int, int);
   extern void rspeak_(int);

// FUNCTIONS AND DATA

// VALUAC, PAGE 2

   f = true;
// 						!ASSUME NO ACTIONS.
   i__ = 579;
// 						!ASSUME NOT LIT.
   if (!lit_(play_1.here)) {
      goto L4000;
   }
// 						!IF NOT LIT, PUNT.
   i__ = 677;
// 						!ASSUME WRONG VERB.
   savep = prsvec_1.prso;
// 						!SAVE PRSO.
   saveh = play_1.here;
// 						!SAVE HERE.

//L100:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L1000;
   }
// 						!TAKE EVERY/VALUA?
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
// 						!LOOP THRU OBJECTS.
      if (!qhere_(prsvec_1.prso, play_1.here) || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.actrbt) != 0 || savep == v && objcts_1.otval[prsvec_1.prso - 1] <= 0) {
         goto L500;
      }
      if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) == 0 && (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.trybt) == 0) {
         goto L500;
      }
      f = false;
      rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = take_(true);
      if (saveh != play_1.here) {
         return;
      }
   L500:
      ;
   }
   goto L3000;

L1000:
   if (prsvec_1.prsa != vindex_1.dropw) {
      goto L2000;
   }
// 						!DROP EVERY/VALUA?
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
      if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner || savep == v && objcts_1.otval[prsvec_1.prso - 1] <= 0) {
         goto L1500;
      }
      f = false;
      rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = drop_(/*true*/);
      if (saveh != play_1.here) {
         return;
      }
   L1500:
      ;
   }
   goto L3000;

L2000:
   if (prsvec_1.prsa != vindex_1.putw) {
      goto L3000;
   }
// 						!PUT EVERY/VALUA?
   i__1 = objcts_1.olnt;
   for (prsvec_1.prso = 1; prsvec_1.prso <= i__1; ++prsvec_1.prso) {
// 						!LOOP THRU OBJECTS.
      if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner || prsvec_1.prso == prsvec_1.prsi || savep == v && objcts_1.otval[prsvec_1.prso - 1] <= 0 || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.visibt) == 0) {
         goto L2500;
      }
      f = false;
      rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
      f1 = put_(/*true*/);
      if (saveh != play_1.here) {
         return;
      }
   L2500:
      ;
   }

L3000:
   i__ = 581;
   if (savep == v) {
      i__ = 582;
   }
// 						!CHOOSE MESSAGE.
L4000:
   if (f) {
      rspeak_(i__);
   }
// 						!IF NOTHING, REPORT.
}
