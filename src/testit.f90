    ! We pass-by-reference the random number x
    subroutine testit(x)
      double precision unifrnd, x

      ! We must always call rndstart to initialize R's random number generator
      ! This will obey the seed set by the R user in R.
      call rndstart()

      ! Okay, now we can create an actual uniform random number
      x = unifrnd()

      ! dblepr just calls a builtin subroutine to message R properly, rather than print
      ! We don't need this message, it's just here for demo purposes.
      call dblepr("X was", 5, x, 1)

      ! We must always call rndend subroutine at the end to free the random number generator
      call rndend()
    end
