C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Resident subroutines for dungeon
C
C Output random message routine
C Called as:
C	CALL RSPEAK(MSGNUM)
	SUBROUTINE RSPEAK(N)
	IMPLICIT INTEGER(A-Z)
C
	CALL RSPSB2(N,0,0)
	RETURN
	END
C
C Output random message with substitutable argument
C Called as:
C	CALL RSPSUB(MSGNUM,SUBNUM)
	SUBROUTINE RSPSUB(N,S1)
	IMPLICIT INTEGER(A-Z)
C
	CALL RSPSB2(N,S1,0)
	RETURN
	END
C
C Output random message with up to two substitutable arguments
C Called as:
C	CALL RSPSB2(MSGNUM,SUBNUM1,SUBNUM2)
	SUBROUTINE    RSPSB2(N,S1,S2)
	IMPLICIT      INTEGER(A-Z)
	CHARACTER*74  B1,B2,B3
	INTEGER*2     OLDREC,NEWREC,JREC
C
	include 'gamestat.h'
C
	include 'mindex.h'
	include 'io.h'
C
C CONVERT ALL ARGUMENTS FROM DICTIONARY NUMBERS (IF POSITIVE)
C TO ABSOLUTE RECORD NUMBERS.
C
	X=N
C						!SET UP WORK VARIABLES.
	Y=S1
	Z=S2
	IF(X.GT.0) X=RTEXT(X)
C						!IF >0, LOOK UP IN RTEXT.
	IF(Y.GT.0) Y=RTEXT(Y)
	IF(Z.GT.0) Z=RTEXT(Z)
	X=IABS(X)
C						!TAKE ABS VALUE.
	Y=IABS(Y)
	Z=IABS(Z)
	IF(X.EQ.0) RETURN
C						!ANYTHING TO DO?
	TELFLG=.TRUE.
C						!SAID SOMETHING.
C
	READ(UNIT=STORYCH,REC=X) OLDREC,B1
C
100	DO 150 I=1,74
	  X1=IAND(X,31)+I
	  B1(I:I)=char(IEOR(ichar(B1(I:I)),X1))
150	CONTINUE
C
200	IF(Y.EQ.0) GO TO 400
C						!ANY SUBSTITUTABLE?
	DO 300 I=1,74
C						!YES, LOOK FOR #.
	  IF(B1(I:I).EQ.'#') GO TO 1000
300	CONTINUE
C
400	DO 500 I=74,1,-1
C						!BACKSCAN FOR BLANKS.
	  IF(B1(I:I).NE.' ') GO TO 600
500	CONTINUE
C
600	WRITE(OUTCH,650) (B1(J:J),J=1,I)
650	FORMAT(1X,74A1)
	X=X+1
C						!ON TO NEXT RECORD.
	READ(UNIT=STORYCH,REC=X) NEWREC,B1
	IF(OLDREC.EQ.NEWREC) GO TO 100
C						!CONTINUATION?
	RETURN
C						!NO, EXIT.
C
C SUBSTITUTION WITH SUBSTITUTABLE AVAILABLE.
C I IS INDEX OF # IN B1.
C Y IS NUMBER OF RECORD TO SUBSTITUTE.
C
C PROCEDURE:
C   1) COPY REST OF B1 TO B2
C   2) READ SUBSTITUTABLE OVER B1
C   3) RESTORE TAIL OF ORIGINAL B1
C
C THE IMPLICIT ASSUMPTION HERE IS THAT THE SUBSTITUTABLE STRING
C IS VERY SHORT (i.e. MUCH LESS THAN ONE RECORD).
C
1000	K2=1
C						!TO
	DO 1100 K1=I+1,74
C						!COPY REST OF B1.
	  B2(K2:K2)=B1(K1:K1)
	  K2=K2+1
1100	CONTINUE
C
C   READ SUBSTITUTE STRING INTO B3, AND DECRYPT IT:
C
	READ(UNIT=STORYCH,REC=Y) JREC,B3
	DO 1150 K1=1,74
	  X1=IAND(Y,31)+K1
	  B3(K1:K1)=char(IEOR(ICHAR(B3(K1:K1)),X1))
1150	CONTINUE
C
C   FILL REMAINDER OF B1 WITH CHARACTERS FROM B3:
C
	K2=1
	DO 1180 K1=I,74
	  B1(K1:K1)=B3(K2:K2)
	  K2=K2+1
1180	CONTINUE
C
C   FIND END OF SUBSTITUTE STRING IN B1:
C
	DO 1200 J=74,1,-1
C						!ELIM TRAILING BLANKS.
	  IF(B1(J:J).NE.' ') GO TO 1300
1200	CONTINUE
C
C   PUT TAIL END OF B1 (NOW IN B2) BACK INTO B1 AFTER SUBSTITUTE STRING:
C
1300	K1=1
C						!FROM
	DO 1400 K2=J+1,74
C						!COPY REST OF B1 BACK.
	  B1(K2:K2)=B2(K1:K1)
	  K1=K1+1
1400	CONTINUE
C
	Y=Z
C						!SET UP FOR NEXT
	Z=0
C						!SUBSTITUTION AND
	GO TO 200
C						!RECHECK LINE.
	END
C
C Apply objects from parse vector
	LOGICAL FUNCTION OBJACT(X)
	IMPLICIT INTEGER (A-Z)
	LOGICAL OAPPLI
	include 'parser.h'
	include 'objects.h'
C
	OBJACT=.TRUE.
C						!ASSUME WINS.
	IF(PRSI.EQ.0) GO TO 100
C						!IND OBJECT?
	IF(OAPPLI(OACTIO(PRSI),0)) RETURN
C						!YES, LET IT HANDLE.
C
100	IF(PRSO.EQ.0) GO TO 200
C						!DIR OBJECT?
	IF(OAPPLI(OACTIO(PRSO),0)) RETURN
C						!YES, LET IT HANDLE.
C
200	OBJACT=.FALSE.
C						!LOSES.
	RETURN
	END
C
C Report fatal system error
C Called as:
C	CALL BUG(NO,PAR)
	SUBROUTINE BUG(A,B)
	IMPLICIT INTEGER(A-Z)
	include 'debug.h'
C
	PRINT 100,A,B
	IF(DBGFLG.NE.0) RETURN
	CALL EXIT
C
100	FORMAT(' PROGRAM ERROR ',I2,', PARAMETER=',I6)
	END
C
C Set new status for object
C Called by:
C	CALL NEWSTA(OBJECT,STRING,NEWROOM,NEWCON,NEWADV)
	SUBROUTINE NEWSTA(O,R,RM,CN,AD)
	IMPLICIT INTEGER(A-Z)
	include 'objects.h'
C
	CALL RSPEAK(R)
	OROOM(O)=RM
	OCAN(O)=CN
	OADV(O)=AD
	RETURN
	END
C
C Test for object in room
	LOGICAL FUNCTION QHERE(OBJ,RM)
	IMPLICIT INTEGER (A-Z)
	include 'objects.h'
C
	QHERE=.TRUE.
	IF(OROOM(OBJ).EQ.RM) RETURN
C						!IN ROOM?
	DO 100 I=1,R2LNT
C						!NO, SCH ROOM2.
	  IF((OROOM2(I).EQ.OBJ).AND.(RROOM2(I).EQ.RM)) RETURN
100	CONTINUE
	QHERE=.FALSE.
C						!NOT PRESENT.
	RETURN
	END
C
C Test for object empty
	LOGICAL FUNCTION QEMPTY(OBJ)
	IMPLICIT INTEGER (A-Z)
	include 'objects.h'
C
	QEMPTY=.FALSE.
C						!ASSUME LOSE.
	DO 100 I=1,OLNT
	  IF(OCAN(I).EQ.OBJ) RETURN
C						!INSIDE TARGET?
100	CONTINUE
	QEMPTY=.TRUE.
	RETURN
	END
C
C You are dead
	SUBROUTINE JIGSUP(DESC)
	IMPLICIT INTEGER (A-Z)
	LOGICAL YESNO,MOVETO,QHERE,F
	INTEGER RLIST(9)
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'io.h'
	include 'debug.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'advers.h'
	include 'flags.h'
C
C Initialized data
	DATA RLIST/8,6,36,35,34,4,34,6,5/
C JIGSUP, PAGE 2
C
	CALL RSPEAK(DESC)
C						!DESCRIBE SAD STATE.
	PRSCON=1
C						!STOP PARSER.
	IF(DBGFLG.NE.0) RETURN
C						!IF DBG, EXIT.
	AVEHIC(WINNER)=0
C						!GET RID OF VEHICLE.
	IF(WINNER.EQ.PLAYER) GO TO 100
C						!HIMSELF?
	CALL RSPSUB(432,ODESC2(AOBJ(WINNER)))
C						!NO, SAY WHO DIED.
	CALL NEWSTA(AOBJ(WINNER),0,0,0,0)
C						!SEND TO HYPER SPACE.
	RETURN
C
100	IF(ENDGMF) GO TO 900
C						!NO RECOVERY IN END GAME.
	IF(DEATHS.GE.2) GO TO 1000
C						!DEAD TWICE? KICK HIM OFF.
	IF(.NOT.YESNO(10,9,8)) GO TO 1100
C						!CONTINUE?
C
	DO 50 J=1,OLNT
C						!TURN OFF FIGHTING.
	  IF(QHERE(J,HERE))   OFLAG2(J)=IAND(OFLAG2(J),not(FITEBT))
50	CONTINUE
C
	DEATHS=DEATHS+1
	CALL SCRUPD(-10)
C						!CHARGE TEN POINTS.
	F=MOVETO(FORE1,WINNER)
C						!REPOSITION HIM.
	EGYPTF=.TRUE.
C						!RESTORE COFFIN.
	IF(OADV(COFFI).EQ.WINNER) CALL NEWSTA(COFFI,0,EGYPT,0,0)
	OFLAG2(DOOR)=IAND(OFLAG2(DOOR),not(TCHBT))
	OFLAG1(ROBOT)=IAND(IOR(OFLAG1(ROBOT),VISIBT),not(NDSCBT))
	IF((OROOM(LAMP).NE.0).OR.(OADV(LAMP).EQ.WINNER))
     &	CALL NEWSTA(LAMP,0,LROOM,0,0)
C
C NOW REDISTRIBUTE HIS VALUABLES AND OTHER BELONGINGS.
C
C THE LAMP HAS BEEN PLACED IN THE LIVING ROOM.
C THE FIRST 8 NON-VALUABLES ARE PLACED IN LOCATIONS AROUND THE HOUSE.
C HIS VALUABLES ARE PLACED AT THE END OF THE MAZE.
C REMAINING NON-VALUABLES ARE PLACED AT THE END OF THE MAZE.
C
	I=1
	DO 200 J=1,OLNT
C						!LOOP THRU OBJECTS.
	  IF((OADV(J).NE.WINNER).OR.(OTVAL(J).NE.0))
     &	GO TO 200
	  I=I+1
	  IF(I.GT.9) GO TO 400
C						!MOVE TO RANDOM LOCATIONS.
	  CALL NEWSTA(J,0,RLIST(I),0,0)
200	CONTINUE
C
400	I=RLNT+1
C						!NOW MOVE VALUABLES.
	NONOFL=RAIR+RWATER+RSACRD+REND
C						!DONT MOVE HERE.
	DO 300 J=1,OLNT
	  IF((OADV(J).NE.WINNER).OR.(OTVAL(J).EQ.0))
     &	GO TO 300
250	  I=I-1
C						!FIND NEXT ROOM.
	  IF(IAND(RFLAG(I),NONOFL).NE.0) GO TO 250
	  CALL NEWSTA(J,0,I,0,0)
C						!YES, MOVE.
300	CONTINUE
C
	DO 500 J=1,OLNT
C						!NOW GET RID OF REMAINDER.
	  IF(OADV(J).NE.WINNER) GO TO 500
450	  I=I-1
C						!FIND NEXT ROOM.
	  IF(IAND(RFLAG(I),NONOFL).NE.0) GO TO 450
	  CALL NEWSTA(J,0,I,0,0)
500	CONTINUE
	RETURN
C
C CAN'T OR WON'T CONTINUE, CLEAN UP AND EXIT.
C
900	CALL RSPEAK(625)
C						!IN ENDGAME, LOSE.
	GO TO 1100
C
1000	CALL RSPEAK(7)
C						!INVOLUNTARY EXIT.
1100	CALL SCORE(.FALSE.)
C						!TELL SCORE.
	CLOSE(STORYCH)
	CALL EXIT
	END
C
C Get actor associated with object
	INTEGER FUNCTION OACTOR(OBJ)
	IMPLICIT INTEGER(A-Z)
	include 'advers.h'
C
	DO 100 I=1,ALNT
C						!LOOP THRU ACTORS.
	  OACTOR=I
C						!ASSUME FOUND.
	  IF(AOBJ(I).EQ.OBJ) RETURN
C						!FOUND IT?
100	CONTINUE
	CALL BUG(40,OBJ)
C						!NO, DIE.
	RETURN
	END
C
C Compute probability
	LOGICAL FUNCTION PROB(G,B)
	IMPLICIT INTEGER(A-Z)
	include 'flags.h'
C
	I=G
C						!ASSUME GOOD LUCK.
	IF(BADLKF) I=B
C						!IF BAD, TOO BAD.
	PROB=RND(100).LT.I
C						!COMPUTE.
	RETURN
	END
C
C Print room description
C RMDESC prints a description of the current room.
C It is also the processor for verbs 'LOOK' and 'EXAMINE'.
	LOGICAL FUNCTION RMDESC(FULL)
C
C FULL=	0/1/2/3=	SHORT/OBJ/ROOM/FULL
C
	IMPLICIT INTEGER (A-Z)
	LOGICAL PROB,LIT,RAPPLI
	include 'parser.h'
	include 'gamestat.h'
	include 'screen.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C RMDESC, PAGE 2
C
	RMDESC=.TRUE.
C						!ASSUME WINS.
	IF(PRSO.LT.XMIN) GO TO 50
C						!IF DIRECTION,
	FROMDR=PRSO
C						!SAVE AND
	PRSO=0
C						!CLEAR.
50	IF(HERE.EQ.AROOM(PLAYER)) GO TO 100
C						!PLAYER JUST MOVE?
	CALL RSPEAK(2)
C						!NO, JUST SAY DONE.
	PRSA=WALKIW
C						!SET UP WALK IN ACTION.
	RETURN
C
100	IF(LIT(HERE)) GO TO 300
C						!LIT?
	CALL RSPEAK(430)
C						!WARN OF GRUE.
	RMDESC=.FALSE.
	RETURN
C
300	RA=RACTIO(HERE)
C						!GET ROOM ACTION.
	IF(FULL.EQ.1) GO TO 600
C						!OBJ ONLY?
	I=RDESC2-HERE
C						!ASSUME SHORT DESC.
C 2021/09/21 Darth Spectra (Lydia Marie Williamson):
C The following comment, referring to the .OR.PROB(80,80) below,
C was found in the 1991 C translation:
C The next line means that when you request VERBOSE mode,
C you only get long room descriptions 20% of the time.
C I don't either like or understand this,
C so the modification ensures VERBOSE works all the time.
C 1987/10/22 jmh@ukc.ac.uk
	IF((FULL.EQ.0)
     &	.AND.(SUPERF.OR.(((IAND(RFLAG(HERE),RSEEN)).NE.0)
     &	        .AND.(BRIEFF.OR.PROB(80,80)))))       GO TO 400
	I=RDESC1(HERE)
C						!USE LONG.
	IF((I.NE.0).OR.(RA.EQ.0)) GO TO 400
C						!IF GOT DESC, SKIP.
	PRSA=LOOKW
C						!PRETEND LOOK AROUND.
	IF(.NOT.RAPPLI(RA)) GO TO 100
C						!ROOM HANDLES, NEW DESC?
	PRSA=FOOW
C						!NOP PARSER.
	GO TO 500
C
400	CALL RSPEAK(I)
C						!OUTPUT DESCRIPTION.
500	IF(AVEHIC(WINNER).NE.0) CALL RSPSUB(431,ODESC2(AVEHIC(WINNER)))
C
600	IF(FULL.NE.2) CALL PRINCR(FULL.NE.0,HERE)
	RFLAG(HERE)=IOR(RFLAG(HERE),RSEEN)
	IF((FULL.NE.0).OR.(RA.EQ.0)) RETURN
C						!ANYTHING MORE?
	PRSA=WALKIW
C						!GIVE HIM A SURPISE.
	IF(.NOT.RAPPLI(RA)) GO TO 100
C						!ROOM HANDLES, NEW DESC?
	PRSA=FOOW
	RETURN
	END
C
C Routing routine for room applicables
	LOGICAL FUNCTION RAPPLI(RI)
	IMPLICIT INTEGER(A-Z)
	LOGICAL RAPPL1,RAPPL2
	DATA NEWRMS/38/
C
	RAPPLI=.TRUE.
C						!ASSUME WINS.
	IF(RI.EQ.0) RETURN
C						!IF ZERO, WIN.
	IF(RI.LT.NEWRMS) RAPPLI=RAPPL1(RI)
C						!IF OLD, PROCESSOR 1.
	IF(RI.GE.NEWRMS) RAPPLI=RAPPL2(RI)
C						!IF NEW, PROCESSOR 2.
	RETURN
	END
