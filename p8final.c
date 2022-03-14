#include<stdio.h>
struct _triangle
{
float base,altitude,area;
};
typedef struct _triangle Triangle;
int input_n()
{
	int n;
	printf("how many triangles to analyzed:");
	scanf("%d",&n);
	return n;
}
Triangle input_triangle()
{
	Triangle input;
	printf("enter the altitude and base of the triangle:");
	scanf("%f %f",&input.altitude,&input.base);
	input.area=0;
	return input;
}
void input_n_triangles(int n, Triangle t[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		t[i]=input_triangle();
	}
}
void find_area(Triangle *t)
{
	t->area=0.5*t->altitude*t->area;
}
void find_areas_n(int n, Triangle t[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		find_area(&t[i]);
	}
}
Triangle find_smallest_triangle(int n, Triangle t[n])
{
	int j,i=0,count=0;
	for(j=0;j<n;j++)
	{
		if((t[i].area)<=(t[j].area))
		{
			count=i;	
		}
		else
		{
			i++;
		}
	}
	return t[count];
}
void output(int n, Triangle t[n], Triangle smallest)
{
 printf("the smallest triangle with heigth %.1f and base %.1f has area of %.1f",smallest.altitude,smallest.base,smallest.area);

}
void main()
{
	int n;
	n=input_n();
	Triangle t[n];
	input_n_triangles(n,&t[n]);
	find_areas_n(n,&t[n]);
	Triangle smallest=find_smallest_triangle(n,&t[n]);
	output(n,&t[n],smallest);	
}