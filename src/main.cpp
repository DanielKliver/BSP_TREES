#include<iostream>
#include<vector>

const int num_of_polygon = 5;

using namespace std;


typedef class BSP_Node
{
	public:
	int index;
	BSP_Node* back = NULL;
	BSP_Node* front = NULL;

}BSP_Node;

typedef class point
{
	public:
	int x;
	int y;
}point;

typedef class polygon
{
	public:
	point one;
	point two;

}polygon;

class BSP_Tree
{
	private:

	BSP_Node *root = NULL;
	polygon *list_of_polygons = NULL;

	public:

	void add_node(polygon *list_of_polygons, BSP_Node *root)
	{
		//НЕТ РЕКУРСИИ
		if(root==NULL)
		{
			//первый полигон из списка будет корнем
			root = new BSP_Node;
			root->index = 0;
		}
		//НЕТ РЕКУРСИИ

		//проверка расположения оставшихся полигонов, относительно текущего
		//вычисление размера текущего списка полигонов
		//int list_size = 0;for(int i: list_of_polygons){list_size++}//for(int i = 0; list_of_polygons<5;i++){list_size++;}

		for(int i = 1; i< num_of_polygon; i++)
		{
			cout<<"count"<<endl;
		}
		////////////////////////////////////////////////////////////////////
	}

	BSP_Tree(polygon *list_of_polygons)
	{
		this->list_of_polygons = list_of_polygons;
		add_node(list_of_polygons, root);
	}

	~BSP_Tree()
	{

	}
	
};

int main()
{
	//массив полигонов 

	polygon *list_of_polygons = new polygon[num_of_polygon]
	{
	{{3, 12}, {10, 16}},
	{{10, 14}, {14, 9}},
	{{9, 3}, {15, 7}},
	{{15, 12}, {17, 17}},
	{{5, 3}, {5, 9}}

	};

	BSP_Tree tree1(list_of_polygons);

	delete [] list_of_polygons;
	return 0;
}
