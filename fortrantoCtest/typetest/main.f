! Fortran 95/90 Module including procedure
      MODULE CPROC
        INTERFACE
            SUBROUTINE INIT(res) bind (c, name='init')
            use iso_c_binding
            REAL (kind=c_float) :: res
            END SUBROUTINE
        END INTERFACE
        END MODULE

        PROGRAM MAIN
        USE CPROC
        USE ass 
        type(myType)::MD
        type(localmyType)::MM
        type(mt)::MN
        CALL INIT(b)
        MD%I1 = b
        MM%I2 = b
        EXTERNAL INITT
        CALL INITT(MN)
        WRITE(*,*) MD%I1,MM%I2,MN%I1
        
        END PROGRAM MAIN
