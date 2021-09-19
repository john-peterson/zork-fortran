C SVERBS-	SIMPLE VERBS PROCESSOR
C	ALL VERBS IN THIS ROUTINE MUST BE INDEPENDANT
C	OF OBJECT ACTIONS
C
C COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
C ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
C WRITTEN BY R. M. SUPNIK
C
	LOGICAL FUNCTION SVERBS(RI)
	IMPLICIT INTEGER (A-Z)
	LOGICAL MOVETO,YESNO
	LOGICAL RMDESC
	LOGICAL QOPEN
	LOGICAL FINDXT,QHERE,F
	INTEGER JOKES(25)
	CHARACTER ANSSTR(78)
	CHARACTER P1(6),P2(6),CH(6)
	INTEGER ANSWER(28)
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'screen.h'
C
C MISCELLANEOUS VARIABLES
C
	CHARACTER VEDIT
	COMMON /VERS/ VMAJ,VMIN,VEDIT
	include 'io.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'exits.h'
	include 'curxt.h'
	include 'xpars.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'clock.h'

	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C
C In-line function
	QOPEN(R)=IAND(OFLAG2(R),OPENBT).NE.0
C
C Initialized data
	DATA MXNOP/39/,MXJOKE/64/
	DATA JOKES/4,5,3,304,305,306,307,308,309,310,311,312,
     &	313,5314,5319,324,325,883,884,120,120,0,0,0,0/
	DATA ANSWER/0,6,1,6,2,5,3,5,4,3,4,6,4,6,4,5,
     &	5,5,5,4,5,6,6,10,7,4,7,6/
	DATA ANSSTR/'T','E','M','P','L','E',
     &	'F','O','R','E','S','T',
     &	'3','0','0','0','3',
     &	'F','L','A','S','K',
     &	'R','U','B',
     &	'F','O','N','D','L','E',
     &	'C','A','R','R','E','S',
     &	'T','O','U','C','H',
     &	'B','O','N','E','S',
     &	'B','O','D','Y',
     &	'S','K','E','L','E','T',
     &	'R','U','S','T','Y','K','N','I','F','E',
     &	'N','O','N','E',
     &	'N','O','W','H','E','R','\0'/
C SVERBS, PAGE 2
C
	SVERBS=.TRUE.
C						!ASSUME WINS.
	IF(PRSO.NE.0) ODO2=ODESC2(PRSO)
C						!SET UP DESCRIPTORS.
	IF(PRSI.NE.0) ODI2=ODESC2(PRSI)
C
	IF(RI.EQ.0) CALL BUG(7,RI)
C						!ZERO IS VERBOTEN.
	IF(RI.LE.MXNOP) RETURN
C						!NOP?
	IF(RI.LE.MXJOKE) GO TO 100
C						!JOKE?
	GO TO (65000,66000,67000,68000,69000,
     & 1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,
     & 11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,
     & 21000,22000,23000,24000,25000,26000,27000),
     &	(RI-MXJOKE)
	CALL BUG(7,RI)
C
C ALL VERB PROCESSORS RETURN HERE TO DECLARE FAILURE.
C
10	SVERBS=.FALSE.
C						!LOSE.
	RETURN
C
C JOKE PROCESSOR.
C FIND PROPER ENTRY IN JOKES, USE IT TO SELECT STRING TO PRINT.
C
100	I=JOKES(RI-MXNOP)
C						!GET TABLE ENTRY.
	J=I/1000
C						!ISOLATE # STRINGS.
	IF(J.NE.0) I=MOD(I,1000)+RND(J)
C						!IF RANDOM, CHOOSE.
	CALL RSPEAK(I)
C						!PRINT JOKE.
	RETURN
C SVERBS, PAGE 2A
C
C V65--	ROOM
C
65000	SVERBS=RMDESC(2)
C						!DESCRIBE ROOM ONLY.
	RETURN
C
C V66--	OBJECTS
C
66000	SVERBS=RMDESC(1)
C						!DESCRIBE OBJ ONLY.
	IF(.NOT.TELFLG) CALL RSPEAK(138)
C						!NO OBJECTS.
	RETURN
C
C V67--	RNAME
C
67000	CALL RSPEAK(RDESC2-HERE)
C						!SHORT ROOM NAME.
	RETURN
C
C V68--	RESERVED
C
68000	RETURN
C
C V69--	RESERVED
C
69000	RETURN
C SVERBS, PAGE 3
C
C V70--	BRIEF.  SET FLAG.
C
1000	BRIEFF=.TRUE.
C						!BRIEF DESCRIPTIONS.
	SUPERF=.FALSE.
	CALL RSPEAK(326)
	RETURN
C
C V71--	VERBOSE.  CLEAR FLAGS.
C
2000	BRIEFF=.FALSE.
C						!LONG DESCRIPTIONS.
	SUPERF=.FALSE.
	CALL RSPEAK(327)
	RETURN
C
C V72--	SUPERBRIEF.  SET FLAG.
C
3000	SUPERF=.TRUE.
	CALL RSPEAK(328)
	RETURN
C
C V73-- STAY (USED IN ENDGAME).
C
4000	IF(WINNER.NE.AMASTR) GO TO 4100
C						!TELL MASTER, STAY.
	CALL RSPEAK(781)
C						!HE DOES.
	CTICK(CEVFOL)=0
C						!NOT FOLLOWING.
	RETURN
C
4100	IF(WINNER.EQ.PLAYER) CALL RSPEAK(664)
C						!JOKE.
	RETURN
C
C V74--	VERSION.  PRINT INFO.
C
5000	WRITE(OUTCH,5010) VMAJ,VMIN,VEDIT
5010	FORMAT(' V',I1,'.',I2,A1)
	TELFLG=.TRUE.
	RETURN
C
C V75--	SWIM.  ALWAYS A JOKE.
C
6000	I=330
C						!ASSUME WATER.
	IF(IAND(RFLAG(HERE),(RWATER+RFILL)).EQ.0)
     &	I=331+RND(3)
	CALL RSPEAK(I)
	RETURN
C
C V76--	GERONIMO.  IF IN BARREL, FATAL, ELSE JOKE.
C
7000	IF(HERE.EQ.MBARR) GO TO 7100
C						!IN BARREL?
	CALL RSPEAK(334)
C						!NO, JOKE.
	RETURN
C
7100	CALL JIGSUP(335)
C						!OVER FALLS.
	RETURN
C
C V77--	SINBAD ET AL.  CHASE CYCLOPS, ELSE JOKE.
C
8000	IF((HERE.EQ.MCYCL).AND.QHERE(CYCLO,HERE)) GO TO 8100
	CALL RSPEAK(336)
C						!NOT HERE, JOKE.
	RETURN
C
8100	CALL NEWSTA(CYCLO,337,0,0,0)
C						!CYCLOPS FLEES.
	CYCLOF=.TRUE.
C						!SET ALL FLAGS.
	MAGICF=.TRUE.
	OFLAG2(CYCLO)=IAND(OFLAG2(CYCLO), not(FITEBT))
	RETURN
C
C V78--	WELL.  OPEN DOOR, ELSE JOKE.
C
9000	IF(RIDDLF.OR.(HERE.NE.RIDDL)) GO TO 9100
C						!IN RIDDLE ROOM?
	RIDDLF=.TRUE.
C						!YES, SOLVED IT.
	CALL RSPEAK(338)
	RETURN
C
9100	CALL RSPEAK(339)
C						!WELL, WHAT?
	RETURN
C
C V79--	PRAY.  IF IN TEMP2, POOF
C						!
C
10000	IF(HERE.NE.TEMP2) GO TO 10050
C						!IN TEMPLE?
	IF(MOVETO(FORE1,WINNER)) GO TO 10100
C						!FORE1 STILL THERE?
10050	CALL RSPEAK(340)
C						!JOKE.
	RETURN
C
10100	F=RMDESC(3)
C						!MOVED, DESCRIBE.
	RETURN
C
C V80--	TREASURE.  IF IN TEMP1, POOF
C						!
C
11000	IF(HERE.NE.TEMP1) GO TO 11050
C						!IN TEMPLE?
	IF(MOVETO(TREAS,WINNER)) GO TO 10100
C						!TREASURE ROOM THERE?
11050	CALL RSPEAK(341)
C						!NOTHING HAPPENS.
	RETURN
C
C V81--	TEMPLE.  IF IN TREAS, POOF
C						!
C
12000	IF(HERE.NE.TREAS) GO TO 12050
C						!IN TREASURE?
	IF(MOVETO(TEMP1,WINNER)) GO TO 10100
C						!TEMP1 STILL THERE?
12050	CALL RSPEAK(341)
C						!NOTHING HAPPENS.
	RETURN
C
C V82--	BLAST.  USUALLY A JOKE.
C
13000	I=342
C						!DONT UNDERSTAND.
	IF(PRSO.EQ.SAFE) I=252
C						!JOKE FOR SAFE.
	CALL RSPEAK(I)
	RETURN
C
C V83--	SCORE.  PRINT SCORE.
C
14000	CALL SCORE(.FALSE.)
	RETURN
C
C V84--	QUIT.  FINISH OUT THE GAME.
C
15000	CALL SCORE(.TRUE.)
C						!TELLL SCORE.
	IF(.NOT.YESNO(343,0,0)) RETURN
C						!ASK FOR Y/N DECISION.
	CLOSE (DBCH)
	CALL EXIT
C						!BYE.
C SVERBS, PAGE 4
C
C V85--	FOLLOW (USED IN ENDGAME)
C
16000	IF(WINNER.NE.AMASTR) RETURN
C						!TELL MASTER, FOLLOW.
	CALL RSPEAK(782)
	CTICK(CEVFOL)=-1
C						!STARTS FOLLOWING.
	RETURN
C
C V86--	WALK THROUGH
C
17000	IF((SCOLRM.EQ.0).OR.((PRSO.NE.SCOL).AND.
     &	((PRSO.NE.WNORT).OR.(HERE.NE.BKBOX)))) GO TO 17100
	SCOLAC=SCOLRM
C						!WALKED THRU SCOL.
	PRSO=0
C						!FAKE OUT FROMDR.
	CTICK(CEVSCL)=6
C						!START ALARM.
	CALL RSPEAK(668)
C						!DISORIENT HIM.
	F=MOVETO(SCOLRM,WINNER)
C						!INTO ROOM.
	F=RMDESC(3)
C						!DESCRIBE.
	RETURN
C
17100	IF(HERE.NE.SCOLAC) GO TO 17300
C						!ON OTHER SIDE OF SCOL?
	DO 17200 I=1,12,3
C						!WALK THRU PROPER WALL?
	  IF((SCOLWL(I).EQ.HERE).AND.(SCOLWL(I+1).EQ.PRSO))
     &	GO TO 17500
17200	CONTINUE
C
17300	IF(IAND(OFLAG1(PRSO),TAKEBT).NE.0) GO TO 17400
	I=669
C						!NO, JOKE.
	IF(PRSO.EQ.SCOL) I=670
C						!SPECIAL JOKE FOR SCOL.
	CALL RSPSUB(I,ODO2)
	RETURN
C
17400	I=671
C						!JOKE.
	IF(OROOM(PRSO).NE.0) I=552+RND(5)
C						!SPECIAL JOKES IF CARRY.
	CALL RSPEAK(I)
	RETURN
C
17500	PRSO=SCOLWL(I+2)
C						!THRU SCOL WALL...
	DO 17600 I=1,8,2
C						!FIND MATCHING ROOM.
	  IF(PRSO.EQ.SCOLDR(I)) SCOLRM=SCOLDR(I+1)
17600	CONTINUE
C						!DECLARE NEW SCOLRM.
	CTICK(CEVSCL)=0
C						!CANCEL ALARM.
	CALL RSPEAK(668)
C						!DISORIENT HIM.
	F=MOVETO(BKBOX,WINNER)
C						!BACK IN BOX ROOM.
	F=RMDESC(3)
	RETURN
C
C V87--	RING.  A JOKE.
C
18000	I=359
C						!CANT RING.
	IF(PRSO.EQ.BELL) I=360
C						!DING, DONG.
	CALL RSPEAK(I)
C						!JOKE.
	RETURN
C
C V88--	BRUSH.  JOKE WITH OBSCURE TRAP.
C
19000	IF(PRSO.EQ.TEETH) GO TO 19100
C						!BRUSH TEETH?
	CALL RSPEAK(362)
C						!NO, JOKE.
	RETURN
C
19100	IF(PRSI.NE.0) GO TO 19200
C						!WITH SOMETHING?
	CALL RSPEAK(363)
C						!NO, JOKE.
	RETURN
C
19200	IF((PRSI.EQ.PUTTY).AND.(OADV(PUTTY).EQ.WINNER))
     &	GO TO 19300
	CALL RSPSUB(364,ODI2)
C						!NO, JOKE.
	RETURN
C
19300	CALL JIGSUP(365)
C						!YES, DEAD
C						!
C						!
C						!
C						!
C						!
	RETURN
C SVERBS, PAGE 5
C
C V89--	DIG.  UNLESS SHOVEL, A JOKE.
C
20000	IF(PRSO.EQ.SHOVE) RETURN
C						!SHOVEL?
	I=392
C						!ASSUME TOOL.
	IF(IAND(OFLAG1(PRSO),TOOLBT).EQ.0) I=393
	CALL RSPSUB(I,ODO2)
	RETURN
C
C V90--	TIME.  PRINT OUT DURATION OF GAME.
C
21000	CALL GTTIME(K)
C						!GET PLAY TIME.
	I=K/60
	J=MOD(K,60)
C
	WRITE(OUTCH,21010)
	IF(I.NE.0) WRITE(OUTCH,21011) I
	IF(I.GE.2) WRITE(OUTCH,21012)
	IF(I.EQ.1) WRITE(OUTCH,21013)
	IF(J.EQ.1) WRITE(OUTCH,21014) J
	IF(J.NE.1) WRITE(OUTCH,21015) J
	TELFLG=.TRUE.
	RETURN
C
21010	FORMAT(' You have been playing Dungeon for ',$)
21011	FORMAT('+',I3,' hour',$)
21012	FORMAT('+s and ',$)
21013	FORMAT('+ and ',$)
21014	FORMAT('+',I2,' minute.')
21015	FORMAT('+',I2,' minutes.')
C
C V91--	LEAP.  USUALLY A JOKE, WITH A CATCH.
C
22000	IF(PRSO.EQ.0) GO TO 22200
C						!OVER SOMETHING?
	IF(QHERE(PRSO,HERE)) GO TO 22100
C						!HERE?
	CALL RSPEAK(447)
C						!NO, JOKE.
	RETURN
C
22100	IF(IAND(OFLAG2(PRSO),VILLBT).EQ.0) GO TO 22300
	CALL RSPSUB(448,ODO2)
C						!CANT JUMP VILLAIN.
	RETURN
C
22200	IF(.NOT.FINDXT(XDOWN,HERE)) GO TO 22300
C						!DOWN EXIT?
	IF((XTYPE.EQ.XNO).OR.((XTYPE.EQ.XCOND).AND.
     &	.NOT.FLAGS(XFLAG))) GO TO 22400
22300	CALL RSPEAK(314+RND(5))
C						!WHEEEE
C						!
	RETURN
C
22400	CALL JIGSUP(449+RND(4))
C						!FATAL LEAP.
	RETURN
C SVERBS, PAGE 6
C
C V92--	LOCK.
C
23000	IF((PRSO.EQ.GRATE).AND.(HERE.EQ.MGRAT))
     &	GO TO 23200
23100	CALL RSPEAK(464)
C						!NOT LOCK GRATE.
	RETURN
C
23200	GRUNLF=.FALSE.
C						!GRATE NOW LOCKED.
	CALL RSPEAK(214)
	TRAVEL(REXIT(HERE)+1)=214
C						!CHANGE EXIT STATUS.
	RETURN
C
C V93--	UNLOCK
C
24000	IF((PRSO.NE.GRATE).OR.(HERE.NE.MGRAT))
     &	GO TO 23100
	IF(PRSI.EQ.KEYS) GO TO 24200
C						!GOT KEYS?
	CALL RSPSUB(465,ODI2)
C						!NO, JOKE.
	RETURN
C
24200	GRUNLF=.TRUE.
C						!UNLOCK GRATE.
	CALL RSPEAK(217)
	TRAVEL(REXIT(HERE)+1)=217
C						!CHANGE EXIT STATUS.
	RETURN
C
C V94--	DIAGNOSE.
C
25000	I=FIGHTS(WINNER,.FALSE.)
C						!GET FIGHTS STRENGTH.
	J=ASTREN(WINNER)
C						!GET HEALTH.
	K=MIN0(I+J,4)
C						!GET STATE.
	IF(.NOT.CFLAG(CEVCUR)) J=0
C						!IF NO WOUNDS.
	L=MIN0(4,IABS(J))
C						!SCALE.
	CALL RSPEAK(473+L)
C						!DESCRIBE HEALTH.
	I=(30*(-J-1))+CTICK(CEVCUR)
C						!COMPUTE WAIT.
C
 	IF(J.NE.0) WRITE(OUTCH,25100) I
25100	FORMAT(' You will be cured after ',I3,' moves.')
C
	CALL RSPEAK(478+K)
C						!HOW MUCH MORE?
	IF(DEATHS.NE.0) CALL RSPEAK(482+DEATHS)
C						!HOW MANY DEATHS?
	RETURN
C SVERBS, PAGE 7
C
C V95--	INCANT
C
26000	DO 26100 I=1,6
C						!SET UP PARSE.
	  P1(I)=' '
	  P2(I)=' '
26100	CONTINUE
	WP=1
C						!WORD POINTER.
	CP=1
C						!CHAR POINTER.
	IF(PRSCON.LE.1) GO TO 26300
	DO 26200 I=PRSCON,INLNT
C						!PARSE INPUT
	  IF(INBUF(I).EQ.',') GO TO 26300
C						!END OF PHRASE?
	  IF(INBUF(I).NE.' ') GO TO 26150
C						!SPACE?
	  IF(CP.NE.1) WP=WP+1
	  CP=1
	  GO TO 26200
26150	  IF(WP.EQ.1) P1(CP)=INBUF(I)
C						!STUFF INTO HOLDER.
	  IF(WP.EQ.2) P2(CP)=INBUF(I)
	  CP=MIN0(CP+1,6)
26200	CONTINUE
C
26300	PRSCON=1
C						!KILL REST OF LINE.
	IF(P1(1).NE.' ') GO TO 26400
C						!ANY INPUT?
	CALL RSPEAK(856)
C						!NO, HO HUM.
	RETURN
C
26400	CALL ENCRYP(P1,CH)
C						!COMPUTE RESPONSE.
	IF(P2(1).NE.' ') GO TO 26600
C						!TWO PHRASES?
C
	IF(SPELLF) GO TO 26550
C						!HE'S TRYING TO LEARN.
C The following line fixes a nice bug in the UNIX version! /* TAA */
C	IF(IAND(RFLAG(TSTRS),RSEEN).EQ.0) GO TO 26575
	SPELLF=.TRUE.
C						!TELL HIM.
	TELFLG=.TRUE.
 	WRITE(OUTCH,26510) P1,CH
26510	FORMAT(' A hollow voice replies:  "',6A1,1X,6A1,'".')
C
	RETURN
C
26550	CALL RSPEAK(857)
C						!HE'S GOT ONE ALREADY.
	RETURN
C
26575	CALL RSPEAK(858)
C						!HE'S NOT IN ENDGAME.
	RETURN
C
26600	IF(IAND(RFLAG(TSTRS),RSEEN).NE.0) GO TO 26800
	DO 26700 I=1,6
	  IF(P2(I).NE.CH(I)) GO TO 26575
C						!WRONG.
26700	CONTINUE
	SPELLF=.TRUE.
C						!IT WORKS.
	CALL RSPEAK(859)
	CTICK(CEVSTE)=1
C						!FORCE START.
	RETURN
C
26800	CALL RSPEAK(855)
C						!TOO LATE.
	RETURN
C SVERBS, PAGE 8
C
C V96--	ANSWER
C
27000	IF((PRSCON.GT.1).AND.
     &	(HERE.EQ.FDOOR).AND.INQSTF)
     &	GO TO 27100
	CALL RSPEAK(799)
C						!NO ONE LISTENS.
	PRSCON=1
	RETURN
C
27100	K=1
C						!POINTER INTO ANSSTR.
	DO 27300 J=1,28,2
C						!CHECK ANSWERS.
	  NEWK=K+ANSWER(J+1)
C						!COMPUTE NEXT K.
	  IF(QUESNO.NE.ANSWER(J)) GO TO 27300
C						!ONLY CHECK PROPER ANS.
	  I=PRSCON-1
C						!SCAN ANSWER.
	  DO 27200 L=K,NEWK-1
27150	    I=I+1
C						!SKIP INPUT BLANKS.
	    IF(I.GT.INLNT) GO TO 27300
C						!END OF INPUT? LOSE.
	    IF(INBUF(I).EQ.' ') GO TO 27150
	    IF(INBUF(I).NE.ANSSTR(L)) GO TO 27300
27200	  CONTINUE
	  GO TO 27500
C						!RIGHT ANSWER.
27300	K=NEWK
C
	PRSCON=1
C						!KILL REST OF LINE.
	NQATT=NQATT+1
C						!WRONG, CRETIN.
	IF(NQATT.GE.5) GO TO 27400
C						!TOO MANY WRONG?
	CALL RSPEAK(800+NQATT)
C						!NO, TRY AGAIN.
	RETURN
C
27400	CALL RSPEAK(826)
C						!ALL OVER.
	CFLAG(CEVINQ)=.FALSE.
C						!LOSE.
	RETURN
C
27500	PRSCON=1
C						!KILL REST OF LINE.
	CORRCT=CORRCT+1
C						!GOT IT RIGHT.
	CALL RSPEAK(800)
C						!HOORAY.
	IF(CORRCT.GE.3) GO TO 27600
C						!WON TOTALLY?
	CTICK(CEVINQ)=2
C						!NO, START AGAIN.
	QUESNO=MOD(QUESNO+3,8)
	NQATT=0
	CALL RSPEAK(769)
C						!ASK NEXT QUESTION.
	CALL RSPEAK(770+QUESNO)
	RETURN
C
27600	CALL RSPEAK(827)
C						!QUIZ OVER,
	CFLAG(CEVINQ)=.FALSE.
	OFLAG2(QDOOR)=IOR(OFLAG2(QDOOR),OPENBT)
	RETURN
C
	END
