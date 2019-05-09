#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Min(a,b,c) min(a,min(b,c))

double farthest(int *sum_x_y,int* min_x_y,int N){

    int min_sum =INT_MAX;
    int min_min =INT_MAX;
    double ans=0;

	for (int i = 2; i <= N; ++i)
	{
       min_sum = min(min_sum,abs(sum_x_y[i]-sum_x_y[i-1]));
       min_min = min(min_min,abs(min_x_y[i]-min_x_y[i-1]));

	}
	ans =  min(min_sum,min_min)/(double)2;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout<<setprecision(25);

	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		int* x = new int[N+1];
		int* y = new int[N+1];
		int* sum_x_y = new int[N+1]();
		int* min_x_y = new int[N+1]();

		for (int i = 1; i <= N; ++i)
		{
			cin>>x[i]>>y[i];
			sum_x_y[i] = x[i]+y[i]; 
			min_x_y[i] = x[i]-y[i];
		}

		sort(sum_x_y+1,sum_x_y+N+1);
		sort(min_x_y+1,min_x_y+N+1);
		
		cout<<  farthest(sum_x_y,min_x_y,N) <<endl;

		free(x);
		free(y);
		free(sum_x_y);
		free(min_x_y);
	}
	return 0;
}