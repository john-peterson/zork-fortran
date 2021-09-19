C FINDXT- FIND EXIT FROM ROOM
C
C COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
C ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
C WRITTEN BY R. M. SUPNIK
C
	LOGICAL FUNCTION FINDXT(DIR,RM)
	IMPLICIT INTEGER (A-Z)
	include 'rooms.h'
	include 'exits.h'
	include 'curxt.h'
	include 'xpars.h'
C
	FINDXT=.TRUE.
C						!ASSUME WINS.
	XI=REXIT(RM)
C						!FIND FIRST ENTRY.
	IF(XI.EQ.0) GO TO 1000
C						!NO EXITS?
C
100	I=TRAVEL(XI)
C						!GET ENTRY.
	XROOM1=IAND(I,XRMASK)
	XTYPE=IAND((IAND(I,32767)/XFSHFT),XFMASK)+1
	GO TO (110,120,130,130),XTYPE
C						!BRANCH ON ENTRY.
	CALL BUG(10,XTYPE)
C
130	XOBJ=IAND(TRAVEL(XI+2),XRMASK)
	XACTIO=TRAVEL(XI+2)/XASHFT
120	XSTRNG=TRAVEL(XI+1)
C						!DOOR/CEXIT/NEXIT - STRING.
110	XI=XI+XELNT(XTYPE)
C						!ADVANCE TO NEXT ENTRY.
	IF(IAND(I,XDMASK).EQ.DIR) RETURN
	IF(IAND(I,XLFLAG).EQ.0) GO TO 100
1000	FINDXT=.FALSE.
C						!YES, LOSE.
	RETURN
	END
C FWIM- FIND WHAT I MEAN
C
	INTEGER FUNCTION FWIM(F1,F2,RM,CON,ADV,NOCARE)
	IMPLICIT INTEGER (A-Z)
	LOGICAL NOCARE
	include 'objects.h'
	include 'oflags.h'
C
	FWIM=0
C						!ASSUME NOTHING.
	DO 1000 I=1,OLNT
C						!LOOP
	  IF(((RM.EQ.0).OR.(OROOM(I).NE.RM)) .AND.
     &	((ADV.EQ.0).OR.(OADV(I).NE.ADV)) .AND.
     &	((CON.EQ.0).OR.(OCAN(I).NE.CON)))
     &	GO TO 1000
C
C OBJECT IS ON LIST... IS IT A MATCH?
C
	  IF(IAND(OFLAG1(I),VISIBT).EQ.0) GO TO 1000
C	  IF(IAND(not(NOCARE),(IAND(OFLAG1(I),TAKEBT).EQ.0)) .OR.
	  IF (((.NOT.NOCARE).AND.(IAND(OFLAG1(I),TAKEBT).EQ.0)) .OR.
     &	((IAND(OFLAG1(I),F1).EQ.0).AND.
     &	 (IAND(OFLAG2(I),F2).EQ.0))) GO TO 500
	  IF(FWIM.EQ.0) GO TO 400
C						!ALREADY GOT SOMETHING?
	  FWIM=-FWIM
C						!YES, AMBIGUOUS.
	  RETURN
C
400	  FWIM=I
C						!NOTE MATCH.
C
C DOES OBJECT CONTAIN A MATCH?
C
500	  IF(IAND(OFLAG2(I),OPENBT).EQ.0) GO TO 1000
	  DO 700 J=1,OLNT
C						!NO, SEARCH CONTENTS.
	    IF((OCAN(J).NE.I).OR.(IAND(OFLAG1(J),VISIBT).EQ.0) .OR.
     &	((IAND(OFLAG1(J),F1).EQ.0).AND.
     &	 (IAND(OFLAG2(J),F2).EQ.0))) GO TO 700
	    IF(FWIM.EQ.0) GO TO 600
	    FWIM=-FWIM
	    RETURN
C
600	    FWIM=J
700	  CONTINUE
1000	CONTINUE
	RETURN
	END
C YESNO- OBTAIN YES/NO ANSWER
C
C CALLED BY-
C
C	YES-IS-TRUE=YESNO(QUESTION,YES-STRING,NO-STRING)
C
	LOGICAL FUNCTION YESNO(Q,Y,N)
	IMPLICIT INTEGER(A-Z)
	COMMON /CHAN/ INPCH,OUTCH,DBCH
	CHARACTER ANS
C
100	CALL RSPEAK(Q)
C						!ASK
	READ(INPCH,110) ANS
C						!GET ANSWER
110	FORMAT(A1)
	IF((ANS.EQ.'Y').OR.(ANS.EQ.'y')) GO TO 200
	IF((ANS.EQ.'N').OR.(ANS.EQ.'n')) GO TO 300
	CALL RSPEAK(6)
C						!SCOLD.
	GO TO 100
C
200	YESNO=.TRUE.
C						!YES,
	CALL RSPEAK(Y)
C						!OUT WITH IT.
	RETURN
C
300	YESNO=.FALSE.
C						!NO,
	CALL RSPEAK(N)
C						!LIKEWISE.
	RETURN
C
	END
