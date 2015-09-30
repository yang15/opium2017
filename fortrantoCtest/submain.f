! Fortran 95/90 Module including procedure
      MODULE CPROC
        INTERFACE
            SUBROUTINE PYTHAGORAS ( res) bind (c, name='pythagoras')
            use iso_c_binding
            real(kind=c_float) :: res
            END SUBROUTINE

!            SUBROUTINE INIT(b) bind (c, name='init')
!            use iso_c_binding
!            real(kind=c_float) :: b
!            END SUBROUTINE

            SUBROUTINE INITFO (aa) bind(c, name='initfo')
            use iso_c_binding
            real(kind=c_float) :: aa
            END SUBROUTINE
        END INTERFACE
        END MODULE

        SUBROUTINE FUNC
        USE EXAMP
! Fortran 95/90 Module including procedure
        USE CPROC

        A(1) = 2
        A(2) = 3
        A(3) = 4
       
        END SUBROUTINE 
