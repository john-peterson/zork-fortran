C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Special purpose room routines, part 1
	LOGICAL FUNCTION RAPPL1(RI)
	IMPLICIT INTEGER (A-Z)
	LOGICAL QOPEN,QON,QHERE,PROB,F
	LOGICAL MOVETO,LIT
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
C
C SCREEN OF LIGHT
C
	COMMON /SCREEN/ FROMDR,SCOLRM,SCOLAC
	COMMON /SCREEN/ SCOLDR(8),SCOLWL(12)
C
C MISCELLANEOUS VARIABLES
C
	COMMON /BATS/ BATDRP(9)
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'clock.h'
	include 'villians.h'
	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C
C In-line functions
	QOPEN(R)=IAND(OFLAG2(R),OPENBT).NE.0
	QON(R)=IAND(OFLAG1(R),ONBT).NE.0
C RAPPL1, PAGE 2
C
	RAPPL1=.TRUE.
C						!USUALLY IGNORED.
	IF(RI.EQ.0) RETURN
C						!RETURN IF NAUGHT.
C
C						!SET TO FALSE FOR
C
C						!NEW DESC NEEDED.
	GO TO (1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,
     & 11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,
     & 21000,22000,23000,24000,25000,26000,27000,28000,29000,30000,
     & 31000,32000,33000,34000,35000,36000,37000),RI
	CALL BUG(1,RI)
C
C R1--	EAST OF HOUSE.  DESCRIPTION DEPENDS ON STATE OF WINDOW
C
1000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=13
C						!ASSUME CLOSED.
	IF(QOPEN(WINDO)) I=12
C						!IF OPEN, AJAR.
	CALL RSPSUB(11,I)
C						!DESCRIBE.
	RETURN
C
C R2--	KITCHEN.  SAME VIEW FROM INSIDE.
C
2000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=13
C						!ASSUME CLOSED.
	IF(QOPEN(WINDO)) I=12
C						!IF OPEN, AJAR.
	CALL RSPSUB(14,I)
C						!DESCRIBE.
	RETURN
C
C R3--	LIVING ROOM.  DESCRIPTION DEPENDS ON MAGICF (STATE OF
C	DOOR TO CYCLOPS ROOM), RUG (MOVED OR NOT), DOOR (OPEN OR CLOSED)
C
3000	IF(PRSA.NE.LOOKW) GO TO 3500
C						!LOOK?
	I=15
C						!ASSUME NO HOLE.
	IF(MAGICF) I=16
C						!IF MAGICF, CYCLOPS HOLE.
	CALL RSPEAK(I)
C						!DESCRIBE.
	I=17+ORRUG
C						!ASSUME INITIAL STATE.
	IF(QOPEN(DOOR)) I=I+2
C						!DOOR OPEN?
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C	NOT A LOOK WORD.  REEVALUATE TROPHY CASE.
C
3500	IF((PRSA.NE.TAKEW).AND.((PRSA.NE.PUTW).OR.(PRSI.NE.TCASE)))
     &	RETURN
	ASCORE(WINNER)=RWSCOR
C						!SCORE TROPHY CASE.
	DO 3600 I=1,OLNT
C						!RETAIN RAW SCORE AS WELL.
	  J=I
C						!FIND OUT IF IN CASE.
3550	  J=OCAN(J)
C						!TRACE OWNERSHIP.
	  IF(J.EQ.0) GO TO 3600
	  IF(J.NE.TCASE) GO TO 3550
C						!DO ALL LEVELS.
	  ASCORE(WINNER)=ASCORE(WINNER)+OTVAL(I)
3600	CONTINUE
	CALL SCRUPD(0)
C						!SEE IF ENDGAME TRIG.
	RETURN
C RAPPL1, PAGE 3
C
C R4--	CELLAR.  SHUT DOOR AND BAR IT IF HE JUST WALKED IN.
C
4000	IF(PRSA.NE.LOOKW) GO TO 4500
C						!LOOK?
	CALL RSPEAK(21)
C						!DESCRIBE CELLAR.
	RETURN
C
4500	IF(PRSA.NE.WALKIW) RETURN
C						!WALKIN?
	IF(IAND(OFLAG2(DOOR),(OPENBT+TCHBT)).NE.OPENBT) RETURN
	OFLAG2(DOOR)=IAND(IAND(OFLAG2(DOOR),CHBT), not(OPENBT))
	CALL RSPEAK(22)
C						!SLAM AND BOLT DOOR.
	RETURN
C
C R5--	MAZE11.  DESCRIBE STATE OF GRATING.
C
5000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(23)
C						!DESCRIBE.
	I=24
C						!ASSUME LOCKED.
	IF(GRUNLF) I=26
C						!UNLOCKED?
	IF(QOPEN(GRATE)) I=25
C						!OPEN?
	CALL RSPEAK(I)
C						!DESCRIBE GRATE.
	RETURN
C
C R6--	CLEARING.  DESCRIBE CLEARING, MOVE LEAVES.
C
6000	IF(PRSA.NE.LOOKW) GO TO 6500
C						!LOOK?
	CALL RSPEAK(27)
C						!DESCRIBE.
	IF(RVCLR.EQ.0) RETURN
C						!LEAVES MOVED?
	I=28
C						!YES, ASSUME GRATE CLOSED.
	IF(QOPEN(GRATE)) I=29
C						!OPEN?
	CALL RSPEAK(I)
C						!DESCRIBE GRATE.
	RETURN
C
6500	IF((RVCLR.NE.0).OR.(QHERE(LEAVE,CLEAR).AND.
     &	((PRSA.NE.MOVEW).OR.(PRSO.NE.LEAVE)))) RETURN
	CALL RSPEAK(30)
C						!MOVE LEAVES, REVEAL GRATE.
	RVCLR=1
C						!INDICATE LEAVES MOVED.
	RETURN
C RAPPL1, PAGE 4
C
C R7--	RESERVOIR SOUTH.  DESCRIPTION DEPENDS ON LOW TIDE FLAG.
C
7000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=31
C						!ASSUME FULL.
	IF(LWTIDF) I=32
C						!IF LOW TIDE, EMPTY.
	CALL RSPEAK(I)
C						!DESCRIBE.
	CALL RSPEAK(33)
C						!DESCRIBE EXITS.
	RETURN
C
C R8--	RESERVOIR.  STATE DEPENDS ON LOW TIDE FLAG.
C
8000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=34
C						!ASSUME FULL.
	IF(LWTIDF) I=35
C						!IF LOW TIDE, EMTPY.
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R9--	RESERVOIR NORTH.  ALSO DEPENDS ON LOW TIDE FLAG.
C
9000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=36
C						!YOU GET THE IDEA.
	IF(LWTIDF) I=37
	CALL RSPEAK(I)
	CALL RSPEAK(38)
	RETURN
C
C R10--	GLACIER ROOM.  STATE DEPENDS ON MELTED, VANISHED FLAGS.
C
10000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(39)
C						!BASIC DESCRIPTION.
	I=0
C						!ASSUME NO CHANGES.
	IF(GLACMF) I=40
C						!PARTIAL MELT?
	IF(GLACRF) I=41
C						!COMPLETE MELT?
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R11--	FOREST ROOM
C
11000	IF(PRSA.EQ.WALKIW) CFLAG(CEVFOR)=.TRUE.
C						!IF WALK IN, BIRDIE.
	RETURN
C
C R12--	MIRROR ROOM.  STATE DEPENDS ON MIRROR INTACT.
C
12000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(42)
C						!DESCRIBE.
	IF(MIRRMF) CALL RSPEAK(43)
C						!IF BROKEN, NASTY REMARK.
	RETURN
C RAPPL1, PAGE 5
C
C R13--	CAVE2 ROOM.  BLOW OUT CANDLES WITH 50% PROBABILITY.
C
13000	IF(PRSA.NE.WALKIW) RETURN
C						!WALKIN?
	IF(PROB(50,50).OR.(OADV(CANDL).NE.WINNER).OR.
     &	.NOT.QON(CANDL)) RETURN
	OFLAG1(CANDL)=IAND(OFLAG1(CANDL), not(ONBT))
	CALL RSPEAK(47)
C						!TELL OF WINDS.
	CFLAG(CEVCND)=.FALSE.
C						!HALT CANDLE COUNTDOWN.
	RETURN
C
C R14--	BOOM ROOM.  BLOW HIM UP IF CARRYING FLAMING OBJECT.
C
14000	J=ODESC2(CANDL)
C						!ASSUME CANDLE.
	IF((OADV(CANDL).EQ.WINNER).AND.QON(CANDL)) GO TO 14100
	J=ODESC2(TORCH)
C						!ASSUME TORCH.
	IF((OADV(TORCH).EQ.WINNER).AND.QON(TORCH)) GO TO 14100
	J=ODESC2(MATCH)
	IF((OADV(MATCH).EQ.WINNER).AND.QON(MATCH)) GO TO 14100
	RETURN
C						!SAFE
C
14100	IF(PRSA.NE.TRNONW) GO TO 14200
C						!TURN ON?
	CALL RSPSUB(294,J)
C						!BOOM
C						!
	CALL JIGSUP(44)
	RETURN
C
14200	IF(PRSA.NE.WALKIW) RETURN
C						!WALKIN?
	CALL RSPSUB(295,J)
C						!BOOM
C						!
	CALL JIGSUP(44)
	RETURN
C
C R15--	NO-OBJS.  SEE IF EMPTY HANDED, SCORE LIGHT SHAFT.
C
15000	EMPTHF=.TRUE.
C						!ASSUME TRUE.
	DO 15100 I=1,OLNT
C						!SEE IF CARRYING.
	  IF(OADV(I).EQ.WINNER) EMPTHF=.FALSE.
15100	CONTINUE
C
	IF((HERE.NE.BSHAF).OR.(.NOT.LIT(HERE))) RETURN
	CALL SCRUPD(LTSHFT)
C						!SCORE LIGHT SHAFT.
	LTSHFT=0
C						!NEVER AGAIN.
	RETURN
C RAPPL1, PAGE 6
C
C R16--	MACHINE ROOM.  DESCRIBE MACHINE.
C
16000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
C						!ASSUME LID CLOSED.
	IF(QOPEN(MACHI)) I=12
C						!IF OPEN, OPEN.
	CALL RSPSUB(45,I)
C						!DESCRIBE.
	RETURN
C
C R17--	BAT ROOM.  UNLESS CARRYING GARLIC, FLY AWAY WITH ME...
C
17000	IF(PRSA.NE.LOOKW) GO TO 17500
C						!LOOK?
	CALL RSPEAK(48)
C						!DESCRIBE ROOM.
	IF(OADV(GARLI).EQ.WINNER) CALL RSPEAK(49)
C						!BAT HOLDS NOSE.
	RETURN
C
17500	IF((PRSA.NE.WALKIW).OR.(OADV(GARLI).EQ.WINNER)) RETURN
	CALL RSPEAK(50)
C						!TIME TO FLY, JACK.
	F=MOVETO(BATDRP(RND(9)+1),WINNER)
C						!SELECT RANDOM DEST.
	RAPPL1=.FALSE.
C						!INDICATE NEW DESC NEEDED.
	RETURN
C
C R18--	DOME ROOM.  STATE DEPENDS ON WHETHER ROPE TIED TO RAILING.
C
18000	IF(PRSA.NE.LOOKW) GO TO 18500
C						!LOOK?
	CALL RSPEAK(51)
C						!DESCRIBE.
	IF(DOMEF) CALL RSPEAK(52)
C						!IF ROPE, DESCRIBE.
	RETURN
C
18500	IF(PRSA.EQ.LEAPW) CALL JIGSUP(53)
C						!DID HE JUMP???
	RETURN
C
C R19--	TORCH ROOM.  ALSO DEPENDS ON WHETHER ROPE TIED TO RAILING.
C
19000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(54)
C						!DESCRIBE.
	IF(DOMEF) CALL RSPEAK(55)
C						!IF ROPE, DESCRIBE.
	RETURN
C
C R20--	CAROUSEL ROOM.  SPIN HIM OR KILL HIM.
C
20000	IF(PRSA.NE.LOOKW) GO TO 20500
C						!LOOK?
	CALL RSPEAK(56)
C						!DESCRIBE.
	IF(.NOT.CAROFF) CALL RSPEAK(57)
C						!IF NOT FLIPPED, SPIN.
	RETURN
C
20500	IF((PRSA.EQ.WALKIW).AND.CAROZF) CALL JIGSUP(58)
C						!WALKED IN.
	RETURN
C RAPPL1, PAGE 7
C
C R21--	LLD ROOM.  HANDLE EXORCISE, DESCRIPTIONS.
C
21000	IF(PRSA.NE.LOOKW) GO TO 21500
C						!LOOK?
	CALL RSPEAK(59)
C						!DESCRIBE.
	IF(.NOT.LLDF) CALL RSPEAK(60)
C						!IF NOT VANISHED, GHOSTS.
	RETURN
C
21500	IF(PRSA.NE.EXORCW) RETURN
C						!EXORCISE?
	IF((OADV(BELL).EQ.WINNER).AND.(OADV(BOOK).EQ.WINNER).AND.
     &	(OADV(CANDL).EQ.WINNER).AND.QON(CANDL)) GO TO 21600
	CALL RSPEAK(62)
C						!NOT EQUIPPED.
	RETURN
C
21600	IF(QHERE(GHOST,HERE)) GO TO 21700
C						!GHOST HERE?
	CALL JIGSUP(61)
C						!NOPE, EXORCISE YOU.
	RETURN
C
21700	CALL NEWSTA(GHOST,63,0,0,0)
C						!VANISH GHOST.
	LLDF=.TRUE.
C						!OPEN GATE.
	RETURN
C
C R22--	LLD2-ROOM.  IS HIS HEAD ON A POLE?
C
22000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(64)
C						!DESCRIBE.
	IF(ONPOLF) CALL RSPEAK(65)
C						!ON POLE?
	RETURN
C
C R23--	DAM ROOM.  DESCRIBE RESERVOIR, PANEL.
C
23000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(66)
C						!DESCRIBE.
	I=67
	IF(LWTIDF) I=68
	CALL RSPEAK(I)
C						!DESCRIBE RESERVOIR.
	CALL RSPEAK(69)
C						!DESCRIBE PANEL.
	IF(GATEF) CALL RSPEAK(70)
C						!BUBBLE IS GLOWING.
	RETURN
C
C R24--	TREE ROOM
C
24000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(660)
C						!DESCRIBE.
	I=661
C						!SET FLAG FOR BELOW.
	DO 24200 J=1,OLNT
C						!DESCRIBE OBJ IN FORE3.
	  IF(.NOT.QHERE(J,FORE3).OR.(J.EQ.FTREE)) GO TO 24200
	  CALL RSPEAK(I)
C						!SET STAGE,
	  I=0
	  CALL RSPSUB(502,ODESC2(J))
C						!DESCRIBE.
24200	CONTINUE
	RETURN
C RAPPL1, PAGE 8
C
C R25--	CYCLOPS-ROOM.  DEPENDS ON CYCLOPS STATE, ASLEEP FLAG, MAGIC FLAG.
C
25000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(606)
C						!DESCRIBE.
	I=607
C						!ASSUME BASIC STATE.
	IF(RVCYC.GT.0) I=608
C						!>0?  HUNGRY.
	IF(RVCYC.LT.0) I=609
C						!<0?  THIRSTY.
	IF(CYCLOF) I=610
C						!ASLEEP?
	IF(MAGICF) I=611
C						!GONE?
	CALL RSPEAK(I)
C						!DESCRIBE.
	IF(.NOT.CYCLOF .AND.(RVCYC.NE.0))
     &	CALL RSPEAK(193+IABS(RVCYC))
	RETURN
C
C R26--	BANK BOX ROOM.
C
26000	IF(PRSA.NE.WALKIW) RETURN
C						!SURPRISE HIM.
	DO 26100 I=1,8,2
C						!SCOLRM DEPENDS ON
	  IF(FROMDR.EQ.SCOLDR(I)) SCOLRM=SCOLDR(I+1)
26100	CONTINUE
C						!ENTRY DIRECTION.
	RETURN
C
C R27--	TREASURE ROOM.
C
27000	IF((PRSA.NE.WALKIW).OR. .NOT.THFACT)
     &	RETURN
	IF(OROOM(THIEF).NE.HERE)
     &	CALL NEWSTA(THIEF,82,HERE,0,0)
	THFPOS=HERE
C						!RESET SEARCH PATTERN.
	OFLAG2(THIEF)=IOR(OFLAG2(THIEF),FITEBT)
	IF(OROOM(CHALI).EQ.HERE)
     &	OFLAG1(CHALI)=IAND(OFLAG1(CHALI),not(TAKEBT))
C
C	VANISH EVERYTHING IN ROOM
C
	J=0
C						!ASSUME NOTHING TO VANISH.
	DO 27200 I=1,OLNT
	  IF((I.EQ.CHALI).OR.(I.EQ.THIEF).OR..NOT.QHERE(I,HERE))
     &	GO TO 27200
	  J=83
C						!FLAG BYEBYE.
	  OFLAG1(I)=IAND(OFLAG1(I),not(VISIBT))
27200	CONTINUE
	CALL RSPEAK(J)
C						!DESCRIBE.
	RETURN
C
C R28--	CLIFF FUNCTION.  SEE IF CARRYING INFLATED BOAT.
C
28000	DEFLAF=OADV(RBOAT).NE.WINNER
C						!TRUE IF NOT CARRYING.
	RETURN
C RAPPL1, PAGE 9
C
C R29--	RIVR4 ROOM.  PLAY WITH BUOY.
C
29000	IF(.NOT.BUOYF.OR.(OADV(BUOY).NE.WINNER)) RETURN
	CALL RSPEAK(84)
C						!GIVE HINT,
	BUOYF=.FALSE.
C						!THEN DISABLE.
	RETURN
C
C R30--	OVERFALLS.  DOOM.
C
30000	IF(PRSA.NE.LOOKW) CALL JIGSUP(85)
C						!OVER YOU GO.
	RETURN
C
C R31--	BEACH ROOM.  DIG A HOLE.
C
31000	IF((PRSA.NE.DIGW).OR.(PRSO.NE.SHOVE)) RETURN
	RVSND=RVSND+1
C						!INCREMENT DIG STATE.
	GO TO (31100,31100,31100,31400,31500),RVSND
C						!PROCESS STATE.
	CALL BUG(2,RVSND)
C
31100	CALL RSPEAK(85+RVSND)
C						!1-3... DISCOURAGE HIM.
	RETURN
C
31400	I=89
C						!ASSUME DISCOVERY.
	IF(IAND(OFLAG1(STATU),VISIBT).NE.0) I=88
	CALL RSPEAK(I)
	OFLAG1(STATU)=IOR(OFLAG1(STATU),VISIBT)
	RETURN
C
31500	RVSND=0
C						!5... SAND COLLAPSES
	CALL JIGSUP(90)
C						!AND SO DOES HE.
	RETURN
C
C R32--	TCAVE ROOM.  DIG A HOLE IN GUANO.
C
32000	IF((PRSA.NE.DIGW).OR.(PRSO.NE.SHOVE)) RETURN
	I=91
C						!ASSUME NO GUANO.
	IF(.NOT. QHERE(GUANO,HERE)) GO TO 32100
C						!IS IT HERE?
	RVGUA=MIN0(4,RVGUA+1)
C						!YES, SET NEW STATE.
	I=91+RVGUA
C						!GET NASTY REMARK.
32100	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R33--	FALLS ROOM
C
33000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(96)
C						!DESCRIBE.
	I=97
C						!ASSUME NO RAINBOW.
	IF(RAINBF) I=98
C						!GOT ONE?
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C RAPPL1, PAGE 10
C
C R34--	LEDGE FUNCTION.  LEDGE CAN COLLAPSE.
C
34000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(100)
C						!DESCRIBE.
	I=102
C						!ASSUME SAFE ROOM OK.
	IF(IAND(RFLAG(MSAFE),RMUNG).NE.0) I=101
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R35--	SAFE ROOM.  STATE DEPENDS ON WHETHER SAFE BLOWN.
C
35000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(104)
C						!DESCRIBE.
	I=105
C						!ASSUME OK.
	IF(SAFEF) I=106
C						!BLOWN?
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R36--	MAGNET ROOM.  DESCRIBE, CHECK FOR SPINDIZZY DOOM.
C
36000	IF(PRSA.NE.LOOKW) GO TO 36500
C						!LOOK?
	CALL RSPEAK(107)
C						!DESCRIBE.
	RETURN
C
36500	IF((PRSA.NE.WALKIW).OR. .NOT.CAROFF) RETURN
C						!WALKIN ON FLIPPED?
	IF(CAROZF) GO TO 36600
C						!ZOOM?
	CALL RSPEAK(108)
C						!NO, SPIN HIS COMPASS.
	RETURN
C
36600	I=58
C						!SPIN HIS INSIDES.
	IF(WINNER.NE.PLAYER) I=99
C						!SPIN ROBOT.
	CALL JIGSUP(I)
C						!DEAD.
	RETURN
C
C R37--	CAGE ROOM.  IF SOLVED CAGE, MOVE TO OTHER CAGE ROOM.
C
37000	IF(CAGESF) F=MOVETO(CAGER,WINNER)
C						!IF SOLVED, MOVE.
	RETURN
	END
