%--------------------------------------------
% A simple test for solving the heat equation
% u_t + u_x = 0       x in (0,2*pi)  (D.E.)
%u(x,0) = sin x                      (I.C.)
%u(0,t) = sin(-t)                    (B.C.)
%---------------------------------------------
clear all;close all;clc;
% --- input arguments ---

bdA=0;bdB=2*pi;
dx=2*pi/100;
x=[bdA:dx:bdB];
m=length(x);

dt=0.5*dx;
T=2*pi;nt=ceil(T/dt);
mu=dt/dx;


%The final exact solution
U=sin(x-T);
%initial profile of U(x,0)
Uf=sin(x);



%FTCS

for it= 1:nt
    Uf(2:m-1)=1/2*(Uf(3:m)+Uf(1:m-2))-mu/2*(Uf(3:m)-Uf(1:m-2));
    Uf(1)=sin(bdA-it*dt);
    Uf(m)=sin(bdB-it*dt);
    
end
Uferr=max(abs(Uf(:)-U(:)));

