%--------------------------------------------
% A simple test for solving the heat equation
% u_t = u_xx , x in (0,1)  (D.E.)
%u(x,0) = u_0(x)           (I.C.)
%u(0,t) = u(1,t) = 0       (B.C.)
%---------------------------------------------
clear all ;
clc;
close all;
% --- input arguments ---
m=200;
bdA=0; bdB=1;
dx=(bdB-bdA)/m;
% make a sequence of x ,which is from 0 to 1 and tolerance is dx
x=[bdA:dx:bdB]; 

dt=dx;
T=0.1;
nt=ceil(T/dt);
mu=dt/dx^2;
Ue = exp(-pi^2*T)*sin(pi*x);
% --- explict scheme ---
U = sin (pi*x);

if dt<=1/2*dx^2 
    for it = 1:nt
        U(2:m) = mu*U(1:m-1) + (1-2*mu)*U(2:m) + mu*U(3:m+1);
%         figure(1)
%         plot(x,U,'r',x,exp(-pi^2*it*dt)*sin(pi*x));
%         axis equal ; 
%         axis([ bdA, bdB, 0, 1]);
%         xlabel('x-axis'); ylabel('u');
%     title(['T = ',num2str(it*dt)]);
    end
E_ex=(max(abs(U-Ue)))
figure(1)
plot(x,U,'*',x,Ue);
else
    E_ex=nan;
end

% --- implict scheme ---
 U1 = sin (pi*x);
 
for it = 1:nt
    U1(2:m) = tridiag( (1+2*mu)*ones(m-1,1),-mu*ones(m-1,1),-mu*ones(m-1,1),U1(2:m)); %implict
%     figure(2)
%     plot(x,U1,'r',x,exp(-pi^2*it*dt)*sin(pi*x));
%     axis equal ; 
%     axis([ bdA, bdB, 0, 1]);
%     xlabel('x-axis'); ylabel('u');
%     title(['T = ',num2str(it*dt)]);
end

E_im=(max(abs(U1-Ue)));
figure(2)
plot(x,U1,'*',x,Ue);

% --- Crank-Nicholson scheme ---
U2 = sin (pi*x);

for it = 1:nt
    U2(2:m) = tridiag( (1+mu)*ones(m-1,1),-0.5*mu*ones(m-1,1),-0.5*mu*ones(m-1,1),0.5*mu*U2(1:m-1)+(1-mu)*U2(2:m)+0.5*mu*U2(3:m+1)); 
%     figure(3)
%     plot(x,U2,'r',x,exp(-pi^2*it*dt)*sin(pi*x));
%     axis equal ; 
%     axis([ bdA, bdB, 0, 1]);
%     xlabel('x-axis'); ylabel('u');
%     title(['T = ',num2str(it*dt)]);

end
E_cn=(max(abs(U2-Ue)));
figure(3)
plot(x,U2,'*',x,Ue);
 
% ---final result---

data1=[dt ;E_ex;E_im ;E_cn];
data=data1';
colnames ={'dt','E_ex','E_im','E_cn'};
figure(4)
O = uitable(data,colnames)