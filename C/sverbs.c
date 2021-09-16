#include "F2C.h"

// parser.h:

// PARSER OUTPUT

extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;
#define prsvec_1 prsvec_

// PARSER STATE

extern struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;
#define orphs_1 orphs_
#define orp ((int *)&orphs_1)

extern struct {
   int lastit;
} last_;
#define last_1 last_

extern struct {
   int act, o1, o2;
   char p1[6], p2[6];
} pv_;
#define pv_1 pv_
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

extern struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;
#define syntax_1 syntax_
#define syn ((int *)&syntax_1)

extern struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;
#define synflg_1 synflg_

extern struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;
#define objflg_1 objflg_

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

// screen.h:

// SCREEN OF LIGHT

extern struct {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;
#define screen_1 screen_

// vers.h: (Unlisted)
extern struct {
   int vmaj, vmin;
   char vedit[1];
} vers_;
#define vers_1 vers_

// io.h:

// I/O VARIABLES

extern struct {
   int inlnt;
   char inbuf[78];
} input_;
#define input_1 input_

extern struct {
   int inpch, outch, dbch;
} chan_;
#define chan_1 chan_

// rooms.h:

// ROOMS

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;
#define rooms_1 rooms_
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)

// rflag.h:

extern struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;
#define rflag_1 rflag_

// rindex.h:

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// exits.h:

// EXITS

extern struct {
   int xlnt, travel[900];
} exits_;
#define exits_1 exits_

// curxt.h:

// CURRENT EXITS

extern struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;
#define curxt_1 curxt_
#define xflag ((int *)&curxt_1 + 4)

// xpars.h:

extern struct {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;
#define xpars_1 xpars_

// xsrch.h:

extern struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;
#define xsrch_1 xsrch_

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

extern struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;
#define oflags_1 oflags_

// oindex.h:

extern struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;
#define oindex_1 oindex_

// clock.h:

// CLOCK INTERRUPTS

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;
#define cevent_1 cevent_
#define eqc ((int *)&cevent_1 + 1)

extern struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;
#define cindex_1 cindex_

// advers.h:

// ADVENTURERS

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;
#define advs_1 advs_
#define eqa ((int *)&advs_1 + 1)

extern struct {
   int astag;
} aflags_;
#define aflags_1 aflags_

extern struct {
   int player, arobot, amastr;
} aindex_;
#define aindex_1 aindex_

// verbs.h:

// VERBS

extern struct {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;
#define vindex_1 vindex_

// flags.h:

// FLAGS

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;
#define findex_1 findex_
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// SVERBS-	SIMPLE VERBS PROCESSOR
// 	ALL VERBS IN THIS ROUTINE MUST BE INDEPENDANT
// 	OF OBJECT ACTIONS

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool sverbs_(int ri) {
// Initialized data

   static int mxnop = 39;
   static int mxjoke = 64;
   static int jokes[25] = {
      4, 5, 3, 304, 305, 306, 307, 308, 309, 310, 311, 312,
      313, 5314, 5319, 324, 325, 883, 884, 120, 120, 0, 0, 0, 0
   };
   static int answer[28] = {
      0, 6, 1, 6, 2, 5, 3, 5, 4, 3, 4, 6, 4, 6, 4, 5, 5, 5, 5, 4, 5, 6,
      6, 10, 7, 4, 7, 6
   };
   static char ansstr[1 * 78] =
      "T" "E" "M" "P" "L" "E" "F" "O" "R" "E" "S" "T" "3" "0" "0" "0" "3" "F" "L" "A" "S" "K" "R" "U" "B" "F" "O" "N" "D" "L" "E" "C" "A" "R" "R" "E" "S" "T" "O" "U" "C" "H" "B" "O" "N" "E" "S" "B" "O" "D" "Y" "S" "K" "E" "L" "E" "T" "R" "U" "S" "T" "Y"
      "K" "N" "I" "F" "E" "N" "O" "N" "E" "N" "O" "W" "H" "E" "R" "\000";

// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   static Bool f;
   static int i__, j;
   extern void rspeak_(int);
   extern void jigsup_(int);
   extern void newsta_(int, int, int, int, int);
   extern void score_(Bool);
   extern void rspsub_(int, int);
   extern int gttime_(void);
   static int k;
   extern int fights_(int, Bool);
   static int l;
   extern void encryp_(const char *, char * /*, size_t, size_t*/);
   static char ch[1 * 6];
   static int cp, wp;
   extern void bug_(int, int);
   extern int rnd_(int);
   static int odi2, odo2;
   extern void exit_(void);
   static int newk;
   extern Bool qhere_(int, int);
   extern Bool yesno_(int, int, int);
   extern Bool rmdesc_(int);
   extern Bool findxt_(int, int);
   extern Bool moveto_(int, int);

// MISCELLANEOUS VARIABLES

// FUNCTIONS AND DATA

// SVERBS, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prso != 0) {
      odo2 = objcts_1.odesc2[prsvec_1.prso - 1];
   }
// 						!SET UP DESCRIPTORS.
   if (prsvec_1.prsi != 0) {
      odi2 = objcts_1.odesc2[prsvec_1.prsi - 1];
   }

   if (ri == 0) {
      bug_(7, ri);
   }
// 						!ZERO IS VERBOTEN.
   if (ri <= mxnop) {
      return ret_val;
   }
// 						!NOP?
   if (ri <= mxjoke) {
      goto L100;
   }
// 						!JOKE?
   switch (ri - mxjoke) {
      case 1:
         goto L65000;
      case 2:
         goto L66000;
      case 3:
         goto L67000;
      case 4:
         goto L68000;
      case 5:
         goto L69000;
      case 6:
         goto L1000;
      case 7:
         goto L2000;
      case 8:
         goto L3000;
      case 9:
         goto L4000;
      case 10:
         goto L5000;
      case 11:
         goto L6000;
      case 12:
         goto L7000;
      case 13:
         goto L8000;
      case 14:
         goto L9000;
      case 15:
         goto L10000;
      case 16:
         goto L11000;
      case 17:
         goto L12000;
      case 18:
         goto L13000;
      case 19:
         goto L14000;
      case 20:
         goto L15000;
      case 21:
         goto L16000;
      case 22:
         goto L17000;
      case 23:
         goto L18000;
      case 24:
         goto L19000;
      case 25:
         goto L20000;
      case 26:
         goto L21000;
      case 27:
         goto L22000;
      case 28:
         goto L23000;
      case 29:
         goto L24000;
      case 30:
         goto L25000;
      case 31:
         goto L26000;
      case 32:
         goto L27000;
   }
   bug_(7, ri);

// ALL VERB PROCESSORS RETURN HERE TO DECLARE FAILURE.

//L10:
   ret_val = false;
// 						!LOSE.
   return ret_val;

// JOKE PROCESSOR.
// FIND PROPER ENTRY IN JOKES, USE IT TO SELECT STRING TO PRINT.

L100:
   i__ = jokes[ri - mxnop - 1];
// 						!GET TABLE ENTRY.
   j = i__ / 1000;
// 						!ISOLATE # STRINGS.
   if (j != 0) {
      i__ = i__ % 1000 + rnd_(j);
   }
// 						!IF RANDOM, CHOOSE.
   rspeak_(i__);
// 						!PRINT JOKE.
   return ret_val;
// SVERBS, PAGE 2A

// V65--	ROOM

L65000:
   ret_val = rmdesc_(2);
// 						!DESCRIBE ROOM ONLY.
   return ret_val;

// V66--	OBJECTS

L66000:
   ret_val = rmdesc_(1);
// 						!DESCRIBE OBJ ONLY.
   if (!play_1.telflg) {
      rspeak_(138);
   }
// 						!NO OBJECTS.
   return ret_val;

// V67--	RNAME

L67000:
   i__1 = rooms_1.rdesc2 - play_1.here;
   rspeak_(i__1);
// 						!SHORT ROOM NAME.
   return ret_val;

// V68--	RESERVED

L68000:
   return ret_val;

// V69--	RESERVED

L69000:
   return ret_val;
// SVERBS, PAGE 3

// V70--	BRIEF.  SET FLAG.

L1000:
   findex_1.brieff = true;
// 						!BRIEF DESCRIPTIONS.
   findex_1.superf = false;
   rspeak_(326);
   return ret_val;

// V71--	VERBOSE.  CLEAR FLAGS.

L2000:
   findex_1.brieff = false;
// 						!LONG DESCRIPTIONS.
   findex_1.superf = false;
   rspeak_(327);
   return ret_val;

// V72--	SUPERBRIEF.  SET FLAG.

L3000:
   findex_1.superf = true;
   rspeak_(328);
   return ret_val;

// V73-- STAY (USED IN ENDGAME).

L4000:
   if (play_1.winner != aindex_1.amastr) {
      goto L4100;
   }
// 						!TELL MASTER, STAY.
   rspeak_(781);
// 						!HE DOES.
   cevent_1.ctick[cindex_1.cevfol - 1] = 0;
// 						!NOT FOLLOWING.
   return ret_val;

L4100:
   if (play_1.winner == aindex_1.player) {
      rspeak_(664);
   }
// 						!JOKE.
   return ret_val;

// V74--	VERSION.  PRINT INFO.

L5000:
   BegExSF(chan_1.outch, /*5010*/"(\002 V\002,i1,\002.\002,i2,a1)", 0);
   DoFio(1, &vers_1.vmaj, sizeof vers_1.vmaj);
   DoFio(1, &vers_1.vmin, sizeof vers_1.vmin);
   DoFio(1, vers_1.vedit, sizeof vers_1.vedit[0]);
   EndExSF();
   play_1.telflg = true;
   return ret_val;

// V75--	SWIM.  ALWAYS A JOKE.

L6000:
   i__ = 330;
// 						!ASSUME WATER.
   if ((rooms_1.rflag[play_1.here - 1] & rflag_1.rwater + rflag_1.rfill) == 0) {
      i__ = rnd_(3) + 331;
   }
   rspeak_(i__);
   return ret_val;

// V76--	GERONIMO.  IF IN BARREL, FATAL, ELSE JOKE.

L7000:
   if (play_1.here == rindex_1.mbarr) {
      goto L7100;
   }
// 						!IN BARREL?
   rspeak_(334);
// 						!NO, JOKE.
   return ret_val;

L7100:
   jigsup_(335);
// 						!OVER FALLS.
   return ret_val;

// V77--	SINBAD ET AL.  CHASE CYCLOPS, ELSE JOKE.

L8000:
   if (play_1.here == rindex_1.mcycl && qhere_(oindex_1.cyclo, play_1.here)) {
      goto L8100;
   }
   rspeak_(336);
// 						!NOT HERE, JOKE.
   return ret_val;

L8100:
   newsta_(oindex_1.cyclo, 337, 0, 0, 0);
// 						!CYCLOPS FLEES.
   findex_1.cyclof = true;
// 						!SET ALL FLAGS.
   findex_1.magicf = true;
   objcts_1.oflag2[oindex_1.cyclo - 1] &= ~oflags_1.fitebt;
   return ret_val;

// V78--	WELL.  OPEN DOOR, ELSE JOKE.

L9000:
   if (findex_1.riddlf || play_1.here != rindex_1.riddl) {
      goto L9100;
   }
// 						!IN RIDDLE ROOM?
   findex_1.riddlf = true;
// 						!YES, SOLVED IT.
   rspeak_(338);
   return ret_val;

L9100:
   rspeak_(339);
// 						!WELL, WHAT?
   return ret_val;

// V79--	PRAY.  IF IN TEMP2, POOF
// 						!

L10000:
   if (play_1.here != rindex_1.temp2) {
      goto L10050;
   }
// 						!IN TEMPLE?
   if (moveto_(rindex_1.fore1, play_1.winner)) {
      goto L10100;
   }
// 						!FORE1 STILL THERE?
L10050:
   rspeak_(340);
// 						!JOKE.
   return ret_val;

L10100:
   f = rmdesc_(3);
// 						!MOVED, DESCRIBE.
   return ret_val;

// V80--	TREASURE.  IF IN TEMP1, POOF
// 						!

L11000:
   if (play_1.here != rindex_1.temp1) {
      goto L11050;
   }
// 						!IN TEMPLE?
   if (moveto_(rindex_1.treas, play_1.winner)) {
      goto L10100;
   }
// 						!TREASURE ROOM THERE?
L11050:
   rspeak_(341);
// 						!NOTHING HAPPENS.
   return ret_val;

// V81--	TEMPLE.  IF IN TREAS, POOF
// 						!

L12000:
   if (play_1.here != rindex_1.treas) {
      goto L12050;
   }
// 						!IN TREASURE?
   if (moveto_(rindex_1.temp1, play_1.winner)) {
      goto L10100;
   }
// 						!TEMP1 STILL THERE?
L12050:
   rspeak_(341);
// 						!NOTHING HAPPENS.
   return ret_val;

// V82--	BLAST.  USUALLY A JOKE.

L13000:
   i__ = 342;
// 						!DONT UNDERSTAND.
   if (prsvec_1.prso == oindex_1.safe) {
      i__ = 252;
   }
// 						!JOKE FOR SAFE.
   rspeak_(i__);
   return ret_val;

// V83--	SCORE.  PRINT SCORE.

L14000:
   score_(false);
   return ret_val;

// V84--	QUIT.  FINISH OUT THE GAME.

L15000:
   score_(true);
// 						!TELLL SCORE.
   if (!yesno_(343, 0, 0)) {
      return ret_val;
   }
// 						!ASK FOR Y/N DECISION.
   CloseF(chan_1.dbch);
   exit_();
// 						!BYE.
// SVERBS, PAGE 4

// V85--	FOLLOW (USED IN ENDGAME)

L16000:
   if (play_1.winner != aindex_1.amastr) {
      return ret_val;
   }
// 						!TELL MASTER, FOLLOW.
   rspeak_(782);
   cevent_1.ctick[cindex_1.cevfol - 1] = -1;
// 						!STARTS FOLLOWING.
   return ret_val;

// V86--	WALK THROUGH

L17000:
   if (screen_1.scolrm == 0 || prsvec_1.prso != oindex_1.scol && (prsvec_1.prso != oindex_1.wnort || play_1.here != rindex_1.bkbox)) {
      goto L17100;
   }
   screen_1.scolac = screen_1.scolrm;
// 						!WALKED THRU SCOL.
   prsvec_1.prso = 0;
// 						!FAKE OUT FROMDR.
   cevent_1.ctick[cindex_1.cevscl - 1] = 6;
// 						!START ALARM.
   rspeak_(668);
// 						!DISORIENT HIM.
   f = moveto_(screen_1.scolrm, play_1.winner);
// 						!INTO ROOM.
   f = rmdesc_(3);
// 						!DESCRIBE.
   return ret_val;

L17100:
   if (play_1.here != screen_1.scolac) {
      goto L17300;
   }
// 						!ON OTHER SIDE OF SCOL?
   for (i__ = 1; i__ <= 12; i__ += 3) {
// 						!WALK THRU PROPER WALL?
      if (screen_1.scolwl[i__ - 1] == play_1.here && screen_1.scolwl[i__] == prsvec_1.prso) {
         goto L17500;
      }
// L17200:
   }

L17300:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) != 0) {
      goto L17400;
   }
   i__ = 669;
// 						!NO, JOKE.
   if (prsvec_1.prso == oindex_1.scol) {
      i__ = 670;
   }
// 						!SPECIAL JOKE FOR SCOL.
   rspsub_(i__, odo2);
   return ret_val;

L17400:
   i__ = 671;
// 						!JOKE.
   if (objcts_1.oroom[prsvec_1.prso - 1] != 0) {
      i__ = rnd_(5) + 552;
   }
// 						!SPECIAL JOKES IF CARRY.
   rspeak_(i__);
   return ret_val;

L17500:
   prsvec_1.prso = screen_1.scolwl[i__ + 1];
// 						!THRU SCOL WALL...
   for (i__ = 1; i__ <= 8; i__ += 2) {
// 						!FIND MATCHING ROOM.
      if (prsvec_1.prso == screen_1.scoldr[i__ - 1]) {
         screen_1.scolrm = screen_1.scoldr[i__];
      }
// L17600:
   }
// 						!DECLARE NEW SCOLRM.
   cevent_1.ctick[cindex_1.cevscl - 1] = 0;
// 						!CANCEL ALARM.
   rspeak_(668);
// 						!DISORIENT HIM.
   f = moveto_(rindex_1.bkbox, play_1.winner);
// 						!BACK IN BOX ROOM.
   f = rmdesc_(3);
   return ret_val;

// V87--	RING.  A JOKE.

L18000:
   i__ = 359;
// 						!CANT RING.
   if (prsvec_1.prso == oindex_1.bell) {
      i__ = 360;
   }
// 						!DING, DONG.
   rspeak_(i__);
// 						!JOKE.
   return ret_val;

// V88--	BRUSH.  JOKE WITH OBSCURE TRAP.

L19000:
   if (prsvec_1.prso == oindex_1.teeth) {
      goto L19100;
   }
// 						!BRUSH TEETH?
   rspeak_(362);
// 						!NO, JOKE.
   return ret_val;

L19100:
   if (prsvec_1.prsi != 0) {
      goto L19200;
   }
// 						!WITH SOMETHING?
   rspeak_(363);
// 						!NO, JOKE.
   return ret_val;

L19200:
   if (prsvec_1.prsi == oindex_1.putty && objcts_1.oadv[oindex_1.putty - 1] == play_1.winner) {
      goto L19300;
   }
   rspsub_(364, odi2);
// 						!NO, JOKE.
   return ret_val;

L19300:
   jigsup_(365);
// 						!YES, DEAD
// 						!
// 						!
// 						!
// 						!
// 						!
   return ret_val;
// SVERBS, PAGE 5

// V89--	DIG.  UNLESS SHOVEL, A JOKE.

L20000:
   if (prsvec_1.prso == oindex_1.shove) {
      return ret_val;
   }
// 						!SHOVEL?
   i__ = 392;
// 						!ASSUME TOOL.
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.toolbt) == 0) {
      i__ = 393;
   }
   rspsub_(i__, odo2);
   return ret_val;

// V90--	TIME.  PRINT OUT DURATION OF GAME.

L21000:
   k = gttime_();
// 						!GET PLAY TIME.
   i__ = k / 60;
   j = k % 60;

   BegExSF(chan_1.outch, /*21010*/"(\002 You have been playing Dungeon for \002,$)", 0);
   EndExSF();
   if (i__ != 0) {
      BegExSF(chan_1.outch, /*21011*/"(\002+\002,i3,\002 hour\002,$)", 0);
      DoFio(1, &i__, sizeof i__);
      EndExSF();
   }
   if (i__ >= 2) {
      BegExSF(chan_1.outch, /*21012*/"(\002+s and \002,$)", 0);
      EndExSF();
   }
   if (i__ == 1) {
      BegExSF(chan_1.outch, /*21013*/"(\002+ and \002,$)", 0);
      EndExSF();
   }
   if (j == 1) {
      BegExSF(chan_1.outch, /*21014*/"(\002+\002,i2,\002 minute.\002)", 0);
      DoFio(1, &j, sizeof j);
      EndExSF();
   }
   if (j != 1) {
      BegExSF(chan_1.outch, /*21015*/"(\002+\002,i2,\002 minutes.\002)", 0);
      DoFio(1, &j, sizeof j);
      EndExSF();
   }
   play_1.telflg = true;
   return ret_val;

// V91--	LEAP.  USUALLY A JOKE, WITH A CATCH.

L22000:
   if (prsvec_1.prso == 0) {
      goto L22200;
   }
// 						!OVER SOMETHING?
   if (qhere_(prsvec_1.prso, play_1.here)) {
      goto L22100;
   }
// 						!HERE?
   rspeak_(447);
// 						!NO, JOKE.
   return ret_val;

L22100:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) == 0) {
      goto L22300;
   }
   rspsub_(448, odo2);
// 						!CANT JUMP VILLAIN.
   return ret_val;

L22200:
   if (!findxt_(xsrch_1.xdown, play_1.here)) {
      goto L22300;
   }
// 						!DOWN EXIT?
   if (curxt_1.xtype == xpars_1.xno || curxt_1.xtype == xpars_1.xcond && !flags[*xflag - 1]) {
      goto L22400;
   }
L22300:
   i__1 = rnd_(5) + 314;
   rspeak_(i__1);
// 						!WHEEEE
// 						!
   return ret_val;

L22400:
   i__1 = rnd_(4) + 449;
   jigsup_(i__1);
// 						!FATAL LEAP.
   return ret_val;
// SVERBS, PAGE 6

// V92--	LOCK.

L23000:
   if (prsvec_1.prso == oindex_1.grate && play_1.here == rindex_1.mgrat) {
      goto L23200;
   }
L23100:
   rspeak_(464);
// 						!NOT LOCK GRATE.
   return ret_val;

L23200:
   findex_1.grunlf = false;
// 						!GRATE NOW LOCKED.
   rspeak_(214);
   exits_1.travel[rooms_1.rexit[play_1.here - 1]] = 214;
// 						!CHANGE EXIT STATUS.
   return ret_val;

// V93--	UNLOCK

L24000:
   if (prsvec_1.prso != oindex_1.grate || play_1.here != rindex_1.mgrat) {
      goto L23100;
   }
   if (prsvec_1.prsi == oindex_1.keys) {
      goto L24200;
   }
// 						!GOT KEYS?
   rspsub_(465, odi2);
// 						!NO, JOKE.
   return ret_val;

L24200:
   findex_1.grunlf = true;
// 						!UNLOCK GRATE.
   rspeak_(217);
   exits_1.travel[rooms_1.rexit[play_1.here - 1]] = 217;
// 						!CHANGE EXIT STATUS.
   return ret_val;

// V94--	DIAGNOSE.

L25000:
   i__ = fights_(play_1.winner, false);
// 						!GET FIGHTS STRENGTH.
   j = advs_1.astren[play_1.winner - 1];
// 						!GET HEALTH.
// Computing MIN
   i__1 = i__ + j;
   k = min(i__1, 4);
// 						!GET STATE.
   if (!cevent_1.cflag[cindex_1.cevcur - 1]) {
      j = 0;
   }
// 						!IF NO WOUNDS.
// Computing MIN
   i__1 = 4, i__2 = abs(j);
   l = min(i__1, i__2);
// 						!SCALE.
   i__1 = l + 473;
   rspeak_(i__1);
// 						!DESCRIBE HEALTH.
   i__ = (-j - 1) * 30 + cevent_1.ctick[cindex_1.cevcur - 1];
// 						!COMPUTE WAIT.

   if (j != 0) {
      BegExSF(chan_1.outch, /*25100*/"(\002 You will be cured after \002,i3,\002 moves.\002)", 0);
      DoFio(1, &i__, sizeof i__);
      EndExSF();
   }

   i__1 = k + 478;
   rspeak_(i__1);
// 						!HOW MUCH MORE?
   if (state_1.deaths != 0) {
      i__1 = state_1.deaths + 482;
      rspeak_(i__1);
   }
// 						!HOW MANY DEATHS?
   return ret_val;
// SVERBS, PAGE 7

// V95--	INCANT

L26000:
   for (i__ = 1; i__ <= 6; ++i__) {
// 						!SET UP PARSE.
      *(unsigned char *)&pv_1.p1[i__ - 1] = ' ';
      *(unsigned char *)&pv_1.p2[i__ - 1] = ' ';
// L26100:
   }
   wp = 1;
// 						!WORD POINTER.
   cp = 1;
// 						!CHAR POINTER.
   if (prsvec_1.prscon <= 1) {
      goto L26300;
   }
   i__1 = input_1.inlnt;
   for (i__ = prsvec_1.prscon; i__ <= i__1; ++i__) {
// 						!PARSE INPUT
      if (*(unsigned char *)&input_1.inbuf[i__ - 1] == ',') {
         goto L26300;
      }
// 						!END OF PHRASE?
      if (*(unsigned char *)&input_1.inbuf[i__ - 1] != ' ') {
         goto L26150;
      }
// 						!SPACE?
      if (cp != 1) {
         ++wp;
      }
      cp = 1;
      goto L26200;
   L26150:
      if (wp == 1) {
         *(unsigned char *)&pv_1.p1[cp - 1] = *(unsigned char *)&input_1.inbuf[i__ - 1];
      }
// 						!STUFF INTO HOLDER.
      if (wp == 2) {
         *(unsigned char *)&pv_1.p2[cp - 1] = *(unsigned char *)&input_1.inbuf[i__ - 1];
      }
// Computing MIN
      i__2 = cp + 1;
      cp = min(i__2, 6);
   L26200:
      ;
   }

L26300:
   prsvec_1.prscon = 1;
// 						!KILL REST OF LINE.
   if (*(unsigned char *)&pv_1.p1[0] != ' ') {
      goto L26400;
   }
// 						!ANY INPUT?
   rspeak_(856);
// 						!NO, HO HUM.
   return ret_val;

L26400:
   encryp_(pv_1.p1, ch/*, sizeof pv_1.p1[0], sizeof ch[0]*/);
// 						!COMPUTE RESPONSE.
   if (*(unsigned char *)&pv_1.p2[0] != ' ') {
      goto L26600;
   }
// 						!TWO PHRASES?

   if (findex_1.spellf) {
      goto L26550;
   }
// 						!HE'S TRYING TO LEARN.
// The following line fixes a nice bug in the UNIX version! /+ TAA +/
// 	IF(IAND(RFLAG(TSTRS),RSEEN).EQ.0) GO TO 26575
   findex_1.spellf = true;
// 						!TELL HIM.
   play_1.telflg = true;
   BegExSF(chan_1.outch, /*26510*/"(\002 A hollow voice replies:  \"\002,6a1,1x,6a1,\002\".\002)", 0);
   DoFio(6, pv_1.p1, sizeof pv_1.p1[0]);
   DoFio(6, ch, sizeof ch[0]);
   EndExSF();

   return ret_val;

L26550:
   rspeak_(857);
// 						!HE'S GOT ONE ALREADY.
   return ret_val;

L26575:
   rspeak_(858);
// 						!HE'S NOT IN ENDGAME.
   return ret_val;

L26600:
   if ((rooms_1.rflag[rindex_1.tstrs - 1] & rflag_1.rseen) != 0) {
      goto L26800;
   }
   for (i__ = 1; i__ <= 6; ++i__) {
      if (*(unsigned char *)&pv_1.p2[i__ - 1] != *(unsigned char *)&ch[i__ - 1]) {
         goto L26575;
      }
// 						!WRONG.
// L26700:
   }
   findex_1.spellf = true;
// 						!IT WORKS.
   rspeak_(859);
   cevent_1.ctick[cindex_1.cevste - 1] = 1;
// 						!FORCE START.
   return ret_val;

L26800:
   rspeak_(855);
// 						!TOO LATE.
   return ret_val;
// SVERBS, PAGE 8

// V96--	ANSWER

L27000:
   if (prsvec_1.prscon > 1 && play_1.here == rindex_1.fdoor && findex_1.inqstf) {
      goto L27100;
   }
   rspeak_(799);
// 						!NO ONE LISTENS.
   prsvec_1.prscon = 1;
   return ret_val;

L27100:
   k = 1;
// 						!POINTER INTO ANSSTR.
   for (j = 1; j <= 28; j += 2) {
// 						!CHECK ANSWERS.
      newk = k + answer[j];
// 						!COMPUTE NEXT K.
      if (findex_1.quesno != answer[j - 1]) {
         goto L27300;
      }
// 						!ONLY CHECK PROPER ANS.
      i__ = prsvec_1.prscon - 1;
// 						!SCAN ANSWER.
      i__1 = newk - 1;
      for (l = k; l <= i__1; ++l) {
      L27150:
         ++i__;
// 						!SKIP INPUT BLANKS.
         if (i__ > input_1.inlnt) {
            goto L27300;
         }
// 						!END OF INPUT? LOSE.
         if (*(unsigned char *)&input_1.inbuf[i__ - 1] == ' ') {
            goto L27150;
         }
         if (*(unsigned char *)&input_1.inbuf[i__ - 1] != *(unsigned char *)&ansstr[l - 1]) {
            goto L27300;
         }
   // L27200:
      }
      goto L27500;
// 						!RIGHT ANSWER.
   L27300:
      k = newk;
   }

   prsvec_1.prscon = 1;
// 						!KILL REST OF LINE.
   ++findex_1.nqatt;
// 						!WRONG, CRETIN.
   if (findex_1.nqatt >= 5) {
      goto L27400;
   }
// 						!TOO MANY WRONG?
   i__1 = findex_1.nqatt + 800;
   rspeak_(i__1);
// 						!NO, TRY AGAIN.
   return ret_val;

L27400:
   rspeak_(826);
// 						!ALL OVER.
   cevent_1.cflag[cindex_1.cevinq - 1] = false;
// 						!LOSE.
   return ret_val;

L27500:
   prsvec_1.prscon = 1;
// 						!KILL REST OF LINE.
   ++findex_1.corrct;
// 						!GOT IT RIGHT.
   rspeak_(800);
// 						!HOORAY.
   if (findex_1.corrct >= 3) {
      goto L27600;
   }
// 						!WON TOTALLY?
   cevent_1.ctick[cindex_1.cevinq - 1] = 2;
// 						!NO, START AGAIN.
   findex_1.quesno = (findex_1.quesno + 3) % 8;
   findex_1.nqatt = 0;
   rspeak_(769);
// 						!ASK NEXT QUESTION.
   i__1 = findex_1.quesno + 770;
   rspeak_(i__1);
   return ret_val;

L27600:
   rspeak_(827);
// 						!QUIZ OVER,
   cevent_1.cflag[cindex_1.cevinq - 1] = false;
   objcts_1.oflag2[oindex_1.qdoor - 1] |= oflags_1.openbt;
   return ret_val;

}
