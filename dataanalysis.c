#include<Rtypes.h>

void dataanalysis()
{

int nb=20,b,c;
int ns=13;
int nd;
double x[50]={0},p[50],qnd[50],p1[50],x1[50]={0},shp1[33],shp[33],shqnd[33];
for(int i=0;i<450000;i++)
{
c= gRandom->Poisson(20);
b= gRandom->Poisson(33);
for(int j=0;j<50;j++)
{
if(b==j)
{
x[j]=x[j]+1;
}
if(c==j)
{
x1[j]=x1[j]+1;
}
}
}

for(int k=0;k<50;k++)
{
p1[k]=x1[k]/450000;
p[k]=x[k]/450000;
qnd[k]=-2*TMath::Log((TMath::Poisson(k,nb+ns))/(TMath::Poisson(k,nb)));
//cout<<k<<" "<<qnd[k]<<" " <<p[k]<<"\n";
}

for(int k=0;k<22;k++)
{
shp1[k]=p1[k];
shp[k]=p[k];
shqnd[k]=qnd[k];
cout<<shqnd[k]<<" " <<shp[k]<<" "<<shp1[k]<<"\n";
}
cout<<"the line\n";
for(int k=0;k<11;k++)
{
shp1[k+22]=p[22]-(k*p[22]/10);
shp[k+22]=p[22]-(k*p[22]/10);
shqnd[k+22]=3.96589;
cout<<shqnd[k+22]<<" " <<shp[k+22]<<" "<<shp1[k+22]<<"\n";
}


///plotting part******************************************************
//cf->SetFillColor(2);
//cf->SetFillStyle(3002);

TGraph *n1=new TGraph(50,qnd,p1);
n1->SetLineColor(kBlue);
n1->SetLineWidth(2);
TGraph *cf1=new TGraph(33,shqnd,shp1);
cf1->SetFillStyle(3004);
cf1->SetFillColor(kBlue);
cf1->SetLineColor(kBlue);
cf1->SetLineWidth(2);
TGraph *n=new TGraph(50,qnd,p);
TGraph *cf=new TGraph(33,shqnd,shp);
n->SetLineWidth(2);
n->SetLineColor(kRed);
cf->SetFillColor(kRed);
cf->SetFillStyle(1001);
cf->SetLineColor(kRed);
cf->SetLineWidth(2);

TMultiGraph *g=new TMultiGraph();
g->Add(n,"AC");
g->Add(n1,"AC");
g->Add(cf,"CF");
g->Add(cf1,"CF");
g->
g->Draw("a");

TLine *l = new TLine(3.96589,0,3.96589,0.09);
l->SetLineWidth(2);
l->Draw();

cout<<"program over";
}
