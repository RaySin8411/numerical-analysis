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
    for i=1:nx
        x(i+1)=x(i)+hx;
    end
x=x(2:nx);

%Function F
F=zeros(1,nx);
    for i= 1:nx-1
        F(i)=f(x(i));
    end
A = diag(-2*ones(nx,1),0) + diag(ones(nx-1,1),-1) + diag(ones(nx-1,1),1)

A=A/(hx^2);
V=A\F';



%Analytical solution
u=@(x) sin(pi*x);
U=zeros(1,nx);
    for i=1:nx-1
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


