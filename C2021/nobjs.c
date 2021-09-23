// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

static Bool mirpan(int, Bool);

// New objects processor
// Objects in this module cannot call rminfo(), jigsup(), major verbs, or other non-resident subroutines
Bool nobjs(int ri/*, int arg*/) {
// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   Bool f;
   int target;
   int i;
   int j;
   int av, wl;
   int nxt, odi2 = 0, odo2 = 0;

// NOBJS, PAGE 2

   if (prsvec.prso != 0) {
      odo2 = objcts.odesc2[prsvec.prso - 1];
   }
   if (prsvec.prsi != 0) {
      odi2 = objcts.odesc2[prsvec.prsi - 1];
   }
   av = advs.avehic[play.winner - 1];
   ret_val = true;

   switch (ri - 31) {
      case 1:
         goto L1000;
      case 2:
         goto L2000;
      case 3:
         goto L3000;
      case 4:
         goto L4000;
      case 5:
         goto L5000;
      case 6:
         goto L6000;
      case 7:
         goto L7000;
      case 8:
         goto L8000;
      case 9:
         goto L9000;
      case 10:
         goto L10000;
      case 11:
         goto L11000;
      case 12:
         goto L12000;
      case 13:
         goto L13000;
      case 14:
         goto L14000;
      case 15:
         goto L15000;
      case 16:
         goto L16000;
      case 17:
         goto L17000;
      case 18:
         goto L18000;
      case 19:
         goto L19000;
      case 20:
         goto L20000;
      case 21:
         goto L21000;
   }
   bug(6, ri);

// RETURN HERE TO DECLARE FALSE RESULT

L10:
   ret_val = false;
   return ret_val;

// O32--	BILLS

L1000:
   if (prsvec.prsa != vindex.eatw) {
      goto L1100;
   }
// 						!EAT?
   rspeak(639);
// 						!JOKE.
   return ret_val;

L1100:
   if (prsvec.prsa == vindex.burnw) {
      rspeak(640);
   }
// 						!BURN?  JOKE.
   goto L10;
// 						!LET IT BE HANDLED.
// NOBJS, PAGE 3

// O33--	SCREEN OF LIGHT

L2000:
   target = oindex.scol;
// 						!TARGET IS SCOL.
L2100:
   if (prsvec.prso != target) {
      goto L2400;
   }
// 						!PRSO EQ TARGET?
   if (prsvec.prsa != vindex.pushw && prsvec.prsa != vindex.movew && prsvec.prsa != vindex.takew && prsvec.prsa != vindex.rubw) {
      goto L2200;
   }
   rspeak(673);
// 						!HAND PASSES THRU.
   return ret_val;

L2200:
   if (prsvec.prsa != vindex.killw && prsvec.prsa != vindex.attacw && prsvec.prsa != vindex.mungw) {
      goto L2400;
   }
   rspsub(674, odi2);
// 						!PASSES THRU.
   return ret_val;

L2400:
   if (prsvec.prsa != vindex.throww || prsvec.prsi != target) {
      goto L10;
   }
   if (play.here == rindex_.bkbox) {
      goto L2600;
   }
// 						!THRU SCOL?
   newsta(prsvec.prso, 0, rindex_.bkbox, 0, 0);
// 						!NO, THRU WALL.
   rspsub(675, odo2);
// 						!ENDS UP IN BOX ROOM.
   cevent.ctick[cindex.cevscl - 1] = 0;
// 						!CANCEL ALARM.
   screen.scolrm = 0;
// 						!RESET SCOL ROOM.
   return ret_val;

L2600:
   if (screen.scolrm == 0) {
      goto L2900;
   }
// 						!TRIED TO GO THRU?
   newsta(prsvec.prso, 0, screen.scolrm, 0, 0);
// 						!SUCCESS.
   rspsub(676, odo2);
// 						!ENDS UP SOMEWHERE.
   cevent.ctick[cindex.cevscl - 1] = 0;
// 						!CANCEL ALARM.
   screen.scolrm = 0;
// 						!RESET SCOL ROOM.
   return ret_val;

L2900:
   rspeak(213);
// 						!CANT DO IT.
   return ret_val;
// NOBJS, PAGE 4

// O34--	GNOME OF ZURICH

L3000:
   if (prsvec.prsa != vindex.givew && prsvec.prsa != vindex.throww) {
      goto L3200;
   }
   if (objcts.otval[prsvec.prso - 1] != 0) {
      goto L3100;
   }
// 						!THROW A TREASURE?
   newsta(prsvec.prso, 641, 0, 0, 0);
// 						!NO, GO POP.
   return ret_val;

L3100:
   newsta(prsvec.prso, 0, 0, 0, 0);
// 						!YES, BYE BYE TREASURE.
   rspsub(642, odo2);
   newsta(oindex.zgnom, 0, 0, 0, 0);
// 						!BYE BYE GNOME.
   cevent.ctick[cindex.cevzgo - 1] = 0;
// 						!CANCEL EXIT.
   f = moveto(rindex_.bkent, play.winner);
// 						!NOW IN BANK ENTRANCE.
   return ret_val;

L3200:
   if (prsvec.prsa != vindex.attacw && prsvec.prsa != vindex.killw && prsvec.prsa != vindex.mungw) {
      goto L3300;
   }
   newsta(oindex.zgnom, 643, 0, 0, 0);
// 						!VANISH GNOME.
   cevent.ctick[cindex.cevzgo - 1] = 0;
// 						!CANCEL EXIT.
   return ret_val;

L3300:
   rspeak(644);
// 						!GNOME IS IMPATIENT.
   return ret_val;

// O35--	EGG

L4000:
   if (prsvec.prsa != vindex.openw || prsvec.prso != oindex.egg) {
      goto L4500;
   }
   if (!((objcts.oflag2[oindex.egg - 1] & OpenO) != 0)) {
      goto L4100;
   }
// 						!OPEN ALREADY?
   rspeak(649);
// 						!YES.
   return ret_val;

L4100:
   if (prsvec.prsi != 0) {
      goto L4200;
   }
// 						!WITH SOMETHING?
   rspeak(650);
// 						!NO, CANT.
   return ret_val;

L4200:
   if (prsvec.prsi != oindex.hands) {
      goto L4300;
   }
// 						!WITH HANDS?
   rspeak(651);
// 						!NOT RECOMMENDED.
   return ret_val;

L4300:
   i = 652;
// 						!MUNG MESSAGE.
   if ((objcts.oflag1[prsvec.prsi - 1] & ToolO) != 0 || (objcts.oflag2[prsvec.prsi - 1] & WeapO) != 0) {
      goto L4600;
   }
   i = 653;
// 						!NOVELTY 1.
   if ((objcts.oflag2[prsvec.prso - 1] & FiteO) != 0) {
      i = 654;
   }
   objcts.oflag2[prsvec.prso - 1] |= FiteO;
   rspsub(i, odi2);
   return ret_val;

L4500:
   if (prsvec.prsa != vindex.openw && prsvec.prsa != vindex.mungw) {
      goto L4800;
   }
   i = 655;
// 						!YOU BLEW IT.
L4600:
   newsta(oindex.begg, i, objcts.oroom[oindex.egg - 1], objcts.ocan[oindex.egg - 1], objcts.oadv[oindex.egg - 1]);
   newsta(oindex.egg, 0, 0, 0, 0);
// 						!VANISH EGG.
   objcts.otval[oindex.begg - 1] = 2;
// 						!BAD EGG HAS VALUE.
   if (objcts.ocan[oindex.canar - 1] != oindex.egg) {
      goto L4700;
   }
// 						!WAS CANARY INSIDE?
   rspeak(objcts.odesco[oindex.bcana - 1]);
// 						!YES, DESCRIBE RESULT.
   objcts.otval[oindex.bcana - 1] = 1;
   return ret_val;

L4700:
   newsta(oindex.bcana, 0, 0, 0, 0);
// 						!NO, VANISH IT.
   return ret_val;

L4800:
   if (prsvec.prsa != vindex.dropw || play.here != rindex_.mtree) {
      goto L10;
   }
   newsta(oindex.begg, 658, rindex_.fore3, 0, 0);
// 						!DROPPED EGG.
   newsta(oindex.egg, 0, 0, 0, 0);
   objcts.otval[oindex.begg - 1] = 2;
   if (objcts.ocan[oindex.canar - 1] != oindex.egg) {
      goto L4700;
   }
   objcts.otval[oindex.bcana - 1] = 1;
// 						!BAD CANARY.
   return ret_val;
// NOBJS, PAGE 5

// O36--	CANARIES, GOOD AND BAD

L5000:
   if (prsvec.prsa != vindex.windw) {
      goto L10;
   }
// 						!WIND EM UP?
   if (prsvec.prso == oindex.canar) {
      goto L5100;
   }
// 						!RIGHT ONE?
   rspeak(645);
// 						!NO, BAD NEWS.
   return ret_val;

L5100:
   if (!findex.singsf && (play.here == rindex_.mtree || play.here >= rindex_.fore1 && play.here < rindex_.clear)) {
      goto L5200;
   }
   rspeak(646);
// 						!NO, MEDIOCRE NEWS.
   return ret_val;

L5200:
   findex.singsf = true;
// 						!SANG SONG.
   i = play.here;
   if (i == rindex_.mtree) {
      i = rindex_.fore3;
   }
// 						!PLACE BAUBLE.
   newsta(oindex.baubl, 647, i, 0, 0);
   return ret_val;

// O37--	WHITE CLIFFS

L6000:
   if (prsvec.prsa != vindex.clmbw && prsvec.prsa != vindex.clmbuw && prsvec.prsa != vindex.clmbdw) {
      goto L10;
   }
   rspeak(648);
// 						!OH YEAH?
   return ret_val;

// O38--	WALL

L7000:
   if ((i__1 = play.here - findex.mloc, abs(i__1)) != 1 || mrhere(play.here) != 0 || prsvec.prsa != vindex.pushw) {
      goto L7100;
   }
   rspeak(860);
// 						!PUSHED MIRROR WALL.
   return ret_val;

L7100:
   if ((rooms.rflag[play.here - 1] & NWallR) == 0) {
      goto L10;
   }
   rspeak(662);
// 						!NO WALL.
   return ret_val;
// NOBJS, PAGE 6

// O39--	SONG BIRD GLOBAL

L8000:
   if (prsvec.prsa != vindex.findw) {
      goto L8100;
   }
// 						!FIND?
   rspeak(666);
   return ret_val;

L8100:
   if (prsvec.prsa != vindex.examiw) {
      goto L10;
   }
// 						!EXAMINE?
   rspeak(667);
   return ret_val;

// O40--	PUZZLE/SCOL WALLS

L9000:
   if (play.here != rindex_.cpuzz) {
      goto L9500;
   }
// 						!PUZZLE WALLS?
   if (prsvec.prsa != vindex.pushw) {
      goto L10;
   }
// 						!PUSH?
   for (i = 1; i <= 8; i += 2) {
// 						!LOCATE WALL.
      if (prsvec.prso == puzzle.cpwl[i - 1]) {
         goto L9200;
      }
// L9100:
   }
   bug(80, prsvec.prso);
// 						!WHAT?

L9200:
   j = puzzle.cpwl[i];
// 						!GET DIRECTIONAL OFFSET.
   nxt = findex.cphere + j;
// 						!GET NEXT STATE.
   wl = puzzle.cpvec[nxt - 1];
// 						!GET C(NEXT STATE).
   switch (wl + 4) {
      case 1:
         goto L9300;
      case 2:
         goto L9300;
      case 3:
         goto L9300;
      case 4:
         goto L9250;
      case 5:
         goto L9350;
   }
// 						!PROCESS.

L9250:
   rspeak(876);
// 						!CLEAR CORRIDOR.
   return ret_val;

L9300:
   if (puzzle.cpvec[nxt + j - 1] == 0) {
      goto L9400;
   }
// 						!MOVABLE, ROOM TO MOVE?
L9350:
   rspeak(877);
// 						!IMMOVABLE, NO ROOM.
   return ret_val;

L9400:
   i = 878;
// 						!ASSUME FIRST PUSH.
   if (findex.cpushf) {
      i = 879;
   }
// 						!NOT?
   findex.cpushf = true;
   puzzle.cpvec[nxt + j - 1] = wl;
// 						!MOVE WALL.
   puzzle.cpvec[nxt - 1] = 0;
// 						!VACATE NEXT STATE.
   cpgoto(nxt);
// 						!ONWARD.
   cpinfo(i, nxt);
// 						!DESCRIBE.
   princr(true, play.here);
// 						!PRINT ROOMS CONTENTS.
   rooms.rflag[play.here - 1] |= SeenR;
   return ret_val;

L9500:
   if (play.here != screen.scolac) {
      goto L9700;
   }
// 						!IN SCOL ACTIVE ROOM?
   for (i = 1; i <= 12; i += 3) {
      target = screen.scolwl[i];
// 						!ASSUME TARGET.
      if (screen.scolwl[i - 1] == play.here) {
         goto L2100;
      }
// 						!TREAT IF FOUND.
// L9600:
   }

L9700:
   if (play.here != rindex_.bkbox) {
      goto L10;
   }
// 						!IN BOX ROOM?
   target = oindex.wnort;
   goto L2100;
// NOBJS, PAGE 7

// O41--	SHORT POLE

L10000:
   if (prsvec.prsa != vindex.raisew) {
      goto L10100;
   }
// 						!LIFT?
   i = 749;
// 						!ASSUME UP.
   if (findex.poleuf == 2) {
      i = 750;
   }
// 						!ALREADY UP?
   rspeak(i);
   findex.poleuf = 2;
// 						!POLE IS RAISED.
   return ret_val;

L10100:
   if (prsvec.prsa != vindex.lowerw && prsvec.prsa != vindex.pushw) {
      goto L10;
   }
   if (findex.poleuf != 0) {
      goto L10200;
   }
// 						!ALREADY LOWERED?
   rspeak(751);
// 						!CANT DO IT.
   return ret_val;

L10200:
   if (findex.mdir % 180 != 0) {
      goto L10300;
   }
// 						!MIRROR N-S?
   findex.poleuf = 0;
// 						!YES, LOWER INTO
   rspeak(752);
// 						!CHANNEL.
   return ret_val;

L10300:
   if (findex.mdir != 270 || findex.mloc != rindex_.mrb) {
      goto L10400;
   }
   findex.poleuf = 0;
// 						!LOWER INTO HOLE.
   rspeak(753);
   return ret_val;

L10400:
   i__1 = findex.poleuf + 753;
   rspeak(i__1);
// 						!POLEUF = 1 OR 2.
   findex.poleuf = 1;
// 						!NOW ON FLOOR.
   return ret_val;

// O42--	MIRROR SWITCH

L11000:
   if (prsvec.prsa != vindex.pushw) {
      goto L10;
   }
// 						!PUSH?
   if (findex.mrpshf) {
      goto L11300;
   }
// 						!ALREADY PUSHED?
   rspeak(756);
// 						!BUTTON GOES IN.
   i__1 = objcts.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!BLOCKED?
      if (qhere(i, rindex_.mreye) && i != oindex.rbeam) {
         goto L11200;
      }
// L11100:
   }
   rspeak(757);
// 						!NOTHING IN BEAM.
   return ret_val;

L11200:
   cevent.cflag[cindex.cevmrs - 1] = true;
// 						!MIRROR OPENS.
   cevent.ctick[cindex.cevmrs - 1] = 7;
   findex.mrpshf = true;
   findex.mropnf = true;
   return ret_val;

L11300:
   rspeak(758);
// 						!MIRROR ALREADYOPEN.
   return ret_val;
// NOBJS, PAGE 8

// O43--	BEAM FUNCTION

L12000:
   if (prsvec.prsa != vindex.takew || prsvec.prso != oindex.rbeam) {
      goto L12100;
   }
   rspeak(759);
// 						!TAKE BEAM, JOKE.
   return ret_val;

L12100:
   i = prsvec.prso;
// 						!ASSUME BLK WITH DIROBJ.
   if (prsvec.prsa == vindex.putw && prsvec.prsi == oindex.rbeam) {
      goto L12200;
   }
   if (prsvec.prsa != vindex.mungw || prsvec.prso != oindex.rbeam || prsvec.prsi == 0) {
      goto L10;
   }
   i = prsvec.prsi;
L12200:
   if (objcts.oadv[i - 1] != play.winner) {
      goto L12300;
   }
// 						!CARRYING?
   newsta(i, 0, play.here, 0, 0);
// 						!DROP OBJ.
   rspsub(760, objcts.odesc2[i - 1]);
   return ret_val;

L12300:
   j = 761;
// 						!ASSUME NOT IN ROOM.
   if (qhere(j, play.here)) {
      i = 762;
   }
// 						!IN ROOM?
   rspsub(j, objcts.odesc2[i - 1]);
// 						!DESCRIBE.
   return ret_val;

// O44--	BRONZE DOOR

L13000:
   if (play.here == rindex_.ncell || findex.lcell == 4 && (play.here == rindex_.cell || play.here == rindex_.scorr)) {
      goto L13100;
   }
   rspeak(763);
// 						!DOOR NOT THERE.
   return ret_val;

L13100:
   if (!opncls(oindex.odoor, 764, 765)) {
      goto L10;
   }
// 						!OPEN/CLOSE?
   if (play.here == rindex_.ncell && (objcts.oflag2[oindex.odoor - 1] & OpenO) != 0) {
      rspeak(766);
   }
   return ret_val;

// O45--	QUIZ DOOR

L14000:
   if (prsvec.prsa != vindex.openw && prsvec.prsa != vindex.closew) {
      goto L14100;
   }
   rspeak(767);
// 						!DOOR WONT MOVE.
   return ret_val;

L14100:
   if (prsvec.prsa != vindex.knockw) {
      goto L10;
   }
// 						!KNOCK?
   if (findex.inqstf) {
      goto L14200;
   }
// 						!TRIED IT ALREADY?
   findex.inqstf = true;
// 						!START INQUISITION.
   cevent.cflag[cindex.cevinq - 1] = true;
   cevent.ctick[cindex.cevinq - 1] = 2;
   findex.quesno = rnd(8);
// 						!SELECT QUESTION.
   findex.nqatt = 0;
   findex.corrct = 0;
   rspeak(768);
// 						!ANNOUNCE RULES.
   rspeak(769);
   i__1 = findex.quesno + 770;
   rspeak(i__1);
// 						!ASK QUESTION.
   return ret_val;

L14200:
   rspeak(798);
// 						!NO REPLY.
   return ret_val;

// O46--	LOCKED DOOR

L15000:
   if (prsvec.prsa != vindex.openw) {
      goto L10;
   }
// 						!OPEN?
   rspeak(778);
// 						!CANT.
   return ret_val;

// O47--	CELL DOOR

L16000:
   ret_val = opncls(oindex.cdoor, 779, 780);
// 						!OPEN/CLOSE?
   return ret_val;
// NOBJS, PAGE 9

// O48--	DIALBUTTON

L17000:
   if (prsvec.prsa != vindex.pushw) {
      goto L10;
   }
// 						!PUSH?
   rspeak(809);
// 						!CLICK.
   if ((objcts.oflag2[oindex.cdoor - 1] & OpenO) != 0) {
      rspeak(810);
   }
// 						!CLOSE CELL DOOR.

   i__1 = objcts.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!RELOCATE OLD TO HYPER.
      if (objcts.oroom[i - 1] == rindex_.cell && (objcts.oflag1[i - 1] & DoorO) == 0) {
         i__2 = findex.lcell * hyper.hfactr;
         newsta(i, 0, i__2, 0, 0);
      }
      if (objcts.oroom[i - 1] == findex.pnumb * hyper.hfactr) {
         newsta(i, 0, rindex_.cell, 0, 0);
      }
// L17100:
   }

   objcts.oflag2[oindex.odoor - 1] &= ~OpenO;
   objcts.oflag2[oindex.cdoor - 1] &= ~OpenO;
   objcts.oflag1[oindex.odoor - 1] &= ~VisiO;
   if (findex.pnumb == 4) {
      objcts.oflag1[oindex.odoor - 1] |= VisiO;
   }

   if (advs.aroom[aindex.player - 1] != rindex_.cell) {
      goto L17400;
   }
// 						!PLAYER IN CELL?
   if (findex.lcell != 4) {
      goto L17200;
   }
// 						!IN RIGHT CELL?
   objcts.oflag1[oindex.odoor - 1] |= VisiO;
   f = moveto(rindex_.ncell, aindex.player);
// 						!YES, MOVETO NCELL.
   goto L17400;
L17200:
   f = moveto(rindex_.pcell, aindex.player);
// 						!NO, MOVETO PCELL.

L17400:
   findex.lcell = findex.pnumb;
   return ret_val;
// NOBJS, PAGE 10

// O49--	DIAL INDICATOR

L18000:
   if (prsvec.prsa != vindex.spinw) {
      goto L18100;
   }
// 						!SPIN?
   findex.pnumb = rnd(8) + 1;
// 						!WHEE
// 						!
   i__1 = findex.pnumb + 712;
   rspsub(797, i__1);
   return ret_val;

L18100:
   if (prsvec.prsa != vindex.movew && prsvec.prsa != vindex.putw && prsvec.prsa != vindex.trntow) {
      goto L10;
   }
   if (prsvec.prsi != 0) {
      goto L18200;
   }
// 						!TURN DIAL TO X?
   rspeak(806);
// 						!MUST SPECIFY.
   return ret_val;

L18200:
   if (prsvec.prsi >= oindex.num1 && prsvec.prsi <= oindex.num8) {
      goto L18300;
   }
   rspeak(807);
// 						!MUST BE DIGIT.
   return ret_val;

L18300:
   findex.pnumb = prsvec.prsi - oindex.num1 + 1;
// 						!SET UP NEW.
   i__1 = findex.pnumb + 712;
   rspsub(808, i__1);
   return ret_val;

// O50--	GLOBAL MIRROR

L19000:
   ret_val = mirpan(832, false);
   return ret_val;

// O51--	GLOBAL PANEL

L20000:
   if (play.here != rindex_.fdoor) {
      goto L20100;
   }
// 						!AT FRONT DOOR?
   if (prsvec.prsa != vindex.openw && prsvec.prsa != vindex.closew) {
      goto L10;
   }
   rspeak(843);
// 						!PANEL IN DOOR, NOGO.
   return ret_val;

L20100:
   ret_val = mirpan(838, true);
   return ret_val;

// O52--	PUZZLE ROOM SLIT

L21000:
   if (prsvec.prsa != vindex.putw || prsvec.prsi != oindex.cslit) {
      goto L10;
   }
   if (prsvec.prso != oindex.gcard) {
      goto L21100;
   }
// 						!PUT CARD IN SLIT?
   newsta(prsvec.prso, 863, 0, 0, 0);
// 						!KILL CARD.
   findex.cpoutf = true;
// 						!OPEN DOOR.
   objcts.oflag1[oindex.stldr - 1] &= ~VisiO;
   return ret_val;

L21100:
   if ((objcts.oflag1[prsvec.prso - 1] & VictO) == 0 && (objcts.oflag2[prsvec.prso - 1] & VillO) == 0) {
      goto L21200;
   }
   i__1 = rnd(5) + 552;
   rspeak(i__1);
// 						!JOKE FOR VILL, VICT.
   return ret_val;

L21200:
   newsta(prsvec.prso, 0, 0, 0, 0);
// 						!KILL OBJECT.
   rspsub(864, odo2);
// 						!DESCRIBE.
   return ret_val;
}

// Processor for global mirror/panel
static Bool mirpan(int st, Bool pnf) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   int num;
   int mrbf;

// MIRPAN, PAGE 2

   ret_val = true;
   num = mrhere(play.here);
// 						!GET MIRROR NUM.
   if (num != 0) {
      goto L100;
   }
// 						!ANY HERE?
   rspeak(st);
// 						!NO, LOSE.
   return ret_val;

L100:
   mrbf = 0;
// 						!ASSUME MIRROR OK.
   if (num == 1 && !findex.mr1f || num == 2 && !findex.mr2f) {
      mrbf = 1;
   }
   if (prsvec.prsa != vindex.movew && prsvec.prsa != vindex.openw) {
      goto L200;
   }
   i__1 = st + 1;
   rspeak(i__1);
// 						!CANT OPEN OR MOVE.
   return ret_val;

L200:
   if (pnf || prsvec.prsa != vindex.lookiw && prsvec.prsa != vindex.examiw && prsvec.prsa != vindex.lookw) {
      goto L300;
   }
   i__1 = mrbf + 844;
   rspeak(i__1);
// 						!LOOK IN MIRROR.
   return ret_val;

L300:
   if (prsvec.prsa != vindex.mungw) {
      goto L400;
   }
// 						!BREAK?
   i__1 = st + 2 + mrbf;
   rspeak(i__1);
// 						!DO IT.
   if (num == 1 && !(pnf)) {
      findex.mr1f = false;
   }
   if (num == 2 && !(pnf)) {
      findex.mr2f = false;
   }
   return ret_val;

L400:
   if (pnf || mrbf == 0) {
      goto L500;
   }
// 						!BROKEN MIRROR?
   rspeak(846);
   return ret_val;

L500:
   if (prsvec.prsa != vindex.pushw) {
      goto L600;
   }
// 						!PUSH?
   i__1 = st + 3 + num;
   rspeak(i__1);
   return ret_val;

L600:
   ret_val = false;
// 						!CANT HANDLE IT.
   return ret_val;
}
