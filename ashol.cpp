#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)

char ch[40],evaluate[40],hayre[40],str[40],matha[40];

double fact(int a)
{
    if(a<=1)return 1;
    return a*fact(a-1);
}

double expression(char *c,int koto)
{
    //cout<<c<<endl;
    int is=0;
    if(*c=='-'){is=1;c++;}
    char *v=NULL,*m=c;
    while(isdigit(*c)||*c=='.')
        c++;
    double ans=0;
    if(*c=='+'||*c=='-')
    {
        if(*c=='+'&&koto%2==0)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)+expression(c+1,koto);
            else ans=-atof(v)+expression(c+1,koto);
        }
        else if(*c=='-'&&koto%2==0)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)-expression(c+1,koto+1);
            else ans=-atof(v)-expression(c+1,koto+1);
        }
        else if(*c=='+'&&koto%2==1)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)-expression(c+1,koto+1);
            else ans=-atof(v)-expression(c+1,koto+1);
        }
        else if(*c=='-'&&koto%2==1)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)+expression(c+1,koto);
            else ans=-atof(v)+expression(c+1,koto);
        }
    }
    else if(*c=='*'||*c=='/')
    {
        int sun=0;
        if(*c=='/')sun=1;
        double bushra;
        if(is==0)bushra=atof(strtok(m,"*/"));
        else bushra=-atof(strtok(m,"*/"));
        //cout<<bushra<<"kopal"<<endl;
        while(1)
        {
            is=0;
            c++;
            if(*c=='-')
            {
                is=1;
                c++;
            }
            m=c;
            while(isdigit(*c)||*c=='.')
                c++;
            if(sun&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra/=atof(strtok(m,"*/"));
                else bushra/=-atof(strtok(m,"*/"));
            }
            else if(sun)
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra/=atof(strtok(m,"+-"));
                else bushra/=-atof(strtok(m,"+-"));
                //cout<<bushra<<"le"<<endl;
                break;
            }
            else if(sun==0&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra*=atof(strtok(m,"*/"));
                else bushra*=-atof(strtok(m,"*/"));
            }
            else
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra*=atof(strtok(m,"+-"));
                else bushra*=-atof(strtok(m,"*/"));
                break;
            }
        }
        ans=bushra;
        if(sun==1&&koto%2==0)
            ans+=expression(c+1,koto);
        else if(sun==1&&koto%2==1)
            ans-=expression(c+1,koto+1);
        else if(sun==2&&koto%2==0)
            ans-=expression(c+1,koto+1);
        else if(sun==2&&koto%2==1)
            ans+=expression(c+1,koto);
    }
    else if(*c==')'&&is==0)ans=atof(m);
    else if(*c==')'&&is)ans=-atof(m);
    //cout<<ans<<endl;
    return ans;
}

int main()
{
    int len,i;
    gets(ch);
    //cout<<expression(ch,0)<<endl;
    len=strlen(ch);
    if(ch[0]!='(')
    {
        ch[len]=')';
        //cout<<ch<<endl;
        evaluate[0]='(';
        strcat(evaluate,ch);
        //cout<<expression(evaluate,0);
    }
    else
    {
        int hihi=1;
        //int ln=strlen(ch);
        for(i=1;i<len;i++)
        {
            if(hihi==0)break;
            if(ch[i]=='(')hihi++;
            else if(ch[i]==')')hihi--;
        }
        if(i!=len)
        {
            ch[len]=')';
            evaluate[0]='(';
            strcat(evaluate,ch);
        }
        else strcpy(evaluate,ch);
    }
    len=strlen(evaluate);
    //cout<<evaluate<<endl;
    char *ptr=NULL;
    for(i=len-1;i>-1;i--)
    {
        //cout<<"-_-"<<endl;

        memset(str,0,sizeof str);
        //cout<<"HIHI"<<endl;
        //cout<<"htha"<<endl;
        if(evaluate[i]=='(')
        {
            memset(matha,0,sizeof matha);
            //cout<<evaluate<<" uff"<<endl;
            int sun=0;
            //printf("%d eibar\n",i);
            double ans;
            int j,k;
            ptr=&evaluate[i];
            //strcpy(str,evaluate);
            while(1)
            {
                //cout<<"HIHI"<<endl;
                if(*ptr==')'||*ptr==0)break;
                ptr++;
            }
            //cout<<*ptr<<endl;
            if(*ptr==')')ptr++;
            //cout<<(int)*ptr<<"-_-"<<endl;

            strcpy(matha,evaluate);
            ans=expression(&matha[i+1],0);
            //cout<<evaluate<<" er"<<endl;
            if(i==0);
            else if(evaluate[i-1]=='t'&&evaluate[i-2]=='c')
            {
                ans=fact((int)ans);
                //cout<<ans;
                i-=4;
            }
            else if(evaluate[i-1]=='n'&&evaluate[i-2]=='i')
            {
                if(i-4<0||evaluate[i-4]!='a')
                {
                    ans=sin(ans*pi/180);
                    i-=3;
                }
                else
                {
                    ans=180/pi*asin(ans);
                    i-=4;
                }
            }
            else if(evaluate[i-1]=='s'&&evaluate[i-2]=='o')
            {
                if(i-4<0||evaluate[i-4]!='a')
                {
                    ans=cos(ans*pi/180);
                    i-=3;
                }
                else
                {
                    ans=180/pi*acos(ans);
                    i-=4;
                }
            }
            else if(evaluate[i-1]=='n'&&evaluate[i-2]=='a')
            {
                if(i-4<0||evaluate[i-4]!='a')
                {
                    ans=tan(ans*pi/180);
                    i-=3;
                }
                else
                {
                    ans=180/pi*atan(ans);
                    i-=4;
                }
            }
            else if(evaluate[i-1]=='n'&&evaluate[i-2]=='l')
            {
                ans=log(ans);
                i-=2;
            }
            else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='a')
            {
                if(i-5<0||evaluate[i-5]!='a')
                {
                    ans=tanh(ans);
                    i-=4;
                }
                else
                {
                    ans=atanh(ans);
                    i-=5;
                }
            }
            else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='i')
            {
                if(i-5<0||evaluate[i-5]!='a')
                {
                    ans=sinh(ans);
                    i-=4;
                }
                else
                {
                    ans=asinh(ans);
                    i-=5;
                }
            }
            else if(evaluate[i-1]=='h'&&evaluate[i-2]=='s'&&evaluate[i-3]=='o')
            {
                if(i-5<0||evaluate[i-5]!='a')
                {
                    ans=cosh(ans);
                    i-=4;
                }
                else
                {
                    ans=acosh(ans);
                    i-=5;
                }
            }
            else if(evaluate[i-1]=='g'&&evaluate[i-2]=='o')
            {
                ans=log10(ans);
                i-=3;
            }
            else if(evaluate[i-1]=='^')
            {
                if(!isdigit(evaluate[i-2]));
                else
                {
                    char tutu[40];
                    int j,mama=0;
                    for(j=i-2;;j--)
                    {
                        if(!isdigit(evaluate[j]))break;
                        tutu[mama++]=evaluate[j];
                    }
                    tutu[mama]=0;
                    strrev(tutu);
                    i=j+1;
                    ans=pow(atof(tutu),ans);
                    //cout<<ans<<endl;
                    //cout<<evaluate<<endl;
                }
            }
            for(j=0;j<i;j++)
                str[j]=evaluate[j];
            //strcpy(evaluate,matha);
            //ans=expression(&evaluate[i+2],0);
            //cout<<ans<<endl;
            sprintf(hayre,"%lf",ans);
            //cout<<hayre<<" :3"<<endl;
            //cout<<itoa((int)ans,w,10)<<endl;
            //cout<<w<<endl;
            for(k=0;k<strlen(hayre);k++)
                str[j++]=hayre[k];
            //cout<<"MIU"<<endl;
            //else strcat(str,w);
            //cout<<str<<"lolo"<<endl;
            strcat(str,ptr);
            memset(evaluate,0,sizeof evaluate);
            strcpy(evaluate,str);
            i=strlen(evaluate);
            //cout<<i<<" uff"<<endl;
            //cout<<evaluate<<" hmm"<<endl;
            //printf("-_-\n");printf("-_-\n");
            ptr=NULL;
        }
        //printf("-_-\n");
    }
    cout<<atof(evaluate);
}
