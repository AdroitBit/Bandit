#include<stdio.h>
#include<math.h>
#include<unistd.h>

int plan(int x,int y,int pnum){
  return (x/pnum)*(y/pnum);
}

int c(int x,int pnum){
  return x-(x/pnum)*pnum;
}

int recur(int x,int y,int pnum){
  if (x == 0)
    return 0;
  return plan(x,y,pnum)+recur(c(x,pnum),y,pnum/2);
}

void main(){
  int x,y,ans,xc,yc,pnum;
  int n=0,tmp=0;
  scanf("%d %d",&x,&y);
  if (x==0 || y==0){
    printf("0");
    return ;
  }
  //find biggest 2^n
  while(1){
    tmp = pow(2,n);
    if (tmp>x || tmp>y){
      pnum = tmp/2;
      break;
    }
    n++;
  }

  //calculate area
  ans = plan(x,y,pnum);
  xc = c(x,pnum);
  yc = c(y,pnum);
  while(1){
    // do x
    int multiply = y/pnum;
    ans += recur(xc,pnum*multiply,pnum);
    //printf("%d\n",ans);

    //do y
    multiply = x/pnum;
    ans += recur(yc,pnum*multiply,pnum);
    //printf("%d\n",ans);

    if (pnum == 1 || xc == 0 || yc == 0)
      break;

    pnum = pnum/2;

    x = xc;
    y = yc;
    ans += plan(x,y,pnum);
    xc = c(x,pnum);
    yc = c(y,pnum);
  }
  printf("%d",ans);
}

//O(log(n)^2)