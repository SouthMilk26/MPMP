#include<bits/stdc++.h>
using namespace std;
int n,mode;
bool m[1000][1000];
int number;
void show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void check(){
    int aux=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            aux+=m[i][j];
        }
    }
    if(aux!=ceil(n*n*0.5))return;
    // cout << aux<<endl;
    for(int k=1;k<n;k++){
        for(int l=-n;l<=n;l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int p[2][4];
                    bool possible=true;
                    p[0][0]=i;p[1][0]=j;
                    p[0][1]=i-l;p[1][1]=j+k;
                    p[0][2]=i-l+k;p[1][2]=j+l+k;
                    p[0][3]=i+k;p[1][3]=j+l;
                    for(int aux=0;aux<4;aux++){
                        if(p[0][aux]<0||p[0][aux]>=n)possible=false;
                        if(p[1][aux]<0||p[1][aux]>=n)possible=false;
                    }
                    if(possible&&m[p[0][0]][p[1][0]]==m[p[0][1]][p[1][1]]&&m[p[0][0]][p[1][0]]==m[p[0][2]][p[1][2]]&&m[p[0][0]][p[1][0]]==m[p[0][3]][p[1][3]]){
//                        for(int aux=0;aux<4;aux++){
//                            cout << p[0][aux]<<","<<p[1][aux]<<endl;
//                        }
                        return;
                    }
                    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                }
            }
        }
    }
    if(mode==2)show();
    number++;
    return;
}

void create(int x,int y){
    if(y==n){
        x++;
        y=0;
    }
    if(x==n){
        check();
    }
    else{
        create(x,y+1);
        m[x][y]=1;
        create(x,y+1);
        m[x][y]=0;
    }
    return;
}

int main(){
    cin >> mode;
    if(mode==1){
        for(n=1;n<6;n++){
            number=0;
            create(0,0);
            cout <<n<<"- "<<number<<endl;
        }
    }
    else if(mode==2){
        cin >> n;
        create(0,0);
    }
    return 0;
}
