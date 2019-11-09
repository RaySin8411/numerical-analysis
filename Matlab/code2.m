clear all
close all

%initial value

r=4;

M=[10 20 40 80];

for z=1:r
    
inter=[0 1];
nx=M(z);

hx=(inter(2)-inter(1))/(nx+1);
x(1)=inter(1);

%diff function
f=@(x) -pi^2*sin(pi*x);

%discrete xi
    for i=1:nx+1
        x(i+1)=x(i)+hx;
    end
x=x(2:nx+2);

%Function F
F=zeros(1,nx+1);
    for i= 1:nx
        F(i)=f(x(i))*hx;
    end
F(1)=F(1)*hx/2+pi;
F(nx)=F(nx)*hx/2-pi;


A=zeros(nx+1);
    for i=1:nx+1
     for j=1:nx+1
        if i==j
            A(i,j)=-2;
        end
        if abs(i-j)==1
            A(i,j)=1;
        end
     end
    end
A=A/(hx);
A(1,1)=-hx;
A(nx+1,nx+1)=A(1,1);
V=A\F';

%Analytical solution
u=@(x) sin(pi*x);
U=zeros(1,nx+1);
    for i=1:nx
        U(i)=u(x(i));
    end
U=U';
K=U-V;
e_max = max(abs(K()));% part of e_max
E_max(z) = e_max;
end
E1=nan;
for c = 1:r-1
    E1(c+1) = E_max(c)/E_max(c+1);
end
data1 = [M; E_max; E1];
data = data1';
colnames = {'M','emax','emax¤ñ­È'};
O = uitable(data,colnames)