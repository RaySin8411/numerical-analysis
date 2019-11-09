%--------------------------------------------
% A simple test for solving the heat equation
% u_t + u_x = 0       x in (0,2*pi)  (D.E.)
%u(x,0) = sin x                      (I.C.)
%u(0,t) = sin(-t)                    (B.C.)
%---------------------------------------------
clear all;close all;clc;
% --- input arguments ---

bdA=0;bdB=2*pi;
dx=2*pi/200;
x=[bdA:dx:bdB];
m=length(x);

dt=0.5*dx;
T=2*pi;nt=ceil(T/dt);
mu=dt/dx;


%The final exact solution
U=sin(x-T);

%Upwind
%initial profile of U(x,0)
Up=sin(x);
%loop
for it= 1:nt
    Up(2:m)=Up(2:m)-mu*(Up(2:m)-Up(1:m-1));
    Up(1)=sin(bdA-it*dt);

    
end
Uperr=max(abs(Up(:)-U(:)));

%FTCS
%initial profile of U(x,0)
Uf=sin(x);
%loop
for it= 1:nt
    Uf(2:m-1)=Uf(2:m-1)-(mu/2)*(Uf(3:m)-Uf(1:m-2));
    Uf(1)=sin(bdA-it*dt);
    Uf(m)=sin(bdB-it*dt);
%         figure(1)
%         plot(x,U,'r',x,exp(-pi^2*it*dt)*sin(pi*x));
%         axis equal ; 
%         axis([ bdA, bdB, 0, 1]);
%         xlabel('x-axis'); ylabel('u');
%     title(['T = ',num2str(it*dt)]);
end
Uferr=max(abs(Uf(:)-U(:)));

%laxfriendriches
%initial profile of U(x,0)
Ulf=sin(x);
%loop
for it= 1:nt
    Ulf(2:m-1)=1/2*(Ulf(3:m)+Ulf(1:m-2))-mu/2*(Ulf(3:m)-Ulf(1:m-2));
    Ulf(1)=sin(bdA-it*dt);
    Ulf(m)=sin(bdB-it*dt);
end
Ulferr=max(abs(Ulf(:)-U(:)));
%lax-wendroff
%initial profile of U(x,0)
Ulw=sin(x);
q=(1-mu)/(1+mu);
%loop
for it= 1:nt
    U1=Ulw(m-1);
    Ulw(2:m-1)=Ulw(2:m-1)-mu/2*(Ulw(3:m)-Ulw(1:m-2))+(mu^2)*(Ulw(1:m-2)-2*Ulw(2:m-1)+Ulw(3:m))/2;
    Ulw(m)=U1-q*Ulw(m-1)+q*Ulw(m);
    Ulw(1)=sin(bdA-it*dt);
    
end
Ulwerr=max(abs(Ulw(:)-U(:)));

data1=[dt; Uperr;Uferr ;Ulferr;Ulwerr];
data=data1';
colnames ={'dt','Uperr','Uferr','Ulferr','Ulwerr'};
figure(4)
O = uitable(data,colnames)

