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
        USE EXAMP
! Fortran 95/90 Module including procedure
        USE CPROC

        A(1)=1.0
        A(2)=2.0
        A(3)=3.0
        CALL INITFO(Y)
        WRITE(*,*) Y

        WRITE(*,*) A(1)
        CALL INIT(B)
        CALL PYTHAGORAS ( X)
        WRITE(*,*) X
       
        END PROGRAM MAIN
