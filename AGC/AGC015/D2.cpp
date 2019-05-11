#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,i,j,k,t1,t2,t3,t4,ans;
int a[66],b[66];
int main(){
	scanf("%lld%lld",&n,&m);
	if (n==m){
		puts("1");return 0;
	}
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	for (a[0]=0,i=n;i;i>>=1) a[++a[0]]=(i&1);
	for (b[0]=0,i=m;i;i>>=1) b[++b[0]]=(i&1);
	for (k=b[0];a[k]==b[k];k--);
	for (j=k-1;j&&!b[j];j--);
	t1=n&((1LL<<k)-1);t2=(1LL<<(k-1))+(1LL<<j)-1;
	t3=(1LL<<(k-1))+(t1);t4=(1LL<<k)-1;
	if (t3<=t2) ans=t4-t1+1;else ans=t2-t1+1+t4-t3+1;
	printf("%lld\n",ans);
	return 0;
}
