%script to solve 2D diffusion

close all;
clear all;
ic_v = @(X,Y) sin(pi*X).*sin(pi*Y);
N=100;
h=1/N;
[X,Y] = meshgrid(h/2:h:1-h/2,h/2:h:1-h/2);
ic = ic_v(X,Y);
D=0.1;
k=h;
delt=0.01;
[A,A_rhs]=nma_generate_A_and_ARHS_for_2D_diffusion_Neumman(N,D,delt,h);
max_t=1;
[u,X,Y,~]=nma_solve_2D_diffusion_ADI(A,A_rhs,h,k,D,max_t,ic,false)
mesh(X,Y,u);