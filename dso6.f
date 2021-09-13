C GHERE--	IS GLOBAL ACTUALLY IN THIS ROOM?
C
C COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
C ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
C WRITTEN BY R. M. SUPNIK
C
C DECLARATIONS
C
	LOGICAL FUNCTION GHERE(OBJ,RM)
	IMPLICIT INTEGER(A-Z)
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
C
	COMMON /STAR/ MBASE,STRBIT
C GHERE, PAGE 2
C
	GHERE=.TRUE.
C						!ASSUME WINS.
	GO TO (1000,1000,1000,1000,1000,1000,
     &1000,1000,1000,1000,1000,
     &2000,3000,4000,5000,5000,5000,6000,
     &7000,8000,9000,9100,8000,10000,11000),OBJ-STRBIT
	CALL BUG(60,OBJ)
C
C 1000--	STARS ARE ALWAYS HERE
C
1000	RETURN
C
C 2000--	BIRD
C
2000	GHERE=((RM.GE.FORE1).AND.(RM.LT.CLEAR)).OR.(RM.EQ.MTREE)
	RETURN
C
C 3000--	TREE
C
3000	GHERE=((RM.GE.FORE1).AND.(RM.LT.CLEAR)).AND.(RM.NE.FORE3)
	RETURN
C
C 4000--	NORTH WALL
C
4000	GHERE=((RM.GE.BKVW).AND.(RM.LE.BKBOX)).OR.(RM.EQ.CPUZZ)
	RETURN
C
C 5000--	EAST, SOUTH, WEST WALLS
C
5000	GHERE=((RM.GE.BKVW).AND.(RM.LT.BKBOX)).OR.(RM.EQ.CPUZZ)
	RETURN
C
C 6000--	GLOBAL WATER
C
6000	GHERE=IAND(RFLAG(RM),(RWATER+RFILL)).NE.0
	RETURN
C
C 7000--	GLOBAL GUARDIANS
C
7000	GHERE=((RM.GE.MRC).AND.(RM.LE.MRD)).OR.
     &((RM.GE.MRCE).AND.(RM.LE.MRDW)).OR.(RM.EQ.INMIR)
	RETURN
C
C 8000--	ROSE/CHANNEL
C
8000	GHERE=((RM.GE.MRA).AND.(RM.LE.MRD)).OR.(RM.EQ.INMIR)
	RETURN
C
C 9000--	MIRROR
C 9100		PANEL
C
9100	IF(RM.EQ.FDOOR) RETURN
C						!PANEL AT FDOOR.
9000	GHERE=((RM.GE.MRA).AND.(RM.LE.MRC)).OR.
     &((RM.GE.MRAE).AND.(RM.LE.MRCW))
	RETURN
C
C 10000--	MASTER
C
10000	GHERE=(RM.EQ.FDOOR).OR.(RM.EQ.NCORR).OR.(RM.EQ.PARAP).OR.
     &(RM.EQ.CELL)
	RETURN
C
C 11000--	LADDER
C
11000	GHERE=(RM.EQ.CPUZZ)
	RETURN
C
	END
C MRHERE--	IS MIRROR HERE?
C
C DECLARATIONS
C
	INTEGER FUNCTION MRHERE(RM)
	IMPLICIT INTEGER(A-Z)
C
C ROOMS
	include 'rindex.h'
	include 'flags.h'
C MRHERE, PAGE 2
C
	IF((RM.LT.MRAE).OR.(RM.GT.MRDW)) GO TO 100
C
C RM IS AN E-W ROOM, MIRROR MUST BE N-S (MDIR= 0 OR 180)
C
	MRHERE=1
C						!ASSUME MIRROR 1 HERE.
	IF(MOD(RM-MRAE,2).EQ.(MDIR/180)) MRHERE=2
	RETURN
C
C RM IS NORTH OR SOUTH OF MIRROR.  IF MIRROR IS N-S OR NOT
C WITHIN ONE ROOM OF RM, LOSE.
C
100	MRHERE=0
	IF((IABS(MLOC-RM).NE.1).OR.(MOD(MDIR,180).EQ.0)) RETURN
C
C RM IS WITHIN ONE OF MLOC, AND MDIR IS E-W
C
	MRHERE=1
	IF(((RM.LT.MLOC).AND.(MDIR.LT.180)).OR.
     &    ((RM.GT.MLOC).AND.(MDIR.GT.180))) MRHERE=2
	RETURN
	END