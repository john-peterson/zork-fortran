C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Get total time played
 	SUBROUTINE GTTIME(T)
 	IMPLICIT INTEGER(A-Z)
C
 	COMMON /TIME/ PLTIME,SHOUR,SMIN,SSEC
C
 	CALL INTIME(H,M,S)
 	T=((H*60)+M)-((SHOUR*60)+SMIN)
 	IF(T.LT.0) T=T+1440
 	T=T+PLTIME
 	RETURN
 	END
C
C Process open/close for doors
	LOGICAL FUNCTION OPNCLS(OBJ,SO,SC)
	IMPLICIT INTEGER (A-Z)
	LOGICAL QOPEN
	include 'parser.h'
	include 'objects.h'
	include 'oflags.h'
	include 'verbs.h'
C
C In-line function
	QOPEN(O)=IAND(OFLAG2(O),OPENBT).NE.0
C
	OPNCLS=.TRUE.
C						!ASSUME WINS.
	IF(PRSA.EQ.CLOSEW) GO TO 100
C						!CLOSE?
	IF(PRSA.EQ.OPENW) GO TO 50
C						!OPEN?
	OPNCLS=.FALSE.
C						!LOSE
	RETURN
C
50	IF(QOPEN(OBJ)) GO TO 200
C						!OPEN... IS IT?
	CALL RSPEAK(SO)
	OFLAG2(OBJ)=IOR(OFLAG2(OBJ),OPENBT)
	RETURN
C
100	IF(.NOT.QOPEN(OBJ)) GO TO 200
C						!CLOSE... IS IT?
	CALL RSPEAK(SC)
	OFLAG2(OBJ)=IAND(OFLAG2(OBJ),not(OPENBT))
	RETURN
C
200	CALL RSPEAK(125+RND(3))
C						!DUMMY.
	RETURN
	END
C
C Is room lit?
	LOGICAL FUNCTION LIT(RM)
	IMPLICIT INTEGER (A-Z)
	LOGICAL QHERE
	include 'rooms.h'
	include 'rflag.h'
	include 'objects.h'
	include 'oflags.h'
	include 'advers.h'
C
	LIT=.TRUE.
C						!ASSUME WINS
	IF(IAND(RFLAG(RM),RLIGHT).NE.0) RETURN
C
	DO 1000 I=1,OLNT
C						!LOOK FOR LIT OBJ
	  IF(QHERE(I,RM)) GO TO 100
C						!IN ROOM?
	  OA=OADV(I)
C						!NO
	  IF(OA.LE.0) GO TO 1000
C						!ON ADV?
	  IF(AROOM(OA).NE.RM) GO TO 1000
C						!ADV IN ROOM?
C
C OBJ IN ROOM OR ON ADV IN ROOM
C
100	  IF(IAND(OFLAG1(I),ONBT).NE.0) RETURN
	  IF((IAND(OFLAG1(I),VISIBT).EQ.0).OR.
     &	((IAND(OFLAG1(I),TRANBT).EQ.0).AND.
     &	(IAND(OFLAG2(I),OPENBT).EQ.0))) GO TO 1000
C
C OBJ IS VISIBLE AND OPEN OR TRANSPARENT
C
	  DO 500 J=1,OLNT
	    IF((OCAN(J).EQ.I).AND.(IAND(OFLAG1(J),ONBT).NE.0))
     &	RETURN
500	  CONTINUE
1000	CONTINUE
	LIT=.FALSE.
	RETURN
	END
C
C Returns sum of weight of qualifying objects
	INTEGER FUNCTION WEIGHT(RM,CN,AD)
	IMPLICIT INTEGER (A-Z)
	LOGICAL QHERE
	include 'objects.h'
C
	WEIGHT=0
	DO 100 I=1,OLNT
C						!OMIT BIG FIXED ITEMS.
	  IF(OSIZE(I).GE.10000) GO TO 100
C						!IF FIXED, FORGET IT.
	  IF((QHERE(I,RM).AND.(RM.NE.0)).OR.
     &	((OADV(I).EQ.AD).AND.(AD.NE.0))) GO TO 50
	  J=I
C						!SEE IF CONTAINED.
25	  J=OCAN(J)
C						!GET NEXT LEVEL UP.
	  IF(J.EQ.0) GO TO 100
C						!END OF LIST?
	  IF(J.NE.CN) GO TO 25
50	  WEIGHT=WEIGHT+OSIZE(I)
100	CONTINUE
	RETURN
	END
