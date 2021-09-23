// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

static Bool infest(int);

// Intermove fight demon
void fightd(void) {
// Initialized data
   const int rout = 1;

// System generated locals
   int i__1, i__2;

// Local variables
   Bool f;
   int i, j, ra;
   int obj;
   int res;
   int out;

// FIGHTD, PAGE 2

   i__1 = vill_1.vlnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP THRU VILLAINS.
      vill_1.vopps[i - 1] = 0;
// 						!CLEAR OPPONENT SLOT.
      obj = vill_1.villns[i - 1];
// 						!GET OBJECT NO.
      ra = objcts_1.oactio[obj - 1];
// 						!GET HIS ACTION.
      if (play_1.here != objcts_1.oroom[obj - 1]) {
         goto L2200;
      }
// 						!ADVENTURER STILL HERE?
      if (obj == oindex_1.thief && findex_1.thfenf) {
         goto L2400;
      }
// 						!THIEF ENGROSSED?
      if (objcts_1.ocapac[obj - 1] >= 0) {
         goto L2050;
      }
// 						!YES, VILL AWAKE?
      if (vill_1.vprob[i - 1] == 0 || !prob(vill_1.vprob[i - 1], vill_1.vprob[i - 1])) {
         goto L2025;
      }
      objcts_1.ocapac[obj - 1] = (i__2 = objcts_1.ocapac[obj - 1], abs(i__2));
      vill_1.vprob[i - 1] = 0;
      if (ra == 0) {
         goto L2400;
      }
// 						!ANYTHING TO DO?
      prsvec_1.prsa = vindex_1.inxw;
// 						!YES, WAKE HIM UP.
      f = oappli(ra, 0);
      goto L2400;
// 						!NOTHING ELSE HAPPENS.

   L2025:
      vill_1.vprob[i - 1] += 10;
// 						!INCREASE WAKEUP PROB.
      goto L2400;
// 						!NOTHING ELSE.

   L2050:
      if ((objcts_1.oflag2[obj - 1] & FiteO) == 0) {
         goto L2100;
      }
      vill_1.vopps[i - 1] = obj;
// 						!FIGHTING, SET UP OPP.
      goto L2400;

   L2100:
      if (ra == 0) {
         goto L2400;
      }
// 						!NOT FIGHTING,
      prsvec_1.prsa = vindex_1.frstqw;
// 						!SET UP PROBABILITY
      if (!oappli(ra, 0)) {
         goto L2400;
      }
// 						!OF FIGHTING.
      objcts_1.oflag2[obj - 1] |= FiteO;
      vill_1.vopps[i - 1] = obj;
// 						!SET UP OPP.
      goto L2400;

   L2200:
      if ((objcts_1.oflag2[obj - 1] & FiteO) == 0 || ra == 0) {
         goto L2300;
      }
      prsvec_1.prsa = vindex_1.fightw;
// 						!HAVE A FIGHT.
      f = oappli(ra, 0);
   L2300:
      if (obj == oindex_1.thief) {
         findex_1.thfenf = false;
      }
// 						!TURN OFF ENGROSSED.
      advs_1.aflag[aindex_1.player - 1] &= ~aflags_1.astag;
      objcts_1.oflag2[obj - 1] &= ~(StagO + FiteO);
      if (objcts_1.ocapac[obj - 1] >= 0 || ra == 0) {
         goto L2400;
      }
      prsvec_1.prsa = vindex_1.inxw;
// 						!WAKE HIM UP.
      f = oappli(ra, 0);
      objcts_1.ocapac[obj - 1] = (i__2 = objcts_1.ocapac[obj - 1], abs(i__2));
   L2400:
      ;
   }
// FIGHTD, PAGE 3

// NOW DO ACTUAL COUNTERBLOWS.

   out = 0;
// 						!ASSUME HERO OK.
L2600:
   i__1 = vill_1.vlnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP THRU OPPS.
      j = vill_1.vopps[i - 1];
      if (j == 0) {
         goto L2700;
      }
// 						!SLOT EMPTY?
      prsvec_1.prscon = 1;
// 						!STOP CMD STREAM.
      ra = objcts_1.oactio[j - 1];
      if (ra == 0) {
         goto L2650;
      }
// 						!VILLAIN ACTION?
      prsvec_1.prsa = vindex_1.fightw;
// 						!SEE IF
      if (oappli(ra, 0)) {
         goto L2700;
      }
// 						!SPECIAL ACTION.
   L2650:
      res = blow(aindex_1.player, j, vill_1.vmelee[i - 1], false, out);
// 						!STRIKE BLOW.
      if (res < 0) {
         return;
      }
// 						!IF HERO DEAD, EXIT.
      if (res == rout) {
         out = rnd(3) + 2;
      }
// 						!IF HERO OUT, SET FLG.
   L2700:
      ;
   }
   --out;
// 						!DECREMENT OUT COUNT.
   if (out > 0) {
      goto L2600;
   }
// 						!IF STILL OUT, GO AGAIN.
}

// Strike blow
int blow(int h, int v, int rmk, Bool hflg, int out) {
// Initialized data
   const int rmiss = 0;
   const int rout = 1;
   const int rkill = 2;
   const int rstag = 5;
   const int rlose = 6;
   const int rhes = 7;
   const int rsit = 8;
   static const int def1r[3] = { 1, 2, 3 };
   static const int def2r[4] = { 13, 23, 24, 25 };
   static const int def3r[5] = { 35, 36, 46, 47, 57 };
   static const int rvectr[66] = {
      0, 0, 0, 0, 5, 5, 1, 1, 2, 2, 2, 2,
      0, 0, 0, 0, 0, 5, 5, 3, 3, 1,
      0, 0, 0, 5, 5, 3, 3, 3, 1, 2, 2, 2,
      0, 0, 0, 0, 0, 5, 5, 3, 3, 4, 4,
      0, 0, 0, 5, 5, 3, 3, 3, 4, 4, 4,
      0, 5, 5, 3, 3, 3, 3, 4, 4, 4
   };
   static const int rstate[45] = {
      5000, 3005, 3008, 4011, 3015, 3018, 1021, 0, 0,
      5022, 3027, 3030, 4033, 3037, 3040, 1043, 0, 0,
      4044, 2048, 4050, 4054, 5058, 4063, 4067, 3071, 1074,
      4075, 1079, 4080, 4084, 4088, 4092, 4096, 4100, 1104,
      4105, 2109, 4111, 4115, 4119, 4123, 4127, 3131, 3134
   };

// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   int i, j, oa, ra, od, mi, dv, def;
   int tbl;
   int att, res;
   int dweap;
   int pblose;

// MISCELLANEOUS VARIABLES
   Bool f;

// BLOW, PAGE 3

   ra = objcts_1.oactio[(2644 + (0 + (v - 1 << 2)) - 2644) / 4];
// 						!GET VILLAIN ACTION,
   dv = objcts_1.odesc2[v - 1];
// 						!DESCRIPTION.
   ret_val = rmiss;
// 						!ASSUME NO RESULT.
// print(" BLOW 10-- %3I7%L7%I7", h, v, rmk, hflg, out); //F
   BegExSF(6, "(\2 BLOW 10-- \2,3i7,l7,i7)", 0);
   DoFio(1, &h, sizeof h), DoFio(1, &v, sizeof v), DoFio(1, &rmk, sizeof rmk);
   DoFio(1, &hflg, sizeof hflg), DoFio(1, &out, sizeof out);
   EndExSF();
   if (!(hflg)) {
      goto L1000;
   }
// 						!HERO STRIKING BLOW?

// HERO IS ATTACKER, VILLAIN IS DEFENDER.

   pblose = 10;
// 						!BAD LK PROB.
   objcts_1.oflag2[v - 1] |= FiteO;
   if ((advs_1.aflag[h - 1] & aflags_1.astag) == 0) {
      goto L100;
   }
   rspeak(591);
// 						!YES, CANT FIGHT.
   advs_1.aflag[h - 1] &= ~aflags_1.astag;
   return ret_val;

L100:
   att = fights(h, true);
// 						!GET HIS STRENGTH.
   oa = att;
   def = vilstr(v);
// 						!GET VILL STRENGTH.
   od = def;
   dweap = 0;
// 						!ASSUME NO WEAPON.
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!SEARCH VILLAIN.
      if (objcts_1.ocan[i - 1] == v && (objcts_1.oflag2[i - 1] & WeapO) != 0) {
         dweap = i;
      }
// L200:
   }
   if (v == advs_1.aobj[aindex_1.player - 1]) {
      goto L300;
   }
// 						!KILLING SELF?
   if (def != 0) {
      goto L2000;
   }
// 						!DEFENDER ALIVE?
   rspsub(592, dv);
// 						!VILLAIN DEAD.
   return ret_val;

L300:
   jigsup(593);
// 						!KILLING SELF.
   return ret_val;

// VILLAIN IS ATTACKER, HERO IS DEFENDER.

L1000:
   pblose = 50;
// 						!BAD LK PROB.
   advs_1.aflag[h - 1] &= ~aflags_1.astag;
   if ((objcts_1.oflag2[v - 1] & StagO) == 0) {
      goto L1200;
   }
   objcts_1.oflag2[v - 1] &= ~StagO;
   rspsub(594, dv);
// 						!DESCRIBE.
   return ret_val;

L1200:
   att = vilstr(v);
// 						!SET UP ATT, DEF.
   oa = att;
   def = fights(h, true);
   if (def <= 0) {
      return ret_val;
   }
// 						!DONT ALLOW DEAD DEF.
   od = fights(h, false);
   dweap = (i__1 = fwim(0, WeapO, 0, 0, h, true), abs(i__1));
// 						!FIND A WEAPON.
// BLOW, PAGE 4

// PARTIES ARE NOW EQUIPPED.  DEF CANNOT BE ZERO.
// ATT MUST BE > 0.

L2000:
// print(" BLOW 2050-- %5I7", att, oa, def, od, dweap); //F
   BegExSF(6, "(\2 BLOW 2050-- \2,5i7)", 0);
   DoFio(1, &att, sizeof att), DoFio(1, &oa, sizeof oa), DoFio(1, &def, sizeof def);
   DoFio(1, &od, sizeof od), DoFio(1, &dweap, sizeof dweap);
   EndExSF();
   if (def > 0) {
      goto L2100;
   }
// 						!DEF ALIVE?
   res = rkill;
   if (hflg) {
      rspsub(595, dv);
   }
// 						!DEADER.
   goto L3000;

L2100:
   if ((i__1 = def - 2) < 0) {
      goto L2200;
   } else if (i__1 == 0) {
      goto L2300;
   } else {
      goto L2400;
   }
// 						!DEF <2,=2,>2
L2200:
   att = min(att, 3);
// 						!SCALE ATT.
   tbl = def1r[att - 1];
// 						!CHOOSE TABLE.
   goto L2500;

L2300:
   att = min(att, 4);
// 						!SCALE ATT.
   tbl = def2r[att - 1];
// 						!CHOOSE TABLE.
   goto L2500;

L2400:
   att -= def;
// 						!SCALE ATT.
// Computing MIN
   i__1 = 2, i__2 = max(-2, att);
   att = min(i__1, i__2) + 3;
   tbl = def3r[att - 1];

L2500:
   res = rvectr[tbl + rnd(10) - 1];
// 						!GET RESULT.
   if (out == 0) {
      goto L2600;
   }
// 						!WAS HE OUT?
   if (res == rstag) {
      goto L2550;
   }
// 						!YES, STAG--> HES.
   res = rsit;
// 						!OTHERWISE, SITTING.
   goto L2600;
L2550:
   res = rhes;
L2600:
   if (res == rstag && dweap != 0 && prob(25, pblose)) {
      res = rlose;
   }

   mi = rstate[(rmk - 1) * 9 + res];
// 						!CHOOSE TABLE ENTRY.
   if (mi == 0) {
      goto L3000;
   }
   i__1 = mi / 1000;
   i = mi % 1000 + rnd(i__1) + star_1.mbase + 1;
   j = dv;
   if (!(hflg) && dweap != 0) {
      j = objcts_1.odesc2[dweap - 1];
   }
// print(" BLOW 2650-- %5I7", res, mi, i, j, star_i.mbase); //F
   BegExSF(6, "(\2 BLOW 2650-- \2,5i7)", 0);
   DoFio(1, &res, sizeof res), DoFio(1, &mi, sizeof mi), DoFio(1, &i, sizeof i), DoFio(1, &j, sizeof j);
   DoFio(1, &star_1.mbase, sizeof star_1.mbase);
   EndExSF();
   rspsub(i, j);
// 						!PRESENT RESULT.
// BLOW, PAGE 5

// NOW APPLY RESULT

L3000:
   switch (res + 1) {
      case 1:
         goto L4000;
      case 2:
         goto L3100;
      case 3:
         goto L3200;
      case 4:
         goto L3300;
      case 5:
         goto L3400;
      case 6:
         goto L3500;
      case 7:
         goto L3600;
      case 8:
         goto L4000;
      case 9:
         goto L3200;
   }

L3100:
   if (hflg) {
      def = -def;
   }
// 						!UNCONSCIOUS.
   goto L4000;

L3200:
   def = 0;
// 						!KILLED OR SITTING DUCK.
   goto L4000;

L3300:
// Computing MAX
   i__1 = 0, i__2 = def - 1;
   def = max(i__1, i__2);
// 						!LIGHT WOUND.
   goto L4000;

L3400:
// Computing MAX
   i__1 = 0, i__2 = def - 2;
   def = max(i__1, i__2);
// 						!SERIOUS WOUND.
   goto L4000;

L3500:
   if (hflg) {
      goto L3550;
   }
// 						!STAGGERED.
   advs_1.aflag[h - 1] |= aflags_1.astag;
   goto L4000;

L3550:
   objcts_1.oflag2[v - 1] |= StagO;
   goto L4000;

L3600:
   newsta(dweap, 0, play_1.here, 0, 0);
// 						!LOSE WEAPON.
   dweap = 0;
   if (hflg) {
      goto L4000;
   }
// 						!IF HERO, DONE.
   dweap = (i__1 = fwim(0, WeapO, 0, 0, h, true), abs(i__1));
// 						!GET NEW.
   if (dweap != 0) {
      rspsub(605, objcts_1.odesc2[dweap - 1]);
   }
// BLOW, PAGE 6

L4000:
   ret_val = res;
// 						!RETURN RESULT.
   if (!(hflg)) {
      goto L4500;
   }
// 						!HERO?
   objcts_1.ocapac[v - 1] = def;
// 						!STORE NEW CAPACITY.
   if (def != 0) {
      goto L4100;
   }
// 						!DEAD?
   objcts_1.oflag2[v - 1] &= ~FiteO;
   rspsub(572, dv);
// 						!HE DIES.
   newsta(v, 0, 0, 0, 0);
// 						!MAKE HIM DISAPPEAR.
   if (ra == 0) {
      return ret_val;
   }
// 						!IF NX TO DO, EXIT.
   prsvec_1.prsa = vindex_1.deadxw;
// 						!LET HIM KNOW.
   f = oappli(ra, 0);
   return ret_val;

L4100:
   if (res != rout || ra == 0) {
      return ret_val;
   }
   prsvec_1.prsa = vindex_1.outxw;
// 						!LET HIM BE OUT.
   f = oappli(ra, 0);
   return ret_val;

L4500:
   advs_1.astren[h - 1] = -10000;
// 						!ASSUME DEAD.
   if (def != 0) {
      advs_1.astren[h - 1] = def - od;
   }
   if (def >= od) {
      goto L4600;
   }
   cevent_1.ctick[cindex_1.cevcur - 1] = 30;
   cevent_1.cflag[cindex_1.cevcur - 1] = true;
L4600:
   if (fights(h, true) > 0) {
      return ret_val;
   }
   advs_1.astren[h - 1] = 1 - fights(h, false);
// 						!HE'S DEAD.
   jigsup(596);
   ret_val = -1;
   return ret_val;
}

// Sword intermove demon
void swordd(void) {
// System generated locals
   int i__1, i__2;

// Local variables
   int i, ng;

// SWORDD, PAGE 2

   if (objcts_1.oadv[oindex_1.sword - 1] != aindex_1.player) {
      goto L500;
   }
// 						!HOLDING SWORD?
   ng = 2;
// 						!ASSUME VILL CLOSE.
   if (infest(play_1.here)) {
      goto L300;
   }
// 						!VILL HERE?
   ng = 1;
   i__1 = xsrch_1.xmax;
   i__2 = xsrch_1.xmin;
   for (i = xsrch_1.xmin; i__2 < 0 ? i >= i__1 : i <= i__1; i += i__2) {
// 						!NO, SEARCH ROOMS.
      if (!findxt(i, play_1.here)) {
         goto L200;
      }
// 						!ROOM THAT WAY?
      switch (curxt_1.xtype) {
         case 1:
            goto L50;
         case 2:
            goto L200;
         case 3:
            goto L50;
         case 4:
            goto L50;
      }
// 						!SEE IF ROOM AT ALL.
   L50:
      if (infest(curxt_1.xroom1)) {
         goto L300;
      }
// 						!CHECK ROOM.
   L200:
      ;
   }
   ng = 0;
// 						!NO GLOW.

L300:
   if (ng == hack_1.swdsta) {
      return;
   }
// 						!ANY STATE CHANGE?
   i__2 = ng + 495;
   rspeak(i__2);
// 						!YES, TELL NEW STATE.
   hack_1.swdsta = ng;
   return;

L500:
   hack_1.swdact = false;
// 						!DROPPED SWORD,
// return;
// 						!DISABLE DEMON.
}

// Subroutine to test for infested room
static Bool infest(int r) {
// System generated locals
   Bool ret_val;

   if (!findex_1.endgmf) {
      ret_val = objcts_1.oroom[oindex_1.cyclo - 1] == r || objcts_1.oroom[oindex_1.troll - 1] == r || objcts_1.oroom[oindex_1.thief - 1] == r && hack_1.thfact;
   } else {
      ret_val = r == rindex_1.mrg || r == rindex_1.mrge || r == rindex_1.mrgw || r == rindex_1.inmir && findex_1.mloc == rindex_1.mrg;
   }
   return ret_val;
}
