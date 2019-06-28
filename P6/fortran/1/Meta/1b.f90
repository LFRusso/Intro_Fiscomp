	program historgramaaleatorio
	implicit none
	integer*8 :: i,m,n
	real*8 :: r
	real*8,dimension(9,3**9) :: Q
	real*8,dimension(100,9) :: S
	real*8,dimension(100,9) :: D
	real*8,dimension(9,2) :: Y
	open(20,file='desviopadraoamostras.dat')
	open(30,file='mediaamostras.dat')
	do i=1,100

		do m=1,9
			!open(10,file='sequencialeatoria.dat')
			s(i,m)=0.d0
			d(i,m)=0.d0
			do n=1,3**m
				call random_number(r)
				S(i,m)=s(i,m)+r
				Q(m,n)=r
			end do
			!close(10)
			s(i,m)=s(i,m)/(3.d0**dfloat(m))
			!open(10,file='sequencialeatoria.dat')
			do n=1,3**m
				d(i,m)=d(i,m)+(Q(m,n)-s(i,m))**2.d0
			end do
			!close(10)
			d(i,m)=dsqrt(d(i,m)/(3**m))
			write(20,*)d(i,m)
			write(30,*)s(i,m)
			
		
		end do
	end do
	close(20)
	close(30)
	open(10,file='histogrmed2.dat')
	open(20,file='histogrmed3.dat')
	open(30,file='hisstogrmed4.dat')
	do m=1,3
			do i=1,100
				write(10*m,*)s(i,m+1)
			end do

	end do
	close(10)
	close(20)
	close(30)
	open(10,file='histogrdesv2.dat')
	open(20,file='histogrdesv3.dat')
	open(30,file='hisstogrdesv4.dat')
	do m=1,3
			do i=1,100
				write(10*m,*)d(i,m+1)
			end do

	end do
	close(10)
	close(20)
	close(30)
	open(10,file='desviopadraopornumero.dat')
	do i=1,9
		Y(i,1)=0.d0
		do m=1,100
			Y(i,1)=Y(i,1) +S(m,i)
		end do
		Y(i,1)=Y(i,1)/100.d0	
	end do
	do i=1,9
		Y(i,2)=0.d0
		do m=1,100
			Y(i,2)=Y(i,2)+(Y(i,1)-S(m,i))**2.d0
		end do
		Y(i,2)=dsqrt(Y(i,2)/100.d0)
	end do
	
	do i=1,9
		write(10,*)3.d0**dfloat(i),Y(i,2)
	end do	

	close(10)
	end program
