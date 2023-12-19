#include<iostream>


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

	int index_of_polygon;

}polygon;

class BSP_Tree
{
	private:

	BSP_Node *root = NULL;
	polygon *list_of_polygons = NULL;

	public:

	polygon* del_first_polygon(polygon *list_of_polygons, int num_of_polygon)
	{
		polygon *list_of_polygons_new = new polygon[num_of_polygon-1];//размер массива - 1

		//переменная для перебера новго массива
		int i = 0;
		//переменная для перебора старого массива
		int j = 1;
		while(i<num_of_polygon)
		{
			list_of_polygons_new[i] = list_of_polygons[j];
			i++; j++;
		}

		return list_of_polygons_new;
	}
	/*
	void add_node(polygon *list_of_polygons, BSP_Node *root)
	{
		//НЕТ РЕКУРСИИ
		if(root==NULL)
		{
			//первый полигон из списка будет корнем
			//root = new BSP_Node;
			//root->index = 0;
			int Node_now = 0;
		}
		//НЕТ РЕКУРСИИ

		//проверка расположения оставшихся полигонов, относительно текущего
		//вычисление размера текущего списка полигонов
		for(int i = 1; i< num_of_polygon; i++)
		{
			//if(list_of_polygons[Node_now]->one->x<list_of_polygons[i]->one->x)
			//{

			//}
		}
		////////////////////////////////////////////////////////////////////
	}
	*/

	void Build_BSP_Tree(polygon* list_of_polygons, BSP_Node* root)
	{

	}
	BSP_Tree(polygon *list_of_polygons, int num_of_polygon)
	{
		this->list_of_polygons = list_of_polygons;
		if(list_of_polygons != NULL)
		{
			//если список полигоонов не пуст, 
			//корнем делаем полигон с индексом 0 (1)
			root = new BSP_Node;
			root->index = list_of_polygons[0].index_of_polygon;

			//функция удаления первого элемента листа полигонов
			this->list_of_polygons = del_first_polygon(list_of_polygons, num_of_polygon);
		}
		Build_BSP_Tree(list_of_polygons, root);
		//     add_node(list_of_polygons, root);
	}

	~BSP_Tree()
	{

	}
	
};

int main()
{
	//массив полигонов 
	int num_of_polygon = 5;
	polygon *list_of_polygons = new polygon[num_of_polygon]
	{
	{{3, 12}, {10, 16}, 1},
	{{10, 14}, {14, 9}, 2},
	{{9, 3}, {15, 7}, 3},
	{{15, 12}, {17, 4}},
	{{5, 3}, {5, 9}, 5}

	};

	BSP_Tree tree1(list_of_polygons, num_of_polygon);

	delete [] list_of_polygons;
	return 0;
}
