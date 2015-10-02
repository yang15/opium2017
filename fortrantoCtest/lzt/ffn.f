    subroutine ffn(p,x)
      use par
      type (param) p
      integer ::x

      x = p%n + 1
    end subroutine
