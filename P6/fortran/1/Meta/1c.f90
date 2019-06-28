	program montecarlocirculo 
!!esse programa tenta encontrar para qual número de pontos (em potência de 2) o erro do valor de pi é de 10^-4; Para isso, faz-se 100 amostras de 2**n pontos, aplica-se o método de monte carlo e compara o desvio padrão dessas 100 amostras. Esse programa demora muito para rodar, então basta rodá-lo uma vez, ver o resultado e aplicar a rotina sempre com esse número n de pontos pelo menos
	implicit none
	integer*8 :: i,j,ndentro,n
	real*8 ::x,y,pi,d,s
	real*8,dimension(100) :: V
	n=0
	d=1.d0
	ndentro=0

	do while(d.gt.1.d-4)
		n=n+1
		s=0.d0
		d=0.d0
		do j=1,100
			ndentro=0
			do i=1,2**n
				call random_number(x)
				call random_number(y)
				if (x**2.d0+y**2.d0 .le. 1) then
					ndentro=ndentro+1
				end if
			end do
			pi=4.d0*dfloat(ndentro)/(2.d0**dfloat(n))
			V(j)=pi	
			!write(*,*)pi
		end do

		do i=1,100
			s=s+V(i)
		end do		
		s=s/100.d0
		!write(*,*)s
		do i=1,100
			d=d+(V(i)-s)**2.d0
		end do
		d=dsqrt(d/100.d0)		
		write(*,*)d
	end do
	write(*,*)n
 !!!!!O VALOR ENCONTRADO FOI COM N=28!!!!!
	end program
