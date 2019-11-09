%--------------------------------------------
% A simple test for solving the heat equation
% u_t = 0.1( u_xx + u_yy) , x in (0,1) y in  (0,1)  (D.E.)
%u(x,y,0) = u_0(x,y)                                (I.C.)
%u(0,t) = u(1,t) = 0                                (B.C.)
%---------------------------------------------
clear all;close all;clc;
% --- input arguments ---
m=100;n=m;
bdA=0;bdB=1;bdC=0;bdD=1;nu=0.1;
dx=(bdB-bdA)/m;dy=(bdC-bdD)/n;
xg=[bdA:dx:bdB];yg=[bdC:dx:bdD];
[xx yy]=meshgrid(xg,yg);xx=xx';yy=yy';

dt=min([dx,dy]);
endT=0.1;nt=floor(endT/dt);
mux=dt*nu/(2*dx*dx);muy=dt*nu/(2*dy*dy);

%Set screen size
scrsz=get(0,'ScreenSize');
figure('Position',[500 250 scrsz(3)/1.5 scrsz(4)/2]);%colormap('hot');

%initial profile of U(x,y,0)
U=Uex(xx,yy,0,nu);

%allocation variables 
Ui=zeros(m+1,n+1);
Ue=zeros(m+1,n+1);
Ue0=zeros(m+1,n+1);

%main loop


 Ue=U


for it=1:nt
  for i= 1:m+1
    
    Ui(1,i)=1/2*(Ue(1,i)+Ue0(1,i))+muy/2*(Ue0(1,i)-Ue(1,i))+1/2*(Ue0(2,i)-Ue(2,i));
     Ui(m+1,i)=1/2*(Ue(m+1,i)+Ue0(m+1,i))+muy/2*(Ue0(m+1,i)-Ue(m+1,i))+1/2*(Ue0(m,i)-Ue(m,i));
     Ui(i,1)=1/2*(Ue(i,1)+Ue0(i,1))+muy/2*(Ue0(i,1)-Ue(i,1))+1/2*(Ue0(i,2)-Ue(i,2));  
      Ui(i,m+1)=1/2*(Ue(i,m+1)+Ue0(i,m+1))+muy/2*(Ue0(i,m+1)-Ue(i,m+1))+1/2*(Ue0(i,m)-Ue(i,m));
  end
  
                           
  
    

    for j=2:n
    for i=2:m
         f1=muy*Ue(i,j-1)+(1+muy)*Ue(i,j)+muy*Ue(i,j+1) ;                                                                                                                                                             
        Ui(i,j)= tridiag( (1-mux)*ones(m-1,1),-mux*ones(m-1,1),-mux*ones(m-1,1),f1);
    end
    end
     
    for i=2:m
        for j=2:n
        f2=mux*Ui(i-1,j)+(1+mux)*Ue(i,j)+mux*Ue(i+1,j);  
        Ue0(i,j)= tridiag( (1-muy)*ones(m-1,1),-muy*ones(m-1,1),-muy*ones(m-1,1),f2);
        end
    end
   
  
    figure(1);
    subplot(1,3,1);surf(xx,yy,U);
    subplot(1,3,2);surf(xx,yy,Ue);
    subplot(1,3,3);surf(xx,yy,U-Ue);
   Ue=Ue0
end

fprintf(['(m,n)=(',num2str(m),',',num2str(n) '),=||U-Ue||_infty = ',num2str(max(abs(U(:)-Ue(:)))) , ' \n ']);