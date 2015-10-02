! Fortran 95/90 Module including procedure
      MODULE CPROC
        INTERFACE
            SUBROUTINE PYTHAGORAS ( res) bind (c, name='pythagoras')
            use iso_c_binding
            real(kind=c_float) :: res
            END SUBROUTINE

            SUBROUTINE INIT(b) bind (c, name='init')
            use iso_c_binding
            real(kind=c_float) :: b
            END SUBROUTINE

            SUBROUTINE INITFO (aa) bind(c, name='initfo')
            use iso_c_binding
            real(kind=c_float) :: aa
            END SUBROUTINE
        END INTERFACE
        END MODULE

        PROGRAM MAIN
        USE CPROC
        USE EXAMP
        type(mytype)::MD
!       CALL INIT(RES)
        WRITE(*,*) I1,I2
! Fortran 95/90 Module including procedure
!        implicit none
        A(1)=1.0
        A(2)=2.0
        A(3)=3.0
        CALL INITFO(Y)
        WRITE(*,*) Y

        WRITE(*,*) A(1)
        MD%x = 3
!        MD%INFO='this is'
        MD%y(1) = 0.d0
        WRITE(*,*) MD%y
!        MD%BARY(2) = 0.d0
!        MD%BARY(3) = 0.d0
        CALL PYTHAGORAS ( X)
!        WRITE(*,*) MD%BARY(1)
        WRITE(*,*) X
!        BASE.YY(1) = 4
!        BASE.YY(2) = 3
!        BASE.YY(3) = 2
!        EXTERNAL FTOC
!        CALL FTOC (BASE) 
        END PROGRAM MAIN
