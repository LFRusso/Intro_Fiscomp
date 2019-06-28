	program montecarlodefato
	implicit none	
	integer*8 ::i,n,j
	real*8 :: a,b,mf,x
	open(10,file='integralaleat.dat')
	open(20,file='errointegralaleat.dat')
	write(*,*)'quais o limite inferior e o superior na integração?'
	read(*,*)a,b
	do j=1,9
		mf=0.d0
		do i=1,10**j
			call random_number(x)
			x=(b-a)*x+a
			mf=mf+1.d0/x!4.d0/(1.d0+x**2.d0)
		end do
		mf=mf/10.d0**dfloat(n)
		write(10,*)10.d0**dfloat(j),(b-a)*mf
		write(20,*)10.d0**dfloat(j),dabs((b-a)*mf-dlog(10.d0))
	end do
	close(10)
	end program
