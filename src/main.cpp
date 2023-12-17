#include<iostream>

using namespace std;

/*
В данном случае представлено разбиение двухмерного пространства
Соответственно полигоны выглядят, как плоскости.
Также, в данной реализации построения BSP дерева, при разбиении, нормаль изображается относительно точки,
представляющей из себя наблюдателя
*/

typedef class BSP_Node
{
	public:

	BSP_Node* back;
	BSP_Node* front;

}BSP_Node;

//точка
typedef class point
{
	//координаты точки 
	public:
	int x;
	int y;
}point;

typedef class vector
{
	public:
	point one;
	point two;
}vector;

typedef class polygon
{
	/*
	в моём случае будет реализовано 2д пространство,
	поэтому полигоны будут отображаться, как прямые
	*/
	public:
	point one;
	point two;

}polygon;

typedef class plane 
{
	public:
	polygon* list_of_polygons;

}plane;

class BSP_Tree
{
	private:

	point human;
	plane BSP_Plane;

	public:

	BSP_Tree(plane BSP_Plane, point human)
	{
		//выбираю объект, по которому буду строить плоскость
	}
	~BSP_Tree()
	{

	}

	
};

int main()
{
	//массив полигонов 
	plane *plane1 = new plane; plane1->list_of_polygons = new polygon[5]
	{
		
		{{3, 12}, {10, 16}},
		{{10, 14}, {14, 9}},
		{{9, 3}, {15, 7}},
		{{15, 12}, {17, 17}},
		{{5, 3}, {5, 9}}
	};
	point *human = new point; human->x=12; human->y=17;

	delete [] plane1;
	delete [] human;
	return 0;
}
