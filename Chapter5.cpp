#include <iostream>
#include <string>

using namespace std;

string Dec2Bin(double num)
{
    if(num>=1||num<=0) return "ERROR";
    string s;
    s.append("0.");
    while(num)
    {
        num=num*2;
        if(num>=1)
        {
            s.append("1");
            num=num-1;
        }
        else
        {
            s.append("0");
        }
        if(s.length()>32) return "ERROR";
    }
    return s;
}

int Flip2Win(int num)
{
    int max=1; //we can always have at least one 1s
    int cnt=0;
    int flag=0;
    
    if(num<0) return sizeof(int)*8;
    
    while(num)
    {
        bool bit=num&1;
        if(bit)
        {
            cnt++;
        }
        else
        {
            flag++;
            if(flag==1)
            {
                cnt++;
            }
            else if(flag==2)
            {
                int temp=cnt;
                max=(cnt>max? cnt:max);
                cnt=0;
                flag=0;
            }
        }
        num>>=1;
    }
    max=(cnt>max? cnt:max);
    return max;
}

void Draw(int *screen,int width,int length)
{
    int j=0;
    while(j<length)
    {
        int data=screen[j];
        for(int i=0;i<8;i++)
        {
            if(data&0x80) cout<<"-";
            else cout<<" ";
            data<<=1;
        }
        j++;
        if(j%(width/8)==0) cout<<endl;
    }
}

void DrawLine(int x1,int x2,int y,int width)
{
    int size=y*width/8;
    int temp=(x2%8)?(x2/8+1):(x2/8);
    size+=temp;
    int data[size];
    for(int i=0;i<size;i++) data[i]=0;
    for(int j=0;j<=(x2-x1)/8;j++)
    {
        data[x1/8+j+y*width/8]=0xff;
    }
    if(x1/8==x2/8) data[x1/8+y*width/8]=((1<<(8-x1))-1)&(0xff<<(8-x2%8));
    else
    {
        data[x1/8+y*width/8]=(1<<(8-x1%8))-1;
        data[x2/8+y*width/8]=0xff<<(8-x2%8);
    }
    Draw(data,width,size);
}

int main()
{
    /* 
    //Solution to 5.2
    double num;
    cout<<"input the num"<<endl;
    cin>>num;
    cout<<Dec2Bin(num);
    */
    
    /*
    //Solution to 5.3
    int num;
    cout<<"input the num"<<endl;
    cin>>num;
    cout<<Flip2Win(num);
    */
    ///*
    //Solution to 5.8
    int x1,x2,y,width;
    cout<<"input x1"<<endl;cin>>x1;cout<<endl;
    cout<<"input x2"<<endl;cin>>x2;cout<<endl;
    cout<<"input y"<<endl;;cin>>y;cout<<endl;
    cout<<"input width"<<endl;cin>>width;cout<<endl;
    
    DrawLine(x1,x2,y,width);
    //*/
    cout<<endl;
    return 0;
}
