	program distribuicao_exponencial
	real*8 :: r
	integer*8 :: i
	open(10,file='distribuicaoexponencial.dat')
	do i=1,10**6
		call random_number(r)
		write(10,*)-dlog(1.d0-r)
	end do

	close(100)
	end program
