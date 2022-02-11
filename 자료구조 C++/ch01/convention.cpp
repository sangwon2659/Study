class box{
public:
	int x,y,width,height;
};
int range_sum ( int a,int b )
{
	int sum=0;
	for( int i=a ; i<= b ; i++ ){
		sum+=i;
	}
	return sum;
}
