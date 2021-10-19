C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Move player to new room
	LOGICAL FUNCTION MOVETO(NR,WHO)
	IMPLICIT INTEGER (A-Z)
	LOGICAL NLV,LHR,LNR
	include 'gamestat.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'objects.h'
	include 'oindex.h'
	include 'advers.h'
C MOVETO, PAGE 2
C
	MOVETO=.FALSE.
C						!ASSUME FAILS.
	LHR=IAND(RFLAG(HERE),RLAND).NE.0
	LNR=IAND(RFLAG(NR),RLAND).NE.0
	J=AVEHIC(WHO)
C						!HIS VEHICLE
C
	IF(J.NE.0) GO TO 100
C						!IN VEHICLE?
	IF(LNR) GO TO 500
C						!NO, GOING TO LAND?
	CALL RSPEAK(427)
C						!CAN'T GO WITHOUT VEHICLE.
	RETURN
C
100	BITS=0
C						!ASSUME NOWHERE.
	IF(J.EQ.RBOAT) BITS=RWATER
C						!IN BOAT?
	IF(J.EQ.BALLO) BITS=RAIR
C						!IN BALLOON?
	IF(J.EQ.BUCKE) BITS=RBUCK
C						!IN BUCKET?
	NLV=IAND(RFLAG(NR),BITS).EQ.0
	IF((.NOT.LNR .AND.NLV) .OR.
     &	(LNR.AND.LHR.AND.NLV.AND.(BITS.NE.RLAND)))
     &	GO TO 800
C
500	MOVETO=.TRUE.
C						!MOVE SHOULD SUCCEED.
	IF(IAND(RFLAG(NR),RMUNG).EQ.0) GO TO 600
	CALL RSPEAK(RRAND(NR))
C						!YES, TELL HOW.
	RETURN
C
600	IF(WHO.NE.PLAYER) CALL NEWSTA(AOBJ(WHO),0,NR,0,0)
	IF(J.NE.0) CALL NEWSTA(J,0,NR,0,0)
	HERE=NR
	AROOM(WHO)=HERE
	CALL SCRUPD(RVAL(NR))
C						!SCORE ROOM
	RVAL(NR)=0
	RETURN
C
800	CALL RSPSUB(428,ODESC2(J))
C						!WRONG VEHICLE.
	RETURN
	END
C
C Print out current score
	SUBROUTINE SCORE(FLG)
	IMPLICIT INTEGER (A-Z)
	LOGICAL FLG
	INTEGER RANK(10),ERANK(5)
	include 'gamestat.h'
	include 'state.h'
C
	COMMON /CHAN/ INPCH,OUTCH,INDEXCH,STORYCH
	include 'advers.h'
	include 'flags.h'
C
C Initialized data
	DATA RANK/20,19,18,16,12,8,4,2,1,0/
	DATA ERANK/20,15,10,5,0/
C SCORE, PAGE 2
C
	AS=ASCORE(WINNER)
C
	IF(ENDGMF) GO TO 60
C						!ENDGAME?
 	IF(FLG) WRITE(OUTCH,100)
 	IF(.NOT.FLG) WRITE(OUTCH,110)
 	IF(MOVES.NE.1) WRITE(OUTCH,120) AS,MXSCOR,MOVES
 	IF(MOVES.EQ.1) WRITE(OUTCH,130) AS,MXSCOR,MOVES
C
	DO 10 I=1,10
	  IF((AS*20/MXSCOR).GE.RANK(I)) GO TO 50
10	CONTINUE
50	CALL RSPEAK(484+I)
	RETURN
C
60	IF(FLG) WRITE(OUTCH,140)
 	IF(.NOT.FLG) WRITE(OUTCH,150)
 	WRITE(OUTCH,120) EGSCOR,EGMXSC,MOVES
	DO 70 I=1,5
	  IF((EGSCOR*20/EGMXSC).GE.ERANK(I)) GO TO 80
70	CONTINUE
80	CALL RSPEAK(786+I)
	RETURN

100	FORMAT('Your score would be',$)
110	FORMAT('Your score is',$)
120	FORMAT(I4,' [total of',I4,' points], in',I5,' moves.')
130	FORMAT(I4,' [total of',I4,' points], in',I5,' move.')
140	FORMAT('Your score in the endgame would be',$)
150	FORMAT('Your score in the endgame is',$)
	END
C
C Update winner's score
	SUBROUTINE SCRUPD(N)
	IMPLICIT INTEGER (A-Z)
	include 'gamestat.h'
	include 'state.h'
	include 'clock.h'
	include 'advers.h'
	include 'flags.h'
C
	IF(ENDGMF) GO TO 100
C						!ENDGAME?
	ASCORE(WINNER)=ASCORE(WINNER)+N
C						!UPDATE SCORE
	RWSCOR=RWSCOR+N
C						!UPDATE RAW SCORE
	IF(ASCORE(WINNER).LT.(MXSCOR-(10*DEATHS))) RETURN
	CFLAG(CEVEGH)=.TRUE.
C						!TURN ON END GAME
	CTICK(CEVEGH)=15
	RETURN
C
100	EGSCOR=EGSCOR+N
C						!UPDATE EG SCORE.
	RETURN
	END
