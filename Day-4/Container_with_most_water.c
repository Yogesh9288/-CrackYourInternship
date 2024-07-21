int maxArea(int* height, int heightSize) {
    int ans=0;
    int i=0;
    int j=heightSize-1;

    while(i<j)
    {
        int min=(height[i]>height[j])?height[j]:height[i];
        int area=min*(j-i);
        if(ans<area) ans=area;
        if(height[i]<height[j]) i++;
        else j--;
    }


    return ans;
}
