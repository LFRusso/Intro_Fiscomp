	program decaimento_radioativo
	implicit none
	real*8,parameter :: dt=5.d-3
	real*8 :: r,m
	integer*8 :: N0,N,k,i,j,l,u
	real*8, allocatable :: P(:,:)
	real*8, dimension(1400) :: A
	real*8,dimension(1400) :: D
	write(*,*)'Qual o número inicial de partículas?'
	read(*,*)N0
	write(*,*)'Qual o número de amostras você quer analisar?'
	read(*,*)K
	allocate(P(1400,k))

	do j=1,K
		N=N0
		do i=1,1400
			u=N
			do l=1,u
				call random_number(r)		
				if (r.lt.dt) then
					N=N-1
				end if
			end do	
			P(i,j)=N
		end do
	end do
	open(4,file='decaimento1.dat')
	open(8,file='decaimento2.dat')
	open(12,file='decaimento3.dat')
	open(16,file='decaimento4.dat')
	open(20,file='decaimento5.dat')
	open(24,file='decaimento6.dat')
	open(28,file='decaimento7.dat')
	open(32,file='decaimento8.dat')
	open(36,file='decaimento9.dat')
	open(40,file='decaimento10.dat')
	open(50,file='decaimentomedia.dat')
	do i=1,10
		do j=1,1400
			write(4*i,*)dfloat(j)*dt,P(j,i)
		end do
	end do
	do j=1,1400
		do i=1,k
			A(j)=A(j)+P(j,i)
		end do
		A(j)=A(j)/dfloat(k)

	end do
	do i=1,1400
		do j=1,k
			D(i)=D(i)+(A(i)-P(i,j))**2.d0
		end do
		D(i)=dsqrt(D(i)/(dfloat(1400)*dfloat(k)))
		write(50,*)dfloat(i)*dt,A(i),D(i)
	end do
	end program
