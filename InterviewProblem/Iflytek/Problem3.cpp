//
// Created by linjliang on 2020/7/31.
//

/*
 * 给定两个矩形对角线的两个顶点坐标，
 * 判断俩矩形是否相交
 */

// Unsure
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long pos1[4] = {0,0,4,3};
    long pos2[4] = {0,1,5,4};
    for (int i = 0; i < 4; ++i) { cin>>pos1[i]; }
    for (int i = 0; i < 4; ++i) { cin>>pos2[i]; }

    bool ans = true;
    long long x1 = pos1[0]; long long y1 = pos1[1];
    long long x2 = pos1[2]; long long y2 = pos1[3];
    long long xmax = max(x2,x1); long long xmin = min(x2,x1);
    long long ymax = max(y2,y1); long long ymin = min(y2,y1);

    long long xx1 = pos2[0]; long long yy1 = pos2[1];
    long long xx2 = pos2[2]; long long yy2 = pos2[3];
    long long xxmax = max(xx2,xx1); long long xxmin = min(xx2,xx1);
    long long yymax = max(yy2,yy1); long long yymin = min(yy2,yy1);

    if (ymin > yymax) ans = false;
    else if (ymax < yymin) ans = false;
    else if (xmin > xxmax) ans = false;
    else if (xmax < xxmin) ans = false;

    cout<<ans<<endl;
}