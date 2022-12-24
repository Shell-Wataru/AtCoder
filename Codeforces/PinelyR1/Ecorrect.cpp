#include <cstdio>
#include <vector>
#include <unordered_set>
const int inf=1e9,N=4e3+10;
int T,n,id,ans,deg[N];bool vis[N];char s[N][N];
std::unordered_set<int> nset,fans;std::vector<std::unordered_set<int>> vec;
void dfs(int u){
	nset.insert(u),vis[u]=true;
	for(int i=1;i<=n;++i)if(s[u][i]=='1'&&!vis[i])dfs(i);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=inf,vec.clear();
		for(int i=1;i<=n;++i){
			deg[i]=0,vis[i]=false,scanf("%s",s[i]+1);
			for(int j=1;j<=n;++j)deg[i]+=s[i][j]^48;
		}
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			nset.clear(),dfs(i),vec.push_back(nset);
		}
		if(vec.size()==1){puts("0");continue;}
		for(auto i:vec){
			int p=*i.begin();
			for(int j:i)if(deg[j]<deg[p])p=j;
			if(deg[p]!=(int)i.size()-1||!deg[p])ans=1,id=p;
			else if((int)i.size()<ans)ans=i.size(),fans=i;
		}
		if(ans>2&&vec.size()>2){
			printf("2\n1 "),deg[1]=n-1-deg[1];int p=1;
			for(int i=2;i<=n;++i)deg[i]-=(s[1][i]^48),deg[i]+=((s[1][i]^=1)^48);
			for(int i=2;i<=n;++i)if(s[1][i]=='1'&&deg[i]<deg[p])p=i;
			printf("%d\n",p);continue;
		}
		printf("%d\n",ans);
		if(ans==1)printf("%d",id);
		else for(int i:fans)printf("%d ",i);
		putchar('\n');
	}
	return 0;
}
