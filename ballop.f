C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Balloon function
	LOGICAL FUNCTION BALLOP(ARG)
	IMPLICIT INTEGER (A-Z)
	LOGICAL FINDXT,QEMPTY
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'curxt.h'
	include 'xpars.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'clock.h'

	include 'verbs.h'
	include 'flags.h'
C BALLOP, PAGE 2
C
	BALLOP=.TRUE.
C						!ASSUME WINS.
	IF(ARG.NE.2) GO TO 200
C						!READOUT?
	IF(PRSA.NE.LOOKW) GO TO 10
C						!ONLY PROCESS LOOK.
	IF(BINFF.NE.0) GO TO 50
C						!INFLATED?
	CALL RSPEAK(543)
C						!NO.
	GO TO 100
50	CALL RSPSUB(544,ODESC2(BINFF))
C						!YES.
100	IF(BTIEF.NE.0) CALL RSPEAK(545)
C						!HOOKED?
	RETURN
C
200	IF(ARG.NE.1) GO TO 500
C						!READIN?
	IF(PRSA.NE.WALKW) GO TO 300
C						!WALK?
	IF(FINDXT(PRSO,HERE)) GO TO 250
C						!VALID EXIT?
	CALL RSPEAK(546)
C						!NO, JOKE.
	RETURN
C
250	IF(BTIEF.EQ.0) GO TO 275
C						!TIED UP?
	CALL RSPEAK(547)
C						!YES, JOKE.
	RETURN
C
275	IF(XTYPE.NE.XNORM) GO TO 10
C						!NORMAL EXIT?
	IF(IAND(RFLAG(XROOM1),RMUNG).EQ.0) BLOC=XROOM1
10	BALLOP=.FALSE.
	RETURN
C
300	IF((PRSA.NE.TAKEW).OR.(PRSO.NE.BINFF)) GO TO 350
	CALL RSPSUB(548,ODESC2(BINFF))
C						!RECEP CONT TOO HOT.
	RETURN
C
350	IF((PRSA.NE.PUTW).OR.(PRSI.NE.RECEP).OR.QEMPTY(RECEP))
     &	GO TO 10
	CALL RSPEAK(549)
	RETURN
C
500	IF((PRSA.NE.UNBOAW).OR.(IAND(RFLAG(HERE),RLAND).EQ.0))
     &	GO TO 600
	IF(BINFF.NE.0) CTICK(CEVBAL)=3
C						!HE GOT OUT, START BALLOON.
	GO TO 10
C
600	IF((PRSA.NE.BURNW).OR.(OCAN(PRSO).NE.RECEP)) GO TO 700
	CALL RSPSUB(550,ODESC2(PRSO))
C						!LIGHT FIRE IN RECEP.
	CTICK(CEVBRN)=OSIZE(PRSO)*20
	OFLAG1(PRSO)=IOR(OFLAG1(PRSO),
     &	IAND((ONBT+FLAMBT+LITEBT), not(TAKEBT+READBT)))
	IF(BINFF.NE.0) RETURN
	IF(.NOT.BLABF) CALL NEWSTA(BLABE,0,0,BALLO,0)
	BLABF=.TRUE.
	BINFF=PRSO
	CTICK(CEVBAL)=3
	CALL RSPEAK(551)
	RETURN
C
700	IF((PRSA.EQ.UNBOAW).AND.(BINFF.NE.0).AND.
     &	(IAND(RFLAG(HERE),RLAND).NE.0))
     &	CTICK(CEVBAL)=3
	GO TO 10
	END
