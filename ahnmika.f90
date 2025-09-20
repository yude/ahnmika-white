program main
    implicit none
    
    double precision :: rand
    integer :: i, seedsize, colors, count = 0
    integer, allocatable :: seed(:)
    integer, parameter :: SIGINT = 2
    logical :: flg = .false.


    call random_seed(size=seedsize)
    allocate(seed(seedsize))
    do i = 1, seedsize
        call system_clock(count=seed(i))
    end do
    call random_seed(put=seed)

    call signal(SIGINT, sigint_handler)

    do

        call random_number(rand)
        colors = int(rand * (1000 - 100 + 1) + 100)
        print"('白って', I0, '色あんねん')", colors
        count = count + 1
        if (flg) then
            print"(I0, '人のアンミカ')", count
            flg = .false.
            stop
        end if
    end do
contains
    subroutine sigint_handler()
        flg = .true.
    end subroutine
end program main
