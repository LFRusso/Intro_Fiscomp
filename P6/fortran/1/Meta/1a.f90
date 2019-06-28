	program testealeatorio
	implicit none
	integer*8 :: i,m,n
	real*8 :: r,s,d
	real*8,dimension(3**9) :: Q
	open(20,file='desviopadraoamostras.dat')
	open(30,file='mediaamostras.dat')
	do i=1,100

		do m=1,9
			!open(10,file='sequencialeatoria.dat')
			s=0.d0
			d=0.d0
			do n=1,3**m
				call random_number(r)
				s=s+r
				Q(n)=r
			end do
			!close(10)
			s=s/(3.d0**dfloat(m))
			!open(10,file='sequencialeatoria.dat')
			do n=1,3**m
				d=d+(Q(n)-s)**2.d0
			end do
			!close(10)
			d=dsqrt(d/(3**m))
			write(20,*)3**m,d
			write(30,*)3**m,s
			
		
		end do
	end do
	close(20)
	close(30)
	open(40,file='mediaesperada.dat')
	open(50,file='desviopadraoesperado.dat')
	do i=1,19683
		write(40,*)i,0.5d0
		write(50,*)i,1.d0/dsqrt(12.d0)
	end do
	end program
