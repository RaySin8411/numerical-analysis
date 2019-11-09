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
Up=sin(x);



%Upwind

for it= 1:nt
    Up(2:m)=Up(2:m)-mu*(Up(2:m)-Up(1:m-1));
    Up(1)=sin(bdA-it*dt);

    
end
Uperr=max(abs(Up(:)-U(:)));

