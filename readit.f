C	NOTE: This hasn't yet been updated
C       to read the current version of 'dtext.dat'
	PROGRAM StreamIO
	IMPLICIT NONE
	INTEGER*2 :: N,EXN
	INTEGER :: I,J,STORYCH
	PARAMETER(STORYCH=1)
	CHARACTER(74) :: Buf
	OPEN(STORYCH,FILE="dtext.dat",STATUS="OLD",ACCESS="STREAM")
	I=0
	EXN=0
	DO WHILE (.TRUE.)
           READ(STORYCH,POS=76*I+1,END=100)N,Buf
           DO 110 J=1,74
              Buf(J:J)=CHAR(XOR(ICHAR(Buf(J:J)),AND(I+1,Z'1F')+J))
110	   CONTINUE
	   IF (N.EQ.EXN) THEN
	      WRITE(*,130)
	   ELSE
	      WRITE(*,120)N
	   ENDIF
	   WRITE(*,140)Buf
	   EXN=N
	   I=I+1
	END DO
100	CLOSE(STORYCH)
120	FORMAT('#',I4.4,$)
130	FORMAT('     ',$)
140	FORMAT(':',A74)
	END
