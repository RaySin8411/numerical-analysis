%initial
alpha=1;
beta=3;
elison=[0.3 0.1 0.05 0.01];
hx=1/100;

for r=1:4

 inter=[0 1];
 x(1)=inter(1);
 %discrete xi
    for i=1:101
        x(i+1)=x(i)+hx;
    end
 x=x(2:101);
 %discretr function   
 u=@(x) alpha+x+(beta-alpha-1)*(exp(x/elison(r))-1)/(exp(1/elison(r))-1);

 U=zeros(1,100);
    for i= 1:100
        U(i)=(u(x(i)));
    end
    subplot(2,2,r);
    plot(x,U)
    
end