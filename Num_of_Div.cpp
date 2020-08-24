ll a[1001];
void numofdiv()
{
    ll mx=sqrt(1000),ii,jj;
    for(ii=1; ii<=mx; ii++)
    {
        for(jj=ii*ii; jj<=1000; jj+=ii)
        {
            if(jj==ii*ii)
                a[jj]++;
            else
                a[jj]+=2;
        }
    }
}
