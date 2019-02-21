function func(i) result(j)
    integer, intent(in) :: i ! input
    integer             :: j ! output
    integer, dimension (5,5) :: matrix  
    j = i**2 + i**3
end function func

program xfunc
    implicit none
    integer :: i
    integer :: func
    i = 3
    print*,"sum of the square and cube of",i," is",func(i)
 end program xfunc
