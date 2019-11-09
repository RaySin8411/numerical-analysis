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
T=2*pi;nt=floor(T/dt);
mu=dt/dx;


%The final exact solution
U=sin(x-T);
%initial profile of U(x,0)
Ulw=sin(x);



%lax-wendroff
q=(1-mu)/(1+mu);
for it= 1:nt
    U1=Ulw(m-1);
    Ulw(2:m-1)=Ulw(2:m-1)-mu/2*(Ulw(3:m)-Ulw(1:m-2))+(mu^2)*(Ulw(1:m-2)-2*Ulw(2:m-1)+Ulw(3:m))/2;
    Ulw(m)=U1-q*Ulw(m-1)+q*Ulw(m);
    Ulw(1)=sin(bdA-it*dt);
    
end
Ulwerr=max(abs(Ulw(:)-U(:)));

