//2019.6.5 by ljz
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define RG register
typedef pair<LL,LL> Pair;
#define mp make_pair
#define fi first
#define se second
inline char gc() {
    static char buf[100000],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10,B=510+10;
namespace MAIN {
    inline LL cal(const RG Pair &x,const RG LL &val){
        return x.fi*val+x.se;
    }
    inline Pair operator + (const RG Pair &A,const RG Pair &B){
        return mp(A.fi+B.fi,A.se+B.se);
    }
    inline bool cmp(const RG Pair &A,const RG Pair &B,const RG LL &x){
        return cal(A,x)<cal(B,x);
    }
    inline bool cmp(const RG Pair &A,const RG Pair &B,const RG Pair &C){
        return (A.se-C.se)*(A.fi-B.fi)>=(A.se-B.se)*(A.fi-C.fi);
    }
    inline bool cmp(const RG Pair &A,const RG Pair &B,const RG Pair &C,const RG Pair &D){
        return (C.se-D.se)*(A.fi-B.fi)>=(A.se-B.se)*(C.fi-D.fi);
    }
    inline bool cmp(const RG Pair &A,const RG Pair &B){
        return A.fi!=B.fi?A.fi<B.fi:A.se>B.se;
    }
    Pair mem[N*100],*ptr=mem,st[N<<2],st0[N<<2],st1[N<<2];
    struct TU{
        Pair *a;
        int siz;
        TU() {siz=0;}
        inline void Cover(const RG Pair *A,const res &sz){
            siz=sz;
            for(res i=1;i<=sz;i++)a[i]=A[i];
        }
        inline void mod(const RG LL &x){
            res p=1;
            while(p<siz&&cmp(a[p],a[p+1],x))p++;
            for(res i=p;i<=siz;i++)a[i-p+1]=mp(a[i].fi,a[i].se+a[i].fi*x);
            siz-=p-1;
        }
        inline void mod(const RG LL &x,res &p){
            while(p<siz&&cmp(a[p],a[p+1],x))p++;
        }
        inline void get(const res &len){
            a=ptr,ptr+=len+1;
        }
    };
    inline void add_TU(res &top,const RG Pair &x){
    	if(top&&x.fi==st[top].fi){st[top].se=max(st[top].se,x.se);return;}
    	while(top>1&&cmp(st[top-1],st[top],x))top--;
    	st[++top]=x;
    }
    inline void Minkowski(const RG TU &lm,const RG TU &rm,const RG TU &ansl,const RG TU &ansr,RG TU &ret){
    	res top0=0,top1=0,i=1,j=1,szl=lm.siz,szr=rm.siz,Top=0;
    	for(;i<szl||j<szr;)st0[++top0]=lm.a[i]+rm.a[j],i==szl?j++:(j==szr?i++:(cmp(lm.a[i],lm.a[i+1],rm.a[j],rm.a[j+1])?j++:i++));
        st0[++top0]=lm.a[szl]+rm.a[szr],i=j=1,szl=ansl.siz,szr=ansr.siz;
        for(;i<=szl||j<=szr;)i==szl+1?st1[++top1]=ansr.a[j++]:(j==szr+1?st1[++top1]=ansl.a[i++]:(st1[++top1]=cmp(ansl.a[i],ansr.a[j])?ansl.a[i++]:ansr.a[j++]));
        for(i=j=1,szl=top0,szr=top1;i<=szl||j<=szr;)i==szl+1?add_TU(Top,st1[j++]):(j==szr+1?add_TU(Top,st0[i++]):(add_TU(Top,cmp(st0[i],st1[j])?st0[i++]:st1[j++])));
        ret.Cover(st,Top);
    }
    inline void merge(const RG TU &A,const RG TU &B,const RG LL &sum,const res &len,RG TU &ret){
        res Top=0;
        for(res i=1,sz=A.siz;i<=sz;i++)st[++Top]=A.a[i];
        for(res i=1,sz=B.siz;i<=sz;i++)add_TU(Top,mp(len+B.a[i].fi,sum+B.a[i].se));
        ret.Cover(st,Top);
    }
    struct TR{
        int len;
        TU pre,suf,ans;
        LL sum,laz;
        inline void init(const RG LL &val){
            sum=val,pre.siz=1,pre.a[1]=mp(1,val),suf.siz=1,suf.a[1]=mp(1,val),ans.siz=1,ans.a[1]=mp(1,val);
        }
        inline void Change(const RG LL &val){
        	pre.mod(val),suf.mod(val),ans.mod(val);
        }
        inline void change(const RG LL &val){
            pre.mod(val),suf.mod(val),ans.mod(val),sum+=len*val,laz+=val;
        }
        inline void mod(const RG LL &TG,const res &val,res &ansp,res &prep,res &sufp){
            laz+=val,sum+=len*val,ans.mod(TG,ansp),pre.mod(TG,prep),suf.mod(TG,sufp);
        }
        inline void get(){
            pre.get(len),suf.get(len),ans.get(len);
        }
    };
    struct P{
        LL lm,rm,sum,mx;
        P() {}
        P(RG LL lm,RG LL rm,RG LL sum,RG LL mx):lm(lm),rm(rm),sum(sum),mx(mx) {}
    };
    inline P operator + (const RG P &A,const RG P &B){
        return P(max(A.lm,A.sum+B.lm),max(B.rm,B.sum+A.rm),A.sum+B.sum,max({A.rm+B.lm,A.mx,B.mx}));
    }
    LL qaq[B];
    struct BL{
        LL a[B],tag,mx,lm,rm;
        int n,ansp,prep,sufp;
        TR tr[B<<2];
        inline void pushup(const res &rt){
            res ls=rt<<1,rs=rt<<1|1;
            tr[rt].sum=tr[ls].sum+tr[rs].sum,merge(tr[ls].pre,tr[rs].pre,tr[ls].sum,tr[ls].len,tr[rt].pre),merge(tr[rs].suf,tr[ls].suf,tr[rs].sum,tr[rs].len,tr[rt].suf),Minkowski(tr[ls].suf,tr[rs].pre,tr[ls].ans,tr[rs].ans,tr[rt].ans);
        }
        void build(res rt,res l,res r){
            tr[rt].len=r-l+1,tr[rt].laz=tr[rt].sum=0,tr[rt].get();
            if(l==r){tr[rt].init(a[l]);return;}
            res mid=(l+r)>>1;
            build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),pushup(rt);
        }
        inline void pushdown(const res &rt){
            if(!tr[rt].laz)return;
            tr[rt<<1].change(tr[rt].laz),tr[rt<<1|1].change(tr[rt].laz),tr[rt].laz=0;
        }
        void modify(res rt,res l,res r,const res &L,const res &R,const res &val){
            if(L<=l&&r<=R){tr[rt].change(val);return;}
            pushdown(rt);
            res mid=(l+r)>>1;
            if(L<=mid)modify(rt<<1,l,mid,L,R,val);
            if(R>mid)modify(rt<<1|1,mid+1,r,L,R,val);
            pushup(rt);
        }
        inline void push(){
            ansp=prep=sufp=1;
            if(!tag)return;
            for(res i=1;i<=n;i++)a[i]+=tag;
            tr[1].Change(tag),tag=0;
        }
        inline void blmod(const res &l,const res &r,const res &val){
            for(res i=l;i<=r;i++)a[i]+=val;
        }
        inline void mod(const res &val){
            tag+=val,tr[1].mod(tag,val,ansp,prep,sufp),mx=cal(tr[1].ans.a[ansp],tag),lm=cal(tr[1].pre.a[prep],tag),rm=cal(tr[1].suf.a[sufp],tag);
        }
        inline LL mxcalc(const res &l,const res &r){
            res tot=0;
            for(res i=l;i<=r;i++)qaq[++tot]=a[i]+tag;
            for(res i=1;i<=tot;i++)qaq[i]+=qaq[i-1];
            RG LL mn=0,ret=0;
            for(res i=1;i<=tot;i++)ret=max(ret,qaq[i]-mn),mn=min(mn,qaq[i]);
            return ret;
        }
        inline P calc(const res &l,const res &r){
            RG P ret=P(0,0,0,0);
            res tot=0;
            for(res i=l;i<=r;i++)qaq[++tot]=a[i]+tag;
            for(res i=1;i<=tot;i++)ret.sum+=qaq[i],ret.lm=max(ret.lm,ret.sum);
            ret.sum=0;
            for(res i=tot;i;i--)ret.sum+=qaq[i],ret.rm=max(ret.rm,ret.sum);
            RG LL mn=0;
            for(res i=1;i<=tot;i++)qaq[i]+=qaq[i-1];
            for(res i=1;i<=tot;i++)ret.mx=max(ret.mx,qaq[i]-mn),mn=min(mn,qaq[i]);
            return ret;
        }
        inline P calc(){
        	return P(lm,rm,tr[1].sum,mx);
        }
    }A[B];
    int a[N],pl[N],pr[N],Mp[N],n,m,block;
    inline void MAIN(){
        n=read(),m=read(),block=int(sqrt(n));
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++)pr[i/block]=i;
        for(res i=n;i;i--)pl[i/block]=i;
        for(res i=0;i<=n/block;i++){
            for(res j=pl[i];j<=pr[i];j++)A[i].a[j-pl[i]+1]=a[j],Mp[j]=j-pl[i]+1;
            A[i].n=pr[i]-pl[i]+1,A[i].build(1,1,A[i].n),A[i].push(),A[i].mod(0);
        }
        while(m--){
            res opt=read(),l=read(),r=read();
            if(opt==1){
                res x=read();
                if(l/block==r/block){
                    res ID=l/block;
                    A[ID].push(),A[ID].blmod(Mp[l],Mp[r],x),A[ID].modify(1,1,A[ID].n,Mp[l],Mp[r],x),A[ID].mod(0);
                }
                else {
                    res ID=l/block;
                    A[ID].push(),A[ID].blmod(Mp[l],A[ID].n,x),A[ID].modify(1,1,A[ID].n,Mp[l],A[ID].n,x),A[ID].mod(0);
                    ID=r/block,A[ID].push(),A[ID].blmod(1,Mp[r],x),A[ID].modify(1,1,A[ID].n,1,Mp[r],x),A[ID].mod(0);
                    for(res i=l/block+1;i<ID;i++)A[i].mod(x);
                }
            }
            else {
                if(l/block==r/block)printf("%lld\n",A[l/block].mxcalc(Mp[l],Mp[r]));
                else {
                    RG P ret=A[l/block].calc(Mp[l],A[l/block].n);
                    for(res i=l/block+1;i<r/block;i++)ret=ret+A[i].calc();
                    ret=ret+A[r/block].calc(1,Mp[r]),printf("%lld\n",ret.mx);
                }
            }
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}
